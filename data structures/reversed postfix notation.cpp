#include <iostream>
#include <vector>
#include <string>

class list {
private:

public:
    class node {
    public:
        node* next;
        node* prev;
        int data;

        node(int data = 0, node* next = nullptr, node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };
    int msize;
    node* head;
    node* tail;

    list();
    ~list() {};

    void push_back(int data);
    void pop_back();
    
    void plus();
    void mult();
    void dif();


    int top() { return this->tail->next->data; }
    int size() { return msize; }
    int& operator [](int ind);
};

list::list() {
    msize = 0;
    this->head = new node(-1);
    this->tail = new node(-1);
}

void list::push_back(int data)
{
    if (head->next == nullptr) {
        node* temp = new node(data, this->tail, this->head);
        this->head->next = temp;
        this->tail->next = temp;
    }
    else {
        node* prev = this->tail->next;
        node* temp = new node(data, this->tail, prev);
        prev->next = temp;
        this->tail->next = temp;

    }
    ++msize;
}

void list::pop_back()
{
    node* last = this->tail->next;
    if (msize == 1) {
        delete head;
        delete tail;
        this->head = new node(-1);
        this->tail = new node(-1);
    }
    else {
        this->tail->next = last->prev;
        last->prev->next = tail;
    }
    delete last;
    --msize;

}

void list::plus()
{
    int prev = this->tail->next->data;
    int secprev = this->tail->next->prev->data;
    this->pop_back();
    this->pop_back();
    this->push_back(prev+secprev);
}

void list::mult()
{
    int prev = this->tail->next->data;
    int secprev = this->tail->next->prev->data;
    this->pop_back();
    this->pop_back();
    this->push_back(prev * secprev);
}

void list::dif()
{
    int prev = this->tail->next->data;
    int secprev = this->tail->next->prev->data;
    this->pop_back();
    this->pop_back();
    this->push_back(secprev - prev);
}

int& list::operator[](int ind)
{
    node* temp = this->head->next;

    int count = 0;
    while (temp != nullptr) {
        if (count == ind)
            return temp->data;
        temp = temp->next;
        ++count;
    }

}


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    list ls;
    int num;
    char oper;
    std::string s;
    std::getline(std::cin, s);

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '+')
            ls.plus();
        else if (s[i] == '*')
            ls.mult();
        else if (s[i] == '-')
            ls.dif();
        else if (s[i] != ' ')
            ls.push_back((int)(s[i] - '0'));
    }

    std::cout << ls.top();


    return 0;
}

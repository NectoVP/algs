#include <iostream>
#include <vector>
#include <string>

class list {
private:
    class node {
    public:
        node* next;
        node* prev;
        char data;

        node(int data = 0, node* next = nullptr, node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };
    int msize;
    node* head;
    node* tail;
    char top;
public:
    list();
    ~list() {};

    void push_back(int data);
    void pop_back();

    void clear();
    char top_elem() { return top; }
    int size() { return msize; }
    char& operator [](int ind);
};

list::list() {
    msize = 0;
    this->head = new node(-1);
    this->tail = new node(-1);
    top = -1;
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
    top = data;
    ++msize;
}

void list::pop_back()
{
    node* last = this->tail->next;
    top = last->prev->data;
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

char& list::operator[](int ind)
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

void list::clear() {
    if (msize != 0) {
        node* temp1 = this->head->next;
        node* temp2 = this->head->next;
        while (temp1 != tail) {
            temp2 = temp1;
            temp1 = temp1->next;
            delete temp2;
        }
        delete this->tail;
        delete this->head;
        msize = 0;
        this->head = new node(-1);
        this->tail = new node(-1);
        top = -1;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    list ls;
    std::string s;
    std::vector <std::string> vec;
    while (std::getline(std::cin, s)) {
        if (s.empty())
            break;
        vec.push_back(s);
    }
    for (int i = 0; i < vec.size(); ++i) {
        s = vec[i];
        bool f = true;
        ls.clear();
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '(' || s[j] == '[') {
                ls.push_back(s[j]);
                continue;
            }
            if (s[j] == ']' || s[j] == ')') {
                if (ls.size() == 0) {
                    f = false;
                    break;
                }
                else if (s[j] == ')' && ls.top_elem() == '(') {
                    ls.pop_back();
                    continue;
                }
                else if (s[j] == ']' && ls.top_elem() == '[') {
                    ls.pop_back();
                    continue;
                }
                else {
                    f = false;
                    break;
                }
            }
        }
        if (f == true && ls.size() == 0)
            std::cout << "YES" << '\n';
        else
            std::cout << "NO" << '\n';


    }


    return 0;
}

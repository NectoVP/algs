#include <iostream>
#include <vector>
#include <string>
using namespace std;

class list {
private:
    class node {
    public:
        node* next;
        int data;

        node(int data = 0, node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
    int msize;
    node* head;

public:
    list();
    ~list();
    
    void push_back(int data);
    void push_front(int data);
    void pop_front();
    void pop_back();

    int& operator [](int ind);
    int size();
};

list::list() {
    msize = 0;
    head = nullptr;
}

list::~list() {
    while (msize != 0)
        pop_front();
}

void list::push_back(int data)
{
    if (head == nullptr) {
        head = new node(data);
    }
    else {
        node* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new node(data);
    }
    ++msize;
}

void list::pop_front()
{
    node *temp = head;
    head = head->next;
    delete temp;
    --msize;
}

void list::pop_back()
{
    node* temp = head;
    for (int i = 0; i < msize - 2; ++i)
        temp = temp->next;
    node *b = temp->next;
    delete b;
    temp->next = nullptr;
    --msize;
}

void list::push_front(int data)
{
    head = new node(data, head);    
    ++msize;
}

int& list::operator[](int ind)
{
    node* temp = this->head;
    int count = 0;
    while (temp != nullptr) {
        if (count == ind)
            return temp->data;
        temp = temp->next;
        ++count;
    }

}

int list::size()
{
    return msize;
}

int main() {
    return 0;
}

#include "stack_linked.h"

void Stack::push(char c) {
    Node* new_top = new Node(c);
    new_top->down = top_;
    top_ = new_top;
}

char Stack::top() {
    return top_->letter;
}

void Stack::pop() {
    Node* new_top = top_->down;
    delete top_;
    top_ = new_top;
}

Stack::~Stack() {
    while (top_ != nullptr) {
        pop();
    }
}

bool Stack::isEmpty() {
    return top_ == nullptr;
}

void Stack::clear() {
    while (top_ != nullptr) {
        pop();
    }
}
//write a stack to an ostream and please separate with commas and including a trailing comma. 
std::ostream &operator<<(std::ostream &os, const Stack &s) {
    Node* current = s.top_;
    while (current != nullptr) {
        os << current->letter;
        current = current->down;
        os << ",";
    }
    return os;
}

Stack &Stack::operator=(Stack other) {
    while (top_ != nullptr) {
        pop();
    }
    Node* current = other.top_;
    Stack temp;
    while (current != nullptr) {
        temp.push(current->letter);
        current = current->down;
    }
    while (temp.top_ != nullptr) {
        push(temp.top());
        temp.pop();
    }
    return *this;
}

Stack::Stack(const Stack &other) {
    Node* current = other.top_;
    //invert the order of the other stack
    Stack temp;
    while (current != nullptr) {
        temp.push(current->letter);
        current = current->down;
    }
    
    //copy the other stack to this stack
    current = temp.top_;
    while (current != nullptr) {
        push(current->letter);
        current = current->down;
    }
}

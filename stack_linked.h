#pragma once
#include <iostream>

class Node {
 public:
  char letter;
  Node* down;
  Node(char c) : letter(c), down(nullptr) {}
};

class Stack {
 private:
  Node* top_ = nullptr;

 public:
  Stack() = default;
  void push(char c);
  char top();
  void pop();
  bool isEmpty();
  void clear();
  friend std::ostream& operator<<(std::ostream& os, Stack const& s);
  ~Stack();
  Stack& operator=(Stack other);
  Stack(Stack const& other);
};
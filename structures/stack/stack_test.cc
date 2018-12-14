#include "stack.hpp"
#include <iostream>

int main() {
    Stack<int> stack;
    stack.push(123);
    std::cout << stack.top();
    stack.pop();
    stack.pop(); // Exception Ocurred
    return 0;
}
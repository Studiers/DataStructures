#include "stack.hpp"
#include <iostream>

int main() {
    Stack<int> stack;
    std::cout << stack.top();
    return 0;
}
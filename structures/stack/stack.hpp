#include "stack_exceptions.h"
#include <algorithm>

template<class _ElType, const int _Size=128>
class Stack {
  _ElType* _elements;
  int _size, _top;

public:
  Stack() {
    _top = -1;
    _size = _Size;
    _elements = new _ElType[_size];
  }

  _ElType const& top() const {
    if (_top == -1)
      throw StackEmptyException();
    
    return _elements[_top];
  }

  void push(_ElType el) {
      _elements[++_top] = el;
  }

  void pop() {
    --_top;
  }

  void resize(const int size) {
    _ElType* newElements = new _ElType[size];
    std::copy(newElements, newElements+_size, newElements);
    _elements = newElements;
  }
};
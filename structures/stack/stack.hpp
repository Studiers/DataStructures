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
    if (_size <= _top) {
      resize(_size*2);
      _size = _size << 1;
    }

    _elements[++_top] = el;
  }

  void pop() {
    if (_top == -1)
      throw StackEmptyException();
      
    --_top;
  }

  void resize(const int size) {
    _ElType* newElements = new _ElType[size];
    std::copy(newElements, newElements+_size, newElements);
    delete _elements;
    _elements = newElements;
  }

  size_t size() const {
    return _size;
  }

  void clear() {
    _top = -1;
  }
};
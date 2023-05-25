#pragma once

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
public:
	Array() : _elems(NULL), _size(0) {}

	explicit Array(unsigned int n) : _size(n) {
		_elems = new T[n];
		for (unsigned int i = 0; i < _size; ++i)
			_elems[i] = T();
	}

	Array(const Array& other) : _size(other._size) {
		_elems = new T[_size];
		for (size_t i = 0; i < other.size(); ++i)
			_elems[i] = other[i];
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] _elems;
			_size = other._size;
			_elems = new T[_size];
			for (size_t i = 0; i < other.size(); ++i)
				_elems[i] = other[i];
		}
		return *this;
	}

	~Array() { delete[] _elems; }

	T& operator[](unsigned int i) {
		if (i >= _size)
			throw std::out_of_range("Array index out of bounds");
		return _elems[i];
	}

	const T& operator[](unsigned int i) const {
		if (i >= _size)
			throw std::out_of_range("Array index out of bounds");
		return _elems[i];
	}

	unsigned int size() const { return _size; }

private:
	T* _elems;
	unsigned int _size;
};

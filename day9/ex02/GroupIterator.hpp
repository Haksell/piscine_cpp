#pragma once

#include <algorithm>

template <typename Iterator>
class GroupIterator {
private:
	Iterator _it;
	std::size_t _size;

	GroupIterator() {}
	GroupIterator& operator=(const GroupIterator& other);

public:
	typedef std::random_access_iterator_tag iterator_category;
	typedef Iterator iterator_type;
	typedef typename std::iterator_traits<Iterator>::value_type value_type;
	typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename std::iterator_traits<Iterator>::pointer pointer;
	typedef typename std::iterator_traits<Iterator>::reference reference;

	GroupIterator(Iterator it, std::size_t size) : _it(it), _size(size) {}

	GroupIterator(const GroupIterator& other) : _it(other._it), _size(other._size) {}

	iterator_type base() const { return _it; }

	std::size_t size() const { return _size; }

	reference operator*() const { return _it[_size - 1]; }

	pointer operator->() const { return &(operator*()); }

	GroupIterator& operator++() {
		_it += _size;
		return *this;
	}

	GroupIterator operator++(int) {
		GroupIterator tmp = *this;
		operator++();
		return tmp;
	}

	GroupIterator& operator--() {
		_it -= _size;
		return *this;
	}

	GroupIterator operator--(int) {
		GroupIterator tmp = *this;
		operator--();
		return tmp;
	}

	GroupIterator& operator+=(std::size_t increment) {
		_it += _size * increment;
		return *this;
	}

	GroupIterator& operator-=(std::size_t increment) {
		_it -= _size * increment;
		return *this;
	}

	size_t operator[](std::size_t pos) { return _it[pos * _size + _size - 1]; }

	size_t operator[](std::size_t pos) const { return _it[pos * _size + _size - 1]; }
};

template <typename Iterator1, typename Iterator2>
bool operator==(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() == rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator!=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() != rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() < rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() <= rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() > rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base >= rhs.base();
}

template <typename Iterator>
GroupIterator<Iterator> operator+(GroupIterator<Iterator> it, std::size_t size) {
	return it += size;
}

template <typename Iterator>
GroupIterator<Iterator> operator+(std::size_t size, GroupIterator<Iterator> it) {
	return it += size;
}

template <typename Iterator>
GroupIterator<Iterator> operator-(GroupIterator<Iterator> it, std::size_t size) {
	return it -= size;
}

template <typename Iterator>
typename GroupIterator<Iterator>::difference_type operator-(const GroupIterator<Iterator>& lhs,
															const GroupIterator<Iterator>& rhs) {
	return (lhs.base() - rhs.base()) / lhs.size();
}

template <typename Iterator>
GroupIterator<Iterator> makeGroupIterator(Iterator it, std::size_t size) {
	GroupIterator<Iterator> tmp(it, size);
	return tmp;
}

template <typename Iterator>
GroupIterator<Iterator> makeGroupIterator(GroupIterator<Iterator> it, std::size_t size) {
	GroupIterator<Iterator> tmp(it.base(), size * it.size());
	return tmp;
}
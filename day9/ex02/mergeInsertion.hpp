#pragma once

#include "GroupIterator.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

extern int g_count;

template <typename Iterator>
bool compare(Iterator it1, Iterator it2) {
	++g_count;
	return it1 < it2;
}

template <typename RandomAccessIterator>
bool comparePtr(RandomAccessIterator it1, RandomAccessIterator it2) {
	return compare(*it1, *it2);
}

template <typename RandomAccessIterator>
struct Node {
	RandomAccessIterator it;
	typename std::list<RandomAccessIterator>::iterator next;
};

template <typename RandomAccessIterator>
static void _mergeInsertion(RandomAccessIterator first, RandomAccessIterator last) {
	static const size_t jacobsthal_diff[] = {2u,
											 2u,
											 6u,
											 10u,
											 22u,
											 42u,
											 86u,
											 170u,
											 342u,
											 682u,
											 1366u,
											 2730u,
											 5462u,
											 10922u,
											 21846u,
											 43690u,
											 87382u,
											 174762u,
											 349526u,
											 699050u,
											 1398102u,
											 2796202u,
											 5592406u,
											 11184810u,
											 22369622u,
											 44739242u,
											 89478486u,
											 178956970u,
											 357913942u,
											 715827882u,
											 1431655766u,
											 2863311530u,
											 5726623062u,
											 11453246122u,
											 22906492246u,
											 45812984490u,
											 91625968982u,
											 183251937962u,
											 366503875926u,
											 733007751850u,
											 1466015503702u,
											 2932031007402u,
											 5864062014806u,
											 11728124029610u,
											 23456248059222u,
											 46912496118442u,
											 93824992236886u,
											 187649984473770u,
											 375299968947542u,
											 750599937895082u,
											 1501199875790165u,
											 3002399751580331u,
											 6004799503160661u,
											 12009599006321322u,
											 24019198012642644u,
											 48038396025285288u,
											 96076792050570576u,
											 192153584101141152u,
											 384307168202282304u,
											 768614336404564608u,
											 1537228672809129216u,
											 3074457345618258432u,
											 6148914691236516864u};

	std::size_t size = std::distance(first, last);
	if (size < 2)
		return;
	bool hasStray = size & 1;
	RandomAccessIterator end = hasStray ? last - 1 : last;
	for (RandomAccessIterator it = first; it != end; it += 2)
		if (compare(it[1], it[0]))
			std::swap_ranges(it.base(), it.base() + it.size(), (it + 1).base());

	_mergeInsertion(makeGroupIterator(first, 2), makeGroupIterator(end, 2));
	std::list<RandomAccessIterator> a;
	a.push_back(first);
	a.push_back(first + 1);
	std::list<Node<RandomAccessIterator> > b;
	for (RandomAccessIterator it = first + 2; it != end; it += 2) {
		Node<RandomAccessIterator> node = {it, a.insert(a.end(), it + 1)};
		b.push_back(node);
	}
	if (hasStray) {
		Node<RandomAccessIterator> node = {end, a.end()};
		b.push_back(node);
	}

	for (int k = 0;; ++k) {
		size_t dist = jacobsthal_diff[k];
		if (dist >= b.size())
			break;
		typename std::list<Node<RandomAccessIterator> >::iterator it = b.begin();
		std::advance(it, dist - 1);

		while (true) {
			typename std::list<RandomAccessIterator>::iterator insertion_point =
				std::upper_bound(a.begin(), it->next, it->it, comparePtr<RandomAccessIterator>);
			a.insert(insertion_point, it->it);
			it = b.erase(it);
			if (it == b.begin())
				break;
			--it;
		}
	}

	while (!b.empty()) {
		typename std::list<Node<RandomAccessIterator> >::reverse_iterator it = b.rbegin();
		typename std::list<RandomAccessIterator>::iterator insertion_point =
			std::upper_bound(a.begin(), it->next, it->it, comparePtr<RandomAccessIterator>);
		a.insert(insertion_point, it->it);
		b.pop_back();
	}

	std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> cache;
	for (typename std::list<RandomAccessIterator>::iterator it = a.begin(); it != a.end(); ++it) {
		std::copy(it->base(), it->base() + it->size(), std::back_inserter(cache));
	}
	std::copy(cache.begin(), cache.end(), first.base());
}

template <typename RandomAccessIterator>
void mergeInsertion(RandomAccessIterator first, RandomAccessIterator last) {
	_mergeInsertion(makeGroupIterator(first, 1), makeGroupIterator(last, 1));
}
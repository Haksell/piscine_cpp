#include "MutantStack.hpp"
#include <list>
#include <vector>

static void updateAll(MutantStack<int>& mstack, std::vector<int>& vec, std::list<int>& lst, int n) {
	if (n == 0) {
		mstack.pop();
		vec.pop_back();
		lst.pop_back();
	} else {
		mstack.push(n);
		vec.push_back(n);
		lst.push_back(n);
	}
}

int main() {
	MutantStack<int> mstack;
	std::vector<int> vec;
	std::list<int> lst;

	updateAll(mstack, vec, lst, 27);
	updateAll(mstack, vec, lst, 42);
	updateAll(mstack, vec, lst, 0);
	updateAll(mstack, vec, lst, 69);
	updateAll(mstack, vec, lst, 111);

	printIterator(mstack.begin(), mstack.end());
	printIterator(mstack.rbegin(), mstack.rend());
	printIterator(vec.begin(), vec.end());
	printIterator(vec.rbegin(), vec.rend());
	printIterator(lst.begin(), lst.end());
	printIterator(lst.rbegin(), lst.rend());
}
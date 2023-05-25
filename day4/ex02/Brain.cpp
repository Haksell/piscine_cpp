#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = "Pierre qui roule n'amasse pas mousse.";
	std::cout << "Brain constructed.\n";
}

Brain::Brain(Brain const& brain) {
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copied.\n";
}

Brain& Brain::operator=(Brain const& brain) {
	if (this != &brain)
		for (int i = 0; i < NUM_IDEAS; i++)
			this->ideas[i] = brain.ideas[i];
	std::cout << "Brain assigned.\n";
	return *this;
}

Brain::~Brain() { std::cout << "Brain destructed.\n"; }

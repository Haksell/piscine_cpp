#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>

#define DATA_PATH "files/data.csv"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		std::cerr << "Example:" << std::endl;
		std::cerr << "date | value" << std::endl;
		std::cerr << "2011-01-03 | 2" << std::endl;
		std::cerr << "2011-01-03 | 1.2" << std::endl;
		std::cerr << "2011-01-09 | 3" << std::endl;
		return EXIT_FAILURE;
	}
	std::stringstream dataStream, inputStream;
	if (!readFile(DATA_PATH, dataStream) || !readFile(argv[1], inputStream))
		return EXIT_FAILURE;
	BitcoinExchange bitcoinExchange;
	if (!bitcoinExchange.update(dataStream)) {
		std::cerr << "Failed to parse " << DATA_PATH << "." << std::endl;
		return EXIT_FAILURE;
	}
	std::string line;
	std::getline(inputStream, line);
	if (line != "date | value")
		complain("invalid data header: " + line);
	while (std::getline(inputStream, line))
		bitcoinExchange.query(line);
	return EXIT_SUCCESS;
}

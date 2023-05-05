#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./sed " << argv[0] << " infile s1 s2\n";
        return EXIT_FAILURE;
    }
    std::string infile(argv[1]);
    std::ifstream ifs(infile.c_str());
    if (!ifs.good()) {
        std::cerr << "Cannot read from " << infile << "\n";
        return EXIT_FAILURE;
    }
    std::string outfile = infile + ".replace";
    std::ofstream ofs(outfile.c_str());
    if (!ofs.good()) {
        std::cerr << "Cannot write to " << outfile << "\n";
        return EXIT_FAILURE;
    }
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string content = buffer.str();
    std::string before(argv[2]);
    std::string after(argv[3]);
    size_t i = 0;
    while (i < content.size()) {
        if (content.substr(i, before.size()) == before) {
            ofs << after;
            i += before.size();
        } else {
            ofs << content[i];
            ++i;
        }
    }
}
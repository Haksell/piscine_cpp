#include "ex02.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

static bool endswith(std::string const& str, std::string const& end) {
	if (end.size() > str.size())
		return false;
	return std::equal(end.rbegin(), end.rend(), str.rbegin());
}

static std::vector<std::string> getFilenames() {
	DIR* dpdf = opendir(SHRUBBERY_DIRECTORY);
	if (!dpdf)
		throw std::runtime_error("Failed to open shrubbery directory");
	std::vector<std::string> filenames;
	struct dirent* epdf;
	while ((epdf = readdir(dpdf))) {
		std::string filename = epdf->d_name;
		if (filename == "." || filename == "..")
			continue;
		if (!endswith(filename, ".ppm"))
			throw std::runtime_error("Non-PPM file found in shrubbery directory");
		filenames.push_back(filename);
	}
	if (filenames.empty())
		throw std::runtime_error("No file found in shrubbery directory");
	free(dpdf);
	return filenames;
}

static std::string getFilename() {
	std::vector<std::string> filenames = getFilenames();
	return SHRUBBERY_DIRECTORY + filenames[std::rand() % filenames.size()];
}

static void initFileStreams(std::ifstream& ifs, std::ofstream& ofs, const std::string& filename,
							const std::string& target) {
	ifs.open(filename.c_str(), std::ios::binary);
	if (!ifs.good())
		throw std::runtime_error("Could not open input file.");
	ofs.open((target + "_shrubbery").c_str());
	if (!ofs.good())
		throw std::runtime_error("Could not open output file.");
}

static size_t getFileSize(std::ifstream& ifs) {
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	return size;
}

static void skipWhitespace(std::ifstream& ifs) {
	int byte = ifs.get();
	if (!std::isspace(byte))
		throw PpmParsingException();
	while (true) {
		byte = ifs.get();
		if (!std::isspace(byte)) {
			ifs.seekg(-1, std::ios::cur);
			return;
		}
		if (byte == -1)
			throw PpmParsingException();
	}
}

static unsigned int parseNum(std::ifstream& ifs) {
	skipWhitespace(ifs);
	unsigned int n = 0;
	while (true) {
		int byte = ifs.get();
		if (std::isspace(byte)) {
			if (n == 0)
				throw PpmParsingException();
			ifs.seekg(-1, std::ios::cur);
			return n;
		}
		if (byte < '0' || byte > '9')
			throw PpmParsingException();
		n = 10 * n + byte - '0';
		if (n > PPM_PARAM_LIMIT)
			throw PpmParsingException();
	}
}

static PpmParams parsePpmHeader(std::ifstream& ifs) {
	if (ifs.get() != 'P' || ifs.get() != '6')
		throw PpmParsingException();
	PpmParams ppmParams = {
		.width = parseNum(ifs), .height = parseNum(ifs), .maxval = parseNum(ifs)};
	if (!std::isspace(ifs.get()))
		throw PpmParsingException();
	return ppmParams;
}

static unsigned int getValue(std::ifstream& ifs, unsigned int maxval) {
	unsigned int color = ifs.get();
	if (maxval >= 256) {
		color <<= 8;
		color |= ifs.get();
	}
	return color * 255 / maxval;
}

static std::string getPixel(std::ifstream& ifs, unsigned int maxval) {
	std::stringstream ss;
	ss << "\x1B[48;2;" << getValue(ifs, maxval) << ";" << getValue(ifs, maxval) << ";"
	   << getValue(ifs, maxval) << "m " << RESET;
	return ss.str();
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	checkRequirements(executor);
	std::string filename = getFilename();
	std::ifstream ifs;
	std::ofstream ofs;
	initFileStreams(ifs, ofs, filename, _target);
	size_t size = getFileSize(ifs);
	PpmParams ppmParams = parsePpmHeader(ifs);
	size_t expectedRemainingBytes =
		ppmParams.width * ppmParams.height * 3 * (ppmParams.maxval >= 256 ? 2 : 1);
	if (size - ifs.tellg() != expectedRemainingBytes)
		throw PpmParsingException();
	for (size_t y = 0; y < ppmParams.height; ++y) {
		for (size_t x = 0; x < ppmParams.width; ++x) {
			std::string pixel = getPixel(ifs, ppmParams.maxval);
			ofs << pixel << pixel;
		}
		ofs << std::endl;
	}
}
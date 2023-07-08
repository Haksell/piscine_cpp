#include "utils.hpp"

bool complain(const std::string& message) {
	std::cerr << "Error: " << message << std::endl;
	return false;
}

bool parseDouble(const std::string& s, double& out) {
	std::istringstream iss(s);
	iss >> out;
	return iss.eof() && !iss.fail();
}

static bool fileError(const char* path, const std::string& message) {
	std::cerr << "Error: " << path << " " << message << "." << std::endl;
	return false;
}

bool readFile(const char* path, std::stringstream& content) {
	struct stat sb;
	if (stat(path, &sb) != 0)
		return fileError(path, "does not exist");
	if (!S_ISREG(sb.st_mode))
		return fileError(path, "is not a regular file");
	std::ifstream ifs(path);
	if (!ifs.is_open())
		return fileError(path, "could not be opened");
	content << ifs.rdbuf();
	ifs.close();
	if (content.tellp() == 0)
		return fileError(path, "is empty");
	return true;
}

std::string strtrim(const std::string& s) {
	std::string result = s;
	std::string::size_type pos = result.find_first_not_of(SPACES);
	if (pos == std::string::npos)
		return result;
	result.erase(0, pos);
	pos = result.find_last_not_of(SPACES);
	result.erase(pos + 1);
	return result;
}

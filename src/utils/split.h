#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

/**
 * @brief split string function
 * @param string
 * @param delimitor
 * @return splitted string in a std::vector<std::string>
 */
std::vector<std::string> split(const std::string &s, char delim);

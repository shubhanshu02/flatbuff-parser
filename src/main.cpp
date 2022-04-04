#include <iostream>
#include <string>

#include "vwparser.hpp"

int main(int argc, char** argv)
{
  Parser parser;
  std::cout << argc << std::endl;
  if (argc == 1) {
    std::string a_name, file_name;
    float a_float;
    bool a_flag;

    parser.take_input(&a_name, &a_float, &a_flag, &file_name);
    auto buf = parser.createTableRow(a_name, a_float, a_flag);
    parser.writeToDisk(buf, file_name);
    std::cout << "Successfully written to " << file_name << std::endl;
    delete buf;
  } else if (argc == 3
             && (!strcmp(argv[1], "-r") || !strcmp(argv[1], "--read"))) {
    std::cout << "Reading file " << argv[2] << std::endl;
    auto x = parser.readFromDisk(argv[2]);
    parser.printRow(x);
  } else {
    std::cout << "Usage: " << argv[0] << "-r <filename>\nOR\n";
    std::cout << "Usage: " << argv[0] << std::endl;
    return -1;
  }

  return 0;
}

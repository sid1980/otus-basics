#include "misc.h"


//int stoi(
//    const std::string &str,
//    int *p_value,
//    std::size_t *pos,
//    int base)
//{
//  try {
//          *p_value = std::stoi(str, pos, base);
//          return 0;
//      }

//      catch (const std::invalid_argument& ia) {
//          std::cout << "Invalid argument: " << ia.what() << std::endl;
//          return -1;
//      }

//      catch (const std::out_of_range& oor) {
//          std::cout << "Out of Range error: " << oor.what() << std::endl;
//          return -2;
//      }

//      catch (const std::exception& e)
//      {
//          std::cout << "Undefined error: " << e.what() << std::endl;
//          return -3;
//      }
//}

std::vector<std::string> inputToVector(int argc, char** argv)
{
  std::vector<std::string>  input;
  for (int i=0; i < argc; i++) {
    input.push_back(argv[i]);
  }
  return input;
}

void printVec(const std::vector<std::string> &vec) {

  int i = 0;
  for (std::string cstr : vec) {
    std::cout << i++ << " "<< cstr.c_str() << std::endl;
  }
}

int getRandomValue(int max)
{
  if(max <= 0) {
    //! TODO: подумать как лучше обработать эту ситуацию.
    max = 10;
  }

  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  return std::rand() % max;
}

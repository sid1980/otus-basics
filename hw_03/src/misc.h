#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>


//! Обертка для обработка исключительных ситуаций.
//int stoi(const std::string& str,
//         int* p_value,
//         std::size_t* pos = 0,
//         int base = 10);

void printVec(const std::vector<std::string>& vec);

int getRandomValue(int max);

//! Переводит параметры коммандной строки в вектор.
std::vector<std::string> inputToVector(int argc, char** argv);

#endif // MISC_H

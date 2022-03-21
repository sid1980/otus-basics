#ifndef HIGH_SCORES_HPP
#define HIGH_SCORES_HPP

#include "misc.h"

#include <iostream>
#include <fstream>
#include <unordered_map>

using std::string;
using std::vector;
using std::pair;

//! Вынести в файл настроек.
static const std::string g_high_scores_filename = "high_scores.txt";


//! Печатет таблицу результатов.
inline void printScoreTable (
    const std::unordered_map<string, string>& table)
{

  for(std::pair<std::string, std::string> item: table) {

    std::cout << item.first << " " << item.second << std::endl;
  }
}


inline int saveScoreTable (
    const std::unordered_map<string, string>& table)
{

  std::ofstream out_file{g_high_scores_filename, std::ios_base::trunc};
  if (!out_file.is_open()) {
          std::cout << "Failed to open file for write: "
                    << g_high_scores_filename << "!" << std::endl;
          return -1;
  }

  for (auto item: table) {

    // Append new results to the table:
    out_file << item.first << ' ';
    out_file << item.second;
    out_file << std::endl;
  }

  return EXIT_SUCCESS;
}

//! Загружает таблицу результатов игроков.
inline int loadScoreTable (
    std::unordered_map<string, string>& table)
{

  std::ifstream in_file{g_high_scores_filename};
  if (!in_file.is_open()) {
          std::cout << "Failed to open file for read: "
                    << g_high_scores_filename << "!" << std::endl;
           return -1;
  }

  std::string username;
  int high_score = 0;

  while (true) {
          // Read the username first
          in_file >> username;
          // Read the high score next
          in_file >> high_score;
          // Ignore the end of line symbol
          in_file.ignore();

          if (in_file.fail()) {
                  break;
          }
          //! TODO: проверить что считанное второе значение действительно число.
          table.insert(std::make_pair(username, std::to_string(high_score)));
  }

  return 1;
}

inline void addScore (
    std::unordered_map<string, string>& table,
    const GameData& gameData)
{

  //! Если в результате попыток меньше то сохраняем их
  //! NOTE: надо сохранять еще и уровень т.к. попыток на простом уровне
  //! будет значительно меньше.
  if (table.find(gameData.userName) != table.end()) {

    int score{0};
    try {
      score = std::stoi(table[gameData.userName]);
    } catch (std::exception &e) {
      std::cout << "error add score: " << e.what() << std::endl;
      return;
    }

    if (score > gameData.attempts ) {
      table.insert(make_pair(gameData.userName,
                                  std::to_string(gameData.attempts)));
    }
  } else {
    //! Если есть такое имя в таблице.
    table[gameData.userName] = std::to_string(gameData.attempts);
  }

}

#endif // HIGH_SCORES_HPP

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "misc.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>


static std::string MAX{"-max"};
static std::string TABLE{"-table"};
static std::string LEVEL{"-level"};

namespace game {
  static const int MAX_LEVEL1 = 10;
  static const int MAX_LEVEL2 = 50;
  static const int MAX_LEVEL3 = 100;

}

struct GameData
{
  //! Максимальное число.
  int maxNumber{10};
  //! Загаданное число;
  int number{1};
  //! Попытки.
  int attempts{0};
  //! Введена комманда TABLE для показать таблицу.
  bool isTable{false};
  //! Имя пользователя.
  std::string userName{"NoName"};

  GameData() {}

  void print() {
    std::cout << "maxNumber:" << maxNumber << std::endl;
    std::cout << "isTable:" << isTable << std::endl;
    std::cout << "userName:" << userName << std::endl;
    std::cout << "number:" << number << std::endl;
    std::cout << "attempts:" << attempts << std::endl;
    std::cout << "------" << std::endl;
  }

  void setUserName() 
  {
    do {
      userName = inputUserName();

      // TODO(ML): проверить является ли имя в таблице или нет.
      if (!userName.empty()) {
        
        break;
      } else {
        std::cout << "Name must by not zero" << std::endl;
      }

    } while(true);

  }

};

std::string inputUserName();

int initGame(GameData& gameData, std::vector<std::string> input);

int getGuessNumberBy(int level);

void gameLoop(GameData& data);

#endif // GAMELOGIC_H

#include "gamelogic.h"

std::string inputUserName()
{
 std::string name;

 std::cout << "Hi! Enter your name, please:" << std::endl;
 std::cin >> name;

 return name;
}


int getGuessNumberBy(int level) {

  if (level == 1)  {

    return getRandomValue(game::MAX_LEVEL1);
  } else if (level == 2) {

    return getRandomValue(game::MAX_LEVEL2);
  } else if (level == 3) {

    return getRandomValue(game::MAX_LEVEL3);
  }
  else {
    return getRandomValue(game::MAX_LEVEL3);
  }
}


int initGame(GameData &gameData, std::vector<std::string> input)
{
  if (input.size() >= 2) {

    if (input.at(1) == MAX) {

      try {

        gameData.maxNumber = std::stoi(input.at(2));
        gameData.number = getRandomValue(gameData.maxNumber);
      } catch (const std::invalid_argument & e) {

        std::cout << "error: " << e.what() << "\n";
        return 0;
      } catch (const std::out_of_range & e) {

        std::cout << e.what() << "\n";
        return 0;
      } catch (const std::exception & e) {

        std::cout << e.what() << "\n";
        return 0;
       }
    } else if(input.at(1) == TABLE) {

      gameData.isTable = true;
    } else if(input.at(1) == LEVEL) {

      int level = 1;
      try {
        level = std::stoi(input.at(2));
      } catch (std::exception &e){
        std::cout << "Enter wrong LEVEL: "<< input.at(2) << e.what() << "\n";
        level = 1;
      }

      gameData.maxNumber = getGuessNumberBy(level);
      gameData.number = getRandomValue(gameData.maxNumber);
   } else {
     std::cout << "Unused argument: "<< input.at(1) << "\n";
   }

  }

 return 1;
}

void gameLoop(GameData& data) {

  const int target_value = data.number;
  int current_value = 0;
  bool not_win = true;
  std::string input;

  int attempts = 0;

  std::cout << "Enter your guess:" << std::endl;

  do {
          std::cin >> input;

          try {
            current_value = std::stoi(input);
          } catch (std::exception &e) {
            std::cout << "Wrong input value, try arain" << std::endl;
            continue;
          }

          //! Чтобы не потерялось 1 попытка после правильного ответа.
          ++attempts;

          if (current_value < target_value) {
                  std::cout << "less than " << current_value << std::endl;
          }
          else if (current_value > target_value) {
                  std::cout << "greater than " << current_value << std::endl;
          }
          else {
                  std::cout << "you win!" << "attempts = " << attempts <<std::endl;
                  break;
          }

  } while(true);

  data.attempts = attempts;
}

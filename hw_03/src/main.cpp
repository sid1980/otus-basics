/*
 use case1:
 > guess_the_number
Hi! Enter your name, please:
Username
Enter your guess:
42
less than 42
1
greater than 1
33
you win! attempts = 3
High scores table:
SomeName 13
SomeOtherName 24
Username 9
Username 3

use case2:
> guess_the_number -max 42
Задаем максимальное значение загаданного числа

use case3:
> guess_the_number -table
Программа распечатывает всю таблицу результатов игроков.
(таблица храниться в текстовом файле в корне: high_scores.txt
в формате:  [Имя пользователя] [результат]
S 10
D 1
A 1
C 42
A 1
B 2
)

use case4:
> guess_the_number -level [1..3]
1 – масимальное значение 10 (таким образом отгадывать будет в диапазоне от 0 до 9)
2 – максимальное значение 50 (диапазон станет от 0 до 49)
3 – максимальное значение 100 (диапазон от 0 до 99)

(В случае выполнения дополнительного задания 1, считаем ввод параметров “-level” и “-max”
одновременно ошибочной ситуацией. Допустимо либо указать уровень сложности, либо явно
задать максимальное значение.)

 */

#include "misc.h"
#include "gamelogic.h"
#include "high_scores.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <utility>
#include <unordered_map>

using std::string;
using std::vector;
using std::pair;
using std::endl;
using std::cout;

//!
static bool g_debug = true;


int main(int argc, char** argv)
{
  setlocale(LC_ALL, "ru_RU.utf8");

  try {

    char *str  = "Cуть игры. \r\n"
                 " Приложение \"загадывает\" некоторое число и ждёт в цикле ввода от пользователя.\n"
                 "В случае, если пользователь ввёл число, меньшее загаданного, выводится подсказка \"less than\". \n"
                 "В случае, если пользователь ввёл число, большее заданного, выводится подсказка \"greater than\". \n"
                 "В случае, когда пользователь, наконец, угадывает число, выводится сообщение «you win!», \n"
                 " и цикл ввода завершается.\n";
    std::cout << str << std::endl;

    GameData gameData;
    if (!initGame(gameData, inputToVector(argc, argv))) {
      return 0;
    }

    //! Загрузка данных из таблицы
    //! ввод имени пользователя 
    //! Игровой процесс 
    //! GameRound - одна итерация игры 
    //! ScoreTable - таблица результатов (хранить список результатов )
    //! Game - игра 


    std::unordered_map<string, string> tableScore{};
    const int rez = loadScoreTable(tableScore);
    if (rez == -1) {
      //! TODO: что произойдет если файл с таблицей результатов не найден.
    }

    if (gameData.isTable) {
      printScoreTable(tableScore);
      return 0;
    }
    
    //! Запускает очередной раунд игры.
    gameData.setUserName();

    if (g_debug) {
       gameData.print();
    }

    //! Главный игровой цикл.
    gameLoop(gameData);


    addScore(tableScore, gameData);

    //! Сахраняет базу данных в файл.
    saveScoreTable(tableScore);

    //! Выводим таблицу результатов.
    printScoreTable(tableScore);

    return EXIT_SUCCESS;
  } catch (const std::exception& e) {

      std::cout << "Undefined error: " << e.what() << std::endl;
      return EXIT_FAILURE;
  }
}

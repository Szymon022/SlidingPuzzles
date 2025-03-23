//
// Created by szymon on 3/23/25.
//

#ifndef RANDOMBOARDFACTORY_H
#define RANDOMBOARDFACTORY_H
#include "Board.h"


class RandomBoardFactory {
    static bool isSolvable(const std::vector<int> &board);

public:
    static Board *getRandomBoard(int boardSize);
};


#endif //RANDOMBOARDFACTORY_H

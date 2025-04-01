//
// Created by szymon on 3/23/25.
//

#ifndef RANDOMBOARDFACTORY_H
#define RANDOMBOARDFACTORY_H
#include "Board.h"


/**
* Creates random number boards.
*/
class RandomBoardFactory {
    static bool isSolvable(const std::vector<int> &board);

public:
    /**
     * \brief Method that creates random number board. This board is always solvable and has empty tile in the bottom-right corner.
     * @param boardSize - target board size
     * @return solvable number board with empty tile in the bottom-right corner.
     */
    static Board *getRandomBoard(int boardSize);
};


#endif //RANDOMBOARDFACTORY_H

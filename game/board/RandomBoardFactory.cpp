//
// Created by szymon on 3/23/25.
//

#include "RandomBoardFactory.h"

#include <random>

bool RandomBoardFactory::isSolvable(const std::vector<int> &board) {
    int inversions = 0;
    for (int i = 0; i < board.size(); i++) {
        if (board[i] == 0) continue;
        for (int j = i + 1; j < board.size(); j++) {
            if (board[j] != 0 && board[i] > board[j]) {
                inversions++;
            }
        }
    }

    return inversions % 2 == 0;
}

Board *RandomBoardFactory::getRandomBoard(const int boardSize) {
    auto randomEngine = std::default_random_engine();
    int boardElementsNumer = boardSize * boardSize;

    auto board = std::vector<int>();
    do {
        board.clear();
        for (int i = 0; i < boardElementsNumer - 1; i++) {
            board.push_back(i + 1);
        }
        board.push_back(0);
        std::ranges::shuffle(board, randomEngine);
    } while (!(isSolvable(board) && board[board.size() - 1] == 0));

    return new Board(board);
}

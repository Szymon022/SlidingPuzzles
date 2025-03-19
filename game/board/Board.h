//
// Created by szymon on 3/13/25.
//

#ifndef BOARD_H
#define BOARD_H
#include <qobject.h>

#include "tiles/Tile.h"

class Board : public QObject {
    int size;
    std::vector<Tile *> board;
    std::vector<Tile *> startPosition;

    int toOneDimensionIndex(int row, int column) const;

    bool isEmptyTile(int row, int column) const;

public:
    /**
     * Creates a square board from given vector. Size of the resulting board is sqrt of board.size().
     * Resulting board is created row by row.
     *
     * Creating a board from vector `{1, 2, 3, 4, 5, 6, 7, 8, 0} will create a board with rows:
     * {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}
     *
     * @param board vector of tiles. 0 represents an empty tile.
     */
    explicit Board(const std::vector<int> &board);

    ~Board() override;

    /**
     * \brief Swaps clicked non-empty tile with empty tile neighbour if it is possible.
     *
     * Swap is possible only if clicked tile is a direct neighbor of an empty tile.
     * Empty tile that is placed diagonally relative to clicked tile is not considered to be a neighbor.
     * @param row
     * @param column
     */
    bool onTileClick(int row, int column);

    int getSize() const;

    Tile *getTile(int row, int column) const;

    /**
     * \brief Checks if board is in solved state or not.
     *
     * Board is considered to be in a solved state if tiles in board are sorted in ascending order by tile ordinals.
     *
     * @return if board is in solved state.
     */
    bool isSolved() const;

    void printBoard() const;

    /**
     * \brief Resets board to starting position in which the board was created.
     */
    void restart();
};


#endif //BOARD_H

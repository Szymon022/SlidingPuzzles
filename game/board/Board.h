//
// Created by szymon on 3/13/25.
//

#ifndef BOARD_H
#define BOARD_H
#include <qobject.h>

#include "tiles/Tile.h"

class Board : public QObject {
    int size;
    std::vector<Tile*> board;

    int toOneDimensionIndex(int row, int column) const;

    bool isEmptyTile(int row, int column) const;

public:
    explicit Board(const std::vector<Tile*> &board);
    ~Board() override;

    void onTileClick(int row, int column);

    int getSize() const;

    Tile* getTile(int row, int column) const;

    bool isSolved() const;

    void printBoard() const;
};


#endif //BOARD_H

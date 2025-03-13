//
// Created by szymon on 3/13/25.
//

#ifndef BOARD_H
#define BOARD_H

class Board
{
    int rows = 3;
    int columns = 3;
    int board[3][3]{};

public:
    explicit Board(int board[3][3]);
    void onTileClick(int row, int column);

    int getBoardRows();
    int getBoardCols();

    int getTile(int row, int column) const;
};


#endif //BOARD_H

//
// Created by szymon on 3/13/25.
//

#include "Board.h"

Board::Board(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->board[i][j] = board[i][j];
        }
    }
}

void Board::onTileClick(const int row, const int column)
{
    if (row < 0 || row >= rows || column < 0 || column >= columns)
    {
        return;
    }

    int tile = board[row][column];
    if (tile == 0) return;

    if (row > 0 && board[row - 1][column] == 0)
    {
        board[row][column] = 0;
        board[row - 1][column] = tile;
    }
    else if (row < rows - 1 && board[row + 1][column] == 0)
    {
        board[row][column] = 0;
        board[row + 1][column] = tile;
    }
    else if (column > 0 && board[row][column - 1] == 0)
    {
        board[row][column] = 0;
        board[row][column - 1] = tile;
    }
    else if (column < columns - 1 && board[row][column + 1] == 0)
    {
        board[row][column] = 0;
        board[row][column + 1] = tile;
    }
}

int Board::getBoardCols()
{
    return columns;
}

int Board::getTile(const int row, const int column) const
{
    return board[row][column];
}

int Board::getBoardRows()
{
    return rows;
}

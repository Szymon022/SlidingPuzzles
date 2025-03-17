//
// Created by szymon on 3/13/25.
//

#include "Board.h"

#include <iosfwd>
#include <qdebug.h>
#include <qstring.h>
#include <sstream>
#include <vector>
#include <vector>

#include "tiles/EmptyTile.h"
#include "tiles/NumberTile.h"


int Board::toOneDimensionIndex(const int row, const int column) const {
    if (row < 0 || row >= size || column < 0 || column >= size) throw std::invalid_argument("index out of bounds");
    return row * size + column;
}

bool Board::isEmptyTile(const int row, const int column) const {
    Tile *tile = board[toOneDimensionIndex(row, column)];
    return dynamic_cast<EmptyTile *>(tile) != nullptr;
}

Board::Board(const std::vector<int> &board) {
    if (board.size() == 0) {
        throw std::invalid_argument("board is empty");
    }
    const int boardSize = sqrt(board.size());
    if (boardSize * boardSize != board.size()) {
        throw std::invalid_argument("board must be square shaped");
    }

    this->size = boardSize;
    this->board = std::vector<Tile *>();
    for (int i = 0; i < board.size(); i++) {
        if (board[i] == 0) {
            this->board.push_back(new EmptyTile(i));
        } else {
            this->board.push_back(new NumberTile(i, board[i]));
        }
    }
}

Board::~Board() {
    for (const auto tile: board) {
        delete tile;
    }
}

void Board::onTileClick(const int row, const int column) {
    if (isEmptyTile(row, column)) return;

    Tile *tile = board[toOneDimensionIndex(row, column)];

    if (row > 0 && isEmptyTile(row - 1, column)) {
        board[toOneDimensionIndex(row, column)] = board[toOneDimensionIndex(row - 1, column)];
        board[toOneDimensionIndex(row - 1, column)] = tile;
    } else if (row < size - 1 && isEmptyTile(row + 1, column)) {
        board[toOneDimensionIndex(row, column)] = board[toOneDimensionIndex(row + 1, column)];
        board[toOneDimensionIndex(row + 1, column)] = tile;
    } else if (column > 0 && isEmptyTile(row, column - 1)) {
        board[toOneDimensionIndex(row, column)] = board[toOneDimensionIndex(row, column - 1)];
        board[toOneDimensionIndex(row, column - 1)] = tile;
    } else if (column < size - 1 && isEmptyTile(row, column + 1)) {
        board[toOneDimensionIndex(row, column)] = board[toOneDimensionIndex(row, column + 1)];
        board[toOneDimensionIndex(row, column + 1)] = tile;
    }
}

int Board::getSize() const {
    return size;
}

Tile *Board::getTile(const int row, const int column) const {
    return board[toOneDimensionIndex(row, column)];
}

bool Board::isSolved() const {
    for (int i = 0; i < board.size(); i++) {
        if (board[i]->getOrdinal() != i) return false;
    }

    return true;
}

void Board::printBoard() const {
    std::stringstream ss;
    qDebug() << "-------------------";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            ss << board[toOneDimensionIndex(i, j)] << "|";
        }
        ss << board[toOneDimensionIndex(i, size - 1)];
        qDebug() << ss.str();
        ss.str("");
    }
    qDebug() << "-------------------";
}

//
// Created by szymon on 3/19/25.
//

#include "GameScreenViewModel.h"

#include "board/tiles/EmptyTile.h"
#include "board/tiles/NumberTile.h"

void GameScreenViewModel::startTimer() {
    if (timer == nullptr) {
        timer = new QTimer(this);
        timer->setInterval(1000);
        connect(timer, &QTimer::timeout, this, &GameScreenViewModel::onTimerTick);
        timer->start();
    }
}

void GameScreenViewModel::stopTimer() {
    if (timer == nullptr) return;
    timer->stop();
    delete timer;
    timer = nullptr;
}

void GameScreenViewModel::emitUpdateTimerState(const int time) {
    std::stringstream ss;

    ss << time / 60000;
    ss << ":";
    ss << std::setw(2) << std::setfill('0') << time / 1000 % 60;

    emit updateTimerState(QString::fromStdString(ss.str()));
}

void GameScreenViewModel::emitUpdateMovesCounterState(const int movesCounter) {
    emit updateMovesCounterState(QString("Moves: ") + QString::number(movesCounter));
}

void GameScreenViewModel::emitUpdateBoardState(const Board *board) {
    const auto boardSize = board->getSize();
    auto boardState = std::vector<QString>();
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            const auto tile = board->getTile(i, j);
            if (const auto numberTile = dynamic_cast<NumberTile *>(tile); numberTile != nullptr) {
                boardState.push_back(QString::number(numberTile->getValue()));
            } else if (const auto emptyTile = dynamic_cast<EmptyTile *>(tile); emptyTile != nullptr) {
                boardState.push_back("");
            }
        }
    }
    emit updateBoardState(boardState);
}

void GameScreenViewModel::onTimerTick() {
    gameDurationMillis += 1000;
    emitUpdateTimerState(gameDurationMillis);
}

GameScreenViewModel::GameScreenViewModel() {
    this->board = new Board({2, 8, 6, 7, 1, 5, 4, 3, 0});
}

GameScreenViewModel::~GameScreenViewModel() {
    if (timer != nullptr) {
        timer->stop();
        delete timer;
    }
    delete this->board;
}

void GameScreenViewModel::getInitialState() {
    emitUpdateBoardState(board);
    emitUpdateMovesCounterState(movesCounter);
    emitUpdateTimerState(gameDurationMillis);
    emit updateGameWonState(false);
}

void GameScreenViewModel::onBoardClick(const int row, const int column) {
    if (board->isSolved()) return;
    if (board->onTileClick(row, column) == false) return;

    if (board->isSolved()) {
        stopTimer();
        emit updateGameWonState(true);
    } else {
        startTimer();
    }

    emitUpdateMovesCounterState(++movesCounter);
    emitUpdateBoardState(board);
}

void GameScreenViewModel::onRestartClick() {
    stopTimer();
    gameDurationMillis = 0;
    movesCounter = 0;
    board->restart();

    emitUpdateBoardState(board);
    emitUpdateTimerState(gameDurationMillis);
    emitUpdateMovesCounterState(movesCounter);
    emit updateGameWonState(false);
}

//
// Created by szymon on 3/20/25.
//

#include "GameSettingsScreenViewModel.h"

GameSettingsScreenViewModel::GameSettingsScreenViewModel(const int boardSize, const QString timeLimitLiteral) {
    timeLimitMillis = 2 * 60 * 1000;
    this->boardSize = boardSize;
    this->timeLimitLiteral = timeLimitLiteral;
}

void GameSettingsScreenViewModel::onUpdateEnableTimeLimitCheckboxState(const bool enabled) {
}

void GameSettingsScreenViewModel::onUpdateTimeLimit(const QString &timeLimit) {
    timeLimitLiteral = timeLimit;
}

bool GameSettingsScreenViewModel::validateInput() {
    auto splitTime = timeLimitLiteral.split(":");

    if (splitTime.count() != 2) {
        qDebug("Wrong time format");
        return false;
    }

    bool ok;
    const auto mins = splitTime[0].toInt(&ok);
    if (!ok || mins < 0) {
        qDebug("Wrong mins format");
        return false;
    }
    const auto secs = splitTime[1].toInt(&ok);
    if (!ok || secs < 0 || secs >= 60) {
        qDebug("Wrong secs format");
        return false;
    }

    timeLimitMillis = mins * 60 * 1000 + secs * 1000;
    return true;
}

int GameSettingsScreenViewModel::getBoardSize() const {
    return boardSize;
}

int GameSettingsScreenViewModel::getTimeLimitMillis() const {
    return timeLimitMillis;
}

void GameSettingsScreenViewModel::onSetBoardSize(const int size) {
    this->boardSize = size;
    emit updateBoardPreviewState(size);
}

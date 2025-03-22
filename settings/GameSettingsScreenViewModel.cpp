//
// Created by szymon on 3/20/25.
//

#include "GameSettingsScreenViewModel.h"

GameSettingsScreenViewModel::GameSettingsScreenViewModel(const int boardSize) {
    timeLimitMillis = 2 * 60 * 1000;
    timeLimitEnabled = false;
    this->boardSize = boardSize;
}

void GameSettingsScreenViewModel::onUpdateEnableTimeLimitCheckboxState(const bool enabled) {
    this->timeLimitEnabled = enabled;
}

void GameSettingsScreenViewModel::onUpdateTimeLimit(QString &timeLimit) {
}

void GameSettingsScreenViewModel::onSetBoardSize(const int size) {
    this->boardSize = size;
    emit updateBoardPreviewState(size);
}

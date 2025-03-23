//
// Created by szymon on 3/23/25.
//

#include "ResultsStorage.h"

int ResultsStorage::getBestMovesCounter(const int boardSize) {
    const QSettings settings;

    const auto key = "bestMovesCounter" + QString::number(boardSize);
    return settings.value(key, -1).toInt();
}

int ResultsStorage::getBestTimeMs(const int boardSize) {
    const QSettings settings;

    const auto key = "bestTimeMs" + QString::number(boardSize);
    return settings.value(key, -1).toInt();
}

int ResultsStorage::upsertMovesCounter(const int boardSize, const int moves) {
    QSettings settings;

    const auto bestMovesCounter = getBestMovesCounter(boardSize);
    if (moves <= 0) return -1;

    const auto key = "bestMovesCounter" + QString::number(boardSize);
    if (bestMovesCounter == -1) {
        settings.setValue(key, moves);
        return moves;
    }
    if (moves < bestMovesCounter) {
        settings.setValue(key, moves);
        return moves;
    }

    return -1;
}

int ResultsStorage::upsertTimeMs(const int boardSize, const int timeMs) {
    QSettings settings;

    const auto bestTimeMs = getBestTimeMs(boardSize);
    if (timeMs <= 0) return -1;

    const auto key = "bestTimeMs" + QString::number(boardSize);
    if (bestTimeMs == -1) {
        settings.setValue(key, timeMs);
        return timeMs;
    }
    if (timeMs < bestTimeMs) {
        settings.setValue(key, timeMs);
        return timeMs;
    }

    return -1;
}

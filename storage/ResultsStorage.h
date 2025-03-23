//
// Created by szymon on 3/23/25.
//

#ifndef RESULTSSTORAGE_H
#define RESULTSSTORAGE_H
#include <QSettings>

class ResultsStorage {
public:
    ResultsStorage() = delete;

    static int getBestMovesCounter(int boardSize);

    static int getBestTimeMs(int boardSize);

    static int upsertMovesCounter(int boardSize, int moves);

    static int upsertTimeMs(int boardSize, int timeMs);
};


#endif //RESULTSSTORAGE_H

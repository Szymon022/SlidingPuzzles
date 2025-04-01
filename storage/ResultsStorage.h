//
// Created by szymon on 3/23/25.
//

#ifndef RESULTSSTORAGE_H
#define RESULTSSTORAGE_H
#include <QSettings>

/**
 * Wrapper for QSetting that enables easy querying and updating best moves counter and best times.
 * Every best move and time is associated with exactly 1 board size.
 */
class ResultsStorage {
public:
    ResultsStorage() = delete;

    /**
     * @param boardSize board size.
     * @return moves counter for the given board size.
     */
    static int getBestMovesCounter(int boardSize);

    /**
     * @param boardSize board size
     * @return best time in ms for the given board size
     */
    static int getBestTimeMs(int boardSize);

    /**
     * Inserts/Updates best moves counter for given board size.
     * @param boardSize board size
     * @param moves moves counter to be inserted
     * @return inserted moves counter or -1 if it was not updated
     */
    static int upsertMovesCounter(int boardSize, int moves);

    /**
     * Inserts/Updates best time in ms counter for given board size.
     * @param boardSize board size
     * @param timeMs to be inserted
     * @return inserted time or -1 if it was not updated
     */
    static int upsertTimeMs(int boardSize, int timeMs);
};


#endif //RESULTSSTORAGE_H

//
// Created by szymon on 3/19/25.
//

#ifndef GAMESCREENVIEWMODEL_H
#define GAMESCREENVIEWMODEL_H
#include <qobject.h>
#include <QTimer>

#include "board/Board.h"
#include <QSettings>

/**
 * View model for the GameScreen.
 */
class GameScreenViewModel : public QObject {
    Q_OBJECT

    QTimer *timer = nullptr;
    Board *board;
    int movesCounter{0};
    int gameDurationMillis{0};
    QSettings settings;
    int boardSize;
    bool isTimeLimitEnabled;
    int timeLimitMs;
    int gameEnded{false};

    void startTimer();

    void stopTimer();

    void emitUpdateTimerState(int time);

    void emitUpdateMovesCounterState(int movesCounter);

    void emitUpdateBoardState(const Board *board);

    void updateBestResult() const;

    QString getTimerLabel(int timeMs) const;

    void emitGameWonDialog();

signals:
    /**
     * Emitted when timer state is updated.
     * @param label timer label
     */
    void updateTimerState(QString label);

    /**
     * Emitted when moves counter is updated.
     * @param label moves counter label
     */
    void updateMovesCounterState(QString label);

    /**
     * Emitted when board state is updated.
     * @param board board state written in 1D vector row-wise.
     */
    void updateBoardState(std::vector<QString> &board);

    /**
     * Emitted when the game is won and the game won dialog should be visible.
     * @param yourMoves user moves label
     * @param bestMoves best moves label
     * @param yourTime user time label
     * @param bestTime best time label
     */
    void showGameWonDialog(QString yourMoves, QString bestMoves, QString yourTime, QString bestTime);

    /**
     * Emitted when the game is lost and the game lost dialog should be visible.
     */
    void showGameLostDialog();

private slots:
    /**
     * Handles timer tick event.
     */
    void onTimerTick();

public:
    GameScreenViewModel() = delete;

    /**
     * Creates view model with given parameters.
     * @param boardSize board size to be handled
     * @param timeLimitMs time limit. It is ignored if enableTimeLimit flag is set to true
     * @param enableTimeLimit flag to enable time limit provided by timeLimitMs parameter
     */
    explicit GameScreenViewModel(int boardSize, int timeLimitMs = 0, bool enableTimeLimit = false);

    ~GameScreenViewModel() override;

    /**
     * Emits signals with initial states. This should be called only once at the end of the GameScreen construction.
     */
    void getInitialState();

    /**
     * Handles board tile click.
     * @param row row of the tile clicked
     * @param column  column of the tile clicked
     */
    void onBoardClick(int row, int column);

    /**
     * Handles restart game butten click.
     */
    void onRestartClick();
};


#endif //GAMESCREENVIEWMODEL_H

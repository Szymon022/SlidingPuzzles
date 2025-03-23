//
// Created by szymon on 3/19/25.
//

#ifndef GAMESCREENVIEWMODEL_H
#define GAMESCREENVIEWMODEL_H
#include <qobject.h>
#include <QTimer>

#include "board/Board.h"
#include <QSettings>

class GameScreenViewModel : public QObject {
    Q_OBJECT

    QTimer *timer = nullptr;
    Board *board;
    int movesCounter{0};
    int gameDurationMillis{0};
    QSettings settings;

    void startTimer();

    void stopTimer();

    void emitUpdateTimerState(int time);

    void emitUpdateMovesCounterState(int movesCounter);

    void emitUpdateBoardState(const Board *board);

    void updateBestResult() const;

signals:
    void updateTimerState(QString label);

    void updateMovesCounterState(QString label);

    void updateBoardState(std::vector<QString> &board);

    void updateGameWonState(bool isGameWon);

private slots:
    void onTimerTick();

public:
    GameScreenViewModel() = delete;

    explicit GameScreenViewModel(int boardSize);

    ~GameScreenViewModel() override;

    void getInitialState();

    void onBoardClick(int row, int column);

    void onRestartClick();
};


#endif //GAMESCREENVIEWMODEL_H

//
// Created by szymon on 3/20/25.
//

#ifndef GAMESETTINGSSCREENVIEWMODEL_H
#define GAMESETTINGSSCREENVIEWMODEL_H
#include <qobject.h>


class GameSettingsScreenViewModel : public QObject {
    Q_OBJECT

    int boardSize;
    int timeLimitMillis;
    bool timeLimitEnabled;

    void emitUpdateBoardPreviewState();

signals:
    void updateBoardPreviewState(int boardSize);

public:
    explicit GameSettingsScreenViewModel(int boardSize);

    void onSetBoardSize(int size);

    void onUpdateEnableTimeLimitCheckboxState(bool enabled);

    void onUpdateTimeLimit(QString &timeLimit);
};


#endif //GAMESETTINGSSCREENVIEWMODEL_H

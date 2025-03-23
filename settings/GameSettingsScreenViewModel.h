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
    QString timeLimitLiteral;

    void emitUpdateBoardPreviewState();


signals:
    void updateBoardPreviewState(int boardSize);

public:
    GameSettingsScreenViewModel() = delete;

    GameSettingsScreenViewModel(int boardSize, QString timeLimitLiteral);

    void onSetBoardSize(int size);

    void onUpdateEnableTimeLimitCheckboxState(bool enabled);

    void onUpdateTimeLimit(const QString &timeLimit);

    bool validateInput();

    int getBoardSize() const;

    int getTimeLimitMillis() const;
};


#endif //GAMESETTINGSSCREENVIEWMODEL_H

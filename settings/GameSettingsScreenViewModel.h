//
// Created by szymon on 3/20/25.
//

#ifndef GAMESETTINGSSCREENVIEWMODEL_H
#define GAMESETTINGSSCREENVIEWMODEL_H
#include <qobject.h>


class GameSettingsScreenViewModel : public QObject {
    Q_OBJECT

signals:
    void updateBoardPreviewState(std::vector<QString> &boardState);

    void updateBoardSizeState(QString &selectedSize);

    void updateEnableTimeLimitCheckboxState(bool enabled);

    void updateTimeLimitEditTextState(QString &timeLimit);

public:
    explicit GameSettingsScreenViewModel();

    ~GameSettingsScreenViewModel();

    void onSetBoardSize(int size);

    void onEnableTimeLimitCheckboxState(bool enabled);

    void onUpdateTimeLimit(QString &timeLimit);
};


#endif //GAMESETTINGSSCREENVIEWMODEL_H

//
// Created by szymon on 3/20/25.
//

#ifndef GAMESETTINGSSCREEN_H
#define GAMESETTINGSSCREEN_H

#include <QWidget>

#include "GameSettingsScreenViewModel.h"
#include "../game/board/BoardPreview.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class GameSettingsScreen;
}

QT_END_NAMESPACE

class GameSettingsScreen : public QWidget {
    Q_OBJECT

signals:
    void navigateToMainMenu(bool popBackStack);

    void navigateToGameScreen(int boardSize, int timeLimitMs, bool enableTimeLimit);

private slots:
    void onUpdateBoardPreviewSize(int boardSize) const;

public:
    explicit GameSettingsScreen(QWidget *parent = nullptr);

    ~GameSettingsScreen() override;

private:
    Ui::GameSettingsScreen *ui;
    GameSettingsScreenViewModel *viewModel;
    std::vector<int> boardSizes;
    BoardPreview *boardPreviewWidget;
};


#endif //GAMESETTINGSSCREEN_H

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

/**
 * Class representing game setting screen where user selects gama parameters: board size, enables/disable time limit, sets time limit.
 */
class GameSettingsScreen : public QWidget {
    Q_OBJECT

signals:
    /**
     * Emitted if the user clicks return to main menu button.
     * @param popBackStack if this view should be popped from the navigation stack
     */
    void navigateToMainMenu(bool popBackStack);

    /**
     * Emitted if the user clicks start game button.
     * @param boardSize board size that the player will solve
     * @param timeLimitMs time limit. It is disabled unless enableTimeLimit flag is set to true.
     * @param enableTimeLimit if the time limit should be enabled or not
     */
    void navigateToGameScreen(int boardSize, int timeLimitMs, bool enableTimeLimit);

private slots:
    /**
     * Handles preview board size update.
     * @param boardSize board size that the preview should represent
     */
    void onUpdateBoardPreviewSize(int boardSize) const;

public:
    /**
     * @param parent parent of this screen.
     */
    explicit GameSettingsScreen(QWidget *parent = nullptr);

    ~GameSettingsScreen() override;

private:
    Ui::GameSettingsScreen *ui;
    GameSettingsScreenViewModel *viewModel;
    std::vector<int> boardSizes;
    BoardPreview *boardPreviewWidget;
};


#endif //GAMESETTINGSSCREEN_H

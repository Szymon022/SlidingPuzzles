//
// Created by szymon on 3/20/25.
//

#ifndef GAMESETTINGSSCREENVIEWMODEL_H
#define GAMESETTINGSSCREENVIEWMODEL_H
#include <qobject.h>

/**
 * View model for GameSettingsScreen.
 */
class GameSettingsScreenViewModel : public QObject {
    Q_OBJECT

    int boardSize;
    int timeLimitMillis;
    QString timeLimitLiteral;

signals:
    /**
     * Emitted when user selects board size from the combo box.
     * @param boardSize board size that the preview should represent
     */
    void updateBoardPreviewState(int boardSize);

public:
    GameSettingsScreenViewModel() = delete;

    /**
     * Creates view model with initial state provided through parameters.
     * @param boardSize initially selected board size
     * @param timeLimitLiteral initially set time limit literal
     */
    GameSettingsScreenViewModel(int boardSize, QString timeLimitLiteral);

    /**
     * Sets board preview size.
     * @param size new board preview size
     */
    void onSetBoardSize(int size);

    /**
     * Sets time limit according to provided literal that is parsed into ms.
     * @param timeLimit time limit literal in format m:ss. Example: 2:52
     */
    void onUpdateTimeLimit(const QString &timeLimit);

    /**
     * Validates time limit literal.
     * @return true if the time limit input is valid
     */
    bool validateInput();

    /**
     * @return board size
     */
    int getBoardSize() const;

    /**
     *
     * @return time limit in ms
     */
    int getTimeLimitMillis() const;
};


#endif //GAMESETTINGSSCREENVIEWMODEL_H

//
// Created by szymon on 3/11/25.
//

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class MenuScreen;
}

QT_END_NAMESPACE

/**
 * MenuScreen class.
 */
class MenuScreen : public QWidget {
    Q_OBJECT

public:
    /**
     * @param parent parent of the MenuScreen.
     */
    explicit MenuScreen(QWidget *parent = nullptr);

    ~MenuScreen() override;

signals:
    /**
     * Emitted when start game button is clicked.
     */
    void navigateToGameSettings();

private slots:
    /**
     * Handles new game clicked.
     */
    void onNewGameClicked();

    /**
     * Handles exit game clicked.
     */
    void onExitGameClicked();

private:
    Ui::MenuScreen *ui;
};


#endif //MAINMENU_H

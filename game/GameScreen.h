//
// Created by szymon on 3/12/25.
//

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class GameScreen; }
QT_END_NAMESPACE

class GameScreen : public QWidget {
Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = nullptr);
    ~GameScreen() override;

private slots:
    void onNavigateToMainMenu();

signals:
    void navigateToMainMenu();

private:
    Ui::GameScreen *ui;
};


#endif //GAMESCREEN_H

#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow main_window;
    main_window.show();

    QCoreApplication::setOrganizationName("PW");
    QCoreApplication::setApplicationName("sliding_puzzles");
    return QApplication::exec();
}

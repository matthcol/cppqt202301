#include "mainwindow.h"

#include <QApplication>
#include "personlistmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create model
    PersonListModel personListModel;
    // create GUI
    MainWindow w;
    w.setPersonListModel(&personListModel);
    w.show();
    return a.exec();
}

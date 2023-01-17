#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "personlistmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    PersonListModel *personListModel() const;
    void setPersonListModel(PersonListModel *newPersonListModel);

private slots:
    void on_btn_register_clicked();

    void on_btn_joke_clicked();

    void on_btn_add_langs_clicked();

    void on_btn_clear_langs_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *langListModel;
    PersonListModel *m_personListModel;
};
#endif // MAINWINDOW_H

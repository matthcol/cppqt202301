#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_register_clicked();

    void on_btn_joke_clicked();

    void on_btn_add_langs_clicked();

    void on_btn_clear_langs_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *langListModel;
};
#endif // MAINWINDOW_H

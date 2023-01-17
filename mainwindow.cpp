#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // additional settings of UI here
    // 1. Combo Box: langs
    langListModel = new QStringListModel();
    QStringList langList;
    langList << "FR" << "EN" << "JP";
    langListModel->setStringList(langList);
    ui->cb_lang->setModel(langListModel);
    // 2. List View: all langs
    QStringList allLangList = {"FR", "EN", "JP", "FI", "FJ" };
    QStringListModel *allLangListModel = new QStringListModel(allLangList);
    ui->lv_alllangs->setModel(allLangListModel);
}

MainWindow::~MainWindow()
{
    delete ui->cb_lang->model();
    delete ui;
}


void MainWindow::on_btn_register_clicked()
{
    QString lastname = ui->le_lastname->text();
    QString firstname = ui->le_firstname->text();
    qint32 level = ui->spx_level->value();
    QDate birthdate = ui->dt_birthdate->date();
    QString lang = ui->cb_lang->currentText();
    qDebug() << "Register: ";
    qDebug() << " - lastname = " << lastname;
    qDebug() << " - firstname = " <<  firstname;
    qDebug() << " - level = " << level;
    qDebug() << " - birthdate = " << birthdate;
    qDebug() << " - lang = " << lang
             << " (choix " << ui->cb_lang->currentIndex()
             << " ; data = " << ui->cb_lang->currentData(Qt::DisplayRole)
             << ")";
}


void MainWindow::on_btn_joke_clicked()
{
    // Joke 1: change lang choices
    QStringList langList {"ES", "DE", "SW"};
    QStringListModel* newLangListModel = new QStringListModel(langList);
    delete langListModel;
    langListModel = newLangListModel;
    ui->cb_lang->setModel(newLangListModel);

    // Joke 2: change label text
    ui->lbl_birthdate->setText("Birthday");
}


void MainWindow::on_btn_add_langs_clicked()
{
   QModelIndex indexChoice = ui->lv_alllangs->currentIndex();
   if (!indexChoice.isValid()) {
       return;
   }
   QString newLang = ui->lv_alllangs
           ->model()
           ->data(indexChoice)
           .toString();
   if (langListModel->stringList().contains(newLang)){
       return;
   }
   qint32 row = langListModel->rowCount();
   langListModel->insertRow(row);
   langListModel->setData(langListModel->index(row), newLang);
   langListModel->sort(0);
}


void MainWindow::on_btn_clear_langs_clicked()
{
    ui->cb_lang->clear();
}


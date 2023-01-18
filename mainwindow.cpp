#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringListModel>
#include <QFileDialog>
#include <QJsonDocument>
#include "person.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // model settings

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

    // signal/slot connections
    // version QT 4
//    connect(ui->frm_persons,
//            SIGNAL(personSelected(Person*)),
//            ui->frm_viewPersonDetail,
//            SLOT(viewPerson(Person*)));
    // version QT 5
    connect(ui->frm_persons,
            &ViewPersonsFrame::personSelected,
            ui->frm_viewPersonDetail,
            &ViewPersonDetailFrame::viewPerson);
    connect(ui->frm_persons,
            &ViewPersonsFrame::personSelected,
            [](Person *p){ qDebug() << p;});
    connect(ui->frm_persons,
            &ViewPersonsFrame::personSelected,
            [](){ qDebug() << "A person has been selected";});
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
    Person *person = new Person(lastname, firstname, level, birthdate, lang);
    m_personListModel->addPerson(person);
    qDebug() << "Person registered: " << *person;
}


void MainWindow::on_btn_joke_clicked()
{
    // dialog without static predefined method
    QMessageBox confirmMessageBox;
    confirmMessageBox.setText("Ready to joke?");
    confirmMessageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    confirmMessageBox.setDefaultButton(QMessageBox::Ok);
    int choice = confirmMessageBox.exec();
    if (choice == QMessageBox::Cancel) return;

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
    // confirm before clear
    QMessageBox::StandardButton choice = QMessageBox::question(
            this,
            "Confirm clear",
            "Are you sure to remove all langs");
    if (choice == QMessageBox::Yes) ui->cb_lang->clear();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton choice = confirmQuitDialog();
    if (choice == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}

PersonListModel *MainWindow::personListModel() const
{
    return m_personListModel;
}

void MainWindow::setPersonListModel(PersonListModel *newPersonListModel)
{
    m_personListModel = newPersonListModel;
    ui->frm_persons->setPersonListModel(newPersonListModel);
}



void MainWindow::on_actionQuit_triggered()
{
    QMessageBox::StandardButton choice = confirmQuitDialog();
    if (choice == QMessageBox::Yes) QApplication::quit();
}

QMessageBox::StandardButton MainWindow::confirmQuitDialog()
{
    return QMessageBox::question(
                this,
                "Quit confirm",
                "Are you sure to quit the app",
                QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                QMessageBox::Cancel);
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                QString(),
                tr("Json (*.json)"));
    qDebug() << "JSon file selected: " << filename;
    bool ok = m_personListModel->loadFromJSon(filename);
}


void MainWindow::on_actionSave_triggered()
{

}


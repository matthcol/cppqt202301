#include "viewpersonsframe.h"
#include "ui_viewpersonsframe.h"

ViewPersonsFrame::ViewPersonsFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ViewPersonsFrame)
{
    ui->setupUi(this);
}

ViewPersonsFrame::~ViewPersonsFrame()
{
    delete ui;
}

PersonListModel *ViewPersonsFrame::personListModel() const
{
    return m_personListModel;
}

void ViewPersonsFrame::setPersonListModel(PersonListModel *newPersonListModel)
{
    m_personListModel = newPersonListModel;
    ui->lv_persons->setModel(newPersonListModel);
}

QListView *ViewPersonsFrame::personListView() const
{
    return ui->lv_persons;
}

void ViewPersonsFrame::on_lv_persons_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;
    QVariant persontVariant = ui->lv_persons
            ->model()
            ->data(index, Qt::EditRole);
    // TODO: check if variant not empty
    Person *person = persontVariant.value<Person *>();
    qDebug() << "A person has been selected at index "
             << index.row()
             << " : "
             << *person;
    emit personSelected(person);
}


#include "viewpersondetailframe.h"
#include "ui_viewpersondetailframe.h"

ViewPersonDetailFrame::ViewPersonDetailFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ViewPersonDetailFrame)
{
    ui->setupUi(this);
}

ViewPersonDetailFrame::~ViewPersonDetailFrame()
{
    delete ui;
}

void ViewPersonDetailFrame::viewPerson(const Person &person)
{
    ui->lbl_currentPerson->setText(person.toString());
}

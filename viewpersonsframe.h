#ifndef VIEWPERSONSFRAME_H
#define VIEWPERSONSFRAME_H

#include <QFrame>
#include <QListView>
#include "personlistmodel.h"

namespace Ui {
class ViewPersonsFrame;
}

class ViewPersonsFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ViewPersonsFrame(QWidget *parent = nullptr);
    ~ViewPersonsFrame();

    PersonListModel *personListModel() const;
    void setPersonListModel(PersonListModel *newPersonListModel);
    QListView *personListView() const;

signals:
    void personSelected(const Person *person);

private slots:
    void on_lv_persons_clicked(const QModelIndex &index);

private:
    Ui::ViewPersonsFrame *ui;
    PersonListModel *m_personListModel;

};

#endif // VIEWPERSONSFRAME_H

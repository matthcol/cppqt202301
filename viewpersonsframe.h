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

private:
    Ui::ViewPersonsFrame *ui;
    PersonListModel *m_personListModel;

};

#endif // VIEWPERSONSFRAME_H

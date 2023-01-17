#ifndef VIEWPERSONDETAILFRAME_H
#define VIEWPERSONDETAILFRAME_H

#include <QFrame>
#include "person.h"

namespace Ui {
class ViewPersonDetailFrame;
}

class ViewPersonDetailFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ViewPersonDetailFrame(QWidget *parent = nullptr);
    ~ViewPersonDetailFrame();

public slots:
    void viewPerson(const Person* person);

private:
    Ui::ViewPersonDetailFrame *ui;
};

#endif // VIEWPERSONDETAILFRAME_H

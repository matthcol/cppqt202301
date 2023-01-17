#ifndef PERSONLISTMODEL_H
#define PERSONLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "person.h"

class PersonListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PersonListModel(QObject *parent = nullptr);

signals:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void addPerson(Person *person);

private:
    QList<Person*> m_personList;
};

#endif // PERSONLISTMODEL_H

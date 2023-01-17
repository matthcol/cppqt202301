#include "personlistmodel.h"

PersonListModel::PersonListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int PersonListModel::rowCount(const QModelIndex &parent) const
{
    return m_personList.size();
}

QVariant PersonListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        const Person *person = m_personList[index.row()];
        return QVariant(person->toString());
    }
    return QVariant();
}

void PersonListModel::addPerson(Person *person)
{
    int lastRow = m_personList.size();
    beginInsertRows(QModelIndex(),lastRow,lastRow);
    m_personList << person;
    endInsertRows();
}

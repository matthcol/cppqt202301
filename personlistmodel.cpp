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
    Person *person = m_personList[index.row()];
    switch (role) {
        case Qt::DisplayRole:
            return QVariant(person->toString()); // return person->toString();
        case Qt::EditRole:{
            return QVariant::fromValue(person);
        }
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

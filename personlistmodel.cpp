#include "personlistmodel.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

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

bool PersonListModel::loadFromJSon(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return false;
    QByteArray contentText = file.readAll();
    qDebug() << contentText;
    file.close();
    // convert to JSON Document
    QJsonDocument personsJson = QJsonDocument::fromJson(contentText);
    if (personsJson.isNull()) return false;
    if (!personsJson.isArray()) return false;
    QJsonArray personsJsonArray = personsJson.array();
    QList<Person*> newPersonList;
    for (auto personJsonValueRef: personsJsonArray) {
        if (!personJsonValueRef.isObject()) return false;
        QJsonObject personJson = personJsonValueRef.toObject();
        qDebug() << "JSON Person: " << personJson;
        Person *person = Person::fromJson(personJson);
        if (person == nullptr) return false;
        qDebug() << "Person: " << *person;
        newPersonList << person;
    }
    // TODO: replace current list by new local list
    qDebug() << "Person list loaded: " << newPersonList;
    return true;
}

void PersonListModel::saveToJson(QString filename)
{

}

#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QJsonObject>

class Person: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lang READ lang WRITE setLang NOTIFY langChanged)

public:
    explicit Person(QObject *parent = nullptr);
    Person(
            const QString &lastname,
            const QString &firstname,
            qint32 level,
            const QDate &birthdate,
            const QString &lang,
            QObject *parent = nullptr);
    QString lastname() const;
    void setLastname(const QString &newLastname);
    QString firstname() const;
    void setFirstname(const QString &newFirstname);
    qint32 level() const;
    void setLevel(qint32 newLevel);
    QDate birthdate() const;
    void setBirthdate(const QDate &newBirthdate);
    QString lang() const;
    void setLang(const QString &newLang);
    QString toString() const;

    static Person *fromJson(const QJsonObject &personJson);

signals:
    void langChanged();

private:
    QString m_lastname;
    QString m_firstname;
    qint32 m_level;
    QDate m_birthdate;
    QString m_lang;
};

QDebug &operator<<(QDebug &out, const Person &person);

Q_DECLARE_METATYPE(Person*)

#endif // PERSON_H

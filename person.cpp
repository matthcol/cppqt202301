#include "person.h"

Person::Person(QObject *parent): QObject(parent)
{

}

Person::Person(const QString &lastname,
               const QString &firstname,
               qint32 level,
               const QDate &birthdate,
               const QString &lang, QObject *parent
): QObject(parent),
    m_lastname(lastname),
    m_firstname(firstname),
    m_level(level),
    m_birthdate(birthdate),
    m_lang(lang)
{

}

QString Person::lastname() const
{
    return m_lastname;
}

void Person::setLastname(const QString &newLastname)
{
    m_lastname = newLastname;
}

QString Person::firstname() const
{
    return m_firstname;
}

void Person::setFirstname(const QString &newFirstname)
{
    m_firstname = newFirstname;
}

qint32 Person::level() const
{
    return m_level;
}

void Person::setLevel(qint32 newLevel)
{
    m_level = newLevel;
}

QDate Person::birthdate() const
{
    return m_birthdate;
}

void Person::setBirthdate(const QDate &newBirthdate)
{
    m_birthdate = newBirthdate;
}

QString Person::lang() const
{
    return m_lang;
}

void Person::setLang(const QString &newLang)
{
    if (m_lang == newLang)
        return;
    m_lang = newLang;
    emit langChanged();
}

QString Person::toString() const
{
    return QString("%1 %2 (%3)")
            .arg(m_lastname, m_firstname, m_lang);
}

QDebug &operator<<(QDebug &out, const Person &person){
    return out << person.toString();
}

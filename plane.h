#ifndef PLANE_H
#define PLANE_H

#include <QObject>

class Plane : public QObject
{
    Q_OBJECT
public:
    explicit Plane(QObject *parent = nullptr);

signals:

};

#endif // PLANE_H

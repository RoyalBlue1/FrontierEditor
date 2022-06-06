#ifndef POSITIONHANDLER_H
#define POSITIONHANDLER_H

#include <QObject>


class PositionHandler : public QObject
{
    Q_OBJECT
public:
    explicit PositionHandler(QObject *parent = nullptr);
    PositionHandler(QObject *parent,const char* name);
    ~PositionHandler();
    QVector<QVector3D*> *getMapPositons();
    void clear();
    void addPosition(QVector3D *pos);
    void removeAll();
    QVector3D* removePosition(int index);
    //QColor color;
    const QString name;
signals:
        void positionChanged();
private:
    QVector<QVector3D*> positions;

};

#endif // POSITIONHANDLER_H

#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <QAbstractItemModel>
#include "projectitem.h"

class ProjectModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit ProjectModel(QObject *parent = 0);
    int rowCount(const QModelIndex & /*parent*/) const;
    int columnCount(const QModelIndex & /*parent*/) const;
    //QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    QVariant data(const QModelIndex &index, int role) const;


    
signals:
    
public slots:

private:
    ProjectItem *rootItem;
    
};

#endif // PROJECTMODEL_H

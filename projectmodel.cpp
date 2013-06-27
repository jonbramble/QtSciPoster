#include "projectmodel.h"

ProjectModel::ProjectModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Files" << "Size";
}

int ProjectModel::rowCount(const QModelIndex & /*parent*/) const{
    return 5;
}

int ProjectModel::columnCount(const QModelIndex & /*parent*/) const{
    return 2;
}

QModelIndex ProjectModel::index(int row, int column, const QModelIndex &parent) const{
    //return createIndex(row,column,0);
}

QModelIndex ProjectModel::parent(const QModelIndex &child) const{

}

QVariant ProjectModel::data(const QModelIndex &index, int role) const{

}

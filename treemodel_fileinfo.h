/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 11-03-2017
///		Date update	: 12-03-2017
///		Comment		:
/// ============================================================================

#ifndef __TREEMODEL_FILEINFO_H__
#define __TREEMODEL_FILEINFO_H__

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class TreeItem;

//! [0]
class treemodel_fileinfo : public QAbstractItemModel
{
    Q_OBJECT

public:
    treemodel_fileinfo( QObject *parent = 0 );
    ~treemodel_fileinfo();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    //-------------------------------------------------------------------------
    TreeItem* root( )
    {
        return this->rootItem;
    }

private:

    TreeItem *rootItem = nullptr;
};
//! [0]

#endif//__TREEMODEL_FILEINFO_H__

#ifndef PRODUCTSTABLEMODEL_H
#define PRODUCTSTABLEMODEL_H

#include <QtSql/QSqlQueryModel>
#include "../Database/ProductDatabase.h"

class ProductsTableModel : public QSqlQueryModel {
    Q_OBJECT
public:
    ProductsTableModel(QObject *parent = nullptr);
    ~ProductsTableModel() = default;
public:
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    void removeRecords(const QModelIndexList& indices);

    void update();
private:
    ID getIdFromIndex(const QModelIndex &index);
private:
    ProductDatabase m_database;
};

#endif // PRODUCTSTABLEMODEL_H

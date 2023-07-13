
#ifndef BILLTABLEMODEL_H
#define BILLTABLEMODEL_H


#include <QtSql/QSqlQueryModel>
#include "../Database/ProductDatabase.h"


class BillTableModel:QSqlQueryModel
{
    Q_OBJECT

public:

    BillTableModel(QObject *parent = nullptr);
    ~BillTableModel()=default;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    void fetchProduct(ID id);
    ID indexToID(const QModelIndex& index);
    void update();

public:
    QList<QPair<std::string,int>> tableData;
private:
    ProductDatabase m_database;
    Product m_product;

};

#endif // BILLTABLEMODEL_H


#include "BillTableModel.h"
#include <QtSql/QSqlQuery>

BillTableModel::BillTableModel(QObject *parent):
    QSqlQueryModel(parent)
{
    setHeaderData(0,Qt::Horizontal,"Product Name");
    setHeaderData(1,Qt::Horizontal,"Price");

}

void BillTableModel::fetchProduct(ID id){
    m_product = m_database.getProduct(id);
}


ID BillTableModel::indexToID(const QModelIndex& index){
    QModelIndex idIndex = QSqlQueryModel::index(index.row(),0);
    ID id = data(idIndex).toString();
    return id;
}

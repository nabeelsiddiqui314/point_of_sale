#include "ProductsTableModel.h"

ProductsTableModel::ProductsTableModel(QObject *parent)
    : QSqlQueryModel(parent) {
    update();
}

Qt::ItemFlags ProductsTableModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);

    if (index.column() == 1 || index.column() == 2) {
        flags |= Qt::ItemIsEditable;
    }

    return flags;
}

bool ProductsTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.column() == 0) {
        return false;
    }

    ID id = getIdFromIndex(index);

    bool isDataModified;

    if (index.column() == 1) {
        auto name = value.toString();
        isDataModified = m_database.modifyProductName(id, name);
    }
    else if (index.column() == 2) {
        bool isValidNumber;
        int price = value.toInt(&isValidNumber);

        if (!isValidNumber) {
            return false;
        }

        isDataModified = m_database.modifyProductPrice(id, price);
    }

    update();

    return isDataModified;
}

void ProductsTableModel::removeRecords(const QModelIndexList& indices) {
    for (auto& index : indices) {
        ID id = getIdFromIndex(index);
        m_database.deleteProduct(id);
    }
    update();
}

void ProductsTableModel::update() {
    setQuery("select * from products");

    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "Name");
    setHeaderData(2, Qt::Horizontal, "Price");
}

ID ProductsTableModel::getIdFromIndex(const QModelIndex &index) {
    QModelIndex idIndex = QSqlQueryModel::index(index.row(), 0);
    ID id = data(idIndex).toString();
    return id;
}

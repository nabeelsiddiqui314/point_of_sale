#include "BillModel.h"

BillModel::BillModel(QObject *parent)
    : QAbstractTableModel(parent) {

}

//QVariant BillModel::headerData(int section, Qt::Orientation orientation, int role) const {
//    return QString("test");
//}

//bool BillModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role) {
//    if (value != headerData(section, orientation, role)) {
//        // FIXME: Implement me!
//        emit headerDataChanged(orientation, section, section);
//        return true;
//    }
//    return false;
//}


int BillModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return 0;

    return m_bill.getItemCount();
}

int BillModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return 0;

    return 4;
}

QVariant BillModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    BillItem item = m_bill.getItemAt(index.row());

    QVariant cellValue;

    switch (index.column()) {
    case 0:
        cellValue = item.id;
        break;
    case 1:
        cellValue = item.product.name;
        break;
    case 2:
        cellValue = item.product.price;
        break;
    case 3:
        cellValue = item.quantity;
        break;
    }

    return cellValue;
}

bool BillModel::setData(const QModelIndex &index, const QVariant& value, int role) {
    if (data(index, role) == value)
        return false;

    if (index.column() != 3)
        return false;

    bool isNumerical;
    int quantity = value.toInt(&isNumerical);

    if (!isNumerical || quantity < 1)
        return false;

    m_bill.changeQuantityAt(index.row(), quantity);

    emit dataChanged(index, index, {role});

    return true;
}

Qt::ItemFlags BillModel::flags(const QModelIndex& index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;

    auto flags = QAbstractItemModel::flags(index);

    if (index.column() == 3) {
        flags |= Qt::ItemIsEditable;
    }

    return flags;
}

bool BillModel::addItem(const ID& id) {
    if (!m_database.doesProductExist(id)) {
        return false;
    }

    if (!m_bill.doesItemExist(id)) {
        beginInsertRows(QModelIndex(), m_bill.getItemCount(), m_bill.getItemCount());
        m_bill.addItem(id);
        endInsertRows();
    }
    else {
        m_bill.addItem(id);
        int row = m_bill.getIndexFromID(id);
        auto index = QAbstractTableModel::index(row, 3);
        emit dataChanged(index, index);
    }

    return true;
}

void BillModel::removeItems(const QModelIndexList& indices) {
    if (indices.empty()) {
        return;
    }

    auto index = indices[0];

    beginRemoveRows(QModelIndex(), index.row(), index.row());
    m_bill.removeItemAt(index.row());
    endRemoveRows();
}

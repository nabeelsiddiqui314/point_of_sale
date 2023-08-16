#ifndef BILLMODEL_H
#define BILLMODEL_H

#include <QAbstractTableModel>

#include "../Bill/Bill.h"

class BillModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BillModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    bool addItem(const ID& id);
    void removeItems(const QModelIndexList& indices);

    int getTotal() const;
signals:
    void billChanged();
private:
    Bill m_bill;
    ProductDatabase m_database;
};

#endif // BILLMODEL_H

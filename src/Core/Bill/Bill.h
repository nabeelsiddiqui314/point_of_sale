#ifndef BILL_H
#define BILL_H

#include "../Database/ProductDatabase.h"

struct BillItem {
    ID id;
    Product product;
    int quantity;
};

class Bill {
public:
    Bill() = default;
    ~Bill() = default;
public:
    void addItem(const ID& id);
    void changeQuantityAt(int index, int newQuantity);

    void removeItemAt(int index);

    bool doesItemExist(const ID& id) const;
    int getIndexFromID(const ID& id) const;

    BillItem getItemAt(int index) const;
    int getItemCount() const;
private:
    std::vector<BillItem> m_items;
    ProductDatabase m_database;
};

#endif // BILL_H

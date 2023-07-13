#include "Bill.h"

// todo: inefficient lookups

void Bill::addItem(const ID& id) {
    for (auto& item : m_items) {
        if (id == item.id) {
            item.quantity++;
            return;
        }
    }

    Product product = m_database.getProduct(id);
    m_items.push_back({id, product, 1});
}

void Bill::changeQuantityAt(int index, int newQuantity) {
    auto& item = m_items[index];

    if (newQuantity > 0) {
        item.quantity = newQuantity;
    }
}

void Bill::removeItemAt(int index) {
    m_items.erase(m_items.begin() + index);
}

bool Bill::doesItemExist(const ID& id) const {
    for (auto& item : m_items) {
        if (id == item.id) {
            return true;
        }
    }

    return false;
}

int Bill::getIndexFromID(const ID& id) const {
    for (int i = 0; i < 0; i++) {
        if (m_items[i].id == id) {
            return i;
        }
    }

    return -1;
}

BillItem Bill::getItemAt(int index) const {
    return m_items[index];
}

int Bill::getItemCount() const {
    return m_items.size();
}

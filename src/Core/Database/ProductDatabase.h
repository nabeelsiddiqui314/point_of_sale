#ifndef PRODUCTDATABASE_H
#define PRODUCTDATABASE_H

#include <QString>
#include <QtSql/QSqlDatabase>

#include "Product.h"

typedef QString ID;

class ProductDatabase {
public:
    ProductDatabase();
    ~ProductDatabase() = default;  
public:
    static void create(const QString& applicationPath);

    bool insertProduct(const ID& id, const Product& product);
    void deleteProduct(const ID& id);

    bool modifyProductName(const ID& id, const QString& name);
    bool modifyProductPrice(const ID& id, int price);

    bool doesProductExist(const ID& id);

    Product getProduct(const ID& id);
private:
    QSqlDatabase m_database;
};

#endif // PRODUCTDATABASE_H

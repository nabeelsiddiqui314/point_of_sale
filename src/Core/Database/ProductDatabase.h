#ifndef PRODUCTDATABASE_H
#define PRODUCTDATABASE_H

#include <QString>
#include <QtSql/QSqlDatabase>

#include "Product.h"

class ProductDatabase {
public:
    ProductDatabase();
    ~ProductDatabase() = default;  
public:
    static void create(const QString& applicationPath);

    bool insertProduct(int id, const Product& product);
    void deleteProduct(int id);

    bool doesProductExist(int id);

    Product getProduct(int id);
private:
    QSqlDatabase m_database;
};

#endif // PRODUCTDATABASE_H

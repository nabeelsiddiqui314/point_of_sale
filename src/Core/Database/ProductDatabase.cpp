#include "ProductDatabase.h"
#include <QtSql/QSqlQuery>

ProductDatabase::ProductDatabase() {
    m_database = QSqlDatabase::database();
}

void ProductDatabase::create(const QString& applicationPath) {
    auto database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(applicationPath + "/products.db");

    database.open();

    QSqlQuery query;
    query.exec("create table if not exists products (id int, name varchar(50), price int)");
    database.close();
}


bool ProductDatabase::insertProduct(int id, const Product& product) {
    if (doesProductExist(id))
        return false;

    QSqlQuery query;
    query.prepare("insert into products values (:id, :name, :price)");
    query.bindValue(":id", id);
    query.bindValue(":name", product.name);
    query.bindValue(":price", product.price);

    query.exec();

    return true;
}

void ProductDatabase::deleteProduct(int id) {
    if (doesProductExist(id)) {
        QSqlQuery query;
        query.prepare("delete from products where id = :id");
        query.bindValue(":id", id);

        query.exec();
    }
}

bool ProductDatabase::doesProductExist(int id) {
    QSqlQuery query;
    query.prepare("select * from products where id = :id");
    query.bindValue(":id", id);

    query.exec();

    if (query.next())
        return true;

    return false;
}

Product ProductDatabase::getProduct(int id) {
    QSqlQuery query;
    query.prepare("select * from products where id = :id");
    query.bindValue(":id", id);

    query.exec();

    query.next();

    Product product;
    product.name = query.value(1).toString();
    product.price = query.value(2).toInt();

    return product;
}
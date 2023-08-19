#include <stdio.h>
#include "mysql.h"
int main() {
    // 初始化MySQL对象
    MYSQL mysql;
    mysql_init(&mysql);

    // 连接MySQL数据库
    const char* host = "127.0.0.1";//mysql服务器地址
    const char* user = "root";//账号
    const char* password = "123456";//密码
    const char* database = "mydb";//数据库名称
    unsigned int port = 3306;
    if (!mysql_real_connect(&mysql, host, user, password, database, port, NULL, 0)) {
        fprintf(stderr, "Failed to connect to database: %s\n", mysql_error(&mysql));
        return 1;
    }

    // 执行查询语句
    const char* query = "SELECT * FROM mytable";
    if (mysql_query(&mysql, query)) {
        fprintf(stderr, "Query error: %s\n", mysql_error(&mysql));
        return 1;
    }

    // 获取查询结果
    MYSQL_RES* result = mysql_store_result(&mysql);
    if (!result) {
        fprintf(stderr, "Failed to get result set: %s\n", mysql_error(&mysql));
        return 1;
    }

    // 遍历结果集
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        // 获取每一行的数据
        unsigned int num_fields = mysql_num_fields(result);
        for (unsigned int i = 0; i < num_fields; ++i) {
            printf("%s ", row[i]);
        }
        printf("\n");
    }

    // 释放结果集和关闭连接
    mysql_free_result(result);
    mysql_close(&mysql);

    return 0;
}

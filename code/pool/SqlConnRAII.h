/*
 * @Author       : kong
 * @Date         : 2022-05-29
 */

#ifndef SQLCONNRAII_H
#define SQLCONNRAII_H
#include "SqlConnPool.h"



class SqlConnRAII {
public:
    SqlConnRAII(MYSQL** sql,SqlConnPool *connpool) {
        assert(connpool);
        *sql = connpool->GetConn();
        sql_ = *sql;
        connpool_ = connpool;
    }
    ~SqlConnRAII() {
        if(sql_) connpool_->FreeConn(sql_);
    }

private:
    MYSQL *sql_;
    SqlConnPool* connpool_;
};


#endif //SQLCONNRAII_H
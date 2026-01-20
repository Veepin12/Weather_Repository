#include <iostream>
#include <mysql/mysql.h>

using namespace std;

int main() {
    MYSQL *conn;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(
            conn,
            "localhost",
            "root",
            "virat",          // password
            "cppdb",     // database
            0, NULL, 0)) {

        cout << "❌ Connection failed: "
                  << mysql_error(conn) << endl;
        return 1;
    }

    cout << "✅ CONNECTED SUCCESSFULLY (MySQL C API)" << endl;

    mysql_close(conn);
    return 0;
}
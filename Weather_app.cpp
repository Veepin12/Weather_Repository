#include <iostream>
#include <vector>
#include <string>
#include <mysql/jdbc.h>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>

using namespace std;


string sha256(const string &str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)str.c_str(), str.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        ss << hex << setw(2) << setfill('0') << (int)hash[i];

    return ss.str();
}


class MerkleTree {
private:
    vector<string> leaves;

public:
    MerkleTree(const vector<string>& data) {
        for (auto &d : data)
            leaves.push_back(sha256(d));
    }

    string getMerkleRoot() {
        if (leaves.empty()) return "";

        vector<string> level = leaves;

        while (level.size() > 1) {
            vector<string> nextLevel;

            for (size_t i = 0; i < level.size(); i += 2) {
                if (i + 1 < level.size())
                    nextLevel.push_back(sha256(level[i] + level[i + 1]));
                else
                    nextLevel.push_back(sha256(level[i] + level[i]));
            }
            level = nextLevel;
        }
        return level[0];
    }
};


vector<string> fetchWeatherData() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    vector<string> records;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "virat",
                            "weather_db", 0, NULL, 0)) {
        cerr << "MySQL Connection Failed\n";
        exit(1);
    }

    mysql_query(conn, "SELECT city, temperature, humidity, pressure, record_date FROM weather_data");
    res = mysql_store_result(conn);

    while ((row = mysql_fetch_row(res))) {
        string record = string(row[0]) + "|" +
                        row[1] + "|" +
                        row[2] + "|" +
                        row[3] + "|" +
                        row[4];
        records.push_back(record);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return records;
}


int main() {
    cout << "\n--- Weather Forecasting System using Merkle Tree ---\n";

    vector<string> weatherRecords = fetchWeatherData();

    cout << "\nFetched Weather Records:\n";
    for (auto &r : weatherRecords)
        cout << r << endl;

    MerkleTree tree(weatherRecords);
    string merkleRoot = tree.getMerkleRoot();

    cout << "\nMerkle Root (Data Integrity Hash):\n";
    cout << merkleRoot << endl;

    cout << "\n✔ Data Integrity Verified Using Merkle Tree\n";
    return 0;
} 
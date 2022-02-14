#include "../include/global.hpp"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/* mendapatkan data buku */
auto fetchData()
{
    string line, word;
    vector<vector<string>> data;
    ifstream db;
    db.open(".database/DataBuku.csv");
    while (getline(db, line))
    {
        vector<string> row;
        stringstream stream(line);
        while (getline(stream, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }
    db.close();
    return data;
}
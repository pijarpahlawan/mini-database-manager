#include "../include/Global.h"
#include <fstream>
#include <sstream>

/* mendapatkan data buku */
std::vector<std::vector<std::string>> fetchData()
{
    std::string line, word;
    std::vector<std::vector<std::string>> data;
    std::ifstream db;
    db.open(".database/DataBuku.csv");
    while (getline(db, line))
    {
        std::vector<std::string> row;
        std::stringstream stream(line);
        while (getline(stream, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }
    db.close();
    return data;
}
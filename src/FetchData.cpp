#include "../include/Global.h"
#include <fstream>
#include <sstream>

/* mendapatkan data buku */
buffer fetchdata()
{
    std::string line, word;
    buffer data;
    std::ifstream db;
    db.open(DB_PATH);
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
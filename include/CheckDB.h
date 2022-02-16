#include "../include/Global.h"
#include <fstream>

bool dbexists()
{
    std::ifstream db(DB_PATH);
    if (db)
        return true;
    else
        return false;
}

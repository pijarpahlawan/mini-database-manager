#include "../include/Global.h"
#include <fstream>

bool dbexists()
{
    buffer data = fetchdata();
    if (data.size() != 0)
        return true;
    else
        return false;
}

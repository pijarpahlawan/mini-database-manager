#include "../include/Global.h"
#include <fstream>

/**
 * @brief fungsi untuk mengecek database ada atau tidak
 *
 * @return true jika terdapat database
 * @return false jika tidak terdapat database
 */
bool dbexists()
{
    buffer data = fetchdata();
    if (data.size() != 0)
        return true;
    else
        return false;
}

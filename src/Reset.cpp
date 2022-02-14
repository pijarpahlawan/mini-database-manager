#include "../include/Reset.h"
#include "../include/Global.h"
#include <iostream>
#include <fstream>

/**
 * @brief Construct a new Reset:: Reset object
 *
 */
Reset::Reset()
{
    std::ifstream db(DB_PATH);
    if (db)
    {
        db.close();
        conf();
    }
    else
    {
        notification("Tidak ada database saat ini");
        cont("kembali ke menu");
    }
}

/**
 * @brief confirm database deletion
 *
 */
void Reset::conf()
{
    while (true)
    {
        warning("Database akan terhapus");
        std::cout << "\n\nApakah anda yakin? (y/n): ";
        std::cin >> confirm;
        if (mklc(confirm) == 'y')
        {
            cmdcons("hapus database");
            break;
        }
        else if (mklc(confirm) == 'n')
        {
            break;
        }
        else
        {
            notification("Silahkan masukkan y/n");
            cont("kembali memilih y/n");
        }
    }
}
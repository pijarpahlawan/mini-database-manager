#include "../include/Global.h"
#include "../include/CheckDB.h"
#include "../include/Programs.h"
#include <iostream>

void Programs::resetdb()
{
    confirm = '\0';

    // jika terdapat database maka lanjutkan program
    if (dbexists())
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
    // jika tidak terdapat database maka kembali ke menu
    else
    {
        notification("Tidak ada database saat ini");
        cont("kembali ke menu");
    }
}

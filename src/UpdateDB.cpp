#include "../include/Global.h"
#include "../include/Programs.h"
#include <iostream>

void Programs::updatedb()
{
    confirm = '\0';
    if (!dbexists())
    {
        warning("Database kosong");
        while (true)
        {
            std::cout << "\n\nTambahkan data? (y/n): ";
            std::cin >> confirm;
            if (!(mklc(confirm) == 'y' || mklc(confirm) == 'n'))
            {
                notification("Silahkan masukkan y/n");
                cont("kembali memilih y/n");
            }
            else
                break;
        }
        if (mklc(confirm) == 'y')
        {
            create();
            update();
        }
    }
    else
        update();
}

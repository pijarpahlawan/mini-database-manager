#include "../include/Global.h"
#include "../include/CRUD.h"
#include <iostream>
#include <limits>

void CRUD::update()
{
    choice = 0;
    while (true)
    {
        while (true)
        {
            readData();
            std::cout << "Pilihan:\n[1] Menambah buku\n[2] Menghapus buku\n[3] Kembali\n\nSilahkan pilih: ";
            std::cin >> choice;
            if (!(std::cin.fail() || (choice < 1 || choice > 3)))
                break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            cont("memasukkan pilihan kembali");
        }
        if (choice == 1)
            create();
        else if (choice == 2)
            deleteData();
        else
            break;
    }
}

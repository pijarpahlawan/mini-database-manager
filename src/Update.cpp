#include "../include/Global.h"
#include "../include/CRUD.h"
#include <iostream>
#include <limits>

void CRUD::update()
{
    std::vector<std::vector<std::string>> data_buku = fetchData();
    choice = 0;

    while (true)
    {
        while (true)
        {
            read(data_buku);
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
        {
            create();
            data_buku = fetchData();
        }
        else if (choice == 2)
        {
            deleteData();
            data_buku = fetchData();
            if (data_buku.size() == 0)
            {
                notification("Tidak ada buku saat ini");
                cont("kembali ke menu");
                break;
            }
        }
        else
        {
            break;
        }
    }
}
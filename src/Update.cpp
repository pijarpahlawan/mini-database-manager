#include "../include/Global.h"
#include "../include/CRUD.h"
#include <iostream>

/**
 * @brief fungsi untuk memberi pilihan update (insert atau delete)
 *
 */
void CRUD::update()
{
    buffer data = fetchdata();
    choice = 0;

    while (true)
    {
        // selama input bukan merupakan integer dan tidak dalam interval
        // 1 <= choice <= 3, maka input akan diulang
        while (true)
        {
            read(data);
            std::cout << "Pilihan:\n[1] Menambah buku\n[2] Menghapus buku\
            \n[3] Kembali\n\nSilahkan pilih: ";
            std::cin >> choice;
            if (!std::cin.fail() && (choice >= 1 && choice <= 3))
                break;
            std::cin.clear();
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            cont("memasukkan pilihan kembali");
        }
        if (choice == 1)
        {
            create();
            data = fetchdata();
        }
        else if (choice == 2)
        {
            del();
            data = fetchdata();
            if (!dbexists())
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
#include "../include/Global.h"
#include "../include/Programs.h"
#include <iostream>

/**
 * @brief program untuk membeli buku
 *
 */
void Programs::buy()
{
    buffer data = fetchdata();
    choice = 0;

    if (dbexists())
    {
        // selama input bukan merupakan integer dan tidak ada dalam pilihan
        // maka input akan diulang
        while (true)
        {
            read(data);
            std::cout << "\nPilih buku nomor berapa: ";
            std::cin >> choice;
            // buku yang dipilih harus ada dalam pilihan
            if (!std::cin.fail() && (choice > 0 && choice <= data.size()))
            {
                choice = choice - 1;
                showdetails(data);
                break;
            }
            std::cin.clear();
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            cont("memasukkan pilihan kembali");
        }
    }
    else
    {
        notification("Tidak ada buku saat ini");
        cont("kembali ke menu");
    }
}
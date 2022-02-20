#include "../include/Global.h"
#include "../include/Programs.h"
#include <iostream>
#include <string>

/**
 * @brief fungsi untuk meminta tagihan
 *
 * @param price harga buku
 * @param pay pembayaran yang diinputkan
 * @param change kembalian pembayaran
 */
void Programs::getpaid(std::string price, int &pay, int &change)
{
    int bill = 0;
    while (true)
    {
        cmdcons("bersihkan layar");
        std::cout << "Pembayaran\n\n";
        std::cout << "Total harga\t\t: " << fprice(price) << std::endl;
        std::cout << "Masukkan uang anda\t: ";
        std::cin >> pay;
        bill = std::stoi(price);

        // input harus bilangan positif
        if (!std::cin.fail() && pay > 0)
        {
            change = abs(pay - bill);
            // bila uang lebih maka tampilkan kembalian
            if (pay > bill)
            {
                std::cout << "Uang anda kembali\t: " << fprice(std::to_string(change)) << std::endl;
                break;
            }
            // bila uang kurang maka tampilkan kekurangan
            else if (pay < bill)
            {
                std::cout << "Uang anda kurang\t: " << fprice(std::to_string(change)) << std::endl;
                cont("mengulangi");
            }
            else
                break;
        }
        else
        {
            std::cin.clear();
            notification("Masukkan bilangan positif");
            cont("mengulangi");
        }
    }
}

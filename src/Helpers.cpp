#include "../include/Global.h"
#include <iostream>
#include <limits>

/**
 * @brief fungsi tempat command console berada
 *
 * @param command perintah
 */
void cmdcons(const std::string &command)
{
    if (OS_WINDOWS)
    {
        if (command == "bersihkan layar")
            system("cls");
        else if (command == "hapus database")
            system("rmdir /Q /S .database");
    }
    else
    {
        if (command == "bersihkan layar")
            system("clear");
        else if (command == "hapus database")
            system("rm -rf .database");
    }
}

/**
 * @brief fungsi untuk menampilkan peringatan
 *
 * @param format peringatan yang akan ditampilkan
 */
void warning(const std::string &format)
{
    int mid = 55 - format.size();
    cmdcons("bersihkan layar");
    for (int i = 0; i < 110; i++)
    {
        std::cout << '!';
        if (i == 54)
        {
            std::cout << std::endl;
            for (int j = 0; j < (mid - 6) / 2; j++)
            {
                std::cout << '>';
            }
            for (int j = 0; j < 6; j++)
            {
                std::cout << ' ';
                if (j == 2)
                {
                    std::cout << format;
                }
            }
            for (int j = 0; j < (mid - 6) / 2; j++)
            {
                std::cout << '<';
            }
            std::cout << std::endl;
        }
    }
}

/**
 * @brief fungsi untuk menampilkan notifikasi
 *
 * @param format notifikasi yang akan ditampilkan
 */
void notification(const std::string &format)
{
    int mid = 75 - format.size();

    cmdcons("bersihkan layar");
    for (int i = 0; i < 150; i++)
    {
        std::cout << '-';
        if (i == 74)
        {
            std::cout << "\n!";
            for (int j = 0; j < (mid - 2); j++)
            {
                std::cout << " ";
                if (j == mid / 2 - 1)
                {
                    std::cout << format;
                }
            }
            std::cout << "!\n";
        }
    }
    std::cout << std::endl;
}

/**
 * @brief fungsi untuk memberi keterangan tekan enter
 *
 * @param str tujuan selanjutnya
 */
void cont(const std::string &str)
{
    std::cout << "\nTekan ENTER untuk " + str + "...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

/**
 * @brief fungsi untuk memeriksa apakah dalam angka terdapat huruf
 *
 * @param str kalimat yang akan diperiksa
 * @return true jika inputan tidak ada string (all int)
 * @return false jika inputan terdapat string (sekali dapat)
 */
bool stringalldgt(const std::string &str)
{
    // inisialisasi awal dari iterator
    std::string::const_iterator it = str.begin();
    // jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it))
        ++it;
    // mengembalikan kondisi apakah iterator sudah mencapai akhir
    return !str.empty() && it == str.end();
}

/**
 * @brief fungsi untuk memeriksa apakah dalam string hanya terdapat unsur whitespace
 *
 * @param str kalimat yang akan diperiksa
 * @return true jika dalam string hanya terdapat unsur whitespace
 * @return false jika dalam string tidak hanya terdapat unsur whitespace
 */
bool stringonlyws(const std::string &str)
{
    auto it = str.begin();
    while (it != str.end() && !(*it > 32 && *it < 127))
        ++it;
    return str.empty() || it == str.end();
}

/**
 * @brief fungsi untuk mengubah karaktee ke lowercase
 *
 * @param ch karakter yang akan diubah
 * @return char karakter lowercase
 */
char mklc(char ch)
{
    if (ch > 64 && ch < 91)
        ch = ch + 32;
    return ch;
}

/**
 * @brief fungsi untuk me-format harga supaya mudah dibaca
 *
 * @param price harga yang akan diformat
 * @return std::string harga terformat
 */
std::string fprice(std::string price)
{
    int count = 0;
    for (int i = price.size(); i > 0; i -= 3)
    {
        // tiap 3 karakter dari belakang maka string akan di tambahkan titik
        if (count > 0)
            price.insert(i, ".");
        count++;
    }
    // mengembalikan harga yang sudah diformat dengan currency IDR
    return "Rp" + price;
}

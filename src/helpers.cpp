#include "../include/global.hpp"
#include <iostream>

using namespace std;

/*  fungsi tempat command console berada */
void cmdcons(const string &command)
{
    if (OS_WINDOWS)
    {
        if (command == "bersihkan layar")
            system("cls");
        else if (command == "hapus database")
            system("del .database\\DataBuku.csv");
    }
    else
    {
        if (command == "bersihkan layar")
            system("clear");
        else if (command == "hapus database")
            system("rm .database/DataBuku.csv");
    }
}

/* fungsi untuk menampilkan peringatan */
void warning(const string &format)
{
    int mid = 55 - format.size();
    cmdcons("bersihkan layar");
    for (int i = 0; i < 110; i++)
    {
        cout << '!';
        if (i == 54)
        {
            cout << endl;
            for (int j = 0; j < (mid - 6) / 2; j++)
            {
                cout << '>';
            }
            for (int j = 0; j < 6; j++)
            {
                cout << ' ';
                if (j == 2)
                {
                    cout << format;
                }
            }
            for (int j = 0; j < (mid - 6) / 2; j++)
            {
                cout << '<';
            }
            cout << endl;
        }
    }
}

/* fungsi untuk menampilkan notifikasi */
void notification(const string &format)
{
    int mid = 75 - format.size();

    cmdcons("bersihkan layar");
    for (int i = 0; i < 150; i++)
    {
        cout << '-';
        if (i == 74)
        {
            cout << "\n!";
            for (int j = 0; j < (mid - 2); j++)
            {
                cout << " ";
                if (j == mid / 2 - 1)
                {
                    cout << format;
                }
            }
            cout << "!\n";
        }
    }
    cout << endl;
}

/* fungsi untuk memberi keterangan tekan enter */
void cont(const string &str)
{
    cout << "\nTekan ENTER untuk " + str + "...";
    cin.ignore();
    cin.get();
}

/* fungsi untuk memeriksa apakah dalam angka terdapat huruf
    - akan true jika inputan tidak ada string (all int)
    - akan false jika inputan terdapat string (sekali dapat) */
bool stringalldgt(const string &str)
{
    // inisialisasi awal dari iterator
    string::const_iterator it = str.begin();
    // jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it))
        ++it;
    // mengembalikan kondisi apakah iterator sudah mencapai akhir
    return !str.empty() && it == str.end();
}

/* fungsi untuk memeriksa apakah dalam string hanya terdapat unsur whitespace
    - akan true jika dalam string hanya terdapat unsur whitespace
    - akan false jika dalam string tidak hanya terdapat unsur whitespace */
bool stringonlyws(const string &str)
{
    auto it = str.begin();
    while (it != str.end() && !(*it > 32 && *it < 127))
        ++it;
    return str.empty() || it == str.end();
}

/* fungsi untuk mengubah string ke lowercase */
string mklc(const string &str)
{
    string result = str;
    for (int i = 0; i < str.size(); i++)
    {
        if (result[i] > 64 && result[i] < 91)
            result[i] = result[i] + 32;
    }
    return result;
}

/* fungsi untuk me-format harga supaya mudah dibaca */
string fprice(const string &price)
{
    string format = price;
    string result = "\0";
    int count = 0;

    for (int i = price.size(); i > 0; i -= 3)
    {
        // tiap 3 karakter dari belakang maka string akan di tambahkan titik
        if (count > 0)
            format.insert(i, ".");
        count++;
    }

    result = "Rp" + format;
    // mengembalikan harga yang sudah diformat dengan currency IDR
    return result;
}

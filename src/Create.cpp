#include "../include/Global.h"
#include "../include/CRUD.h"
#include "sys/stat.h"
#include <iostream>
#include <fstream>
#include <sstream>

void CRUD::create()
{
    confirm = '\0';

    std::string penampung[11];
    bool dont_use_goto = true;

insert:
    cmdcons("bersihkan layar");

    // memasukkan detail buku ke dalam vector sebagai penyimpanan sementara
    std::cout << "\t\t\tMASUKKAN DETAIL BUKU\n";
    std::cout << "\t\t    ----------------------------\n\n";
    for (int i = 0; i < 11; i++)
    {
        std::cout << detail_buku[i];
        if (i == 0 && dont_use_goto)
            std::cin.ignore();
        getline(std::cin, penampung[i]);
    }

    // memverifikasi apakah user menginputkan integer di detail harga
    if (!stringalldgt(penampung[10]) || stringonlyws(penampung[0]))
    {
        dont_use_goto = false;
        notification("Judul buku harus ada dan harga harus diisi berupa angka");
        std::cout << "\nTekan ENTER untuk kembali menginputkan data buku...";
        getchar();
        goto insert;
    }

    // membuat direktori database
    struct stat info;
    if (stat(".database", &info) != 0)
    {
        if (OS_WINDOWS)
            system("mkdir .database && attrib +h .database");
        else
            system("mkdir .database");
    }

    // menulis data yang sudah terverifikasi ke dalam database
    std::ofstream db(".database/DataBuku.csv", std::ios::app);
    for (int i = 0; i < 11; i++)
    {
        db << penampung[i];
        if (i != 10)
            db << ',';
        else
            db << '\n';
    }
    db.close();

again:
    // konfirmasi menambahkan data
    std::cout << "\n\nTambahkan data? (y/n): ";
    std::cin >> confirm;
    if (mklc(confirm) == 'y')
    {
        dont_use_goto = true;
        goto insert;
    }
    else if (!(mklc(confirm) == 'n'))
    {
        notification("Silahkan masukkan y/n");
        cont("kembali memilih y/n");
        goto again;
    }
}

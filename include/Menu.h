#include "../include/VariadicTable.h"
#include "../include/Global.h"
#include <iostream>

/* menu aksi */
int menu()
{
    std::string tindakan[] = {"Mengupdate data buku", "Membeli buku", "Menghapus data buku", "Keluar aplikasi"};
    std::string pilihan = "\0";
    int choice = 0;

    cmdcons("bersihkan layar");
    std::cout << "\t     Menu\n\t   ********\n\n";
    VariadicTable<int, std::string> vt({"No.", "Tindakan"});
    for (int i = 0; i < 4; i++)
    {
        vt.addRow(i + 1, tindakan[i]);
    }
    vt.print(std::cout);

    std::cout << "Masukkan pilihan: ";
    std::cin >> pilihan;
    choice = stoi(pilihan);
    return choice;
}
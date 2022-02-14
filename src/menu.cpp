#include "../include/variadic-table.h"
#include "../include/global.hpp"
#include <iostream>
using namespace std;

/* menu aksi */
int menu()
{
    string tindakan[] = {"Mengupdate data buku", "Membeli buku", "Menghapus data buku", "Keluar aplikasi"};
    string pilihan = "\0";
    int choice = 0;

    cmdcons("bersihkan layar");
    cout << "\t     Menu\n\t   ********\n\n";
    VariadicTable<int, string> vt({"No.", "Tindakan"});
    for (int i = 0; i < 4; i++)
    {
        vt.addRow(i + 1, tindakan[i]);
    }
    vt.print(cout);

    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    choice = stoi(pilihan);
    return choice;
}
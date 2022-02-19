#include "../include/Global.h"
#include "../include/CRUD.h"
#include <iostream>
#include <fstream>
#include <limits>

/* menghapus data indeks buku dalam database */
void CRUD::del()
{
    buffer data = fetchdata();
    std::ofstream db;

    choice = 0;
    confirm = '\0';

    std::cout << "\nMasukkan nomor indeks buku yang mau dihapus: ";
    std::cin >> choice;
    // buku yang dipilih harus ada dalam daftar yang ditampilkan
    if (!std::cin.fail() && (choice > 0 && choice <= data.size()))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (true)
        {
            // konfirmasi penghapusan data
            warning("Buku yang anda pilih akan terhapus");
            std::cout << "\n\nApakah anda yakin? (y/n): ";
            std::cin >> confirm;
            if (mklc(confirm) == 'y')
            {
                choice = choice - 1;

                // perintah untuk menghapus data buku yang dipilih
                data[choice].erase(data[choice].begin(), data[choice].end());

                // memasukkan data baru ke dalam database
                db.open(DB_PATH);
                for (int i = 0; i < data.size(); i++)
                {
                    for (int j = 0; j < data[i].size(); j++)
                    {
                        db << data[i][j];
                        if (j != 10)
                            db << ',';
                        else
                            db << '\n';
                    }
                }
                db.close();

                // jika database kosong maka hapus file database
                if (!dbexists())
                    cmdcons("hapus database");
                break;
            }
            else if (mklc(confirm) == 'n')
            {
                update();
                break;
            }
            else
            {
                notification("Silahkan masukkan y/n");
                cont("kembali memilih y/n");
            }
        }
    }
    else
    {
        notification("Masukkan angka sesuai dengan pilihan yang tersedia");
        cont("memasukkan pilihan kembali");
        update();
    }
}
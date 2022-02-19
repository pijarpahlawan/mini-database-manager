#include "../include/Global.h"
#include "../include/CRUD.h"
#include <iostream>
#include <fstream>
#include <limits>

/* menghapus data indeks buku dalam database */
void CRUD::del()
{
    std::vector<std::vector<std::string>> data_buku = fetchData();
    std::string check = "";
    std::ofstream db_out;
    std::ifstream db_in;

    std::cout << "\nMasukkan nomor indeks buku yang mau dihapus: ";
    std::cin >> choice;
    // buku yang dipilih harus ada dalam daftar yang ditampilkan
    if (std::cin.fail() && (choice > 0 && choice <= data_buku.size()))
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
                data_buku[choice].erase(data_buku[choice].begin(), data_buku[choice].end());

                // memasukkan data baru ke dalam database
                db_out.open(".database/DataBuku.csv");
                for (int i = 0; i < data_buku.size(); i++)
                {
                    for (int j = 0; j < data_buku[i].size(); j++)
                    {
                        db_out << data_buku[i][j];
                        if (j != 10)
                            db_out << ',';
                        else
                            db_out << '\n';
                    }
                }
                db_out.close();

                // jika database kosong maka hapus file database
                db_in.open(".database/DataBuku.csv");
                db_in >> check;
                db_in.close();
                if (db_in.eof())
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
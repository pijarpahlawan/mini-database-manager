#include "../include/VariadicTable.h"
#include "../include/Global.h"
#include "../include/Programs.h"
#include <limits>

int menu();
int main()
{
    Programs program;
    int choice;

    while (true)
    {
        choice = menu();
        if (choice == 1)
        {
            program.updatedb();
        }
        else if (choice == 2)
        {
            buybook();
        }
        else if (choice == 3)
        {
            program.resetdb();
        }
        else
        {
            cmdcons("bersihkan layar");
            break;
        }
    }

    return 0;
}

/* menu aksi */
int menu()
{
    std::string action[] = {"Mengupdate data buku", "Membeli buku",
                            "Menghapus data buku", "Keluar aplikasi"};
    int choice = 0;

    while (true)
    {
        cmdcons("bersihkan layar");
        std::cout << "\t     Menu\n\t   ********\n\n";
        VariadicTable<int, std::string> vt({"No.", "Tindakan"});
        for (int i = 0; i < 4; i++)
        {
            vt.addRow(i + 1, action[i]);
        }
        vt.print(std::cout);

        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;
        if (!std::cin.fail() && (choice >= 1 && choice <= 4))
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        notification("Masukkan angka sesuai dengan pilihan yang tersedia");
        cont("kembali memilih");
    }
    return choice;
}
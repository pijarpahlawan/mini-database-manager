#include "../include/Menu.h"
#include "../include/Programs.h"

int main()
{
    Programs program;
    bool repeat = true;

    while (repeat)
    {
        switch (menu())
        {
        case 1:
            program.updatedb();
            break;
        case 2:
            buyBook();
            repeat = false;
            break;
        case 3:
            program.resetdb();
            break;
        case 4:
            cmdcons("bersihkan layar");
            repeat = false;
            break;
        default:
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            cont("kembali memilih");
            break;
        }
    }

    return 0;
}
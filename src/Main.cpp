#include "../include/Global.h"
#include "../include/Reset.h"

int main()
{
    bool repeat = true;

    while (repeat)
    {
        switch (menu())
        {
        case 1:
            update();
            repeat = false;
            break;
        case 2:
            buyBook();
            repeat = false;
            break;
        case 3:
            Reset *database = new Reset;
            delete database;
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
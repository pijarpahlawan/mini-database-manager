#include "../include/Global.h"
#include "../include/Programs.h"
#include "../include/VariadicTable.h"

void Programs::showdetails(buffer data)
{
    int pay = 0;
    int change = 0;
    std::string taken = "\0";

    confirm = '\0';

    while (true)
    {
        cmdcons("bersihkan layar");
        VariadicTable<std::string> detail({"DETAIL BUKU"});
        for (int i = 0; i < 11; i++)
        {
            taken = data[choice][i];
            stringonlyws(taken) == true ? taken = "N/A" : taken;
            if (i != 10)
                detail.addRow(details[i] + taken);
            else
                detail.addRow(details[i] + fprice(taken));
        }
        detail.print(std::cout);

        std::cout << "\nPilihan:\n[y] Bila yakin\n[n] Bila ingin memilih kembali\
        \n[b] Kembali ke menu\nMasukkan pilihan: ";
        std::cin >> confirm;
        if (mklc(confirm) == 'y')
        {
            getpaid(data[choice][10], change, pay);
            getreceipt(data, pay, change);
            break;
        }
        else if (mklc(confirm) == 'n')
        {
            buy();
            break;
        }
        else if (mklc(confirm) == 'b')
        {
            break;
        }
        else
        {
            notification("Silahkan masukkan y/n/b");
            cont("kembali memilih");
        }
    }
}
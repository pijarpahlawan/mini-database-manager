#include "../include/Global.h"
#include "../include/Programs.h"
#include "../include/VariadicTable.h"
#include <fstream>
#include <sys/stat.h>

void Programs::getreceipt(buffer data, int money_in, int money_out)
{
    std::ofstream write;
    std::ifstream read;
    std::string line = "\0";
    int receipt_number = 1;

    // membuat folder export apabila direktori tidak ada
    struct stat info;
    if (stat("export", &info) != 0)
        system("mkdir export");

    // mengecek apakah sudah ada bukti pembayaran dengan nama yang sama
    while (true)
    {
        read.open("export/receipt" + std::to_string(receipt_number) + ".txt");
        if (read)
        {
            receipt_number++;
            read.close();
        }
        else
        {
            read.close();
            break;
        }
    }

    // mengeksport bukti pembayaran
    write.open("export/receipt" + std::to_string(receipt_number) + ".txt");
    VariadicTable<std::string> receipt({"*** Bukti Pembayaran ***"});
    receipt.addRow(details[0] + data[choice][0]);
    receipt.addRow(details[10] + fprice(data[choice][10]));
    receipt.addRow("Dibayarkan      : " + fprice(std::to_string(money_in)));
    receipt.addRow("Kembalian       : " + fprice(std::to_string(money_out)));
    receipt.print(write);
    write.close();
    cont("menampilkan bukti pembayaran");
    cmdcons("bersihkan layar");

    // menampilkan bukti pembayaran ke layar
    read.open("export/receipt" + std::to_string(receipt_number) + ".txt");
    cmdcons("bersihkan layar");
    while (getline(read, line))
    {
        std::cout << line << "\n";
    }
    read.close();
    std::cout << "\n\nNOTE: pembayaran telah tersimpan di folder export\n\n";
    std::cout << "\n\nTekan enter untuk kembali ke menu....";
    getchar();
}
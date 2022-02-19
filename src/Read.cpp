#include "../include/VariadicTable.h"
#include "../include/Global.h"
#include "../include/CRUD.h"

void CRUD::read(buffer data)
{

    cmdcons("bersihkan layar");
    VariadicTable<int, std::string, std::string> vt({"No.", "Judul buku", "Harga"});
    for (int i = 0; i < data.size(); i++)
    {
        vt.addRow(i + 1, data[i][0], fprice(data[i][10]));
    }
    vt.print(std::cout);
}
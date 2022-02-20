#include "../include/CRUD.h"

/**
 * @brief class berisi bagian program
 *
 */
class Programs : CRUD
{
private:
    int choice;
    char confirm;
    void showdetails(buffer);
    void getpaid(std::string, int &, int &);
    void getreceipt(buffer, const int &, const int &);

public:
    void updatedb();
    void buy();
    void resetdb();
};

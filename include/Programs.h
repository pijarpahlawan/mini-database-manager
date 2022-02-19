#include "../include/CRUD.h"

/**
 * @brief class berisi bagian program
 *
 */
class Programs : CRUD
{
private:
    char confirm;
    void showdetails(buffer);
    void getpaid(std::string, int &, int &);
    void getreceipt(buffer, int, int);

public:
    void updatedb();
    void buy();
    void resetdb();
};

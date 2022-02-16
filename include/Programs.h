#include "../include/CRUD.h"

class Programs : private CRUD
{
private:
    char confirm;

public:
    void updatedb();
    void buy();
    void resetdb();
};

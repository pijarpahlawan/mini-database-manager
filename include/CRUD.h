/**
 * @brief class untuk mengubah database secara parsial
 *
 */
class CRUD
{
private:
    int choice;
    char confirm;

protected:
    void create();
    void read(std::vector<std::vector<std::string>> data);
    void update();
    void del();
};
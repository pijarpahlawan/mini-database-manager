/* define database path, OS condition, and data type */
#define DB_PATH ".database/DataBuku.csv"

#ifdef WIN32
#define OS_WINDOWS 1
#else
#define OS_WINDOWS 0
#endif

#include <string>
#include <vector>

typedef std::vector<std::vector<std::string>> buffer;

extern void cmdcons(const std::string &);
extern void warning(const std::string &);
extern void notification(const std::string &);
extern void cont(const std::string &);
extern bool stringalldgt(const std::string &);
extern bool stringonlyws(const std::string &);
extern bool dbexists();
extern char mklc(char);
extern std::string fprice(std::string);
extern buffer fetchdata();
extern std::string details[] = {"Judul buku      : ", "Penulis         : ",
                                "Jumlah halaman  : ", "Bahasa          : ",
                                "Penerbit        : ", "Tanggal terbit  : ",
                                "ISBN            : ", "Panjang         : ",
                                "Lebar           : ", "Berat           : ",
                                "Harga           : "};
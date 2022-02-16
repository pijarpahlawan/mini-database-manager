/* define database path */
#define DB_PATH ".database/DataBuku.csv"

/* define OS condition */
#ifdef WIN32
#define OS_WINDOWS 1
#else
#define OS_WINDOWS 0
#endif

#include <string>
#include <vector>

extern void cmdcons(const std::string &);
extern void warning(const std::string &);
extern void notification(const std::string &);
extern void cont(const std::string &);
extern bool stringalldgt(const std::string &);
extern bool stringonlyws(const std::string &);
extern char mklc(char);
extern std::string fprice(std::string);
extern std::vector<std::vector<std::string>> fetchData();
extern std::string detail_buku[] = {"Judul buku      : ", "Penulis         : ",
                                    "Jumlah halaman  : ", "Bahasa          : ",
                                    "Penerbit        : ", "Tanggal terbit  : ",
                                    "ISBN            : ", "Panjang         : ",
                                    "Lebar           : ", "Berat           : ",
                                    "Harga           : "};
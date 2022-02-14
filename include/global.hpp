/* define database path */
#define DB_PATH ".database/DataBuku.csv"

/* define OS condition */
#ifdef WIN32
#define OS_WINDOWS 1
#else
#define OS_WINDOWS 0
#endif

extern int menu();
extern auto fetchData();
extern void cmdcons(const string &);
extern void warning(const string &);
extern void notification(const string &);
extern void cont(const string &);
extern bool stringalldgt(const string &);
extern bool stringonlyws(const string &);
extern string mklc(const string &);
extern string fprice(const string &);
extern string detail_buku[] = {"Judul buku      : ", "Penulis         : ",
                               "Jumlah halaman  : ", "Bahasa          : ",
                               "Penerbit        : ", "Tanggal terbit  : ",
                               "ISBN            : ", "Panjang         : ",
                               "Lebar           : ", "Berat           : ",
                               "Harga           : "};
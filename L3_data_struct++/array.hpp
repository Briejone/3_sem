#ifndef ARRAY_H
#define ARRAY_H

#define CHAR_SIZE 256

class Array {
public:
    Array(int size = CHAR_SIZE); // Обновите конструктор
    ~Array();
    char* ArrAdd(const char* newData);
    char* ArrDel();
    int ArrIns(const char* newData, int pos);
    char* ArrRem(int pos);
    int ArrChg(const char* newData, int pos);
    char* ArrGet(int pos);
    void print_array() const;
    int ArrSrch(const char* searchData) const;
private:
    char* data[CHAR_SIZE];
    int size;
};


#endif // ARRAY_H

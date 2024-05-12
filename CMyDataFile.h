#ifndef CMYDATAFILE_H
#define CMYDATAFILE_H

#include "CFile.h"

struct MyData {
    int id;
    char name[50];

    MyData() : id(0) { name[0] = '\0'; }
};

class CMyDataFile : public CFile {
public:
    bool WriteData(const MyData& data);
    bool ReadData(MyData& data);
};
#endif

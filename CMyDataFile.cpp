#include <iostream>
#include "CMyDataFile.h"

bool CMyDataFile::WriteData(const MyData& data) {
    if (!file.write(reinterpret_cast<const char*>(&data), sizeof(data))) {
        std::cerr << "������ ������ � ����." << std::endl;
        return false;
    }
    return true;
}

bool CMyDataFile::ReadData(MyData& data) {
    if (!file.read(reinterpret_cast<char*>(&data), sizeof(data))) {
        std::cerr << "������ ������ �� �����." << std::endl;
        return false;
    }
    return true;
}
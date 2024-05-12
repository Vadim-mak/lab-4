#include "CFile.h"
#include <iostream>

CFile::CFile() : filename("") {}

CFile::~CFile() {
    if (file.is_open()) {
        file.close();
    }
}

bool CFile::Open(const std::string& name, std::ios::openmode mode) {
    filename = name;
    file.open(name, mode);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << name << std::endl;
        return false;
    }
    return true;
}

void CFile::Close() {
    if (file.is_open()) {
        file.close();
    }
}

void CFile::Seek(std::streampos position) {
    file.seekg(position);
}

std::streampos CFile::GetPosition() {
    return file.tellg();
}

std::streamsize CFile::GetLength() {
    if (!file.is_open()) return 0;
    std::streampos current_pos = file.tellg();
    file.seekg(0, std::ios::end);
    std::streamsize length = file.tellg();
    file.seekg(current_pos);
    return length;
}

bool CFile::Read(char* buffer, std::streamsize size) {
    if (!file.read(buffer, size)) {
        std::cerr << "Ошибка чтения из файла." << std::endl;
        return false;
    }
    return true;
}

bool CFile::Write(const char* data, std::streamsize size) {
    if (!file.write(data, size)) {
        std::cerr << "Ошибка записи в файл." << std::endl;
        return false;
    }
    return true;
}
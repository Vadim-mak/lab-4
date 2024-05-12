#ifndef CFILE_H
#define CFILE_H

#include <fstream>
#include <string>

class CFile {
protected:
    std::fstream file;
    std::string filename;

public:
    CFile();
    ~CFile();
    bool Open(const std::string& name, std::ios::openmode mode = std::ios::in | std::ios::out);
    void Close();
    void Seek(std::streampos position);
    std::streampos GetPosition();
    std::streamsize GetLength();
    bool Read(char* buffer, std::streamsize size);
    bool Write(const char* data, std::streamsize size);
};
#endif
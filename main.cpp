#include "CMyDataFile.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    CMyDataFile file;
    MyData data;

    // Заполнение данных
    data.id = 1;
    strcpy_s(data.name, sizeof(data.name), "Пример");

    // Открытие файла для записи
    if (file.Open("example.dat", std::ios::binary | std::ios::out)) {
        file.WriteData(data);
        file.Close();
    }

    // Открытие файла для чтения
    if (file.Open("example.dat", std::ios::binary | std::ios::in)) {
        file.ReadData(data);
        std::cout << "ID: " << data.id << ", Имя: " << data.name << std::endl;
        file.Close();
    }

    return 0;
}

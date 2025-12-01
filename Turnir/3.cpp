#include <iostream>
#include <string>
#include <iomanip>
#include <zip.h>
#include <cstring>

bool try_password(const std::string& zip_path, const std::string& password) {
    int err = 0;
    zip_t* archive = zip_open(zip_path.c_str(), ZIP_RDONLY, &err);
    
    if (!archive) {
        std::cerr << "Не удалось открыть архив" << std::endl;
        return false;
    }

    // Устанавливаем пароль
    zip_set_default_password(archive, password.c_str());

    // Пытаемся извлечь первый файл (как тест)
    bool success = true;
    for (int i = 0; i < zip_get_num_entries(archive, 0); i++) {
        zip_file_t* file = zip_fopen_index(archive, i, 0);
        if (!file) {
            success = false;
            break;
        }
        zip_fclose(file);
    }

    zip_close(archive);
    return success;
}

void find_password(const std::string& zip_path) {
    for (int i = 0; i < 1000000000; ++i) {
        std::string password = std::to_string(i);
        password = std::string(9 - password.length(), '0') + password; // Дополняем нулями
        
        std::cout << "Пробую пароль: " << password << std::endl;
        
        if (try_password(zip_path, password)) {
            std::cout << "Пароль найден: " << password << std::endl;
            return;
        }
    }
    
    std::cout << "Пароль не найден" << std::endl;
}

int main() {
    std::string zip_file_path = "D:\\super-secret-files.zip";
    find_password(zip_file_path);
    return 0;
}
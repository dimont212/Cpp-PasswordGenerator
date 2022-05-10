#include <iostream>
#include <stdlib.h>
#include <string>
#include "rand.h"

int main() 
{
    std::cout << "Enter site name: ";
    // Создаём строку с названием сайта
    std::string siteName;
    // Вводим название сайта
    std::cin >> siteName;
    // Создаём (пока что пустую) строку для пароля
    std::string password;

    // Генерируем случайный пароль длиной в зависимости от количества символов в названии сайта
    for (char c : siteName) 
    {
        // В качестве сида указываем целочисленное значение текущего символа из строки
        srand((int)c);
        // Генерируем пароль
        passwordGenerator(password);
    }
    // Если символов в названии сайта меньше, чем 7
    if (siteName.length() < 7) 
    {
        for (char c : siteName) 
        {
            // В качестве сида указываем целочисленное значение текущего символа из строки + случайное число 
            // (чтобы не получился просто дубликат пароля который сгенерировался перед этим)
            srand((int)c + rand());
            // Генерируем вторую половину пароля
            passwordGenerator(password);
        }
    }

    // Выводим пароль
    std::cout << "Password: " << password << '\n';
    // Очищаем поток ввода
    std::cin.ignore();
    std::cin.clear();
    // Ввод любого символа (сделано, чтобы программа не закрывалась при запуске через exe-файл)
    std::cin.get();
}

// Функция для получения случайного числа
int getRandomNumber(int min, int max)
{
    // Генерация случайного числа (min + rand() % (max - min + 1) даёт случайное число в правильном диапазоне)
    int num = min + rand() % (max - min + 1);
    return num;
}

// Функция для генерации пароля
void passwordGenerator(std::string& password) 
{
    // Генерируем случайный символ в диапазоне от '0' до 'z'
    char randomChar = (char)getRandomNumber(48, 122);
    // Если случайный символ не является цифрой или буквой, заменяем его на 'f'
    if ((randomChar >= '[' && randomChar <= '`') || (randomChar >= ':' && randomChar <= '@')) randomChar = 'f';
    // Добавляем случайный символ в пароль
    password.push_back(randomChar);
}
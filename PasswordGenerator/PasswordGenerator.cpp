#include <iostream>
#include <stdlib.h>
#include <string>
#include "rand.h"

int main()
{
    std::cout << "Enter master key: ";
    // Создаём строку для мастер-пароля
    std::string masterKey;
    // Вводим мастер-пароль
    std::cin >> masterKey;

    std::cout << "Enter site name: ";
    // Создаём строку с названием сайта
    std::string siteName;
    // Вводим название сайта
    std::cin >> siteName;

    // Создаём переменную для хранения целочисленного значения мастер-пароля
    ull keyTemp = stringToInteger(masterKey);

    // Создаём (пока что пустую) строку для пароля
    std::string password;
    // Создаём массив с символами для пароля
    char symbols[] = { "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%&*_" };

    // Генерируем случайный пароль длиной в зависимости от количества символов в названии сайта
    for (char c : siteName)
    {
    /* 
        В качестве сида указываем целочисленное значение мастер-пароля, 
        умноженное на текущий символ из строки с названием сайта
    */
        srand(keyTemp * (ull)c);
        // Генерируем пароль
        passwordGenerator(password, symbols);
    }
    // Если символов в названии сайта меньше, чем 7
    if (siteName.length() < 7)
    {
        // Выбираем случайную длину второй части пароля
        for (int i = 0; i <= getRandomNumber(6, 15); i++)
        {
        /* 
            В качестве сида указываем целочисленное значение мастер-пароля, 
            умноженное на случайное число
        */                               
            srand(keyTemp * rand());
            // Генерируем вторую половину пароля
            passwordGenerator(password, symbols);
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
    // Генерация min + rand() % (max - min + 1) даёт случайное число в правильном диапазоне
    int num = min + rand() % (max - min + 1);
    return num;
}

// Функция для генерации пароля
void passwordGenerator(std::string& password, char symbols[70])
{
    // Генерируем случайный символ из массива
    char randomChar = symbols[getRandomNumber(0, 69)];
    // Добавляем случайный символ в пароль
    password.push_back(randomChar);
}

// Функция для преобразования строки в число
ull stringToInteger(std::string str)
{
    // Создаём переменную для результата
    ull result = 0;

    for (ull i = 0; i < (ull)str.length(); i++) 
    {
        // Прибавляем к результату символ из строки умноженный на его индекс + 1
        result += str[i] * (i + 1);
    }
    // Возвращаем результат
    return result;
}
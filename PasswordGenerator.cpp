#include <iostream>
#include <stdlib.h>
#include <string>
#include "randNumber.h"

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
    // если их >= 7, то символов в пароле будет столько же, сколько в строке названия сайта, иначе их будет в два раза больше
    for (int _ = 0; _ < (siteName.length() < 7 ? 2 : 1); _++) 
    {
        for (char c : siteName) 
        {
            // В качестве сида указываем целочисленное значение текущего символа из строки
            srand((int)c);
            // Генерируем случайный символ в диапазоне от '0' до 'z'
            char randomChar = (char)getRandomNumber(48, 122);
            // Если случайный символ не является цифрой или буквой, заменяем его на 'f'
            if ((randomChar >= '[' && randomChar <= '`') || (randomChar >= ':' && randomChar <= '@')) randomChar = 'f';
            // Добавляем случайный символ в пароль
            password.push_back(randomChar);
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
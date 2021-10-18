// Урок 11.10.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
bool is_palindrome(char str[]);
void remove_symbol(char str[], char symbol);
int StringLength(char str[]);
int is_int_number(char str[]);
int main()
{
	const int n = 256;
	char str[n] = "Аргентина манит негра";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите строку: ";
	
	std::cin.getline(str, n);
	//std::cout << is_palindrome(str) << std::endl;
	if (is_palindrome(str))
	{
		std::cout << "Введенная строка - палиндром" <<std::endl;
	}
	else
	{
		std::cout << "Введенная строка - НЕ палиндром" << std::endl;
	}

	if (is_int_number(str))
		std::cout << "Строка - число!" <<std:: endl;
	else
		std::cout << "Строка - Не число!" <<std:: endl;
	return 0;
}
int StringLength(char str[])
{

	int i = 0;
	for (; str[i] != 0; ++i);
	return i;
	std::cout << typeid(str).name() << std::endl;

}
void to_upper(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
			str[i] -= 32;
	}

}

bool is_palindrome(char str[])
{

    
    //int n = StringLength(str);
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; i < n; ++i)
		//buffer[i] = str[i];
		strcpy(buffer, str);
	//strcpy(dst, src);//dst(destri
	to_upper(buffer);
	remove_symbol(buffer, ' ');
	n= StringLength(buffer);
	for (int i = 0; i < n/2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; ++i)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; ++j)
				str[j] = str[j + 1];
		}
	}
}
int is_int_number(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return false;
	}
	return true;
}
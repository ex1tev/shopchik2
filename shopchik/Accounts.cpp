#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* statusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };

void ChangeAccounts()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"\n\n\t\t\tРедактор учётных записей\n\n";
		std::wcout << L"1 - Создать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить пароль\n";
		std::wcout << L"4 - Изменить уровни доступа\n";
		std::wcout << L"5 - Редактировать пермии и штрафы\n";
		std::wcout << L"6 - Удалить аккаунт\n";
		std::wcout << L"0 - Выход\n\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

	}
}
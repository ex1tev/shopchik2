#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

size_t maxStorageSize = 150;
size_t currentStorageSize = 0;

double maxPrice = 500000;

void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Мышка\t\t\t"			L"Порода: \"Петерболд\"\t",
			L"Клавиатура\t\t\t"			L"Порода: \"Ксолоитцкуинтли\"\t",
			L"Монитор fullhd\t\t\t"			L"Порода: \"Обычный\"\t",
			L"Систмный блок\t\t"			L"Порода: \"Свинорылая\"\t",
			L"Коврик маленький\t\t\t"			L"Порода: \"Рекс\"\t",
			L"Беспроводная мышь\t\t\t"			L"Порода: \"Фалабелла\"\t",
			L"Монитор 2К\t\t\t"			L"Порода: \"Гладыш\"",
			L"Коврик на весь стол\t\t"	L"Порода: \"Лунуария\"\t\t",
			L"Жираф ручной\t\t"		L"Порода: \"Сетчатый\"\t\t",
			L"Касатка ручная\t\t"	L"Порода: \"Домосед\"\t\t"
		};
		size_t countArrStatic[staticSize]{ 14, 30, 9, 18, 23, 7, 22, 40, 10, 3 };
		double priceArrStatic[staticSize]{ 143.3, 210.4, 452.1, 377.3, 116.8, 287.2, 140.4, 210.3, 899.9, 1900.0 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArrStatic, idArr, sizeSt);
		FillArray(nameArrStatic, nameArr, sizeSt);
		FillArray(countArrStatic, countArr, sizeSt);
		FillArray(priceArrStatic, priceArr, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}
		isStorageCreated = true;
	}
	
	else if (mode == 1)
	{
		// TO_DO
	}

	else
	{
		std::wcout << L"Склад уже создан\n\n";
		Sleep(500);
	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");

		std::wcout << L"Товары \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40)
				<< nameArr[i] << L"\t" << countArr[i] <<std::setprecision(2) << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");
	}

	else if (mode == 1)
	{
		system("cls");

		std::wcout << L"Пополнение товаров \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Заполненость склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
	else if (mode == 2)
	{
		system("cls");

		std::wcout << L"Пополнение товаров \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Свободного метса: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(1);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товаров\n\n";
			system("pause");
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;

			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некоректное кол-во! На складе осталось " << maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить? \n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно добавлен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена поплнения " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}

}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(2);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списания товаров\n\n";
			system("pause");
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;

			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > countArr[id])
					{
						std::wcout << L"Некоректное кол-во! На складе осталось " << countArr[id] << L" ед. товара\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить? \n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}

}

void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;

	while (true)
	{
		ShowStorage(3);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изменения цены\n\n";
			system("pause");
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;

			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите новую стоимость товара: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					double price = std::stod(choosePrice);
					if (price < 0 || price > maxPrice)
					{
						std::wcout << L"Некоректное цена! Максимально возможная цена " 
							<< maxPrice << L" рублей\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" -----> "
								<< price << L"\n\n";
							std::wcout << L"Подтвердить? \n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Успешное изменение цены\n\n";
								priceArr[id] = price;
								// :)
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}

}

void ChangeStorage()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"\t\tРедактирование склада\n\n";
		std::wcout << L"1 - Добавить новый товар\n";
		std::wcout << L"2 - Показать сИзменить название товара\n";
		std::wcout << L"3 - Удаление товара\n";
		std::wcout << L"4 - Изменить лимиты\n";
		std::wcout << L"0 - Выход\n";
		Getline(choose);

		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{
			
		}
		else if (choose == L"3")
		{
			
		}
		else if (choose == L"4")
		{
			
		}
		else if (choose == L"0")
		{
			std::wcout << L"\nВыход из редактора склада\n\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}
}
void AddNewProduct()
{
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;

	while (true)
	{
		while (true)
		{
			system("cls");

			std::wcout << L"Введите название нового товара или \"exit\" для выхода";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (chooseName.size() > 40 || chooseName.size() < 3)
			{
				std::wcout << L"Ошибка длины названия товара\n Допустимое значение от 3 до 40 символов\n\n";
				Sleep(1500);
			}
			if (IsNotSame(chooseName, nameArr, sizeSt))
			{
				break;
			}
			else
			{
				std::wcout << L"Данныый товар уже есть на складе\n\n";
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Введите кол-во нового товара или \"exit\" для выхода: ";
			Getline(chooseCount);
			if (chooseCount == L"exit" || chooseCount == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				system("pause");
			}

			if (IsNumber(chooseCount))
			{
				count = std::stoull(chooseCount);
				if (count < 0 || count > maxStorageSize - currentStorageSize)
				{
					std::wcout << L"Некоректное кол-во! На складе осталось " <<
						maxStorageSize - currentStorageSize << L" свободных мест\n\n";
				}
			}
			else
			{
				break;
			}
		}

		while (true)
		{
			system("cls");

			std::wcout << L"Введите цену нового товара или \"exit\" для выхода: ";
			Getline(choosePrice);
			if (choosePrice == L"exit" || choosePrice == L"Exit")
			{
				std::wcout << L"Отмена добавление новго товара\n\n";
				Sleep(1500);
				return;
			}
			
			if (IsNumber(choosePrice))
			{
				price = std::stod(choosePrice);
				
				if (price < 0 || price > maxPrice)
				{
					std::wcout << L"Неккоректная цена! Максимально возможная цена " 
						<< maxPrice << L" рублей\n\n";
					Sleep(2000);
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");

			std::wcout << L"Новый товар: " << chooseName << L"\n";
			std::wcout << L"Колличество: " << count << L"\n";
			std::wcout << L"Цена: " << price << L"\n";
			std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод : ";
			Getline(choose);

			if (choose == L"1")
			{
				std::wcout << L"Загрузка новых данных в базу данных..";
				Sleep(2000);
				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);
				sizeSt++;
				idArr[sizeSt - 1] = sizeSt;
				nameArr[sizeSt - 1] = chooseName;
				countArr[sizeSt - 1] = count;
				priceArr[sizeSt - 1] = price;
				currentStorageSize += count;
				// :)
				std::wcout << L"\n\nНовый товар успешно добавлен!\n\n";
			}

			else if (choose == L"2")
			{
				std::wcout << L"Отмена\n\n";
				system("pause");
				break;
			}
			else
			{
				Err();
			}

		}
	}
}
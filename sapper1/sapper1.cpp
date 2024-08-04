#include <time.h>
#include <string>
#include <iostream>

using namespace std;

void menu();

void error(int& lim, int& min);

void displayField(string pole2[][100], int lim)
{
	for (int i = 0; i < lim; i++) {
		for (int j = 0; j < lim; j++) {
			cout << pole2[i][j] << "\t";
		}
		cout << endl;
	}
}

void clearConsole()
{
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
}

int minn(int pole[][100], int lim, int row, int col)
{
	int mine = 0;
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j <= col + 1; j++) {
			if (i >= 0 && i < lim && j >= 0 && j < lim && !(i == row && j == col)) {
				if (pole[i][j] == 1) {
					mine++;
				}
			}
		}
	}
	return mine;
}

void back()
{
	string back = "";
	cin >> back;
	if (back != "1")
	{
		clearConsole();
		cout << "С возвращением!" << endl;
		menu();
	}
}

void start(int pole[][100], int lim, int min)
{
	clearConsole();

	bool game_end = 1;
	bool error = 1;
	bool error1 = 1;
	int col = 0;
	int rov = 0;
	int fl1 = 0;
	int fl2 = 0;
	int life = 2;
	int flag1 = 0;
	int const LIM = 100;
	string pole2[LIM][LIM];
	int abc = 0;
	int count = 0;
	int flag = 0;
	int choise = 0;

	cout << "|||||||||||||||||||||||||||||||||||Игра началась!|||||||||||||||||||||||||||||||||||" << endl;
	for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < lim; j++)
		{
			cout << pole[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < lim; j++)
		{
			pole2[i][j] = "[]";
		}
	}

	cout << "Если вы готовы начать, то можете выбирать клетку!" << "\n" << "!!!Напоминание!!!" << "\n" << "Введите 2 числа, первое число - это столец, второе число - строчка, удачи!" << endl;
	while (game_end)
	{
		if (abc > 0)
		{
			clearConsole();
		}
		abc++;

		displayField(pole2, lim);

		cout << "1 - открыть ячейку\n" << "2 - поставить флажок" << endl;
		cin >> choise;

		if (choise == 1)
		{
			clearConsole();
			displayField(pole2, lim);

			cout << "Введите номер столбца: " << endl;
			cin >> col;
			cout << "Введите номер строки: " << endl;
			cin >> rov;

			while (col > lim || col <= 0)
			{
				cout << "Ошибка! Вы ввели неправильный номер столбца и вышли за границы игрового поля, попробуйте снова" << endl;
				cin >> col;
			}
			while (rov > lim || rov <= 0)
			{
				cout << "Ошибка! Вы ввели неправильный номер строки и вышли за границы игрового поля, попробуйте снова" << endl;
				cin >> rov;
			}

			col = col - 1;
			rov = rov - 1;

			if (pole[rov][col] == 1)
			{
				pole2[rov][col] = "* ";
				//cout << "Вы попали на мину! Игра окончена :(" << endl;
				//game_end = false;
			}
			else
			{
				int mine = minn(pole, lim, rov, col);
				pole2[rov][col] = to_string(mine) + " ";
			}
			clearConsole();
			if (pole2[rov][col] == "* " && life == 1)
			{
				cout << "Вы попали на мину! Игра окончена :(" << endl;
				game_end = false;
			}

			if (pole2[rov][col] == "* " && life == 2)
			{
				cout << "Вы попали на мину, но ничего страшного, т.к. это первый ход, просто наступите на поле, которое отмечено цифрой :)" << endl;
				life = 1;
			}
			//clearConsole();
			displayField(pole2, lim);
		}
		else if(choise == 2)
		{
			clearConsole();
			displayField(pole2, lim);

			cout << "Выберите место, куда вы хотите поставить флаг." << endl;
			cout << "Введите номер столбца: " << endl;
			cin >> fl1;
			cout << "Введите номер строки: " << endl;
			cin >> fl2;

			while (fl1 > lim || fl1 <= 0 || fl2 > lim || fl2 <= 0) {
				cout << "Ошибка! Вы ввели неправильные координаты и вышли за границы игрового поля, попробуйте снова" << endl;
				cout << "Введите номер столбца: " << endl;
				cin >> fl1;
				cout << "Введите номер строки: " << endl;
				cin >> fl2;
			}

			fl1 = fl1 - 1;
			fl2 = fl2 - 1;
			pole2[fl2][fl1] = "ф ";
			//flag1 = 0;

			clearConsole();
			displayField(pole2, lim);
		}

		for (int i = 0; i < lim; i++)
		{
			for (int j = 0; j < lim; j++)
			{
				if (pole2[i][j] == "[]")
				{
					count++;
				}
			}
		}

		for (int i = 0; i < lim; i++)
		{
			for (int j = 0; j < lim; j++)
			{
				if (pole2[i][j] == "ф " || pole2[i][j] == "* ")
				{
					flag++;
				}
			}
		}


		if (count == 0 && flag == min)
		{
			cout << "Поздравляю, ты выиграл! Скоро вас перебросит в меню" << endl;
			system("pause");
			menu();
		}
/*
		displayField(pole2, lim);

		cout << "Введите номер столбца: " << endl;
		cin >> col;
		cout << "Введите номер строки: " << endl;
		cin >> rov;

		while (col > lim || col <= 0)
		{
			cout << "Ошибка! Вы ввели неправильный номер столбца и вышли за границы игрового поля, попробуйте снова" << endl;
			cin >> col;
		}
		while (rov > lim || rov <= 0)
		{
			cout << "Ошибка! Вы ввели неправильный номер строки и вышли за границы игрового поля, попробуйте снова" << endl;
			cin >> rov;
		}

		col = col - 1;
		rov = rov - 1;

		if (pole[rov][col] == 1)
		{
			pole2[rov][col] = "* ";
			//cout << "Вы попали на мину! Игра окончена :(" << endl;
			//game_end = false;
		}
		else

		{
			int mine = minn(pole, lim, rov, col);
			pole2[rov][col] = to_string(mine) + " ";
		}

		clearConsole();
		if (pole2[rov][col] == "* " && life == 1)
		{
			cout << "Вы попали на мину! Игра окончена :(" << endl;
			game_end = false;
		}

		if (pole2[rov][col] == "* " && life == 2)
		{
			cout << "Вы попали на мину, но ничего страшного, т.к. это первый ход, просто наступите на поле, которое отмечено цифрой :)" << endl;
			life = 1;
		}
		*/
		//displayField(pole2, lim);
		if (!game_end)
		{
			break;
		}
		//cout << "1 - поставить флаг, продолжить игру - любая другая клавиша" << endl;
		//cin >> flag1;

		/*if (flag1 == 1)
		{
			cout << "Выберите место, куда вы хотите поставить флаг." << endl;
			cout << "Введите номер столбца: " << endl;
			cin >> fl1;
			cout << "Введите номер строки: " << endl;
			cin >> fl2;

			while (fl1 > lim || fl1 <= 0 || fl2 > lim || fl2 <= 0) {
				cout << "Ошибка! Вы ввели неправильные координаты и вышли за границы игрового поля, попробуйте снова" << endl;
				cout << "Введите номер столбца: " << endl;
				cin >> fl1;
				cout << "Введите номер строки: " << endl;
				cin >> fl2;
			}

			fl1 = fl1 - 1;
			fl2 = fl2 - 1;
			pole2[fl2][fl1] = "ф ";
			flag1 = 0;

			clearConsole();
			displayField(pole2, lim);
		}*/
		life = 1;
		count = 0;
		flag = 0;
	}
}

void game(int lim, int min)
{
	clearConsole();
	srand(time(NULL));
	bool restart = false;
	int restartt = 0;
	int const LIM = 100;
	int pole[LIM][LIM] = { 0 };

	bool error3 = true;

	//Проверка на ошибки
	while (true)
	{
		if (lim > 100 || lim <= 0 || min > (lim * lim) || min < 0)
		{
			error(lim, min);
		}
		else
		{
			break;
		}
	}

	//Генерация поля
	for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < lim;)
		{
			int var = (-(lim * lim) + min) + rand() % (lim * lim + 1);
			bool found = false;

			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < lim; l++)
				{
					if (pole[k][l] == var)
					{
						found = true;
						break;
					}
				}
				if (found)
				{
					break;
				}
			}
			if (!found)
			{
				pole[i][j] = var;
				j++;
			}
		}
	}
	//Показывает сгенерированное поле
	/*for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < lim; j++)
		{
			cout << pole[i][j] << "\t";
		}
		cout << endl;
	}

	//Показывает поле в формате ячейка-мина, 0-1
	cout << "\n" << "\n" << "\n" << "|||||||||||Представление поля в виде 0 1|||||||||||" << "\n" << "\n" << "\n" << endl;
	*/
	for (int i = 0; i < lim; i++)
	{
		for (int j = 0; j < lim; j++)
		{
			if (pole[i][j] > 0)
			{
				pole[i][j] = 1;
				//break;
			}
			else
			{
				pole[i][j] = 0;
				//break;
			}
			//cout << pole[i][j] << "\t";
		}
		//cout << endl;
	}

	//Сообщения после генерации поля
	cout << "\n" << "\n" << "\n" << "Ваше поле успешно сгенерировано!" << "\n" << "Оно состоит из " << lim * lim - min << " безопасных полей и " << min << " полей, содержищих мины " << "\n" << "Сгенерировать новое поле ? " << "\n" << "Нажмите 1, если да" << "\n" << "Если вы хотите сгенерировать новое поле с новым колличеством мин, то нажмите 2" << endl;
	cout << "Нажмите любую другую кнопку, если хотите начать игру" << endl;

	//циклы для рестарта генерации поля
	cin >> restartt;

	//Полная генерация с 0
	if (restartt == 2)
	{
		clearConsole();
		cout << "Введите размер поля: " << endl;
		cin >> lim;
		cout << "Введите количество мин: " << endl;
		cin >> min;
		game(lim, min);
	}

	//генерация с прежними параметрами
	if (restartt == 1)
	{
		restart = true;
	}

	while (restart)
	{
		clearConsole();
		game(lim, min);
	}
	//Цикл для запуска игры
	if (restartt != 1 && restartt != 2)
	{
		start(pole, lim, min);
	}
}

//Функция для запуска игры
void try_game()
{
	clearConsole();
	int lim = 9;
	int min = 9;
	bool error3 = true;
	int  error2 = 1;

	cout << "Начать Игру?" << "\n" << "Нажмите 1, если готовы начать" << "\n" << "Нажмите любую кнопку, если хотите вернуться в меню" << endl;
	back();
	clearConsole();
	cout << "Выберите размер поля и количество мин" << "\n" << "1 число - размер поля(сторона квадрата, максимальное значение - 100)" << "\n" << "второе число количество мин." << endl;
	system("pause");
	clearConsole();
	cout << "Введите размер поля: " << endl;
	cin >> lim;
	cout << "Введите количество мин: " << endl;
	cin >> min;
	//cin >> lim >> min;
	game(lim, min);
}

//Функция для графического вывода ошибок и их исправления
void error(int& lim, int& min)
{
	clearConsole();
	if (min < 0)
	{
		cout << "Ошибка! Выберите положительное количество мин." << endl;
		cin >> min;
	}
	if (lim > 100 || lim <= 0)
	{
		cout << "Ошибка! Вы ввели неправильные границы, попробуйте еще раз." << endl;
		cin >> lim;
	}
	if (min > (lim * lim))
	{
		cout << "Ошибка! Количество мин не может превышать количество полей. Введите новые границы и количество мин." << endl;
		cin >> lim >> min;
	}
}

//функция для инструкции
int instruction()
{
	clearConsole();
	cout << "есть 2 конпки, 1 - открыть поле, 2 - поставить флажок, игровое поле - матрица, чтобы выбрать определенную ячейку, нужно написать координаты ячейки, где 1 число - столбцы, 2 число - строки" << endl;
	cout << "Нажмите 1, чтобы закрыть программу, любую другую кнопку, чтобы вернуться в меню выбора" << endl;
	back();
	return 0;
}

//функция для меню
void menu()
{
	clearConsole();
	int choice = 0;
	cout << "Выберите действие" << endl;
	cout << "1 - Игра" << "\n" << "2 - Инструкция" << "\n" << "3 - Закрыть программу" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		try_game();
		break;
	case 2:
		instruction();
		break;
	case 3:
		break;
	default:
		cout << "Вы ошиблись при вводе! Попробуйте еще раз" << endl;
		menu();
		break;
	}
}

//Запуск
int main()
{
	setlocale(LC_ALL, "rus");

	menu();
	return 0;
}

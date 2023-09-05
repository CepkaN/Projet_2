#include<iostream>
#include"Biblioteca.h"
#include"Studente.h"
#include"Bibliotecario.h"

#include <windows.h>
#include <shellapi.h>

#include <conio.h> 
#include <mmsystem.h>

// список студентов
std::vector<Studente*>_tuttiStudenti;
// один библиотекарь
auto bibliotecario = Bibliotecario::instance();

char menuva[3][35] = { "1. Посмотреть список композиторов ","2. Войти в аккаунт                ","3. Выход                          " };
char menuva1[5][35] = { "1. Добавить произведение          ","2. Убрать произведение            ","3. Просмотреть список             ",
	"4. Получить произведение          ","5. Выйти из аккаунта              " };
char menuva2[5][35] = { "1. Добавить произведение          ","2. Удалить произведение           ","3. Просмотр списка студентов      ",
"4. Просмотреть список             ","5. Выйти из аккаунта              " };

enum color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
HANDLE okno = GetStdHandle(STD_OUTPUT_HANDLE);
enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Esc = 27, BackSpace = 8 };


void setColor(color text, color zalivka) {
	SetConsoleTextAttribute(okno, (WORD)((zalivka << 4) | text));
}
// расположение курсора
void nacialo(int x, int y) {
	COORD koord = { x,y };
	SetConsoleCursorPosition(okno, koord);
}
// покраска меню студента
void pokraska(char var[5][35], int T) {
	for (int i = 0; i < 5; i++) {
		nacialo(20, 6 + i);
		for (int j = 0; j < 35; j++) {
			if (i == T) {
				setColor(White, Blue);
			}
			else
				setColor(White, Black);
			std::cout << var[i][j];
		}
	}
}
// покраски главного меню
void pokraska1(char var[3][35], int T) {
	for (int i = 0; i < 3; i++) {
		nacialo(20, 6 + i);
		for (int j = 0; j < 35; j++) {
			if (i == T) {
				setColor(Black, LightRed);
			}
			else
				setColor(White, Black);
			std::cout << var[i][j];
		}
	}
}
// покраска меню библиотекаря
void pokraska2(char var[5][35], int T) {
	for (int i = 0; i < 5; i++) {
		nacialo(20, 6 + i);
		for (int j = 0; j < 35; j++) {
			if (i == T) {
				setColor(Black, Yellow);
			}
			else
				setColor(White, Black);
			std::cout << var[i][j];
		}
	}
}
// меню студента
void Menu1(Studente* st) {
	int klava1 = 0, y1 = 0, change1 = 0, klava7 = 0;
	system("cls");
	setColor(White, Black);
	nacialo(30, 4);
	std::cout << " АККАУНТ СТУДЕНТА ";
	pokraska(menuva1, change1);
	do
	{
		klava1 = _getch(); // выбор позиции.
		switch (klava1)
		{
		case Up:y1--;
			change1 = y1;
			pokraska(menuva1, change1); break;
		case Down:y1++;
			change1 = y1;
			pokraska(menuva1, change1); break;
		case Enter:system("cls");  break;
		}
	} while (klava1 != Enter);
	if (change1 == 0) {
		do
		{
			system("cls");
			st->AddOpus();
			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change1 == 1) {
		do
		{
			system("cls");
			st->RimOpus();
			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change1 == 2) {
		do
		{
			system("cls");
			st->MostraOpus();
			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change1 == 3) {
		do
		{
			system("cls");
			st->GetAdresse();
			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change1 == 4) {
		system("cls");
		setColor(White, Black);
		return;
	}
	Menu1(st);
}
//меню библиотекаря
void Menu2() {
	int change2 = 0, y2 = 0, klava2 = 0, klava7 = 0;
	system("cls");
	setColor(White, Black);
	nacialo(25, 4);
	std::cout << " АККАУНТ БИБЛИОТЕКАРЯ ";
	pokraska2(menuva2, change2);
	do
	{
		klava2 = _getch(); // выбор позиции.
		switch (klava2)
		{
		case Up:y2--;
			change2 = y2;
			pokraska2(menuva2, change2); break;
		case Down:y2++;
			change2 = y2;
			pokraska2(menuva2, change2); break;
		case Enter:system("cls");  break;
		}
	} while (klava2 != Enter);
	if (change2 == 0) {
		do
		{
			system("cls");
			bibliotecario->AddBiblio();  // Вот это не работает, ну и ладно...
			bibliotecario->AddAutore();
			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change2 == 1) {
		do
		{
			system("cls");
			bibliotecario->RimBiblio();
			bibliotecario->AddAutore();

			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change2 == 2) {
		do
		{
			system("cls");
			bibliotecario->MostraStudenti();
			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change2 == 3) {
		do
		{
			system("cls");
			bibliotecario->MostraB();
			klava7 = _getch();
		} while (klava7 != Enter);
	}
	else if (change2 == 4) {
		system("cls");
		setColor(White, Black);
		return;
	}
	Menu2();
}
// главное меню
void Menu() {

	// значение клавиши, меняемое значение, итоговое значение. Для интерфейса меню.
	int klava = 0, y = 0, change = 0, change3 = 0, y3 = 0, klava7 = 0;
	char t = 'f';
	char u = 'f';
	system("cls");
	setColor(White, Black);
	nacialo(30, 4);
	std::cout << "НОТНАЯ БИБЛИОТЕКА";
	pokraska1(menuva, change);
	do
	{
		klava = _getch(); // выбор позиции.
		switch (klava)
		{
		case Up:y--;
			change = y;
			pokraska1(menuva, change); break;
		case Down:y++;
			change = y;
			pokraska1(menuva, change); break;
		case Enter:system("cls");  break;
		}
	} while (klava != Enter);
	if (change == 0) {
		bibliotecario->AddAutore(); 
		do {
			system("cls");
			bibliotecario->MostraAutore();		
			klava7 = _getch();
		} while (klava7 != Enter);
		
	}
	else if (change == 1) {
		system("cls");
		std::string nome, parol;
		std::cout << "Введите логин : ";
		std::cin >> nome;
		std::cout << "\nВведите пароль : "; std::cin >> parol;
		if (nome == bibliotecario->GetnameBibliotecario() && parol == bibliotecario->GetparoleBiblio()) {
			// Вызывается меню библиотекаря.
			Menu2();
		}
		else {
			Studente* st = new Studente(nome, parol);
			for (auto& i : _tuttiStudenti) {
				if (i->GetnameStudente() == st->GetnameStudente() && i->Getparola() == st->Getparola()) {
					// Вызывается меню студента.
					Menu1(i);
				}
				else {
					std::cout << "Вы не зарегистрированы в библиотеке .";
				}
			}
		}

	}
	else if (change == 2) {
		system("cls");
		setColor(White, Black);
		return;
	}
	Menu();
}



Opera* opera1 = new Opera("Alexandrov", { {"Sonata op.19","https://piano.ru/scores/alex/alex-son.pdf"},{"Etude op.31 №2","https://piano.ru/scores/alex/alex-et-31-2.pdf"}});
Opera* opera2 = new Opera("Balakirev", { {"Islamei","https://piano.ru/scores/balakirev/bal-is.pdf"} });
Opera* opera3 = new Opera("Glinka", { {"Ruslan e Ljudmila","https://piano.ru/gl-rus.html"},{"Ivan Susanin","https://piano.ru/gl-zhizn.html"}});
Opera* opera4 = new Opera("Ljadov", { {"2 Mazurke per pianoforte, Op. 15","https://piano.ru/scores/liadov/liadov-15.pdf"} });
Opera* opera5 = new Opera("Stancinskij", { {"Dodici Schizzi op. 1","https://piano.ru/scores/stan/stan-1.pdf"},{"Notturno ","https://piano.ru/scores/stan/stan-noc.pdf"},{"Canone in si min.","https://piano.ru/scores/stan/stan-can.pdf" } });


int main() {
	setlocale(LC_ALL, "Russian");

	bibliotecario->AddBiblio2(*opera1);
	bibliotecario->AddBiblio2(*opera2);
	bibliotecario->AddBiblio2(*opera3);
	bibliotecario->AddBiblio2(*opera4);
	bibliotecario->AddBiblio2(*opera5);

	Studente* studente = new Studente("Studente", "111111");
	Studente* studente2 = new Studente("Studente2", "222222");
	_tuttiStudenti.push_back(studente);
	_tuttiStudenti.push_back(studente2);

	studente->AddOpus(*opera2);
	studente->AddOpus(*opera3);

	studente2->AddOpus(*opera4);
	studente2->AddOpus(*opera5);
	
	Menu();

	system("cls");
	setColor(White, Black);

	return 0;
}
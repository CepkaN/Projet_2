#pragma once
#include<iostream>
#include<vector>
#include"Opera.h"
#include"Biblioteca.h"

class Studente
{
private:
	std::string _nameStudente;
	std::string _parola;
	std::vector<Opera*> _opusStudente;
public:
	Studente(std::string nameS, std::string par);
	~Studente(){}
	friend Opera* Biblioteca::CercareAutore();

	// Вывод произведения студента
	void MostraOpus();

	// Добавляет автора к списку студента
	void AddOpus();

	// то же самое
	void AddOpus(Opera&op);

	// Дает ссылку на произведение
	void GetAdresse();

	// Имя
	std::string GetnameStudente();

	// Пароль
	std::string Getparola();

	// Удаление произведения
	void RimOpus();
};


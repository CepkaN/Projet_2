#pragma once
#include<set>
#include<iostream>
#include<vector>
#include"Opera.h"
#include"opere.h"


extern std::vector<Opera*> _TutteOpere;


class Biblioteca
{

public:

	Biblioteca(){}
	~Biblioteca(){}

	// Сет для списка композиторов
	std::set<std::string> _nomeAutoreDiOp;

	// Добавляет автора
	void AddAutore(); 

	// Показывает автора
	void MostraAutore();

	// ПОиск по имени
	static Opera* CercareAutore();

	// Удаление автора по имени
	static void RimAuBibl(std::string str);

	// Показывает список произведений
	void MostraB();

	// Добавление произведения
	void AddBiblio2(Opera& op);

};


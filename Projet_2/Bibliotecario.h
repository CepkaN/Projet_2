#pragma once
#include <iostream>
#include"Biblioteca.h"
#include<string>
#include"Opera.h"
#include"Studente.h"

extern std::vector<Opera*> _TutteOpere;
extern std::vector<Studente*>_tuttiStudenti;

class Bibliotecario :public Biblioteca
{
private:
	std::string _nameBibliotecario = "Bibliotecario";
	std::string _paroleBiblio = "BIBLIOTECA";
public:
	Bibliotecario(){}
	~Bibliotecario(){}
	
	// ���
	std::string GetnameBibliotecario();

	// ������
	std::string GetparoleBiblio();

	// �������� ������������
	void RimBiblio();

	// ���������� ������������
	void AddBiblio();

	// ���������� ������ ���������
	void MostraStudenti();
};


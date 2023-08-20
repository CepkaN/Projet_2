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

	// ����� ������������ ��������
	void MostraOpus();

	// ��������� ������ � ������ ��������
	void AddOpus();

	// �� �� �����
	void AddOpus(Opera&op);

	// ���� ������ �� ������������
	void GetAdresse();

	// ���
	std::string GetnameStudente();

	// ������
	std::string Getparola();

	// �������� ������������
	void RimOpus();
};


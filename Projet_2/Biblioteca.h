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

	// ��� ��� ������ ������������
	std::set<std::string> _nomeAutoreDiOp;

	// ��������� ������
	void AddAutore(); 

	// ���������� ������
	void MostraAutore();

	// ����� �� �����
	static Opera* CercareAutore();

	// �������� ������ �� �����
	static void RimAuBibl(std::string str);

	// ���������� ������ ������������
	void MostraB();

	// ���������� ������������
	void AddBiblio2(Opera& op);

};


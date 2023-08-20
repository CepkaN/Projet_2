#pragma once
#include<iostream>
#include<map>
#include<vector>


class Opera
{
private:
	std::string _nomeAutore;
	std::map<std::string, std::string> _titolo{};
public:
	Opera(){}
	Opera(std::string nome, std::map<std::string, std::string> titolo);
	~Opera(){}

	// Показывает имя композитора
	std::string OttenereNomeAutore();

	// Предоставляет список произведений
	std::map<std::string, std::string> Gettitolo();

	// Выводит названия произведений
	void MostraOpera();

	Opera operator=(Opera&op) {
		_nomeAutore = op._nomeAutore;
		_titolo = op._titolo;
	}
};



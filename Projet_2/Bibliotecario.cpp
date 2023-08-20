#include "Bibliotecario.h"

std::string Bibliotecario::GetnameBibliotecario()
{
	return _nameBibliotecario;
}

std::string Bibliotecario::GetparoleBiblio()
{
	return _paroleBiblio;
}

void Bibliotecario::RimBiblio()
{
	std::cout << " ������� ��� ����������� : ";
	std::string nome;
	std::cin >> nome;
	Biblioteca::RimAuBibl(nome);
}

void Bibliotecario::AddBiblio()
{
	std::string nome, lavoro, site;
	std::cout << " ������� ��� ����������� : ";
	std::cin >> nome;
	std::cout << " ������� �������� ������������ : ";
	std::cin.ignore();
	std::getline(std::cin,lavoro);
	std::cout << " ������� ����� : ";
	std::cin >> site;

	Opera* oper = new Opera(nome, { {lavoro,site} });
	_TutteOpere.push_back(oper);
}

void Bibliotecario::MostraStudenti()
{
	for (auto& iii : _tuttiStudenti) {
		std::cout << iii->GetnameStudente() << '\n';
		iii->MostraOpus();
	}
}


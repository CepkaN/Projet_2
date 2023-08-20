#include "Biblioteca.h"



void Biblioteca::AddAutore()
{	
	_nomeAutoreDiOp.clear();
	for (auto& itt : _TutteOpere) {
		_nomeAutoreDiOp.insert(itt->OttenereNomeAutore());
	}
	
}



void Biblioteca::MostraAutore()
{
	std::cout << " �������� ������������ ����� ������������ : " << '\n';
	for (auto& i : _nomeAutoreDiOp) {
		std::cout << i << '\n';
	}
}

Opera* Biblioteca::CercareAutore()
{
	std::cout << " ������� ��� ����������� : ";
	std::string nome;
	std::cin >> nome;
	
	Opera* it4 = nullptr;
	for (auto& it3 : _TutteOpere) {
		if (it3->OttenereNomeAutore() == nome) {
			it3->MostraOpera();
			return it4 = it3;
		}
	}
	std::cout << " ������ ������ ��� � ������ ."; return nullptr;
}

void Biblioteca::RimAuBibl(std::string str)
{
	int a = 0;
	for (auto& it3 : _TutteOpere) {
		if (it3->OttenereNomeAutore() == str) {
			_TutteOpere.erase(_TutteOpere.begin() + a); 
			std::cout << " ����� ����� \n"; return;
		}
		++a;
	}
	std::cout << " ������ \n";
}
void Biblioteca::MostraB()
{
	for (auto& it1 : _TutteOpere) {
		std::cout<<it1->OttenereNomeAutore()<<'\n';
		it1->MostraOpera();
		std::cout << '\n';
	}
}
void Biblioteca::AddBiblio2(Opera& op)
{
	_TutteOpere.push_back(&op);
}
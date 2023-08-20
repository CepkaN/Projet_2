#include "Studente.h"

Studente::Studente(std::string nameS, std::string par):_nameStudente(nameS),_parola(par){}

void Studente::MostraOpus()
{
	for(auto & it1:_opusStudente) {
		std::cout<<it1->OttenereNomeAutore()<<'\n';
		it1->MostraOpera();
		std::cout << '\n';
}
}

void Studente::AddOpus()
{
	Opera* op = Biblioteca::CercareAutore();
	if (op) {
		_opusStudente.push_back(op);
	}
}

void Studente::AddOpus(Opera& op)
{
	_opusStudente.push_back(&op);
}

void Studente::GetAdresse()
{
	int a = 0, b = 0;
	for (auto& it1 : _opusStudente) {
		std::cout << it1->OttenereNomeAutore() << '\n';
		for (auto& it2 : it1->Gettitolo()) {
			std::cout<<++a<<". " << it2.first<<'\n';
		}
		std::cout << '\n';
	}
	int n = 0;
	std::cout << "Введите номер произведения : ";
	std::cin >> n;
	
	for (auto& it1 : _opusStudente) {
		for (auto& it2 : it1->Gettitolo()) {
			++b;
			if (b == a) {
				std::cout << '\n' << it2.second;
			}
		}
	}
}



std::string Studente::GetnameStudente()
{
	return _nameStudente;
}

std::string Studente::Getparola()
{
	return _parola;
}

void Studente::RimOpus()
{
	int a = 0; int b; 
	for (auto& it6 : _opusStudente) {
		std::cout << ++a << "\t"<< it6->OttenereNomeAutore()<<'\n';
	}
	std::cout << " Введите номер для удаления : ";
	std::cin >> b;
	b--;
	_opusStudente.erase(_opusStudente.begin() + b);
}

#include "Opera.h"

Opera::Opera(std::string nome, std::map<std::string, std::string> titolo):_nomeAutore(nome),_titolo(titolo){}

std::string Opera::OttenereNomeAutore()
{
	return _nomeAutore;
}

std::map<std::string, std::string> Opera::Gettitolo()
{
	return _titolo;
}


void Opera::MostraOpera()
{
	int a = 0;
	for (auto &it22 : _titolo) {
		std::cout << ++a << ". " << it22.first << '\n';
	}
}

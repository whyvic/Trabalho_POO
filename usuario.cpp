#include "Usuario.hpp"

Usuario::Usuario(string nome, string email, Endereco* endereco){
	this->nome = nome;
	this->email = email;
	this->endereco = endereco;
	this->pontuacao = 0;
}

string Usuario::getNome(){
	return this->nome;
}

string Usuario::getEmail(){
	return this->email;
}

void Usuario::getEndereco(){
	this->endereco->imprimeEndereco();
}

int Usuario::getPontuacao(){
	return this->pontuacao;
}

void Usuario::mostrarInfos(){
	cout << "Nome: " << this->nome << endl;
	cout << "Email: " << this->email << endl;
	cout << "Endereco: "; this->endereco->imprimeEndereco();
	cout << "Pontuacao: " << this->pontuacao << endl << endl;
}

void Usuario::addPontos(int pontos){
	this->pontuacao += pontos;
}

void Usuario::rmvPontos(int pontos){
	this->pontuacao -= pontos;
}

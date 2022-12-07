#include "Acervo.hpp"


void Acervo::cadastrarUsuario(string nome, string email, Endereco* endereco){
	
	Usuario* novoUsuario = new Usuario(nome, email, endereco);
	
	this->usuarios.push_back(novoUsuario);
	
}


void Acervo::mostrarUsuarios(){
	
	for(int i = 0; i < (this->usuarios.size()); i++){
		cout << "Usuario " << i+1 << endl;
		usuarios[i]->mostrarInfos();
	}
}


bool Acervo::validaUsuario(string emailUsuario){

	for(int i = 0; i < (this->usuarios.size()); i++){
		if(usuarios[i]->getEmail() == emailUsuario){
			return true;
		}		
	}
	
	return false;
	
}

Usuario* Acervo::usuarioValidado(string email){
	for(int i = 0; i < (this->usuarios.size()); i++){
		if(usuarios[i]->getEmail() == email){
			return usuarios[i];
		}		
	}
	
	return 0;
}

#include <vector>
#include "Livro_Filme.cpp"
#include "Usuario.cpp"

class Acervo{
	
	protected:
		vector<Usuario*> usuarios;
	
	public:
					
		virtual void cadastrarUsuario(string nome, string email, Endereco* endereco);
		virtual void mostrarUsuarios();
		bool validaUsuario(string emailUsuario);
		Usuario* usuarioValidado(string email);
		
		
		
};

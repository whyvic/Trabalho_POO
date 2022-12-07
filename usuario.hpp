#include "Endereco.cpp"

using namespace std;


class Usuario{
	
	private:
		string nome;
		string email;
		Endereco* endereco;
		int pontuacao;
		
	public:
		Usuario(string nome, string email, Endereco* endereco);
		string getNome();
		string getEmail();
		void getEndereco();
		void addPontos(int pontos);
		void rmvPontos(int pontos);
		int getPontuacao();
		void mostrarInfos();
		
};

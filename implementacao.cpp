#include "classes/AcervoLivrosEFilmes.cpp"


void mostrarInterface(){
	cout << "\nSeja bem vindo ao nosso acervo de livros e filmes!" << endl;
	cout << "Digite uma das opcoes a seguir: " << endl;
	cout << "[1] Cadastro de Usuario." << endl;
	cout << "[2] Sessao Livros." << endl;
	cout << "[3] Sessao Filmes." << endl;

}

void mostrarInterfaceLivros(){
	cout << "\n[1] Doar Livro ao Acervo." << endl;
	cout << "[2] Mostrar Livros Disponiveis." << endl;
	cout << "[3] Buscar Livro por Nome." << endl;
	cout << "[4] Buscar Livro por Genero." << endl;
	cout << "[5] Buscar Livro por Autor." << endl;
	cout << "[6] Fazer Emprestimo de Livro." << endl;
}

void cadastraUsuario(AcervoFilmes* acervoFilmes, AcervoLivros* acervoLivros){
	string nome, email, cidade, rua, numero, bairro;
	
	cout << "Digite seu nome: ";
	cin.ignore();
	getline(cin, nome);
	cout << "Digite seu email: ";
	cin >> email;
	cout << "Digite sua cidade: ";
	cin.ignore();
	getline(cin, cidade);
	cout << "Digite sua rua: ";
	getline(cin, rua);
	cout << "Digite o numero da sua casa: ";
	cin >> numero;
	cout << "Digite seu bairro: ";
	cin.ignore();
	getline(cin, bairro);
	
	Endereco* endereco = new Endereco(cidade, rua, numero, bairro);
	
	acervoLivros->cadastrarUsuario(nome, email, endereco);
	acervoFilmes->cadastrarUsuario(nome, email, endereco);

	cout << "Usuario cadastrado com sucesso." << endl;
	cout << "Seja bem vindo ao nosso acervo, " << nome << endl;

}

void doarLivro(AcervoLivros* acervo){

	string nomeLivro, autor, genero;
	int paginas, pontuacao;

	cout << "Digite o nome do livro: ";
	cin.ignore();
	getline(cin, nomeLivro);
	

	cout << "Digite o nome do autor: ";
	getline(cin, autor);

	cout << "Digite o genero: ";
	getline(cin, genero);

	cout << "Digite a quantidade de paginas: ";
	cin >> paginas;

	pontuacao = paginas / 10;

	acervo->addLivro(nomeLivro, autor, genero, paginas, pontuacao);
}

void buscarLivroNome(AcervoLivros* acervo){

	string nomeLivro;

	cout << "Digite o nome do livro que deseja buscar: " << endl;
	cin.ignore();
	getline(cin, nomeLivro);		

	acervo->buscaLivro(nomeLivro);
}

void buscarLivroGenero(AcervoLivros* acervo){

	string nomeGenero;

	cout << "Digite o genero do livro que deseja buscar: " << endl;
	cin.ignore();
	getline(cin, nomeGenero);		

	acervo->buscaGenero(nomeGenero);
}

void buscarLivroAutor(AcervoLivros* acervo){
	string nomeAutor;

	cout << "Digite o nome do autor que deseja buscar: " << endl;
	cin.ignore();
	getline(cin, nomeAutor);		

	acervo->buscaAutor(nomeAutor);
}

void emprestarLivro(AcervoLivros* acervo){

	string nomeLivro;

	cout << "Digite o nome do livro que deseja pegar emprestado: " << endl;
	cin.ignore();
	getline(cin, nomeLivro);

	acervo->realizarEmprestimo(nomeLivro);
}

void sessaoLivros(AcervoLivros* acervo){
	int resposta = -1;

	while(resposta != 0){
		mostrarInterfaceLivros();
		cin >> resposta;

		if(resposta == 1){
			doarLivro(acervo);
		}

		else if(resposta == 2){
			acervo->mostrarLivrosDisponiveis();
		}

		else if(resposta == 3){
			buscarLivroNome(acervo);		
		}

		else if(resposta == 4){
			buscarLivroGenero(acervo);	
		}

		else if(resposta == 5){
			buscarLivroAutor(acervo);			
		}

		else if(resposta == 6){

			emprestarLivro(acervo);
		}
	}
}
	

void mostrarInterfaceFilmes(){
	cout << "\n[1] Doar Filme ao Acervo." << endl;
	cout << "[2] Mostrar Filmes Disponiveis." << endl;
	cout << "[3] Buscar Filmes por Nome." << endl;
	cout << "[4] Buscar Filmes por Genero." << endl;
	cout << "[5] Buscar Filmes por Diretor." << endl;
	cout << "[6] Fazer Emprestimo de Filme." << endl;
}

void doarFilme(AcervoFilmes* acervo){

	string nomeFilme, diretor, genero;
	char charTempo[21];
	int horas, minutos, pontuacao;

	cout << "Digite o nome do filme: ";
	cin.ignore();
	getline(cin, nomeFilme);
	

	cout << "Digite o nome do diretor: ";
	getline(cin, diretor);

	cout << "Digite o genero: ";
	getline(cin, genero);

	cout << "Digite a quantidade de horas do filme: ";
	cin >> horas;

	cout << "Digite a quantidade de minutos do filme: ";
	cin >> minutos;

	sprintf(charTempo, "%d horas e %d minutos", horas, minutos);

	string tempo (charTempo);
	pontuacao = (horas * 10) + (minutos * 1.5);

	acervo->addFilme(nomeFilme, diretor, genero, tempo, pontuacao);
}

void buscarFilmeNome(AcervoFilmes* acervo){
	string nomeFilme;

	cout << "Digite o nome do filme que deseja buscar: " << endl;
	cin.ignore();
	getline(cin, nomeFilme);		

	acervo->buscaFilme(nomeFilme);
}

void buscarFilmeGenero(AcervoFilmes* acervo){
	string nomeGenero;

	cout << "Digite o genero do filme que deseja buscar: " << endl;
	cin.ignore();
	getline(cin, nomeGenero);		

	acervo->buscaGenero(nomeGenero);
}
	
void buscarFilmeDiretor(AcervoFilmes* acervo){
	string nomeDiretor;

	cout << "Digite o nome do diretor que deseja buscar: " << endl;
	cin.ignore();
	getline(cin, nomeDiretor);		

	acervo->buscaDiretor(nomeDiretor);
}

void emprestarFilme(AcervoFilmes* acervo){
	string nomeFilme;

	cout << "Digite o nome do filme que deseja pegar emprestado: " << endl;
	cin.ignore();
	getline(cin, nomeFilme);

	acervo->realizarEmprestimo(nomeFilme);
}

void sessaoFilmes(AcervoFilmes* acervo){
	int resposta = -1;

	while(resposta != 0){
		mostrarInterfaceFilmes();
		cin >> resposta;

		if(resposta == 1){
			doarFilme(acervo);
		}

		else if(resposta == 2){
			acervo->mostrarFilmesDisponiveis();
		}

		else if(resposta == 3){
			buscarFilmeNome(acervo);
		}

		else if(resposta == 4){
			buscarFilmeGenero(acervo);
		}

		else if(resposta == 5){
			buscarFilmeDiretor(acervo);
		}

		else if(resposta == 6){
			emprestarFilme(acervo);
		}
	}
}

int main(){
	
	int resposta = -1;
	
	AcervoLivros acervoLivros;
	AcervoFilmes acervoFilmes;
	
	while(resposta != 0){
		
		mostrarInterface();
		
		cin >> resposta;
		
		if(resposta == 1){	
			cadastraUsuario(&acervoFilmes, &acervoLivros);		
		}
		else if(resposta == 2){
			sessaoLivros(&acervoLivros);
		}
		else if(resposta == 3){
			sessaoFilmes(&acervoFilmes);
		}
		
	}
	
	
}

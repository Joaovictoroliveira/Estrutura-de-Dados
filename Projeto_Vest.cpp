#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct {
    string nome;
    int idade;
    int cpf;
    int opcao_curso;
    int numero_inscricao;
    string status_inscricao;
}ELEMENTO;

 typedef struct NO{
 	ELEMENTO aluno;
 	struct NO* proximo;
 }*LISTA;
 
 typedef struct {
    string nome;
    string cargo;
}FISCAL;

 typedef struct NO2{
 	FISCAL funcionario;
 	struct NO2* seguinte;
 }*LISTA2;


 LISTA inicializar(LISTA lista_de_candidados){
 	// lista_de_candidados = (LISTA) malloc( sizeof(NO) );
  	lista_de_candidados = new NO;
 	lista_de_candidados->proximo = NULL;
 	return lista_de_candidados;
 }
 
 LISTA2 comecar(LISTA2 lista_de_funcionarios){
 	lista_de_funcionarios = new NO2;
 	lista_de_funcionarios->seguinte = NULL;
 	return lista_de_funcionarios;
 }

 LISTA cadastrar_candidato(LISTA lista_de_candidados){
     ELEMENTO novo_candidato;
     cout << "Digite o nome do vestibulando: " << endl;
     cin >> novo_candidato.nome;
     cout << "Digite o cpf do vestibulando: " << endl;
     cin >> novo_candidato.cpf;
     cout << "Digite a opcao de curso do vestibulando: " << endl;
     cin >> novo_candidato.opcao_curso;
     cout << "Digite o numero de inscricao do vestibulando: " << endl;
     cin >> novo_candidato.numero_inscricao;
     LISTA aux = new NO;
  	 aux->aluno = novo_candidato;
  	 aux->proximo  = lista_de_candidados;
     lista_de_candidados = aux;
     return lista_de_candidados;
 }
 
 LISTA2 cadastrar_funcionario(LISTA2 lista_de_funcionarios){
 	FISCAL novo_funcionario;
 	cout << "Digite o nome do funcionario: " << endl;
 	cin >> novo_funcionario.nome;
 	cout << "Digite o cargo do funcionario: " << endl;
 	cin >> novo_funcionario.cargo;
 	LISTA2 aux = new NO2;
 	aux->funcionario = novo_funcionario;
 	aux->seguinte = lista_de_funcionarios;
 	lista_de_funcionarios = aux;
 	return lista_de_funcionarios;
 }
 
 void opcaoCurso(){
 	ELEMENTO novo_candidato;
	if (novo_candidato.opcao_curso == 1){
		cout << "Sistemas para Internet" << endl;
		cin >> novo_candidato.opcao_curso;
	}
	
	else if (novo_candidato.opcao_curso == 2) {
		cout << "Gestao empresarial" << endl;
		cin >> novo_candidato.opcao_curso;
	}
	
	else {
		cout << "\nOpcao Invalida";
	}
}

void validar_inscricao(LISTA lista_de_candidados){
	//ELEMENTO novo_candidato;
	LISTA no = lista_de_candidados;
	int validar_inscricao;
	string pagar;	
	cout << "Digite o numero da sua inscricao: " << endl;
	cin >> validar_inscricao;
	
	while(no != NULL){
		if(no->aluno.numero_inscricao == validar_inscricao)
		{
			cout << "inscricao encontrada, ";
			cout << "A inscricao foi paga? " << endl;
			cin >> pagar;	
			if (pagar == "sim"){
				cout << "Ta feito, inscricao efetivada" << endl;
				no->aluno.status_inscricao = "Inscricao efetivada";
			}
			else{
				cout << "Aguardando pagamento do boleto" << endl;
				no->aluno.status_inscricao = "Inscricao nao efetivada";				
			}
		}
		no = no->proximo;
	}
	return;		
}

 void mostrar_inscritos(LISTA lista_de_candidados){
    LISTA no = lista_de_candidados;
 	while(no != NULL){
        if (no->proximo != NULL) {
           cout <<"Nome: " << no->aluno.nome << "\n ";
            cout <<"Cpf: " << no->aluno.cpf << "\n ";
            if(no->aluno.opcao_curso == 1) {
				cout << "Curso: Sistemas para Internet" << endl;
			}else {
				cout << "Curso: Gestao Empresarial" << endl;
			}
            cout << "Numero de inscricao: " << no->aluno.numero_inscricao << "\n ";
            cout << "Status da inscricao: " << no->aluno.status_inscricao << "\n";
            cout << "\n\n";
        }

 		no = no->proximo;
 	}
 	cout << endl;
 }
 
 void mostrar_fiscais(LISTA2 lista_de_funcionarios){
 	LISTA2 no = lista_de_funcionarios;
 	while(no != NULL){
 		if(no->seguinte != NULL){
 			cout << "Nome: " << no->funcionario.nome << "\n";
 			cout << "Cargo: " << no->funcionario.cargo << "\n";
		 }
		 no = no->seguinte;
	 }
	 cout << endl;
 }
 
 void editar_Cadastro(LISTA lista_de_candidados){
 	LISTA no = lista_de_candidados;
	int numero_inscricao;
	cout << "Digite o numero de inscricao: ";
	cin >> numero_inscricao;
	if(numero_inscricao == no->aluno.numero_inscricao){
		cout << "Nome: " << endl;
		cin >> no->aluno.nome;
		cout << "CPF: " << endl;
		cin >> no->aluno.cpf;
		cout << "Opcao: " << endl;
		cin >> no->aluno.opcao_curso;
		
	}else{
		cout << "\n\n ** ERRO: Opcao Invalida! ** \n\n";
	}
}
 

 int numero_de_inscritos(LISTA lista_de_candidados){
     LISTA lista_local = lista_de_candidados;
 	int cont = 0;
 	while(lista_local != NULL){
 		lista_local = lista_local->proximo;
        cont++;
 	}
 	return (cont - 1);
 }
 
 int numero_de_fiscais(LISTA2 lista_de_funcionarios){
 	LISTA2 lista_local = lista_de_funcionarios;
 	int cont = 0;
 	while(lista_local != NULL){
 		lista_local = lista_local->seguinte;
 		cont++;
	 }
	 return (cont -1);
 }
 
 void destruir(LISTA lista_de_candidados){
    if(lista_de_candidados->proximo != NULL ) {
        LISTA noProximo = lista_de_candidados;
        while(noProximo->proximo != NULL){
            cout << "| " << noProximo->aluno.nome;
            cout << " - " << noProximo->aluno.idade << endl;
            lista_de_candidados = noProximo->proximo;
            noProximo->proximo = NULL;
            delete noProximo;
            noProximo = lista_de_candidados;
     	}
      delete lista_de_candidados;
    }
 }

 int buscarFila(LISTA lista_de_candidados, string candidato){
     LISTA noProximo = lista_de_candidados;
     int cont = numero_de_inscritos(lista_de_candidados);
     while(noProximo != NULL){
         if (candidato == noProximo->aluno.nome) {
             return cont;
         }
         cont--;
         noProximo = noProximo->proximo;
     }
     return cont;
 }

 int main(){
     LISTA lista_de_candidados;
     char escolha = 'x';
     ELEMENTO candidado;
     lista_de_candidados = inicializar(lista_de_candidados);
     LISTA2 lista_de_funcionarios;
     FISCAL funcionario;
     lista_de_funcionarios = comecar(lista_de_funcionarios);
     do {
           cout << "\n ------------- MENU DE OPCOES ------------\n";
           cout << "1- \t Cadastrar candidato\n";
           cout << "2- \t Validar inscricao\n";
           cout << "3- \t Encontrar candidato \n";
           cout << "4- \t Listar Candidatos \n";
           cout << "5- \t Editar dados do candidato \n";
           cout << "6- \t Cadastrar fiscal de sala \n";
           cout << "7- \t Listar fiscais \n";
           cout << "8- \t Numero de salas \n";
           cout << "9- \t Encerrar \n\n\n";
           cin >> escolha;
           if(escolha == '1'){
               lista_de_candidados = cadastrar_candidato(lista_de_candidados);
           }
           if(escolha == '2'){
              validar_inscricao(lista_de_candidados);
           }
           if(escolha == '3'){
               string candidato_procurado;
               cout << " Digite o nome do cliente procurado : " << endl;
               cin >> candidato_procurado;
               cout << "O candidato "<< candidato_procurado ;
               cout << " encontra-se na posicao "<< buscarFila(lista_de_candidados, candidato_procurado);
               cout << " da fila" << endl;
           }
           if(escolha == '4'){
               cout << "Candidatos inscritos: " << numero_de_inscritos(lista_de_candidados) << endl;
               mostrar_inscritos(lista_de_candidados);
           }
           if(escolha == '5'){
                editar_Cadastro(lista_de_candidados);
           }
           if(escolha == '6'){
           		lista_de_funcionarios = cadastrar_funcionario(lista_de_funcionarios);
		   }
		   if(escolha == '7'){
		   		cout << "Fiscais cadastrados: " << numero_de_fiscais(lista_de_funcionarios) << endl;
		   		mostrar_fiscais(lista_de_funcionarios);
		   }
		   if(escolha == '8'){
		   		
		   }
       } while( escolha != '9');

     destruir(lista_de_candidados);
     return 0;
 }

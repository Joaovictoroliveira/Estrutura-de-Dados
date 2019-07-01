#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

 typedef struct {
    string nome;
    int cpf;
    int opcao_curso;
    int numero_inscricao;
    int status_inscricao;
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

 typedef struct NO3{
 	ELEMENTO dados_alunos;
 	struct NO3* next;
 	double vetor_aluno[2];
 }*LISTA3;

 LISTA inicializar(LISTA lista_de_candidatos){
  	lista_de_candidatos = new NO;
 	lista_de_candidatos->proximo = NULL;
 	return lista_de_candidatos;
 }
 
 
 LISTA2 comecar(LISTA2 lista_de_funcionarios){
 	lista_de_funcionarios = new NO2;
 	lista_de_funcionarios->seguinte = NULL;
 	return lista_de_funcionarios;
 }

 LISTA3 salas(LISTA3 lista_de_salas){
 	lista_de_salas = new NO3;
 	lista_de_salas->next = NULL;
	return lista_de_salas; 	
 }

 LISTA cadastrar_candidato(LISTA lista_de_candidatos){
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
  	 aux->proximo  = lista_de_candidatos;
     lista_de_candidatos = aux;
     return lista_de_candidatos;
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

 void validar_inscricao(LISTA lista_de_candidatos){
	LISTA no = lista_de_candidatos;
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
				no->aluno.status_inscricao = 1;
			}
			else{
				cout << "Aguardando pagamento do boleto" << endl;
				no->aluno.status_inscricao = 0;				
			}
		}
		no = no->proximo;
	}
	return;		
}

 void mostrar_inscritos(LISTA lista_de_candidatos){
    LISTA no = lista_de_candidatos;
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
 
 void nomes_inscritos_efetivados(LISTA lista_de_candidatos){
 	LISTA no = lista_de_candidatos;
 	while(no != NULL){
        if (no->proximo != NULL) {
        	if(no->aluno.status_inscricao == 1)
           		cout <<"Nome: " << no->aluno.nome << "\n ";	
		}
 		no = no->proximo;
 	}
 	cout << endl;
 }
 
 double numero_de_inscritos_efetivados(LISTA lista_de_candidatos){
 	LISTA no = lista_de_candidatos;
 	double candidatos_efetivados = 0;
 	double salas;
 	while(no != NULL){
        if (no->proximo != NULL) {
        	if(no->aluno.status_inscricao == 1)
           		candidatos_efetivados++;
		}
 		no = no->proximo;
 	}
 	cout << "Candidatos efetivados: " << candidatos_efetivados << "\n";
 	return 0;
 }
 
 double numero_de_salas(LISTA lista_de_candidatos, LISTA3 lista_de_salas){ 	
 	LISTA no = lista_de_candidatos;
 	LISTA3 no2 = lista_de_salas;
 	double candidatos_efetivados = numero_de_inscritos_efetivados(lista_de_candidatos);
 	int salas = 1;
 	
 	salas=candidatos_efetivados / 2;

	
 	for (int i=0; i<salas; i++)
	 
 	cout <<"Nome: " << no->aluno.nome << " " <<  "sala: " << salas << "\n";
	
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
 
 void editar_Cadastro(LISTA lista_de_candidatos){
 	LISTA no = lista_de_candidatos;
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

 void salvar_dados(LISTA lista_de_candidatos){

}

 int numero_de_inscritos(LISTA lista_de_candidatos){
    LISTA lista_local = lista_de_candidatos;
 	int cont = 0;
 	while(lista_local != NULL){
 		lista_local = lista_local->proximo;
        cont++;
 	}
 	return (cont - 1);
 }
 
 double candidato_por_vaga_sistemas(LISTA lista_de_candidatos){
 	LISTA lista_local = lista_de_candidatos;
 	double inscritos_sistemas = 0;
 	while(lista_local != NULL){
 		if (lista_local->proximo != NULL){
 			if(lista_local->aluno.opcao_curso == 1)
 			inscritos_sistemas++;
 			inscritos_sistemas = (inscritos_sistemas / 40);
		 }
		 lista_local = lista_local->proximo;
	 }
		cout << "Candidatos por vaga SI: " << inscritos_sistemas << endl;
	 return 0;
 }
 
 double candidato_por_vaga_gestao(LISTA lista_de_candidatos){
 	LISTA lista_local = lista_de_candidatos;
 	double inscritos_gestao = 0;
 	while(lista_local != NULL){
 		if (lista_local->proximo != NULL){
 			if(lista_local->aluno.opcao_curso == 2)
 			inscritos_gestao++;
 			inscritos_gestao = (inscritos_gestao / 40);
		 }
		 lista_local = lista_local->proximo;
	 }
		cout << "Candidatos por vaga GE: " << inscritos_gestao << endl;
	 return 0;
 }
 
 int inscritos_por_salas(LISTA lista_de_candidatos){
 	LISTA no = lista_de_candidatos;
	int sala = 1;
	int cont = 1;
	while(no != NULL){
        if (no->proximo != NULL) {
        	if(no->aluno.status_inscricao == 1)
        		if(cont <=2){
        			cout <<"Nome: " << no->aluno.nome << " " <<  "sala: " << sala << "\n";
        			cont++;
				}else if(cont>2){
					sala++;
					cont = 0;
				}	
		}
 		no = no->proximo;
 	}
 	cout << endl;
 	return 0;
}
		 
 int numero_de_fiscais(LISTA2 lista_de_funcionarios){
 	LISTA2 lista_local = lista_de_funcionarios;
 	int cont = 0;
 	while(lista_local != NULL){
 		lista_local = lista_local->seguinte;
 		cont++;
	 }
	 return (cont - 1);
 }
 
 void destruir(LISTA lista_de_candidatos){
    if(lista_de_candidatos->proximo != NULL ) {
        LISTA noProximo = lista_de_candidatos;
        while(noProximo->proximo != NULL){
            cout << "| " << noProximo->aluno.nome;
            lista_de_candidatos = noProximo->proximo;
            noProximo->proximo = NULL;
            delete noProximo;
            noProximo = lista_de_candidatos;
     	}
      delete lista_de_candidatos;
    }
 }

 int buscarFila(LISTA lista_de_candidatos, string candidato){
     LISTA noProximo = lista_de_candidatos;
     int cont = numero_de_inscritos(lista_de_candidatos);
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
     LISTA lista_de_candidatos;
     char escolha = 'x';
     ELEMENTO candidado;
     lista_de_candidatos = inicializar(lista_de_candidatos);
     LISTA2 lista_de_funcionarios;
     FISCAL funcionario;
     LISTA3 lista_de_salas;
     ELEMENTO dados_alunos;
     lista_de_funcionarios = comecar(lista_de_funcionarios);
     do {
           cout << "\n ------------- MENU DE OPCOES ------------\n";
           cout << "A- \t Cadastrar candidato\n";
           cout << "B- \t Validar inscricao\n";
           cout << "C- \t Encontrar candidato \n";
           cout << "D- \t Listar Candidatos \n";
           cout << "E- \t Editar dados do candidato \n";
           cout << "F- \t Cadastrar fiscal de sala \n";
           cout << "G- \t Listar fiscais \n";
           cout << "H- \t Inscritos efetivados \n";
           cout << "I- \t numero de salas \n";
           cout << "J- \t Candidatos por sala \n";
           cout << "K- \t Relacao Candidatos por vaga \n";
           cout << "L- \t Salvar dados dos inscritos \n";
           cout << "Z- \t Encerrar \n\n\n";
           cin >> escolha;
           if(escolha == 'A' || escolha == 'a'){
               lista_de_candidatos = cadastrar_candidato(lista_de_candidatos);
           }
           if(escolha == 'B' || escolha == 'b'){
              validar_inscricao(lista_de_candidatos);
           }
           if(escolha == 'C' || escolha == 'c'){
               string candidato_procurado;
               cout << " Digite o nome do candidato procurado : " << endl;
               cin >> candidato_procurado;
               cout << "O candidato "<< candidato_procurado ;
               cout << " encontra-se na posicao "<< buscarFila(lista_de_candidatos, candidato_procurado);
               cout << " da fila" << endl;
           }
           if(escolha == 'D' || escolha == 'd'){
               cout << "Candidatos inscritos: " << numero_de_inscritos(lista_de_candidatos) << endl;
               mostrar_inscritos(lista_de_candidatos);
           }
           if(escolha == 'E' || escolha == 'e'){
                editar_Cadastro(lista_de_candidatos);
           }
           if(escolha == 'F' || escolha == 'f'){
           		lista_de_funcionarios = cadastrar_funcionario(lista_de_funcionarios);
		   }
		   if(escolha == 'G' || escolha == 'g'){
		   		cout << "Fiscais cadastrados: " << numero_de_fiscais(lista_de_funcionarios) << endl;
		   		mostrar_fiscais(lista_de_funcionarios);
		   }
		   if(escolha == 'H' || escolha == 'h'){
		   		nomes_inscritos_efetivados(lista_de_candidatos);
		   		numero_de_inscritos_efetivados(lista_de_candidatos);
		   }
		   if(escolha == 'I' || escolha == 'i'){
		   		numero_de_salas(lista_de_candidatos, lista_de_salas);
		   		
		   }
		   if(escolha == 'J' || escolha == 'j'){
		   		inscritos_por_salas(lista_de_candidatos);
		   }
		   if(escolha == 'K' || escolha == 'k'){
		   		candidato_por_vaga_sistemas(lista_de_candidatos);
		   		candidato_por_vaga_gestao(lista_de_candidatos);
		   }
		   if(escolha == 'L' || escolha == 'l'){
		   		salvar_dados(lista_de_candidatos);
		   }
       } while(escolha != 'z');

     destruir(lista_de_candidatos);
     return 0;
 }


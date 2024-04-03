#include<iostream>
#include <bits/stdc++.h> 
#include <windows.h>
using namespace std;
const int ALPHABET_SIZE = 26; 

// no arvore 
struct TrieNode 
{ 
	struct TrieNode *filhos[ALPHABET_SIZE]; 

	// FimPalavra é verdadeiro se o no
	// representa o fim de uma palabra
	bool FimPalavra; 
}; 

// retorna um novo no (inicia nulo) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->FimPalavra = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->filhos[i] = NULL; 

	return pNode; 
} 

void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->filhos[index]) 
			pCrawl->filhos[index] = getNode(); 

		pCrawl = pCrawl->filhos[index]; 
	} 

	// marca o ultimo nó como folha
	pCrawl->FimPalavra = true; 
} 

bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->filhos[index]) 
			return false; 

		pCrawl = pCrawl->filhos[index]; 
	} 

	return (pCrawl != NULL && pCrawl->FimPalavra); 
} 

class Login{
	
	string usuario,senha;
	
	list<char>usuario_original_hexa; 		// armazena senha e usuario CEO
	list<char>::iterator conteudo;	
	list<char>senha_original_hexa;
	list<char>::iterator conteudo2;
		
	list<char>usuario_oficial_Projetos_hexa;	// projetos
	list<char>::iterator cont_proj;
	list<char>senha_oficial_Projetos_hexa;
	list<char>::iterator cont_proj2;
	
	list<char>usuario_oficial_Comercial_hexa; // comercial
	list<char>::iterator cont_comer;
	list<char>senha_oficial_Comercial_hexa;	
	list<char>::iterator cont_comer2;
	
	list<char>usuario_oficial_RH_hexa;			//rh
	list<char>senha_oficial_RH_hexa;
	list<char>::iterator cont_rh;					
	list<char>::iterator cont_rh2;
	
	list<char>usuario_oficial_Mark_hexa;		//mk
	list<char>senha_oficial_Mark_hexa;
	list<char>::iterator cont_mark;				
	list<char>::iterator cont_mark2;
	
	list<char>usuario_verifica_hexa;	// verifica o que será inserido
	list<char>senha_verifica_hexa;
	list<char>::iterator verifica;		
	list<char>::iterator verifica2;
	
	bool ceo_user,ceo_senha,projetos_user,projetos_senha,comercial_user,comercial_senha,rh_user,rh_senha,mark_user,mark_senha;
	bool cria_eventos_empresa,modifica_projetos_proj,cria_eventos_proj,modifica_projetos_comer,cria_eventos_comer,modifica_projetos_rh,cria_eventos_rh,modifica_projetos_mark,cria_eventos_mark;
	
	queue<string>projetos_proj;
	queue<string>contratos_comer;
	queue<string>projetos_rh;
	queue<string>projetos_mark;
	
	queue<string>funcionarios_proj;
	queue<string>funcionarios_comer;
	queue<string>funcionarios_rh;
	queue<string>funcionarios_mark;
	
	stack<string>convidados_eventos;
	
	
	public:
		
	void preenche_banco_de_dados(){
		
			usuario_original_hexa.push_back('7');usuario_original_hexa.push_back('6');usuario_original_hexa.push_back('6');usuario_original_hexa.push_back('3');
			usuario_original_hexa.push_back('6');usuario_original_hexa.push_back('D');usuario_original_hexa.push_back('6');usuario_original_hexa.push_back('2');
			usuario_original_hexa.push_back('6');usuario_original_hexa.push_back('E');usuario_original_hexa.push_back('6');usuario_original_hexa.push_back('1');
			usuario_original_hexa.push_back('3');usuario_original_hexa.push_back('0');
			
			senha_original_hexa.push_back('7');senha_original_hexa.push_back('7');senha_original_hexa.push_back('6');senha_original_hexa.push_back('5');
			senha_original_hexa.push_back('7');senha_original_hexa.push_back('2');senha_original_hexa.push_back('7');senha_original_hexa.push_back('4');
			senha_original_hexa.push_back('7');senha_original_hexa.push_back('9');senha_original_hexa.push_back('7');senha_original_hexa.push_back('5');
			senha_original_hexa.push_back('3');senha_original_hexa.push_back('0');
			
			usuario_oficial_Projetos_hexa.push_back('6');usuario_oficial_Projetos_hexa.push_back('A');usuario_oficial_Projetos_hexa.push_back('6');usuario_oficial_Projetos_hexa.push_back('B');
			usuario_oficial_Projetos_hexa.push_back('6');usuario_oficial_Projetos_hexa.push_back('C');usuario_oficial_Projetos_hexa.push_back('3');usuario_oficial_Projetos_hexa.push_back('1');
			usuario_oficial_Projetos_hexa.push_back('3');usuario_oficial_Projetos_hexa.push_back('2');usuario_oficial_Projetos_hexa.push_back('5');usuario_oficial_Projetos_hexa.push_back('1');
			usuario_oficial_Projetos_hexa.push_back('3');usuario_oficial_Projetos_hexa.push_back('0');
			
			senha_oficial_Projetos_hexa.push_back('3');senha_oficial_Projetos_hexa.push_back('8');senha_oficial_Projetos_hexa.push_back('3');senha_oficial_Projetos_hexa.push_back('9');
		  	senha_oficial_Projetos_hexa.push_back('3');senha_oficial_Projetos_hexa.push_back('7');senha_oficial_Projetos_hexa.push_back('3');senha_oficial_Projetos_hexa.push_back('5');
			senha_oficial_Projetos_hexa.push_back('7');senha_oficial_Projetos_hexa.push_back('5');senha_oficial_Projetos_hexa.push_back('6');senha_oficial_Projetos_hexa.push_back('F');
			senha_oficial_Projetos_hexa.push_back('3');senha_oficial_Projetos_hexa.push_back('0');
			
			
			usuario_oficial_Comercial_hexa.push_back('7');usuario_oficial_Comercial_hexa.push_back('3');usuario_oficial_Comercial_hexa.push_back('7');usuario_oficial_Comercial_hexa.push_back('2');
			usuario_oficial_Comercial_hexa.push_back('7');usuario_oficial_Comercial_hexa.push_back('4');usuario_oficial_Comercial_hexa.push_back('3');usuario_oficial_Comercial_hexa.push_back('4');
			usuario_oficial_Comercial_hexa.push_back('3');usuario_oficial_Comercial_hexa.push_back('5');usuario_oficial_Comercial_hexa.push_back('5');usuario_oficial_Comercial_hexa.push_back('0');
			usuario_oficial_Comercial_hexa.push_back('3');usuario_oficial_Comercial_hexa.push_back('0');
	
			senha_oficial_Comercial_hexa.push_back('3');senha_oficial_Comercial_hexa.push_back('3');senha_oficial_Comercial_hexa.push_back('3');senha_oficial_Comercial_hexa.push_back('2');
			senha_oficial_Comercial_hexa.push_back('3');senha_oficial_Comercial_hexa.push_back('6');senha_oficial_Comercial_hexa.push_back('3');senha_oficial_Comercial_hexa.push_back('5');
			senha_oficial_Comercial_hexa.push_back('7');senha_oficial_Comercial_hexa.push_back('3');senha_oficial_Comercial_hexa.push_back('6');senha_oficial_Comercial_hexa.push_back('4');
			senha_oficial_Comercial_hexa.push_back('3');senha_oficial_Comercial_hexa.push_back('0');
	
	
			usuario_oficial_RH_hexa.push_back('7');usuario_oficial_RH_hexa.push_back('A');usuario_oficial_RH_hexa.push_back('6');usuario_oficial_RH_hexa.push_back('7');
			usuario_oficial_RH_hexa.push_back('6');usuario_oficial_RH_hexa.push_back('8');usuario_oficial_RH_hexa.push_back('3');usuario_oficial_RH_hexa.push_back('3');
			usuario_oficial_RH_hexa.push_back('3');usuario_oficial_RH_hexa.push_back('4');usuario_oficial_RH_hexa.push_back('4');usuario_oficial_RH_hexa.push_back('1');
			usuario_oficial_RH_hexa.push_back('3');usuario_oficial_RH_hexa.push_back('0');
		
			senha_oficial_RH_hexa.push_back('3');senha_oficial_RH_hexa.push_back('8');senha_oficial_RH_hexa.push_back('3');senha_oficial_RH_hexa.push_back('5');
			senha_oficial_RH_hexa.push_back('3');senha_oficial_RH_hexa.push_back('4');senha_oficial_RH_hexa.push_back('3');senha_oficial_RH_hexa.push_back('7');
			senha_oficial_RH_hexa.push_back('6');senha_oficial_RH_hexa.push_back('2');senha_oficial_RH_hexa.push_back('7');senha_oficial_RH_hexa.push_back('3');
			senha_oficial_RH_hexa.push_back('3');senha_oficial_RH_hexa.push_back('0');
	
	
			usuario_oficial_Mark_hexa.push_back('7');usuario_oficial_Mark_hexa.push_back('6');usuario_oficial_Mark_hexa.push_back('6');usuario_oficial_Mark_hexa.push_back('C');
			usuario_oficial_Mark_hexa.push_back('7');usuario_oficial_Mark_hexa.push_back('4');usuario_oficial_Mark_hexa.push_back('3');usuario_oficial_Mark_hexa.push_back('1');
			usuario_oficial_Mark_hexa.push_back('3');usuario_oficial_Mark_hexa.push_back('2');usuario_oficial_Mark_hexa.push_back('4');usuario_oficial_Mark_hexa.push_back('D');
			usuario_oficial_Mark_hexa.push_back('3');usuario_oficial_Mark_hexa.push_back('0');
			
			senha_oficial_Mark_hexa.push_back('3');senha_oficial_Mark_hexa.push_back('4');senha_oficial_Mark_hexa.push_back('3');senha_oficial_Mark_hexa.push_back('3');
			senha_oficial_Mark_hexa.push_back('3');senha_oficial_Mark_hexa.push_back('4');senha_oficial_Mark_hexa.push_back('3');senha_oficial_Mark_hexa.push_back('0');
			senha_oficial_Mark_hexa.push_back('7');senha_oficial_Mark_hexa.push_back('A');senha_oficial_Mark_hexa.push_back('7');senha_oficial_Mark_hexa.push_back('8');
			senha_oficial_Mark_hexa.push_back('3');senha_oficial_Mark_hexa.push_back('0');
			
			projetos_proj.push("Otimização de rede wi-fi Banco do Brasil");projetos_proj.push("Teste de vulnerabilidade PMDF");projetos_proj.push("Criação do site para Construção & Cia");
			contratos_comer.push("Otimizacão de rede Wi-Fi do Banco do Brasil");contratos_comer.push("Teste de vunerabilidade do sitema de informações da PMDF");contratos_comer.push("Desenvolvimento web para a loja Construção & Cia");
			projetos_rh.push("Aprimorar o sistema de classificação do funcionários");projetos_rh.push("Elaboração de uma metodologia para o motivar os funcionários");projetos_rh.push("Aprimorar a política interna na entrega de projetos");
			projetos_mark.push("Atualizar a logo da empresa");projetos_mark.push("Arte do dia das Mães");projetos_mark.push("Atualizar as redes socias ");
			
			funcionarios_proj.push("Lucia Barros");funcionarios_proj.push("Alice Costa");funcionarios_proj.push("Carlos Alberto");
			funcionarios_comer.push("Mathias Ribeiro");funcionarios_comer.push("Nathalia Andrade");funcionarios_comer.push("Gabriel Barbosa");
			funcionarios_rh.push("Gabriela Cardoso");funcionarios_rh.push("Marilia Campos");funcionarios_rh.push("Mathues Borges");
			funcionarios_mark.push("Julia Duarte");funcionarios_mark.push("Beatriz Castro");funcionarios_mark.push("Juliana Freitas");
	}
	void cria_arquivos(){
		
		fstream EvEmpresa,EvProjetos,EvComercial,EvRh,EvMarketing,Banco_de_Dados;
		fstream Projetos_Dir_Projetos,Contratos_Dir_Comercial,Projetos_Dir_RH,Projetos_Dir_Marketing;
		
		EvEmpresa.open("Agenda Empresa.txt", ios::in | ios::app);
		EvEmpresa.close();
		
		EvProjetos.open("Agenda Projetos.txt", ios::in | ios::app);
		EvProjetos.close();
		
		EvComercial.open("Agenda Comercial.txt", ios::in | ios::app);;
		EvComercial.close();
		
		EvRh.open("Agenda Recursos Humanos.txt", ios::in | ios::app);
		EvRh.close();
		
		EvMarketing.open("Agenda Marketing.txt", ios::in | ios::app);
		EvMarketing.close();
	
	
		Projetos_Dir_Projetos.open("Projetos Projetos.txt",ios::in | ios::app);
		Projetos_Dir_Projetos.close(); 
		
		Contratos_Dir_Comercial.open("Contratos Comercial.txt",ios::in | ios::app);
		Contratos_Dir_Comercial.close();
		
		Projetos_Dir_RH.open("Projetos Recursos Humanos.txt",ios::in | ios::app);
		Projetos_Dir_RH.close();
		
		Projetos_Dir_Marketing.open("Projetos Marketing.txt",ios::in | ios::app);
		Projetos_Dir_Marketing.close();
		
		Banco_de_Dados.open("Banco de Dados Empresa.txt",ios::in | ios::app);
		Banco_de_Dados.close();
			
	}
	void faz_login(){
	
	
		list<int>binario0,binario1,binario2,binario3,binario4,binario5;
		list<int>senha0,senha1,senha2,senha3,senha4,senha5;
		
		int aux,au,i,junt,tamjunt,J,Junt,Ju,tam0,tam1,tam2,tam3,tam4,tam5,tentativas;
		int tam_senha0,tam_senha1,tam_senha2,tam_senha3,tam_senha4,tam_senha5;
		
		int Junta[100];
		int junta[100];
		
		int dif0,dif1,dif2,dif3,dif4,dif5;
		int dif_senha0,dif_senha1,dif_senha2,dif_senha3,dif_senha4,dif_senha5;
		
		int aux0[8],aux1[8],aux2[8],aux3[8],aux4[8],aux5[8];
		int senha_aux0[8],senha_aux1[8],senha_aux2[8],senha_aux3[8],senha_aux4[8],senha_aux5[8];
			
		
		if(usuario_original_hexa.empty() || senha_original_hexa.empty() || usuario_oficial_Projetos_hexa.empty() || senha_oficial_Projetos_hexa.empty() ||
			usuario_oficial_Comercial_hexa.empty() || senha_oficial_Comercial_hexa.empty() || usuario_oficial_RH_hexa.empty() || senha_oficial_RH_hexa.empty() ||
			usuario_oficial_Mark_hexa.empty() || senha_oficial_Mark_hexa.empty()){
			cout<<"Informações do banco de dados estão incompletas, logo não podem ser acessadas para verificar as credenciais de usuário"<<endl;
		}else{
			cout<<"\t\t\t\t\t\t\t" <<"Insira o usuário : ";
			cin>>usuario;
			cout<<"\t\t\t\t\t\t\t" <<"Insira a senha : ";
			cin>>senha;
		
			tentativas=3;
	
			while(usuario.size()!=6 && senha.size()!=6){
				cout<<"Quantidade de caracteres incorreta ( deve ter 6 caracteres ). Você possui "<<tentativas<<" tentativas !!!!!!"<<endl;
				cout<<"Insira novamente o usuario : ";
				cin>>usuario;
				cout<<"Insira novamente a senha : ";
				cin>>senha;
				tentativas--;
				if(tentativas==0)
					exit(0);
			}if(usuario.size()==6 && senha.size()==6){
		
		// 1 -> Ao inserir o usuario com 6 digitos, o seguinte laço utiliza o decimal do caractere para calcular o seu binário.
		// O binário de cada caractere é armazenado em uma lista própria.
		
				for(i=0;i<usuario.size();i++){
					if(i==0){
						aux=(usuario[i]*1); 
						while(aux!=0){
							if(aux == 1){
								binario0.push_back(1);// se o decimal for zero (pela Tabela ASCII vale zero), armazena na lista zero.
								aux=0; 
							}else{
								binario0.push_back(aux%2);
								aux = aux/2;
							}
						}
					}
					if(i==1){
						aux=(usuario[i]*1); 
						while(aux!=0){
							if(aux == 1){
								binario1.push_back(1);
								aux=0; 
							}else{
								binario1.push_back(aux%2);
								aux = aux/2;
							}
						}	
					}
					if(i==2){
						aux=(usuario[i]*1);
						while(aux!=0){
							if(aux == 1){
								binario2.push_back(1);
								aux=0; 
							}else{
								binario2.push_back(aux%2);
								aux = aux/2;
							}
						}	
					}
					if(i==3){
						aux=(usuario[i]*1); 
						while(aux!=0){
							if(aux == 1){
								binario3.push_back(1);
								aux=0; 
							}else{
								binario3.push_back(aux%2);
								aux = aux/2;
							}
						}	
					}
					if(i==4){
						aux=(usuario[i]*1); 
						while(aux!=0){
							if(aux == 1){
								binario4.push_back(1);
								aux=0; 
							}else{
								binario4.push_back(aux%2);
								aux = aux/2;
							}
						}	
					}
					if(i==5){
						aux=(usuario[i]*1); 
						while(aux!=0){
							if(aux == 1){
								binario5.push_back(1);
								aux=0; 
							}else{
								binario5.push_back(aux%2);
								aux = aux/2;
							}
						}	
					}
				}
		
				for(i=0;i<senha.size();i++){ // laco da senha
					if(i==0){
						au=(senha[i]*1); 
						while(au!=0){
							if(au == 1){
								senha0.push_back(1);// se o decimal for zero (pela Tabela ASCII vale zero), armazena na lista zero.
								au=0; 
							}else{
								senha0.push_back(au%2);
								au = au/2;
							}
						}
					}
					if(i==1){
						au=(senha[i]*1); 
						while(au!=0){
							if(au == 1){
								senha1.push_back(1);
								au=0; 
							}else{
								senha1.push_back(au%2);
								au = au/2;
							}
						}	
					}
					if(i==2){
						au=(senha[i]*1);
						while(au!=0){
							if(au == 1){
								senha2.push_back(1);
								au=0; 
							}else{
								senha2.push_back(au%2);
								au = au/2;
							}
						}	
					}
					if(i==3){
						au=(senha[i]*1); 
						while(au!=0){
							if(au == 1){
								senha3.push_back(1);
								au=0; 
							}else{
								senha3.push_back(au%2);
								au = au/2;
							}
						}	
					}
					if(i==4){
						au=(senha[i]*1); 
						while(au!=0){
							if(au == 1){
								senha4.push_back(1);
								au=0; 
							}else{
								senha4.push_back(au%2);
								au = au/2;
							}
						}	
					}
					if(i==5){
						au=(senha[i]*1); 
						while(au!=0){
							if(au == 1){
								senha5.push_back(1);
								au=0; 
							}else{
								senha5.push_back(au%2);
								au = au/2;
							}
						}	
					}
				}
		
		// 2 -> Como no algoritmo do SHA-1, completamos as coversões em binário com 0 até que tenha 8 bits.
		// Para isso, utilizamos arrays para facilitar a manipulação.
	
				tam0 = binario0.size();
				int seq0[tam0];
				dif0=8-tam0; // quantos zeros serao adicionados
				int j=0;
				
				for(i=0;i<tam0;i++){
					seq0[i]=binario0.back();
					binario0.pop_back();
				}
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<dif0;i++)
							aux0[i]=0;
					}else{
						for(i=dif0;i<8;i++){
							aux0[i]=seq0[j];
							j++;
						}
					}
			 	}
			
				tam1 = binario1.size();
				int seq1[tam1];
				dif1=8-tam1; 
				int k=0;
				
				for(i=0;i<tam1;i++){
					seq1[i]=binario1.back();
					binario1.pop_back();
				}
				
				for(i=0;i<8;i++){ 
					if(i==0){
						for(i=0;i<dif1;i++)
							aux1[i]=0;
					}else{
						for(i=dif1;i<8;i++){
							aux1[i]=seq1[k];
							k++;
						}
					}
				}
				
		
				tam2 = binario2.size();
				int seq2[tam2];
				dif2=8-tam2; 
				int l=0;
				
				for(i=0;i<tam2;i++){
					seq2[i]=binario2.back();
					binario2.pop_back();
				}
				
				for(i=0;i<8;i++){ 
					if(i==0){
						for(i=0;i<dif2;i++)
							aux2[i]=0;
					}else{
						for(i=dif2;i<8;i++){
							aux2[i]=seq2[l];
							l++;
						}
					}
				}
				
				
				tam3 = binario3.size();
				int seq3[tam3];
				dif3=8-tam3; 
				int m=0;
				
				for(i=0;i<tam3;i++){
					seq3[i]=binario3.back();
					binario3.pop_back();
				}
				
				for(i=0;i<8;i++){ 
					if(i==0){
						for(i=0;i<dif3;i++)
							aux3[i]=0;
					}else{
						for(i=dif3;i<8;i++){
							aux3[i]=seq3[m];
							m++;
						}
					}
				}
		
				tam4 = binario4.size();
				int seq4[tam4];
				dif4=8-tam4; 
				int n=0;
				
				for(i=0;i<tam4;i++){
					seq4[i]=binario4.back();
					binario4.pop_back();
				}
				
				for(i=0;i<8;i++){ 
					if(i==0){
						for(i=0;i<dif4;i++)
							aux4[i]=0;
					}else{
						for(i=dif4;i<8;i++){
							aux4[i]=seq4[n];
							n++;
						}
					}
				}
			
			
				tam5 = binario5.size();
				int seq5[tam5];
				dif5=8-tam5; 
				int p=0;
				
				for(i=0;i<tam5;i++){
					seq5[i]=binario5.back();
					binario5.pop_back();
				}
				
				for(i=0;i<8;i++){ 
					if(i==0){
						for(i=0;i<dif5;i++)
							aux5[i]=0;
					}else{
						for(i=dif5;i<8;i++){
							aux5[i]=seq5[p];
							p++;
						}
					}
				}
				
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////-> Senha
				tam_senha0 = senha0.size();
				int SEQ0[tam_senha0];
				dif_senha0=8-tam_senha0; // quantos zeros serao adicionados
				int Q=0;
				
				for(i=0;i<tam_senha0;i++){
					SEQ0[i]=senha0.back();
					senha0.pop_back();
				}
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<dif_senha0;i++)
							senha_aux0[i]=0;
					}else{
						for(i=dif_senha0;i<8;i++){
							senha_aux0[i]=SEQ0[Q];
							Q++;
						}
					}
				}
		
				tam_senha1 = senha1.size();
				int SEQ1[tam_senha1];
				dif_senha1=8-tam_senha1; // quantos zeros serao adicionados
				int W=0;
				
				for(i=0;i<tam_senha1;i++){
					SEQ1[i]=senha1.back();
					senha1.pop_back();
				}
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<dif_senha1;i++)
							senha_aux1[i]=0;
					}else{
						for(i=dif_senha1;i<8;i++){
							senha_aux1[i]=SEQ1[W];
							W++;
						}
					}
				}
			
				tam_senha2 = senha2.size();
				int SEQ2[tam_senha2];
				dif_senha2=8-tam_senha2; // quantos zeros serao adicionados
				int E=0;
				
				for(i=0;i<tam_senha2;i++){
					SEQ2[i]=senha2.back();
					senha2.pop_back();
				}
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<dif_senha2;i++)
							senha_aux2[i]=0;
					}else{
						for(i=dif_senha2;i<8;i++){
							senha_aux2[i]=SEQ2[E];
							E++;
						}
					}
				}
				
			
				tam_senha3 = senha3.size();
				int SEQ3[tam_senha3];
				dif_senha3 = 8-tam_senha3; // quantos zeros serao adicionados
				int R=0;
				
				for(i=0;i<tam_senha3;i++){
					SEQ3[i]=senha3.back();
					senha3.pop_back();
				}
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<dif_senha3;i++)
							senha_aux3[i]=0;
					}else{
						for(i=dif_senha3;i<8;i++){
							senha_aux3[i]=SEQ3[R];
							R++;
						}
					}
				}
				
		
				tam_senha4 = senha4.size();
				int SEQ4[tam_senha4];
				dif_senha4 = 8-tam_senha4; // quantos zeros serao adicionados
				int T=0;
				
				for(i=0;i<tam_senha4;i++){
					SEQ4[i]=senha4.back();
					senha4.pop_back();
				}
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<dif_senha4;i++)
							senha_aux4[i]=0;
					}else{
						for(i=dif_senha4;i<8;i++){
							senha_aux4[i]=SEQ4[T];
							T++;
						}
					}
				}

		
				tam_senha5 = senha5.size();
				int SEQ5[tam_senha5];
				dif_senha5=8-tam_senha5; // quantos zeros serao adicionados
				int Y=0;
				
				for(i=0;i<tam_senha5;i++){
					SEQ5[i]=senha5.back();
					senha5.pop_back();
				}
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<dif_senha5;i++)
							senha_aux5[i]=0;
					}else{
						for(i=dif_senha5;i<8;i++){
							senha_aux5[i]=SEQ5[Y];
							Y++;
						}
					}
				}
				
			// 3 -> Juntamos todos os arrays auxiliares no array junta[100]
			
				J=0;j=0;k=0;l=0;m=0;n=0;p=0;
				
				for(junt=0;junt<6;junt++){
					if(junt==0){
						for(i=0;i<8;i++){
							junta[J]=aux0[j];
							J++;j++;
						}
					}
					if(junt==1){
						for(i=8;i<16;i++){
							junta[J]=aux1[k];
							J++;k++;
						}
					}
					if(junt==2){
						for(i=16;i<24;i++){
							junta[J]=aux2[l];
							J++;l++;
						}
					}
					if(junt==3){
						for(i=24;i<32;i++){
							junta[J]=aux3[m];
							J++;m++;
						}
					}
					if(junt==4){
						for(i=32;i<40;i++){
							junta[J]=aux4[n];
							J++;n++;
						}
					}
					if(junt==5){
						for(i=40;i<48;i++){
							junta[J]=aux5[p];
							J++;p++;
						}
					}
				}
			
				Ju=0;Q=0;W=0;E=0;R=0;T=0;Y=0;
			
				for(Junt=0;Junt<6;Junt++){
					if(Junt==0){
						for(i=0;i<8;i++){
							Junta[Ju]=senha_aux0[Q];
							Ju++;Q++;
						}
					}
					if(Junt==1){
						for(i=8;i<16;i++){
							Junta[Ju]=senha_aux1[W];
							Ju++;W++;
						}
					}
					if(Junt==2){
						for(i=16;i<24;i++){
							Junta[Ju]=senha_aux2[E];
							Ju++;E++;
						}
					}
					if(Junt==3){
						for(i=24;i<32;i++){
							Junta[Ju]=senha_aux3[R];
							Ju++;R++;
						}
					}
					if(Junt==4){
						for(i=32;i<40;i++){
							Junta[Ju]=senha_aux4[T];
							Ju++;T++;
						}
					}
					if(Junt==5){
						for(i=40;i<48;i++){
							Junta[Ju]=senha_aux5[Y];
							Ju++;Y++;
						}
					}
				}
			
			// 4 -> Pegamos o tamanho do array "junta" ao juntar os arrays com os binarios, nesse caso 6 * 8 = 48, e transformamos em binario.
			// Utilizamos o mesmo processo anterior : armazenar em uma lista -> array auxiliar -> completa com zero -> armazena no array junta[100]
			
				list<int>a;
				int t;
				t=48;
			    while(t!=0){
					if(t == 1){
						a.push_back(1);
						t=0; 
					}else{
						a.push_back(t%2);
						t = t/2;
					}
				}
			   	    
				int atam=a.size(); 
				int A[atam];
				int DIF=8-atam;
				int auxA[8];
				int contA=0;
				
				for(i=0;i<atam;i++){
					A[i]=a.back();
					a.pop_back();
				}
				
				for(i=0;i<8;i++){ // preenche com zero o array no inicio
					if(i==0){
						for(i=0;i<DIF;i++)
							auxA[i]=0;
					}else{
						for(i=DIF;i<8;i++){
							auxA[i]=A[contA];
							contA++;
						}
					}
				}
				
				i=0;
				for(J=48;J<56;J++){
					junta[J]=auxA[i]; // adiciona o binario de 48 ao final do array que armazena os bits do usuario
					i++;
				}
				i=0;
				for(Ju=48;Ju<56;Ju++){ // adiciona o binario de 48 ao final do array que armazena os bits 
					Junta[Ju]=auxA[i];
					i++;
				}
				
			// 5 -> Coverteremos em blocos de 4 os valores em binarios para hexadecimal ( sem ser da ASCII ) 
		
				char senhaCEO[13]; // usuario em hexa
				char senha_realCEO[13]; // senha em hexa
			
			
				for(i=0;i<14;i++){ // sao 14 ( de 0 a 13 ) grupamentos de 4 bits (usuario)
					if(i==0){
						if((junta[0]==0) && (junta[1]==0) && (junta[2]==0) && (junta[3]==0)){  
							senhaCEO[i]='0';
						}
						if((junta[0]==0) && (junta[1]==0) && (junta[2]==0) && (junta[3]==1)){ 
							senhaCEO[i]='1';
						}
						if((junta[0]==0) && (junta[1]==0) && (junta[2]==1) && (junta[3]==0)){ 
							senhaCEO[i]='2';
						}
						if((junta[0]==0) && (junta[1]==0) && (junta[2]==1) && (junta[3]==1)){ 
							senhaCEO[i]='3';
						}
						if((junta[0]==0) && (junta[1]==1) && (junta[2]==0) && (junta[3]==0)){ 
							senhaCEO[i]='4';
						}
						if((junta[0]==0) && (junta[1]==1) && (junta[2]==0) && (junta[3]==1)){ 
							senhaCEO[i]='5';
						}
						if((junta[0]==0) && (junta[1]==1) && (junta[2]==1) && (junta[3]==0)){ 
							senhaCEO[i]='6';
						}
						if((junta[0]==0) && (junta[1]==1) && (junta[2]==1) && (junta[3]==1)){ 
							senhaCEO[i]='7';
						}
						if((junta[0]==1) && (junta[1]==0) && (junta[2]==0) && (junta[3]==0)){ 
							senhaCEO[i]='8';
						}
						if((junta[0]==1) && (junta[1]==0) && (junta[2]==0) && (junta[3]==1)){ 
							senhaCEO[i]='9';
						}
						if((junta[0]==1) && (junta[1]==0) && (junta[2]==1) && (junta[3]==0)){ 
							senhaCEO[i]='A';
						}
						if((junta[0]==1) && (junta[1]==0) && (junta[2]==1) && (junta[3]==1)){ 
							senhaCEO[i]='B';
						}
						if((junta[0]==1) && (junta[1]==1) && (junta[2]==0) && (junta[3]==0)){ 
							senhaCEO[i]='C';
						}
						if((junta[0]==1) && (junta[1]==1) && (junta[2]==0) && (junta[3]==1)){ 
							senhaCEO[i]='D';
						}
						if((junta[0]==1) && (junta[1]==1) && (junta[2]==1) && (junta[3]==0)){ 
							senhaCEO[i]='E';
						}
						if((junta[0]==1) && (junta[1]==1) && (junta[2]==1) && (junta[3]==1)){ 
							senhaCEO[i]='F';
						}
					}
					if(i==1){
						if((junta[4]==0) && (junta[5]==0) && (junta[6]==0) && (junta[7]==0)){  
							senhaCEO[i]='0';
						}
						if((junta[4]==0) && (junta[5]==0) && (junta[6]==0) && (junta[7]==1)){ 
							senhaCEO[i]='1';
						}
						if((junta[4]==0) && (junta[5]==0) && (junta[6]==1) && (junta[7]==0)){ 
							senhaCEO[i]='2';
						}
						if((junta[4]==0) && (junta[5]==0) && (junta[6]==1) && (junta[7]==1)){ 
							senhaCEO[i]='3';
						}
						if((junta[4]==0) && (junta[5]==1) && (junta[6]==0) && (junta[7]==0)){ 
							senhaCEO[i]='4';
						}
						if((junta[4]==0) && (junta[5]==1) && (junta[6]==0) && (junta[7]==1)){  
							senhaCEO[i]='5';
						}
						if((junta[4]==0) && (junta[5]==1) && (junta[6]==1) && (junta[7]==0)){ 
							senhaCEO[i]='6';
						}
						if((junta[4]==0) && (junta[5]==1) && (junta[6]==1) && (junta[7]==1)){ 
							senhaCEO[i]='7';
						}
						if((junta[4]==1) && (junta[5]==0) && (junta[6]==0) && (junta[7]==0)){ 
							senhaCEO[i]='8';
						}
						if((junta[4]==1) && (junta[5]==0) && (junta[6]==0) && (junta[7]==1)){
							senhaCEO[i]='9';
						}
						if((junta[4]==1) && (junta[5]==0) && (junta[6]==1) && (junta[7]==0)){ 
							senhaCEO[i]='A';
						}
						if((junta[4]==1) && (junta[5]==0) && (junta[6]==1) && (junta[7]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[4]==1) && (junta[5]==1) && (junta[6]==0) && (junta[7]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[4]==1) && (junta[5]==1) && (junta[6]==0) && (junta[7]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[4]==1) && (junta[5]==1) && (junta[6]==1) && (junta[7]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[4]==1) && (junta[5]==1) && (junta[6]==1) && (junta[7]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==2){
						if((junta[8]==0) && (junta[9]==0) && (junta[10]==0) && (junta[11]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[8]==0) && (junta[9]==0) && (junta[10]==0) && (junta[11]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[8]==0) && (junta[9]==0) && (junta[10]==1) && (junta[11]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[8]==0) && (junta[9]==0) && (junta[10]==1) && (junta[11]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[8]==0) && (junta[9]==1) && (junta[10]==0) && (junta[11]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[8]==0) && (junta[9]==1) && (junta[10]==0) && (junta[11]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[8]==0) && (junta[9]==1) && (junta[10]==1) && (junta[11]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[8]==0) && (junta[9]==1) && (junta[10]==1) && (junta[11]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[8]==1) && (junta[9]==0) && (junta[10]==0) && (junta[11]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[8]==1) && (junta[9]==0) && (junta[10]==0) && (junta[11]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[8]==1) && (junta[9]==0) && (junta[10]==1) && (junta[11]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[8]==1) && (junta[9]==0) && (junta[10]==1) && (junta[11]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[8]==1) && (junta[9]==1) && (junta[10]==0) && (junta[11]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[8]==1) && (junta[9]==1) && (junta[10]==0) && (junta[11]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[8]==1) && (junta[9]==1) && (junta[10]==1) && (junta[11]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[8]==1) && (junta[9]==1) && (junta[10]==1) && (junta[11]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==3){
						if((junta[12]==0) && (junta[13]==0) && (junta[14]==0) && (junta[15]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[12]==0) && (junta[13]==0) && (junta[14]==0) && (junta[15]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[12]==0) && (junta[13]==0) && (junta[14]==1) && (junta[15]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[12]==0) && (junta[13]==0) && (junta[14]==1) && (junta[15]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[12]==0) && (junta[13]==1) && (junta[14]==0) && (junta[15]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[12]==0) && (junta[13]==1) && (junta[14]==0) && (junta[15]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[12]==0) && (junta[13]==1) && (junta[14]==1) && (junta[15]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[12]==0) && (junta[13]==1) && (junta[14]==1) && (junta[15]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[12]==1) && (junta[13]==0) && (junta[14]==0) && (junta[15]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[12]==1) && (junta[13]==0) && (junta[14]==0) && (junta[15]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[12]==1) && (junta[13]==0) && (junta[14]==1) && (junta[15]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[12]==1) && (junta[13]==0) && (junta[14]==1) && (junta[15]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[12]==1) && (junta[13]==1) && (junta[14]==0) && (junta[15]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[12]==1) && (junta[13]==1) && (junta[14]==0) && (junta[15]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[12]==1) && (junta[13]==1) && (junta[14]==1) && (junta[15]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[12]==1) && (junta[13]==1) && (junta[14]==1) && (junta[15]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==4){
						if((junta[16]==0) && (junta[17]==0) && (junta[18]==0) && (junta[19]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[16]==0) && (junta[17]==0) && (junta[18]==0) && (junta[19]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[16]==0) && (junta[17]==0) && (junta[18]==1) && (junta[19]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[16]==0) && (junta[17]==0) && (junta[18]==1) && (junta[19]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[16]==0) && (junta[17]==1) && (junta[18]==0) && (junta[19]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[16]==0) && (junta[17]==1) && (junta[18]==0) && (junta[19]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[16]==0) && (junta[17]==1) && (junta[18]==1) && (junta[19]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[16]==0) && (junta[17]==1) && (junta[18]==1) && (junta[19]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[16]==1) && (junta[17]==0) && (junta[18]==0) && (junta[19]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[16]==1) && (junta[17]==0) && (junta[18]==0) && (junta[19]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[16]==1) && (junta[17]==0) && (junta[18]==1) && (junta[19]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[16]==1) && (junta[17]==0) && (junta[18]==1) && (junta[19]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[16]==1) && (junta[17]==1) && (junta[18]==0) && (junta[19]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[16]==1) && (junta[17]==1) && (junta[18]==0) && (junta[19]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[16]==1) && (junta[17]==1) && (junta[18]==1) && (junta[19]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[16]==1) && (junta[17]==1) && (junta[18]==1) && (junta[19]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==5){
						if((junta[20]==0) && (junta[21]==0) && (junta[22]==0) && (junta[23]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[20]==0) && (junta[21]==0) && (junta[22]==0) && (junta[23]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[20]==0) && (junta[21]==0) && (junta[22]==1) && (junta[23]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[20]==0) && (junta[21]==0) && (junta[22]==1) && (junta[23]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[20]==0) && (junta[21]==1) && (junta[22]==0) && (junta[23]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[20]==0) && (junta[21]==1) && (junta[22]==0) && (junta[23]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[20]==0) && (junta[21]==1) && (junta[22]==1) && (junta[23]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[20]==0) && (junta[21]==1) && (junta[22]==1) && (junta[23]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[20]==1) && (junta[21]==0) && (junta[22]==0) && (junta[23]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[20]==1) && (junta[21]==0) && (junta[22]==0) && (junta[23]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[20]==1) && (junta[21]==0) && (junta[22]==1) && (junta[23]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[20]==1) && (junta[21]==0) && (junta[22]==1) && (junta[23]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[20]==1) && (junta[21]==1) && (junta[22]==0) && (junta[23]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[20]==1) && (junta[21]==1) && (junta[22]==0) && (junta[23]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[20]==1) && (junta[21]==1) && (junta[22]==1) && (junta[23]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[20]==1) && (junta[21]==1) && (junta[22]==1) && (junta[23]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==6){ 
						if((junta[24]==0) && (junta[25]==0) && (junta[26]==0) && (junta[27]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[24]==0) && (junta[25]==0) && (junta[26]==0) && (junta[27]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[24]==0) && (junta[25]==0) && (junta[26]==1) && (junta[27]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[24]==0) && (junta[25]==0) && (junta[26]==1) && (junta[27]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[24]==0) && (junta[25]==1) && (junta[26]==0) && (junta[27]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[24]==0) && (junta[25]==1) && (junta[26]==0) && (junta[27]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[24]==0) && (junta[25]==1) && (junta[26]==1) && (junta[27]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[24]==0) && (junta[25]==1) && (junta[26]==1) && (junta[27]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[24]==1) && (junta[25]==0) && (junta[26]==0) && (junta[27]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[24]==1) && (junta[25]==0) && (junta[26]==0) && (junta[27]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[24]==1) && (junta[25]==0) && (junta[26]==1) && (junta[27]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[24]==1) && (junta[25]==0) && (junta[26]==1) && (junta[27]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[24]==1) && (junta[25]==1) && (junta[26]==0) && (junta[27]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[24]==1) && (junta[25]==1) && (junta[26]==0) && (junta[27]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[24]==1) && (junta[25]==1) && (junta[26]==1) && (junta[27]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[24]==1) && (junta[25]==1) && (junta[26]==1) && (junta[27]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==7){
						if((junta[28]==0) && (junta[29]==0) && (junta[30]==0) && (junta[31]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[28]==0) && (junta[29]==0) && (junta[30]==0) && (junta[31]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[28]==0) && (junta[29]==0) && (junta[30]==1) && (junta[31]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[28]==0) && (junta[29]==0) && (junta[30]==1) && (junta[31]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[28]==0) && (junta[29]==1) && (junta[30]==0) && (junta[31]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[28]==0) && (junta[29]==1) && (junta[30]==0) && (junta[31]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[28]==0) && (junta[29]==1) && (junta[30]==1) && (junta[31]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[28]==0) && (junta[29]==1) && (junta[30]==1) && (junta[31]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[28]==1) && (junta[29]==0) && (junta[30]==0) && (junta[31]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[28]==1) && (junta[29]==0) && (junta[30]==0) && (junta[31]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[28]==1) && (junta[29]==0) && (junta[30]==1) && (junta[31]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[28]==1) && (junta[29]==0) && (junta[30]==1) && (junta[31]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[28]==1) && (junta[29]==1) && (junta[30]==0) && (junta[31]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[28]==1) && (junta[29]==1) && (junta[30]==0) && (junta[31]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[28]==1) && (junta[29]==1) && (junta[30]==1) && (junta[31]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[28]==1) && (junta[29]==1) && (junta[30]==1) && (junta[31]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==8){ 
						if((junta[32]==0) && (junta[33]==0) && (junta[34]==0) && (junta[35]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[32]==0) && (junta[33]==0) && (junta[34]==0) && (junta[35]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[32]==0) && (junta[33]==0) && (junta[34]==1) && (junta[35]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[32]==0) && (junta[33]==0) && (junta[34]==1) && (junta[35]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[32]==0) && (junta[33]==1) && (junta[34]==0) && (junta[35]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[32]==0) && (junta[33]==1) && (junta[34]==0) && (junta[35]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[32]==0) && (junta[33]==1) && (junta[34]==1) && (junta[35]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[32]==0) && (junta[33]==1) && (junta[34]==1) && (junta[35]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[32]==1) && (junta[33]==0) && (junta[34]==0) && (junta[35]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[32]==1) && (junta[33]==0) && (junta[34]==0) && (junta[35]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[32]==1) && (junta[33]==0) && (junta[34]==1) && (junta[35]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[32]==1) && (junta[33]==0) && (junta[34]==1) && (junta[35]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[32]==1) && (junta[33]==1) && (junta[34]==0) && (junta[35]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[32]==1) && (junta[33]==1) && (junta[34]==0) && (junta[35]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[32]==1) && (junta[33]==1) && (junta[34]==1) && (junta[35]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[32]==1) && (junta[33]==1) && (junta[34]==1) && (junta[35]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==9){ // <= a partir daqui mexer nas posições
						if((junta[36]==0) && (junta[37]==0) && (junta[38]==0) && (junta[39]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[36]==0) && (junta[37]==0) && (junta[38]==0) && (junta[39]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[36]==0) && (junta[37]==0) && (junta[38]==1) && (junta[39]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[36]==0) && (junta[37]==0) && (junta[38]==1) && (junta[39]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[36]==0) && (junta[37]==1) && (junta[38]==0) && (junta[39]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[36]==0) && (junta[37]==1) && (junta[38]==0) && (junta[39]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[36]==0) && (junta[37]==1) && (junta[38]==1) && (junta[39]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[36]==0) && (junta[37]==1) && (junta[38]==1) && (junta[39]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[36]==1) && (junta[37]==0) && (junta[38]==0) && (junta[39]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[36]==1) && (junta[37]==0) && (junta[38]==0) && (junta[39]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[36]==1) && (junta[37]==0) && (junta[38]==1) && (junta[39]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[36]==1) && (junta[37]==0) && (junta[38]==1) && (junta[39]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[36]==1) && (junta[37]==1) && (junta[38]==0) && (junta[39]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[36]==1) && (junta[37]==1) && (junta[38]==0) && (junta[39]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[36]==1) && (junta[37]==1) && (junta[38]==1) && (junta[39]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[36]==1) && (junta[37]==1) && (junta[38]==1) && (junta[39]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==10){
						if((junta[40]==0) && (junta[41]==0) && (junta[42]==0) && (junta[43]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[40]==0) && (junta[41]==0) && (junta[42]==0) && (junta[43]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[40]==0) && (junta[41]==0) && (junta[42]==1) && (junta[43]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[40]==0) && (junta[41]==0) && (junta[42]==1) && (junta[43]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[40]==0) && (junta[41]==1) && (junta[42]==0) && (junta[43]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[40]==0) && (junta[41]==1) && (junta[42]==0) && (junta[43]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[40]==0) && (junta[41]==1) && (junta[42]==1) && (junta[43]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[40]==0) && (junta[41]==1) && (junta[42]==1) && (junta[43]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[40]==1) && (junta[41]==0) && (junta[42]==0) && (junta[43]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[40]==1) && (junta[41]==0) && (junta[42]==0) && (junta[43]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[40]==1) && (junta[41]==0) && (junta[42]==1) && (junta[43]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[40]==1) && (junta[41]==0) && (junta[42]==1) && (junta[43]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[40]==1) && (junta[41]==1) && (junta[42]==0) && (junta[43]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[40]==1) && (junta[41]==1) && (junta[42]==0) && (junta[43]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[40]==1) && (junta[41]==1) && (junta[42]==1) && (junta[43]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[40]==1) && (junta[41]==1) && (junta[42]==1) && (junta[43]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==11){
						if((junta[44]==0) && (junta[45]==0) && (junta[46]==0) && (junta[47]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[44]==0) && (junta[45]==0) && (junta[46]==0) && (junta[47]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[44]==0) && (junta[45]==0) && (junta[46]==1) && (junta[47]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[44]==0) && (junta[45]==0) && (junta[46]==1) && (junta[47]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[44]==0) && (junta[45]==1) && (junta[46]==0) && (junta[47]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[44]==0) && (junta[45]==1) && (junta[46]==0) && (junta[47]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[44]==0) && (junta[45]==1) && (junta[46]==1) && (junta[47]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[44]==0) && (junta[45]==1) && (junta[46]==1) && (junta[47]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[44]==1) && (junta[45]==0) && (junta[46]==0) && (junta[47]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[44]==1) && (junta[45]==0) && (junta[46]==0) && (junta[47]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[44]==1) && (junta[45]==0) && (junta[46]==1) && (junta[47]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[44]==1) && (junta[45]==0) && (junta[46]==1) && (junta[47]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[44]==1) && (junta[45]==1) && (junta[46]==0) && (junta[47]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[44]==1) && (junta[45]==1) && (junta[46]==0) && (junta[47]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[44]==1) && (junta[45]==1) && (junta[46]==1) && (junta[47]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[44]==1) && (junta[45]==1) && (junta[46]==1) && (junta[47]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==12){
						if((junta[48]==0) && (junta[49]==0) && (junta[50]==0) && (junta[51]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[48]==0) && (junta[49]==0) && (junta[50]==0) && (junta[51]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[48]==0) && (junta[49]==0) && (junta[50]==1) && (junta[51]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[48]==0) && (junta[49]==0) && (junta[50]==1) && (junta[51]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[48]==0) && (junta[49]==1) && (junta[50]==0) && (junta[51]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[48]==0) && (junta[49]==1) && (junta[50]==0) && (junta[51]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[48]==0) && (junta[49]==1) && (junta[50]==1) && (junta[51]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[48]==0) && (junta[49]==1) && (junta[50]==1) && (junta[51]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[48]==1) && (junta[49]==0) && (junta[50]==0) && (junta[51]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[48]==1) && (junta[49]==0) && (junta[50]==0) && (junta[51]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[48]==1) && (junta[49]==0) && (junta[50]==1) && (junta[51]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[48]==1) && (junta[49]==0) && (junta[50]==1) && (junta[51]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[48]==1) && (junta[49]==1) && (junta[50]==0) && (junta[51]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[48]==1) && (junta[49]==1) && (junta[50]==0) && (junta[51]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[48]==1) && (junta[49]==1) && (junta[50]==1) && (junta[51]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[48]==1) && (junta[49]==1) && (junta[50]==1) && (junta[51]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
					if(i==13){
						if((junta[52]==0) && (junta[53]==0) && (junta[54]==0) && (junta[55]==0)){ // 0 0 0 0 
							senhaCEO[i]='0';
						}
						if((junta[52]==0) && (junta[53]==0) && (junta[54]==0) && (junta[55]==1)){ // 0 0 0 1
							senhaCEO[i]='1';
						}
						if((junta[52]==0) && (junta[53]==0) && (junta[54]==1) && (junta[55]==0)){ // 0 0 1 0
							senhaCEO[i]='2';
						}
						if((junta[52]==0) && (junta[53]==0) && (junta[54]==1) && (junta[55]==1)){ // 0 0 1 1
							senhaCEO[i]='3';
						}
						if((junta[52]==0) && (junta[53]==1) && (junta[54]==0) && (junta[55]==0)){ // 0 1 0 0
							senhaCEO[i]='4';
						}
						if((junta[52]==0) && (junta[53]==1) && (junta[54]==0) && (junta[55]==1)){ // 0 1 0 1 
							senhaCEO[i]='5';
						}
						if((junta[52]==0) && (junta[53]==1) && (junta[54]==1) && (junta[55]==0)){ // 0 1 1 0
							senhaCEO[i]='6';
						}
						if((junta[52]==0) && (junta[53]==1) && (junta[54]==1) && (junta[55]==1)){ // 0 1 1 1
							senhaCEO[i]='7';
						}
						if((junta[52]==1) && (junta[53]==0) && (junta[54]==0) && (junta[55]==0)){ // 1 0 0 0
							senhaCEO[i]='8';
						}
						if((junta[52]==1) && (junta[53]==0) && (junta[54]==0) && (junta[55]==1)){ // 1 0 0 1
							senhaCEO[i]='9';
						}
						if((junta[52]==1) && (junta[53]==0) && (junta[54]==1) && (junta[55]==0)){ // 1 0 1 0
							senhaCEO[i]='A';
						}
						if((junta[52]==1) && (junta[53]==0) && (junta[54]==1) && (junta[55]==1)){ // 1 0 1 1
							senhaCEO[i]='B';
						}
						if((junta[52]==1) && (junta[53]==1) && (junta[54]==0) && (junta[55]==0)){ // 1 1 0 0
							senhaCEO[i]='C';
						}
						if((junta[52]==1) && (junta[53]==1) && (junta[54]==0) && (junta[55]==1)){ // 1 1 0 1
							senhaCEO[i]='D';
						}
						if((junta[52]==1) && (junta[53]==1) && (junta[54]==1) && (junta[55]==0)){ // 1 1 1 0
							senhaCEO[i]='E';
						}
						if((junta[52]==1) && (junta[53]==1) && (junta[54]==1) && (junta[55]==1)){ // 1 1 1 1
							senhaCEO[i]='F';
						}
					}
				}
				for(i=0;i<14;i++){ // sao 14 ( de 0 a 13 ) grupamentos de 4 bits ( senha )
					if(i==0){
						if((Junta[0]==0) && (Junta[1]==0) && (Junta[2]==0) && (Junta[3]==0)){  
							senha_realCEO[i]='0';
						}
						if((Junta[0]==0) && (Junta[1]==0) && (Junta[2]==0) && (Junta[3]==1)){ 
							senha_realCEO[i]='1';
						}
						if((Junta[0]==0) && (Junta[1]==0) && (Junta[2]==1) && (Junta[3]==0)){ 
							senha_realCEO[i]='2';
						}
						if((Junta[0]==0) && (Junta[1]==0) && (Junta[2]==1) && (Junta[3]==1)){ 
							senha_realCEO[i]='3';
						}
						if((Junta[0]==0) && (Junta[1]==1) && (Junta[2]==0) && (Junta[3]==0)){ 
							senha_realCEO[i]='4';
						}
						if((Junta[0]==0) && (Junta[1]==1) && (Junta[2]==0) && (Junta[3]==1)){  
							senha_realCEO[i]='5';
						}
						if((Junta[0]==0) && (Junta[1]==1) && (Junta[2]==1) && (Junta[3]==0)){ 
							senha_realCEO[i]='6';
						}
						if((Junta[0]==0) && (Junta[1]==1) && (Junta[2]==1) && (Junta[3]==1)){ 
							senha_realCEO[i]='7';
						}
						if((Junta[0]==1) && (Junta[1]==0) && (Junta[2]==0) && (Junta[3]==0)){ 
							senha_realCEO[i]='8';
						}
						if((Junta[0]==1) && (Junta[1]==0) && (Junta[2]==0) && (Junta[3]==1)){
							senha_realCEO[i]='9';
						}
						if((Junta[0]==1) && (Junta[1]==0) && (Junta[2]==1) && (Junta[3]==0)){ 
							senha_realCEO[i]='A';
						}
						if((Junta[0]==1) && (Junta[1]==0) && (Junta[2]==1) && (Junta[3]==1)){ 
							senha_realCEO[i]='B';
						}
						if((Junta[0]==1) && (Junta[1]==1) && (Junta[2]==0) && (Junta[3]==0)){ 
							senha_realCEO[i]='C';
						}
						if((Junta[0]==1) && (Junta[1]==1) && (Junta[2]==0) && (Junta[3]==1)){
							senha_realCEO[i]='D';
						}
						if((Junta[0]==1) && (Junta[1]==1) && (Junta[2]==1) && (Junta[3]==0)){ 
							senha_realCEO[i]='E';
						}
						if((Junta[0]==1) && (Junta[1]==1) && (Junta[2]==1) && (Junta[3]==1)){ 
							senha_realCEO[i]='F';
						}
					}
					if(i==1){
						if((Junta[4]==0) && (Junta[5]==0) && (Junta[6]==0) && (Junta[7]==0)){  
							senha_realCEO[i]='0';
						}
						if((Junta[4]==0) && (Junta[5]==0) && (Junta[6]==0) && (Junta[7]==1)){ 
							senha_realCEO[i]='1';
						}
						if((Junta[4]==0) && (Junta[5]==0) && (Junta[6]==1) && (Junta[7]==0)){ 
							senha_realCEO[i]='2';
						}
						if((Junta[4]==0) && (Junta[5]==0) && (Junta[6]==1) && (Junta[7]==1)){ 
							senha_realCEO[i]='3';
						}
						if((Junta[4]==0) && (Junta[5]==1) && (Junta[6]==0) && (Junta[7]==0)){ 
							senha_realCEO[i]='4';
						}
						if((Junta[4]==0) && (Junta[5]==1) && (Junta[6]==0) && (Junta[7]==1)){  
							senha_realCEO[i]='5';
						}
						if((Junta[4]==0) && (Junta[5]==1) && (Junta[6]==1) && (Junta[7]==0)){ 
							senha_realCEO[i]='6';
						}
						if((Junta[4]==0) && (Junta[5]==1) && (Junta[6]==1) && (Junta[7]==1)){ 
							senha_realCEO[i]='7';
						}
						if((Junta[4]==1) && (Junta[5]==0) && (Junta[6]==0) && (Junta[7]==0)){ 
							senha_realCEO[i]='8';
						}
						if((Junta[4]==1) && (Junta[5]==0) && (Junta[6]==0) && (Junta[7]==1)){ 
							senha_realCEO[i]='9';
						}
						if((Junta[4]==1) && (Junta[5]==0) && (Junta[6]==1) && (Junta[7]==0)){ 
							senha_realCEO[i]='A';
						}
						if((Junta[4]==1) && (Junta[5]==0) && (Junta[6]==1) && (Junta[7]==1)){ 
							senha_realCEO[i]='B';
						}
						if((Junta[4]==1) && (Junta[5]==1) && (Junta[6]==0) && (Junta[7]==0)){ 
							senha_realCEO[i]='C';
						}
						if((Junta[4]==1) && (Junta[5]==1) && (Junta[6]==0) && (Junta[7]==1)){ 
							senha_realCEO[i]='D';
						}
						if((Junta[4]==1) && (Junta[5]==1) && (Junta[6]==1) && (Junta[7]==0)){ 
							senha_realCEO[i]='E';
						}
						if((Junta[4]==1) && (Junta[5]==1) && (Junta[6]==1) && (Junta[7]==1)){ 
							senha_realCEO[i]='F';
						}
					}
					if(i==2){
						if((Junta[8]==0) && (Junta[9]==0) && (Junta[10]==0) && (Junta[11]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[8]==0) && (Junta[9]==0) && (Junta[10]==0) && (Junta[11]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[8]==0) && (Junta[9]==0) && (Junta[10]==1) && (Junta[11]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[8]==0) && (Junta[9]==0) && (Junta[10]==1) && (Junta[11]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[8]==0) && (Junta[9]==1) && (Junta[10]==0) && (Junta[11]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[8]==0) && (Junta[9]==1) && (Junta[10]==0) && (Junta[11]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[8]==0) && (Junta[9]==1) && (Junta[10]==1) && (Junta[11]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[8]==0) && (Junta[9]==1) && (Junta[10]==1) && (Junta[11]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[8]==1) && (Junta[9]==0) && (Junta[10]==0) && (Junta[11]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[8]==1) && (Junta[9]==0) && (Junta[10]==0) && (Junta[11]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[8]==1) && (Junta[9]==0) && (Junta[10]==1) && (Junta[11]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[8]==1) && (Junta[9]==0) && (Junta[10]==1) && (Junta[11]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[8]==1) && (Junta[9]==1) && (Junta[10]==0) && (Junta[11]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[8]==1) && (Junta[9]==1) && (Junta[10]==0) && (Junta[11]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[8]==1) && (Junta[9]==1) && (Junta[10]==1) && (Junta[11]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[8]==1) && (Junta[9]==1) && (Junta[10]==1) && (Junta[11]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==3){
						if((Junta[12]==0) && (Junta[13]==0) && (Junta[14]==0) && (Junta[15]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[12]==0) && (Junta[13]==0) && (Junta[14]==0) && (Junta[15]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[12]==0) && (Junta[13]==0) && (Junta[14]==1) && (Junta[15]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[12]==0) && (Junta[13]==0) && (Junta[14]==1) && (Junta[15]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[12]==0) && (Junta[13]==1) && (Junta[14]==0) && (Junta[15]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[12]==0) && (Junta[13]==1) && (Junta[14]==0) && (Junta[15]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[12]==0) && (Junta[13]==1) && (Junta[14]==1) && (Junta[15]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[12]==0) && (Junta[13]==1) && (Junta[14]==1) && (Junta[15]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[12]==1) && (Junta[13]==0) && (Junta[14]==0) && (Junta[15]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[12]==1) && (Junta[13]==0) && (Junta[14]==0) && (Junta[15]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[12]==1) && (Junta[13]==0) && (Junta[14]==1) && (Junta[15]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[12]==1) && (Junta[13]==0) && (Junta[14]==1) && (Junta[15]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[12]==1) && (Junta[13]==1) && (Junta[14]==0) && (Junta[15]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[12]==1) && (Junta[13]==1) && (Junta[14]==0) && (Junta[15]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[12]==1) && (Junta[13]==1) && (Junta[14]==1) && (Junta[15]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[12]==1) && (Junta[13]==1) && (Junta[14]==1) && (Junta[15]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==4){
						if((Junta[16]==0) && (Junta[17]==0) && (Junta[18]==0) && (Junta[19]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[16]==0) && (Junta[17]==0) && (Junta[18]==0) && (Junta[19]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[16]==0) && (Junta[17]==0) && (Junta[18]==1) && (Junta[19]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[16]==0) && (Junta[17]==0) && (Junta[18]==1) && (Junta[19]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[16]==0) && (Junta[17]==1) && (Junta[18]==0) && (Junta[19]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[16]==0) && (Junta[17]==1) && (Junta[18]==0) && (Junta[19]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[16]==0) && (Junta[17]==1) && (Junta[18]==1) && (Junta[19]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[16]==0) && (Junta[17]==1) && (Junta[18]==1) && (Junta[19]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[16]==1) && (Junta[17]==0) && (Junta[18]==0) && (Junta[19]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[16]==1) && (Junta[17]==0) && (Junta[18]==0) && (Junta[19]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[16]==1) && (Junta[17]==0) && (Junta[18]==1) && (Junta[19]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[16]==1) && (Junta[17]==0) && (Junta[18]==1) && (Junta[19]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[16]==1) && (Junta[17]==1) && (Junta[18]==0) && (Junta[19]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[16]==1) && (Junta[17]==1) && (Junta[18]==0) && (Junta[19]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[16]==1) && (Junta[17]==1) && (Junta[18]==1) && (Junta[19]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[16]==1) && (Junta[17]==1) && (Junta[18]==1) && (Junta[19]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==5){
						if((Junta[20]==0) && (Junta[21]==0) && (Junta[22]==0) && (Junta[23]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[20]==0) && (Junta[21]==0) && (Junta[22]==0) && (Junta[23]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[20]==0) && (Junta[21]==0) && (Junta[22]==1) && (Junta[23]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[20]==0) && (Junta[21]==0) && (Junta[22]==1) && (Junta[23]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[20]==0) && (Junta[21]==1) && (Junta[22]==0) && (Junta[23]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[20]==0) && (Junta[21]==1) && (Junta[22]==0) && (Junta[23]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[20]==0) && (Junta[21]==1) && (Junta[22]==1) && (Junta[23]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[20]==0) && (Junta[21]==1) && (Junta[22]==1) && (Junta[23]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[20]==1) && (Junta[21]==0) && (Junta[22]==0) && (Junta[23]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[20]==1) && (Junta[21]==0) && (Junta[22]==0) && (Junta[23]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[20]==1) && (Junta[21]==0) && (Junta[22]==1) && (Junta[23]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[20]==1) && (Junta[21]==0) && (Junta[22]==1) && (Junta[23]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[20]==1) && (Junta[21]==1) && (Junta[22]==0) && (Junta[23]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[20]==1) && (Junta[21]==1) && (Junta[22]==0) && (Junta[23]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[20]==1) && (Junta[21]==1) && (Junta[22]==1) && (Junta[23]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[20]==1) && (Junta[21]==1) && (Junta[22]==1) && (Junta[23]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==6){ 
						if((Junta[24]==0) && (Junta[25]==0) && (Junta[26]==0) && (Junta[27]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[24]==0) && (Junta[25]==0) && (Junta[26]==0) && (Junta[27]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[24]==0) && (Junta[25]==0) && (Junta[26]==1) && (Junta[27]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[24]==0) && (Junta[25]==0) && (Junta[26]==1) && (Junta[27]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[24]==0) && (Junta[25]==1) && (Junta[26]==0) && (Junta[27]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[24]==0) && (Junta[25]==1) && (Junta[26]==0) && (Junta[27]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[24]==0) && (Junta[25]==1) && (Junta[26]==1) && (Junta[27]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[24]==0) && (Junta[25]==1) && (Junta[26]==1) && (Junta[27]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[24]==1) && (Junta[25]==0) && (Junta[26]==0) && (Junta[27]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[24]==1) && (Junta[25]==0) && (Junta[26]==0) && (Junta[27]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[24]==1) && (Junta[25]==0) && (Junta[26]==1) && (Junta[27]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[24]==1) && (Junta[25]==0) && (Junta[26]==1) && (Junta[27]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[24]==1) && (Junta[25]==1) && (Junta[26]==0) && (Junta[27]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[24]==1) && (Junta[25]==1) && (Junta[26]==0) && (Junta[27]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[24]==1) && (Junta[25]==1) && (Junta[26]==1) && (Junta[27]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[24]==1) && (Junta[25]==1) && (Junta[26]==1) && (Junta[27]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==7){
						if((Junta[28]==0) && (Junta[29]==0) && (Junta[30]==0) && (Junta[31]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[28]==0) && (Junta[29]==0) && (Junta[30]==0) && (Junta[31]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[28]==0) && (Junta[29]==0) && (Junta[30]==1) && (Junta[31]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[28]==0) && (Junta[29]==0) && (Junta[30]==1) && (Junta[31]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[28]==0) && (Junta[29]==1) && (Junta[30]==0) && (Junta[31]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[28]==0) && (Junta[29]==1) && (Junta[30]==0) && (Junta[31]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[28]==0) && (Junta[29]==1) && (Junta[30]==1) && (Junta[31]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[28]==0) && (Junta[29]==1) && (Junta[30]==1) && (Junta[31]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[28]==1) && (Junta[29]==0) && (Junta[30]==0) && (Junta[31]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[28]==1) && (Junta[29]==0) && (Junta[30]==0) && (Junta[31]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[28]==1) && (Junta[29]==0) && (Junta[30]==1) && (Junta[31]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[28]==1) && (Junta[29]==0) && (Junta[30]==1) && (Junta[31]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[28]==1) && (Junta[29]==1) && (Junta[30]==0) && (Junta[31]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[28]==1) && (Junta[29]==1) && (Junta[30]==0) && (Junta[31]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[28]==1) && (Junta[29]==1) && (Junta[30]==1) && (Junta[31]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[28]==1) && (Junta[29]==1) && (Junta[30]==1) && (Junta[31]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==8){ 
						if((Junta[32]==0) && (Junta[33]==0) && (Junta[34]==0) && (Junta[35]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[32]==0) && (Junta[33]==0) && (Junta[34]==0) && (Junta[35]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[32]==0) && (Junta[33]==0) && (Junta[34]==1) && (Junta[35]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[32]==0) && (Junta[33]==0) && (Junta[34]==1) && (Junta[35]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[32]==0) && (Junta[33]==1) && (Junta[34]==0) && (Junta[35]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[32]==0) && (Junta[33]==1) && (Junta[34]==0) && (Junta[35]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[32]==0) && (Junta[33]==1) && (Junta[34]==1) && (Junta[35]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[32]==0) && (Junta[33]==1) && (Junta[34]==1) && (Junta[35]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[32]==1) && (Junta[33]==0) && (Junta[34]==0) && (Junta[35]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[32]==1) && (Junta[33]==0) && (Junta[34]==0) && (Junta[35]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[32]==1) && (Junta[33]==0) && (Junta[34]==1) && (Junta[35]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[32]==1) && (Junta[33]==0) && (Junta[34]==1) && (Junta[35]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[32]==1) && (Junta[33]==1) && (Junta[34]==0) && (Junta[35]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[32]==1) && (Junta[33]==1) && (Junta[34]==0) && (Junta[35]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[32]==1) && (Junta[33]==1) && (Junta[34]==1) && (Junta[35]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[32]==1) && (Junta[33]==1) && (Junta[34]==1) && (Junta[35]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==9){ 
						if((Junta[36]==0) && (Junta[37]==0) && (Junta[38]==0) && (Junta[39]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[36]==0) && (Junta[37]==0) && (Junta[38]==0) && (Junta[39]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[36]==0) && (Junta[37]==0) && (Junta[38]==1) && (Junta[39]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[36]==0) && (Junta[37]==0) && (Junta[38]==1) && (Junta[39]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[36]==0) && (Junta[37]==1) && (Junta[38]==0) && (Junta[39]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[36]==0) && (Junta[37]==1) && (Junta[38]==0) && (Junta[39]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[36]==0) && (Junta[37]==1) && (Junta[38]==1) && (Junta[39]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[36]==0) && (Junta[37]==1) && (Junta[38]==1) && (Junta[39]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[36]==1) && (Junta[37]==0) && (Junta[38]==0) && (Junta[39]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[36]==1) && (Junta[37]==0) && (Junta[38]==0) && (Junta[39]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[36]==1) && (Junta[37]==0) && (Junta[38]==1) && (Junta[39]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[36]==1) && (Junta[37]==0) && (Junta[38]==1) && (Junta[39]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[36]==1) && (Junta[37]==1) && (Junta[38]==0) && (Junta[39]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[36]==1) && (Junta[37]==1) && (Junta[38]==0) && (Junta[39]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[36]==1) && (Junta[37]==1) && (Junta[38]==1) && (Junta[39]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[36]==1) && (Junta[37]==1) && (Junta[38]==1) && (Junta[39]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==10){
						if((Junta[40]==0) && (Junta[41]==0) && (Junta[42]==0) && (Junta[43]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[40]==0) && (Junta[41]==0) && (Junta[42]==0) && (Junta[43]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[40]==0) && (Junta[41]==0) && (Junta[42]==1) && (Junta[43]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[40]==0) && (Junta[41]==0) && (Junta[42]==1) && (Junta[43]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[40]==0) && (Junta[41]==1) && (Junta[42]==0) && (Junta[43]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[40]==0) && (Junta[41]==1) && (Junta[42]==0) && (Junta[43]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[40]==0) && (Junta[41]==1) && (Junta[42]==1) && (Junta[43]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[40]==0) && (Junta[41]==1) && (Junta[42]==1) && (Junta[43]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[40]==1) && (Junta[41]==0) && (Junta[42]==0) && (Junta[43]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[40]==1) && (Junta[41]==0) && (Junta[42]==0) && (Junta[43]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[40]==1) && (Junta[41]==0) && (Junta[42]==1) && (Junta[43]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[40]==1) && (Junta[41]==0) && (Junta[42]==1) && (Junta[43]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[40]==1) && (Junta[41]==1) && (Junta[42]==0) && (Junta[43]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[40]==1) && (Junta[41]==1) && (Junta[42]==0) && (Junta[43]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[40]==1) && (Junta[41]==1) && (Junta[42]==1) && (Junta[43]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[40]==1) && (Junta[41]==1) && (Junta[42]==1) && (Junta[43]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==11){
						if((Junta[44]==0) && (Junta[45]==0) && (Junta[46]==0) && (Junta[47]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[44]==0) && (Junta[45]==0) && (Junta[46]==0) && (Junta[47]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[44]==0) && (Junta[45]==0) && (Junta[46]==1) && (Junta[47]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[44]==0) && (Junta[45]==0) && (Junta[46]==1) && (Junta[47]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[44]==0) && (Junta[45]==1) && (Junta[46]==0) && (Junta[47]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[44]==0) && (Junta[45]==1) && (Junta[46]==0) && (Junta[47]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[44]==0) && (Junta[45]==1) && (Junta[46]==1) && (Junta[47]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[44]==0) && (Junta[45]==1) && (Junta[46]==1) && (Junta[47]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[44]==1) && (Junta[45]==0) && (Junta[46]==0) && (Junta[47]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[44]==1) && (Junta[45]==0) && (Junta[46]==0) && (Junta[47]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[44]==1) && (Junta[45]==0) && (Junta[46]==1) && (Junta[47]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[44]==1) && (Junta[45]==0) && (Junta[46]==1) && (Junta[47]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[44]==1) && (Junta[45]==1) && (Junta[46]==0) && (Junta[47]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[44]==1) && (Junta[45]==1) && (Junta[46]==0) && (Junta[47]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[44]==1) && (Junta[45]==1) && (Junta[46]==1) && (Junta[47]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[44]==1) && (Junta[45]==1) && (Junta[46]==1) && (Junta[47]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==12){
						if((Junta[48]==0) && (Junta[49]==0) && (Junta[50]==0) && (Junta[51]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[48]==0) && (Junta[49]==0) && (Junta[50]==0) && (Junta[51]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[48]==0) && (Junta[49]==0) && (Junta[50]==1) && (Junta[51]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[48]==0) && (Junta[49]==0) && (Junta[50]==1) && (Junta[51]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[48]==0) && (Junta[49]==1) && (Junta[50]==0) && (Junta[51]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[48]==0) && (Junta[49]==1) && (Junta[50]==0) && (Junta[51]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[48]==0) && (Junta[49]==1) && (Junta[50]==1) && (Junta[51]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[48]==0) && (Junta[49]==1) && (Junta[50]==1) && (Junta[51]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[48]==1) && (Junta[49]==0) && (Junta[50]==0) && (Junta[51]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[48]==1) && (Junta[49]==0) && (Junta[50]==0) && (Junta[51]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[48]==1) && (Junta[49]==0) && (Junta[50]==1) && (Junta[51]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[48]==1) && (Junta[49]==0) && (Junta[50]==1) && (Junta[51]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[48]==1) && (Junta[49]==1) && (Junta[50]==0) && (Junta[51]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[48]==1) && (Junta[49]==1) && (Junta[50]==0) && (Junta[51]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[48]==1) && (Junta[49]==1) && (Junta[50]==1) && (Junta[51]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[48]==1) && (Junta[49]==1) && (Junta[50]==1) && (Junta[51]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
					if(i==13){
						if((Junta[52]==0) && (Junta[53]==0) && (Junta[54]==0) && (Junta[55]==0)){ // 0 0 0 0 
							senha_realCEO[i]='0';
						}
						if((Junta[52]==0) && (Junta[53]==0) && (Junta[54]==0) && (Junta[55]==1)){ // 0 0 0 1
							senha_realCEO[i]='1';
						}
						if((Junta[52]==0) && (Junta[53]==0) && (Junta[54]==1) && (Junta[55]==0)){ // 0 0 1 0
							senha_realCEO[i]='2';
						}
						if((Junta[52]==0) && (Junta[53]==0) && (Junta[54]==1) && (Junta[55]==1)){ // 0 0 1 1
							senha_realCEO[i]='3';
						}
						if((Junta[52]==0) && (Junta[53]==1) && (Junta[54]==0) && (Junta[55]==0)){ // 0 1 0 0
							senha_realCEO[i]='4';
						}
						if((Junta[52]==0) && (Junta[53]==1) && (Junta[54]==0) && (Junta[55]==1)){ // 0 1 0 1 
							senha_realCEO[i]='5';
						}
						if((Junta[52]==0) && (Junta[53]==1) && (Junta[54]==1) && (Junta[55]==0)){ // 0 1 1 0
							senha_realCEO[i]='6';
						}
						if((Junta[52]==0) && (Junta[53]==1) && (Junta[54]==1) && (Junta[55]==1)){ // 0 1 1 1
							senha_realCEO[i]='7';
						}
						if((Junta[52]==1) && (Junta[53]==0) && (Junta[54]==0) && (Junta[55]==0)){ // 1 0 0 0
							senha_realCEO[i]='8';
						}
						if((Junta[52]==1) && (Junta[53]==0) && (Junta[54]==0) && (Junta[55]==1)){ // 1 0 0 1
							senha_realCEO[i]='9';
						}
						if((Junta[52]==1) && (Junta[53]==0) && (Junta[54]==1) && (Junta[55]==0)){ // 1 0 1 0
							senha_realCEO[i]='A';
						}
						if((Junta[52]==1) && (junta[53]==0) && (Junta[54]==1) && (Junta[55]==1)){ // 1 0 1 1
							senha_realCEO[i]='B';
						}
						if((Junta[52]==1) && (Junta[53]==1) && (Junta[54]==0) && (Junta[55]==0)){ // 1 1 0 0
							senha_realCEO[i]='C';
						}
						if((Junta[52]==1) && (Junta[53]==1) && (Junta[54]==0) && (Junta[55]==1)){ // 1 1 0 1
							senha_realCEO[i]='D';
						}
						if((Junta[52]==1) && (Junta[53]==1) && (Junta[54]==1) && (Junta[55]==0)){ // 1 1 1 0
							senha_realCEO[i]='E';
						}
						if((Junta[52]==1) && (Junta[53]==1) && (Junta[54]==1) && (Junta[55]==1)){ // 1 1 1 1
							senha_realCEO[i]='F';
						}
					}
				}
			
				for(i=0;i<14;i++){ // laco para preencher a lista verifica usuario
					usuario_verifica_hexa.push_back(senhaCEO[i]);
				}
		
				for(i=0;i<14;i++){ // laco para preencher a lista verifica senha
					senha_verifica_hexa.push_back(senha_realCEO[i]);
				}
				cout<<"\n\n";
			}
		}
	}
	
	void autentica_senha_usuario(){
		int verdade;
		for(int i=0;i<6;i++){
			if(i==0){
				
				verifica=usuario_verifica_hexa.begin();
				
				for(conteudo=usuario_original_hexa.begin();conteudo!=usuario_original_hexa.end();conteudo++){
					if(*conteudo==*verifica){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica++;
				}
				if(verdade==1){
					
					ceo_user=true;					
				}else{
				
					ceo_user=false;
				}
	
				verifica2=senha_verifica_hexa.begin();
			
				verdade=0;
				for(conteudo2=senha_original_hexa.begin();conteudo2!=senha_original_hexa.end();conteudo2++){
					if(*conteudo2==*verifica2){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica2++;
				}
				if(verdade==1){
					ceo_senha=true;
				}else{
					ceo_senha=false;
				}
			}
			if(i==1){
				verifica=usuario_verifica_hexa.begin();
				for(cont_proj=usuario_oficial_Projetos_hexa.begin();cont_proj!=usuario_oficial_Projetos_hexa.end();cont_proj++){
					if(*cont_proj==*verifica){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica++;
				}
				if(verdade==1){
					
					projetos_user=true;
					
				}else{
					
					projetos_user=false;
				}
				
				verifica2=senha_verifica_hexa.begin();
				
				verdade=0;
				for(cont_proj2=senha_oficial_Projetos_hexa.begin();cont_proj2!=senha_oficial_Projetos_hexa.end();cont_proj2++){
					if(*cont_proj2==*verifica2){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica2++;
				}
				if(verdade==1){
					
					projetos_senha=true;
					
				}else{
					
					projetos_senha=false;
				}
				if(projetos_user==true && projetos_senha==true){ // condicao que libera o aceeso para modificar os arquivos
					modifica_projetos_proj==true;
					cria_eventos_proj==true;
				}
			}
			if(i==2){
				verifica=usuario_verifica_hexa.begin();
				for(cont_comer=usuario_oficial_Comercial_hexa.begin();cont_comer!=usuario_oficial_Comercial_hexa.end();cont_comer++){
					if(*cont_comer==*verifica){
					verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica++;
				}
				if(verdade==1){
					
					comercial_user=true;
					
				}else{
					
					comercial_user=false;
				}
					
				verifica2=senha_verifica_hexa.begin();
				
				verdade=0;
				for(cont_comer2=senha_oficial_Comercial_hexa.begin();cont_comer2!=senha_oficial_Comercial_hexa.end();cont_comer2++){
					if(*cont_comer2==*verifica2){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica2++;
				}
				if(verdade==1){
					
					comercial_senha=true;
				}else{
					
					comercial_senha=false;
				}
				if(comercial_user==true && comercial_senha==true){
					modifica_projetos_comer==true;
					cria_eventos_comer==true;
				}
			}
			if(i==3){
				verifica=usuario_verifica_hexa.begin();
				for(cont_rh=usuario_oficial_RH_hexa.begin();cont_rh!=usuario_oficial_RH_hexa.end();cont_rh++){
					if(*cont_rh==*verifica){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica++;
				}
				if(verdade==1){
					
					rh_user=true;
				}else{
					
					rh_user=false;
				}
			
				verifica2=senha_verifica_hexa.begin();
				
				verdade=0;
				for(cont_rh2=senha_oficial_RH_hexa.begin();cont_rh2!=senha_oficial_RH_hexa.end();cont_rh2++){
					if(*cont_rh2==*verifica2){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica2++;
				}
				if(verdade==1){
					
					rh_senha=true;
				}else{
					
					rh_senha=false;
				}
				if(rh_user==true && rh_senha==true){
					modifica_projetos_rh==true;
					cria_eventos_rh==true;
					cria_eventos_empresa==true;
				}
			}
			if(i==4){
				verifica=usuario_verifica_hexa.begin();
				for(cont_mark=usuario_oficial_Mark_hexa.begin();cont_mark!=usuario_oficial_Mark_hexa.end();cont_mark++){
					if(*cont_mark==*verifica){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica++;
				}
				if(verdade==1){
					
					mark_user=true;
				}else{
					
					mark_user=false;
				}
					
				verifica2=senha_verifica_hexa.begin();
				
				verdade=0;
				for(cont_mark2=senha_oficial_Mark_hexa.begin();cont_mark2!=senha_oficial_Mark_hexa.end();cont_mark2++){
					if(*cont_mark2==*verifica2){
						verdade=1;
					}else{
						verdade=0;
						break;
					}
					verifica2++;
				}
				if(verdade==1){
					
					mark_senha=true;
				}else{
					
					mark_senha=false;
				}
				if(mark_user==true && mark_senha==true){
					modifica_projetos_mark==true;
					cria_eventos_mark==true;
				}
			}
		}
		if(	ceo_user==ceo_senha==false && projetos_user==projetos_senha==false && comercial_user==comercial_senha==false && 
			rh_user==rh_senha==false &&  mark_user==mark_senha==false){
					
			cout<<"Os valores inseridos não pertencem a nenhum diretor, logo as informações não serão disponibilizadas"<<endl;
			exit(0); // sai do programa
		}
	}
	
	void verifica_entrega(){
			string por;
	        int menu;
	        bool sa = false;
	        
	        HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
	        SetConsoleTextAttribute( h, 5 );
	        cout << "\n\n\t\t\t\t\t\t\t|||| V E R I F I C A D O R   D E   E N T R E G A S ||||" << endl << endl;
	        SetConsoleTextAttribute( h, 7);

	        struct TrieNode *root = getNode(); 
		
	        while(5){
		
			    cout << "\t\t\t\t\t\t\t"<<"Qual diretoria você quer checar os projetos?" << endl << endl;
			    cout << "\t\t\t\t\t\t\t"<<"1 - Projetos." << endl;
			    cout << "\t\t\t\t\t\t\t"<<"2 - Comercial." << endl;
		     	cout << "\t\t\t\t\t\t\t"<<"3 - Recursos Humanos." << endl;
			    cout << "\t\t\t\t\t\t\t"<<"4 - Marketing." << endl;
			    cout << "\t\t\t\t\t\t\t"<<"5 - Sair." << endl;
			    cout << "\t\t\t\t\t\t\t"<<"Qual ação deseja realizar ? " << endl;
			    cin >> menu;
			
			    switch(menu){
				
					case 1 :{
							string projetos[] = {"Graficos"}; 
				            int n = sizeof(projetos)/sizeof(projetos[0]); 
				            
				            struct TrieNode *root = getNode(); 
				            
				            for (int i = 0; i < n; i++) 
					        insert(root, projetos[i]); 
					        
					        cout << "\t\t\t\t\t\t\t"<< "Digite qual projeto quer procurar : "; "Digite qual projeto quer procurar : ";
					        cin >> por;
					        search(root,por)?cout << "\t\t\t\t\t\t\t"<< "Foi entregue !\n"<< endl:
				                 cout << "\t\t\t\t\t\t\t"<< "Não foi entregue !\n"<< endl;
				                 system("pause");
				                 system("CLS");
							break;
						}	
						case 2:{
							string comercial[] = {"redebb","vulnerabilidade_pmdf","desenvolvimento_web"}; 
				            int n1 = sizeof(comercial)/sizeof(comercial[0]); 
				            
				            struct TrieNode *root1 = getNode(); 
				            
				            for (int i = 0; i < n1; i++) 
					        insert(root, comercial[i]); 
					        
					        cout << "\t\t\t\t\t\t\t"<< "Digite qual projeto quer procurar : ";
					        cin >> por;
					        search(root,por)?cout << "\t\t\t\t\t\t\t"<< "Foi entregue !\n"<< endl:
				                 cout << "\t\t\t\t\t\t\t"<< "Não foi entregue !\n"<< endl;
				                 system("pause");
				                 system("CLS");
							break;
						}
						case 3:{
							string rh[] = {"teste2"}; 
				            int n2 = sizeof(rh)/sizeof(rh[0]); 
				            
				            struct TrieNode *root2 = getNode(); 
				            
				            for (int i = 0; i < n2; i++) 
					        insert(root, rh[i]); 
					        
					        cout << "\t\t\t\t\t\t\t"<< "Digite qual projeto quer procurar: ";
					        cin >> por;
					        search(root,por)?cout << "\t\t\t\t\t\t\t"<< "Foi entregue !\n"<< endl:
				                 cout << "\t\t\t\t\t\t\t"<< "Não foi entregue !\n"<< endl;
				                 system("pause");
				                 system("CLS");
							break;
						}	
						case 4:{
							string marketing[] = {"teste3"}; 
				            int n3 = sizeof(marketing)/sizeof(marketing[0]); 
				            
				            struct TrieNode *root3 = getNode(); 
				            
				            for (int i = 0; i < n3; i++) 
					        insert(root, marketing[i]); 
					        
					        cout << "\t\t\t\t\t\t\t"<<"Digite qual projeto quer procurar: ";
					        cin >> por;
					        search(root,por)?cout <<search(root,por)?cout << "\t\t\t\t\t\t\t"<< "Foi entregue !\n"<< endl:
				                 cout << "\t\t\t\t\t\t\t"<< "Foi entregue !\n"<< endl:
				                 cout << "\t\t\t\t\t\t\t"<< "Não foi entregue !\n"<< endl;
				                 system("pause");
				                 system("CLS");
							break;
							}	
						case 5:
							return altera_infos();
						break;			     
				}
		    }
	}
	
	void separa_rendimento(){
		
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE ); 
	
	list <int> func;
	list <int> funclow;
	list <int> funcok;
	list <string> op;
	
	list <int> :: iterator it;
	list <int> :: iterator it2;
	list <int> :: iterator it3;
	list <string> :: iterator ito;
	
	
	func.push_back(3);
	func.push_back(4);
	func.push_back(6);
	func.push_back(7);
	func.push_back(10);
	
	op.push_back("Claudia");
	op.push_back("Alice");
	op.push_back("Paulo");
	op.push_back("Joao");
	op.push_back("Lucio");
	
	
	it = func.begin();
	
	SetConsoleTextAttribute( h, 6 );
	cout << " \n\n\t\t\t\t\t\t\t||||  R E N D I M E N T O   D O S  F U N C I O N A R I O S.   ||||\n\n\n";
	SetConsoleTextAttribute( h, 7 );
	
	for(it; it != func.end(); it++){
		
		if(*it >= 6){
			funcok.push_back(*it);
		}
		else
		funclow.push_back(*it);
	}
	
	for(it = func.begin(),ito = op.begin() ; it != func.end(),ito != op.end();it++,ito++){
		cout << "\t\t\t\t\t\t\t"<< "O funcionario " << *ito << " teve rendimento de nota " << *it << " .\n";
    }
    
    SetConsoleTextAttribute( h, 4 );  
    cout << "\n\t\t\t\t\t\t\tRendimento abaixo da media: ";
	for(it3 = funclow.begin(); it3 != funclow.end();it3++){
	cout << *it3;
    }
    
    SetConsoleTextAttribute( h, 1 );
    cout << "\n\t\t\t\t\t\t\tRendimento acima da media: ";
	for(it2 = funcok.begin(); it2 != funcok.end();it2++){
	cout << *it2;
    }
	
	SetConsoleTextAttribute( h, 7 );
	
	ofstream melhores("best_func.txt",ofstream :: app);
	if(melhores.is_open()){
		melhores << "\t\t\t\t\t\t\t"<< "Funcionarios com rendimento acima da media : ";
		for(it2 = funcok.begin(); it2 != funcok.end();it2++){
	    melhores << *it2;
    }
    melhores.close();
    cout << "\n\n\t\t\t\t\t\t\tLista gravada !";
	}
	
	ofstream abaixo("low_func.txt",ofstream :: app);
	if(abaixo.is_open()){
		abaixo << "\t\t\t\t\t\t\t"<< "Funcionarios com rendimento abaixo da media : ";
		for(it3 = funclow.begin(); it3 != funclow.end();it3++){
	    abaixo << *it3;
    }
    abaixo.close();
    cout << "\n\n\t\t\t\t\t\t\tLista gravada (enviar para diretoria) !";
	}
		
	}
	
	void altera_infos(){
		int opcao;
		bool sb = false;
		string projeto;
		if(ceo_user==true && ceo_senha==true){
			
			while(4){
				cout<<"\t\t\t\t\t\t\t"<<".......... CEO .........."<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"1 - Verificar a entrega dos projetos"<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"2 - Quadro Resumo da Empresa "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"3 - Eventos da Empresa "<<endl; // arquivos dos eventos da empresa 
				cout<<"\t\t\t\t\t\t\t"<<"4 - Encerrar sessão "<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"O que deseja consultar ? ";
				cin>>opcao;
				switch(opcao){
					case 1:{
						verifica_entrega();	
						break;
					}
					case 2:{
						quadro_resumo();	
						break;
					}
					case 3:{
						evento_empresa();
						break;
					}
					case 4:{
						exit(4);
						break;
					}
				}
			}
		}
		if(projetos_user==true && projetos_senha==true){
			
			while(4){
				cout<<"\t\t\t\t\t\t\t"<<".......... Projetos .........."<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"1 - Adicionar Projeto "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"2 - Adicionar Evento "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"3 - Adicionar evento "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"4 - Encerrar sessão "<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"Qual ação deseja realizar ? ";
				cin>>opcao;
				switch(opcao){
					case 1:{
						criar_projeto();
						break;
					}
					case 2:{
						adiciona_evento();
						break;
					}
					case 3:{
						evento_empresa();
						break;
					}
					case 4:{
						exit(4);
						break;
					}
				}
			}
		}
		if(comercial_user==true && comercial_senha==true){
			
			while(3){
				cout<<"\t\t\t\t\t\t\t"<<".......... Comercial .........."<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"1 - Adicionar Contrato "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"2 - Adicionar Evento "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"3 - Encerrar sessão "<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"Qual ação deseja realizar ? ";
				cin>>opcao;
				switch(opcao){
					case 1:{
						criar_projeto();
						break;
					}
					case 2:{
						adiciona_evento();
						break;
					}
					case 3:{
						exit(3);
						break;
					}
				}
			}
		}
		if(rh_user==true && rh_senha==true){
	
			while(3){
				cout<<"\n\n\t\t\t\t\t\t\t"<<"..........Recursos Humanos.........."<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"1 - Adicionar Projeto "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"2 - Adicionar Evento "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"3 - Ver rendimento dos funcionarios "<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"4 - Encerrar sessão "<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"Qual ação deseja realizar ? ";
				cin>>opcao;
				switch(opcao){
					case 1:{
						criar_projeto();
						break;
					}
					case 2:{
						adiciona_evento();
						break;
					}
					case 3:{
						separa_rendimento();
						break;
					}
					case 4:{
						exit(4);
						break;
					}
				}
			}
		}
		if(mark_user==true && mark_senha==true){
		
			
			while(3){
				cout<<"\t\t\t\t\t\t\t"<<".......... Marketing .........."<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"1 - Adicionar Projeto "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"2 - Adicionar Evento "<<endl; 
				cout<<"\t\t\t\t\t\t\t"<<"3 - Encerrar sessão "<<endl;
				cout<<"\t\t\t\t\t\t\t"<<"Qual ação deseja realizar ? ";
				cin>>opcao;
				switch(opcao){
					case 1:{
						criar_projeto();
						break;
					}
					case 2:{
						adiciona_evento();
						break;
					}
					case 3:{
						exit(3);
						break;
					}
				}
			}
		}
	}
	
	void evento_empresa(){ // pertence ao CEO
		cout<<"\n";
		int opcao;
		string info;
		fstream EvEmpresa,EvPrjetos,EvComercial,EvRh,EvMarketing;
		while(3){
			cout<<"\t\t\t\t\t\t\t"<<"Deseja consultar qual tipo de agenda de eventos ? "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"1 - Empresa "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"2 - Diretoria "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"3 - Voltar ao menu anterior "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"Qual ação deseja realizar ? ";
			cin>>opcao;
			switch(opcao){
				case 1:{
					cout<<"\n\n\n";
					EvEmpresa.open("Agenda Empresa.txt", ios::in | ios::app);
					while (getline(EvEmpresa,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvEmpresa.close();
					
					cout<<"\n";
					break;
				}
				case 2:{
					evento_diretoria();
					break;
				}
				case 3:{
					altera_infos();
					break;
				}
			}
		}
	}
	
	void evento_diretoria(){ // pertence ao CEO
		cout<<"\n";
		fstream EvEmpresa,EvProjetos,EvComercial,EvRh,EvMarketing;
		int opcao;
		string info;
		while(6){
			cout<<"\t\t\t\t\t\t\t"<<"Deseja consultar quais eventos ? "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"1 - Projetos "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"2 - Comercial "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"3 - Recursos Humanos "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"4 - Marketing "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"5 - Todas as Diretorias "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"6 - Voltar ao menu inicial "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"7 - Voltar ao menu anterior "<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"Qual ação deseja realizar ? ";
			cin>>opcao;
			switch(opcao){	
				case 1:{
					
					cout<<"\n\n\n";
					EvProjetos.open("Agenda Projetos.txt", ios::in | ios::app);
					while (getline(EvProjetos,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvProjetos.close();
					
					cout<<"\n";	
					break;
				}
				case 2:{
					
					cout<<"\n\n\n";
					EvComercial.open("Agenda Comercial.txt", ios::in | ios::app);
					while (getline(EvComercial,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvComercial.close();
					cout<<"\n";
					break;
				}
				case 3:{
					
					cout<<"\n\n\n";
					EvRh.open("Agenda Recursos Humanos.txt", ios::in | ios::app);
					while (getline(EvRh,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvRh.close();
					cout<<"\n";
					break;
				}
				case 4:{
					
					cout<<"\n\n\n";
					EvMarketing.open("Agenda Marketing.txt", ios::in | ios::app);
					while (getline(EvMarketing,info))
					cout <<"\t\t\t\t\t\t\t"<< info <<"\n";
					EvMarketing.close();
					cout<<"\n";		
					break;
				}
				case 5:{
					
					cout<<"\n\n\n";
					EvProjetos.open("Agenda Projetos.txt", ios::in | ios::app);
					while (getline(EvProjetos,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvProjetos.close();
					cout<<"\n\n";
					
					EvComercial.open("Agenda Comercial.txt", ios::in | ios::app);
					while (getline(EvComercial,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvComercial.close();
					cout<<"\n\n";
					
					EvRh.open("Agenda Recursos Humanos.txt", ios::in | ios::app);
					while (getline(EvRh,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvRh.close();
					cout<<"\n\n";
					
					EvMarketing.open("Agenda Marketing.txt", ios::in | ios::app);
					while (getline(EvMarketing,info))
					cout << "\t\t\t\t\t\t\t" <<info <<"\n";
					EvMarketing.close();
					cout<<"\n\n";
						
					break;
				}
				case 6:{
					
					cout<<"\n";
					system("cls");
					altera_infos();
					
					break;
				}
				case 7:{
					
					cout<<"\n";
					system("cls");
					evento_empresa();
					
					break;
				}
			}
		}
	}
	
	void criar_projeto(){
		
		int tam,dia,mes,ano,dia1,mes1,ano1;
		string projeto,participantes,contratante,contratado,servico;
		float valor;
		
		fstream Projetos_Dir_Projetos,Contratos_Dir_Comercial,Projetos_Dir_RH,Projetos_Dir_Marketing;
		
		if(modifica_projetos_proj==true){ // na autenticação se for o dir de projetos as variáveis ficam true
			
			Projetos_Dir_Projetos.open("Projetos Projetos.txt",ios::in | ios::app);
			cout<<"\t\t\t\t\t\t\t" <<"Insira a quantidade de projetos que serão inseridos : ";
			cin>>tam;
		
			for(int i=0;i<tam;i++){
				
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do projeto : ";
				getline(cin,projeto);
				Projetos_Dir_Projetos<<"Projeto : "<<projeto<<endl;
				
				cout<<"\t\t\t\t\t\t\t" <<"Insira os participantes : ";
				getline(cin,participantes);
				Projetos_Dir_Projetos<<"Integrantes : "<<participantes<<"\n\n\n";
				
				cout<<"\t\t\t\t\t\t\t" <<"Insira a Data de Início : ";
				cin>>dia>>mes>>ano;
				cout<<"\t\t\t\t\t\t\t" <<"Insira a Data da Primeira Prévia : ";
				cin>>dia1>>mes1>>ano1;
				
				Projetos_Dir_Projetos<<"Data de Início : "<<dia<<" / "<<mes<<" / "<<ano<<"\n";
				Projetos_Dir_Projetos<<"Data da Primeira Prévia : "<<dia1<<" / "<<mes1<<" / "<<ano1<<"\n";
			}
						
			Projetos_Dir_Projetos.close();
		}
		if(modifica_projetos_comer==true){
			
			Contratos_Dir_Comercial.open("Contratos Comercial.txt",ios::in | ios::app);
			cout<<"\t\t\t\t\t\t\t" <<"Insira a quantidade de projetos que serão inseridos : ";
			cin>>tam;
		
			for(int i=0;i<tam;i++){
				
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do projeto : ";
				getline(cin,projeto);
				Contratos_Dir_Comercial<<"Projeto : "<<projeto<<endl;
				
				cout<<"\t\t\t\t\t\t\t" <<"Nome do contratante : ";
				getline(cin,contratante);
				Contratos_Dir_Comercial<<"Contratante : "<<contratante<<endl;
				
				cout<<"\t\t\t\t\t\t\t" <<"Funcionário responsável : ";
				getline(cin,participantes);
				Contratos_Dir_Comercial<<"Funcionário responsável : "<<participantes<<endl;
				
				cout<<"\t\t\t\t\t\t\t" <<"Valor do contrato : ";
				cin>>valor;
				Contratos_Dir_Comercial<<"Valor do contrato : "<<valor<<"\n\n\n";
				
			}
						
			Contratos_Dir_Comercial.close();
		}
		if(modifica_projetos_rh==true){ 
			
			Projetos_Dir_RH.open("Projetos Recursos Humanos.txt",ios::in | ios::app);
			cout<<"\t\t\t\t\t\t\t" <<"Insira a quantidade de projetos que serão inseridos : ";
			cin>>tam;
		
			for(int i=0;i<tam;i++){
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do projeto : ";
				getline(cin,projeto);
				Projetos_Dir_RH<<"Projeto : "<<projeto<<endl;
				
				cout<<"\t\t\t\t\t\t\t" <<"Insira os participantes : ";
				getline(cin,participantes);
				Projetos_Dir_RH<<"Integrantes : "<<participantes<<"\n\n\n";
			}
						
			Projetos_Dir_RH.close();
		}
		if(modifica_projetos_mark==true){
			
			Projetos_Dir_Marketing.open("Projetos Marketing.txt",ios::in | ios::app);
			cout<<"\t\t\t\t\t\t\t" <<"Insira a quantidade de projetos que serão inseridos : ";
			cin>>tam;
		
			for(int i=0;i<tam;i++){
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do projeto : ";
				getline(cin,projeto);
				Projetos_Dir_Marketing<<"Projeto : "<<projeto<<endl;
				
				cout<<"\t\t\t\t\t\t\t" <<"Insira os integrantes : ";
				getline(cin,participantes);
				Projetos_Dir_Marketing<<"Integrantes : "<<participantes<<"\n\n\n";
			}
						
			Projetos_Dir_Marketing.close();
		}
	}
	
	void adiciona_evento(){
		
		int nev,convidados,opcao;
		string evento,descricao,palestrantes,local,diretoria,resposta,nome;
		
		fstream EvEmpresa,EvProjetos,EvComercial,EvRh,EvMarketing;
		
		if(cria_eventos_proj==true){
			cout<<"\t\t\t\t\t\t\t" <<"Quantos eventos deseja adicionar : ";
			cin>>nev;
			for(int i=0;i<nev;i++){
				
				EvProjetos.open("Agenda Projetos.txt", ios::in | ios::app);
			
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do evento : ";
				getline(cin,evento);
				EvProjetos<<"Nome do evento : "<<evento<<endl;
					
				cout<<"\t\t\t\t\t\t\t" <<"Insira um breve descrição do evento : ";
				getline(cin,descricao);
				EvProjetos<<"Descrição : "<<descricao<<endl;
						
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome dos palestrantes : ";
				getline(cin,palestrantes);
				EvProjetos<<"Palestrantes : "<<palestrantes<<endl;
						
				cout<<"\t\t\t\t\t\t\t" <<"Insira o local da palestra : ";
				getline(cin,local);
				EvProjetos<<"Local : "<<local<<"\n\n\n";
			}
			EvProjetos.close();	
		}
		if(cria_eventos_comer==true){
			cout<<"\t\t\t\t\t\t\t" <<"Quantos eventos deseja adicionar : ";
			cin>>nev;
			for(int i=0;i<nev;i++){
				
				EvComercial.open("Agenda Comercial.txt", ios::in | ios::app);
			
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do evento : ";
				getline(cin,evento);
				EvComercial<<"Nome do evento : "<<evento<<endl;
					
				cout<<"\t\t\t\t\t\t\t" <<"Insira um breve descrição do evento : ";
				getline(cin,descricao);
				EvComercial<<"Descrição : "<<descricao<<endl;
						
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome dos palestrantes : ";
				getline(cin,palestrantes);
				EvComercial<<"Palestrantes : "<<palestrantes<<endl;
						
				cout<<"\t\t\t\t\t\t\t" <<"Insira o local da palestra : ";
				getline(cin,local);
				EvComercial<<"Local : "<<local<<"\n\n\n";
			}
			EvComercial.close();	
		}
		if(cria_eventos_rh==true && cria_eventos_empresa==true){
			
			while(3){
				cout<<"\t\t\t\t\t\t\t" <<"1 - Evento para Empresa "<<endl;
				cout<<"\t\t\t\t\t\t\t" <<"2 - Evento para Recursos Humanos "<<endl;
				cout<<"\t\t\t\t\t\t\t" <<"3 - Menu anterior "<<endl;
				cout<<"\t\t\t\t\t\t\t" <<"Inserir opção : ";
				cin>>opcao;
				switch(opcao){
					case 1:{
						
						cout<<"\t\t\t\t\t\t\t" <<"O evento que será adicionado necessita de uma lista de convidados ( Sim / Nao ) ? ";
						cin>>resposta;
						
						if(resposta=="Sim"){
			
							EvEmpresa.open("Agenda Empresa.txt", ios::in | ios::app);
							
							cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do evento : ";
							getline(cin,evento);
							EvEmpresa<<"Nome do evento : "<<evento<<endl;
								
							cout<<"\t\t\t\t\t\t\t" <<"Insira um breve descrição do evento : ";
							getline(cin,descricao);
							EvEmpresa<<"Descrição : "<<descricao<<endl;
									
							cout<<"\t\t\t\t\t\t\t" <<"Insira o nome dos palestrantes : ";
							getline(cin,palestrantes);
							EvEmpresa<<"Palestrantes : "<<palestrantes<<endl;
									
							cout<<"\t\t\t\t\t\t\t" <<"Insira o local da palestra : ";
							getline(cin,local);
							EvEmpresa<<"Local : "<<local<<endl;
									
							cout<<"\t\t\t\t\t\t\t" <<"Insira o número de convidados : ";
							cin>>convidados;
							EvEmpresa<<"Número de convidados : "<<convidados<<"\n";
							
							for(int i=0;i<convidados;i++){
								
								cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do convidado "<<i+1<<" : ";
								getline(cin,nome);
								convidados_eventos.push(nome); // armazena em uma pilha
								
							}
							for(int i=0;i<convidados;i++){ // joga da pliha para o arquivo
								
								EvEmpresa<<i+1<<". "<<convidados_eventos.top()<<"\n";
								convidados_eventos.pop();
								
							}
							
							EvEmpresa.close();
						}
						if(resposta=="Nao"){
							
							EvEmpresa.open("Agenda Empresa.txt", ios::in | ios::app);
							
							cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do evento : ";
							getline(cin,evento);
							EvEmpresa<<"Nome do evento : "<<evento<<endl;
								
							cout<<"\t\t\t\t\t\t\t" <<"Insira um breve descrição do evento : ";
							getline(cin,descricao);
							EvEmpresa<<"Descrição : "<<descricao<<endl;
									
							cout<<"\t\t\t\t\t\t\t" <<"Insira o nome dos palestrantes : ";
							getline(cin,palestrantes);
							EvEmpresa<<"Palestrantes : "<<palestrantes<<endl;
									
							cout<<"\t\t\t\t\t\t\t" <<"Insira o local da palestra : ";
							getline(cin,local);
							EvEmpresa<<"Local : "<<local<<"\n\n";
						}
						break;
					}
					case 2:{
						
						cout<<"\t\t\t\t\t\t\t" <<"Quantos eventos deseja adicionar : ";
						cin>>nev;
						for(int i=0;i<nev;i++){
							
							EvRh.open("Agenda Comercial.txt", ios::in | ios::app);
						
							cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do evento : ";
							getline(cin,evento);
							EvRh<<"Nome do evento : "<<evento<<endl;
								
							cout<<"\t\t\t\t\t\t\t" <<"Insira um breve descricao do evento : ";
							getline(cin,descricao);
							EvRh<<"Descrição : "<<descricao<<endl;
									
							cout<<"\t\t\t\t\t\t\t" <<"Insira o nome dos palestrantes : ";
							getline(cin,palestrantes);
							EvRh<<"Palestrantes : "<<palestrantes<<endl;
									
							cout<<"\t\t\t\t\t\t\t" <<"Insira o local da palestra : ";
							getline(cin,local);
							EvRh<<"Local : "<<local<<"\n\n";
						}
						EvComercial.close();	
						
						break;
					}
					case 3:{
							altera_infos();	
						break;
					}
				}
			}
		}
		if(cria_eventos_mark==true){
			cout<<"\t\t\t\t\t\t\t" <<"Quantos eventos deseja adicionar : ";
			cin>>nev;
			for(int i=0;i<nev;i++){
				
				EvMarketing.open("Agenda Marketing.txt", ios::in | ios::app);
			
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome do evento : ";
				getline(cin,evento);
				EvMarketing<<"Nome do evento : "<<evento<<endl;
					
				cout<<"\t\t\t\t\t\t\t" <<"Insira um breve descrição do evento : ";
				getline(cin,descricao);
				EvMarketing<<"Descrição : "<<descricao<<endl;
						
				cout<<"\t\t\t\t\t\t\t" <<"Insira o nome dos palestrantes : ";
				getline(cin,palestrantes);
				EvMarketing<<"Palestrantes : "<<palestrantes<<endl;
						
				cout<<"\t\t\t\t\t\t\t" <<"Insira o local da palestra : ";
				getline(cin,local);
				EvMarketing<<"Local : "<<local<<"\n\n";
			}
			EvMarketing.close();	
		}	
	}
	
	void quadro_resumo(){
		int opcao;
		while(5){
			cout<<"\n";
			cout<<"\t\t\t\t\t\t\t"<<"........... Quadro Resumo .........."<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"1 - Projetos Dir Projetos"<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"2 - Projetos Dir Comercial"<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"3 - Projetos Dir Rh"<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"4 - Projetos Dir Marketing"<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"5 - Voltar ao menu inicial"<<endl;
			cout<<"\t\t\t\t\t\t\t"<<"Qual ação deseja relaizar ? ";
			cin>>opcao;
			switch(opcao){
				case 1:{
					
					while(!projetos_proj.empty() && !funcionarios_proj.empty()){
						cout<<"\n";
						cout<<"\t\t\t\t\t\t\t"<<"Projeto : "<<projetos_proj.front()<<endl;
						cout<<"\t\t\t\t\t\t\t"<<"Funcionario responsavel : "<<funcionarios_proj.front()<<"\n\n";
						projetos_proj.pop();
						funcionarios_proj.pop();
					}
					break;
				}
				case 2:{
					
					while(!contratos_comer.empty() && !funcionarios_comer.empty()){
						cout<<"\n";
						cout<<"\t\t\t\t\t\t\t"<<"Projeto : "<<contratos_comer.front()<<endl;
						cout<<"\t\t\t\t\t\t\t"<<"Funcionario responsavel : "<<funcionarios_comer.front()<<"\n\n";
						contratos_comer.pop();
						funcionarios_comer.pop();
					}	
					break;
				}
				case 3:{
					
					while(!projetos_rh.empty() && !funcionarios_rh.empty()){
						cout<<"\n";
						cout<<"\t\t\t\t\t\t\t"<<"Projeto : "<<projetos_rh.front()<<endl;
						cout<<"\t\t\t\t\t\t\t"<<"Funcionario responsavel : "<<funcionarios_rh.front()<<"\n\n";
						projetos_rh.pop();
						funcionarios_rh.pop();
					}
					break;
				}
				case 4:{
					
					while(!projetos_mark.empty() && !funcionarios_mark.empty()){
						cout<<"\n";
						cout<<"\t\t\t\t\t\t\t"<<"Projeto : "<<projetos_mark.front()<<endl;
						cout<<"\t\t\t\t\t\t\t"<<"Funcionario responsavel : "<<funcionarios_mark.front()<<"\n\n";
						projetos_mark.pop();
						funcionarios_mark.pop();
					}
					break;
				}
				case 5:{
					cout<<"\n";
					
					altera_infos();				
					break;
				}
			}
		}
	}
};
int main(){
	setlocale(LC_ALL,"Portuguese");
	Login login;
	
	login.cria_arquivos();
	login.preenche_banco_de_dados();
	login.faz_login();
	login.autentica_senha_usuario();
	login.altera_infos();
	
	return 0;
}

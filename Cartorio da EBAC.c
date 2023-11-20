#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro()
{
	char arquivo[40]; // Variável char + o número de string a ser inseridos; string são conjuntos de variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a Ser Cadastrado: ");
	scanf("%s", cpf); // scanf= procura os arquivos da biblioteca; %s para o recebimento da string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a Ser Cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a Ser Cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a Ser Cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a Ser Consultado: ");
	scanf("%s",cpf);
  	
	FILE *file; // Procurando o arquivo na biblioteca
	file = fopen(cpf,"r"); //Função de abrir o arquivo e ler (r = "read")
  	
	if(file == NULL) //Função se o sistema não achar o arquivo
	{
	printf("Não Foi Possivel Localizar o Arquivo!.\n");
	}	
	
	while(fgets(conteudo, 100, file) != NULL)
	{
	printf("\n Essas São as Informações do Usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
  	
	system ("pause");
}

int deletar()
{
	printf("Você Escolheu Deletar Nomes!\n");
	system("pause");	
}


	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a Opção Desejada do Menu:\n\n");
		printf("\t1 - Registrar Momes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa Opção Não Está Disponível!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}

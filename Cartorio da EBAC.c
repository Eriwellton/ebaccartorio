#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro()
{
	char arquivo[40]; // Vari�vel char + o n�mero de string a ser inseridos; string s�o conjuntos de vari�veis
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
	file = fopen(cpf,"r"); //Fun��o de abrir o arquivo e ler (r = "read")
  	
	if(file == NULL) //Fun��o se o sistema n�o achar o arquivo
	{
	printf("N�o Foi Possivel Localizar o Arquivo!.\n");
	}	
	
	while(fgets(conteudo, 100, file) != NULL)
	{
	printf("\n Essas S�o as Informa��es do Usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
  	
	system ("pause");
}

int deletar()
{
	printf("Voc� Escolheu Deletar Nomes!\n");
	system("pause");	
}


	
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a Op��o Desejada do Menu:\n\n");
		printf("\t1 - Registrar Momes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Op��o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls");
	
		switch(opcao) //inicio da sele��o
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
			printf("Essa Op��o N�o Est� Dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
			
	}	
}

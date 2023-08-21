#include <stdio.h> //biblioteca de comunicaçao com o usuário
#include <stdlib.h> //biblioteca de alocaçao de espaço em memoria
#include <locale.h> //biblioteca de alocaçao de texto por regial
#include <string.h> //biblioteca responsal por cuidar das string


int registar() //Responsavel responsalvel por cadastrar no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo idioma
	
	//inicio da criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
    //fim da criação de variaveis

	printf("Digite o cpf a ser cadastrado: "); //Coletando as informaçoes do usuario
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo, "w" de write(escrever)
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF informado não foi localizado! \n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nInformações do Usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usuário não foi encontrado no Sistema!\n");
		system("pause");
	}
	
	
}


int main()
{
	int opcao=0;//Definindo as Variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	   system("cls"); //Responsavel por limpar a tela
	   
	   setlocale(LC_ALL,"Portuguese" );//Definindo a Linguagem
    	
	   printf("### Cartório da EBAC ###\n\n");//Inicio do Menu
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar Nomes\n");
  	   printf("\t2 - Consultar Nomes\n");
       printf("\t3 - Deletar Nomes\n\n");
	   printf("Opçoes:");//Fim do menu
	
	   scanf("%d", &opcao);//Armazenando a escolha do Usuario
	
	   system("cls");
	   
	   switch(opcao)
	   {
	   	
		case 1:
	    registar(); //chama as funçoes
		break;
		
		case 2:
		consultar();
	   	break;
	   	
	   	case 3:
	   	deletar();
		break;
		
		default:
		printf("Essa opção não está disponivel!\n");
	    system("pause");
	    break;
	    
	   }
    }
   
}

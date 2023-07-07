#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void gerarSenha(int tamanho, int letras, int numeros, int especiais)
{
	srand(time(NULL));
		
	//definir quais sao os caracteres presentes
	const char letrasMaiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char letrasMinusculas[] = "abcdefghijklmnopqrstuvwxyz";
	const char numerosString[] = "0123456789";
	const char caracteresEspeciais[] = "!@#$%^&*()_+{}[]<>?";
	
	//definir qual o tamanho de cada variavel com base em seus caracteres presentes
	int tamanhoLetrasMaiusculas = strlen(letrasMaiusculas);
	int tamanhoLetrasMinusculas = strlen(letrasMinusculas);
	int tamanhoNumeros = strlen(numerosString);
	int tamanhoEspeciais = strlen(caracteresEspeciais);
	
	
	//caso todas as opcoes do usuario sejam 0, ira simplesmente mandar essa mensagem
	if(letras + numeros + especiais == 0)
	{
		printf("Escolha uma das alternativas");
	}
	
	//irá criar um ponteiro da variável senha, que ficará alocada na memória
	char* senha = (char*)malloc((tamanho+1) * sizeof(char));
	
	int i;
	
	//inicia um loop onde se I for menor que o tamanho da string, adicionará algo
	for(i = 0; i < tamanho; i++)
	{
		//escolherá um valor aleatório entre letras, numeros e especiais
		//nessa soma, caso pegue 0 ou 1, sera uma letra, caso seja 2 a 4 sera um numero, caso contrario, um caracter especial
		int opcao = rand() % (letras + numeros + especiais);
		
		if(opcao < letras)
		{
			//int indice será um placeholder, apenas para segurar um valor 
			//então tera atribuido algum valor aleatorio vindo das letras
			//que estará vindo com base numa casa aleatoria do tamanho do array
			int indice = rand() % tamanhoLetrasMinusculas;
			
			//entao será atribuido a letra que está nesta casa alaeatoria da variavel
			senha[i] = letrasMinusculas[indice];
		}
		else if(opcao < letras + numeros)
		{
			int indice = rand() % tamanhoNumeros;
			senha[i] = numerosString[indice];
		}
		else
		{
			int indice = rand() % tamanhoEspeciais;
			senha[i] = caracteresEspeciais[indice];
		}
	}
	
	//\0 necessário, para determinar o fim da string senha
	senha[tamanho] = '\0';
	
	printf("Sua senha sera: %s\n\n", senha);
	
	//libera o espaço alocado na memoria pela variavel senha
	free(senha);
}

int main(void)
{
	int tamanho, letras, numeros, especiais;
	
	//um do while apenas para caso o usuario digite algum valor invalido, ter de refazer as alternativas	
	do{		
	
		printf("Digite o tamanho da senha: ");
		scanf("%d", &tamanho);
		
		printf("Voce deseja que tenham letras?\n1- Sim\t0- Nao\nResposta: ");
		scanf("%d", &letras);
		
		printf("Voce deseja que tenham numeros?\n1- Sim\t0- Nao\nResposta: ");
		scanf("%d", &numeros);
		
		printf("Voce deseja que tenham caracteres especiais?\n1- Sim\t0- Nao\nResposta: ");
		scanf("%d", &especiais);
		
		gerarSenha(tamanho, letras, numeros, especiais);
		printf("\n\n");
	}while(tamanho <= 0 || letras < 0 || letras > 1 || numeros < 0 || numeros > 1 || especiais < 0 || especiais > 1);
	
	system("Pause");
	return 0;
		
}

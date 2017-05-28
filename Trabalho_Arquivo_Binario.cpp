#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

FILE *arquivo;

typedef struct Contato {
	char nome[50];
	char telefone[15];
	int idade;
};

///////////////////////////////////////////////////////////////////////


//Pesquisa o contato no arquivo pelo nome e retorna TRUE se for encontrado; retorna tambem o CONTATO_PESQUISADO e a POSICAO dele no arquivo
//Note que CONTATO_PESQUISADO e POSICAO estao sendo passados por referencia

bool pesquisar_registro(char nome[50], Contato* contato_pesquisado, fpos_t* posicao) {
	Contato contato_pesquisa;
	
	//Tenta abrir o arquivo para leitura de dados binarios
	if ((arquivo = fopen("arquivo4.dat", "rb")) == NULL) {
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	
	//Pega a posicao atual da stream de dados e armazena em POSICAO
	//Lê o primeiro contato do arquivo e arzamena em CONTATO_PESQUISA
	fgetpos(arquivo, posicao);
	fread(&contato_pesquisa, sizeof(Contato), 1, arquivo);
	
	//Loop que vai executando enquanto nao chegar no fim do arquivo
	while(!feof(arquivo)) {
		//Como estamos comparando os nomes, se o nome de CONTATO_PESQUISA for igual ao NOME, 
		//CONTATO_PESQUISADO recebe o CONTATO_PESQUISA, fecha o arquivo e retorna TRUE
		//Usei STRCMPI para comparar nao importanto letras maiusculas e minusculas
		if (strcmpi(contato_pesquisa.nome, nome) == 0) {
			*contato_pesquisado = contato_pesquisa;
			fclose(arquivo);
			return true;
		}
		
		//Caso os nomes nao sejam iguais, pega a posicao atual da stream de dados e lê o proximo contato do arquivo
		fgetpos(arquivo, posicao);
		fread(&contato_pesquisa, sizeof(Contato), 1, arquivo);
	}
	
	//Se chegou neste ponto, eh pq nao foi encontrado nenhum contato com o nome equivalente
	//Entao fechamos o arquivo e retornamos FALSE
	fclose(arquivo);
	
	return false;
}


//////////////////////////////////////////////////////////////////////////



//Insere o contato no arquivo
                      //Registro contato;
bool inserir_registro(Contato contato) {
	Contato contato_aux; //CONTATO_AUX e POSICAO_AUX serao usados apenas para armazenar os valores vindo da funcao PESQUISAR_REGISTRO
	fpos_t posicao_aux; //Para armazenar a posicao atual da stream de dados no arquivo, usamos o tipo FPOS_T
	
	//Estamos assumindo que nao deve possuir dois contatos com mesmo nome no arquivo,
	//entao precisamos verificar primeiro se o nome deste contato ja existe nos contatos do arquivo
	if (pesquisar_registro(contato.nome, &contato_aux, &posicao_aux)) {
		//Se ja existir um contato com o mesmo nome, retorna FALSE
		return false;
	}
	
	//Tenta abrir o arquivo para anexacao (append) de dados binarios
	if ((arquivo = fopen("arquivo4.dat", "ab")) == NULL) {
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	
	//Se chegou neste ponto, eh pq nao foi encontrado nenhum contato com o mesmo nome,
	//entao escrevemos o contato no arquivo, fechamos e retornamos TRUE
	fwrite(&contato, sizeof(Contato), 1, arquivo);
	fclose(arquivo);
	
	return true;
}

/////////////////////////////////////////////////////////////////////////////

//Procura o contato no arquivo e, caso encontre, substitui ele pelo outro contato passado por parametro
bool alterar_registro(char nome[50], Contato contato) {
	Contato contato_pesquisado, contato_aux;
	fpos_t posicao, posicao_aux;
	
	//Precisamos verificar se existe um contato com este nome para que possamos alterar o registro dele
	//Verifica tambem se existe um contato com este nome E se este contato eh diferente do nome que iremos alterar. Se for, retorna FALSE
	if(!pesquisar_registro(nome, &contato_pesquisado, &posicao)) {
		//Se nao existir um contato com o mesmo nome, retorna FALSE
		return false;
	} else if (pesquisar_registro(contato.nome, &contato_aux, &posicao_aux) && strcmpi(contato.nome, nome) != 0) {
		return false;
	}
	
	//Tenta abrir o arquivo para leitura/atualizacao de dados binarios
	if ((arquivo = fopen("arquivo4.dat", "r+b")) == NULL) {
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	
	//Posiciona o "cursor" do stream de dados para a posicao que se encontra o contato que queremos alterar
	//Inserimos o novo contato por cima do contato antigo, alterando os dados
	fseek(arquivo, posicao, SEEK_SET);
	fwrite(&contato, sizeof(Contato), 1, arquivo);
	
	printf("\n======Contato antigo======\n");
	printf("Nome: %s\nTelefone: %s\nIdade: %d\n\n", contato_pesquisado.nome, contato_pesquisado.telefone, contato_pesquisado.idade);
	
	printf("======Contato alterado======\n");
	printf("Nome: %s\nTelefone: %s\nIdade: %d", contato.nome, contato.telefone, contato.idade);
	
	fclose(arquivo);
	
	return true;
}


////////////////////////////////////////////////////////////////////////

//Procura o contato no arquivo e, caso encontre, exclui ele
//Nao existe funcao para excluir dados, entao uma das formas eh transferir os dados do arquivo (exceto o registro que vc quer excluir) para
//outro arquivo temporario, deletar o atual e renomear o temporario para o nome do deletado
bool excluir_registro(char nome[50]) {
	Contato contato_pesquisa, contato_aux;
	fpos_t posicao;
	FILE* temp;
	
	//Precisamos verificar se existe um contato com este nome para que possamos excluir o registro dele
	if (!pesquisar_registro(nome, &contato_aux, &posicao)) {
		//Se nao existir um contato com o mesmo nome, retorna FALSE
		return false;
	}
	
	//Tenta abrir o arquivo para leitura de dados binarios
	if ((arquivo = fopen("arquivo4.dat", "rb")) == NULL) {
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	
	//Tenta abrir o arquivo temporario para anexação (append) de dados binarios
	if ((temp = fopen("temp.dat", "ab")) == NULL) {
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	
	//Lê o primeiro contato do arquivo e arzamena em CONTATO_PESQUISA
	fread(&contato_pesquisa, sizeof(Contato), 1, arquivo);
	
	//Loop que vai executando enquanto nao chegar no fim do arquivo
	while(!feof(arquivo)) {
		//Como estamos transferindo os dados exceto o registro que queremos excluir, o IF so vai executar
		//se o nome NAO corresponder ao que queremos excluir
		if (strcmpi(contato_pesquisa.nome, nome) != 0) {
			//Escreve o contato no arquivo temporario
			fwrite(&contato_pesquisa, sizeof(Contato), 1, temp);
		}
		
		//Lê o proximo contato do arquivo
		fread(&contato_pesquisa, sizeof(Contato), 1, arquivo);
	}
	
	fclose(arquivo);
	fclose(temp);
	
	//Iremos remover o arquivo atual e renomear o temporario para o nome do atual
	if (remove("arquivo4.dat") != 0) {
		printf("Erro ao remover arquivo!");
		exit(1);
	} else if (rename("temp.dat", "arquivo4.dat") != 0) {
		printf("Erro ao renomear arquivo!");
		exit(1);
	}
	
	return true;
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

int main() {
	char nome[50];
	Contato contato, contato_pesquisado;
	int opcao;
	fpos_t posicao_aux;
	
	//Caso nao existe nenhum arquivo, criará um para a manipulacao de dados
	//Caso ja exista, so abre o arquivo e fecha em seguida
	if ((arquivo = fopen("arquivo4.dat", "ab")) == NULL) {
		printf("Erro ao abrir arquivo!");
		exit(1);
	}
	fclose(arquivo);
	
	printf("Opcoes\n1.Inserir\n2.Pesquisar\n3.Alterar\n4.Excluir\n5.Sair\n\nEscolha: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	switch (opcao) {
		case 1:
			printf("Insira o nome do Contato: ");
			gets(contato.nome);
			
			printf("Insira o telefone do Contato: ");
			gets(contato.telefone);
			
			printf("Insira a idade do Contato: ");
			scanf("%d", &contato.idade);
			
			//Se a insercao de registro retornar FALSE
			if(!inserir_registro(contato)) {
				printf("Ja existe um contato com este nome!");
			} else {
				printf("Contato cadastrado com sucesso!");
			}
			break;
		case 2:
			printf("Insira o nome do Contato: ");
			gets(nome);
			
			//Ao mesmo tempo que o IF verifica o retorna da funcao, ela executa a funcao e ja me fornece os resultados
			if (pesquisar_registro(nome, &contato_pesquisado, &posicao_aux)) {
				printf("\n======Contato encontrado======\n");
				printf("Nome: %s\nTelefone: %s\nIdade: %d", contato_pesquisado.nome, contato_pesquisado.telefone, contato_pesquisado.idade);
			} else {
				printf("Nao foi encontrado nenhum contato com este nome!");
			}
			break;
		case 3:
			printf("Insira o nome do Contato a ser alterado: ");
			gets(nome);
			
			//Caso exista um registro com este nome para que possamos alterar
			if (pesquisar_registro(nome, &contato_pesquisado, &posicao_aux)) {
				printf("Insira o novo nome do Contato: ");
				gets(contato.nome);
				
				printf("Insira o novo telefone do Contato: ");
				gets(contato.telefone);
				
				printf("Insira a nova idade do Contato: ");
				scanf("%d", &contato.idade);
				
				if (!alterar_registro(nome, contato)) {
					printf("Ja existe um contato com este nome!");
				}
			} else {
				printf("Nao foi encontrado nenhum contato com este nome!");
			}
			break;
		case 4:
			printf("Insira o nome do Contato a ser excluido: ");
			gets(nome);
			
			//Caso exista um registro com este nome para que possamos excluir
			if (pesquisar_registro(nome, &contato_pesquisado, &posicao_aux)) {
				if (excluir_registro(nome)) {
					printf("Contato excluido com sucesso!");
				}
			} else {
				printf("Nao foi encontrado nenhum contato com este nome!");
			}
			break;
		case 5:
			break;
	}
	
	getch();
}

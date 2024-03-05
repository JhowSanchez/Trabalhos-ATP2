//------------------------------------------------------------------------------
//        ALUNOS
//GERSON LUCAS DA SILVA ABREU
//262228130
//JONATHAN WESLEY SANCHEZ DE ANGELIS
//262227665
//------------------------------------------------------------------------------

#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

//tamanho alunos
#define TFA 10
//tamanho disciplina
#define TFD 5
//tamanho nota
#define TFN 50

//tamanho string ra
#define TFra 10
//tamanho string nome
#define TFnome 41
//tamanho string cod
#define TFcod 4
//------------------------------------------------------------------------------
//STRUCTs
struct alunos
{
	char ra[TFra], nome[TFnome];
};

struct disciplinas
{
	char nome[TFnome], cod[TFcod];
};

struct notas
{
	char ra[TFra], cod[TFcod];
	float nota;
};
// -----------------------------------------------------------------------------
//PROTOTIPOS
void inserir(alunos alun[TFA], int &TLA, disciplinas disc[TFD], int &TLD, notas nota[TFN], int &TLN);

void menu(int &pos);
void menu2(int &pos);

void moldura(void);
void apagartela(void);
void apagarmenu(void);
void apagarbotao(void);
void apagarlinha(int y);
void apagar(void);
void linha(int y);

void exibAlun(alunos alun[TFA], int TLA);
void exibDisc(disciplinas disc[TFD], int TLD);
void exibNota(notas nota[TFN], int TLN);

int buscaRa (alunos alun[TFA], int TLA, char aux[TFra]);
int buscaCod (disciplinas disc[TFD], int TLD,char cod[TFcod]);
int buscaRaNota (notas nota[TFN],int TLN, char aux[TFra], int i);
int buscaCodNota (notas nota[TFN],int TLN, char aux[TFcod], int i);

void cadAlun(alunos alun[TFA], int &TLA);
void cadDisc(disciplinas disc[TFD], int &TLD);
void cadNota (notas nota[TFN], int &TLN, alunos alun[TFA],int TLA, disciplinas disc[TFD],int TLD);

void altAlun(alunos alun[TFA], int TLA);
void altDisc(disciplinas disc[TFD], int TLD);
void altNota(notas nota[TFN], int TLN, alunos alun[TFA],int TLA, disciplinas disc[TFD],int TLD);

void excluirRa(alunos alun[TFA], int &TLA, notas nota[TFN], int &TLN);
void excluirCod(disciplinas disc[TFD], int &TLD, notas nota[TFN], int &TLN);
void excluirNota(notas nota[TFN], int &TLN, alunos alun[TFA], int TLA,disciplinas disc[TFD], int TLD);

void exibRela(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN, int pos, int &y);
void exibRelaDisc(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN, int pos, int &y);

void repr(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN);
void discRepr(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN);
void exibLetra(notas nota[TFN], int TLN,alunos alun[TFA], int TLA,disciplinas disc[TFD], int TLD, char aux);
void consAlun(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN);
void consDisc(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN);
void consNota(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN);

void todos(alunos alun[TFA],int TLA, disciplinas disc[TFD],int TLD, notas nota[TFN], int TLN);
void ordAlun(alunos alun[TFA], int TLA);
void ordDisc(disciplinas disc[TFD], int TLD);
void ordNota(notas nota[TFN], int TLN, alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD);
// -----------------------------------------------------------------------------
//PRINCIPAL
int main (void)
{
	alunos alun[TFA];
	disciplinas disc[TFD];
	notas nota[TFN];
	int pos=0, pos2=0;
	char inicial;
	int TLA=0, TLD=0, TLN=0, x=6, y=5;
	moldura();
	
	do
	{
		apagar();
		menu(pos);
		switch (pos)
		{
			//CADASTRAR
			case 0:
				do
				{
					apagar();
					textcolor(15);
					gotoxy(6,3);
					printf("Menu - Cadastrar >");
					menu2(pos2);
					switch(pos2)
					{
						case 0:
							cadAlun(alun,TLA); //OK
							ordAlun(alun,TLA);
							break;
						case 1:
							cadDisc(disc,TLD); //OK
							ordDisc(disc,TLD);
							break;
						case 2:
							cadNota(nota,TLN,alun,TLA,disc,TLD); //OK
							ordNota(nota,TLN,alun,TLA,disc,TLD);
					}
				}while(pos2!=9);
				pos2 = 0;
				break;
			//ALTERAR
			case 1:
				do
				{
					apagar();
					textcolor(2);
					gotoxy(6,3);
					printf("Menu - Alterar >");
					menu2(pos2);
					switch(pos2)
					{
						case 0:
							altAlun(alun,TLA); //OK
							ordAlun(alun,TLA);
							break;
						case 1:
							altDisc(disc,TLD); //OK
							break;
						case 2:
							altNota(nota,TLN, alun, TLA, disc, TLD); //OK
							break;
					}
					
				} while(pos2 != 9);
				pos2 = 0;
				break;
				
			case 2:
				do
				{
					apagar();
					textcolor(2);
					gotoxy(6,3);
					printf("Menu - Excluir >");
					menu2(pos2);
					switch(pos2)
					{
						case 0:
							excluirRa(alun,TLA,nota,TLN); //OK
							break;
						case 1:
							excluirCod(disc,TLD,nota,TLN); //OK
							break;
						case 2:
							excluirNota(nota,TLN,alun,TLA,disc,TLD); //OK
							break;
					}
				}while(pos2 != 9);
				pos2 = 0;
				break;
			case 3:
				repr(alun,TLA,disc,TLD,nota,TLN); // OK
				break;
			case 4:
				if(TLA>0)
				{
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(7);
					apagarlinha(8);
					apagarlinha(9);
					apagarlinha(10);
					apagarlinha(11);
					apagarlinha(12);
					apagarlinha(13);
					
					textcolor(15);
					gotoxy(6,3);
					printf("Menu - Exibir aluno por inicial >");
					
					apagarbotao();
					
					textcolor(4);
					gotoxy(80,3);
					printf("[ESC] Sair");
					
					textcolor(15);
					gotoxy(6,5);
					printf("Inicial: ");
					inicial = toupper(getch());
					if(!(inicial == 27))
					{
						apagarbotao();
						exibLetra(nota,TLN,alun,TLA,disc,TLD,inicial); //OK
					}
				}
				else
				{
					apagar();
					textcolor(2);
					gotoxy(6,3);
					printf("Menu - Exibir aluno por inicial >");
					textcolor(15);
					gotoxy(6,5);
					printf("NAO HA O QUE EXIBIR");
					gotoxy(6,6);
					printf("Pressione qualquer tecla para prosseguir");
					getch();
				}
				break;
			case 5:
				discRepr(alun,TLA,disc,TLD,nota,TLN); // OK
				break;
			case 6:
				do
				{
					apagarmenu();
					apagartela();
					gotoxy(6,3);
					printf("Menu - Consultar >");
					menu2(pos2);
					switch(pos2)
					{
						case 0:
							consAlun(alun, TLA, disc, TLD, nota, TLN); //OK
							break;
						case 1:
							consDisc(alun, TLA, disc, TLD, nota, TLN); //OK
							break;
						case 2:
							consNota(alun, TLA, disc, TLD, nota, TLN); //OK
							break;
					}
					
				} while(pos2 != 9);
				pos2 = 0;
				break;
			case 7:
				todos(alun,TLA,disc,TLD,nota,TLN); // OK
				break;
			case 8:
				inserir(alun, TLA, disc, TLD, nota, TLN); //OK
				break;
		}
	} while(pos != 9);
}

//INSERIR DADOS PARA TESTE
void inserir(alunos alun[TFA], int &TLA, disciplinas disc[TFD], int &TLD, notas nota[TFN], int &TLN)
{
	int i, j;
	
	apagar();
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Inserir >");
	textcolor(15);
	strcpy(alun[0].ra,"000000000");
	strcpy(alun[1].ra,"111111111");
	strcpy(alun[2].ra,"222222222");
	strcpy(alun[3].ra,"333333333");
	
	strcpy(alun[0].nome,"Gerson Abreu");
	strcpy(alun[1].nome,"Jonathan Sanchez");
	strcpy(alun[2].nome,"Michael Jackson");
	strcpy(alun[3].nome,"Gustavo Lima");
	TLA = 4;
	
	strcpy(disc[0].cod,"000");
	strcpy(disc[1].cod,"111");
	strcpy(disc[2].cod,"222");
	
	strcpy(disc[0].nome,"Algoritimos e tecnicas de programacao");
	strcpy(disc[1].nome,"Fundamentos de sistemas de informacao");
	strcpy(disc[2].nome,"Ciencia de dados");
	
	TLD = 3;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			strcpy(nota[i*3+j].ra, alun[i].ra);
			strcpy(nota[i*3+j].cod, disc[j].cod);
			nota[i*3+j].nota = 1.0*(rand()%11);
		}
	}
	gotoxy(6,5);
	printf("Inserido");
	gotoxy(6,6);
	printf("Pressione qualquer tecla para prosseguir...");
	TLN = 12;
	getch();
}
//FUNCAO MENU
void menu(int &pos)
{
	char op;
	
	textcolor(RED);
	gotoxy(80,3);
	printf("[ESC] Fechar o programa!");
	
	gotoxy(6,3);
	textcolor(15);
	printf("Menu >");
	do
	{
		if(pos == 0)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,5);
		printf("Cadastrar");
		
		if(pos == 1)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,6);
		printf("Alterar");
		
		if(pos == 2)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,7);
		printf("Excluir");
		
		if(pos == 3)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,8);
		printf("Reprovados em 2 ou mais disciplinas");
	
		if(pos == 4)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,9);
		printf("Exibir por inicial");
	
		if(pos == 5)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,10);
		printf("Disciplinas com media geral abaixo de 6");
	
		if(pos == 6)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,11);
		printf("Consultar");
		
		if(pos == 7)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,12);
		printf("Exibir todos os alunos");
		
		if(pos == 8)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,13);
		printf("Inserir");
		
		gotoxy(1,1);
		op = toupper(getch());
		
		switch(op)
		{
			case 72:
				pos--;
				break;
			case 80:
				pos++;
				break;
		}
		if (pos < 0)
			pos = 8;
		if (pos > 8)
			pos = 0;
	} while(op != 27 && op != 13);
	
	if(op == 27)
		pos = 9;
}
//MENU CADASTRO
void menu2(int &pos)
{
	char op;
	
	textcolor(RED);
	gotoxy(80,3);
	printf("[ESC] Voltar");
	
	do
	{
		if(pos == 0)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,5);
		printf("Alunos");
		
		if(pos == 1)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,6);
		printf("Disciplinas");
		
		if(pos == 2)
			textcolor(GREEN);
		else
			textcolor(WHITE);
		gotoxy(6,7);
		printf("Notas");
		
		gotoxy(1,1);
		op = toupper(getch());
		
		switch(op)
		{
			case 72:
				pos--;
				break;
			case 80:
				pos++;
				break;
		}
		if (pos < 0)
			pos = 2;
		if (pos > 2)
			pos = 0;
	} while(op != 27 && op != 13);
	
	if(op == 27)
		pos = 9;
}
//EXIBIR -----------------------------------------------------------------------
//FUNCAO PARA EXIBIR ALUNOS
void exibAlun(alunos alun[TFA], int TLA)
{
	int i;
	if(TLA > 0)
	{
		printf("  TABELA DE ALUNOS:\n\n");
		for(i=0;i<TLA;i++)
		{
			printf("  RA: %s\t",alun[i].ra);
			printf("  Nome: %s\n",alun[i].nome);
		}
	}
	else
	{
		printf("  VAZIO!\n");
	}
	printf("\n");
}

//FUNCAO PARA EXIBIR DISCIPLINAS
void exibDisc(disciplinas disc[TFD], int TLD)
{
	int i;
	if(TLD > 0)
	{
		printf("  TABELA DE DISCIPLINAS:\n\n");
		for(i=0;i<TLD;i++)
		{
			printf("  Codigo da Disciplina: %s\t",disc[i].cod);
			printf("  Disciplina: %s\n",disc[i].nome);
		}
	}
	else
	{
		printf("  VAZIO!\n");
	}
	printf("\n");
}

//FUNCAO PARA EXIBIR NOTAS
void exibNota(notas nota[TFN], int TLN)
{
	int i;
	if(TLN > 0)
	{
		printf("  TABELA DE NOTAS:\n\n");
		for(i=0;i<TLN;i++)
		{
			printf("  RA: %s\t",nota[i].ra);
			printf("  Codigo da disciplina: %s\t",nota[i].cod);
			printf("  Nota: %.1f\n",nota[i].nota);
		}
	}
	else
	{
		printf("  VAZIO!\n");
	}
	printf("\n");
}

//BUSCAR -----------------------------------------------------------------------
//FUCAO PARA BUSCAR COD DISCIPLINA
int buscaCod (disciplinas disc[TFD], int TLD, char aux[TFcod])
{
	int i=0;
	while(i<TLD && strcmp(disc[i].cod,aux) != 0)
		i++;
	if(i < TLD)
		return i;
	else
		return -1;
}

//FUCAO PARA BUSCAR RA
int buscaRa (alunos alun[TFA], int TLA, char aux[TFra])
{
	int i=0;
	while(i<TLA && strcmp(alun[i].ra,aux) != 0)
		i++;
	if(i < TLA)
		return i;
	else
		return -1;
}

//FUNCAO PARA BUSCAR RA NA NOTA
int buscaRaNota (notas nota[TFN],int TLN, char aux[TFra], int i)
{
	while(i < TLN && strcmp(aux,nota[i].ra) != 0)
		i++;
	if(i < TLN)
		return i;
	else
		return -1;
}

//FUNCAO PARA BUSCAR COD NA NOTA
int buscaCodNota (notas nota[TFN],int TLN, char aux[TFcod], int i)
{
	while(i < TLN && strcmp(nota[i].cod,aux) != 0)
		i++;
	if(i < TLN)
		return i;
	else
		return -1;
}

//CADASTRO ---------------------------------------------------------------------

//FUNCAO PARA CADASTRAR ALUNOS
void cadAlun(alunos alun[TFA], int &TLA)
{
	char aux[TFra], aux1;
	int pos;
	
	apagarlinha(7);
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Cadastrar - Alunos >");
	if(TLA >= 0)
	{
		do
		{
				apagarlinha(6);
			do
			{
				apagarbotao();
				apagarlinha(5);
				gotoxy(24,5);
				textcolor(15);
				printf("Nome: ");
				
				gotoxy(80,3);
				textcolor(4);
				printf("[ENTER] Sair (se o ra estiver vazio)");
			
				textcolor(15);
				gotoxy(6,5);
				printf("RA: ");
				
				gotoxy(10,5);
				textcolor(6);
				fflush(stdin);
				gets(aux);
				
				if(strlen(aux) > 0 && strlen(aux) != 9)
				{
					textcolor(4);
					gotoxy(6,6);
					printf("*Sao 9 numeros!*");
				}
			} while(strlen(aux) > 0 && strlen(aux) != 9);
			if(strlen(aux) > 0)
			{
				apagarlinha(6);
				pos = buscaRa(alun,TLA,aux);
				if(pos == -1)
				{
					strcpy(alun[TLA].ra,aux);
					
					gotoxy(30,5);
					textcolor(6);
					fflush(stdin);
					gets(alun[TLA].nome);
					TLA++;
					textcolor(2);
					gotoxy(6,7);
					printf("Cadastrado");
				}
				else
				{
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(7);
					apagarbotao();
					textcolor(4);
					gotoxy(6,5);
					printf("RA JA CADASTRADO!");
					textcolor(15);
					gotoxy(6,6);
					printf("Pressione qualquer tecla para prosseguir...");
					getch();
				}
			}
		} while(TLA < TFA && strlen(aux) > 0);
	}
	if (TLA == TFA)
	{
		apagarlinha(5);
		apagarlinha(6);
		apagarbotao();
		textcolor(4);
		gotoxy(6,5);
		printf("SEM ESPACO!");
		gotoxy(6,6);
		textcolor(15);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//FUNCAO PARA CADASTRAR DISCIPLINAS
void cadDisc(disciplinas disc[TFD], int &TLD)
{
	char aux1,aux[TFcod];
	int pos;
	
	apagarlinha(7);
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Cadastro - Disciplinas >");
	
	while(TLD < TFD && strlen(aux) > 0)
	{
		gotoxy(80,3);
		textcolor(4);
		printf("[ENTER] Sair (se o cod estiver vazio)");
		
		apagarlinha(6);
		do
		{
			apagarlinha(5);
			textcolor(15);
			gotoxy(6,5);
			printf("Codigo:");
			gotoxy(24,5);
			printf("Nome da disciplina:");
			
			textcolor(6);
			gotoxy(14,5);
			fflush(stdin);
			gets(aux);
			if(strlen(aux) > 0 && strlen(aux) != 3)
			{
				apagarlinha(7);
				textcolor(4);
				gotoxy(6,6);
				printf("*Sao 3 numeros!*");
			} 
		}while(strlen(aux) > 0 && strlen(aux) != 3);
		if(strlen(aux) > 0)
		{
			apagarlinha(6);
			pos = buscaCod(disc,TLD,aux);
			if(pos == -1)
			{
				strcpy(disc[TLD].cod,aux);
				textcolor(6);
				gotoxy(44,5);
				fflush(stdin);
				gets(disc[TLD].nome);
				TLD++;
				
				textcolor(2);
				gotoxy(6,7);
				printf("Cadastrado");
			}
			else
			{
				apagarlinha(5);
				apagarlinha(6);
				apagarlinha(7);
				apagarbotao();
				textcolor(4);
				gotoxy(6,5);
				printf("DISCIPLINA JA CADASTRADA!");
				textcolor(15);
				gotoxy(6,6);
				printf("Pressione qualquer tecla para prosseguir...");
				getch();
			}
		}
			
	}
	if (TLD == TFD)
	{
		apagarlinha(5);
		apagarlinha(6);
		apagarbotao();
		textcolor(4);
		gotoxy(6,5);
		printf("SEM ESPACO!");
		textcolor(15);
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//FUNCAO PARA CADASTRAR NOTAS
void cadNota (notas nota[TFN], int &TLN, alunos alun[TFA],int TLA, disciplinas disc[TFD],int TLD)
{
	char aux[TFra],aux1[TFra];
	int cod, pos,pos1,pos2,i;
	bool cont;
	
	apagarlinha(5);
	apagarlinha(6);
	apagarlinha(7);
	apagarbotao();
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Cadastro - Notas >");
	
	while (TLN < TFN && TLN < TLD*TLA && strlen(aux) > 0)
	{
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		
		gotoxy(80,3);
		textcolor(4);
		printf("[ENTER] Sair (se o ra estiver vazio)");
		
		textcolor(15);
		gotoxy(6,5);
		printf("RA:");
		textcolor(3);
		gotoxy(24,5);
		printf("Nome:");
		
		textcolor(15);
		gotoxy(6,6);
		printf("Codigo:");
		textcolor(3);
		gotoxy(24,6);
		printf("Disciplina:");
		
		textcolor(15);
		gotoxy(6,7);
		printf("Nota:");
		
		textcolor(6);
		gotoxy(10,5);
		fflush(stdin);
		gets(aux);
		if(strlen(aux) > 0)
		{
			//BUSCA RA		
			pos = buscaRa(alun,TLA,aux);
			if(pos >= 0)
			{
				textcolor(2);
				gotoxy(30,5);
				printf("%s",alun[pos].nome);
				strcpy(nota[TLN].ra,aux);
				
				textcolor(6);
				gotoxy(14,6);
				fflush(stdin);
				gets(aux1);
				//BUSCA COD
				pos = buscaCod(disc,TLD,aux1);
				if(pos >= 0)
				{
					textcolor(2);
					gotoxy(36,6);
					printf("%s",disc[pos].nome);
					
					strcpy(nota[TLN].cod,aux1);
					i=0;
					while (i<TLN && (strcmp(aux,nota[i].ra) != 0 || strcmp(aux1,nota[i].cod) != 0))
						i++;
					if(i < TLN)
					{
						apagarbotao();
						apagarlinha(5);
						apagarlinha(6);
						apagarlinha(7);
						apagarlinha(8);
						
						textcolor(4);
						gotoxy(6,5);
						printf("CODIGO JA CADASTRADO!");
						textcolor(15);
						gotoxy(6,6);
						printf("Pressione qualquer tecla para prosseguir...");
						getch();
					}
					else
					{
						textcolor(2);
						gotoxy(12,7);
						scanf("%f",&nota[TLN].nota);
						TLN++;
						
						gotoxy(6,8);
						printf("Cadastrado!");
					}
				}
				else
				{
					
					apagarbotao();
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(7);
					apagarlinha(8);
					
					textcolor(4);
					gotoxy(6,5);
					printf("CODIGO NAO ENCONTRADO!");
					textcolor(15);
					gotoxy(6,6);
					printf("Pressione qualquer tecla para prosseguir...");
					getch();
				}
			}
			else
			{
				apagarbotao();
				apagarlinha(5);
				apagarlinha(6);
				apagarlinha(7);
				apagarlinha(8);
				
				textcolor(4);
				gotoxy(6,5);
				printf("RA NAO ENCONTRADO!");
				textcolor(15);
				gotoxy(6,6);
				printf("Pressione qualquer tecla para prosseguir...");
				getch();
			}
		}
	}
		
	if(TLN >= TLD*TLA)
	{
		apagarbotao();
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		
		textcolor(15);
		gotoxy(6,5);
		printf("Nao ha o que cadastrar");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//ALTERAR ----------------------------------------------------------------------
//ALTERAR ALUNO
void altAlun(alunos alun[TFA], int TLA)
{
	char aux[TFra];
	int pos, i;
	
	apagarbotao();
	apagarlinha(7);
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Alterar - Alunos >");
	
	do
	{
		gotoxy(80,3);
		textcolor(4);
		printf("[ENTER] Sair (se o ra estiver vazio)");
		
		apagarlinha(5);
		apagarlinha(6);
		
		if(TLA > 0)
		{
			textcolor(15);
			gotoxy(6,5);
			printf("RA:");
			
			textcolor(3);
			gotoxy(24,5);
			printf("Nome:");
			
			textcolor(15);
			gotoxy(6,6);
			printf("Novo nome:");
			
			textcolor(6);
			gotoxy(10,5);
			fflush(stdin);
			gets(aux);
			if(strlen(aux) > 0)
			{
				pos = buscaRa(alun,TLA,aux);
				if (pos >= 0)
				{
					textcolor(2);
					gotoxy(30,5);
					printf("%s",alun[pos].nome);
					textcolor(6);
					gotoxy(17,6);
					fflush(stdin);
					gets(alun[pos].nome);
					
					textcolor(2);
					gotoxy(6,8);
					printf("Alterado");
				}
				else
				{
					apagarbotao();
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(8);
					textcolor(4);
					gotoxy(6,5);
					printf("RA NAO ENCONTRADO!");
					gotoxy(6,6);
					textcolor(15);
					printf("Pressione qualquer tecla para prosseguir...");
					getch();
				}
			}
		}
	} while(strlen(aux) > 0 && TLA > 0);
	
	if(TLA == 0)
	{
		apagarbotao();
		apagarlinha(5);
		apagarlinha(6);
		textcolor(15);
		gotoxy(6,5);
		printf("Nao ha o que alterar");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//ALTERAR DISCIPLINA
void altDisc(disciplinas disc[TFD], int TLD)
{
	char aux[TFcod];
	int pos, i;
	
	apagarbotao();
	apagarlinha(7);
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Alterar - Disciplinas >");
	
	do
	{
		gotoxy(80,3);
		textcolor(4);
		printf("[ENTER] Sair (se o cod estiver vazio)");
		
		apagarlinha(5);
		apagarlinha(6);
		
		if(TLD > 0)
		{
			textcolor(15);
			gotoxy(6,5);
			printf("Codigo:");
			
			textcolor(3);
			gotoxy(24,5);
			printf("Disciplina:");
			
			textcolor(15);
			gotoxy(6,6);
			printf("Novo nome:");
			
			textcolor(6);
			gotoxy(14,5);
			fflush(stdin);
			gets(aux);
			if(strlen(aux) > 0)
			{
				pos = buscaCod(disc,TLD,aux);
				if (pos >= 0)
				{
					textcolor(2);
					gotoxy(36,5);
					printf("%s",disc[pos].nome);
					textcolor(6);
					gotoxy(17,6);
					fflush(stdin);
					gets(disc[pos].nome);
					
					textcolor(2);
					gotoxy(6,8);
					printf("Alterado");
				}
				else
				{
					apagarbotao();
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(8);
					textcolor(4);
					gotoxy(6,5);
					printf("CODIGO NAO ENCONTRADO!");
					gotoxy(6,6);
					textcolor(15);
					printf("Pressione qualquer tecla para prosseguir...");
					getch();
				}
			}
		}
	} while(strlen(aux) > 0 && TLD > 0);
	
	if(TLD == 0)
	{
		apagarbotao();
		apagarlinha(5);
		apagarlinha(6);
		textcolor(15);
		gotoxy(6,5);
		printf("Nao ha o que alterar");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//ALTERAR NOTA
void altNota(notas nota[TFN], int TLN, alunos alun[TFA],int TLA, disciplinas disc[TFD],int TLD)
{
	char auxRa[TFra], auxCod[TFcod];
	int pos=0, i;
	
	apagarbotao();
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Alterar - Notas >");
	
	do
	{
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		
		textcolor(4);
		gotoxy(80,3);
		printf("[ENTER] Sair (se o ra estiver vazio)");
		
		if(TLN > 0)
		{
			textcolor(15);
			gotoxy(6,5);
			printf("RA:");
			
			textcolor(3);
			gotoxy(24,5);
			printf("Nome: ");
			
			textcolor(15);
			gotoxy(6,6);
			printf("Codigo: ");
			
			textcolor(3);
			gotoxy(24,6);
			printf("Disciplina: ");
			
			textcolor(15);
			gotoxy(6,7);
			printf("Nova nota:");
			
			textcolor(3);
			gotoxy(24,7);
			printf("Nota:");
			
			textcolor(6);
			gotoxy(10,5);
			fflush(stdin);
			gets(auxRa);
			if (strlen(auxRa) > 0)
			{
				pos = buscaRaNota(nota,TLN,auxRa,0);
				if(pos >= 0)
				{
					textcolor(2);
					gotoxy(30,5);
					printf("%s",alun[buscaRa(alun,TLA,auxRa)].nome);
					
					textcolor(6);
					gotoxy(14,6);
					fflush(stdin);
					gets(auxCod);
					i=0;
					while(i<TFN)
					{
						if(strcmp(auxCod,nota[i].cod) == 0 && strcmp(auxRa,nota[i].ra) == 0)
							pos = i;
						i++;
					}
					if(pos == TLN)
					{
						clrscr();
						printf("Menu - Alterar - Notas>\n\n");
						printf("  CODIGO NAO ENCONTRADO!\n");
						printf("  Pressione qualquer tecla para prosseguir...");
						getch();
					}
					else
					{
						textcolor(2);
						gotoxy(36,6);
						printf("%s",disc[buscaCod(disc,TLD,auxCod)].nome);
						
						textcolor(2);
						gotoxy(32,7);
						printf("%.1f",nota[pos].nota);
						
						textcolor(6);
						gotoxy(17,7);
						scanf("%f",&nota[pos].nota);
						
						textcolor(2);
						gotoxy(6,8);
						printf("Cadastrado");
					}
				}
				else
				{
					apagarbotao();
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(7);
					apagarlinha(8);
					textcolor(4);
					gotoxy(6,5);
					printf("RA NAO ENCONTRADO");
					textcolor(15);
					gotoxy(6,6);
					printf("Pressione qualquer tecla para prosseguir...");
					getch();
				}
			}
		}
	} while (strlen(auxRa) > 0 && TLN > 0);
	
	if(TLN == 0)
	{
		apagarbotao();
		textcolor(15);
		gotoxy(6,5);
		printf("Nao ha o que alterar");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//EXCLUIR ----------------------------------------------------------------------
//ESCLUIR RA 
void excluirRa(alunos alun[TFA], int &TLA, notas nota[TFN], int &TLN)
{
	int pos, i;
	char aux[TFra], r=0;
	
	apagarbotao();
	apagarlinha(7);
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Excluir - Alunos >");
	
	do
	{
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		apagarlinha(8);
		apagarbotao();
		
		textcolor(4);
		gotoxy(81,3);
		printf("[ENTER]Sair (se o RA estiver vazio)");
		
		if(TLA > 0)
		{
			gotoxy(6,5);
			textcolor(15);
			printf("RA:");
			
			textcolor(6);
			gotoxy(10,5);
			fflush(stdin);
			gets(aux);
			
			if(strlen(aux) > 0)
			{
				pos = buscaRa(alun,TFA,aux);	
				if(pos >= 0)
				{
					apagarbotao();
					apagarlinha(5);
					textcolor(15);
					gotoxy(6,5);
					printf("Voce tem certeza que deseja apagar os dados de '%s'?",alun[pos].nome);
					gotoxy(6,6);
					printf("Apagar esse aluno, tambem ira apagar as suas notas!");
					textcolor(2);
					gotoxy(6,8);
					printf("[S]Sim ou [N]nao?");
					do
					{
						r = toupper(getch());
						if (r == 'S')
						{
							for(i=pos;i<TLA-1;i++)
								alun[i] = alun[i+1];
							TLA--;
							pos = buscaRaNota(nota,TLN,aux,0);
							while(pos >= 0)
							{
								for(i=pos;i<TLN-1;i++)
									nota[i] = nota[i+1];
								TLN--;
								
								pos = buscaRaNota(nota,TLN,aux,pos);
							}
							if(TLA > 0)
							{
								apagarbotao();
								apagarlinha(5);
								apagarlinha(6);
								apagarlinha(8);
								textcolor(2);
								gotoxy(6,5);
								printf("Excluido!");
								textcolor(15);
								gotoxy(6,6);
								printf("Pressione qualquer tecla para voltar...");
								getch();
							}
						}
					} while(r != 'S' && r != 'N');
				}
				else
				{
					apagarbotao();
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(7);
					apagarlinha(8);
					
					textcolor(4);
					gotoxy(6,5);
					printf("RA NAO ENCONTRADO!");
					textcolor(15);
					gotoxy(6,6);
					printf("Pressione qualquer tecla para voltar...");
					getch();
				}
			}
		}
	} while(strlen(aux) > 0 && TLA > 0);
	
	if(TLA == 0)
	{
		apagarbotao();
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		apagarlinha(8);
		
		textcolor(15);
		gotoxy(6,5);
		printf("NAO HA ALUNOS PARA EXCLUIR");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para voltar...");
		getch();
	}
}

//EXCLUIR DISCIPLINA
void excluirCod(disciplinas disc[TFD], int &TLD, notas nota[TFN], int &TLN)
{
	int pos, i;
	char aux[TFcod], r=0;
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Excluir - Disciplinas >");
	
	apagarbotao();
	
	do
	{
		apagarbotao();
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		apagarlinha(8);
		
		textcolor(4);
		gotoxy(81,3);
		printf("[ENTER]Sair (se o COD estiver vazio)");
		
		if(TLD > 0)
		{
			textcolor(15);
			gotoxy(6,5);
			printf("Codigo da disciplina:");
			
			textcolor(6);
			gotoxy(28,5);
			fflush(stdin);
			gets(aux);
			if(strlen(aux) > 0)
			{
				pos = buscaCod(disc,TFD,aux);	
				if(pos >= 0)
				{
					apagarbotao();
					apagarlinha(5);
					textcolor(15);
					gotoxy(6,5);
					printf("Voce tem certeza que deseja apagar os dados de '%s'?",disc[pos].nome);
					gotoxy(6,6);
					printf("Apagar essa disciplina, tambem ira apagar as suas notas!");
					textcolor(2);
					gotoxy(6,8);
					printf("[S]Sim ou [N]nao?");
					do
					{
						r = toupper(getch());
						if (r == 'S')
						{
							for(i=pos;i<TLD-1;i++)
								disc[i] = disc[i+1];
							TLD--;
							
							pos = buscaCodNota(nota,TLN,aux,0);
							while(pos >= 0)
							{
								for(i=pos;i<TLN-1;i++)
									nota[i] = nota[i+1];
								TLN--;
								
								pos = buscaCodNota(nota,TLN,aux,pos);
							}
							if(TLD > 0)
							{
								apagarbotao();
								apagarlinha(5);
								apagarlinha(6);
								apagarlinha(8);
								textcolor(2);
								gotoxy(6,5);
								printf("Excluido!");
								textcolor(15);
								gotoxy(6,6);
								printf("Pressione qualquer tecla para voltar...");
								getch();
							}
						}
					} while(r != 'S' && r != 'N');
				}
				else
				{
					apagarbotao();
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(7);
					apagarlinha(8);
					
					textcolor(4);
					gotoxy(6,5);
					printf("CODIGO NAO ENCONTRADO!");
					textcolor(15);
					gotoxy(6,6);
					printf("Pressione qualquer tecla para voltar...");
					getch();
				}
			}
		}
	} while(strlen(aux) > 0 && TLD > 0);
	
	if(TLD == 0)
	{
		apagarbotao();
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		apagarlinha(8);
		
		textcolor(15);
		gotoxy(6,5);
		printf("NAO HA ALUNOS PARA EXCLUIR");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para voltar...");
		getch();
	}
}

//EXCLUIR NOTAS TODO BUGADO§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
void excluirNota(notas nota[TFN], int &TLN, alunos alun[TFA], int TLA,disciplinas disc[TFD], int TLD)
{
	char aux[TFra],aux1[TFcod],r=0;
	int pos,pos1,i;
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Excluir - Notas >");
	
	apagarbotao();
	
	do
	{
		if(TLN > 0)
		{
			apagarlinha(5);
			apagarlinha(6);
			apagarlinha(7);
			apagarlinha(9);
			apagarlinha(11);
			
			textcolor(4);
			gotoxy(81,3);
			printf("[ENTER]Sair (se o RA estiver vazio)");
			
			textcolor(15);
			gotoxy(6,5);
			printf("RA:");
			
			gotoxy(6,6);
			printf("Codigo: ");
			
			textcolor(3);
			gotoxy(24,5);
			printf("Nome:");
			
			gotoxy(24,6);
			printf("Disciplina:");
			
			gotoxy(24,7);
			printf("Nota:");
			
			textcolor(6);
			gotoxy(10,5);
			fflush(stdin);
			gets(aux);
			
			if(strlen(aux)>0)
			{
				pos=buscaRaNota(nota,TLN,aux,0);
				if(pos>=0 && strlen(aux) > 0)
				{
					textcolor(2);
					gotoxy(30,5);
					printf("%s",alun[buscaRa(alun,TLA,aux)].nome);
					
					textcolor(6);
					gotoxy(14,6);
					fflush(stdin);
					gets(aux1);
					while(pos < TLN && (strcmp(aux,nota[pos].ra) != 0 || strcmp(aux1,nota[pos].cod) != 0))
					{
						printf("%d\n",pos);
						pos++;
					}
					if(pos < TLN)
					{
						textcolor(2);
						gotoxy(36,6);
						printf("%s",disc[buscaCod(disc,TLD,aux1)].nome);
						
						textcolor(2);
						gotoxy(30,7);
						printf("%.1f",nota[pos].nota);
						
						textcolor(15);
						gotoxy(6,9);
						printf("Voce tem certeza que deseja apagar essa nota?");
						
						textcolor(2);
						gotoxy(6,11);
						printf("[S]Sim ou [N]nao?");
						do
						{
							r = toupper(getch());
							if(r == 'S')
							{
								for(;pos<TLN-1;pos++)
								{
									nota[pos]=nota[pos+1];
								}
								TLN--;
								if(TLN > 0)
								{
									apagarbotao();
									apagarlinha(5);
									apagarlinha(6);
									apagarlinha(7);
									apagarlinha(9);
									apagarlinha(11);
									
									textcolor(2);
									gotoxy(6,5);
									printf("Excluido!");
									
									textcolor(15);
									gotoxy(6,6);
									printf("Pressione qualquer tecla para voltar...");
									
									getch();
									apagar();
								}
							}
						}while(r != 'S' && r != 'N');
					}
					else
					{
						apagarbotao();
						apagarlinha(5);
						apagarlinha(6);
						apagarlinha(7);
						apagarlinha(9);
						apagarlinha(11);
						
						textcolor(4);
						gotoxy(6,5);
						printf("CODIGO NAO ENCONTRADO!");
						
						textcolor(15);
						gotoxy(6,6);
						printf("Pressione qualquer tecla para voltar...");
						
						getch();
					}
				}
				else
				{
					apagarbotao();
					apagarlinha(5);
					apagarlinha(6);
					apagarlinha(7);
					apagarlinha(9);
					apagarlinha(11);
					
					textcolor(4);
					gotoxy(6,5);
					printf("RA NAO ENCONTRADO!");
					
					textcolor(15);
					gotoxy(6,6);
					printf("Pressione qualquer tecla para voltar...");
					
					getch();
				}
			}
		}
		if(TLN == 0)
		{
			apagarbotao();
			apagarlinha(5);
			apagarlinha(6);
			apagarlinha(7);
			apagarlinha(9);
			apagarlinha(11);
			
			textcolor(15);
			gotoxy(6,5);
			printf("NAO HA NOTAS PARA EXCLUIR");
			textcolor(15);
			gotoxy(6,6);
			printf("Pressione qualquer tecla para voltar...");
			getch();
		}
	}while(strlen(aux)>0&&TLN>0);
}

// B ---------------------------------------------------------------------------
//EXIBIR RELATORIO DE ALUNOS
void exibRela(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN, int pos, int &y)
{
	char auxRa[TFra];
	int i;
	
	gotoxy(6,y);
	printf("RA: %s",alun[pos].ra);
	strcpy(auxRa, alun[pos].ra);
	gotoxy(24,y);
	printf("Nome: %s",alun[pos].nome);
	y++;
	i = buscaRaNota(nota,TLN,auxRa,0);
	while(i >= 0)
	{
		
		gotoxy(6,y);
		printf("Codigo: %s",nota[i].cod);
		gotoxy(24,y);
		printf("Disciplina: %s",disc[buscaCod(disc,TLD,nota[i].cod)].nome);
		gotoxy(85,y);
		printf("Nota: %.1f",nota[i].nota);
		if(nota[i].nota >= 6)
		{
			gotoxy(96,y);
			printf("Situacao: Aprovado");
		}
		else
		{
			gotoxy(96,y);
			printf("Situacao: Reprovado");

		}
		i = buscaRaNota(nota,TLN,auxRa,i+1);
		y++;
		
	}
}

//EXIBI RELATORIOS DE DISCIPLINAS
void exibRelaDisc(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN, int pos, int &y)
{
	char aux[TFcod];
	strcpy(aux, disc[pos].cod);
	textcolor(15);
	gotoxy(6,y);
	printf("Codigo: %s",disc[pos].cod);
	gotoxy(24,y);
	printf("Disciplina: %s", disc[pos].nome);
	pos = buscaCodNota(nota,TLN,aux,0);
	y++;
	while(pos >= 0)
	{
		gotoxy(6,y);
		printf("RA: %s ",nota[pos].ra);
		gotoxy(24,y);
		printf("Aluno: %s",alun[buscaRa(alun,TLA,nota[pos].ra)].nome);
		gotoxy(85,y);
		printf("Nota: %.1f",nota[pos].nota);
		gotoxy(96,y);
		if(nota[pos].nota >= 6)
			printf("Situacao: Aprovado\n");
		else
			printf("Situacao: Reprovado\n");
		
		pos = buscaCodNota(nota,TLN,aux,pos+1);
		y++;
	}
	y++;
}

void todos(alunos alun[TFA],int TLA, disciplinas disc[TFD],int TLD, notas nota[TFN], int TLN)
{
	int i=0, y, p=0, vet[10]; //12 19 26
	char op;
	apagar();
	
	textcolor(2);
	gotoxy(6,3);
	printf("Menu - Exibir todos os alunos >");
	
	if(TLA > 0)
	{
		textcolor(4);
		gotoxy(80,3);
		printf("[ESC] Sair");
		
		textcolor(3);
		linha(11);
		linha(18);
		linha(25);
		textcolor(15);
		do
		{
			textcolor(15);
			i = p*3;
			y=5;
			if(i<TLA)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,i,y);
				i++;
			}
			y=12;
			if(i<TLA)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,i,y);
				i++;
			}
			else
			{
				apagarlinha(12);
				apagarlinha(13);
				apagarlinha(14);
				apagarlinha(15);
				apagarlinha(16);
				apagarlinha(17);
			}
			y=19;
			if(i<TLA)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,i,y);
				i++;
			}
			else
			{
				apagarlinha(19);
				apagarlinha(20);
				apagarlinha(21);
				apagarlinha(22);
				apagarlinha(23);
				apagarlinha(24);
			}
			
			textcolor(2);
			gotoxy(95,26);
			printf("Pagina: %d",p+1);
			
			textcolor(6);
			gotoxy(95,27);
			if(i<TLA)
				printf("[->] Avancar Pagina");
			else
				apagarlinha(27);
			gotoxy(95,28);
			if(i > 3)
				printf("[<-] Voltar Pagina");
			else
				apagarlinha(28);
			op = getch();
			switch(op)
			{
				case 75:
					if(i > 3)
						p--;
					break;
				case 77:
					if(i<TLA)
						p++;
					break;
			}
		} while(op != 27);
	}
	else
	{
		textcolor(15);
		gotoxy(6,5);
		printf("NAO HA ALUNOS PARA EXIBIR");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//REPROVADO EM 2 OU MAIS DISCIPLINAS
void repr(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN)
{
	int i, c, pos,y, vetpos[10], TL = 0, p=0;
	char op;
	
	apagarbotao();
	textcolor(4);
	gotoxy(80,3);
	printf("[ESC] Sair");
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Reprovados >");
	
	apagartela();
	textcolor(15);
	for(i=0;i<TLA;i++)
	{
		c=0;
		for(pos = 0; pos < TLN; pos++)
		{
			if(strcmp(alun[i].ra, nota[pos].ra) == 0)
			{
				if(nota[pos].nota < 6)
				{
					c++;
				}
			}
		}
		if(c > 1)
		{
			vetpos[TL] = i;
			TL++;
		}
	}
	if(TLA == 0)
	{
		apagarbotao();
		gotoxy(6,5);
		textcolor(15);
		printf("NAO HA ALUNOS");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
	else if(TL == 0)
	{
		apagarbotao();
		gotoxy(6,5);
		textcolor(15);
		printf("NENHUM ALUNO FOI REPROVADO");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
	else
	{
		textcolor(3);
		linha(11);
		linha(18);
		linha(25);
		do
		{
			textcolor(15);
			i = p*3;
			y=5;
			if(i<TL)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,vetpos[i],y);
				i++;
			}
			y=12;
			if(i<TL)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,vetpos[i],y);
				i++;
			}
			else
			{
				apagarlinha(12);
				apagarlinha(13);
				apagarlinha(14);
				apagarlinha(15);
				apagarlinha(16);
				apagarlinha(17);
			}
			y=19;
			if(i<TL)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,vetpos[i],y);
				i++;
			}
			else
			{
				apagarlinha(19);
				apagarlinha(20);
				apagarlinha(21);
				apagarlinha(22);
				apagarlinha(23);
				apagarlinha(24);
			}
			
			textcolor(2);
			gotoxy(95,26);
			printf("Pagina: %d",p+1);
			
			textcolor(6);
			gotoxy(95,27);
			if(i<TL)
				printf("[->] Avancar Pagina");
			else
				apagarlinha(27);
			gotoxy(95,28);
			if(i > 3)
				printf("[<-] Voltar Pagina");
			else
				apagarlinha(28);
			op = getch();
			switch(op)
			{
				case 75:
					if(i > 3)
						p--;
					break;
				case 77:
					if(i<TL)
						p++;
					break;
			}
		} while(op != 27);
	}
}

//DISCIPLINAS COM MEDIA GERAL ABAIXO DE 6
void discRepr(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN)
{
	int i, j, cont, y=5, c=0;
	char op;
	float soma;
	
	apagarmenu();
	apagartela();
	apagarbotao();
	textcolor(2);
	gotoxy(6,3);
	printf("Menu - Disciplinas com media abaixo de 6 >");
	for(i=0;i<TLD;i++)
	{
		soma = 0;
		cont = 0;
		for(j=0;j<TLN;j++)
		{
			if(strcmp(disc[i].cod,nota[j].cod) == 0)
			{
				soma = nota[j].nota+soma;
				cont++;
			}
		}
		if(soma/cont < 6)
		{
			textcolor(15);
			gotoxy(6,y);
			printf("Codigo: %s",disc[i].cod);
			gotoxy(24,y);
			printf("Disciplina: %s",disc[i].nome);
			gotoxy(80,y);
			printf("MEDIA: %.1f", soma/cont);
			c=1;
		}
		printf("\n");
		y++;
	}
	if(TLD == 0)
	{
		textcolor(15);
		gotoxy(6,5);
		printf("SEM DISCIPLINAS PARA AVALIAR");
		
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
	else if(c == 0)
	{
		textcolor(15);
		gotoxy(6,5);
		printf("NAO HA DISCIPLINAS COM MEDIA ABAIXO DE 6");
		getch();
		
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
	else
	{
		gotoxy(80,3);
		textcolor(4);
		printf("[ESC] Voltar");
		gotoxy(1,1);
		do
		{
			op=getch();
		}
		while(op != 27);
		
	}
}
//------------------------------------------------------------------------------
//EXIBIR POR INICIAL
void exibLetra(notas nota[TFN], int TLN,alunos alun[TFA], int TLA,disciplinas disc[TFD], int TLD, char aux)
{
	char aux1[TFra], op;
	int y , i, vetpos[10], TL = 0, p=0;
	
	textcolor(4);
	gotoxy(80,3);
	printf("[ESC] Sair");
	
	textcolor(2);
	for(i=0;i<TLA;i++)
	{
		if(alun[i].nome[0] == aux)
		{	
			vetpos[TL] = i;
			TL++;
		}
	}
	if(TL == 0)
	{
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		apagarlinha(8);
		apagarlinha(9);
		apagarlinha(10);
		apagarlinha(11);
		apagarlinha(12);
		apagarlinha(13);
		
		textcolor(15);
		gotoxy(6,5);
		printf("NENHUM ALUNO ENCONTRADO");
		
		gotoxy(6,6);
		printf("pressione qualquer tecla para prosseguir...");
		getch();
	}
	else
	{
		apagarlinha(5);
		apagarlinha(6);
		apagarlinha(7);
		apagarlinha(8);
		apagarlinha(9);
		apagarlinha(10);
		apagarlinha(11);
		apagarlinha(12);
		
		textcolor(3);
		linha(11);
		linha(18);
		linha(25);
		do
		{
			textcolor(15);
			i = p*3;
			y=5;
			if(i<TL)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,vetpos[i],y);
				i++;
			}
			y=12;
			if(i<TL)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,vetpos[i],y);
				i++;
			}
			else
			{
				apagarlinha(12);
				apagarlinha(13);
				apagarlinha(14);
				apagarlinha(15);
				apagarlinha(16);
				apagarlinha(17);
			}
			y=19;
			if(i<TL)
			{
				exibRela(alun,TLA,disc,TLD,nota,TLN,vetpos[i],y);
				i++;
			}
			else
			{
				apagarlinha(19);
				apagarlinha(20);
				apagarlinha(21);
				apagarlinha(22);
				apagarlinha(23);
				apagarlinha(24);
			}
			
			textcolor(2);
			gotoxy(95,26);
			printf("Pagina: %d",p+1);
			
			textcolor(6);
			gotoxy(95,27);
			if(i<TL)
				printf("[->] Avancar Pagina");
			else
				apagarlinha(27);
			gotoxy(95,28);
			if(i > 3)
				printf("[<-] Voltar Pagina");
			else
				apagarlinha(28);
			op = getch();
			switch(op)
			{
				case 75:
					if(i > 3)
						p--;
					break;
				case 77:
					if(i<TL)
						p++;
					break;
			}
		} while(op != 27);
	}
}
//CONSULTAR ALUNOS
void consAlun(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN)
{
	char aux[TFra];
	int pos,y=5;
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Consultar - Alunos >");
	apagarlinha(5);
	apagarlinha(6);
	apagarlinha(7);
	apagarbotao();
	textcolor(4);
	gotoxy(80,3);
	printf("[ESC] Sair (se o RA estiver vazio)");
	
	if(TLA > 0)
	{
		textcolor(15);
		gotoxy(6,5);
		printf("RA: ");
		textcolor(6);
		fflush(stdin);
		gets(aux);
		apagarlinha(5);
		if (strlen(aux) > 0)
		{
			pos = buscaRa(alun,TLA,aux);
			if(pos >= 0)
			{
				textcolor(15);
				apagarbotao();
				exibRela(alun, TLA, disc, TLD, nota, TLN, pos,y);
				y++;
				gotoxy(6,y);
				printf("Pressione qualquer tecla para prosseguir...");
			}
			else
			{
				apagarbotao();
				textcolor(4);
				gotoxy(6,5);
				printf("RA NAO ENCONTRADO!");
				textcolor(15);
				gotoxy(6,6);
				printf("Pressione qualquer tecla para prosseguir...");
			}
		}
	}
	else
	{
		apagarbotao();
		textcolor(15);
		gotoxy(6,5);
		printf("NAO HA O QUE CONSULTAR");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
	}
	getch();
}

//CONSULTAR DISCIPLINAS
void consDisc(alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN)
{
	char aux[TFcod];
	int pos, y=5;
	
	apagarlinha(5);
	apagarlinha(6);
	apagarlinha(7);
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Consultar - Disciplinas >");
	
	apagarbotao();
	textcolor(4);
	gotoxy(80,3);
	printf("[ESC] Sair (se o COD estiver vazio)");
	
	if(TLA > 0)
	{
		textcolor(15);
		gotoxy(6,5);
		printf("Codigo: ");
		textcolor(6);
		fflush(stdin);
		gets(aux);
		if(strlen(aux) > 0)
		{
			pos = buscaCod(disc,TLD,aux);
			if (pos >= 0)
			{
				apagarlinha(5);
				exibRelaDisc(alun, TLA, disc, TLD, nota, TLN, pos, y);
				y++;
				gotoxy(6,y);
				printf("Pressione qualquer tecla para prosseguir...");
			}
			else
			{
				apagarlinha(5);
				apagarbotao();
				textcolor(4);
				gotoxy(6,5);
				printf("CODIGO NAO ENCONTRADO!");
				textcolor(15);
				gotoxy(6,6);
				printf("Pressione qualquer tecla para prosseguir...");
			}
		}
	}
	else
	{
		apagarbotao();
		textcolor(15);
		gotoxy(6,5);
		printf("NAO HA O QUE CONSULTAR");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
	}
	getch();
}

//CONSULTAR NOTA
void consNota(alunos alun[TFA], int TLA,disciplinas disc[TFD], int TLD, notas nota[TFN], int TLN)
{
	char auxRa[TFra], auxCod[TFcod];
	int pos;
	
	apagarlinha(5);
	apagarlinha(6);
	apagarlinha(7);
	apagarbotao();
	
	textcolor(4);
	gotoxy(80,3);
	printf("[ESC] Sair (se o RA estiver vazio)");
	
	textcolor(15);
	gotoxy(6,3);
	printf("Menu - Consultar - Nota >");
	
	
	if(TLA > 0)
	{
		textcolor(3);
		gotoxy(24,5);
		printf("Nome:");
		
		gotoxy(24,6);
		printf("Disciplina:");
		
		textcolor(15);
		gotoxy(6,6);
		printf("Codigo:");
		
		gotoxy(6,5);
		printf("RA: ");
		
		textcolor(6);
		fflush(stdin);
		gets(auxRa);
		
		if(strlen(auxRa) > 0)
		{
			pos = buscaRaNota(nota,TLN,auxRa,0);
			if (pos >= 0)
			{
				
				gotoxy(30,5);
				printf("%s",alun[buscaRa(alun,TLA,auxRa)].nome);
				
				gotoxy(14,6);
				fflush(stdin);
				gets(auxCod);
				
				while (pos<TLN && (strcmp(auxRa,nota[pos].ra) != 0 || strcmp(auxCod,nota[pos].cod) != 0))
					pos++;
				if (pos < TLN)
				{
					textcolor(15);
					gotoxy(6,5);
					printf("RA: %s",auxRa);
					
					gotoxy(24,5);
					printf("Nome: %s",alun[buscaRa(alun,TLA,auxRa)].nome);
					
					gotoxy(6,6);
					printf("Codigo: %s",auxCod);
					
					gotoxy(24,6);
					printf("Disciplina: %s",disc[buscaCod(disc,TLD,auxCod)].nome);
					
					gotoxy(6,7);
					printf("Nota: %.1f",nota[pos].nota);
					getch();
				}
				else
				{
					apagarlinha(5);
					apagarlinha(6);
					apagarbotao();
					textcolor(4);
					gotoxy(6,5);
					printf("CODIGO NAO ENCONTRADO!");
					textcolor(15);
					gotoxy(6,6);
					printf("Pressione qualquer tecla para prosseguir...");
					getch();
				}
			}
			else
			{
				apagarlinha(5);
				apagarlinha(6);
				apagarbotao();
				textcolor(4);
				gotoxy(6,5);
				printf("RA NAO ENCONTRADO!");
				textcolor(15);
				gotoxy(6,6);
				printf("Pressione qualquer tecla para prosseguir...");
				getch();
			}
		}
	}
	else
	{
		apagarbotao();
		textcolor(15);
		gotoxy(6,5);
		printf("NAO HA O QUE CONSULTAR");
		gotoxy(6,6);
		printf("Pressione qualquer tecla para prosseguir...");
		getch();
	}
}

//FUNCAO PARA CRIAR A MOLDURA --------------------------------------------------
void moldura(void)
{
	int i;
	textcolor(3);
	//LINHAS HORIZONTAIS
	for(i=4;i<4+113;i++)
	{
		gotoxy(i,2); printf("%c",205);
		gotoxy(i,2+27); printf("%c",205);
	}
	
	//LINHAS VERTICAIS
	for(i=2;i<2+27;i++)
	{
		gotoxy(4,i); printf("%c",186);
		gotoxy(4+113,i); printf("%c",186);
	}
	
	//CANTOS
	gotoxy(4,2); printf("%c",201);
	gotoxy(4+113,2); printf("%c",187);
	gotoxy(4,2+27); printf("%c",200);
	gotoxy(4+113,2+27); printf("%c",188);
	
	//LINHA INDICE
	gotoxy(4,4); printf("%c",204);
	for(i=5;i<117;i++)
	{
		gotoxy(i,4); printf("%c",205);
	}
	gotoxy(117,4); printf("%c",185);
	
	//LINHA DE BOTAO PARA SAIR
	gotoxy(78,2); printf("%c",203);
	gotoxy(78,3); printf("%c",186);
	gotoxy(78,4); printf("%c",202);
}


void apagarlinha(int y)
{
	int x;
	for(x=5;x<117;x++)
	{
		gotoxy(x,y); printf(" ");
	}
}
void apagarbotao(void)
{
	int x, y;
	for(x=79;x<117;x++)
	{
		gotoxy(x,3); printf(" ");
	}
}
void apagarmenu(void)
{
	int x;
	for(x=5;x<78;x++)
	{
		gotoxy(x,3); printf(" ");
	}
}
void apagartela(void)
{
	int x, y;
	for(y=5;y<29;y++)
		for(x=5;x<117;x++)
		{
			gotoxy(x,y); printf(" ");
		}
}
void apagar(void)
{
	apagarbotao();
	apagarmenu();
	apagartela();
}
void linha(int y)
{
	int x;
	for(x=6;x<116;x++)
	{
		gotoxy(x,y); printf("-");
	}
}

void ordAlun(alunos alun[TFA], int TLA)
{
	int i, j;
	alunos aux;
	for(i=0;i<TLA-1;i++)
	{
		for(j=i+1;j<TLA;j++)
		{
			if(stricmp(alun[i].nome,alun[j].nome)==1)
			{
				aux = alun[i];
				alun[i] = alun[j];
				alun[j] = aux;
			}
		}
	}
}

void ordDisc(disciplinas disc[TFD], int TLD)
{
	int i, j;
	disciplinas aux;
	for(i=0;i<TLD-1;i++)
	{
		for(j=i+1;j<TLD;j++)
		{
			if(stricmp(disc[i].cod,disc[j].cod)==1)
			{
				aux = disc[i];
				disc[i] = disc[j];
				disc[j] = aux;
			}
		}
	}
}

void ordNota(notas nota[TFN], int TLN, alunos alun[TFA], int TLA, disciplinas disc[TFD], int TLD)
{
	notas aux;
	int a, d, n, i;
	for(a=0;a<TLA;a++)
	{
		for(d=0;d<TLD;d++)
		{
			for(n=0;n<TLN;n++)
			{
				i=0;
				while(i<TLN && (strcmp(nota[i].ra,alun[a].ra) != 0 || strcmp(nota[i].cod,disc[d].cod) != 0))
					i++;
				if(i < TLN)
				{
					aux = nota[n];
					nota[n] = nota[i];
					nota[i] = aux;
				}
			}
		}
	}
}

/*

262228130
Gerson Lucas
159753222
Jhow Sanchez
789456123
Gabriel Yuji

b159
ATP II
123
Gestao
456
Ambientes

c262228130
159
4
262228130
123
4
262228130
456
10
789456123
159
10
789456123
123
10
789456123
456
4
159753222
159
4
159753222
123
4
159753222
456
4

*/




//Exclusoes Logicas, Fisicas, Fisicas especificas, relatorios

//terminar

//jhoow
//Consulta, colocar orden nas fim exclu 
//conferir se o codigo ta utilizando todas as busca e ord
//testar codigo por codigo 
#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

struct jogos
{
	int cod;
	char descr[100];
	char status;
};

struct campeonatos
{
	int cod, anoDisputa, codJogo;
	char titulo[100], responsavel[100], descr[250];
	char status;
};

struct participantes
{
	int cod;
	char descr[100];
	char status;
};

struct controles
{
	int codCamp, codPart;
	char nick[100];
	char status;
};

void ir(int &l);
void moldura(void);
void limpar(int &l);

void inicializar(void);

void inserir(void);

char pegaN(int &n);

char menup(void);

char menu2(void);
void menu3(void);
char menu4(void);

void cadastrar(void);
void exibir(void);
void editar (void);
void excluir(void);

void cadJogo(void);
void cadParticipante(void);
void cadCampeonato(void);
void cadControle(void);

void consultJogos(void);
void consultCamp(void);
void consultPart(void);
void consultControle(void);

void relatoJogo(void);
void relatoCamp(void);

void exibJogo(void);
void exibParticipante(void);
void exibCampeonato(void);
void exibControle(void);

void ordenarJogo(void);
void ordenarParticipante(void);
void ordenarParticipanteNome(void);
void ordenarCampeonato(void);
void ordenarControle(void);
void ordenarInserct(void);
void ordenarBolha (void);
void OrdenarDireta(void);
int posMaior(FILE *ptr,int TL);

void editarJogo(void);
void editarPart(void);
void editCamp(void);
void editarControle(void);

int buscaExaustiva(FILE *arq, int cod);
int buscaExaustivaCamp(FILE *arq, int cod);
int buscaIndexadaJogo(FILE *arq, int cod);
int buscaBinariaPart(FILE *arq, int codPart);
int buscaExaustivaControl(FILE *arq, int codCamp, int codPart);
int buscaExaustivaSentCamp(FILE *arq, int cod);

void exclusaoLogicaJogos(void);
void exclusaoLogicaParticipantes(void);
void excLogCamp(void);
void excLogControle(void);
void excFisJog(void);
void excFisPart(void);
void excFisCamp(void);
void excFisContr(void);

void exclusaoFisica(void);

int main (void)
{
	char op,a;
	moldura();
	textcolor(15);
	inicializar();
	
	
	do
	{
		
		op = menup();
		switch(op)
		{
			case '1':
				cadastrar();
				break;
			case '2':
				editar();
				break;
			case '3':
				excluir();
				break;
			case '4':
				exibir();				
				break;
			case '5':
				menu3();				
				break;
			case 'P':
				inserir();
				break;
		}
	} while(op != 27);
	exclusaoFisica();
	return 0;
}

char menup()
{
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** MENU ***");
	
	ir(l); printf("[1] Cadastrar");
	ir(l); printf("[2] Editar");
	ir(l); printf("[3] Excluir");
	ir(l); printf("[4] Relatorios");
	ir(l); printf("[5] Consulta");
	return toupper(getch());
}

char menu2()
{
	int l = 5;
	ir(l); printf("[1] Jogos");
	ir(l); printf("[2] Participantes");
	ir(l); printf("[3] Campeonatos");
	ir(l); printf("[4] Controle de participantes");
	return toupper(getch());
}

void menu3(void)
{
	int l = 5;
	char op;
	do
	{
		limpar(l);
		gotoxy(6,3); printf("*** Consulta ***");
		
		ir(l); printf("[1] Jogos");
		ir(l); printf("[2] Participantes");
		ir(l); printf("[3] Campeonatos");
		ir(l); printf("[4] Controle de participantes");
		op = toupper(getch());
			switch(op)
			{
				case '1':
					consultJogos();
					break;
				case '2':
					consultPart();
					break;
				case '3':
					consultCamp();
					break;
				case '4':
					consultControle();
					break;
			}
	}while (op != 27);
}

char menu4()
{
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** RELATORIO ***");
	
	ir(l); printf("[1] Jogos");
	ir(l); printf("[2] Participantes");
	ir(l); printf("[3] Campeonatos");
	ir(l); printf("[4] Controle de participantes");
	return toupper(getch());
}

void cadJogo(void)
{
	FILE *arq = fopen("jogos.dat", "ab+");
	jogos reg;
	char aux[5];
	int l = 5;
	
	limpar(l);
	gotoxy(6,3); printf("*** Cadastrar jogos ***");
	
	if(arq == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do jogo: ");
		while(pegaN(reg.cod))
		{
			if(buscaExaustiva(arq, reg.cod) == -1)
			{
				ir(l); printf("Nome do jogo: ");
				fflush(stdin);
				gets(reg.descr);
				reg.status = 1;
				fwrite(&reg, sizeof(reg), 1, arq);
				
				fclose(arq);
				OrdenarDireta();
				arq = fopen("jogos.dat", "ab+");
			}
			else
			{
				ir(l); printf("Este codigo de jogo ja existe!");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Cadastrar jogo ***");
			ir(l); printf("Codigo do jogo: ");
			
		}
		fclose(arq);
		
	}
}

int buscaExaustiva(FILE *arq, int cod)
{
	jogos reg;
	
	rewind(arq);
	fread(&reg, sizeof(reg), 1, arq);
	while (!feof(arq) && (cod != reg.cod || reg.status == 0))
		fread(&reg, sizeof(reg), 1, arq);
	if(!feof(arq))
		return ftell(arq) - sizeof(reg);
	else
		return -1;
}

int buscaExaustivaCamp(FILE *arq, int cod)
{
	campeonatos reg;
	
	rewind(arq);
	fread(&reg, sizeof(reg), 1, arq);
	while (!feof(arq) && (cod != reg.cod || reg.status == 0))
		fread(&reg, sizeof(reg), 1, arq);
	if(!feof(arq))
		return ftell(arq) - sizeof(reg);
	else
		return -1;
}


//puxar exclusao logo apos
int buscaExaustivaSentCamp(FILE *arq, int cod)
{
	campeonatos reg;
	FILE *ptr = fopen("campeonatos.dat","ab");
	
	fseek(ptr,0,2);
	reg.cod = cod;
	reg.anoDisputa = 0;
	reg.codJogo = 0;
	strcpy(reg.descr,"A");
	strcpy(reg.responsavel,"A");
	strcpy(reg.titulo,"A");
	reg.status = 0;
	fwrite(&reg,sizeof(campeonatos),1,ptr);
	fclose(ptr);
	
	fseek(arq,0,0);
	fread(&reg, sizeof(campeonatos), 1, arq);
	while (cod != reg.cod )
		fread(&reg, sizeof(campeonatos), 1, arq);
	if(reg.anoDisputa != 0 && reg.status == 1)
		return ftell(arq) - sizeof(campeonatos);
	else
		return -1;
}

int buscaExaustivaControl(FILE *arq, int codCamp, int codPart)
{
	controles reg;
	
	rewind(arq);
	fread(&reg, sizeof(reg), 1, arq);
	while (!feof(arq) && (codCamp != reg.codCamp || codPart != reg.codPart || reg.status == 0))
		fread(&reg, sizeof(reg), 1, arq);
	if(!feof(arq))
		return ftell(arq) - sizeof(reg);
	else
		return -1;
}

int buscaIndexadaJogo(FILE *arq, int cod)
{
	jogos reg;
	
		rewind(arq);
		fread(&reg, sizeof(reg), 1, arq);
		while (!feof(arq) && (cod > reg.cod || reg.status == 0))
			fread(&reg, sizeof(reg), 1, arq);
		if(cod == reg.cod && reg.status == 1)
			return ftell(arq) - sizeof(reg);
		else
			return -1;
}

char pegaN(int &n)
{
	char aux[5];
	
	fflush(stdin);
	gets(aux);
	if(strlen(aux) > 0)
	{
		n = atoi(aux);
		return 1;
	}
	else
		return 0;
}

void cadastrar(void)
{
	char op;
	int l = 5;
	
	do
	{
		limpar(l);
		gotoxy(6,3); printf("*** Cadastrar ***");
		ir(l); printf("[1] Jogos");
		ir(l); printf("[2] Participantes");
		ir(l); printf("[3] Campeonatos");
		ir(l); printf("[4] Controle de participantes");
		op = toupper(getch());
		switch(op)
		{
			case '1':
				cadJogo();
				break;
			case '2':
				cadParticipante();
				break;
			case '3':
				cadCampeonato();
				break;
			case '4':
				cadControle();
				break;
		}
	} while(op != 27);
}

void exibir(void)
{
	char op;
	int i;
	int l = 5;
	
	do
	{
		limpar(l);
		gotoxy(6,3); printf("*** Exibir ***");
		ir(l); printf("[1] Jogos");
		ir(l); printf("[2] Participantes");
		ir(l); printf("[3] Campeonatos");
		ir(l); printf("[4] Controle de participantes");
		ir(l); printf("[5] Relatorio Jogador");
		ir(l); printf("[6] Relatorio Campeonato");
		op = toupper(getch());
		switch(op)
		{
			case '1':
				exibJogo();
				break;
			case '2':
				exibParticipante();
				ordenarBolha();
				break;
			case '3':
				exibCampeonato();
				break;
			case '4':
				exibControle();
				break;
			case '5':
				relatoJogo();
				break;
			case '6':
				relatoCamp();
				break;
		}
	} while(op != 27);
}

void exibJogo(void)
{
	FILE *arq = fopen("jogos.dat", "rb");
	jogos reg;
	int l = 5;
	
	limpar(l);
	gotoxy(6,3); printf("*** Exibir Jogos ***");
	ordenarJogo();
	if(arq == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
	}
	else
	{
		fread(&reg,sizeof(jogos),1,arq);
		if(!feof(arq))
			while(!feof(arq))
			{
				if(reg.status == 1)
				{
					ir(l); printf("Codigo: %d, Nome: %s",reg.cod,reg.descr);
				}
				fread(&reg,sizeof(jogos),1,arq);
			}
		else
		{
			ir(l); printf("Vazio!");
		}
		
		fclose(arq);
	}
	getch();
}

void exibCampeonato(void)
{
	FILE *arq = fopen("campeonatos.dat", "rb"), *ptrAux = fopen("jogos.dat", "rb");
	campeonatos reg;
	jogos regAux;
	bool flag = true;
	int l = 5;
	
	limpar(l);
	gotoxy(6,3); printf("*** Exibir Campeonatos ***");
	
	ordenarCampeonato();
	if(arq == NULL || ptrAux == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
	}
	else
	{
		ir(l); printf("--------------------------------------------------------------------------------------------------------------");
		fread(&reg,sizeof(reg),1,arq);
		while(!feof(arq))
		{
			if(reg.status == 1)
			{
				fseek(ptrAux, buscaExaustiva(ptrAux,reg.codJogo), 0);
				fread(&regAux, sizeof(regAux), 1, ptrAux);
				ir(l); printf("Codigo: %d, Titulo: %s,",reg.cod,reg.titulo);
				ir(l); printf("Jogo: %s, Ano: %d, Responsavel: %s,",regAux.descr,reg.anoDisputa,reg.responsavel);
				ir(l); printf("Descricao: %s",reg.descr);
				ir(l); printf("--------------------------------------------------------------------------------------------------------------");
				flag = false;
			}
			fread(&reg,sizeof(reg),1,arq);
		}
		if(flag)
		{
			ir(l); printf("Vazio!");
		}
		
		fclose(arq);
		fclose(ptrAux);
	}
	getch();
}

void exibParticipante(void)
{
	FILE *arq = fopen("participantes.dat", "rb");
	participantes reg;
	int l = 5;
	
	ordenarBolha();
	limpar(l);
	gotoxy(6,3); printf("*** Exibir Participantes ***");
	
	if(arq == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
	}
	else
	{
		fread(&reg,sizeof(reg),1,arq);
		if(!feof(arq))
			while(!feof(arq))
			{
				if(reg.status == 1)
				{
				
					ir(l); printf("Codigo: %d, Nome: %s",reg.cod,reg.descr);
				}
//				ir(l); printf("Codigo: %d, Nome: %s, Status: ""%d""",reg.cod,reg.descr,reg.status);
				fread(&reg,sizeof(reg),1,arq);
			}
		else
		{	
			ir(l); printf("Vazio!");
		}
		fclose(arq);
	}
	getch();
}

void exibControle(void)
{
	FILE *arq = fopen("controles.dat", "rb");
	controles reg;
	int l = 5;
	
	limpar(l);
	gotoxy(6,3); printf("*** Exibir Nicknames ***");
	
	ordenarControle();
	if(arq == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
	}
	else
	{
		fread(&reg,sizeof(reg),1,arq);
		if(!feof(arq))
			while(!feof(arq))
			{
				if(reg.status == 1)
				{
					ir(l); printf("Codigo do campeonato: %d, Codigo do participante: %d, Nome: %s",reg.codCamp,reg.codPart,reg.nick);
				}
					
				fread(&reg,sizeof(reg),1,arq);
			}
		else
		{
			ir(l); printf("Vazio!");
		}
		
		fclose(arq);
	}
	getch();
}

void cadParticipante(void)
{
	FILE *ptr = fopen("participantes.dat", "ab+");
	participantes reg;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Cadastrar participante ***");
	
	if(ptr == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do Participante: ");
		while(pegaN(reg.cod))
		{
			fclose(ptr);
			ordenarBolha();	
			ptr = fopen("participantes.dat","ab+");
			
			if(buscaBinariaPart(ptr, reg.cod) == -1)
			{
				ir(l); printf("Nome do Participante: ");
				fflush(stdin);
				gets(reg.descr);
				reg.status = 1;
				fseek(ptr,0,2);
				fwrite(&reg, sizeof(participantes), 1, ptr);
			
				fclose(ptr);
				ordenarBolha();			
				ptr = fopen("participantes.dat", "ab+");
			}
			else
			{
				ir(l); printf("Este codigo ja existe!");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Cadastrar participante ***");
			ir(l); printf("Codigo do participante: ");
		}
		fclose(ptr);
	}
}

void cadCampeonato(void)
{
	FILE *ptr = fopen("campeonatos.dat", "ab+"), *ptrJogo = fopen("jogos.dat","rb");
	campeonatos reg;
	int pos;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Cadastrar Campeonato ***");
	
	if(ptr == NULL || ptrJogo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do Campeonato: ");
		while(pegaN(reg.cod))
		{
			if(buscaExaustivaSentCamp(ptr, reg.cod) == -1)
			{
				fclose(ptr);
				excFisCamp();
				ptr = fopen("campeonatos.dat","ab+");
				
				ir(l); printf("Codigo do jogo: ");
				fflush(stdin);
				pegaN(reg.codJogo);
				if(buscaIndexadaJogo(ptrJogo,reg.codJogo) == -1)
				{
					ir(l); printf("Jogo inexistente!");
					getch();
				}
				else
				{
					ir(l); printf("Titulo: ");
					fflush(stdin);
					gets(reg.titulo);
					ir(l); printf("Responsavel: ");
					fflush(stdin);
					gets(reg.responsavel);
					ir(l); printf("Ano da disputa: ");
					scanf("%d", &reg.anoDisputa);
					ir(l); printf("Descricao: ");
					fflush(stdin);
					gets(reg.descr);
					reg.status = 1;
					fwrite(&reg, sizeof(reg), 1, ptr);
					
					fclose(ptr);
					fclose(ptrJogo);
					
					ordenarInserct();
					
					ptr = fopen("campeonatos.dat", "ab+");
					ptrJogo = fopen("jogos.dat","rb");				
				}
			}
			else
			{
				ir(l); printf("Este codigo ja existe!");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Cadastrar Campeonato ***");
			ir(l); printf("Codigo do Campeonato: ");
		}
		fclose(ptr);
		fclose(ptrJogo);
		//OrdenarDireta();
	}
}

void cadControle(void)
{
	FILE *ptr = fopen("controles.dat", "ab+");
	FILE *arqCamp = fopen("campeonatos.dat","ab+");
	FILE *arqPart = fopen("participantes.dat","ab+");
	controles reg;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Cadastrar Nicknames ***");
	
	if(ptr == NULL || arqCamp == NULL || arqPart == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do Campeonato: ");
		while(pegaN(reg.codCamp))
		{
			if(buscaExaustivaCamp(arqCamp,reg.codCamp) >= 0)
			{
				ir(l); printf("Codigo do Participante: ");
				pegaN(reg.codPart);
				if(buscaBinariaPart(arqPart, reg.codPart) == -1)
				{
					ir(l); printf("Codigo nao encontrado!");
					getch();
				}
				else
				{
					if(buscaExaustivaControl(ptr ,reg.codCamp, reg.codPart) == -1)
					{
						ir(l); printf("Nickname: ");
						fflush(stdin);
						gets(reg.nick);
						reg.status = 1;
						fwrite(&reg, sizeof(reg), 1, ptr);
					}
					else
					{
						ir(l); printf("Nickname ja cadastrado!");
						getch();
					}
				}
			}
			else
			{
				ir(l); printf("Codigo nao encontrado!");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Cadastrar Nickname ***");
			ir(l); printf("Codigo do Campeonato: ");
		}
		fclose(ptr);
		fclose(arqCamp);
		fclose(arqPart);
		ordenarControle();
	}
}

void inicializar(void)
{
	FILE *arq1 = fopen("jogos.dat","ab");
	FILE *arq2 = fopen("participantes.dat","ab");
	FILE *arq3 = fopen("campeonatos.dat","ab");
	FILE *arq4 = fopen("controles.dat","ab");
	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
	fclose(arq4);
}

void ordenarJogo(void)
{
	FILE *arq = fopen("jogos.dat","rb+");
	jogos reg1, reg2;
	int i, j, fim;
	int l = 5;
	if(arq != NULL)
	{
		fseek(arq, 0, 2);
		fim = ftell(arq)/sizeof(reg1);
		for(i=0;i<fim-1;i++)
		{
			for(j=i+1;j<fim;j++)
			{
				fseek(arq,i*sizeof(reg1),0);
				fread(&reg1,sizeof(reg1),1,arq);
				fseek(arq,j*sizeof(reg2),0);
				fread(&reg2,sizeof(reg2),1,arq);
				if(reg1.cod > reg2.cod || reg1.status == 0 && reg2.status)
				{
					fseek(arq,i*sizeof(reg1),0);
					fwrite(&reg2,sizeof(reg2),1,arq);
					fseek(arq,j*sizeof(reg2),0);
					fwrite(&reg1,sizeof(reg1),1,arq);
				}
			}
		}
		fclose(arq);
	}
	else
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
}

void ordenarParticipante(void)
{
	FILE *arq = fopen("participantes.dat","rb+");
	participantes reg1, reg2;
	int i, j, fim;
	int l = 5;
	if(arq != NULL)
	{
		fseek(arq, 0, 2);
		fim = ftell(arq)/sizeof(reg1);
		for(i=0;i<fim-1;i++)
		{
			for(j=i+1;j<fim;j++)
			{
				fseek(arq,i*sizeof(reg1),0);
				fread(&reg1,sizeof(reg1),1,arq);
				fseek(arq,j*sizeof(reg2),0);
				fread(&reg2,sizeof(reg2),1,arq);
				if(reg1.cod > reg2.cod || reg1.status == 0 && reg2.status == 1)
				{
					fseek(arq,i*sizeof(reg1),0);
					fwrite(&reg2,sizeof(reg2),1,arq);
					fseek(arq,j*sizeof(reg2),0);
					fwrite(&reg1,sizeof(reg1),1,arq);
				}
			}
		}
		fclose(arq);
	}
	else
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
}

//inserction 
void ordenarInserct(void)
{
	FILE *ptr = fopen("campeonatos.dat","rb+");
	campeonatos reg1, reg2;
	int pos,i,j;
	
	fseek(ptr,0,2);
	i = ftell(ptr)/sizeof(campeonatos)-1;
	if(i > 0)
	{
		fseek(ptr,(i-1)*sizeof(campeonatos),0);
		fread(&reg1,sizeof(campeonatos),1,ptr);
		fread(&reg2,sizeof(campeonatos),1,ptr);
		
		if(reg1.cod > reg2.cod)
		{
			fseek(ptr,(i-1)*sizeof(campeonatos),0);
			fwrite(&reg2,sizeof(campeonatos),1,ptr);
			
			fseek(ptr,i*sizeof(campeonatos),0);
			fwrite(&reg1,sizeof(campeonatos),1,ptr);	
		}
		i--;
	}
	while(i > 0 && reg1.cod > reg2.cod)
	{
		fseek(ptr,(i-1)*sizeof(campeonatos),0);
		fread(&reg1,sizeof(campeonatos),1,ptr);
		fread(&reg2,sizeof(campeonatos),1,ptr);
		if(reg1.cod > reg2.cod)
		{
			fseek(ptr,(i-1)*sizeof(campeonatos),0);
			fwrite(&reg2,sizeof(campeonatos),1,ptr);
			
			fseek(ptr,i*sizeof(campeonatos),0);
			fwrite(&reg1,sizeof(campeonatos),1,ptr);	
		}
		i--;			
	}	
	fclose(ptr);
}

void ordenarBolha (void)
{
	FILE *ptr = fopen("participantes.dat","rb+");
	participantes reg1,reg2;
	int qntd,i;
	
	fseek(ptr,0,2);
	qntd = ftell(ptr) / sizeof(participantes);
	fseek(ptr,0,0);
	
	while(qntd > 1 )
	{	
		for(i=0;i<qntd-1;i++)
		{	
			fseek(ptr,i*sizeof(participantes),0);
			fread(&reg1,sizeof(participantes),1,ptr);
			fread(&reg2,sizeof(participantes),1,ptr);
			
			if(reg1.cod > reg2.cod && reg2.status || !reg1.status)
			{	
				fseek(ptr,i*sizeof(participantes),0);
				fwrite(&reg2,sizeof(participantes),1,ptr);
				fwrite(&reg1,sizeof(participantes),1,ptr);
			}			
		}
		qntd--;
	}
	fclose(ptr);
}

void ordenarCampeonato(void)
{
	FILE *arq = fopen("campeonatos.dat","rb+");
	campeonatos reg1, reg2;
	int i, j, fim;
	
		fseek(arq, 0, 2);
		fim = ftell(arq)/sizeof(reg1);
		for(i=0;i<fim-1;i++)
		{
			for(j=i+1;j<fim;j++)
			{
				fseek(arq,i*sizeof(reg1),0);
				fread(&reg1,sizeof(reg1),1,arq);
				fseek(arq,j*sizeof(reg2),0);
				fread(&reg2,sizeof(reg2),1,arq);
				if(reg1.cod > reg2.cod || reg1.status == 0 && reg2.status == 1)
				{
					fseek(arq,i*sizeof(reg1),0);
					fwrite(&reg2,sizeof(reg2),1,arq);
					fseek(arq,j*sizeof(reg2),0);
					fwrite(&reg1,sizeof(reg1),1,arq);
				}
			}
		}
		fclose(arq);
}

void ordenarControle(void)
{
	FILE * ptr = fopen ("control.dat","rb+");

    int x,y,qtd,d=3,l=5;
    controles reg1, reg2;

    if(ptr == NULL)
    {
        ir(l); printf("ERRO AO ABRIR O ARQUIVO");
    }
    else
    {
        fseek(ptr,0,2);
        qtd = ftell(ptr)/sizeof(controles);
        while(qtd > 1)
        {

            for(y = x+1; y<qtd; y++)
            {
                fseek(ptr, x*sizeof(controles),0);
                fread(&reg1,sizeof(controles),1,ptr);

                fseek(ptr, y*sizeof(controles),0);
                fread(&reg2, sizeof(controles),1,ptr);

                if(reg1.codCamp > reg2.codCamp)
                {
                    fseek(ptr, x*sizeof(controles),0);
                    fwrite(&reg2, sizeof(controles),1,ptr);

                    fseek(ptr, y*sizeof(controles),0);
                    fwrite(&reg1, sizeof(controles),1,ptr);

                }
            }
            qtd--;
        }
        fclose(ptr);
    }
}

int buscaBinariaPart(FILE *arq, int codPart)
{
	participantes reg;
	int inicio=0,meio,fim;
	
	fseek(arq,0,2);
	
	fim = ftell(arq)/sizeof(participantes)-1;
	meio = fim/2;
	
	fseek(arq,meio*sizeof(participantes),0);
	fread(&reg,sizeof(participantes),1,arq);
	
	while(fim > inicio && (reg.cod != codPart || reg.status == 0))
	{
		if (reg.cod > codPart )
			fim = meio-1;
		else
			inicio = meio+1;
		
		meio = (inicio+fim)/2;
		fseek(arq,meio*sizeof(participantes),0);
		fread(&reg,sizeof(participantes),1,arq);
	}
	if(reg.cod == codPart && reg.status == 1)
		return meio * sizeof(participantes);
	else
		return -1;
}

void editar (void)
{
	char op;
	int i;
	int l = 5;
	do
	{
		limpar(l);
		gotoxy(6,3); printf("*** Editar ***");
		ir(l); printf("[1] Jogos");
		ir(l); printf("[2] Participantes");
		ir(l); printf("[3] Campeonatos");
		ir(l); printf("[4] Controle de participantes");
		op = toupper(getch());
		switch(op)
		{
			case '1':
				editarJogo();
				break;
			case '2':
				editarPart();
				break;
			case '3':
				editCamp();
				break;
			case '4':
				editarControle();
				break;
		}
	} while(op != 27);
}

void editarJogo()
{
	char op;
	int pos;
	FILE *arq = fopen("jogos.dat","rb+");
	jogos reg;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Editar Jogos ***");
	ir(l); printf("Codigo do jogo: ");
	if(arq == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo");
		getch();
	}
	else
	{
		while(pegaN(reg.cod))
		{
			pos = buscaExaustiva(arq,reg.cod);
			if(pos == -1)
			{
				ir(l); printf("Jogo nao encontrado!");
				getch();
			}
			else
			{
				fseek(arq,pos,0);
				fread(&reg,sizeof(reg),1,arq);
				ir(l); printf("Deseja realmente alterar o nome (%s) SIM (S) ou NAO (N)",reg.descr);
				do
				{
					op = toupper(getch());
				} while(op != 'N' && op != 'S' && op != 27);
				if(op == 'S')
				{
					limpar(l);
					gotoxy(6,3); printf("*** Editar Jogos ***");
					ir(l); printf("Nome: ");
					fflush(stdin);
					gets(reg.descr);
					fseek(arq,pos,0);
					fwrite(&reg,sizeof(reg),1,arq);
					ir(l); printf("Nome alterado!");
					getch();
				}
			}
			limpar(l);
			gotoxy(6,3); printf("*** Editar Jogos ***");
			ir(l); printf("Codigo do jogo: ");
		}
		fclose(arq);
	}
}

void editarPart()
{
	char op;
	int pos;
	FILE *arq = fopen("participantes.dat","rb+");
	participantes reg;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Editar Participantes ***");
	ir(l); printf("Codigo do participante: ");
	if(arq == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo");
		getch();
	}
	else
	{
		while(pegaN(reg.cod))
		{
			pos = buscaExaustiva(arq,reg.cod);
			if(pos == -1)
			{
				ir(l); printf("Jogo nao encontrado!");
				getch();
			}
			else
			{
				fseek(arq,pos,0);
				fread(&reg,sizeof(reg),1,arq);
				ir(l); printf("Deseja realmente alterar o nome (%s) SIM (S) ou NAO (N)",reg.descr);
				do
				{
					op = toupper(getch());
				} while(op != 'N' && op != 'S' && op != 27);
				if(op == 'S')
				{
					limpar(l);
					gotoxy(6,3); printf("*** Editar Jogos ***");
					ir(l); printf("Nome: ");
					fflush(stdin);
					gets(reg.descr);
					fseek(arq,pos,0);
					fwrite(&reg,sizeof(reg),1,arq);
					ir(l); printf("Nome alterado!");
					getch();
				}
			}
			limpar(l);
			gotoxy(6,3); printf("*** Editar Participantes ***");
			ir(l); printf("Codigo do participante: ");
		}
		fclose(arq);
	}
}

void editarControle(void)
{
	FILE *ptr = fopen("controles.dat", "rb+"), *ptrCamp = fopen("campeonatos.dat","rb");
	controles reg;
	int pos;
	char op;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Editar Controle ***");
	
	if(ptr == NULL || ptrCamp == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do Campeonato: ");
		while(pegaN(reg.codCamp))
		{
			if(buscaExaustivaCamp(ptrCamp, reg.codCamp) >= 0)
			{
				ir(l); printf("Codigo do Participante: ");
				pegaN(reg.codPart);
				pos = buscaExaustivaControl(ptr, reg.codCamp, reg.codPart);
				if(pos == -1)
				{
					ir(l); printf("Codigos nao encontrado!");
					getch();
				}
				else
				{
					fseek(ptr, pos, 0);
					fread(&reg, sizeof(reg), 1, ptr);
					ir(l); printf("Deseja realmente alterar o controle: %s? [S] SIM ou [N] NAO",reg.nick);
					do
					{
						op = toupper(getch());
					} while(op != 'N' && op != 'S' && op != 27);
					if(op == 'S')
					{
						limpar(l);
						gotoxy(6,3); printf("*** Editar Controle ***");
						ir(l); printf("Nick: ");
						gets(reg.nick);
						fseek(ptr, pos, 0);
						fwrite(&reg, sizeof(reg), 1, ptr);
					}
				}
			}
			else
			{
				ir(l); printf("Codigo Inexistente!");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Editar Controle ***");
			ir(l); printf("Codigo do Campeonato: ");
		}
		fclose(ptr);
		fclose(ptrCamp);
	}
}

void editCamp(void)
{
	FILE *ptr = fopen("campeonatos.dat","rb+"), *ptrJogo;
	campeonatos reg;
	jogos regJogo;
	char op,aux1;
	int aux,aux2,aux3,pos;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Editar Campeonato ***");
	if(ptr == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getche();
	}
	else
	{
		ir(l); printf("Codigo do Campeonato: ");
			while(pegaN(reg.cod))
			{
				aux = buscaExaustivaCamp(ptr, reg.cod);
				if(aux >= 0)
				{
					fseek(ptr,aux,0);  //Posiciona o ponteiro para fazer a alteracao
					fread(&reg,sizeof(campeonatos),1,ptr);//le a posicao do ponteiro e se prepara para fazer alteracao
					do{
						limpar(l);
						gotoxy(6,3); printf("*** Editar Campeonato ***");
						ir(l); printf("[1] Titulo");
						ir(l); printf("[2] Responsavel");
						ir(l); printf("[3] Ano da disputa");
						ir(l); printf("[4] Descricao");
						ir(l); printf("[5] Tipo Jogo");
						op = toupper(getch());
						switch(op)
						{
							case '1':
								limpar(l);
								gotoxy(6,3); printf("*** Editar Campeonato ***");
								ir(l); printf("Deseja realmente alterar o Titulo %s? [S] SIM ou [N] NAO",reg.titulo);
								aux1=toupper(getch());
								if(aux1 == 'S')
								{
									limpar(l);
									gotoxy(6,3); printf("*** Editar Campeonato ***");
									ir(l); printf("Informe o novo titulo: ");
									fflush(stdin);
									gets(reg.titulo);
									ir(l); printf("Alterado com sucesso!!!");
									getche();
								}
								break;
							case '2':
								limpar(l);
								gotoxy(6,3); printf("*** Editar Campeonato ***");
								ir(l); printf("Deseja realmente alterar o Responsavel %s? [S] SIM ou [N] NAO",reg.responsavel);
								aux1=toupper(getch());
								if(aux1=='S')
								{
									limpar(l);
									gotoxy(6,3); printf("*** Editar Campeonato ***");
									ir(l); printf("Responsavel: ");
									fflush(stdin);
									gets(reg.responsavel);
									ir(l); printf("Alterado com sucesso!!!");
									getche();
								}
								break;
							case '3':
								limpar(l);
								gotoxy(6,3); printf("*** Editar Campeonato ***");
								ir(l); printf("Deseja realmente alterar o Ano da Disputa %d? [S] SIM ou [N] NAO",reg.anoDisputa);
								aux1=toupper(getch());
								if(aux1=='S')
								{
									limpar(l);
									gotoxy(6,3); printf("*** Editar Campeonato ***");
									ir(l); printf("Ano da Disputa: ");
									pegaN(reg.anoDisputa);
									ir(l); printf("Alterado com sucesso!!!");
									getche();
								}
								break;
							case '4':
								limpar(l);
								gotoxy(6,3); printf("*** Editar Campeonato ***");
								ir(l); printf("Deseja realmente alterar a Descricao %s? [S] SIM ou [N] NAO",reg.descr);
								aux1=toupper(getch());
								if(aux1=='S')
								{
									limpar(l);
									gotoxy(6,3); printf("*** Editar Campeonato ***");
									ir(l); printf("Descricao: ");
									fflush(stdin);
									gets(reg.descr);
									ir(l); printf("Alterado com sucesso!!!");
									getche();
								}
								break;	
							case '5':
								limpar(l);
								gotoxy(6,3); printf("*** Editar Campeonato ***");
								ptrJogo = fopen("jogos.dat","rb");
								aux3 = buscaExaustiva(ptrJogo,reg.cod);
								fseek(ptrJogo, aux3, 0);
								fread(&regJogo,sizeof(regJogo),1,ptrJogo);
								ir(l); printf("Deseja realmente alterar o Jogo %s? [S] SIM ou [N] NAO",regJogo.descr);
								aux1 = toupper(getch());
								if(aux1 == 'S')
								{
									limpar(l);
									gotoxy(6,3); printf("*** Editar Campeonato ***");
									ir(l); printf("Codigo do jogo: ");
									pegaN(aux3);
									pos = buscaExaustiva(ptrJogo, aux3);
									if(pos == -1)
									{
										limpar(l);
										gotoxy(6,3); printf("*** Editar Campeonato ***");
										ir(l); printf("Jogo inexistente!");
										getch();
									}
									else
									{
										limpar(l);
										gotoxy(6,3); printf("*** Editar Campeonato ***");
										reg.cod = aux3;
										ir(l); printf("Alterado com sucesso!");
										getch();
									}
								}
								fclose(ptrJogo);
								break;
						}
					}while(op != 27);
					fseek(ptr,aux,0);
					fwrite(&reg,sizeof(campeonatos),1,ptr);
				}
				else
				{
					limpar(l);
					gotoxy(6,3); printf("*** Editar Campeonato ***");
					ir(l); printf("Codigo nao encontrado!!!");
					getche();
				}
				limpar(l);
				gotoxy(6,3); printf("*** Editar Campeonato ***");
				ir(l); printf("Informe o codigo do campeonato: ");
			}
		fclose(ptr);
	}	
}

void excluir(void)
{
	char op1, op2;
	int l = 5;
	do
	{
		limpar(l);
		gotoxy(6,3); printf("*** Excluir ***");
		ir(l); printf("[1] Jogos");
		ir(l); printf("[2] Participantes");
		ir(l); printf("[3] Campeonatos");
		ir(l); printf("[4] Controle de participantes");
		op1 = toupper(getch());
		switch(op1)
		{
			case '1':
				exclusaoLogicaJogos();
				break;
			case '2':
				exclusaoLogicaParticipantes();
				break;
			case '3':
				excLogCamp();
				break;
			case '4':
				excLogControle();
				break;
		}
	} while(op1 != 27);
}

void exclusaoLogicaJogos(void)
{
	int a, b;
	char op;
	int pos;
	FILE *arq = fopen("jogos.dat","rb+"), *arqCamp = fopen("campeonatos.dat","rb+"), *arqCont = fopen("controles.dat","rb+");
	jogos reg;
	campeonatos regCamp;
	controles regCont;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Exclusao logica Jogos ***");
	if(arq == NULL || arqCamp == NULL || arqCont == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do jogo: ");
		while(pegaN(reg.cod))
		{
			pos = buscaExaustiva(arq,reg.cod);
			if(pos == -1)
			{
				ir(l); printf("Jogo nao encontrado!");
				getch();
			}
			else
			{
				fseek(arq,pos,0);
				fread(&reg,sizeof(reg),1,arq);
				ir(l); printf("Deseja realmente EXCLUIR o jogo (%s) SIM (S) ou NAO (N)",reg.descr);
				ir(l); printf("Excluir esse jogo também ira excluir campeonatos cadastrados com esse jogo!");
				do
				{
					op = toupper(getch());
				} while(op != 'N' && op != 'S' && op != 27);
				if(op == 'S')
				{
					limpar(l);
					gotoxy(6,3); printf("*** Exclusao logica Jogos ***");
					reg.status = 0;
					fseek(arq,pos,0);
					fwrite(&reg,sizeof(reg),1,arq);
					
					arqCamp = fopen("campeonatos.dat","rb+");
					fread(&regCamp,sizeof(regCamp),1,arqCamp);
					while(!feof(arqCamp))
					{
						if(regCamp.codJogo == reg.cod)
						{
							a = ftell(arqCamp);
							regCamp.status = 0;
							fseek(arqCamp,ftell(arqCamp)-sizeof(regCamp),0);
							fwrite(&regCamp,sizeof(regCamp),1,arqCamp);
							fseek(arqCamp, a, 0);
							
							fread(&regCont,sizeof(regCont),1,arqCont);
							while(!feof(arqCont))
							{
								if(regCont.codCamp == regCamp.cod)
								{
									b = ftell(arqCont);
									regCont.status = 0;
									fseek(arqCont,ftell(arqCont)-sizeof(regCont),0);
									fwrite(&regCont,sizeof(regCont),1,arqCont);
									fseek(arqCont, b, 0);
								}
								fread(&regCont,sizeof(regCont),1,arqCont);
							}
						}
						fread(&regCamp,sizeof(regCamp),1,arqCamp);
					}
					
					ir(l); printf("Jogo excluido!");
					getch();
				}
			}
			limpar(l);
			gotoxy(6,3); printf("*** Exclusao logica Jogos ***");
			ir(l); printf("Codigo do jogo: ");
		}
		fclose(arq);
		fclose(arqCamp);
		fclose(arqCont);
		ordenarJogo();
	}
}

void exclusaoLogicaParticipantes(void)
{
	int a;
	char op;
	int pos;
	FILE *arq = fopen("participantes.dat","rb+"), *arqAux;
	participantes reg;
	controles regAux;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Exclusao logica Participantes ***");
	if(arq == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do participante: ");
		while(pegaN(reg.cod))
		{
			pos = buscaExaustiva(arq,reg.cod);
			if(pos == -1)
			{
				ir(l); printf("Participante nao encontrado!");
				getch();
			}
			else
			{
				fseek(arq,pos,0);
				fread(&reg,sizeof(reg),1,arq);
				ir(l); printf("Deseja realmente EXCLUIR o participante (%s) SIM (S) ou NAO (N)",reg.descr);
				ir(l); printf("Excluir esse participante também ira excluir controles cadastrados com esse participante!");
				do
				{
					op = toupper(getch());
				} while(op != 'N' && op != 'S' && op != 27);
				if(op == 'S')
				{
					limpar(l);
					gotoxy(6,3); printf("*** Exclusao logica Participantes ***");
					reg.status = 0;
					fseek(arq,pos,0);
					fwrite(&reg,sizeof(reg),1,arq);
					
					arqAux = fopen("controles.dat","rb+");
					fread(&regAux,sizeof(regAux),1,arqAux);
					while(!feof(arqAux))
					{
						if(regAux.codPart == reg.cod)
						{
							a = ftell(arqAux);
							regAux.status = 0;
							fseek(arqAux,ftell(arqAux)-sizeof(regAux),0);
							fwrite(&regAux,sizeof(regAux),1,arqAux);
							fseek(arqAux, a, 0);
						}
						fread(&regAux,sizeof(regAux),1,arqAux);
					}
					fclose(arqAux);
					
					ir(l); printf("Participante excluido!");
					getch();
				}
			}
			limpar(l);
			gotoxy(6,3); printf("*** Exclusao logica Participantes ***");
			ir(l); printf("Codigo do participante: ");
		}
		fclose(arq);
		ordenarBolha();
	}
}

void excLogControle(void)
{
	FILE *ptr = fopen("controles.dat","rb+");
	controles reg;
	char op;
	int aux,aux1,pos;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Excluir Controle ***");
	ir(l); printf("Informe o codigo do Campeonato: ");
	while(pegaN(aux) == 1)
	{
		ir(l); printf("Informe o codigo do Participante: ");
		pegaN(aux1);	
		pos=buscaExaustivaControl(ptr,aux,aux1);
		if(pos >= 0)
		{
			fseek(ptr, pos, 0);
			fread(&reg, sizeof(reg),1,ptr);
			ir(l); printf("Deseja realmente excluir '%s'?  [S] SIM ou [N] NAO", reg.nick);	
			op = toupper(getche());
			if(op == 'S')
			{
				reg.status = 0;
				fseek(ptr, pos, 0);
				fwrite(&reg,sizeof(reg),1,ptr);
				ir(l); printf("Excluido com sucesso!!!");
				getch();
			}
		}
		else
		{
			ir(l); printf("Nao foi encontrando!!!");
			getch();
		}
		limpar(l);
		gotoxy(6,3); printf("*** Excluir Controle ***");
		ir(l); printf("Informe o codigo do Campeonato: ");
	}
	fclose(ptr);
	ordenarControle();
}

void excLogCamp(void)
{
	int i;
	FILE *ptr = fopen("campeonatos.dat","rb+");
	FILE *ptrCont = fopen("controles.dat","rb+");
	campeonatos reg;
	controles regCont;
	char op;
	int aux,aux1,pos;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Exclusao Campeonato ***");
	ir(l); printf("Informe o codigo do Campeonato: ");
	while(pegaN(aux) == 1)
	{
		pos = buscaExaustivaCamp(ptr, aux);
		if(pos >= 0)
		{
			fseek(ptr, pos, 0);
			fread(&reg, sizeof(reg),1,ptr);
			ir(l); printf("Deseja realmente excluir '%s'?  [S] SIM ou [N] NAO", reg.titulo);	
			ir(l); printf("Excluir esse campeonato também ira excluir controles cadastrados com esse campeonato!");
			op = toupper(getch());
			if(op == 'S')
			{
				reg.status = 0;
				fseek(ptr, pos, 0);
				fwrite(&reg,sizeof(reg),1,ptr);
				
				i=0;
				fseek(ptrCont,sizeof(regCont)*i,0);
				fread(&regCont,sizeof(regCont),1,ptrCont);
				while(!feof(ptrCont))
				{
					if(reg.cod == regCont.codCamp)
					{
						regCont.status = 0;
						fseek(ptrCont,sizeof(regCont)*i,0);
						fwrite(&regCont,sizeof(regCont),1,ptrCont);
					}
					i++;
					fseek(ptrCont,sizeof(regCont)*i,0);
					fread(&regCont,sizeof(regCont),1,ptrCont);
				}
				
				ir(l); printf("Excluido com sucesso!");
				getch();
			}
		}
		else
		{
			ir(l); printf("Nao foi encontrando!");
			getch();
		}
		limpar(l);
		gotoxy(6,3); printf("*** Exclusao Campeonato ***");
		ir(l); printf("Informe o codigo do Campeonato: ");
	}
	fclose(ptrCont);
	fclose(ptr);
	ordenarCampeonato();
}

void OrdenarDireta(void)
{
	FILE *ptr = fopen("jogos.dat","rb+");
	jogos reg,maior;
	int posMaior1,tl,i=0;
	
	fseek(ptr,0,2);
	tl = ftell(ptr)/sizeof(jogos);
	
	while(tl>0)
	{
		posMaior1 = posMaior(ptr,tl);
		if(posMaior1 < tl-1)
		{	
			//AUXILIAR RECEBENDO
			fseek(ptr,posMaior1*sizeof(jogos),0);
			fread(&maior,sizeof(jogos),1,ptr);
				
			//REGISTRO RECEBE O BGL TODO E POKAS
			fseek(ptr,(tl-1)*sizeof(jogos),0);
			fread(&reg,sizeof(jogos),1,ptr);
			
			fseek(ptr,posMaior1*sizeof(jogos),0);
			fwrite(&reg,sizeof(jogos),1,ptr);
			
			fseek(ptr,(tl-1)*sizeof(jogos),0);
			fwrite(&maior,sizeof(jogos),1,ptr);	
		}
		tl--;
	}
	fclose(ptr);
}

int posMaior(FILE *ptr, int TL)
{
	int posMaior, maior,i=0;
	jogos Reg;
	
	fseek(ptr,0,0);
	posMaior = 0;
	maior = 0;
	
	fread(&Reg,sizeof(jogos),1,ptr);
	while(i<TL)
	{
		if(maior < Reg.cod )
		{
			maior = Reg.cod;
			posMaior = ftell(ptr)/sizeof(jogos) - 1;
		}
		fread(&Reg,sizeof(jogos),1,ptr);
	i++;
	}
	
	return posMaior;
}
void excFisJog(void)
{
	FILE *ptr = fopen("jogos.dat","rb"), *ptrNovo = fopen("novo.dat","ab");
	jogos regJogo;
	int l = 5;
	
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regJogo,sizeof(regJogo),1,ptr);
		while(!feof(ptr))
		{
			if(regJogo.status == 1)
				fwrite(&regJogo,sizeof(regJogo),1,ptrNovo);
			fread(&regJogo,sizeof(regJogo),1,ptr);
		}
		fclose(ptr);
		remove("jogos.dat");
		fclose(ptrNovo);
		rename("novo.dat","jogos.dat");
		OrdenarDireta();
	}
}

void excFisPart(void)
{
	FILE *ptr = fopen("participantes.dat","rb");
	FILE *ptrNovo = fopen("novo.dat","ab");
	participantes regPart;
	int l = 5;
	
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regPart,sizeof(regPart),1,ptr);
		while(!feof(ptr))
		{
			if(regPart.status == 1)
				fwrite(&regPart,sizeof(regPart),1,ptrNovo);
			fread(&regPart,sizeof(regPart),1,ptr);
		}
		fclose(ptr);
		remove("participantes.dat");
		fclose(ptrNovo);
		rename("novo.dat","participantes.dat");
		ordenarBolha();
	}
	
}

void excFisCamp(void)
{
	FILE *ptr = fopen("campeonatos.dat","rb");
	FILE *ptrNovo = fopen("novo.dat","ab");
	campeonatos regCamp;
	int l = 5;
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regCamp,sizeof(regCamp),1,ptr);
		while(!feof(ptr))
		{
			if(regCamp.status == 1)
				fwrite(&regCamp,sizeof(regCamp),1,ptrNovo);
			fread(&regCamp,sizeof(regCamp),1,ptr);
		}
		fclose(ptr);
		remove("campeonatos.dat");
		fclose(ptrNovo);
		rename("novo.dat","campeonatos.dat");	
		ordenarCampeonato();
	}	
}

void excFisContr(void)
{
	FILE *ptr = fopen("controles.dat","rb");
	FILE *ptrNovo = fopen("novo.dat","ab");
	controles regCont;
	int l = 5;
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regCont,sizeof(regCont),1,ptr);
		while(!feof(ptr))
		{
			if(regCont.status == 1)
				fwrite(&regCont,sizeof(regCont),1,ptrNovo);
			fread(&regCont,sizeof(regCont),1,ptr);
		}
		fclose(ptr);
		remove("controles.dat");
		fclose(ptrNovo);
		rename("novo.dat","controles.dat");
		ordenarControle();
	}
	printf("Exclusao feita com sucesso!!!");
	getch();

}

void exclusaoFisica(void)
{
	FILE *ptr = fopen("jogos.dat","rb"), *ptrNovo = fopen("novo.dat","ab");
	jogos regJogo;
	participantes regPart;
	campeonatos regCamp;
	controles regCont;
	int l = 5;
	limpar(l);
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regJogo,sizeof(regJogo),1,ptr);
		while(!feof(ptr))
		{
			if(regJogo.status == 1)
				fwrite(&regJogo,sizeof(regJogo),1,ptrNovo);
			fread(&regJogo,sizeof(regJogo),1,ptr);
		}
		fclose(ptr);
		remove("jogos.dat");
		fclose(ptrNovo);
		rename("novo.dat","jogos.dat");
		OrdenarDireta();
	}
	
	ptr = fopen("participantes.dat","rb");
	ptrNovo = fopen("novo.dat","ab");
	
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regPart,sizeof(regPart),1,ptr);
		while(!feof(ptr))
		{
			if(regPart.status == 1)
				fwrite(&regPart,sizeof(regPart),1,ptrNovo);
			fread(&regPart,sizeof(regPart),1,ptr);
		}
		fclose(ptr);
		remove("participantes.dat");
		fclose(ptrNovo);
		rename("novo.dat","participantes.dat");
		ordenarBolha();
	}
	
	ptr = fopen("campeonatos.dat","rb");
	ptrNovo = fopen("novo.dat","ab");
	
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regCamp,sizeof(regCamp),1,ptr);
		while(!feof(ptr))
		{
			if(regCamp.status == 1)
				fwrite(&regCamp,sizeof(regCamp),1,ptrNovo);
			fread(&regCamp,sizeof(regCamp),1,ptr);
		}
		fclose(ptr);
		remove("campeonatos.dat");
		fclose(ptrNovo);
		rename("novo.dat","campeonatos.dat");
		ordenarCampeonato();	
	}	
	
	ptr = fopen("controles.dat","rb");
	ptrNovo = fopen("novo.dat","ab");
	
	if(ptr == NULL || ptrNovo == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo na exclusao fisica");
		getch();
	}
	else
	{
		fread(&regCont,sizeof(regCont),1,ptr);
		while(!feof(ptr))
		{
			if(regCont.status == 1)
				fwrite(&regCont,sizeof(regCont),1,ptrNovo);
			fread(&regCont,sizeof(regCont),1,ptr);
		}
		fclose(ptr);
		remove("controles.dat");
		fclose(ptrNovo);
		rename("novo.dat","controles.dat");
		ordenarControle();
	}
}

void consultJogos(void)
{
	FILE *ptr = fopen("jogos.dat","rb");
	jogos reg;
	int aux,pos;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Consultar Jogos ***");
	if(ptr == NULL)
	{
		ir(l); printf("Erro de abertura!");
		getch();
	}
	else
	{
		ir(l); printf("Digite o COD do jogo: ");
		while(pegaN(reg.cod))
		{		
			fclose(ptr);
			OrdenarDireta();
			ptr = fopen("jogos.dat","rb");
			
			pos = buscaIndexadaJogo(ptr,reg.cod);
			
			if(pos != -1)
			{
				fseek(ptr,pos,0);
				fread(&reg,sizeof(jogos),1,ptr);
				ir(l); printf("Codigo: %d, Nome: %s, Status: '%d' ",reg.cod,reg.descr,reg.status);
				getch();
			}
			else
			{
				ir(l); printf("Codigo nao encontrado!!!  ");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Consultar Jogos ***");
			ir(l); printf("Digite o COD do jogo: ");
		}	
	}
	fclose(ptr);
}
void consultCamp(void)
{
	FILE *ptr = fopen("campeonatos.dat","rb");
	campeonatos reg;
	int aux,pos;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Consulta de Campeonatos ***");
	if(ptr == NULL)
	{
		ir(l); printf("Erro de abertura!");
		getch();
	}
	else
	{
		ir(l); printf("Digite o COD do campeonato: ");
		while(pegaN(reg.cod))
		{
			
			pos = buscaExaustivaSentCamp(ptr,reg.cod);
			
			if(pos != -1)
			{
				fseek(ptr,pos,0);
				fread(&reg,sizeof(campeonatos),1,ptr);
				ir(l); printf("Codigo: %d, Titulo: %s,",reg.cod,reg.titulo);
				ir(l); printf("Jogo: %d, Ano: %d, Responsavel: %s,",reg.codJogo,reg.anoDisputa,reg.responsavel);
				ir(l); printf("Descricao: %s",reg.descr);
				getch();
			}
			else
			{
				ir(l); printf("Codigo nao encontrado!!!  ");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Consulta de Campeonatos ***");
			ir(l); printf("Digite o COD do campeonato: ");
		}	
	}
	fclose(ptr);
}

void consultPart(void)
{
	FILE *ptr = fopen("participantes.dat","rb");
	jogos reg;
	int aux,pos;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Editar Participantes ***");
	
	if(ptr == NULL)
	{
		ir(l); printf("Erro de abertura!");
		getch();
	}
	else
	{
		ir(l); printf("Digite o COD do participantes: ");
		while(pegaN(reg.cod))
		{		
			fclose(ptr);
			ordenarBolha();	
			ptr = fopen("participantes.dat","rb");
			
			pos = buscaBinariaPart(ptr,reg.cod);
			
			if(pos != -1)
			{
				fseek(ptr,pos,0);
				fread(&reg,sizeof(participantes),1,ptr);
				ir(l); printf("Codigo: %d, Nome: %s",reg.cod,reg.descr);
				getch();
			}
			else
			{
				ir(l); printf("Codigo nao encontrado!!!  ");
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Editar Participantes ***");
			ir(l); printf("Digite o COD do participantes: ");
		}	
	}
	fclose(ptr);
}

void consultControle(void)
{
	FILE *ptr = fopen("controles.dat", "rb");
	controles reg;
	int pos;
	char op;
	int l = 5;
	limpar(l);
	gotoxy(6,3); printf("*** Consultar Controles ***");
	
	if(ptr == NULL)
	{
		ir(l); printf("Erro de abertura de arquivo!");
		getch();
	}
	else
	{
		ir(l); printf("Codigo do Campeonato: ");
		while(pegaN(reg.codCamp))
		{
			ir(l); printf("Codigo do Participante: ");
			pegaN(reg.codPart);
			pos = buscaExaustivaControl(ptr, reg.codCamp, reg.codPart);
			if(pos == -1)
			{
				ir(l); printf("Codigos nao encontrado!");
				getch();
			}
			else
			{
				fseek(ptr, pos, 0);
				fread(&reg,sizeof(reg),1,ptr);
				ir(l); printf("Cod. Campeonato: %d, Cod. Participante: %d, Nome: %s", reg.codCamp, reg.codPart, reg.nick);
				getch();
			}
			limpar(l);
			gotoxy(6,3); printf("*** Consulatar Controle ***");
			ir(l); printf("Codigo do Campeonato: ");
		}
		fclose(ptr);
	}
}

void relatoJogo(void)
{
	FILE * ptrP = fopen("participantes.dat","rb");
	FILE * ptrC = fopen("campeonatos.dat","rb");
	FILE * ptrJ = fopen("jogos.dat","rb");
	FILE * ptrCo = fopen("controles.dat","rb");
	participantes regP;
	jogos regJ;
	campeonatos regC;
	controles regCo;
	int pos,tl,tl2,tl3,i,j,k,cont=0;
	int l = 5;
	
		limpar(l);
		fseek(ptrP,0,0);
		gotoxy(6,3); printf("*** Relatorio do Participante ***");
		ir(l); printf("Digite o codigo do Participantes: ");
		while(pegaN(regP.cod))
		{
			pos = buscaBinariaPart(ptrP,regP.cod);
			if(pos != -1)
			{
				fseek(ptrP,pos,0);
				fread(&regP,sizeof(participantes),1,ptrP);
				limpar(l);
				gotoxy(6,3); printf("*** Relatorio do Participante ***");
				ir(l); printf("Jogador Selecionado: %s",regP.descr);
				ir(l); printf("--------------------------------------------------------------------------------------------------------------");
				fseek(ptrJ,0,2);
				fseek(ptrC,0,2);
				fseek(ptrCo,0,2);
				
				tl = ftell(ptrJ) / sizeof(jogos);
				tl2 = ftell(ptrC) / sizeof(campeonatos);
				tl3 = ftell(ptrCo) / sizeof(controles);
				
				fseek(ptrJ,0,0);
				fseek(ptrC,0,0);
				fseek(ptrCo,0,0);
					
				for(i=0;i<tl;i++)
				{
					cont = 0;
				
					fseek(ptrJ,i*sizeof(jogos),0);
					fread(&regJ,sizeof(jogos),1,ptrJ);
						
					for(j = 0; j<tl2 ;j++)
					{
						
						fseek(ptrC,j*sizeof(campeonatos),0);
						fread(&regC,sizeof(campeonatos),1,ptrC);
						
						if(regJ.cod == regC.codJogo)
						{
							pos = buscaExaustivaControl(ptrCo,regC.cod,regP.cod);
							if(pos != -1)
							{
								fseek(ptrCo,k*sizeof(controles),0);
								fread(&regCo,sizeof(controles),1,ptrCo);
								if(cont == 0)
								{
									ir(l); printf("Tipo de jogo: %s",regJ.descr);
								}
								for(k =0 ; k<tl3; k++)
                                {
                                    fseek(ptrCo,k*sizeof(controles),0);
                                    fread(&regCo,sizeof(controles),1,ptrCo);
                                    if(regC.cod == regCo.codCamp && regP.cod == regCo.codPart)
                                    {
                                        ir(l); printf("%s - Responsavel: %s(%d) - Nick: %s",regC.titulo,regC.responsavel,regC.anoDisputa,regCo.nick);
                                        cont++;
                                    }
                                }
							}
						}
					}
					if(cont > 0)
					{
						ir(l); printf("Total de Campeonatos %d",cont);
						ir(l); printf("--------------------------------------------------------------------------------------------------------------");
					}
				}
				getch();
			}
			else
			{
				ir(l); printf("Jogador nao encontrado!!!");
				getch();
			}
			limpar(l);
			fseek(ptrP,0,0);
			gotoxy(6,3); printf("*** Relatorio do Participante ***");
			ir(l); printf("Digite o codigo do Participantes: ");
		}
	fclose(ptrP);
	fclose(ptrCo);
	fclose(ptrC);
	fclose(ptrJ);
}

void relatoCamp(void)
{
	FILE *ptrC = fopen("campeonatos.dat","rb");
	FILE *ptrJ = fopen("jogos.dat","rb");
	FILE *ptrP = fopen("participantes.dat","rb");
	FILE *ptrCo = fopen("controles.dat","rb");
	jogos regJ;
	campeonatos regC;
	participantes regP;
	controles regCo;
	int pos,tl,tl2,i,j;
	int l = 5;
	
	limpar(l);
	fseek(ptrC,0,0);
	gotoxy(6,3); printf("*** Relatorio de campeonato ***");
	ir(l); printf("Digite o cod do Campeonato: ");
	while(pegaN(regC.cod))
	{
		pos = buscaExaustivaCamp(ptrC,regC.cod);
		if(pos != -1)
		{
			fseek(ptrC,pos,0);
			fread(&regC,sizeof(campeonatos),1,ptrC);
			
			fclose(ptrJ);
			ordenarJogo();
			ptrJ = fopen("jogos.dat","rb");
			
			pos = buscaIndexadaJogo(ptrJ,regC.codJogo);
			if(pos!=1)
			{
				fseek(ptrJ,pos,0);
				fread(&regJ,sizeof(jogos),1,ptrJ);
				
				ir(l); printf("Campeonato selecionado %s",regC.titulo);
				ir(l); printf("Responsavel:%s - %d - %s",regC.responsavel,regC.anoDisputa,regJ.descr);
				ir(l); printf("Descricao:");
				ir(l); printf("%s",regC.descr);
				ir(l); printf("Participantes (em ordem Alfabetica)");
				
				ordenarParticipanteNome();
				
				fseek(ptrP,0,0);
				fread(&regP,sizeof(regP),1,ptrP);
				while(!feof(ptrP))
				{
					pos = buscaExaustivaControl(ptrCo, regC.cod, regP.cod);
					if(pos > -1)
					{
						ir(l); printf(" - %s",regP.descr);
					}
					fread(&regP,sizeof(regP),1,ptrP);
				}
				getch();
			}
			else
			{
				ir(l); printf("Jogo nao encontrado!");
				getch();
			}
		}
		else
		{
			ir(l); printf("Campeonato nao encontrado!");
			getch();
		}
		limpar(l);
		fseek(ptrC,0,0);
		gotoxy(6,3); printf("*** Relatorio de campeonato ***");
		ir(l); printf("Digite o cod do Campeonato: ");
	}
	fclose(ptrP);
	fclose(ptrCo);
	fclose(ptrJ);
	fclose(ptrC);
	ordenarParticipante();
}



void ordenarParticipanteNome(void)
{
	FILE *arq = fopen("participantes.dat","rb+");
	participantes reg1, reg2;
	int i, j, fim;
	
		fseek(arq, 0, 2);
		fim = ftell(arq)/sizeof(reg1);
		for(i=0;i<fim-1;i++)
		{
			for(j=i+1;j<fim;j++)
			{
				fseek(arq,i*sizeof(reg1),0);
				fread(&reg1,sizeof(reg1),1,arq);
				fseek(arq,j*sizeof(reg2),0);
				fread(&reg2,sizeof(reg2),1,arq);
				if(stricmp(reg1.descr,reg2.descr) > 0 || reg1.status == 0 && reg2.status == 1)
				{
					fseek(arq,i*sizeof(reg1),0);
					fwrite(&reg2,sizeof(reg2),1,arq);
					fseek(arq,j*sizeof(reg2),0);
					fwrite(&reg1,sizeof(reg1),1,arq);
				}
			}
		}
		fclose(arq);

}

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
}

void ir(int &l)
{
	int i;
	if(l == 27)
	{
		gotoxy(6,27);
		ir(l); printf("--------------------------------------------------------------------------------------------------------------");
		gotoxy(8,28);
		textcolor(10);
		printf("  PRESSIONE QUALQUER TECLA PARA IR PARA PROXIMA PAGINA!");
		textcolor(15);
		l = 5;
		getch();
		for(i=5;i<29;i++)
		{
			gotoxy(6,i);
			printf("                                                                                                              ");
		}
	}
	gotoxy(6,l);
	l++;
}

void limpar(int &l)
{
	int i;
	gotoxy(6,3);
	printf("                                                                                                              ");
	for(i=5;i<29;i++)
	{
		gotoxy(6,i);
		printf("                                                                                                              ");
	}
	l=5;
}

void inserir(void)
{
	FILE *ptr = fopen("jogos.dat","wb");
	
	jogos regJogo;
	participantes regPart;
	campeonatos regCamp;
	controles regCont;
	
	regJogo.cod = 1;
	strcpy(regJogo.descr, "League of Legends");
	regJogo.status = 1;
	fwrite(&regJogo,sizeof(jogos),1,ptr);
	regJogo.cod = 2;
	strcpy(regJogo.descr, "Fortnite");
	regJogo.status = 1;
	fwrite(&regJogo,sizeof(jogos),1,ptr);
	regJogo.cod = 3;
	strcpy(regJogo.descr, "Mortal Kombat");
	regJogo.status = 1;
	fwrite(&regJogo,sizeof(jogos),1,ptr);
	regJogo.cod = 4;
	strcpy(regJogo.descr, "CS:GO");
	regJogo.status = 1;
	fwrite(&regJogo,sizeof(jogos),1,ptr);
	
	fclose(ptr);
	ptr = fopen("participantes.dat","wb");
	
	regPart.cod = 1;
	strcpy(regPart.descr, "Marcelo “coldzera” David");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 2;
	strcpy(regPart.descr, "Olof “olofmeister” Kajbjer");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 3;
	strcpy(regPart.descr, "Ladislav “GuardiaN” Kovács");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 4;
	strcpy(regPart.descr, "Nicolai “dev1ce” Reedtz");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 5;
	strcpy(regPart.descr, "Santorin");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 6;
	strcpy(regPart.descr, "SGD Sty1eee");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 7;
	strcpy(regPart.descr, "Solokill3hk");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 8;
	strcpy(regPart.descr, "JUGKlNG");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	regPart.cod = 9;
	strcpy(regPart.descr, "Kyle Giersdorf (Bugha)");
	regPart.status = 1;
	fwrite(&regPart,sizeof(participantes),1,ptr);
	
	fclose(ptr);
	ptr = fopen("campeonatos.dat","wb");
	
	regCamp.cod = 1;
	strcpy(regCamp.titulo,"Mundial de LoL");
	strcpy(regCamp.responsavel,"Riot Games");
	regCamp.anoDisputa = 2019;
	regCamp.codJogo = 1;
	strcpy(regCamp.descr, "O torneio mais importante do MOBA da Riot Games...");
	regCamp.status = 1;
	fwrite(&regCamp,sizeof(regCamp),1,ptr);
	
	regCamp.cod = 2;
	strcpy(regCamp.titulo,"Copa do mundo de Fortnite");
	strcpy(regCamp.responsavel,"Epic Games");
	regCamp.anoDisputa = 2019;
	regCamp.codJogo = 2;
	strcpy(regCamp.descr, "A jornada para a Fortnite World Cup comeca com dez qualificatorias semanais...");
	regCamp.status = 1;
	fwrite(&regCamp,sizeof(regCamp),1,ptr);
	
	regCamp.cod = 3;
	strcpy(regCamp.titulo,"Campeonato Brasileiro de CS:GO");
	strcpy(regCamp.responsavel,"Valve");
	regCamp.anoDisputa = 2020;
	regCamp.codJogo = 4;
	strcpy(regCamp.descr, "Uma nova competicao de Counter-Strike: Global Offensive foi anunciada no Brasil...");
	regCamp.status = 1;
	fwrite(&regCamp,sizeof(regCamp),1,ptr);
	
	fclose(ptr);
	ptr = fopen("controles.dat","wb");
	
	regCont.codCamp = 3;
	regCont.codPart = 2;
	strcpy(regCont.nick,"SG BOOTCAMP");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 3;
	regCont.codPart = 1;
	strcpy(regCont.nick,"PERAQTOCOSTA");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 1;
	regCont.codPart = 1;
	strcpy(regCont.nick,"KT ROLSTER");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 1;
	regCont.codPart = 2;
	strcpy(regCont.nick,"FREECS");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 3;
	regCont.codPart = 4;
	strcpy(regCont.nick,"INSTANTK");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 1;
	regCont.codPart = 9;
	strcpy(regCont.nick,"ROYAL NEVER");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 1;
	regCont.codPart = 3;
	strcpy(regCont.nick,"GEN.G");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 3;
	regCont.codPart = 5;
	strcpy(regCont.nick,"NASDH");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 2;
	regCont.codPart = 6;
	strcpy(regCont.nick,"BUGHA");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 1;
	regCont.codPart = 8;
	strcpy(regCont.nick,"ROOKIE");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	regCont.codCamp = 2;
	regCont.codPart = 7;
	strcpy(regCont.nick,"NYHROX");
	regCont.status = 1;
	fwrite(&regCont,sizeof(regCont),1,ptr);
	
	fclose(ptr);
}


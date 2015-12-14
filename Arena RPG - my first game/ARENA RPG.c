//ARENA RPG
//ANDREY

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "game.h"

int x,y,condicao,dinheiro,nivel,espada=1,machado,arco,escudo,lanca,espada1,ogro_vida=15,experiencia,vida1,hit;
int vidamax, energiamax,vida,energia,pocoes,ervas,lobo_vida,ladrao_vida,CONDICAO,windows_vida,popai_vida,bob_vida;
int CONDICAO,popai_vida,wandaymo_vida,condicao_1=1,itens[10][10];
char slot[30][100],nome[20];
void testes(){
	if(nivel==2){vidamax=25;energiamax=10;}
	if(nivel==3){vidamax=30;energiamax=15;}
	if(nivel==4){vidamax=35;energiamax=20;}
	if(nivel==5){vidamax=45;energiamax=25;}
	if(nivel==6){vidamax=50;energiamax=30;}
	if(nivel==7){vidamax=55;energiamax=35;}
	if(nivel==8){vidamax=60;energiamax=40;}
	if(nivel==9){vidamax=70;energiamax=50;}
	if(nivel==10){vidamax=80;energiamax=60;}
	if(nivel==11){vidamax=90;energiamax=70;}
	if(nivel==12){vidamax=100;energiamax=80;}
	if(nivel==13){vidamax=120;energiamax=80;}
	if(nivel==14){vidamax=140;energiamax=100;}
	if(nivel==15){vidamax=150;energiamax=110;}
	if(experiencia>=10){nivel=2;}
	if(experiencia>=25){nivel=3;}
	if(experiencia>=60){nivel=4;}
	if(experiencia>=100){nivel=5;}
	if(experiencia>=160){nivel=6;}
	if(experiencia>=280){nivel=7;}
	if(experiencia>=420){nivel=8;}
	if(experiencia>=600){nivel=9;}
	if(experiencia>=900){nivel=10;}
	if(experiencia>=1300){nivel=11;}
	if(experiencia>=1700){nivel=12;}
	if(experiencia>=2000){nivel=13;}
	if(experiencia>=2500){nivel=14;}
	if(experiencia>=3000){nivel=15;}
}
void mover(){
	char tc;
	textcolor(7);
	testes();
	tc=getch();
	switch (tc){
	case 72:{
		clrscr();
		y=y-1;
		gotoxy(x,y);puts("\x1");break;
	}
	case 80:{
		clrscr();
		y=y+1;
		gotoxy(x,y);puts("\x1");break;
	}
	case 77:{
		inicio:
		clrscr();
		x=x+1;
		gotoxy(x,y);puts("\x1/");break;
	}
	case 75:{
		clrscr();
		x=x-1;
		gotoxy(x,y);puts("\\\x1");break;
		}
		case 32:{
			clrscr();
			char p;
			int a,b;menu:a=9;b=5;
			do{
				gotoxy(10,5 );printf("STATUS");
				gotoxy(10,7 );printf("EQUIPAMENTOS");
				gotoxy(10,9 );printf("CONQUISTAS");
				gotoxy(10,11);printf("SAIR");
				p=getch();
				if(p==80){clrscr();b=b+2;gotoxy(a,b);printf("\xFE");}
				if(p==72){clrscr();b=b-2;gotoxy(a,b);printf("\xFE");}
				if(b==13){clrscr();b=b-2;gotoxy(a,b);printf("\xFE");}
				if(b==3){clrscr();b=b+2;gotoxy(a,b);printf("\xFE");}
				if(((a==9)&&(b==5))&&(p==13)){
					gotoxy(30,5 );printf("| %s: ",nome);
					gotoxy(30,6 );printf("| VIDA:%d/%d",vida,vidamax);
					gotoxy(30,7 );printf("| ENERGIA:%d/%d",energia,energiamax);
					gotoxy(30,8 );printf("|________________");
					gotoxy(30,9 );printf("| HABILIDADES");
					gotoxy(30,10);printf("| ESPADA:%d",espada);
					gotoxy(30,11);printf("| MACHADO:%d",machado);
					gotoxy(30,12);printf("| ARCO E FLECHA: %d",arco);
					gotoxy(30,13);printf("| LANCA:%d",lanca);
					gotoxy(30,14);printf("| ESCUDO:%d",escudo);
					gotoxy(30,16);printf("|>NIVEL:%d",nivel);
					gotoxy(30,15);printf("| DINHEIRO: %dRS",dinheiro);
				}
				if(((a==9)&&(b==7))&&(p==13)){
					ekips:
					a=29;b=5;
					clrscr();
					do{
						gotoxy(30,5 );printf("MAO ESQUERDA:");
						gotoxy(30,6 );printf("MAO DIREITA:");
						gotoxy(30,7 );printf("TORSO:");
						gotoxy(30,8 );printf("PERNAS:");
						gotoxy(30,9 );printf("PES:");
						gotoxy(30,10);printf("CABECA ");
						gotoxy(30,11);printf("VOLTAR");
						gotoxy(30,12);printf("");
						gotoxy(30,13);printf("");
						p=getch();
						if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
						if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
						if(b==12){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
						if(b==4 ){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
						if((b==11)&&(p==13)){clrscr();goto menu;}
						if((b==5)&&(p==13)){
							clrscr();
							do{
								gotoxy(30,5 );printf("%s",slot[0]);
								gotoxy(30,6 );printf("%s",slot[1]);
								gotoxy(30,7 );printf("%s",slot[2]);
								gotoxy(30,8 );printf("%s",slot[3]);
								gotoxy(30,9 );printf("%s",slot[4]);
								gotoxy(30,10);printf("VOLTAR");
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==11){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==4 ){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if((p==13)&&(b==5)){
									gotoxy(30,3);printf("EQUIPADO: %s",slot[0]);
									if(strcmp(slot[0],"FACA")==0) {espada=5555;}
									if(strcmp(slot[0],"ESPADA DE MADEIRA")==0) {espada=10;}
									if(strcmp(slot[0],"ESPADA DA SERPENTE")==0) {espada=20;}
									if(strcmp(slot[0],"ESPADA DO DRAGAO")==0) {espada=30;}
									if(strcmp(slot[0],"")==0) {espada=1;}
								}
								if((p==13)&&(b==6)){
									gotoxy(30,3);printf("EQUIPADO: %s",slot[1]);
									if(strcmp(slot[1],"FACA")==0) {espada=5;}
									if(strcmp(slot[1],"ESPADA DE MADEIRA")==0) {espada=10;}
									if(strcmp(slot[1],"ESPADA DA SERPENTE")==0) {espada=20;}
									if(strcmp(slot[1],"ESPADA DO DRAGAO")==0) {espada=30;}
									if(strcmp(slot[1],"")==0) {espada=1;}
								}
								if((p==13)&&(b==7)){
									gotoxy(30,3);printf("EQUIPADO: %s",slot[2]);
									if(strcmp(slot[2],"FACA")==0) {espada=5;}
									if(strcmp(slot[2],"ESPADA DE MADEIRA")==0) {espada=10;}
									if(strcmp(slot[2],"ESPADA DA SERPENTE")==0) {espada=20;}
									if(strcmp(slot[2],"ESPADA DO DRAGAO")==0) {espada=30;}
									if(strcmp(slot[2],"")==0) {espada=1;}
								}
								if((p==13)&&(b==8)){
									gotoxy(30,3);printf("EQUIPADO: %s",slot[3]);
									if(strcmp(slot[3],"FACA")==0) {espada=5;}
									if(strcmp(slot[3],"ESPADA DE MADEIRA")==0) {espada=10;}
									if(strcmp(slot[3],"ESPADA DA SERPENTE")==0) {espada=20;}
									if(strcmp(slot[3],"ESPADA DO DRAGAO")==0) {espada=30;}
									if(strcmp(slot[3],"")==0) {espada=1;}
								}
								if((p==13)&&(b==9)){
									gotoxy(30,3);printf("EQUIPADO: %s",slot[4]);
									if(strcmp(slot[4],"FACA")==0) {espada=5;}
									if(strcmp(slot[4],"ESPADA DE MADEIRA")==0) {espada=10;}
									if(strcmp(slot[4],"ESPADA DA SERPENTE")==0) {espada=20;}
									if(strcmp(slot[4],"ESPADA DO DRAGAO")==0) {espada=30;}
									if(strcmp(slot[4],"")==0) {espada=1;}
								}
								if((b==10)&&(p==13)){goto ekips;}
							}while(1);
						}
						if((b==6)&&(p==13)){
							clrscr();
							do{
								gotoxy(30,5 );printf("SLOT1[maos]");
								gotoxy(30,6 );printf("SLOT2[maos]");
								gotoxy(30,7 );printf("SLOT3[maos]");
								gotoxy(30,8 );printf("SLOT4[maos]");
								gotoxy(30,9 );printf("SLOT5[maos]");
								gotoxy(30,10);printf("VOLTAR");
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==11){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==4 ){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if((b==10)&&(p==13)){goto ekips;}
							}while(1);
						}
							if((b==7)&&(p==13)){
							clrscr();
							do{
								gotoxy(30,5 );printf("SLOT1[torso]");
								gotoxy(30,6 );printf("SLOT2[torso]");
								gotoxy(30,7 );printf("SLOT3[torso]");
								gotoxy(30,8 );printf("SLOT4[torso]");
								gotoxy(30,9 );printf("SLOT5[torso]");
								gotoxy(30,10);printf("VOLTAR");
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==11){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==4 ){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if((b==10)&&(p==13)){goto ekips;}
							}while(1);
						}
							if((b==8)&&(p==13)){
							clrscr();
							do{
								gotoxy(30,5 );printf("SLOT1[pernas]");
								gotoxy(30,6 );printf("SLOT2[pernas]");
								gotoxy(30,7 );printf("SLOT3[pernas]");
								gotoxy(30,8 );printf("SLOT4[pernas]");
								gotoxy(30,9 );printf("SLOT5[pernas]");
								gotoxy(30,10);printf("VOLTAR");
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==11){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==4 ){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if((b==10)&&(p==13)){goto ekips;}
							}while(1);

						}
							if((b==9)&&(p==13)){
							clrscr();
							do{
								gotoxy(30,5 );printf("SLOT1[pes]");
								gotoxy(30,6 );printf("SLOT2[pes]");
								gotoxy(30,7 );printf("SLOT3[pes]");
								gotoxy(30,8 );printf("SLOT4[pes]");
								gotoxy(30,9 );printf("SLOT5[pes]");
								gotoxy(30,10);printf("VOLTAR");
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==11){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==4 ){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if((b==10)&&(p==13)){goto ekips;}
							}while(1);
						}
							if((b==10)&&(p==13)){
							clrscr();
							do{
								gotoxy(30,5 );printf("SLOT1[cabeca]");
								gotoxy(30,6 );printf("SLOT2[cabeca]");
								gotoxy(30,7 );printf("SLOT3[cabeca]");
								gotoxy(30,8 );printf("SLOT4[cabeca]");
								gotoxy(30,9 );printf("SLOT5[cabeca]");
								gotoxy(30,10);printf("VOLTAR");
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==11){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
								if(b==4 ){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
								if((b==10)&&(p==13)){goto ekips;}
							}while(1);
						}
				}while(1);
			}
			if(((a==9)&&(b==11))&&(p==13)){
				system("break");
				clrscr();
				goto inicio;
			}
			}while(1);
			break;
		}
	}
	if(x==81){
		clrscr();
		x=x-1;
		gotoxy(x,y);puts("\xFE");
	}
	if(x==0){
		clrscr();
		x=x+1;
		gotoxy(x,y);puts("\xFE");
	}
	if(y==25){
		clrscr();
		y=y-1;
		gotoxy(x,y);puts("\xFE");
	}
	if(y==0){
		clrscr();
		y=y+1;
		gotoxy(x,y);puts("\xFE");
	}
}

void bordas(){
	int i;
	for(i=2;i<25;i++){
    	gotoxy(4,i); puts("\xBA");
    	gotoxy(77,i);puts("\xBA");
	}
    for(i=4;i<77;i++){
       	gotoxy(i,2); puts("\xCD");
       	gotoxy(i,25);puts("\xCD");
       }
    gotoxy(77,2);puts("\xBB");
    gotoxy(4,25);puts("\xC8");
    gotoxy(4,2); puts("\xC9");
    gotoxy(77,25);puts("\xBC");
}

void principal(){
	inicio:
	do{

	textcolor(9);
	if (condicao_1==1){
		gotoxy(20,13);
		printf("APERTE AS SETAS PARA MOVER");
		condicao_1=2;
	}
    gotoxy(30,1);printf("VALE");
    textcolor(2);
    gotoxy(20,10);printf(" /\\");
    gotoxy(20,11);printf("/__\\");
    gotoxy(20,12);printf(" ||");
    gotoxy(40,5 );printf(" /\\");
    gotoxy(40,6 );printf("/__\\");
    gotoxy(40,7 );printf(" ||");
    gotoxy(30,8 );printf(" /\\");
    gotoxy(30,9 );printf("/__\\");
    gotoxy(30,10);printf(" ||");
    gotoxy(10,3 );printf(" /\\");
    gotoxy(10,4 );printf("/__\\");
    gotoxy(10,5 );printf(" ||");
    gotoxy(60,18);printf(" /\\");
    gotoxy(60,19);printf("/__\\");
    gotoxy(60,20);printf(" ||");
    gotoxy(55,5);printf(" /\\");
    gotoxy(55,6);printf("/__\\");
    gotoxy(55,7);printf(" ||");
    gotoxy(6 ,21);printf(" /\\");
    gotoxy(6 ,22);printf("/__\\");
    gotoxy(6 ,23);printf(" ||");
    gotoxy(65,20);printf(" /\\");
    gotoxy(65,21);printf("/__\\");
    gotoxy(65,22);printf(" ||");
    gotoxy(30,15);printf(" /\\");
    gotoxy(30,16);printf("/__\\");
    gotoxy(30,17);printf(" ||");
    gotoxy(50,17);printf(" /\\");
    gotoxy(50,18);printf("/__\\");
    gotoxy(50,19);printf(" ||");
    textcolor(7);
     gotoxy(60,8 );printf("Entrada da cidade");
       textcolor(4);
    gotoxy(65,9 );printf("  __");
    gotoxy(65,10);printf(" /  \\");
    gotoxy(65,11);printf("/____\\");
       textcolor(7);
    gotoxy(65,12);printf("|    |");
    gotoxy(65,13);printf("| _  |");
    gotoxy(65,14);printf("|| |_|");
	mover();
    if ((x==67)&&(y==14)){
  		npc1:
    	clrscr();
    	system("break");
    	int a,b;
    	char p;
    	a=34;b=5;
    	clrscr();
    	do{
                  textcolor(3);
			gotoxy(3,3) ;printf("______0000000000000000       ");  textcolor(7);gotoxy(35,3);printf("OLA, O QUE VOCE DESEJA DA CIDADE?");  textcolor(3);
            gotoxy(3,4) ;printf("____0000000000000000000000  ");  textcolor(7);gotoxy(35,5);printf("ENTRAR");  textcolor(3);
            gotoxy(3,5) ;printf("__000000000__00000__00000000 ");  textcolor(7);gotoxy(35,6);printf("SAIR");  textcolor(3);
			gotoxy(3,6) ;printf("00000000000__00000__000000000");  textcolor(7);gotoxy(35,7);printf("INFORMACOES");  textcolor(3);
            gotoxy(3,7) ;printf("00000000000__00000__0000000000");
			gotoxy(3,8) ;printf("000000000000000000000000000000");
			gotoxy(3,9) ;printf("000000000000000000000000000000");
			gotoxy(3,10);printf("000000__________________000000");
			gotoxy(3,11);printf("000000__________________00000");
			gotoxy(3,12);printf("_000000_________________00000");
            gotoxy(3,13);printf("__0000000_____________000000");
			gotoxy(3,14);printf("____0000000_________0000000");
			gotoxy(3,15);printf("______ 0000000000000000");
			p=getch();
			if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
			}
			if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
			}
			if(b==8){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
			}
			if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
			}
			if(((a==34)&&(b==7))&&(p==13)){
				clrscr();
				system("break");
          textcolor(3);
				gotoxy(3,3) ;printf("______0000000000000000       ");  textcolor(7);gotoxy(35,3);printf("ESTA CIDADE SE CHAMA VALYR!");  textcolor(3);
				gotoxy(3,4) ;printf("____0000000000000000000000  ");   textcolor(7);gotoxy(35,4);("E COMANDADA POR LORD KIRIN UM HOMEN MUITO GENEROSO!");  textcolor(3);
                gotoxy(3,5) ;printf("__000000000__00000__00000000 ");  textcolor(7);gotoxy(35,5);gotoxy(20,5);printf("\xFEVOLTAR");  textcolor(3);
				gotoxy(3,6) ;printf("00000000000__00000__000000000");gotoxy(35,6);
                gotoxy(3,7) ;printf("00000000000__00000__0000000000");
				gotoxy(3,8) ;printf("000000000000000000000000000000");
				gotoxy(3,9) ;printf("000000000000000000000000000000");
				gotoxy(3,10);printf("000000__________________000000");
				gotoxy(3,11);printf("000000__________________00000");
				gotoxy(3,12);printf("_000000_________________00000");
                gotoxy(3,13);printf("__0000000_____________000000");
				gotoxy(3,14);printf("____0000000_________0000000");
				gotoxy(3,15);printf("______ 0000000000000000");
				p=getch();
				if (p==13){
					clrscr();
					system("break");
					goto npc1;
					}
				}
			if(((a==34)&&(b==6))&&(p==13)){
				clrscr();
				x=62;y=15;
				goto inicio;
				}
			if(((a==34)&&(b==5))&&(p==13)){
				clrscr();
				x=8;y=15;
				valyr1:
				if(condicao_1==2){textcolor(9);
					gotoxy(20,13);printf("APERTE ESPACO PARA IR AO MENU DE OPCOES,\n"
										"\t\t\tPARA EQUIPAR SUAS ARMAS ETC.");
					condicao_1=3;
					delay(3000);
					}

				do{
                          textcolor(7);
				gotoxy(22,2);puts(" Armas");  textcolor(4);
				gotoxy(22,3);puts("  /\\");
				gotoxy(22,4);puts(" /  \\");
				gotoxy(22,5);puts("/____\\");  textcolor(7);
				gotoxy(22,6);puts("| _  |");
				gotoxy(22,7);puts("|| |_|");
				if((x==24)&&(y==7)){
					clrscr();
					a=34;b=4;
					textcolor(3);
					casa1:
					    clrscr();
					do{textcolor(3);
						gotoxy(2,3) ;printf("______0000000000000000       ");  textcolor(7);gotoxy(35,3);printf("POSSO LHE OFERECER ARMAS. ESCOLHA O SEU TIPO;");  textcolor(3);
						gotoxy(2,4) ;printf("____0000000000000000000000  ");   textcolor(7);gotoxy(35,4);printf("ESPADA");  textcolor(3);
                        gotoxy(2,5) ;printf("__000000000__00000__00000000 ");  textcolor(7);gotoxy(35,5);printf("ARCO E FLEHCA");  textcolor(3);
						gotoxy(2,6) ;printf("00000000000__00000__000000000");  textcolor(7);gotoxy(35,6);printf("MACHADO");  textcolor(3);
						gotoxy(2,7) ;printf("00000000000__00000__0000000000");  textcolor(7);gotoxy(35,7);printf("LANCA");  textcolor(3);
						gotoxy(2,8) ;printf("000000000000000000000000000000");  textcolor(7);gotoxy(35,8);("ESCUDO");  textcolor(3);
						gotoxy(2,9) ;printf("000000000000000000000000000000");  textcolor(7);gotoxy(35,9);printf("SAIR");   textcolor(3);
						gotoxy(2,10);printf("000000000000000000000000000000");
                        gotoxy(2,11);printf("000000__________________000000");
						gotoxy(2,12);printf("000000__________________00000");
						gotoxy(2,13);printf("_000000_________________00000");
                        gotoxy(2,14);printf("__0000000_____________000000");
						gotoxy(2,15);printf("____0000000_________0000000");
						gotoxy(2,16);printf("______ 0000000000000000");
						p=getch();  textcolor(7);
						if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==10){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==3){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if((b==9)&&(p==13)){
							x=24;y=9;
							clrscr();goto valyr1;
						}

						if((b==4)&&(p==13)){
							a=34;b=4;
							clrscr();
							do{
                                      textcolor(3);
								gotoxy(2,3) ;printf("______0000000000000000      ");
                                gotoxy(2,4) ;printf("____0000000000000000000000  ");
							    gotoxy(2,5) ;printf("__000000000__00000__00000000 ");
								gotoxy(2,6) ;printf("00000000000__00000__000000000");
								gotoxy(2,7) ;printf("00000000000__00000__0000000000");
								gotoxy(2,8) ;printf("000000000000000000000000000000");
								gotoxy(2,9) ;printf("000000000000000000000000000000");
								gotoxy(2,10);printf("000000000000000000000000000000");
								gotoxy(2,11);printf("000000__________________000000");
								gotoxy(2,12);printf("000000__________________00000");
								gotoxy(2,13);printf("_000000_________________00000");
                                gotoxy(2,14);printf("__0000000_____________000000");
								gotoxy(2,15);printf("____0000000_________0000000");
								gotoxy(2,16);printf("______ 0000000000000000");  textcolor(7);
								gotoxy(35,3);printf("ESPADA, BOA ESCOLHA. QUAL DESEJA COMPRAR?              ");
								gotoxy(35,4);printf("FACA      ");
								gotoxy(35,5);printf("ESPADA DE MADEIRA");
								gotoxy(35,6);printf("ESPADA CURTA DA SERPENTE");
								gotoxy(35,7);printf("ESPADA LONGA DO DRAGAO");
								gotoxy(35,8);printf("ESPADA DOS DEUSES");
								gotoxy(35,9);printf("SAIR");
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
								}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
								}
								if(b==10){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
								}
								if(b==3){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
								}
								if( b==9 && p==13 ){
									goto valyr1;
								}

								if((b==4)&&(p==13)){
									a=34;b=5;gotoxy(a,b);printf("\xFE");
									clrscr();  textcolor(3);
									do{textcolor(3);
										gotoxy(2,3) ;printf("______0000000000000000       ");
										gotoxy(2,4) ;printf("____0000000000000000000000  ");
										gotoxy(2,5) ;printf("__000000000__00000__00000000 ");
										gotoxy(2,6) ;printf("00000000000__00000__000000000");
										gotoxy(2,7) ;printf("00000000000__00000__0000000000");
										gotoxy(2,8) ;printf("000000000000000000000000000000");
										gotoxy(2,9) ;printf("000000000000000000000000000000");
										gotoxy(2,10);printf("000000000000000000000000000000");
										gotoxy(2,11);printf("000000__________________000000");
										gotoxy(2,12);printf("000000__________________00000");
										gotoxy(2,13);printf("_000000_________________00000");
                                        gotoxy(2,14);printf("__0000000_____________000000");
										gotoxy(2,15);printf("____0000000_________0000000");
										gotoxy(2,16);printf("______ 0000000000000000");  textcolor(7);
										gotoxy(35,3);printf("ENTAO VOCE DESEJA COMPRAR UMA FACA?          ");
										gotoxy(35,4);printf("ELA CUSTA 5 REAIS! ATAQUE=1                  ");
										gotoxy(35,5);printf("SIM                                      ");
										gotoxy(35,6);printf("NAO                                      ");
										gotoxy(35,7);printf("                                         ");
										gotoxy(35,8);printf("                                         ");
										p=getch();
										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if((b==5)&&(p==13)){
											if(dinheiro>=10){
												do{
												clrscr();
												gotoxy(10 ,9);printf("GUARDAR EM QUAL SLOT DA MOCHILA/MAO ESQUERDA, ENTRE COM O NUMERO");
												gotoxy(10,10);printf("SLOT 1");
												gotoxy(10,11);printf("SLOT 2");
												gotoxy(10,12);printf("SLOT 3");
												gotoxy(10,13);printf("SLOT 4");
												gotoxy(10,14);printf("SLOT 5");
												p=getch();
												switch(p){
													case '1' : {
														clrscr();
														strcat(slot[0],"FACA");
														goto casa1;
														break;
													}
													case '2': {
														clrscr();
														strcat(slot[1],"FACA");
														goto casa1;
														break;
													}
													case '3':{
														clrscr();
														strcat(slot[2],"FACA");
														goto casa1;
														break;
													}
													case '4':{
														clrscr();
														strcat(slot[3],"FACA");
														goto casa1;
														break;
													}
													case '5':{
														clrscr();
														strcat(slot[4],"FACA");
														goto casa1;
														break;
													}
												}
											}while(1);
											}
											else{
												clrscr();
												gotoxy(40,12);printf("SEM DINHEIRO");goto casa1;
											}
										}
										if((b==6)&&(p==13))goto casa1;
									}while(1);
								}


								if((b==5)&&(p==13)){
									a=34;b=5;gotoxy(a,b);
									clrscr();  textcolor(3);
									do{
										gotoxy(2,3) ;printf("______0000000000000000       ");
										gotoxy(2,4) ;printf("____0000000000000000000000  ");
										gotoxy(2,5) ;printf("__000000000__00000__00000000 ");
										gotoxy(2,6) ;printf("00000000000__00000__000000000");
										gotoxy(2,7) ;printf("00000000000__00000__0000000000");
										gotoxy(2,8) ;printf("000000000000000000000000000000");
										gotoxy(2,9) ;printf("000000000000000000000000000000");
										gotoxy(2,10);printf("000000000000000000000000000000");
										gotoxy(2,11);printf("000000__________________000000");
										gotoxy(2,12);printf("000000__________________00000");
										gotoxy(2,13);printf("_000000_________________00000");
                                        gotoxy(2,14);printf("__0000000_____________000000");
										gotoxy(2,15);printf("____0000000_________0000000");
										gotoxy(2,16);printf("______ 0000000000000000");  textcolor(7);
										gotoxy(35,3);printf("ENTAO VOCE DESEJA COMPRAR UMA ESPADA DE MADEIRA?          ");
										gotoxy(35,4);printf("ELA CUSTA 30 REAIS! ATAQUE=2                  ");
										gotoxy(35,5);printf("SIM                                      ");
										gotoxy(35,6);printf("NAO                                      ");
										gotoxy(35,7);printf("                                         ");
										gotoxy(35,8);printf("                                         ");
										p=getch();
										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if((b==5)&&(p==13)){
											if(dinheiro>=30){
												do{
												clrscr();
												gotoxy(10 ,9);printf("GUARDAR EM QUAL SLOT DA MOCHILA/MAO ESQUERDA, ENTRE COM O NUMERO");
												gotoxy(10,10);printf("SLOT 1");
												gotoxy(10,11);printf("SLOT 2");
												gotoxy(10,12);printf("SLOT 3");
												gotoxy(10,13);printf("SLOT 4");
												gotoxy(10,14);printf("SLOT 5");
												p=getch();
												switch(p){
													case '1' : {
														clrscr();
														strcat(slot[0],"ESPADA DE MADEIRA");
														goto casa1;
														break;
													}
													case '2': {
														clrscr();
														strcat(slot[1],"ESPADA DE MADEIRA");
														goto casa1;
														break;
													}
													case '3':{
														clrscr();
														strcat(slot[2],"ESPADA DE MADEIRA");
														goto casa1;
														break;
													}
													case '4':{
														clrscr();
														strcat(slot[3],"ESPADA DE MADEIRA");
														goto casa1;
														break;
													}
													case '5':{
														clrscr();
														strcat(slot[4],"ESPADA DE MADEIRA");
														goto casa1;
														break;
													}
												}
											}while(1);
											}
											else{
												clrscr();
												gotoxy(40,12);printf("SEM DINHEIRO");goto casa1;
											}
										}
										if((b==6)&&(p==13))goto casa1;
									}while(1);
								}


								if((b==6)&&(p==13)){
									a=34;b=5;gotoxy(a,b);
									clrscr();
									do{  textcolor(3);
										gotoxy(2,3) ;printf("______0000000000000000       ");gotoxy(48,3);
										gotoxy(2,4) ;printf("____0000000000000000000000  "); gotoxy(48,4);
										gotoxy(2,5) ;printf("__000000000__00000__00000000 ");gotoxy(48,5);
										gotoxy(2,6) ;printf("00000000000__00000__000000000");gotoxy(48,6);
										gotoxy(2,7) ;printf("00000000000__00000__0000000000");gotoxy(48,7);
										gotoxy(2,8) ;printf("000000000000000000000000000000");gotoxy(48,8);
										gotoxy(2,9) ;printf("000000000000000000000000000000");gotoxy(48,9);
										gotoxy(2,10);printf("000000000000000000000000000000");
										gotoxy(2,11);printf("000000__________________000000");
										gotoxy(2,12);printf("000000__________________00000");
										gotoxy(2,13);printf("_000000_________________00000");
                                        gotoxy(2,14);printf("__0000000_____________000000");
										gotoxy(2,15);printf("____0000000_________0000000");
										gotoxy(2,16);printf("______ 0000000000000000");  textcolor(7);
										gotoxy(35,3);printf("ENTAO VOCE DESEJA COMPRAR UMA ESPADA DA SERPENTE?  ");
										gotoxy(35,4);printf("ELA CUSTA 60 REAIS! ATAQUE=3                  ");
										gotoxy(35,5);printf("SIM                                      ");
										gotoxy(35,6);printf("NAO                                      ");
										gotoxy(35,7);printf("                                         ");
										gotoxy(35,8);printf("                                         ");
										p=getch();
										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if((b==5)&&(p==13)){
											if(dinheiro>=60){
												do{
												clrscr();
												gotoxy(10 ,9);printf("GUARDAR EM QUAL SLOT DA MOCHILA/MAO ESQUERDA, ENTRE COM O NUMERO");
												gotoxy(10,10);printf("SLOT 1");
												gotoxy(10,11);printf("SLOT 2");
												gotoxy(10,12);printf("SLOT 3");
												gotoxy(10,13);printf("SLOT 4");
												gotoxy(10,14);printf("SLOT 5");
												p=getch();
												switch(p){
													case '1' : {
														clrscr();
														strcat(slot[0],"ESPADA DA SERPENTE");
														goto casa1;
														break;
													}
													case '2': {
														clrscr();
														strcat(slot[1],"ESPADA DA SERPENTE");
														goto casa1;
														break;
													}
													case '3':{
														clrscr();
														strcat(slot[2],"ESPADA DA SERPENTE");
														goto casa1;
														break;
													}
													case '4':{
														clrscr();
														strcat(slot[3],"ESPADA DA SERPENTE");
														goto casa1;
														break;
													}
													case '5':{
														clrscr();
														strcat(slot[4],"ESPADA DA SERPENTE");
														goto casa1;
														break;
													}
												}
											}while(1);
											}
											else{
												clrscr();
												gotoxy(40,12);printf("SEM DINHEIRO");goto casa1;
											}
										}
										if((b==6)&&(p==13))goto casa1;
									}while(1);
								}



								if((b==7)&&(p==13)){
									a=34;b=5;gotoxy(a,b);
									clrscr();  textcolor(3);
									do{
										gotoxy(2,3) ;printf("______0000000000000000       ");
										gotoxy(2,4) ;printf("____0000000000000000000000  ");
										gotoxy(2,5) ;printf("__000000000__00000__00000000 ");
										gotoxy(2,6) ;printf("00000000000__00000__000000000");
										gotoxy(2,7) ;printf("00000000000__00000__0000000000");
										gotoxy(2,8) ;printf("000000000000000000000000000000");										gotoxy(5,9) ;printf("000000000000000000000000000000");gotoxy(48,9);
										gotoxy(2,10);printf("000000000000000000000000000000");
										gotoxy(2,11);printf("000000__________________000000");
										gotoxy(2,12);printf("000000__________________00000");
										gotoxy(2,13);printf("_000000_________________00000");
                                        gotoxy(2,14);printf("__0000000_____________000000");
										gotoxy(2,15);printf("____0000000_________0000000");
										gotoxy(2,16);printf("______ 0000000000000000");  textcolor(7);
										gotoxy(35,3);printf("ENTAO VOCE DESEJA COMPRAR UMA ESPADA DO DRAGAO? ");
										gotoxy(35,4);printf("ELA CUSTA 100 REAIS! ATAQUE=4                  ");
										gotoxy(35,5);printf("SIM                                      ");
										gotoxy(35,6);printf("NAO                                      ");
										gotoxy(35,7);printf("                                         ");
										gotoxy(35,8);printf("                                         ");
										p=getch();
										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if((b==5)&&(p==13)){
											if(dinheiro>=100){
												do{
												clrscr();
												gotoxy(10 ,9);printf("GUARDAR EM QUAL SLOT DA MOCHILA/MAO ESQUERDA, ENTRE COM O NUMERO");
												gotoxy(10,10);printf("SLOT 1");
												gotoxy(10,11);printf("SLOT 2");
												gotoxy(10,12);printf("SLOT 3");
												gotoxy(10,13);printf("SLOT 4");
												gotoxy(10,14);printf("SLOT 5");
												p=getch();
												switch(p){
													case '1' : {
														clrscr();
														strcat(slot[0],"ESPADA DO DRAGAO");
														goto casa1;
														break;
													}
													case '2': {
														clrscr();
														strcat(slot[1],"ESPADA DO DRAGAO");
														goto casa1;
														break;
													}
													case '3':{
														clrscr();
														strcat(slot[2],"ESPADA DO DRAGAO");
														goto casa1;
														break;
													}
													case '4':{
														clrscr();
														strcat(slot[3],"ESPADA DO DRAGAO");
														goto casa1;
														break;
													}
													case '5':{
														clrscr();
														strcat(slot[4],"ESPADA DO DRAGAO");
														goto casa1;
														break;
													}
												}
											}while(1);
											}
											else{
												clrscr();
												gotoxy(40,12);printf("SEM DINHEIRO");goto casa1;
											}
										}
										if((b==6)&&(p==13))goto casa1;
									}while(1);
								}



							}while(1);
						}



					}while(1);
				}
				gotoxy(52,2);puts("Escudos");  textcolor(4);
				gotoxy(52,3);puts("  /\\");
				gotoxy(52,4);puts(" /  \\");
				gotoxy(52,5);puts("/____\\");  textcolor(7);
				gotoxy(52,6);puts("| _  |");
				gotoxy(52,7);puts("|| |_|");
				if((x==54)&&(y==7)){
					clrscr();
					a=34;b=4;
					casa2:  textcolor(3);
					do{
						gotoxy(3,3) ;printf("______0000000000000000       ");  textcolor(7);gotoxy(35,3);printf("OLA EU POSSO LHE OFERECER ARMADURAS");  textcolor(7);
                        gotoxy(3,4) ;printf("____0000000000000000000000  ");   textcolor(7);gotoxy(35,4);printf("ARUMADURAS");  textcolor(3);
                        gotoxy(3,5) ;printf("__000000000__00000__00000000 ");  textcolor(7);gotoxy(35,5);printf("CALCAS");  textcolor(3);
                        gotoxy(3,6) ;printf("00000000000__00000__000000000") ; textcolor(7);gotoxy(35,6);printf("BOTAS");  textcolor(3);
                        gotoxy(3,7) ;printf("00000000000__00000__0000000000");  textcolor(7);gotoxy(35,7);printf("CAPACETES");  textcolor(3);
                        gotoxy(3,8) ;printf("000000000000000000000000000000");  textcolor(7);gotoxy(35,8);printf("SAIR");  textcolor(3);
                        gotoxy(3,9) ;printf("000000000000000000000000000000"); ;gotoxy(35,9);
                        gotoxy(3,10);printf("000000000000000000000000000000");
                        gotoxy(3,11);printf("000000__________________000000");
                        gotoxy(3,12);printf("000000__________________00000");
                        gotoxy(3,13);printf("_000000_________________00000");
                        gotoxy(3,14);printf("__0000000_____________000000");
                        gotoxy(3,15);printf("____0000000_________0000000");
                        gotoxy(3,16);printf("______ 0000000000000000");
                        p=getch();
						if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==9){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==3){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if((b==8)&&(p==13)){
							x=54;y=8;
							clrscr();goto valyr1;
						}
					}while(2);
				}
				gotoxy(52,14);puts("Hospital");textcolor(4);
				gotoxy(52,15);puts("  /\\");
				gotoxy(52,16);puts(" /  \\");
				gotoxy(52,17);puts("/_+__\\");textcolor(7);
				gotoxy(52,18);puts("| _  |");
				gotoxy(52,19);puts("|| |_|");
					if((x==24)&&(y==19)){
					clrscr();
					a=34;b=4;
					casa3:
					do{
						gotoxy(3,3) ;printf("______0000000000000000       ");  textcolor(7);gotoxy(35,3);printf("OLA EU POSSO LHE OFERECER POCOES E ERVAS");  textcolor(3);
                        gotoxy(3,4) ;printf("____0000000000000000000000  ");   textcolor(7);gotoxy(35,4);printf("PORCAO DE CURA         ");  textcolor(3);
                        gotoxy(3,5) ;printf("__000000000__00000__00000000 ");  textcolor(7);gotoxy(35,5);printf("ERVA DE CURA        ");  textcolor(3);
                        gotoxy(3,6) ;printf("00000000000__00000__000000000");  textcolor(7);gotoxy(35,6);printf("SAIR     "  );  textcolor(3);
                        gotoxy(3,7) ;printf("00000000000__00000__0000000000");  textcolor(7);gotoxy(35,8);printf("POCOES=%d",pocoes);      textcolor(3);
                        gotoxy(3,8) ;printf("000000000000000000000000000000");  textcolor(7);gotoxy(35,9);printf("ERVAS=%d",ervas);  textcolor(3);
                        gotoxy(3,9) ;printf("000000000000000000000000000000");
                        gotoxy(3,10);printf("000000000000000000000000000000");
                        gotoxy(3,11);printf("000000__________________000000");
                        gotoxy(3,12);printf("000000__________________00000");
                        gotoxy(3,13);printf("_000000_________________00000");
                        gotoxy(3,15);printf("____0000000_________0000000");
                        gotoxy(3,16);printf("______ 0000000000000000");
						p=getch();
						if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==3){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if((b==4)&&(p==13)){
							a=34;b=5;
							clrscr();
							do{
							gotoxy(3,3) ;printf("______0000000000000000       ");  textcolor(7);gotoxy(35,3);printf("OTIMA ESCOLHA, ESSA PORCAO CURA 20 DE SUA VIDA     ");  textcolor(3);
                            gotoxy(3,4) ;printf("____0000000000000000000000  ");   textcolor(7);gotoxy(35,4);printf("E CUSTA APENAS 5 REAIS!          ");  textcolor(3);
                            gotoxy(3,6) ;printf("00000000000__0000000000000000");  textcolor(7);gotoxy(35,6);printf("VOLTAR          ");textcolor(3);
                            gotoxy(3,5) ;printf("__000000000__000000000000000 ");  textcolor(7);gotoxy(35,5);printf("COMPRAR       ");      textcolor(3);
                            gotoxy(3,7) ;printf("00000000000__00000__0000000000");  textcolor(7);gotoxy(35,8);printf("                      ");textcolor(3);
                            gotoxy(3,8) ;printf("000000000000000000000000000000");  textcolor(7);gotoxy(35,9);printf("                        ");textcolor(3);
                            gotoxy(3,9) ;printf("000000000000000000000000000000");
                            gotoxy(3,10);printf("000000000000000000000000000000");
                            gotoxy(3,11);printf("000000__________________000000");
                            gotoxy(3,12);printf("000000__________________00000");
                            gotoxy(3,13);printf("_000000_________________00000");
                            gotoxy(3,14);printf("__0000000_____________000000");
                            gotoxy(3,15);printf("____0000000_________0000000");
                            gotoxy(3,16);printf("______ 0000000000000000");
							p=getch();
							if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
							if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
							if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
							if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
							if((b==5)&&(p==13)){
								if(dinheiro>=5){
									dinheiro=dinheiro-5;
									pocoes=pocoes+1;
									goto casa3;
									}
								}
							}while(1);
						}
						if((b==5)&&(p==13)){
							a=34;b=5;
							clrscr();
							do{
							gotoxy(3,3) ;printf("______0000000000000000       ");textcolor(7);gotoxy(35,3);printf("OTIMA ESCOLHA, ESSA ERVA CURA 40 DE SUA VIDA     ");textcolor(3);
                            gotoxy(3,4) ;printf("____0000000000000000000000  "); textcolor(7);gotoxy(35,4);printf("E CUSTA APENAS 30 REAIS!          ");textcolor(3);
                            gotoxy(3,5) ;printf("__000000000__00000__00000000 ");textcolor(7);gotoxy(35,5);printf("COMPRAR       ");textcolor(3);
                            gotoxy(3,6) ;printf("00000000000__00000__000000000");textcolor(7);gotoxy(35,6);printf("VOLTAR          ");textcolor(3);
                            gotoxy(3,7) ;printf("00000000000__00000__0000000000");textcolor(7);gotoxy(35,8);printf("                      ");textcolor(3);
                            gotoxy(3,8) ;printf("000000000000000000000000000000");textcolor(7);gotoxy(35,9);printf("                        ");textcolor(3);
                            gotoxy(3,9) ;printf("000000000000000000000000000000");
                            gotoxy(3,10);printf("000000000000000000000000000000");
                            gotoxy(3,11);printf("000000__________________000000");
                            gotoxy(3,12);printf("000000__________________00000");
                            gotoxy(3,13);printf("_000000_________________00000");
                            gotoxy(3,14);printf("__0000000_____________000000");
                            gotoxy(3,15);printf("____0000000_________0000000");
                            gotoxy(3,16);printf("______ 0000000000000000");
							p=getch();
							if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
							if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
							if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
							if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
							if((b==5)&&(p==13)){
								if(dinheiro>=30){
									dinheiro=dinheiro-30;
									ervas=ervas+1;
									goto casa3;
								}
							}
							if((b==6)&&(p==13))goto casa3;
						}while(1);
					}
						if((b==6)&&(p==13)){
							x=24;y=20;
							clrscr();goto valyr1;
						}
					}while(2);
				}textcolor(7);
				gotoxy(22,14);puts("Curandeiro");textcolor(4);
				gotoxy(22,15);puts("  /\\");
				gotoxy(22,16);puts(" /  \\");
				gotoxy(22,17);puts("/____\\");textcolor(7);
				gotoxy(22,18);puts("| _  |");
				gotoxy(22,19);puts("|| |_|");
				if((x==54)&&(y==19)){
					clrscr();
					a=34;b=5;
					casa4: textcolor(3);
					do{
						gotoxy(3,3) ;printf("______0000000000000000       ");textcolor(7);gotoxy(35,3);printf("OLA BEM VINDO AO HOSPITAL DE VALYR!");textcolor(3);
                        gotoxy(3,4) ;printf("____0000000000000000000000  ");textcolor(7); gotoxy(35,4);printf("POSSO CURAR  SEUS MACHUDADOS?");textcolor(3);
                        gotoxy(3,5) ;printf("__000000000__00000__00000000 ");textcolor(7);gotoxy(35,5);printf("SIM");textcolor(3);
                        gotoxy(3,6) ;printf("00000000000__00000__000000000");textcolor(7);gotoxy(35,6);printf("NAO");textcolor(3);
                        gotoxy(3,7) ;printf("00000000000__00000__0000000000");textcolor(7);gotoxy(35,8);printf("                      ");textcolor(3);
                        gotoxy(3,8) ;printf("000000000000000000000000000000");textcolor(7);gotoxy(35,9);printf("                        ");textcolor(3);
                        gotoxy(3,9) ;printf("000000000000000000000000000000");
                        gotoxy(3,10);printf("000000000000000000000000000000");
                        gotoxy(3,11);printf("000000__________________000000");
                        gotoxy(3,12);printf("000000__________________00000");
                        gotoxy(3,13);printf("_000000_________________00000");
                        gotoxy(3,14);printf("__0000000_____________000000");
                        gotoxy(3,15);printf("____0000000_________0000000");
                        gotoxy(3,16);printf("______ 0000000000000000");
						p=getch();
						if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==7){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
						}
						if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
						}
						if((b==5)&&(p==13)){
							vida1=vida;
							clrscr();textcolor(3);
						gotoxy(3,3) ;printf("______0000000000000000       ");textcolor(7);gotoxy(35,3);printf("PRONTO SEUS MACHUADOS FORAM CURADOS       ");textcolor(3);
                        gotoxy(3,4) ;printf("____0000000000000000000000  "); textcolor(7);gotoxy(35,4);printf("BOA SORTE!                                  ");textcolor(3);
                        gotoxy(3,5) ;printf("__000000000__000000000000000 ");textcolor(7);gotoxy(35,5);printf("                ");textcolor(3);
                        gotoxy(3,6) ;printf("00000000000__0000000000000000");textcolor(7);gotoxy(35,6);printf("                ");textcolor(3);
                        gotoxy(3,7) ;printf("00000000000__00000__0000000000");textcolor(7);gotoxy(35,8);printf("                      ");textcolor(3);
                        gotoxy(3,8) ;printf("000000000000000000000000000000");textcolor(7);gotoxy(35,9);printf("                        ");textcolor(3);
                        gotoxy(3,9) ;printf("000000000000000000000000000000");
                        gotoxy(3,10);printf("000000000000000000000000000000");
                        gotoxy(3,11);printf("000000__________________000000");
                        gotoxy(3,12);printf("000000__________________00000");
                        gotoxy(3,13);printf("_000000_________________00000");
                        gotoxy(3,14);printf("__0000000_____________000000");
                        gotoxy(3,15);printf("____0000000_________0000000");
                        gotoxy(3,16);printf("______ 0000000000000000");
						delay(1000);x=54;y=20;vida=vidamax;
							clrscr();goto valyr1;
						}
						if((b==6)&&(p==13)){
							x=54;y=20;
							clrscr();goto valyr1;
						}
					}while(2);
				}textcolor(7);
			    gotoxy(65,11);printf(" ______");
			    gotoxy(65,12);printf("|SAIDA |");
			    gotoxy(65,13);printf("|  _   |");
			    gotoxy(65,14);printf("|_| |__|");
			    gotoxy(5,11);printf(" ______");
			    gotoxy(5,12);printf("|VALE  |");
			    gotoxy(5,13);printf("|  _   |");
			    gotoxy(5,14);printf("|_| |__|");
			    mover();
			    if((x==8)&&(y==14)){
			    	goto npc1;
}
				if((x==68)&&(y==14)){
					if(condicao==0){
						clrscr();textcolor(3);
						gotoxy(3,3) ;printf("______0000000000000000       ");textcolor(7);gotoxy(35,3);printf("OLA NOVAMENTE!");textcolor(3);
                        gotoxy(3,4) ;printf("____0000000000000000000000  ");textcolor(7); gotoxy(35,4);printf("Saiba que de agora em diante voce ");textcolor(3);
                        gotoxy(3,5) ;printf("__000000000__00000__00000000 ");textcolor(7);gotoxy(35,5);printf(" encontrara perigos,inimigos e amigos.  ");textcolor(3);
                        gotoxy(3,6) ;printf("00000000000__00000__000000000");textcolor(7);gotoxy(35,6);printf("De agora em diante sua aventura comeca de");textcolor(3);
                        gotoxy(3,7) ;printf("00000000000__00000__0000000000");textcolor(7);gotoxy(35,7);printf(" verdade! Espero te ver novamente!");textcolor(3);
                        gotoxy(3,8) ;printf("000000000000000000000000000000");textcolor(7);gotoxy(35,8);printf(" ...BOA SORTE!");textcolor(3);
                        gotoxy(3,9);printf("000000000000000000000000000000");
                        gotoxy(3,10);printf("000000__________________000000");
                        gotoxy(3,11);printf("000000__________________00000");
                        gotoxy(3,12);printf("_000000_________________00000");
                        gotoxy(3,13);printf("__0000000_____________000000");
                        gotoxy(3,14);printf("____0000000_________0000000");
                        gotoxy(3,15);printf("______ 0000000000000000");

						p=getch();
						condicao=condicao+1;
					}
					clrscr();
					x=8;y=15;
					medio:
						ogro_vida=15;
					do{
						int c;
						iniciar_aleatorio();
						c = aleatorio(2,8);
						if(c==5){
							clrscr();
							aaa:
							a=19;b=15;
							do{textcolor(2);
								gotoxy(30, 1);printf("  /\\__/\\");
								gotoxy(30, 2);printf(" /       \\");
								gotoxy(30, 3);printf("| O     O |");
								gotoxy(30, 4);printf("|   \\_/   |");
								gotoxy(30, 5);printf("|   ___   |");
								gotoxy(30, 6);printf(" \\__    __/");
								gotoxy(30, 7);printf(" ___|  |__");
								gotoxy(30, 8);printf("/         \\");textcolor(7);
								gotoxy(32, 9);printf("OGRO");
								gotoxy(32, 10);printf("VIDA:%d",ogro_vida);
								gotoxy(20,15);printf("ATACAR");
								gotoxy(20,16);printf("DEFENDER");
								gotoxy(20,17);printf("ITEM");
								gotoxy(20,18);printf("FUGIR");
								gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
								gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);
								p=getch();
								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
								}
								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
								}
								if(b==19){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
								}
								if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
								}
								if((b==15)&&(p==13)){
									iniciar_aleatorio();
									c = aleatorio(0,espada);
									delay(500);
									gotoxy(20,11);printf("%s ataca o Ogro",nome);
									delay(1000);
									gotoxy(20,12);printf("Tirou %d da vida do inimigo",c);
									ogro_vida=ogro_vida-c;
									if(ogro_vida<=0){
										iniciar_aleatorio();
										c = aleatorio(0,5);
										clrscr();delay(1000);gotoxy(30,12);printf("VOCE VENCEU!");
										gotoxy(30,13);printf("-RECEBEU 10 PONTOS DE EXPERIENCIA");
										gotoxy(30,14);printf("-RECEBEU %d REAIS",c);
										experiencia=experiencia+10;
										dinheiro=dinheiro+c;
										delay(1000);goto medio;
									}
									iniciar_aleatorio();
									c = aleatorio(0,9);
									delay(1500);gotoxy(20,13);printf("Ogro ataca %s",nome);
									delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
									vida=vida-c;
									if(vida<=0){
										vida=0;
										clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
										x=54;y=20;delay(1000);goto valyr1;
									}
									goto aaa;
								}
								if((b==16)&&(p==13)){
									delay(500);
									gotoxy(20,11);printf("%s se defende do Inimigo",nome);
									delay(1000);
									gotoxy(20,12);printf("...");
									goto aaa;
								}
								if((b==17)&&(p==13)){
									a=59;b=15;
									do{textcolor(2);
										gotoxy(30, 1);printf("  /\\__/\\");
										gotoxy(30, 2);printf(" /       \\");
										gotoxy(30, 3);printf("| O     O |");
										gotoxy(30, 4);printf("|   \\_/   |");
										gotoxy(30, 5);printf("|   ___   |");
										gotoxy(30, 6);printf(" \\__    __/");
										gotoxy(30, 7);printf(" ___|  |__");
										gotoxy(30, 8);printf("/         \\");textcolor(7);
										gotoxy(32, 9);printf("OGRO");
										gotoxy(32, 10);printf("VIDA:%d",ogro_vida);
										gotoxy(20,15);printf("ATACAR");
										gotoxy(20,16);printf("DEFENDER");
										gotoxy(20,17);printf("ITEM");
										gotoxy(20,18);printf("FUGIR");
										gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
										gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);gotoxy(60,17);printf("VOLTAR");
										p=getch();
										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==18){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if((b==17)&&(p==13))goto aaa;
										if((b==15)&&(p==13)){
										if(pocoes>=1){
										pocoes=pocoes-1;
										vida=vida+20;
										if(vida>vidamax)vida=vidamax;
										delay(500);
										gotoxy(20,11);printf("%s usa uma porcao",nome);
										delay(1000);
										gotoxy(20,12);printf("recupera 20 pontos de vida");
										iniciar_aleatorio();
										c = aleatorio(0,9);
										delay(1500);gotoxy(20,13);printf("Ogro ataca %s",nome);
										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
										vida=vida-c;
										if(vida<=0){
											vida=0;
											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
											x=54;y=20;delay(1000);goto valyr1;
											}
											goto aaa;
											}
										}
										if((b==16)&&(p==13)){
										if(ervas>=1){
										ervas=ervas-1;
										vida=vida+40;
										if(vida>vidamax)vida=vidamax;
										delay(500);
										gotoxy(20,11);printf("%s usa uma erva",nome);
										delay(1000);
										gotoxy(20,12);printf("Recupera 40 pontos de vida");
										iniciar_aleatorio();
										c = aleatorio(0,9);
										delay(1500);gotoxy(20,13);printf("Ogro ataca %s",nome);
										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
										vida=vida-c;
										if(vida<=0){
											vida=0;
											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
											x=54;y=20;delay(1000);goto valyr1;
											}
											goto aaa;
											}
										}
									}while(1);
								}
								if((b==18)&&(p==13)){
									iniciar_aleatorio();
									c = aleatorio(0,2);delay(500);
									gotoxy(20,11);printf("%s tenta fugir",nome);delay(1000);
									gotoxy(20,12);printf("...");delay(1500);
									if(c==1){clrscr();gotoxy(20,12);printf("VOCE ESCAPOU!");goto medio;}
									iniciar_aleatorio();
									c = aleatorio(0,9);
									delay(1500);gotoxy(20,13);printf("Ogro ataca %s",nome);
									delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
									vida=vida-c;
									if(vida<=0){
										vida=0;
										clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
										x=54;y=20;delay(1000);goto valyr1;
									}
								}
							}while(1);
						}
						gotoxy(5,11);printf(" ______");
			    		gotoxy(5,12);printf("|VALYR |");
			    		gotoxy(5,13);printf("|  _   |");
			    		gotoxy(5,14);printf("|_| |__|");
					    if((x==8)&&(y==14)){
					    	x=68;y=15;
					    	clrscr();
							goto valyr1;
						}textcolor(2);
						gotoxy(20,15);printf("  /\\");
						gotoxy(20,16);printf(" /  \\");
						gotoxy(20,17);printf("/____\\");
						gotoxy(20,18);printf("  ||");
						gotoxy(5 ,5);printf("  /\\");
						gotoxy(5 ,6);printf(" /  \\");
						gotoxy(5 ,7);printf("/____\\");
						gotoxy(5 ,8);printf("  ||");
						gotoxy(60,6);printf("  /\\");
						gotoxy(60,7);printf(" /  \\");
						gotoxy(60,8);printf("/____\\");
						gotoxy(60,9);printf("  ||");
						gotoxy(65,19);printf("  /\\");
						gotoxy(65,20);printf(" /  \\");
						gotoxy(65,21);printf("/____\\");
						gotoxy(65,22);printf("  ||");
						gotoxy(40,2);printf("  /\\");
						gotoxy(40,3);printf(" /  \\");
						gotoxy(40,4);printf("/____\\");
						gotoxy(40,5);printf("  ||");
						gotoxy( 5,20);printf("  /\\");
						gotoxy( 5,21);printf(" /  \\");
						gotoxy( 5,22);printf("/____\\");
						gotoxy(5 ,23);printf("  ||");textcolor(7);
						gotoxy(65,11);printf(" _________");
					    gotoxy(65,12);printf("|FLORESTA |");
					    gotoxy(65,13);printf("|    _    |");
					    gotoxy(65,14);printf("|___| |___|");
						gotoxy(40,21);printf(" _______");
					    gotoxy(40,22);printf("|  SUL  |");
					    gotoxy(40,23);printf("|   _   |");
					    gotoxy(40,24);printf("|__| | _|");
						mover();
					    if((x==70)&&(y==14)){
					    	clrscr();
					    	x=8;y=15;
					    	floresta:
					    	lobo_vida=25;
					    	do{
					    		iniciar_aleatorio();
								c = aleatorio(2,8);
								if(c==5){
									clrscr();
									aaa1:
									a=19;b=15;
									do{textcolor(8);
										gotoxy(30, 1);printf("      /\\__/\\");
										gotoxy(30, 2);printf(" ____/ O   O \\");
										gotoxy(30, 3);printf("|            |");
										gotoxy(30, 4);printf("|/\\/\\/\\      |");
										gotoxy(30, 5);printf("|____________|");
										gotoxy(30, 6);printf("       |     |");
										gotoxy(30, 7);printf("       |_____|");
										gotoxy(30, 8);printf("          ");textcolor(7);
										gotoxy(32, 9);printf("LOBO");
										gotoxy(32, 10);printf("VIDA:%d",lobo_vida);
										gotoxy(20,15);printf("ATACAR");
										gotoxy(20,16);printf("DEFENDER");
										gotoxy(20,17);printf("ITEM");
										gotoxy(20,18);printf("FUGIR");
										gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
										gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);
										p=getch();
										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==19){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
										}
										if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
										}
										if((b==15)&&(p==13)){
											iniciar_aleatorio();
											c = aleatorio(0,espada);
											delay(500);
											gotoxy(20,11);printf("%s ataca o Lobo",nome);
											delay(1000);
											gotoxy(20,12);printf("Tirou %d da vida do inimigo",c);
											lobo_vida=lobo_vida-c;
											if(lobo_vida<=0){
												iniciar_aleatorio();
												c = aleatorio(0,10);
												clrscr();delay(1000);gotoxy(30,12);printf("VOCE VENCEU!");
												gotoxy(30,13);printf("-RECEBEU 20 PONTOS DE EXPERIENCIA");
												gotoxy(30,14);printf("-RECEBEU %d REAIS",c);
												experiencia=experiencia+20;
												dinheiro=dinheiro+c;
												delay(1000);goto floresta;
											}
											iniciar_aleatorio();
											c = aleatorio(0,9);
											delay(1500);gotoxy(20,13);printf("Lobo ataca %s",nome);
											delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
											vida=vida-c;
											if(vida<=0){
												vida=0;
												clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
												x=54;y=20;delay(1000);goto valyr1;
											}
											goto aaa1;
										}
										if((b==16)&&(p==13)){
											delay(500);
											gotoxy(20,11);printf("%s se defende do Inimigo",nome);
											delay(1000);
											gotoxy(20,12);printf("...");
											goto aaa1;
										}
										if((b==17)&&(p==13)){
											a=59;b=15;textcolor(8);
											do{
												gotoxy(30, 1);printf("      /\\__/\\");
												gotoxy(30, 2);printf(" ____/ O   O \\");
												gotoxy(30, 3);printf("|            |");
												gotoxy(30, 4);printf("|/\\/\\/\\      |");
												gotoxy(30, 5);printf("|____________|");
												gotoxy(30, 6);printf("       |     |");
												gotoxy(30, 7);printf("       |_____|");
												gotoxy(30, 8);printf("           ");textcolor(7);
												gotoxy(32, 9);printf("LOBO");
												gotoxy(32, 10);printf("VIDA:%d",lobo_vida);
												gotoxy(20,15);printf("ATACAR");
												gotoxy(20,16);printf("DEFENDER");
												gotoxy(20,17);printf("ITEM");
												gotoxy(20,18);printf("FUGIR");
												gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
												gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);gotoxy(60,17);printf("VOLTAR");
												p=getch();
												if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
												}
												if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
												}
												if(b==18){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
												}
												if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
												}
												if((b==17)&&(p==13))goto aaa1;
												if((b==15)&&(p==13)){
												if(pocoes>=1){
												pocoes=pocoes-1;
												vida=vida+20;
												if(vida>vidamax)vida=vidamax;
												delay(500);
												gotoxy(20,11);printf("%s usa uma porcao",nome);
												delay(1000);
												gotoxy(20,12);printf("recupera 20 pontos de vida");
												iniciar_aleatorio();
												c = aleatorio(0,18);
												delay(1500);gotoxy(20,13);printf("Lobo ataca %s",nome);
												delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
												vida=vida-c;
												if(vida<=0){
													vida=0;
													clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
													x=54;y=20;delay(1000);goto floresta;
													}
													goto aaa1;
													}
												}
												if((b==16)&&(p==13)){
												if(ervas>=1){
												ervas=ervas-1;
												vida=vida+40;
												if(vida>vidamax)vida=vidamax;
												delay(500);
												gotoxy(20,11);printf("%s usa uma erva",nome);
												delay(1000);
												gotoxy(20,12);printf("Recupera 40 pontos de vida");
												iniciar_aleatorio();
												c = aleatorio(0,18);
												delay(1500);gotoxy(20,13);printf("Lobo ataca %s",nome);
												delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
												vida=vida-c;
												if(vida<=0){
													vida=0;
													clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
													x=54;y=20;delay(1000);goto floresta;
													}
													goto aaa1;
													}
												}
											}while(1);
										}
										if((b==18)&&(p==13)){
											iniciar_aleatorio();
											c = aleatorio(0,2);delay(500);
											gotoxy(20,11);printf("%s tenta fugir",nome);delay(1000);
											gotoxy(20,12);printf("...");delay(1500);
											if(c==1){clrscr();gotoxy(20,12);printf("VOCE ESCAPOU!");goto floresta;}
											iniciar_aleatorio();
											c = aleatorio(0,18);
											delay(1500);gotoxy(20,13);printf("Lobo ataca %s",nome);
											delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
											vida=vida-c;
											if(vida<=0){
												vida=0;
												clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
												x=54;y=20;delay(1000);goto floresta;
											}
										}
									}while(1);
								}textcolor(2);
								gotoxy(20,15);printf("  /\\");
								gotoxy(20,16);printf(" /  \\");
								gotoxy(20,17);printf("/____\\");
								gotoxy(20,18);printf("  ||");
								gotoxy(55,15);printf("  /\\");
								gotoxy(55,16);printf(" /  \\");
								gotoxy(55,17);printf("/____\\");
								gotoxy(55,18);printf("  ||");
								gotoxy(70,1);printf("  /\\");
								gotoxy(70,2);printf(" /  \\");
								gotoxy(70,3);printf("/____\\");
								gotoxy(70,4);printf("  ||");
								gotoxy(5 ,5);printf("  /\\");
								gotoxy(5 ,6);printf(" /  \\");
								gotoxy(5 ,7);printf("/____\\");
								gotoxy(5 ,8);printf("  ||");
								gotoxy(30,6);printf("  /\\");
								gotoxy(30,7);printf(" /  \\");
								gotoxy(30,8);printf("/____\\");
								gotoxy(30,9);printf("  ||");
								gotoxy(65,19);printf("  /\\");
								gotoxy(65,20);printf(" /  \\");
								gotoxy(65,21);printf("/____\\");
								gotoxy(65,22);printf("  ||");
								gotoxy( 5,20);printf("  /\\");
								gotoxy( 5,21);printf(" /  \\");
								gotoxy( 5,22);printf("/____\\");
								gotoxy(5 ,23);printf("  ||");textcolor(7);
								gotoxy(40,1);printf(" _______");
							    gotoxy(40,2);printf("| NORTE |");
							    gotoxy(40,3);printf("|   _   |");
							    gotoxy(40,4);printf("|__| | _|");
								gotoxy(5,11);printf(" _______");
							    gotoxy(5,12);printf("| OESTE |");
							    gotoxy(5,13);printf("|   _   |");
							    gotoxy(5,14);printf("|__| | _|");
							    mover();
							    if((x==9)&&(y==14)){
							    	clrscr();x=70;y=15;goto medio;
								}

							    if((x==44)&&(y==4)){
							    	clrscr();x=45;y=25;
							    	norte_floresta:
							    	ladrao_vida=35;
							    	do{
							    		iniciar_aleatorio();
										c = aleatorio(2,8);
										if(c==5){
											clrscr();
											aaa2:
											a=19;b=15;
											do{textcolor(9);
												gotoxy(30, 1);printf("|||||||||||||");
												gotoxy(30, 2);printf("| __  M  __ |");
												gotoxy(30, 3);printf("|  @     @  |");
												gotoxy(30, 4);printf("|    \\_/    |");
												gotoxy(30, 5);printf("|   #####   |");
												gotoxy(30, 6);printf("|___________|");
												gotoxy(30, 7);printf(" ___|    |___");
												gotoxy(30, 8);printf("/            \\        ");textcolor(7);
												gotoxy(32, 9);printf("LADRAO");
												gotoxy(32, 10);printf("VIDA:%d",ladrao_vida);
												gotoxy(20,15);printf("ATACAR");
												gotoxy(20,16);printf("DEFENDER");
												gotoxy(20,17);printf("ITEM");
												gotoxy(20,18);printf("FUGIR");
												gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
												gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);
												p=getch();
												if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
												}
												if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
												}
												if(b==19){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
												}
												if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
												}
												if((b==15)&&(p==13)){
													iniciar_aleatorio();
													c = aleatorio(0,espada);
													delay(500);
													gotoxy(20,11);printf("%s ataca o Ladrao",nome);
													delay(1000);
													gotoxy(20,12);printf("Tirou %d da vida do inimigo",c);
													ladrao_vida=ladrao_vida-c;
													if(ladrao_vida<=0){
														iniciar_aleatorio();
														c = aleatorio(5,25);
														clrscr();delay(1000);gotoxy(30,12);printf("VOCE VENCEU!");
														gotoxy(30,13);printf("-RECEBEU 30 PONTOS DE EXPERIENCIA");
														gotoxy(30,14);printf("-RECEBEU %d REAIS",c);
														experiencia=experiencia+30;
														dinheiro=dinheiro+c;
														delay(1000);goto norte_floresta;
													}
													iniciar_aleatorio();
													c = aleatorio(5,25);
													delay(1500);gotoxy(20,13);printf("O Ladrao ataca %s",nome);
													delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
													vida=vida-c;
													if(vida<=0){
														vida=0;
														clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
														x=54;y=20;delay(1000);goto valyr1;
													}
													goto aaa2;
												}
												if((b==16)&&(p==13)){
													delay(500);
													gotoxy(20,11);printf("%s se defende do Inimigo",nome);
													delay(1000);
													gotoxy(20,12);printf("...");
													goto aaa2;
												}
												if((b==17)&&(p==13)){
													a=59;b=15;
													do{textcolor(9);
														gotoxy(30, 1);printf("|||||||||||||");
														gotoxy(30, 2);printf("| __  M  __ |");
														gotoxy(30, 3);printf("|  @     @  |");
														gotoxy(30, 4);printf("|    \\_/    |");
														gotoxy(30, 5);printf("|   #####   |");
														gotoxy(30, 6);printf("|___________|");
														gotoxy(30, 7);printf(" ___|    |___");
														gotoxy(30, 8);printf("/            \\        ");textcolor(7);
														gotoxy(32, 9);printf("LADRAO");
														gotoxy(32, 10);printf("VIDA:%d",ladrao_vida);
														gotoxy(20,15);printf("ATACAR");
														gotoxy(20,16);printf("DEFENDER");
														gotoxy(20,17);printf("ITEM");
														gotoxy(20,18);printf("FUGIR");
														gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
														gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);gotoxy(60,17);printf("VOLTAR");
														p=getch();
														if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
														}
														if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
														}
														if(b==18){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
														}
														if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
														}
														if((b==17)&&(p==13))goto aaa2;
														if((b==15)&&(p==13)){
														if(pocoes>=1){
														pocoes=pocoes-1;
														vida=vida+20;
														if(vida>vidamax)vida=vidamax;
														delay(500);
														gotoxy(20,11);printf("%s usa uma porcao",nome);
														delay(1000);
														gotoxy(20,12);printf("recupera 20 pontos de vida");
														iniciar_aleatorio();
														c = aleatorio(5,25);
														delay(1500);gotoxy(20,13);printf("Ladrao ataca %s",nome);
														delay(2000);gotoxy(20,14);printf("Tirou %d da vida de NOME",c,nome);
														vida=vida-c;
														if(vida<=0){
															vida=0;
															clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
															x=54;y=20;delay(1000);goto valyr1;
															}
															goto aaa2;
															}
														}
														if((b==16)&&(p==13)){
														if(ervas>=1){
														ervas=ervas-1;
														vida=vida+40;
														if(vida>vidamax)vida=vidamax;
														delay(500);
														gotoxy(20,11);printf("NOME usa uma erva");
														delay(1000);
														gotoxy(20,12);printf("Recupera 40 pontos de vida");
														iniciar_aleatorio();
														c = aleatorio(5,25);
														delay(1500);gotoxy(20,13);printf("Ladrao ataca %s",nome);
														delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
														vida=vida-c;
														if(vida<=0){
															vida=0;
															clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
															x=54;y=20;delay(1000);goto valyr1;
															}
															goto aaa2;
															}
														}
													}while(1);
												}
												if((b==18)&&(p==13)){
													iniciar_aleatorio();
													c = aleatorio(0,2);delay(500);
													gotoxy(20,11);printf("%s tenta fugir",nome);delay(1000);
													gotoxy(20,12);printf("...");delay(1500);
													if(c==1){clrscr();gotoxy(20,12);printf("VOCE ESCAPOU!");goto norte_floresta;}
													iniciar_aleatorio();
													c = aleatorio(5,25);
													delay(1500);gotoxy(20,13);printf("Ladrao ataca %s",nome);
													delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
													vida=vida-c;
													if(vida<=0){
														vida=0;
														clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
														x=54;y=20;delay(1000);goto norte_floresta;
													}
												}
											}while(1);
										}textcolor(2);
										gotoxy(12,3);printf("  /\\");
										gotoxy(12,4);printf(" /  \\");
										gotoxy(12,5);printf("/____\\");
										gotoxy(12,6);printf("  ||");
										gotoxy(10,15);printf("  /\\");
										gotoxy(10,16);printf(" /  \\");
										gotoxy(10,17);printf("/____\\");
										gotoxy(10,18);printf("  ||");
										gotoxy(60,20);printf("  /\\");
										gotoxy(60,21);printf(" /  \\");
										gotoxy(60,22);printf("/____\\");
										gotoxy(60,23);printf("  ||");
										gotoxy(70,2);printf("  /\\");
										gotoxy(70,3);printf(" /  \\");
										gotoxy(70,4);printf("/____\\");
										gotoxy(70,5);printf("  ||");textcolor(7);
										gotoxy(40,21);printf(" _______");
									    gotoxy(40,22);printf("|  SUL  |");
									    gotoxy(40,23);printf("|   _   |");
									    gotoxy(40,24);printf("|__| | _|");
									    if((x==44)&&(y==24)){
							    		clrscr();x=44;y=5;goto floresta;
										}
							    		gotoxy(40,1);printf(" _______");
									    gotoxy(40,2);printf("| EDRON |");
									    gotoxy(40,3);printf("|   _   |");
									    gotoxy(40,4);printf("|__| | _|");
									    mover();
									    if((x==44)&&(y==4)){
											npc2:
											clrscr();
											system("break");
											int a,b;
											char p;
											a=19;b=5;
											do{textcolor(5);
												gotoxy(5,3);printf("|||||||| ");gotoxy(20,3);printf("OLA, O QUE VOCE DESEJA DA CIDADE?");
												gotoxy(5,4);printf("| _  _ |");
												gotoxy(5,5);printf("| O  O |");gotoxy(20,5);printf("ENTRAR");
												gotoxy(5,6);printf("|  <   |");gotoxy(20,6);printf("SAIR");
												gotoxy(5,7);printf("|  __  |");gotoxy(20,7);printf("INFORMACOES");
												gotoxy(5,8);printf("|______|");
												gotoxy(5,9);printf("  )  (");
												p=getch();
												if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
												if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
												if(b==8){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");}
												if(b==4){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");}
												if(((a==19)&&(b==7))&&(p==13)){
													clrscr();
													system("break");
													gotoxy(5,3);printf("|||||||| ");gotoxy(20,3);printf("ESTA CIDADE SE CHAMA EDRON!");
													gotoxy(5,4);printf("| _  _ |");gotoxy(20,4);printf("E COMANDADA POR LORD STHAN, NEM TODOS GOSTAM DELE!");
													gotoxy(5,5);printf("| O  O |");gotoxy(20,5);printf("AQUI FICA A ARENA MEDIA, PARA LUTAR NA GRANDE ARENA,");
													gotoxy(5,6);printf("|  <   |");gotoxy(20,6);printf("VOCE PRECISA DE UMA QUANTIDADE DE VITORIAS AQUI!");
													gotoxy(5,7);printf("|  __  |");gotoxy(20,7);printf("\xFE VOLTAR");
													gotoxy(5,8);printf("|______|");
													gotoxy(5,9);printf("  )  (");textcolor(7);
													p=getch();
													if (p==13){
														clrscr();
														system("break");
														goto npc2;
														}
													}
														if(((a==19)&&(b==6))&&(p==13)){
															clrscr();
															x=44;y=5;
															goto norte_floresta;
															}
														if(((a==19)&&(b==5))&&(p==13)){
															clrscr();
															x=44;y=24;
															edron1:
															do{textcolor(7);
																gotoxy(40,20);printf(" _______");
															    gotoxy(40,21);printf("| SAIDA |");
															    gotoxy(40,22);printf("|   _   |");
															    gotoxy(40,23);printf("|__| | _|");textcolor(4);
																gotoxy(12,3);printf("  /\\");
																gotoxy(12,4);printf(" /  \\");
																gotoxy(12,5);printf("/____\\");textcolor(7);
																gotoxy(12,6);printf("| _  |");
																gotoxy(12,7);printf("|| |_|");textcolor(4);
																gotoxy(12,17);printf("  /\\");
																gotoxy(12,18);printf(" /  \\");
																gotoxy(12,19);printf("/____\\");textcolor(7);
																gotoxy(12,20);printf("| _  |");
																gotoxy(12,21);printf("|| |_|");textcolor(4);
																gotoxy(62,3);printf("  /\\");
																gotoxy(62,4);printf(" /  \\");
																gotoxy(62,5);printf("/____\\");textcolor(7);
																gotoxy(62,6);printf("| _  |");
																gotoxy(62,7);printf("|| |_|");
																gotoxy(62,17);printf("  /\\");textcolor(4);
																gotoxy(62,18);printf(" /  \\");
																gotoxy(62,19);printf("/____\\");textcolor(7);
																gotoxy(62,20);printf("| _  |");
																gotoxy(62,21);printf("|| |_|");
																gotoxy(30,2 );printf(" __________ ");
																gotoxy(30,3 );printf("|  ARENA   |");
																gotoxy(30,4 );printf("|__________|");
																gotoxy(30,5 );printf("|    _     |");
																gotoxy(30,6 );printf("|___| |____|");
																mover();
																if(x==45 && y==23){
																	goto npc2;
																}
																if(x==35 && y==6){
															    	clrscr();
															    	arena:
															    	a=19;b=6;
															    	do{
															    		gotoxy(5,3);printf("|||||||| ");gotoxy(20,3);printf("OLA BEM VINDO A ARENA MEDIA!                         ");
																		gotoxy(5,4);printf("| \\  / |");gotoxy(20,4);printf("SE VOCE SE SAIR BEM AQUI VOCE PODERA PARTICIPAR,     ");
																		gotoxy(5,5);printf("| O  O |");gotoxy(20,5);printf("DA GRANDE ARENA, O MAIOR ESPETACULO DO MUNDO!           "    );
																		gotoxy(5,6);printf("|  <   |");gotoxy(20,6);printf("PARTICIPAR                                     ");
																		gotoxy(5,7);printf("|  __  |");gotoxy(20,7);printf("INFORMACOES                                    ");
																		gotoxy(5,8);printf(" \\____/");gotoxy(20,8);printf("SAIR                                           ");
																		gotoxy(5,9);printf("  |  |");gotoxy(20,9);
																		p=getch();
																		if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																		}
																		if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																		}
																		if(b==5){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																		}
																		if(b==9){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																		}
																		if(b==8 && p==13){
																			x=35;y=7;clrscr();goto edron1;
																		}
																		if(b==7 && p==13){
																		do{
																		p=getch();b==9;
																		gotoxy(5,3);printf("|||||||| ");gotoxy(20,3);printf("BOM A ARENA MEDIA SERVE COMO UM PRE-REQUISITO              ");
																		gotoxy(5,4);printf("| \\  / |");gotoxy(20,4);printf("PARA PARTICIPAR DA GRANDE ARENA, A MAIOR COMPETICAO,        ");
																		gotoxy(5,5);printf("| O  O |");gotoxy(20,5);printf("DO MIUNDO. ONDE VOCE PODERA SE TORNAR O HOMEM MAIS FORTE!     ");
																		gotoxy(5,6);printf("|  <   |");gotoxy(20,6);printf("AQUI VOCE ENFRENTARA GUERREIROS DE MEDIO PODER,               ");
																		gotoxy(5,7);printf("|  __  |");gotoxy(20,7);printf("QUE FIZERAM MUITO MAL AO MUNDO!                               ");
																		gotoxy(5,8);printf(" \\____/");gotoxy(20,8);printf("MOSTRE SEU VALOR E DERROTE-OS!                                ");
																		gotoxy(5,9);printf("  |  |");gotoxy(20,9);printf("\xFE VOLTAR.");
																		if(p==13){
																			clrscr();goto arena;
																		}
																			}while(1);
																		}
																		if(b==6 && p==13){b=6;
																			do{
																			gotoxy(5,3);printf("|||||||| ");gotoxy(20,3);printf("ENTAO VOCE DESEJA PARTICIPAR DA COMPETICAO...     ");
																			gotoxy(5,4);printf("| \\  / |");gotoxy(20,4);printf("SE VOCE ESCOLHER COMECAR, VC VAI PARA A ARENA,    ");
																			gotoxy(5,5);printf("| O  O |");gotoxy(20,5);printf("NESTE EXATO MOMENTO!                               ");
																			gotoxy(5,6);printf("|  <   |");gotoxy(20,6);printf("COMECAR                                             ");
																			gotoxy(5,7);printf("|  __  |");gotoxy(20,7);printf("VOLTAR                                              ");
																			gotoxy(5,8);printf(" \\____/");gotoxy(20,8);printf("                                                    ");
																			gotoxy(5,9);printf("  |  |");gotoxy(20,9);printf("                                                       ");
																			p=getch();textcolor(7);
																			if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																			}
																			if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																			}
																			if(b==5){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																			}
																			if(b==8){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");};
																			if(b==7 && p==13)goto arena;
																			if(b==6 && p==13){clrscr();
																				do{
																					int o;
																					if(CONDICAO==4 && o>=6){
																						gotoxy(20,12);printf("VOCE JA CONQUISTOU A ARENA MEDIA!");
																						delay(2000);goto edron1;x=35;y=7;
																					}
																					for (o=1;o<=7;o++){
																						gotoxy(40,12);printf("PREPARE-SE");
																						delay(1000);gotoxy(40,13);printf("%d",o);

																						if(CONDICAO ==3 && o>=6 ){
																							clrscr();
																							inimigo3:
																							a=19;b=15;
																							popai_vida=200;textcolor(11);
																							do{
																								gotoxy(30, 1);printf("        ______");
																								gotoxy(30, 2);printf("       /      \\");
																								gotoxy(30, 3);printf("      /        |");
																								gotoxy(30, 4);printf("     | \\  /    |");
																								gotoxy(30, 5);printf("     | O   O   |");
																								gotoxy(30, 6);printf("     /  <      |");
																								gotoxy(30, 7);printf("    / \\___     /");
																								gotoxy(30, 8);printf("   |_|________/");textcolor(7);
																								gotoxy(32, 9);printf("POPAI");
																								gotoxy(32, 10);printf("VIDA:%d",popai_vida);
																								gotoxy(20,15);printf("ATACAR");
																								gotoxy(20,16);printf("DEFENDER");
																								gotoxy(20,17);printf("ITEM");
																								gotoxy(20,18);printf("FUGIR");
																								gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
																								gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);
																								p=getch();
																								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																								}
																								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																								}
																								if(b==19){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																								}
																								if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");																									}
																								if((b==15)&&(p==13)){
																									iniciar_aleatorio();
																									c = aleatorio(0,espada);
																									delay(500);
																									gotoxy(20,11);printf("%s ataca Popai",nome);
																									delay(1000);
																									gotoxy(20,12);printf("Tirou %d da vida do inimigo",c);
																									bob_vida=bob_vida-c;
																									if(bob_vida<=0){
																										clrscr();delay(1000);gotoxy(30,12);printf("VOCE VENCEU!");
																										gotoxy(30,13);printf("PARABENS PELA CONQUISTA!         ");
																										gotoxy(30,14);printf("VOCE CONQUISTOU A ARENA MEDIA. CONTINUE ASSIM!");
																										x=35;y=6;
																										delay(1000);CONDICAO=4;goto edron1;
																									}
																									iniciar_aleatorio();
																									c = aleatorio(20,50);
																									delay(1500);gotoxy(20,13);printf("Popai ataca NOME");
																									delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																									vida=vida-c;
																									if(vida<=0){
																										vida=0;
																										clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																										x=54;y=20;delay(1000);goto edron1;
																									}
																									goto inimigo3;
																								}
																								if((b==16)&&(p==13)){
																									delay(500);
																									gotoxy(20,11);printf("NOME se defende do Inimigo");
																									delay(1000);
																									gotoxy(20,12);printf("...");
																									goto inimigo3;
																								}
																								if((b==17)&&(p==13)){
																									a=59;b=15;
																									do{
																										gotoxy(30, 1);printf("        ______");textcolor(11);
																										gotoxy(30, 2);printf("       /      \\");
																										gotoxy(30, 3);printf("      /        |");
																										gotoxy(30, 4);printf("     | \\  /    |");
																										gotoxy(30, 5);printf("     | O   O   |");
																										gotoxy(30, 6);printf("     /  <      |");
																										gotoxy(30, 7);printf("    / \\___     /");
																										gotoxy(30, 8);printf("   |_|________/");textcolor(7);
																										gotoxy(32, 9);printf("POPAI");
																										gotoxy(32, 10);printf("VIDA:%d",popai_vida);
																										gotoxy(20,15);printf("ATACAR");
																										gotoxy(20,16);printf("DEFENDER");
																										gotoxy(20,17);printf("ITEM");
																										gotoxy(20,18);printf("FUGIR");
																										gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
																										gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);gotoxy(60,17);printf("VOLTAR");
																										p=getch();
																										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																										}
																										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																										}
																										if(b==18){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																										}
																										if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																										}
																										if((b==17)&&(p==13))goto inimigo2;
																										if((b==15)&&(p==13)){
																										if(pocoes>=1){
																										pocoes=pocoes-1;
																										vida=vida+20;
																										if(vida>vidamax)vida=vidamax;
																										delay(500);
																										gotoxy(20,11);printf("%s usa uma porcao",nome);
																										delay(1000);
																										gotoxy(20,12);printf("recupera 20 pontos de vida");
																										iniciar_aleatorio();
																										c = aleatorio(20,50);
																										delay(1500);gotoxy(20,13);printf("Popai ataca NOME");
																										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);																											vida=vida-c;
																										if(vida<=0){
																											vida=0;
																											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																											x=54;y=20;delay(1000);goto edron1;
																											}
																											goto inimigo3;
																											}
																										}
																										if((b==16)&&(p==13)){
																										if(ervas>=1){
																										ervas=ervas-1;
																										vida=vida+40;
																										if(vida>vidamax)vida=vidamax;
																										delay(500);
																										gotoxy(20,11);printf("%s usa uma erva",nome);
																										delay(1000);
																										gotoxy(20,12);printf("Recupera 40 pontos de vida");
																										iniciar_aleatorio();
																										c = aleatorio(20,50);
																										delay(1500);gotoxy(20,13);printf("Popai ataca %s",nome);
																										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																										vida=vida-c;
																										if(vida<=0){
																											vida=0;
																											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																											x=54;y=20;delay(1000);goto edron1;
																										}
																											goto inimigo3;
																											}
																										}
																									}while(1);
																								}
																								if((b==18)&&(p==13)){
																									gotoxy(20,11);printf("%s tenta fugir",nome);delay(1000);
																									gotoxy(20,12);printf("IMPOSSIVEL FUGIR DA ARENA!");delay(1500);
																									iniciar_aleatorio();
																									c = aleatorio(20,50);
																									delay(1500);gotoxy(20,13);printf("Popai ataca %s",nome);
																									delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																									vida=vida-c;
																									if(vida<=0){
																										vida=0;
																										clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																										x=54;y=20;delay(1000);goto edron1;
																									}
																								}
																						}while(1);
																					}
																						if(CONDICAO ==2 && o>=6 ){
																							clrscr();
																							inimigo2:
																							a=19;b=15;
																							bob_vida=200;textcolor(6);
																							do{
																								gotoxy(30, 1);printf(" _____________");
																								gotoxy(30, 2);printf("|  \\      /   |");
																								gotoxy(30, 3);printf("|  O      O   |");
																								gotoxy(30, 4);printf("|    \xCD\xCD\xCD      |");
																								gotoxy(30, 5);printf("|    ___      |");
																								gotoxy(30, 6);printf("|_____________|");
																								gotoxy(30, 7);printf("|____< >______|");
																								gotoxy(30, 8);printf("|_____/\\______|");
																								gotoxy(32, 9);printf("BOB SPONJA");textcolor(7);
																								gotoxy(32, 10);printf("VIDA:%d",bob_vida);
																								gotoxy(20,15);printf("ATACAR");
																								gotoxy(20,16);printf("DEFENDER");
																								gotoxy(20,17);printf("ITEM");
																								gotoxy(20,18);printf("FUGIR");
																								gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
																								gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);
																								p=getch();
																								if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																								}
																								if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																								}
																								if(b==19){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																								}
																								if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");																									}
																								if((b==15)&&(p==13)){
																									iniciar_aleatorio();
																									c = aleatorio(0,espada);
																									delay(500);
																									gotoxy(20,11);printf("%s ataca Bob Sponja",nome);
																									delay(1000);
																									gotoxy(20,12);printf("Tirou %d da vida do inimigo",c);
																									bob_vida=bob_vida-c;
																									if(bob_vida<=0){
																										clrscr();delay(1000);gotoxy(30,12);printf("VOCE VENCEU!");
																										gotoxy(30,13);printf("PARABENS PELA CONQUISTA!         ");
																										gotoxy(30,14);printf("VOLTE AMANHA PARA A TERCEIRA LUTA E ULTIMA LUTA!");
																										x=35;y=6;
																										delay(1000);CONDICAO=3;goto edron1;
																									}
																									iniciar_aleatorio();
																									c = aleatorio(15,40);
																									delay(1500);gotoxy(20,13);printf("Bob Sponja ataca %s",nome);
																									delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																									vida=vida-c;
																									if(vida<=0){
																										vida=0;
																										clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																										x=54;y=20;delay(1000);goto edron1;
																									}
																									goto inimigo2;
																								}
																								if((b==16)&&(p==13)){
																									delay(500);
																									gotoxy(20,11);printf("%s se defende do Inimigo",nome);
																									delay(1000);
																									gotoxy(20,12);printf("...");
																									goto inimigo2;
																								}
																								if((b==17)&&(p==13)){
																									a=59;b=15;
																									do{        textcolor(6);
																										gotoxy(30, 1);printf(" _____________");
																										gotoxy(30, 2);printf("|  \\      /   |");
																										gotoxy(30, 3);printf("|  O      O   |");
																										gotoxy(30, 4);printf("|    \xCD\xCD\xCD      |");
																										gotoxy(30, 5);printf("|    ___      |");
																										gotoxy(30, 6);printf("|_____________|");
																										gotoxy(30, 7);printf("|_____< >_____|");
																										gotoxy(30, 8);printf("|______/\\_____|");
																										gotoxy(32, 9);printf("BOB SPONJA");textcolor(7);
																										gotoxy(32, 10);printf("VIDA:%d",bob_vida);
																										gotoxy(20,15);printf("ATACAR");
																										gotoxy(20,16);printf("DEFENDER");
																										gotoxy(20,17);printf("ITEM");
																										gotoxy(20,18);printf("FUGIR");
																										gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
																										gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);gotoxy(60,17);printf("VOLTAR");
																										p=getch();
																										if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																										}
																										if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																										}
																										if(b==18){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																										}
																										if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																										}
																										if((b==17)&&(p==13))goto inimigo2;
																										if((b==15)&&(p==13)){
																										if(pocoes>=1){
																										pocoes=pocoes-1;
																										vida=vida+20;
																										if(vida>vidamax)vida=vidamax;
																										delay(500);
																										gotoxy(20,11);printf("%s usa uma porcao",nome);
																										delay(1000);
																										gotoxy(20,12);printf("recupera 20 pontos de vida");
																										iniciar_aleatorio();
																										c = aleatorio(15,40);
																										delay(1500);gotoxy(20,13);printf("Bob Sponja ataca %s",nome);
																										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);																											vida=vida-c;
																										if(vida<=0){
																											vida=0;
																											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																											x=54;y=20;delay(1000);goto edron1;
																											}
																											goto inimigo2;
																											}
																										}
																										if((b==16)&&(p==13)){
																										if(ervas>=1){
																										ervas=ervas-1;
																										vida=vida+40;
																										if(vida>vidamax)vida=vidamax;
																										delay(500);
																										gotoxy(20,11);printf("%s usa uma erva",nome);
																										delay(1000);
																										gotoxy(20,12);printf("Recupera 40 pontos de vida");
																										iniciar_aleatorio();
																										c = aleatorio(15,40);
																										delay(1500);gotoxy(20,13);printf("Bob Sponja ataca %s",nome);
																										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																										vida=vida-c;
																										if(vida<=0){
																											vida=0;
																											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																											x=54;y=20;delay(1000);goto edron1;
																										}
																											goto inimigo2;
																											}
																										}
																									}while(1);
																								}
																								if((b==18)&&(p==13)){
																									gotoxy(20,11);printf("%s tenta fugir",nome);delay(1000);
																									gotoxy(20,12);printf("IMPOSSIVEL FUGIR DA ARENA!");delay(1500);
																									iniciar_aleatorio();
																									c = aleatorio(10,30);
																									delay(1500);gotoxy(20,13);printf("Bob Sponja ataca %s",nome);
																									delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																									vida=vida-c;
																									if(vida<=0){
																										vida=0;
																										clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																										x=54;y=20;delay(1000);goto edron1;
																									}
																								}
																						}while(1);
																					}

																						if(o>=6){
																							windows_vida=100;
																							clrscr();
																							inimigo1:
																							a=19;b=15;
																								do{      textcolor(15);
																									gotoxy(30, 1);printf(" _______________");
																									gotoxy(30, 2);printf("|  _________ |  |");
																									gotoxy(30, 3);printf("| |         ||  |");
																									gotoxy(30, 4);printf("| | W.VISTA ||  |");
																									gotoxy(30, 5);printf("| |_________|| /");
																									gotoxy(30, 6);printf("|____________|/");
																									gotoxy(30, 7);printf("    __|  |___");
																									gotoxy(30, 8);printf("   |_________|");
																									gotoxy(32, 9);printf("WINDOWS VISTA");textcolor(7);
																									gotoxy(32, 10);printf("VIDA:%d",windows_vida);
																									gotoxy(20,15);printf("ATACAR");
																									gotoxy(20,16);printf("DEFENDER");
																									gotoxy(20,17);printf("ITEM");
																									gotoxy(20,18);printf("FUGIR");
																									gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
																									gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);
																									p=getch();
																									if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																									}
																									if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																									}
																									if(b==19){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																									}
																									if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																									}
																									if((b==15)&&(p==13)){
																										iniciar_aleatorio();
																										c = aleatorio(0,espada);
																										delay(500);
																										gotoxy(20,11);printf("%s ataca Windows Vista",nome);
																										delay(1000);
																										gotoxy(20,12);printf("Tirou %d da vida do inimigo",c);
																										windows_vida=windows_vida-c;
																										if(windows_vida<=0){
																											clrscr();delay(1000);gotoxy(30,12);printf("VOCE VENCEU!");
																											gotoxy(30,13);printf("PARABENS PELA CONQUISTA!         ");
																											gotoxy(30,14);printf("VOLTE AMANHA PARA A SEGUNDA LUTA");
																											x=35;y=6;
																											delay(2000);CONDICAO=2;x=35;y=7;goto edron1;
																										}
																										iniciar_aleatorio();
																										c = aleatorio(10,20);
																										delay(1500);gotoxy(20,13);printf("Windows Vista ataca %s",nome);
																										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																										vida=vida-c;
																										if(vida<=0){
																											vida=0;
																											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																											x=54;y=20;delay(1000);goto edron1;
																										}
																										goto inimigo1;
																									}
																									if((b==16)&&(p==13)){
																										delay(500);
																										gotoxy(20,11);printf("%s se defende do Inimigo",nome);
																										delay(1000);
																										gotoxy(20,12);printf("...");
																										goto inimigo1;
																									}
																									if((b==17)&&(p==13)){
																										a=59;b=15;
																										do{textcolor(15);
																											gotoxy(30, 1);printf(" _______________");
																											gotoxy(30, 2);printf("|  _________ |  |");
																											gotoxy(30, 3);printf("| |         ||  |");
																											gotoxy(30, 4);printf("| | W.VISTA ||  |");
																											gotoxy(30, 5);printf("| |_________|| /");
																											gotoxy(30, 6);printf("|____________|/");
																											gotoxy(30, 7);printf("    __|  |___");
																											gotoxy(30, 8);printf("   |_________|");
																											gotoxy(32, 9);printf("WINDOWS VISTA");textcolor(7);
																											gotoxy(32, 10);printf("VIDA:%d",windows_vida);
																											gotoxy(20,15);printf("ATACAR");
																											gotoxy(20,16);printf("DEFENDER");
																											gotoxy(20,17);printf("ITEM");
																											gotoxy(20,18);printf("FUGIR");
																											gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
																											gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);gotoxy(60,17);printf("VOLTAR");
																											p=getch();
																											if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																											}
																											if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																											}
																											if(b==18){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
																											}
																											if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
																											}
																											if((b==17)&&(p==13))goto inimigo1;
																											if((b==15)&&(p==13)){
																											if(pocoes>=1){
																											pocoes=pocoes-1;
																											vida=vida+20;
																											if(vida>vidamax)vida=vidamax;
																											delay(500);
																											gotoxy(20,11);printf("%s usa uma porcao",nome);
																											delay(1000);
																											gotoxy(20,12);printf("recupera 20 pontos de vida");
																											iniciar_aleatorio();
																											c = aleatorio(10,20);
																											delay(1500);gotoxy(20,13);printf("Windows Vista ataca %s",nome);
																											delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																											vida=vida-c;
																											if(vida<=0){
																												vida=0;
																												clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																												x=54;y=20;delay(1000);goto edron1;
																												}
																												goto inimigo1;
																												}
																											}
																											if((b==16)&&(p==13)){
																											if(ervas>=1){
																											ervas=ervas-1;
																											vida=vida+40;
																											if(vida>vidamax)vida=vidamax;
																											delay(500);
																											gotoxy(20,11);printf("%s usa uma erva",nome);
																											delay(1000);
																											gotoxy(20,12);printf("Recupera 40 pontos de vida");
																											iniciar_aleatorio();
																											c = aleatorio(10,20);
																											delay(1500);gotoxy(20,13);printf("Windows Vista ataca %s",nome);
																											delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																											vida=vida-c;
																											if(vida<=0){
																												vida=0;
																												clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																												x=54;y=20;delay(1000);goto edron1;
																												}
																												goto inimigo1;
																												}
																											}
																										}while(1);
																									}
																									if((b==18)&&(p==13)){
																										gotoxy(20,11);printf("%s tenta fugir",nome);delay(1000);
																										gotoxy(20,12);printf("IMPOSSIVEL FUGIR DA ARENA!");delay(1500);
																										iniciar_aleatorio();
																										c = aleatorio(10,20);
																										delay(1500);gotoxy(20,13);printf("Windows Vista ataca %s",nome);
																										delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
																										vida=vida-c;
																										if(vida<=0){
																											vida=0;
																											clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE EDRON");
																											x=54;y=20;delay(1000);goto edron1;
																										}
																									}
																								}while(1);
																							}
																						}
																					}while(1);
																					}
																				}while(1);
																			}
																		}while(1);
																	}

																if((x==44)&&(y==6)){
															    	goto npc2;
																}

															    							}while(1);
																							}
																							}while(1);
																						}
																						}while(1);
																					}
																				}while(1);
																		}
						if((x==44)&&(y==24)){
					    	clrscr();
					    	x=45;y=5;
					    	grande_arena:
					    	do{
					    		mover();
								int c;
								gotoxy(40,20);printf(" ____   _____");
								gotoxy(40,21);printf("|    |_|     |");
								gotoxy(40,22);printf("|            |");
								gotoxy(40,23);printf("|            |");
								gotoxy(40,24);printf("|GRANDE ARENA|");
								gotoxy(40,25);printf("|____________|");
								gotoxy(40,1);printf(" _______");
							    gotoxy(40,2);printf("| NORTE |");
							    gotoxy(40,3);printf("|   _   |");
							    gotoxy(40,4);printf("|__| | _|");
							    if((x==44)&&(y==4)){
							    	clrscr();x=44;y=20;
							    	goto medio;
								}
								if((x==46)&&y==20){
									if(CONDICAO<4){
										clrscr();
										do{
											gotoxy(20,3);printf("  ||||||        VOCE NAO CONQUISTOU A ARENA MEDIA!");
											gotoxy(20,4);printf(" /      \\      VA ATE EDRON E CONQUISTE-A !");
											gotoxy(20,5);printf("| \\    / |     OU ENTAO NUNCA IRA PARTICIPAR DA GRANDE ARENA");
											gotoxy(20,6);printf("| U    U |");
											gotoxy(20,7);printf("|   <    |");
											gotoxy(20,8);printf("|  ____  |");
											gotoxy(20,9);printf(" \\_____ /");
											gotoxy(20,10);printf("  _|___|_");
											delay(3000);x=43;y=20;goto grande_arena;
										}while(1);//while da condicao <4 
									}//IF DA CONDICAO
									if(CONDICAO>=4){
										clrscr();
										a=38;b=7;
										do{
											gotoxy(15,3);printf("  ||||||       ENTAO QUE DIZER QUE VOCE CONQUISTOU A ARENA MEDIA");
											gotoxy(15,4);printf(" /      \\     POIS BEM! E DIGNO DE ENFRENTAR O REI WANDAYMO");
											gotoxy(15,5);printf("| \\    / |    BOA SORTE! TENTE DESTRUI-LO E TRONE-SE O REI!");
											gotoxy(15,6);printf("| U    U |");
											gotoxy(15,7);printf("|   <    |     COMECAR!");
											gotoxy(15,8);printf("|  ____  |     SAIR.");
											gotoxy(15,9);printf(" \\_____ /");
											gotoxy(15,10);printf("  _|__|_");
											p=getch();
											if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("<-");
											}
											if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("<-");
											}
											if(b==9){clrscr();b=b-1;gotoxy(a,b);printf("<-");
											}
											if(b==6){clrscr();b=b+1;gotoxy(a,b);printf("<-");
											}
											if(b==8 && p==13){
												clrscr();x=43;y=20;goto grande_arena;	
											}
											if(b==7 && p==13){
												clrscr();
												delay(4000);
												a=19;b=15;
												wandaymo_vida=800;
												wandaymo:
												do{
													gotoxy(30, 1);printf("  0000000");
													gotoxy(30, 2);printf(" /       \\");
													gotoxy(30, 3);printf("| O     O |");
													gotoxy(30, 4);printf("|   \\_/   |");
													gotoxy(30, 5);printf("|   ___   |");
													gotoxy(30, 6);printf(" \\_,,,,__/");
													gotoxy(30, 7);printf(" ___|  |__");
													gotoxy(30, 8);printf("/         \\");
													gotoxy(32, 9);printf("KING WANDAYMO");
													gotoxy(32, 10);printf("VIDA:%d",wandaymo_vida);
													gotoxy(20,15);printf("ATACAR");
													gotoxy(20,16);printf("DEFENDER");
													gotoxy(20,17);printf("ITEM");
													gotoxy(20,18);printf("FUGIR");
													gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
													gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);
													p=getch();
													if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
													}
													if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
													}
													if(b==19){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
													}
													if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
													}
													if((b==15)&&(p==13)){
														iniciar_aleatorio();
														c = aleatorio(0,espada);
														delay(500);
														gotoxy(20,11);printf("%s ataca o Wandaymo",nome);
														delay(1000);
														gotoxy(20,12);printf("Tirou %d da vida do inimigo",c);
														wandaymo_vida=wandaymo_vida-c;
														if(wandaymo_vida<=0){
															clrscr();
															delay(5000);
															do{
																	int i;
																		for (i==1;i<=15;i++){
																			delay(300);
																			clrscr();
																			gotoxy(i,1);puts("VOCE VENCEU! FINALMENTE ALGUEM CONSEGUIU O QUE MUITOS TENTARAM!");
																			}
																			i=0;
																		for(i==1;i<=15;i++){
																			delay(300);
																			clrscr();
																			gotoxy(i+4,3);puts("VOCE VENCEU O HORRIVEL REI WANDAYMO!");
																		}
																		i=0;
																		for(i==1;i<=15;i++){
																			delay(300);
																			clrscr();
																			gotoxy(i+10,5);puts("DE HOJE EM DIANTE VOCE SERA O NOVO REI!");
																		}
																		i=0;
																		for(i==1;i<=15;i++){
																			delay(300);
																			clrscr();
																			gotoxy(i+15,7);puts("TENHO CERTEZA DE QUE VOCE SERA UM REI MUITO MELHOR!");
																		}
																		i=0;
																		for(i==1;i<=15;i++){
																			delay(300);
																			clrscr();
																			gotoxy(i+10,15);puts("ANDREY&MAIKON S.A AGRADECE O TEMPO QUE VC PERDEU!");}
																			i=0;
																		for(i==1;i<=15;i++){
																			delay(300);
																			clrscr();
																			gotoxy(i+50,20);puts("FIM....");
																			}
																			clrscr();
																			delay(3000);
																		
															}while(1);//do fim
														}
														iniciar_aleatorio();
														c = aleatorio(20,50);
														delay(1500);gotoxy(20,13);printf("Wandaymo ataca %s",nome);
														delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
														vida=vida-c;
														if(vida<=0){
															vida=0;
															clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
															x=54;y=20;delay(1000);goto valyr1;
														}
														goto wandaymo;
													}	
													if((b==16)&&(p==13)){
														delay(500);
														gotoxy(20,11);printf("%s se defende do Inimigo",nome);
														delay(1000);
														gotoxy(20,12);printf("...");
														goto wandaymo;
													}
													if((b==17)&&(p==13)){
														a=59;b=15;
														do{
															gotoxy(30, 1);printf("  0000000");
															gotoxy(30, 2);printf(" /       \\");
															gotoxy(30, 3);printf("| O     O |");
															gotoxy(30, 4);printf("|   \\_/   |");
															gotoxy(30, 5);printf("|   ___   |");
															gotoxy(30, 6);printf(" \\_,,,,__/");
															gotoxy(30, 7);printf(" ___|  |__");
															gotoxy(30, 8);printf("/         \\");
															gotoxy(32, 9);printf("KING WANDAYMO");
															gotoxy(32, 10);printf("VIDA:%d",wandaymo_vida);
															gotoxy(20,15);printf("ATACAR");
															gotoxy(20,16);printf("DEFENDER");
															gotoxy(20,17);printf("ITEM");
															gotoxy(20,18);printf("FUGIR");
															gotoxy(40,15);printf("VIDA:%d  ",vida);gotoxy(60,15);printf("POCOES= %d",pocoes);
															gotoxy(40,16);printf("ENERGIA:%d  ",energia);gotoxy(60,16);printf("ERVAS= %d",ervas);gotoxy(60,17);printf("VOLTAR");
															p=getch();
															if(p==80){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
															}
															if(p==72){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
															}
															if(b==18){clrscr();b=b-1;gotoxy(a,b);printf("\xFE");
															}
															if(b==14){clrscr();b=b+1;gotoxy(a,b);printf("\xFE");
															}
															if((b==17)&&(p==13))goto wandaymo;
															if((b==15)&&(p==13)){
															if(pocoes>=1){
															pocoes=pocoes-1;
															vida=vida+20;
															if(vida>vidamax)vida=vidamax;
															delay(500);
															gotoxy(20,11);printf("%s usa uma porcao",nome);
															delay(1000);
															gotoxy(20,12);printf("recupera 20 pontos de vida");
															iniciar_aleatorio();
															c = aleatorio(20,50);
															delay(1500);gotoxy(20,13);printf("Wandaymo ataca %s",nome);
															delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
															vida=vida-c;
															if(vida<=0){
																vida=0;
																clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
																x=54;y=20;delay(1000);goto valyr1;
																}
																goto wandaymo;	
																}
															}
															if((b==16)&&(p==13)){
															if(ervas>=1){
															ervas=ervas-1;
															vida=vida+40;
															if(vida>vidamax)vida=vidamax;
															delay(500);
															gotoxy(20,11);printf("%s usa uma erva",nome);
															delay(1000);
															gotoxy(20,12);printf("Recupera 40 pontos de vida");
															iniciar_aleatorio();
															c = aleatorio(20,50);
															delay(1500);gotoxy(20,13);printf("Wandaymo ataca %s",nome);
															delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
															vida=vida-c;
															if(vida<=0){
																vida=0;
																clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
																x=54;y=20;delay(1000);goto valyr1;
																}
																goto wandaymo;	
																}
															}
														}while(1);
													}
													if((b==18)&&(p==13)){
														iniciar_aleatorio();
														c = aleatorio(0,2);delay(500);
														gotoxy(20,11);printf("%s tenta fugir",nome);delay(1000);
														gotoxy(20,12);printf("...");delay(1500);
														gotoxy(20,13);printf("IMPOSSIVEL FUGIR DA GRANDE ARENA");
														iniciar_aleatorio();
														c = aleatorio(20,50);
														delay(1500);gotoxy(20,13);printf("Wandaymo ataca %s",nome);
														delay(2000);gotoxy(20,14);printf("Tirou %d da vida de %s",c,nome);
														vida=vida-c;
														if(vida<=0){
															vida=0;
															clrscr();gotoxy(10,12);delay(1000);printf("VOCE PERDEU. SEU CORPO SERA LEVADO AO HOSPITAL DE VALYR");
															x=54;y=20;delay(1000);goto valyr1;
														}
													}
												}while(1);//do comecar
											}//DO COMECAR
										}while(1);//da arena;
									}//DA CONDICAO >4
								}//IF DA GRANDE ARENA
							}while(1);
						}
					}while(1);
				}
																	}while(1);
																}
											}while(1);
										}
									}while(1);
								}


int main (){
	x=11;y=12;
	dinheiro=100;
	espada1=1;nivel=1;espada=espada+espada1;machado=1;escudo=1;arco=1;lanca=1;vida=20;energia=5;
	vidamax=vida;energiamax=energia;

    char tecla;
    int a,b;

    retorno:
    a=38;
    b=18;
    do{
    do
    {
        gotoxy(10,3 );textcolor(6);
        printf("       ®®®        ®®®®®®®      ®®®®®®®     ®®®   ®®        ®®®®       ");textcolor(4);
        gotoxy(10,4 );
        printf("      ®®®®®       ®®®  ®®®     ®®®         ®®®®  ®®        ®®®®       ");textcolor(6);
        gotoxy(10,5 );
        printf("      ®® ®®®      ®®®®®®®      ®®®®®®®     ®®®®® ®®       ®® ®®®      ");textcolor(4);
        gotoxy(10,6 );
        printf("     ®®® ®®®      ®®®®®®       ®®®         ®®® ®®®®      ®®®  ®®      ");textcolor(6);
        gotoxy(10,7 );
        printf("     ®®®®®®®®     ®®®  ®®      ®®®®®®®     ®®®  ®®®      ®®®®®®®®     ");textcolor(4);
        gotoxy(10,8 );
        printf("    ®®®   ®®®     ®®®  ®®®     ®®®®®®®     ®®®   ®®     ®®®    ®®     ");textcolor(6);
        gotoxy(10,9 );
        printf("");
        gotoxy(10,10);
        printf("");
        gotoxy(10,11);
        printf("                    ®®®®®®®      ®®®®®®®      ®®®®®®®            ");textcolor(4);
        gotoxy(10,12);
        printf("                    ®®   ®®®     ®®®  ®®     ®®®                ");textcolor(6);
        gotoxy(10,13);
        printf("                    ®®®®®®®      ®®®®®®®     ®®® ®®®®®           ");textcolor(4);
        gotoxy(10,14);
        printf("                    ®®  ®®®      ®®®         ®®®   ®®®           ");textcolor(6);
        gotoxy(10,15);
        printf("                    ®®   ®®®     ®®®          ®®®®®®®	          ");textcolor(4);
        gotoxy(10,16 );
        printf("");
        gotoxy(10,17 );
        printf("");
        gotoxy(10,18 );
        printf("");
        gotoxy(40,18);textcolor(13);
        printf(" Novo Jogo");
        gotoxy(40,20);
        printf(" Informacoes");textcolor(7);
        tecla=getch();
        if(tecla==80)
        {
            clrscr();
            b=b+2;
            gotoxy(a,b);
            printf("->");
        }
        if(tecla==72)
        {
            clrscr();
            b=b-2;
            gotoxy(a,b);
            printf("->");
        }
        if(b==22)
        {
            clrscr();
            b=b-2;
            gotoxy(a,b);
            printf("->");
        }
        if(b==16)
        {
            clrscr();
            b=b+2;
            gotoxy(a,b);
            printf("->");
        }
        if(b==18&&tecla==13)
        {
            clrscr();
            do
            {
                gotoxy(5,4);textcolor(3);
                printf("______0000000000000000   ");
                gotoxy(5,5);
                printf("____0000000000000000000000          Ola, Seja bem vindo a Arena");
                gotoxy(5,6);
                printf("_000000000__00000__0000000000       A partir de agora voce embarcara em um ");
                gotoxy(5,7);
                printf("0000000000__00000__00000000000      mundo de aventuras ");
                gotoxy(5,8);
                printf("0000000000__00000__00000000000         Pressione Enter   " );
                gotoxy(5,9);
                printf("000000000000000000000000000000 ");
                gotoxy(5,10);
                printf("000000000000000000000000000000"     );
                gotoxy(5,11);
                printf("000000__________________000000  " );
                gotoxy(5,12);
                printf("000000__________________000000"    );
                gotoxy(5,13);
                printf("_000000_________________00000"  );
                gotoxy(5,14);
                printf("__0000000_____________000000"   );
                gotoxy(5,15);
                printf("____0000000_________0000000"    );
                gotoxy(5,16);
                printf("______ 0000000000000000"     );


                tecla=getch();

                if(tecla==13)
                {
                    clrscr();
                    do
                    {
                        gotoxy(5,4);
                        printf("______0000000000000000        "  );
                        gotoxy(5,5);
                        printf("____0000000000000000000000               Mas primeiramente me ");
                        gotoxy(5,6);
                        printf("_000000000__00000__0000000000              diga seu nome  " );
                        gotoxy(5,7);
                        printf("0000000000__00000__00000000000   "   );
                        gotoxy(5,8);
                        printf("0000000000__00000__00000000000   ");
                        gotoxy(5,9);
                        printf("000000000000000000000000000000 ");
                        gotoxy(5,10);
                        printf("000000000000000000000000000000"     );
                        gotoxy(5,11);
                        printf("000000__________________000000  " );
                        gotoxy(5,12);
                        printf("000000__________________000000"    );
                        gotoxy(5,13);
                        printf("_000000_________________00000"  );
                        gotoxy(5,14);
                        printf("__0000000_____________000000"   );
                        gotoxy(5,15);
                        printf("____0000000_________0000000"    );
                        gotoxy(5,16);
                        printf("______ 0000000000000000"     );
                        gotoxy(5,17);
                        printf(""            );
                          gotoxy(45,9); fgets(nome,5,stdin);
                          clrscr();


                        do
                        {   gotoxy(5,3);
                            printf("  %s   ",nome);
                            gotoxy(5,4);
                            printf("  Voce esta no planeta AP1                ______0000000000000000        " );
                            gotoxy(5,5);
                            printf("  Nesse planeta existe diversas formas de ____0000000000000000000000"        );
                            gotoxy(5,6);
                            printf("  vida,aconselho que tome cuidade ao se   _000000000__000000000000000"     );
                            gotoxy(5,7);
                            printf("  aventurar por aqui !                    0000000000__0000000000000000"    );
                            gotoxy(5,8);
                            printf("                                          0000000000__0000000__00000000"   );
                            gotoxy(5,9);
                            printf("   Pressione Enter                        000000000000000000000000000000"    );
                            gotoxy(5,10);
                            printf("                                          000000000000000000000000000000"  );
                            gotoxy(5,11);
                            printf("                                          000000__________________000000");
                            gotoxy(5,12);
                            printf("                                          _000000_________________00000" );
                            gotoxy(5,13);
                            printf("                                          __0000000_____________000000" );
                            gotoxy(5,14);
                            printf("                                          ____0000000_________0000000"  );
                            gotoxy(5,15);
                            printf("                                          ______ 0000000000000000"        );
                            gotoxy(5,16);
                            tecla=getch();

 clrscr();
                           principal();
                        }
                        while(1);

                    }
                    while(1);

                }
            }
            while(1);
        }

            if(b==20&&tecla==13)
            {
                clrscr();textcolor(7);
                do
                {
                    printf(" O jogo Arena foi criado pela empresa AndreyMaikon S.A"
                           "\nNo ano de 2015,e tem como principal objetivo de levar"
                           "\nentretenimento a todas as pessoas,nesse jogo voce se aventura"
                           " \npor um mundo onde a imaginacao nao tem fim,"
                           "\ntrava batalhas com diversos inimigos, e a cada vitora ganha"
                           " \nexperiencia com isso vc podera aperfeicoar suas armas e avancar"
                           "\n de fase no jogo."
                           "  \nVoce encontrara inimigos facilmente andando fora da cidade"
                           "\nou tambem podera ir direto a Arena onde entrara em um torneio,"
                           " \nvoce tera que vencer todas as batalhas travadas, caso nao consiga"
                           "\ne perca todo seu sangue,sera encaminhado ao centro medico, onde recebera"
                           "\ncuidados de uma equipe especializada, "
                           "\nAndando pela cidade Valyr voce encontrara duas lojas onde podera comprar pocoes "
                           "\ne armas, assim melhorar seu desempenho no jogo."
                           "\nAgora voce esta preparado para se aventurar nesse mundo Magico!\n"

                           " \nPressione Enter Para informacoes tecninas");
                    tecla=getch();


                      clrscr();
                        printf(" INFORMACOES TECNICAS:"
                               "Esse progama foi criado usando os programas Code::Blocks e Dev-C++"
                               "\nforam necesarias 2890 linhas de codigo,"
                               "\nPara a contrucao do codigo foram usados os seguintes comandos:"
                               "\nComando if - else"
                               "\nEstrutura condicional com mais de um comando"
                               "\n(Condições compostas)"
                               "\nCondicoes (Aninhadas - Encadeadas)"
                               " \nEscolha Caso (Switch Case-Linguagem C),"
                               "\nlaco de repeticao (do_while,for,while)"
                               "\nclrscr : comando usado para limpar a tela,"
                               " \ngotoxy: Usado para posicionar os caracters na tela"
                               "\n delay: Usado para diminuir a velocidade de algumas partes"
                               "\ntextcolor: Para mudar a cor da fonte no programa"
                               "\nFucao que gera numeros aleatorios de um determinado intervalo"
                               "Matrizes,Vetores,Strings e muito mais!"
                               "\n\n Pressione enter para voltar ao menu inicial"
                              );
                                 tecla=getch();

                                        clrscr();
                                    goto retorno;



                }
                while(1);

            }
        }while(1);
        }while(1);
        return 0;
}





/*
	Developer: Pech Aguilar Abel Efrain
	Computer Engineering Student
	Institution: Universidad Autonoma de Baja California
	Date: May 2011
	Chess Game using simple graphics
*/

#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <ajedrez.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int A[5];
int band;
typedef int matriz [8][8];
matriz M;
char jug1[15];
char jug2[15];
int L[6];
char file[15];
int k=0;
struct registro
{
	char nombre1[15];
	char nombre2[15];
	matriz M;
}R;

void graba(char *name, matriz M, char jug1[15],char jug2[15])
{
 FILE *arch;
 int i,j;
 arch=fopen(name, "w");
 for(i=0;i<15;i++)
 {
 R.nombre1[i]=jug1[i];
 R.nombre2[i]=jug2[i];}
 for(i=0;i<8;i++)
 for(j=0;j<8;j++)
 
 R.M[i][j]=M[i][j];
 fwrite(&R, sizeof(struct registro),1,arch);
 fclose(arch);
}

void abre(char *name)
{
 FILE *arch;
 int i,j;
 arch = fopen(name, "r");
 for(i=0;i<15;i++){
 fread(&R,sizeof(struct registro),1,arch);
 jug1[i]=R.nombre1[i];
 jug2[i]=R.nombre2[i];}
 for(i=0;i<8;i++)
 for(j=0;j<8;j++)
{fread(&R,sizeof(struct registro),1,arch);
 M[i][j]=R.M[i][j];
 }
 fclose(arch);
}
void captura1(int x, int y)
{
   char tecla;
   int pos;
   jug1[0]='\x0';
   do
   {
      setcolor(WHITE);
      outtextxy(x,y,jug1);
      tecla=getch();

     if (strlen(jug1) < 14)
     {
      if (isalpha(tecla) || tecla=='.' || tecla==' ' || isdigit(tecla))
      {
	 pos = strlen(jug1);
	 jug1[pos] = tecla;
	 jug1[pos+1]='\x0';
      }
     }
      if (tecla=='\x8')
      {
	 setcolor(BLUE);
	 outtextxy(x,y,jug1);
	 pos=strlen(jug1);
	 jug1[pos-1]='\x0';
      }

   }
   while (tecla != '\xd');
}

void captura2(int x, int y)
{
   char tecla;
   int pos;
   jug2[0]='\x0';
   do
   {
      setcolor(WHITE);
      outtextxy(x,y,jug2);
      tecla=getch();

     if (strlen(jug2) < 14)
     {
      if (isalpha(tecla) || tecla=='.' || tecla==' ' || isdigit(tecla))
      {
	 pos = strlen(jug2);
	 jug2[pos] = tecla;
	 jug2[pos+1]='\x0';
      }
     }
      if (tecla=='\x8')
      {
	 setcolor(BLUE);
	 outtextxy(x,y,jug2);
	 pos=strlen(jug2);
	 jug2[pos-1]='\x0';
      }

   }
   while (tecla != '\xd');

}

void archivo(int x, int y)
{
   char tecla;
   int pos;
   file[0]='\x0';
   do
   {
      setcolor(WHITE);
      outtextxy(x,y,file);
      tecla=getch();

     if (strlen(file) < 14)
     {
      if (isalpha(tecla) || tecla=='.' || tecla==' ' || isdigit(tecla))
      {
	 pos = strlen(file);
	 file[pos] = tecla;
	 file[pos+1]='\x0';
      }
     }
      if (tecla=='\x8')
      {
	 setcolor(BLUE);
	 outtextxy(x,y,file);
	 pos=strlen(file);
	 file[pos-1]='\x0';
      }

   }
   while (tecla != '\xd');

}


void msgcnt(char *frase,int x)
{ setcolor(WHITE);
  box(10, 300,160, 315, 1, DARKGRAY);
  outtextxy(15,305,"Centro de Mensajes");
  box(10,315,160,340,1,YELLOW);
  setcolor(LIGHTBLUE);
  outtextxy(20, 325, frase);
  setcolor(WHITE);
  if (x==1) getch();
  if (x==0);
  else box(10,315,160,340,1,BLUE);
  
}



void menusjuego()
{
	box(10,10,77,30,9, LIGHTGRAY);
	outtextxy(15,17, "ARCHIVO");
	box(87, 10, 160, 30, 9, LIGHTGRAY);
	outtextxy(92, 17, "OPCIONES");
	box(180,10, 290, 30, 9, LIGHTGRAY);
	outtextxy(185, 17, "ACERCA DE...");


}

void menuarchivo()
{
	box(10,30,77,60,9, LIGHTGRAY);
	outtextxy(25, 40, "Nuevo");
	box(10, 60, 77, 90, 9, LIGHTGRAY);
	outtextxy(25, 70, "Abrir");
	box(10, 90, 77, 120, 9, LIGHTGRAY);
	outtextxy(17, 100, "Guardar");
	box(10, 120, 77, 150, 9, LIGHTGRAY);
	outtextxy(25, 130, "Salir");


}

void menuopciones()
{	box(87,30,160,60, 9, LIGHTGRAY);
	outtextxy(92, 42, "Deshacer");
	box(87,60,160,90,9,LIGHTGRAY);
	outtextxy(95, 72, "Rehacer");

}

void nombres()
{setfillstyle(1,BLUE);
 bar(319,49,440,60);
 bar(319,409,440,440);
 setcolor(BLUE); 
 box(10,31,77,150,1,BLUE);
 setcolor(WHITE);
 msgcnt("Nombre Blancas?",0);
 captura1(35,350);
 setfillstyle(1,BLUE);	
 bar(34,349, 150,380);
 setcolor(WHITE); 
 msgcnt("Nombre Negras?",0);
 captura2(35,350);
 setfillstyle(1,BLUE);	
 bar(34,349, 150,380);
 setcolor(WHITE); 
 outtextxy(320,410,jug1);
 outtextxy(320,50,jug2);
 box(10,315,160,340,1,BLUE);
}

void imprime()
{setfillstyle(1,BLUE);
 bar(319,49,440,60);
 bar(319,409,440,440);
 outtextxy(320,410,jug1);
 outtextxy(320,50,jug2);
}

void filename(matriz M)
{
 setcolor(WHITE);
 msgcnt("Nombre Archivo",0);
 archivo( 35,350);
 setfillstyle(1,BLUE);
 bar(34,349,150,380);
 graba(file, M, jug1,jug2);
 box(10,315,160,340,1,BLUE);
}
void open(matriz &M)
{
 setcolor(WHITE);
 msgcnt("Nombre Archivo",0);
 archivo( 35, 350);
 setfillstyle(1,BLUE);
 bar(34,349,150,380);
 abre(file);
 box(10,315,160,340,1,BLUE);
}
void menutab(int &b)
{	int v;
	int c;
        char tecla;
	char car;
	int j=1;
	int pos=1;
	
	menusjuego();

	do {  band=0;  setcolor(WHITE);
		switch(j)
		{
		  case 1:
			box(10,10,77,30,9, DARKGRAY);
			outtextxy(15,17, "ARCHIVO");
			break;
		  case 2:
			box(87, 10, 160, 30, 9, DARKGRAY);
			outtextxy(92, 17, "OPCIONES");
			break;
		  case 3:
			box(180,10, 290, 30, 9, DARKGRAY);
			outtextxy(185, 17, "A CERCA DE...");
		}
		tecla=getch();
		switch(j)
		{  case 1:
			box(10,10,77,30,9, LIGHTGRAY);
			outtextxy(15,17, "ARCHIVO");
			break;
		  case 2:
			box(87, 10, 160, 30, 9, LIGHTGRAY);
			outtextxy(92, 17, "OPCIONES");
			break;
		  case 3:
			box(180,10, 290, 30, 9, LIGHTGRAY);
			outtextxy(185, 17, "ACERCA DE...");
		}

		switch(tecla)
		{
		 case '\x0':	tecla=getch();
				switch(tecla)
				{ case '\x4B': j--; break;
				  case '\x4D': j++; break;
				}
				if(j>3)j=3;
				if(j<1)j=1;
				break;
		case '\x1B': band=1;break;
		case '\xD':   switch(j)
				{ case 1: pos=1;menuarchivo();
					 do{	  switch(pos)
					  {
						case 1:
						box(10,30,77,60,9, DARKGRAY);
						outtextxy(25, 40, "Nuevo");
						break;
						case 2:
						box(10, 60, 77, 90, 9, DARKGRAY);
						outtextxy(25, 70, "Abrir");
						break;
						case 3:
						box(10, 90, 77, 120, 9, DARKGRAY);
						outtextxy(17, 100, "Guardar");
						break;
						case 4:
						box(10, 120, 77, 150, 9, DARKGRAY);
						outtextxy(25, 130, "Salir");
						break;
						}
						car=getch();
						 switch(pos)
						 {
						 case 1:
						box(10,30,77,60,9, LIGHTGRAY);
						outtextxy(25, 40, "Nuevo");
						break;
						 case 2:
						box(10, 60, 77, 90, 9, LIGHTGRAY);
						outtextxy(25, 70, "Abrir");
						break;
						 case 3:
						box(10, 90, 77, 120, 9, LIGHTGRAY);
						outtextxy(17, 100, "Guardar");
						break;
						 case 4:
						box(10, 120, 77, 150, 9, LIGHTGRAY);
						outtextxy(25, 130, "Salir");
						break;
						 }

						 switch(car)
						 {
						  case '\x0': car=getch();
							 switch(car)
							 {
							 case '\x48': pos--; break;
							 case '\x50': pos++; break;
							 }
							 if (pos>4) pos=4;
							 if (pos<1) pos=1;
							 break;
						  case '\xD': switch(pos)
							 {
							 case 1: nombres();
								 iniM(M); 
								 dibtab(M);  car='\x1b';
								 band=1;
								 break;
							 case 2: open(M);imprime();dibtab(M);car='\x1b';
								 break;
							 case 3: filename(M);car='\x1b';
								 break;
							 case 4: msgcnt("---> SALIR <---",0);delay(1000);band=1;b=2;break;
							 }

						 case '\x1B': setfillstyle (1,BLUE);
							  bar(10,31,110,150);
							  
							  break;
						  } if (band==1) car='\x1B';
					  }while(car!='\x1B');
					  break;

				  case 2: pos=1;menuopciones();
					  do { switch(pos)
						{
						case 1:
							box(87,30,160,60, 9, DARKGRAY);
							outtextxy(92, 42, "Deshacer");
							break;
						case 2:
							box(87,60,160,90,9,DARKGRAY);
							outtextxy(95, 72, "Rehacer");
							break;
					
						}
						car=getch();
						switch(pos)
						{
						case 1:
							box(87,30,160,60, 9, LIGHTGRAY);
							outtextxy(92, 42, "Deshacer");
							break;
						case 2:
							box(87,60,160,90,9,LIGHTGRAY);
							outtextxy(95, 72, "Rehacer");
							break;
					
						}
						switch(car)
						{
						case '\x0': 	car=getch();
								switch(car)
								{
								case '\x48':pos--;break;
								case '\x50':pos++;break;
								}
								if(pos>2)pos=2;
								if(pos<1)pos=1;
								break;
						case '\xD':	switch(pos)
								{
								case 1: M[A[3]][A[4]]=0; M[A[0]][A[1]]=A[2]; dibtab(M);car='\x1b'; break;
								case 2: M[A[0]][A[1]]=0; M[A[3]][A[4]]=A[2];dibtab(M);car='\x1b'; break;
								
								}
						case '\x1B':    setfillstyle(1,BLUE);
								bar(87,31,160,120);
								break;
						}
						}while(car!='\x1b');
						break;
				  case 3: msgcnt("Hecho_x_Pech8",1);
					  break;
				}
				break;
		  }
		  }while(band!=1);

}
void mueveM(matriz M)
{ int d, b;
  int i=7;
  int j=7;
  char tecla;	

  do{
  b=0;
  setcolor(WHITE);
  tecla=getch();
  switch(tecla)
  { case '\x0':tecla=getch();
			switch(tecla)
			{
			 case '\x4B':   setcolor(WHITE);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						j--;if(j<0) j=0;
						setcolor(MAGENTA);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						break;
			case '\x4D':   setcolor(WHITE);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						j++;if(j>7) j=7;
						setcolor(MAGENTA);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						break;
			case '\x48':setcolor(WHITE);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						i--;  if(i<0)i=0;
						setcolor(MAGENTA);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						break;
			case '\x50':setcolor(WHITE);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						i++;  if(i>7)i=7;
						setcolor(MAGENTA);
						rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
						break;
				}


		 if(j<0)j=0;
		 if(j>7)j=7;
		 if(i<0)i=0;
		 if(i>7)i=7;
		 break;
	case '\x1B':
			 menutab(b);break;




	case '\xD':  if(M[i][j]==0){msgcnt(" NO HAY PIEZA!!",1);break;}
				 d=M[i][j];
				M[i][j]=0;
				A[0]=i;
				A[1]=j;
				A[2]=d;
				L[0]=A[0];
				L[1]=A[1];

 				
				do{
				tecla=getch();
				switch(tecla)
				{ case '\x0': 	tecla=getch();
								switch(tecla)
								{
								case '\x4B':setcolor(WHITE);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											j--; if(j<0)j=0;
											setcolor(MAGENTA);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											break;
								case '\x4D':setcolor(WHITE);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											j++; if(j>7) j=7;
											setcolor(MAGENTA);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											break;
								case '\x48':setcolor(WHITE);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											i--; if(i<0) i=0;
											setcolor(MAGENTA);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											break;
								case '\x50':setcolor(WHITE);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											i++;if(i>7)i=7;
											setcolor(MAGENTA);
											rectangle(cx(j), cy(i), cx(j)+40, cy(i)-40);
											break;
								}
					if(j<0) j=0;
					if(j>7) j=7;
					if(i<0) i=0;
					if(i>7) i=7;
					break;
			case '\xD': 	
					A[3]=i;
					A[4]=j;
					switch(d)
					{
					case 1: M[i][j]=d;
						dibtab(M);
						b=1;break;
					case 11:
						M[i][j]=d;
						dibtab(M);
						b=1;break;

					case 2: if(L[0]==i || L[1]==j)
						{
						M[i][j]=d;
						dibtab(M);
						b=1;break;
						}
						else { msgcnt (" Mov. Invalido",1); break;}
					case 21: if(L[0]==i || L[1]==j)
						{
						M[i][j]=d;
						dibtab(M);
						b=1;break;
						}
						else { msgcnt (" Mov. Invalido",1); break;}
					case 3 :if(pow(L[0]-i,2)==4&&pow(L[1]-j,2)==1 || pow(L[0]-i,2)==1 && pow(L[1]-j,2)==4) 
						{
						M[i][j]=d;
						dibtab(M);
						b=1;break;
						}
						else { msgcnt (" Mov. Invalido",1); break;}
					case 31:if(pow(L[0]-i,2)==4&&pow(L[1]-j,2)==1 || pow(L[0]-i,2)==1 && pow(L[1]-j,2)==4) 
						{
						M[i][j]=d;
						dibtab(M);
						b=1;break;
						}
						else { msgcnt (" Mov. Invalido",1); break;}
					
					case 4: if(pow(L[0]-i,2)==pow(L[1]-j,2))
						{
						M[i][j]=d;
						dibtab(M);
						b=1;break;
						}
						else { msgcnt (" Mov. Invalido",1); break;}
					case 41: if(pow(L[0]-i,2)==pow(L[1]-j,2))
						{
						M[i][j]=d;
						dibtab(M);
						b=1;break;
						}
						else { msgcnt (" Mov. Invalido",1); break;}
					case 5: if(L[0]==i || L[1]==j || pow(L[0]-i,2)==pow(L[1]-j,2))
						{
						M[i][j]=d;
						dibtab(M);
						b=1;break;
						}
						else { msgcnt (" Mov. Invalido",1); break;}

					}
					
					
						break;
			}

			}while (b!=1);break;
}

}while(b!=2);
}
void jugar()
{

 clearviewport();
 box(0,0,getmaxx(), getmaxy(), 1, BLUE);
 iniM(M);
 dibtab(M);
 menusjuego();
 
 box(0, 450, getmaxx(), getmaxy(), 1, DARKGRAY);
 outtextxy(150,460, "Para_activar_menus_presione_la_tecla_'_Esc_'");
 nombres();
 mueveM(M);


}

void menuprincipal()
{

  int x,y;
  clearviewport();
  box(0,0,getmaxx(), getmaxy(), 1, BLUE);
  settextstyle(0,0,0);
  x= (getmaxx()-90)/2;
  y=  300;
  box(x,y , x+90, y+35, 9, LIGHTGRAY);
  outtextxy( x+25, y+15,"JUGAR");
  box(x, y+55, x+90, y+90, 9, LIGHTGRAY);
  outtextxy( x+25, y+70, "SALIR");
  settextstyle(4,0,9);
  outtextxy(90,50,"AJEDREZ");
  settextstyle(0,0,0);

	
}
void muevem()
{  
	int x, y;
	  x= (getmaxx()-90)/2;
	  y=  300;
	char tecla;
	int i=1;
	menuprincipal();
	
	do {
	     switch(i)
	     {
	       case 1:
			box( x,y, x+90, y+35, 9, DARKGRAY);
			outtextxy(x+25, y+15, "JUGAR");
			break;
		   case 2:
			box(x, y+55, x+90, y+90, 9, DARKGRAY);
			outtextxy(x+25, y+70, "SALIR");
			break;
		  }
		  tecla=getch();
		  switch(i)
		  {
		case 1:
			box(x,y,x+90, y+35, 9, LIGHTGRAY);
			outtextxy(x+25, y+15, "JUGAR");
			break;
		case 2:
			box(x, y+55, x+90, y+90, 9, LIGHTGRAY);
			outtextxy(x+25, y+70, "SALIR");
			break;
		  }

		  switch(tecla)
		  {
		case '\x0':
				tecla=getch();
				switch(tecla)
				{
					case '\x48':i--;break;
					case '\x50':i++; break;
				}
				if (i<1) i=2;
				if (i>2) i=1;
				break;
		case '\xD':     switch (i)
				{
				case 1: clearviewport();jugar(); band=1;break;
				case 2: tecla='\x1B'; break;
				}
				if(i!=2) menuprincipal();
				break;
		}if (band==1) tecla='\x1B';
		  }while(tecla!='\x1B');
  }

void main()
{
  inicializa();
  muevem();
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //campojogador e campoadversario viram tabelas
   int Campojogador[4][4],Campoadversario[4][4],x,y,a,b,Barcosjogador=4,BarcosInimigo=4,vezacabou=0,vez=1;
  //4 barcos cada um//
  //;0=agua;1=barco;2=agua-atingida;3=barco-atingido
  srand((unsigned)time(NULL));
  //zerando as variáveis
  for(x=1;x<=4;x++){
                    for(y=0;y<=4;y++){
                                      Campojogador[x][y]=0;
                                      Campoadversario[x][y]=0;
                    }
  }
  //Colocando os barcos do inimigo em posicoes aleatorias
  for(x=1;x<=4;x++){
                    a=1 + (rand() % 4);
                    b=1 +(rand() % 4);
                    //a próxima linha comentada diz quais foram escolhidos, mesmo as repetições, se quiser usar para testar só tirar o comentário
                    printf("a=%i   b=%i \n\n\n",a,b);
                    //Caso caiam as mesmas coordenadas repete o loop
                    if(Campoadversario[a][b]==1){
                                                 x=x-1;
                    }
                    //Caso contrário, coloca o barco
                    else{
                         
                         Campoadversario[a][b]=1;
                    }
  }
  //A pessoa escolhe os locais dos barcos
  printf("Campo de 4x4:\n");
  printf("\n");
  for(x=1;x<=4;x++){
                    printf("Coordenada x do barco %i \n",x);
                    scanf("%i",&a);
                    printf("Coordenada y do barco %i\n",x);
                    scanf("%i",&b);
                    if(Campojogador[a][b]==1){
                                              printf("Ja existe barco nessas coordenadas\n");
                                              x=x-1;
                    }
                    else{
                         Campojogador[a][b]=1;
                         printf("||Barco %i Colocado nas coordenadas %ix%i|| \n\n",x,a,b);
                    }
  }
  //vez==1(jogador);vez==0(computador)
  //;0=agua;1=barco;2=agua-atingida;3=barco-atingido
  while(Barcosjogador>0 && BarcosInimigo>0){
                                              if(vez==1){
                                                         printf("||Sua Vez||\n");
                                                         printf("Diga a coordenada x que deseja atingir\n");
                                                         scanf("%i",&a);
                                                         printf("Diga a coordenada y que deseja atingir\n");
                                                         scanf("%i",&b);
                                                         if(Campoadversario[a][b]==0){
                                                                                      printf("Atingiu agua\n");
                                                                                      Campoadversario[a][b]=2;
                                                                                      //vezacabou serve para evitar que mais de um if seja executado
                                                                                      //exemplo se acertar a agua, vai virar 2, assim o if 2 vai ser executado, causando problemas
                                                                                      vezacabou=1;
                                                         }
                                                         if(Campoadversario[a][b]==1 && vezacabou==0){
                                                                                      printf("Atingiu um barco\n");
                                                                                      BarcosInimigo=BarcosInimigo-1;
                                                                                      Campoadversario[a][b]=3;
                                                                                      vezacabou=1;
                                                         }
                                                         if(Campoadversario[a][b]==2 && vezacabou==0){
                                                                                      printf("Voce ja atingiu essa posicao, digite outra\n");
                                                                                      printf("Voce ja atingiu as posicoes:\n");
                                                                                      for(x=1;x<=4;x++){
                                                                                                        for(y=1;y<=4;y++){
                                                                                                                          if(Campoadversario[x][y]==2 || Campoadversario[x][y]==3){
                                                                                                                                                       printf("%iX%i\n",x,y);
                                                                                                                          }
                                                                                                        }
                                                                                      }
                                                                                      vez++;
                                                                                      vezacabou=1;
                                                         }
                                                         if(Campoadversario[a][b]==3 && vezacabou==0){
                                                                                      printf("Voce ja atingiu essa posicao, digite outra\n");
                                                                                      printf("Voce ja atingiu as posicoes:\n");
                                                                                      for(x=1;x<=4;x++){
                                                                                                        for(y=1;y<=4;y++){
                                                                                                                          if(Campoadversario[x][y]==2 || Campoadversario[x][y]==3){
                                                                                                                                                       printf("%iX%i\n",x,y);
                                                                                                                          }
                                                                                                        }
                                                                                      }
                                                                                      vez++;
                                                                                      vezacabou=1;
                                                         }
                                                         vez--;
                                                         vezacabou=0;
                                              }
                                              else{
                                                   a=1+(rand()%4);
                                                   b=1+(rand()%4);
                                                   if(Campojogador[a][b]==0){
                                                                             printf("||Vez do asversario||\nEle acertou agua na posicao %iX%i\n",a,b);
                                                                             Campojogador[a][b]=2;
                                                                             vezacabou=1;
                                                   }
                                                   if(Campojogador[a][b]==1 && vezacabou==0){
                                                                                             printf("||Vez do adversario||\nEle acertou um barco na posicao %iX%i\n",a,b);
                                                                                             Barcosjogador=Barcosjogador-1;
                                                                                             Campojogador[a][b]=3;
                                                                                             vezacabou=1;
                                                   }
                                                   if(Campojogador[a][b]==2 && vezacabou==0){
                                                                                             vez--;
                                                                                             vezacabou=1;
                                                   }
                                                   if(Campojogador[a][b]==3 && vezacabou==0){
                                                                                             vez--;
                                                                                             vezacabou=1;
                                                   }
                                                   vezacabou=0;
                                                   vez++;
                                              }
  }
  if(Barcosjogador==0){
                       printf("YOU LOST!\n");
  }
  else{
       printf("YOU WON!\n");
  }
  
  system("PAUSE");	
  return 0;
}

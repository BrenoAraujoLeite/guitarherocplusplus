//Bibliotecas Usadas
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <MMSystem.h>
#define MAX 250

//Funcoes
int cronometro(clock_t comeco, clock_t fim);
void sorteio (int musica[MAX]);
void setTextColor(int fg,int bg);
void gotoxy(int x, int y);
void limpar();
void menu();
void instrucoes();
void telaFinal();

using namespace std;

//Strutc Da Composicao das Notas
struct Notas{
    int posx;
    int posy;
    int id;
    int tecla;
};

//Menu de Configuracao
void configuracoes(Notas& azul, Notas& verde, Notas& vermelho){
    cout<<"Para configurar digite a tecla: "<<endl;
    cout<<"Verde: "<<endl;
    verde.tecla=getch();
    cout<<"Vermelho: "<<endl;
    vermelho.tecla=getch();
    cout<<"Azul: "<<endl;
    azul.tecla=getch();
}

int main(){
    srand(time(NULL));

    //Definindo o padrao das notas
    Notas verde{20,2,1,49};     //Posicao x,y,identificador,tecla
    Notas vermelho{20,2,2,50};
    Notas azul{20,2,3,51};

    //variaveis para funcionamento do jogo
    bool execucao=true;
    int mus;
    char comando;

    //Inicio do jogo
    do{

        menu();       //menu

        cin>>comando;
        limpar();


        //Acao realizada escolhida no Menu
        if(comando=='h' || comando=='H'){
            instrucoes();
        }
        if(comando=='s' || comando=='S'){
           break;
        }
        if(comando=='c' || comando=='C'){
           configuracoes(azul,  verde,  vermelho);
        }
        if(comando=='x' || comando=='X'){ //Parte do jogo

            //Inicio do laco do jogo

            do{
                //Escolha da Musica
                cout<<"Selecione a sua musica!"<<endl;
                cout<<"Opcoes:"<<endl;
                cout<<"1. JAM Project - 'Abertura One Punch Man'"<<endl;
                cout<<"2. SAM - 'Guitarra humana'.mp4"<<endl;
                cout<<"3. Dragonforece - 'Through the fire and flames'"<<endl;
                cout<<"4. Mamonas Assassinas - 'Vira-Vira'"<<endl;
                cout<<"5. Charlei Brow Jr. - 'Ponte indestrutiveis'"<<endl;
                cin>>mus;


                //Selecao da musica
                switch(mus){
                    case 1:
                        PlaySound(TEXT("teste.wav"), NULL, SND_ASYNC);
                        break;
                    case 2:
                        PlaySound(TEXT("teste.wav"), NULL, SND_ASYNC);
                        break;
                    case 3:
                        PlaySound(TEXT("teste.wav"), NULL, SND_ASYNC);
                        break;
                    case 4:
                        PlaySound(TEXT("teste.wav"), NULL, SND_ASYNC);
                        break;
                    case 5:
                        PlaySound(TEXT("teste.wav"), NULL, SND_ASYNC);
                        break;
                    default:
                        break;
                }

                //Variaveis para o jogo
                int nota, aux,score=0;
                limpar();
                clock_t comeco,fim;


                int musica[MAX];    //Notas da Musica

                sorteio(musica);        //Sorteando notas da musica

                cout<<"-----------------------------------------------------"<<endl;
                cout<<"------------------O jogo vai comecar-----------------"<<endl;
                cout<<"----------------Pressione a ultima cor---------------"<<endl;
                cout<<"Verde: "<<(char)verde.tecla<<endl;
                cout<<"Vermelho: "<<(char)vermelho.tecla<<endl;
                cout<<"Azul: "<<(char)azul.tecla<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                Sleep(3500);
                system("pause");
                limpar();

                //Inicio da Partida
                comeco=clock();             //Tempo inicial
                for(int i=0; i<150; i++){   //Imprime as Notas

                    //Desenha a Nota
                    if(musica[i]==1)
                    {
                        gotoxy(verde.posx,verde.posy*i); // vai para a posicao
                        setTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY,0);  //cor da nota
                        cout<<char(219)<<"   "<<"   "<<endl;    //imprime
                        nota=verde.tecla;   //declara a tecla da nota
                    }
                    else if(musica[i]==2)
                    {
                        gotoxy(vermelho.posx,vermelho.posy*i);
                        setTextColor(FOREGROUND_RED|FOREGROUND_INTENSITY,0);
                        cout<<"   "<<char(219)<<"   "<<endl;
                        nota=vermelho.tecla;
                    }
                    else
                    {
                        gotoxy(azul.posx,azul.posy*i);
                        setTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY,0);
                        cout<<"   "<<"   "<<char(219)<<endl;
                        nota=azul.tecla;
                    }





                    aux=getch();   //captura a tecla da nota

                    if(aux==nota){   //calcula o score
                        score++;
                    }


                }// fim da partida

                    PlaySound(NULL, 0, 0); //Para a musica
                    Sleep(1000);

                    fim=clock();     //tempo final do jogo
                    limpar();
                    setTextColor(7,0);
                    //Scores
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<cronometro(comeco,fim)<<" segundos."<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"SCORE: "<<score<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;

            cout<<"Deseja Jogar Novamente? (S/N)";
            cin>>comando;

            if(comando=='s' || comando=='S'){    //Comando para jogar novamente
                execucao=true;
            }else{
                execucao=false;
            }
            limpar();
            }while(execucao);   //Fim da Jogatina

            execucao=true;

        }

        limpar(); //Limpa console

    }while(execucao);       //Fim da execucao do Jogo

    //Fim do jogo (Tela Final)
    telaFinal();

    //Fim da Main
return 0;
}
void setTextColor(int fg,int bg){
    //Muda a cor do background e foreground do console
    HANDLE hconsole= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole, fg|bg<<4);

}
void gotoxy(int x, int y){
    //Muda a posicao do console para imprimir
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sorteio(int musica[MAX]){
    //Sorteia as notas da musica
    int v;
    for(int i=0; i<150; i++)
    {
        v=(rand()%3)+1;
        musica[i]=v;
    }
}
int cronometro(clock_t comeco, clock_t fim){
    //Calcula o Tempo da Partida
    return (fim-comeco)/1000;
}
void limpar(){
    system("cls");
}
void menu(){
    //Tela do Menu do Jogo
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-------------------  GuitarC++  ---------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------Menu--------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"---------------Iniciar (Pressione X)-----------------"<<endl;
    cout<<"---------------Intrucoes (Pressione H)---------------"<<endl;
    cout<<"-------------Configuracoes (Pressione C)-------------"<<endl;
    cout<<"---------------Sair (Pressione S)--------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"------------------By: Breno e Mateus-----------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}
void instrucoes(){
    //Tela de Intrucoes do Jogo
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"---------------------Intrucoes-----------------------"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"O objetivo do jogo e tocar a guitarra da musica que "<<endl;
        cout<<"esta sendo reproduzida, para isso basta acertar as  "<<endl;
        cout<<"notas que surgem na pista."<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"As notas sao representadas pelas teclas '1', '2', '3'"<<endl;
        cout<<"cada acerto representara uma pontuacao e cada "<<endl;
        cout<<"erro sera um decrecimo da mesma."<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        system("pause");
}
void telaFinal(){
    //Tela Para O Fim da Execucao do Jogo
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"--------------------Jogo Finalizado------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"--------Obrigado por Utilizar nossa Ferramenta-------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"---------------------Desenvolvido por:---------------"<<endl;
    cout<<"--------------------------Breno----------------------"<<endl;
    cout<<"----------------------------e------------------------"<<endl;
    cout<<"--------------------------Mateus---------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"--------------------------2017-----------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}


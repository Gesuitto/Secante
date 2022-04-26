#include<iostream>
#include <stdlib.h>
using namespace std;
void movmentW(int x, int y, string campo[20][20], int numrandom1, int numrandom2 )
{

    campo[y][x]=" ";
    campo[y-1][x]="a"; 
    for(int j=0;j<20;j++)
    {
        for(int i=0; i<20;i++)
        {
          if(campo[j][i]=="#"|| campo[j][i]=="a"|| campo[j][i]=="p")
                cout<<campo[j][i];
          else
                cout<<" ";
        }       
        cout<<endl;
    }
    
}
void movmentS(int x, int y, string campo[20][20], int numrandom1, int numrandom2 )
{

    campo[y][x]=" ";
    campo[y+1][x]="a"; 
    for(int j=0;j<20;j++)
    {
        for(int i=0; i<20;i++)
        {
          if(campo[j][i]=="#"|| campo[j][i]=="a"|| campo[j][i]=="p")
                cout<<campo[j][i];
          else
                cout<<" ";
        }       
        cout<<endl;
    }
    
}
void movmentA(int x, int y, string campo[20][20], int numrandom1, int numrandom2 )
{

    campo[y][x]=" ";
    campo[y][x-1]="a"; 
    for(int j=0;j<20;j++)
    {
        for(int i=0; i<20;i++)
        {
          if(campo[j][i]=="#"|| campo[j][i]=="a" || campo[j][i]=="p")
                cout<<campo[j][i];
          else
                cout<<" ";
        }       
        cout<<endl;
    }
    
}
void movmentD(int x, int y, string campo[20][20], int numrandom1, int numrandom2 )
{

    campo[y][x]=" ";
    campo[y][x+1]="a"; 
    for(int j=0;j<20;j++)
    {
        for(int i=0; i<20;i++)
        {
          if(campo[j][i]=="#"|| campo[j][i]=="a"|| campo[j][i]=="p")
                cout<<campo[j][i];
          else
                cout<<" ";
        }       
        cout<<endl;
    }
    
}
bool gameover(string matrix[20][20]) {
    bool controllo=true;
    for (int i = 0; i <19; i++)
    {
        for (int j = 0; j <19; j++)
        if(matrix[i][0] == "a" ||     matrix[i][19] == "a" || matrix[0][j]=="a" || matrix[19][j]=="a")
        {
            controllo=false;
        }
    }
    return controllo;
    }
bool controllomela1(string campo[20][20], int &num, int &num2)
{
    if(campo[num][num2]!="p")
        return true;
    else
        return false;
}
void nuovamela(string campo[20][20], int &numrandom1, int &numrandom2)
{
    numrandom1= rand()%18;
    numrandom2= rand()%18;
    campo[numrandom1][numrandom2]="p";
}
int main()
{
    string campo[20][20];
    int x=9;
    int y=9;
    int j;
    int numrandom1; //mela riga
    numrandom1= rand()%18;
    int numrandom2; //mela riga
    numrandom2= rand()%18;
    for(int i=0; i<20;i++)
    {
        campo[0][i]="#";
        campo[i][0]="#";
        campo[19][i]="#";
        campo[i][19]="#";
        campo[9][9]="a";
    }
    campo[numrandom1][numrandom2]="p";
    for(int j=0;j<20;j++)
    {
        for(int i=0; i<20;i++)
        {
                if(campo[j][i]=="#"|| campo[j][i]=="a"|| campo[j][i]=="p")
                    cout<<campo[j][i];
                else
                    cout<<" ";
        }    
        cout<<endl;
    }
    string num;
    

    while(gameover(campo)==true) //cin
    {

        cin>>num;
         system("cls");
        if(num=="w")
        {
            movmentW(x, y, campo, numrandom1, numrandom2);
            y=y-1;
        }
        else
        {
            if(num=="s")
            {
                movmentS(x, y, campo, numrandom1, numrandom1);
                y=y+1;
            }
            else
            {
                if(num=="a")
                {
                    movmentA(x, y, campo, numrandom1, numrandom1);
                    x=x-1;
                }
                else
                {
                    if(num=="d")
                    {
                        movmentD(x, y, campo, numrandom1, numrandom1);
                        x=x+1;
                    }
                }
            }
        }
        if(controllomela1(campo, numrandom1, numrandom2)==true)
            nuovamela(campo, numrandom1, numrandom2);
    }
    cout<<"gameover";   
}

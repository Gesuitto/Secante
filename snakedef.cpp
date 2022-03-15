#include<iostream>
#include <stdlib.h>
#include<locate>
using namespace std;
void movmentW(int x, int y, string campo[15][40], int numrandom1, int numrandom2 )
{

	campo[y][x]=" ";
	campo[y-1][x]="|"; 
	for(int j=0;j<15;j++)
	{
		for(int i=0; i<40;i++)
		{
		  if(campo[j][i]=="#"|| campo[j][i]=="|")
		        cout<<campo[j][i];
		  else
		        cout<<" ";
		}   	
		cout<<endl;
	}
    
}
void movmentS(int x, int y, string campo[15][40], int numrandom1, int numrandom2 )
{

	campo[y][x]=" ";
	campo[y+1][x]="|"; 
	for(int j=0;j<15;j++)
	{
		for(int i=0; i<40;i++)
		{
		  if(campo[j][i]=="#"|| campo[j][i]=="|")
		        cout<<campo[j][i];
		  else
		        cout<<" ";
		}   	
		cout<<endl;
	}
    
}
void movmentA(int x, int y, string campo[15][40], int numrandom1, int numrandom2 )
{

	campo[y][x]=" ";
	campo[y][x-1]="|"; 
	for(int j=0;j<15;j++)
	{
		for(int i=0; i<40;i++)
		{
		  if(campo[j][i]=="#"|| campo[j][i]=="|")
		        cout<<campo[j][i];
		  else
		        cout<<" ";
		}   	
		cout<<endl;
	}
    
}
void movmentD(int x, int y, string campo[15][40], int numrandom1, int numrandom2 )
{

	campo[y][x]=" ";
	campo[y][x+1]="|"; 
	for(int j=0;j<15;j++)
	{
		for(int i=0; i<40;i++)
		{
		  if(campo[j][i]=="#"|| campo[j][i]=="|")
		        cout<<campo[j][i];
		  else
		        cout<<" ";
		}   	
		cout<<endl;
	}
    
}
bool gameover(string campo[15][40])
{
	for(int i=0; i<40;i++)
	{
		if(campo[0][i]!="#" ||campo[i][0]!="#")  
		{
			return true;
		}
		else
		{
		
			if(campo[14][i]!="#" || campo[i][39]!="#")
			{
				return true;
			}
			else
			{
			return false;
			}
		}
	}
}
bool controllomela1(string campo[15][40], int num, int num2)
{
    if(campo[num][num2]!="ð")
        return true;
    else
        return false;
}
void nuovamela(string campo[15][40])
{
	int numrandom1; //mela riga
	numrandom1= rand()%14;
	int numrandom2; //mela riga
	numrandom2= rand()%40;
	campo[numrandom1][numrandom2]="ð";
	for(int j=0;j<15;j++)
	{
		for(int i=0; i<40;i++)
		{
		    if(j==numrandom1 && i==numrandom2)
		        cout<<campo[j][i];
		}	
		cout<<endl;
	}
}
int main()
{
	setlocate(LC_ALL,"");
    string campo[15][40];
    int x=9;
	int y=9;
	int j;
	int numrandom1; //mela riga
	numrandom1= rand()%14;
	int numrandom2; //mela riga
	numrandom2= rand()%39;
	campo[numrandom1][numrandom2]="ð";
	for(int i=0; i<40;i++)
	{
		campo[0][i];
	}
	for(int i=0; i<40;i++)
	{
		campo[0][i];
	}
	for(int j=0;j<20;j++)
	{
		for(int i=0; i<20;i++)
		{
		        if(campo[j][i]=="#"|| campo[j][i]=="|"|| campo[j][i]=="ð")
		            cout<<campo[j][i];
		        else
		            cout<<" ";
		}	
		cout<<endl;
	}
	string num;
	

	while(gameover(campo)==false) //cin
	{

		cin>>num;
		cout << string( 100, '\n' );
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
		    nuovamela(campo);
	}
	cout<<"gameover";   
}

 

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 1000;
float tablica[SIZE][2];

int nwd(int x,int y) 
{
	if (x<y) return nwd(y,x);
    if (y==0) return x;
    return nwd(y,x%y);
}

void zadanie()
{
  ifstream plik("c:\\dane_ulamki.txt");
  for(int i=0; i<SIZE; i++)
   {
    	plik>>tablica[i][0]>>tablica[i][1];
   }
	plik.close();
  
  int suma=0;
  int currentNwd;
  
  for (int i=0; i<SIZE; i++)
  {
    float licznik = tablica[i][0];
    float mianownik = tablica[i][1];
    while (nwd(licznik, mianownik)>1) 
	{	
    	currentNwd = nwd(licznik, mianownik);
    	licznik = licznik / currentNwd;
    	mianownik = mianownik / currentNwd;  
    }
    suma+=licznik;
  }
  cout<<suma<<endl;
}

int main(int argc, char** argv) 
{
	zadanie();
	return 0;
}

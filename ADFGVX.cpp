#include <iostream>
#include<cstdlib>
#include <ctime>
#include <string.h>

using namespace std;



char *tablicaPom;
char *tablicaPrzestawien;
char tablicaZnakowdodatkowych[12];
string haslo,slowoKodowe;
int poz;
int pomSZ;
int stala;


//<-------------------------------wstawienie wzorca do tablicy
void wyswietl(int tab[6][6]){
char tabS[7][7];

for(int i=0;i<7;i++){
	for(int j=0;j<7;j++){
			
			if(i ==0 && j ==0 )tabS[0][0]=' ';
			if((i==0  && j==1) || (i ==1 && j ==0))tabS[i][j] ='A';
			if((i==0  && j==2) || (i ==2 && j ==0))tabS[i][j] ='D';
			if((i==0  && j==3) || (i ==3 && j ==0))tabS[i][j] ='F';
			if((i==0  && j==4) || (i ==4 && j ==0))tabS[i][j] ='G';
			if((i==0  && j==5) || (i ==5 && j ==0))tabS[i][j] ='V';
			if((i==0  && j==6) || (i ==6 && j ==0))tabS[i][j] ='X';
			
			
			if(i>0 && j>0)tabS[i][j] = tab[i-1][j-1];
			cout<<tabS[i][j]<<" | ";
		
	
			
	}
	cout<<"\n";
}


	
}



//wyznaczanie wszystkich miejsc dla znakow 
void znajdzPOM(int tab[6][6]){
	char pom,pom1;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(i==0)pom = 'A';
			if(j==0)pom1 = 'A';
			if(i==1)pom = 'D';
			if(j==1)pom1 = 'D';
			if(i==2)pom = 'F';
			if(j==2)pom1 = 'F';
			if(i==3)pom = 'G';
			if(j==3)pom1 = 'G';
			if(i==4)pom = 'V';
			if(j==4)pom1 = 'V';
			if(i==5)pom = 'X';
			if(j==5)pom1 = 'X';
			
			if(tab[i][j] == 'x'){
				tablicaZnakowdodatkowych[0] = pom;
				tablicaZnakowdodatkowych[1] = pom1;
			}
			if(tab[i][j] == 'v'){
				tablicaZnakowdodatkowych[2] = pom;
				tablicaZnakowdodatkowych[3] = pom1;
			}
			if(tab[i][j] == 'g'){
				tablicaZnakowdodatkowych[4] = pom;
				tablicaZnakowdodatkowych[5] = pom1;
			}
			if(tab[i][j] == 'f'){
				tablicaZnakowdodatkowych[6] = pom;
				tablicaZnakowdodatkowych[7] = pom1;
			}
			if(tab[i][j] == 'd'){
				tablicaZnakowdodatkowych[8] = pom;
				tablicaZnakowdodatkowych[9] = pom1;
			}
			if(tab[i][j] == 'a'){
				tablicaZnakowdodatkowych[10] = pom;
				tablicaZnakowdodatkowych[11] = pom1;
			}
		}
	}
	
}


void zamien(){
	
}

void wyznaczZnak(int tab[6][6],char kod){
	char pom,pom1;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(tab[i][j] == kod){
				if(i==0)pom = 'A';
				if(i== 1)pom = 'D';
				if(i== 2)pom = 'F';
				if(i== 3)pom = 'G';
				if(i== 4)pom = 'V';
				if(i== 5)pom = 'X';
				
				if(j==0)pom1= 'A';
				if(j== 1)pom1 = 'D';
				if(j== 2)pom1 = 'F';
				if(j== 3)pom1 = 'G';
				if(j== 4)pom1 = 'V';
				if(j== 5)pom1 = 'X';
				
				
				
				tablicaPom[stala] = pom;
				tablicaPom[stala+1] = pom1;
				cout<<"("<<pom<<","<<pom1<<") ,";
				stala +=2;
				
				break;
			}
		}
	}
	
}


void szyfruj(int tab[6][6]){
	
	for(int i=0;i<slowoKodowe.length();i++){
			if(slowoKodowe[i]!=' ')pomSZ++;
	}
	
	
	
	pomSZ*=2;
	
	tablicaPom = new char[pomSZ];
	cout<<"\n";
	for(int i=0;i<slowoKodowe.length();i++){
		if(slowoKodowe[i]==' '){
			cout<<"(spacja :D),";	
		}else
		wyznaczZnak(tab,slowoKodowe[i]);
	
	
	
	
	
}
}





void Sortowanie( char tab[], int left, int right )
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ];
    do
    {
        while( tab[ i ] < x )
             i++;
        
        while( tab[ j ] > x )
             j--;
        
        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );
            
            i++;
            j--;
        }
    } while( i <= j );
    
    if( left < j ) Sortowanie( tab, left, j );
    
    if( right > i ) Sortowanie( tab, i, right );
    
}



void kodujAlfabetycznie(int wier, int kol, int ilosc){
	//sortowanie tablicy
	char tabPom[wier][kol];
	char tabAlf[kol][wier];


//kopia tablicy
	int x;
	cout<<"\n";
	for(int i=0;i<wier;i++){
		for(int j=0;j<kol;j++){
			tabPom[i][j] = tablicaPrzestawien[x];
			x++;
		}
	}	
	


	cout<<"\n Sortowanie kolumn wzgledem kolejnosci liter w hasle\n";
int min,bufor;
x=0;

for (int i=0; i<kol-1; i++)
 	{
 		min=i;
 		//znajdowanie minimum
 		for (int j=i+1; j<kol; j++)
 			{
 				if (tabPom[0][j]<tabPom[0][min])
 					min=j;
 			}
 		//zamiana
 		while(x!=wier){
		 
 		bufor=tabPom[x][min];
 		tabPom[x][min]=tabPom[x][i];
		 tabPom[x][i]=bufor;
 		x++;
	 	}
	 	x=0;
 	}




for(int i=0;i<wier;i++){
		for(int j=0;j<kol;j++){
			cout<<tabPom[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	
	//przestawienie kolumn na poziom do sortowania
	for(int j=0;j<kol;j++){
		for(int i=0;i<wier;i++){
			tabAlf[j][i] = tabPom[i][j];
			
		}
	}
	
	cout<<"\n Zaczyfrowane : \n";
	//wypisanie gotowca
	for(int i=0;i<kol;i++){
		for(int j=1;j<wier;j++){
			cout<<tabAlf[i][j];
		}
		cout<<" ";
	}
	
	
	
	
	
/* SORTOWANIE WARTOSCI KOLUMN ...	
	//przestawienie kolumn na poziom do sortowania
	for(int j=0;j<kol;j++){
		for(int i=0;i<wier;i++){
			tabAlf[j][i] = tabPom[i][j];
			
		}
	}
	
	
	//sortowanie
	int a = wier;
	for(int i=0;i<kol;i++)Sortowanie(tabAlf[i],0,a-1);
	
	
	//wypisanie w boku
	cout<<"\nWypisanie posortowanych kolumn do boku \n";
	for(int i=0;i<kol;i++){
		for(int j=0;j<wier;j++){
			cout<<tabAlf[i][j]<<" ";
		}
		cout<<"\n";
	}	
	
	

	for(int i=0;i<wier;i++){
		for(int j=0;j<kol;j++){
			tabPom[i][j] = tabAlf[j][i];
		}
	}
	
	
	
	
	cout<<"\n Po sortowaniu wzgledem wartosci kolumn \n";
	for(int i=0;i<wier;i++){
		for(int j=0;j<kol;j++){
			cout<<tabPom[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
*/	
//tablicaPrzestawienAlfabetycznych , tablicaprzestawien
}



void przestaw(){
	cout<<"\n";
	for(int i=0;i<haslo.length();i++){
	//	cout<<haslo[i]<<" ";
	}	


	cout<<"\n";
	
	
	int j =0;
	int pomocniczaWielkoscTab = 0;

	//sprawdzenie ilosci brakujacych znakow
	for(int i=0;i<pomSZ;i++){
		if(j == haslo.length())j=0;
		j++;
	}	
	
	
	pomocniczaWielkoscTab = haslo.length()-j;
	int dlug = pomocniczaWielkoscTab;
	pomocniczaWielkoscTab+=pomSZ;
	pomocniczaWielkoscTab += haslo.length();
	tablicaPrzestawien = new char[pomocniczaWielkoscTab];
	
	pomSZ += haslo.length();
	
	for(int i=0;i<pomSZ;i++)
	{
		
		if(i < haslo.length())
		{
			
			tablicaPrzestawien[i] = haslo[i];
			
		}
		else
		{
			
			tablicaPrzestawien[i] = tablicaPom[i-haslo.length()];
			
		}
		
		
	}
	
	int pom = pomSZ;
	int x=0;
	
	
	while(pomocniczaWielkoscTab>pom){
		tablicaPrzestawien[pom] = tablicaZnakowdodatkowych[x];
		pom++;
		x++;
	
	}
	
	
	j=0;
	int iloscWierwszy=0;
	for(int i=0;i<pomocniczaWielkoscTab;i++){
		if(j == haslo.length()){
			cout<<"\n";
			j=0;
			++iloscWierwszy;
		}
		cout<<tablicaPrzestawien[i]<<" ";
		++j;
		
	}	
	
	x = haslo.length();
	kodujAlfabetycznie(iloscWierwszy +1, x, pomocniczaWielkoscTab);

}




int main(){
	string wyjscie;
	do{	


	int tab[6][6];
	srand(time(NULL));
	char tabAlfabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
	int pom;
	int x,y;


		
	
		system("cls");
		pom = 0;
		x=y=0;
		slowoKodowe = "";
	
	
	//wstawienie zer do tablicy
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			tab[i][j] = 0;
			
		}
	}
	
	
	//wczytanie wartosci alfabetu w losowe miejsca tablicy
	while(pom<36){
	x = rand()%6 +0;
	y = rand()%6 + 0;
	
	if(tab[x][y] == 0){
		tab[x][y] = tabAlfabet[pom];
		pom+=1;
	}	
	
}


	
	//wyswietlenie tablicy
	wyswietl(tab);
	znajdzPOM(tab);
	
	
	cout<<"\n\n Podaj slowo do zakodowania : ";
	getline(cin,slowoKodowe);	
	cout<<slowoKodowe;	
	
	
	szyfruj(tab);
	
	
	cout<<"\n\nPodaj tajne haslo :";
	cin>>haslo;
	przestaw();


	
	
	
	
	cout<<"\n Czy chcesz powtorzyc ? (t/n)";
	getline(cin,wyjscie);
	
	
	
	
	
	
	system("PAUSE");
	slowoKodowe = "";
	haslo =  "";
	pomSZ=0;
	pom =0;
	poz = 0;
	stala = 0;	
	delete[] tablicaPom;
	delete[] tablicaPrzestawien;
	
	
}while(wyjscie[0]!='n');
	
	return 0;
}



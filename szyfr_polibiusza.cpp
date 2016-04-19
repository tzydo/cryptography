#include <iostream>
#include<cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

void wyswietl(int tab[5][5]){
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(i == 0 && j ==0)cout<<"  | ";
			else if(i==0)cout<<j<<" | ";
			else if(j == 0)cout<<i<<" | ";
			else
				cout<<(char)tab[i-1][j-1]<<" | ";
		}
		cout<<"\n";
	}
}


void wyznaczZnak(int tab[5][5], char znak){
	
	for(int i = 0;i<5;i++){
		for(int j =0;j<5;j++){
			if(tab[i][j] == znak){
				cout<<"("<<j+1<<" , "<<i+1<<"), ";
				break;
			}
		}
	}
	
}


void szyfruj(int tab[5][5],string kod){
	for(int i=0;i<kod.length();i++){
		if(kod[i]==' '){
			cout<<"(spacja :D),";
			
	//	if(kod[i] == 'i' || kod[i]=='j')cout<<"cos";	
		}else
		wyznaczZnak(tab,kod[i]);
	}
}


int main(){
	
	string a;
	string slowoKodowe;
	int tab[5][5];
	srand(time(NULL));
	char tabAlfabet[] = {'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int pom;
	int x,y;


		
	do{
		system("cls");
		pom = 0;
		x=y=0;
		slowoKodowe = "";
	
	
	//wstawienie zer do tablicy
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			tab[i][j] = 0;
			
		}
	}
	
	
	//wczytanie wartosci alfabetu w losowe miejsca tablicy
	while(pom<25){
	x = rand()%5 +0;
	y = rand()%5 + 0;
	
	if(tab[x][y] == 0){
		tab[x][y] = tabAlfabet[pom];
		pom+=1;
	}	
	
}





	//wyswietlenie tablicy
	wyswietl(tab);
		

	
	cout<<"\n\n Podaj slowo kodowe : ";
	getline(cin,slowoKodowe);
	
	cout<<slowoKodowe;
	szyfruj(tab,slowoKodowe);
	
	
	cout<<"\n Czy chcesz powtorzyc ? (t/n)";
	getline(cin,a);
}while(a[0]!='n');
	return 0;
}

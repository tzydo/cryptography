#include <iostream>
#include <conio.h>
using namespace std;



string sprawdzDlugoscHasla(string k, string h){
	if(k.length() == h.length()){
		return h;
		}		
	else if(k.length()> h.length()){
		string pom;
		int a=0;
		
			for(int i=0;i<k.length();i++){
				
				if(a == h.length())a=0;
				if(k[i] == (char)32)
					pom+=(char)32;
				else
					{
						pom+=h[a];
						a++;
					}
				
				
			}

		return pom;
	}
	
	else if(k.length()<h.length()){
		string pom;
		for(int i=0;i<k.length();i++){
			pom+=h[i];	
		}
		return pom;
	}
		
}



//97-122 male

char szukajWtab(int poczatkowa, int kodowa){
	
	int pom = poczatkowa-97;
	
	if(kodowa+pom<=122){
		kodowa+=pom;
	}
	
	else if(kodowa+pom>=122){
		kodowa= kodowa+pom - 123;
		kodowa+=97;
	}
	
	if (poczatkowa == 32)kodowa=32;
	cout<<(char)kodowa;
	
	}





void szyfruj(string k, string h){
	
	string szyfr;
	int x;
	int y;
	
	for(int i=0;i<k.size();i++){
		x = (int)k[i];	//pozycja (numer) znaku w tablicy slowa kodowego
		//cout<<x;
		y = (int)h[i];	//pozycja (numer) znaku w tablicy hasla
		
		szyfr[i] = szukajWtab(x,y);
		
	}
	//system("PAUSE");
}


int main(){
	string a,kod,haslo;
	cout<<"Podaj tekst jawny :";
	getline(cin,kod);
	//cout<<kod;
	cout<<"Podaj haslo :";
	getline(cin,haslo);
	//cout<<haslo<<"\n";

	haslo = sprawdzDlugoscHasla(kod, haslo);
	//cout <<haslo<<"\n\n";
	cout<<"zakodowane : ";
	szyfruj(kod,haslo);
	//cout<<"\n przed: "<<kod <<" \n"; 
	
	system("Pause");
	return 0;
}

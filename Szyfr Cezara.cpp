#include <iostream>

using namespace std;


void zlicz2(char tekst[]){

        int zlicz2[123] = {}; 
 
        int i=0; 
 
        while(tekst[i]) 
        {
                ++zlicz2[tekst[i]];
				         ++i; 
        }
 
        for(int i=97;i<123;i++) 
                
                        cout<<(char)i<<" - "<<zlicz2[i]<<endl;
                        
                        
                        for(int i=48; i<58;i++)
                        cout<<(char)i<<" - "<<zlicz2[i]<<endl;
	
}

void zlicz(string tekst){

        int zlicz[123] = {}; 
 
        int i=0; 
 
        while(tekst[i]) 
        {
                ++zlicz[tekst[i]];
				         ++i; 
        }
 
        for(int i=97;i<123;i++) 
                
                        cout<<(char)i<<" - "<<zlicz[i]<<endl;
                        
                        
                        for(int i=48; i<58;i++)
                        cout<<(char)i<<" - "<<zlicz[i]<<endl;
	
}


int szyfrowanie(int tab[], int w){
	int przesuniecie,przesuniecie2;
	cout<<" \n Podaj przesuniecie (+/-liczba) \n";
	cin>>przesuniecie;
	
	przesuniecie2 = przesuniecie;
	
	if(przesuniecie>=0)przesuniecie = przesuniecie%26;
	if(przesuniecie<0)przesuniecie = przesuniecie%26 ;
	if(przesuniecie2>10)przesuniecie2 = przesuniecie2%10;
	
	cout<<"\n\n PO SZYFROWANIU CEZARA : \n";	
	int strona;
	if(przesuniecie >= 0)
		strona=0;//dodatnia
		else
		strona = 1;//ujemna	
	
	if(przesuniecie2 >=0)
		strona = 0;
		else
		strona =1;
	
			//a-z 97-122 , A-Z 65-90
			//48 - 57 0-9
		switch(strona)
				{
				case 0:
									
						for(int i=0;i<w;i++){
							if(tab[i]==32){	tab[i]=32;}
							
							//cyfry
							if(tab[i]>=48 && tab[i]<57){
								if(tab[i]+przesuniecie2 ==57)tab[i]=57;
								else if(tab[i]+przesuniecie2>57){
									int pom = tab[i]+przesuniecie2 - 57 -1;
									tab[i]=48+pom;
								}else
								tab[i]+=przesuniecie2;
							}
							else if(tab[i]==57)tab[i]=48+przesuniecie2 -1;
							
							
							
							if(tab[i]>=65 && tab[i]<90){  //duze litery
								if(tab[i]+przesuniecie==90)tab[i]=90;
								else if(tab[i]+przesuniecie>90){
									int pom = tab[i]+przesuniecie - 90 -1;
									tab[i]=65+pom;
									}else
								tab[i]+=przesuniecie;
								}
							
							else if(tab[i] +przesuniecie ==90)tab[i]=90;		
							else if(tab[i]==90)tab[i]=65+przesuniecie -1;
							else if(tab[i]+przesuniecie >90 && tab[i]>=65 &&tab[i]<=90 &&tab[i]!=32)tab[i]=90-przesuniecie -1;
							//cout<<(char)tab[i];	
							
							
							if(tab[i]>=97 && tab[i]<122){   //male litery
								if(tab[i]+przesuniecie==122)tab[i]=122;							
								else if(tab[i]+przesuniecie>122){
									int pom = tab[i]+przesuniecie - 122 -1;
									tab[i]=97+pom;	
										}
										else  tab[i]+=przesuniecie;
							}
							else if(tab[i] +przesuniecie ==122)tab[i]=122;
							else if(tab[i]==122)tab[i]= 97+przesuniecie -1;
							else if(tab[i]+przesuniecie >122 && tab[i]>=97 && tab[i]!=32)tab[i]=122-przesuniecie -1;
										cout<<(char)tab[i];		
													
						}break;
				
				
				
				case 1:		
					for(int i=0;i<w;i++){
						if(tab[i]==32)tab[i]=32; //spacja
						
						//cyfry
						if(tab[i]>48 && tab[i]<=57){
								if(tab[i]+przesuniecie2 ==48){tab[i]=48;}
								else if(tab[i]+przesuniecie2>48)tab[i]+=przesuniecie2;
								else if(tab[i]+przesuniecie2 <48){
								int pom = tab[i]+przesuniecie2 - 48 +1;
								tab[i]=57+pom;
							
							}	
						}
						
						else if(tab[i]==48)tab[i]= 57+przesuniecie2;	
						
							
						
							//DUZE A-Z
						if(tab[i]>65 && tab[i]<=90){
							if(tab[i]+przesuniecie==65){tab[i]=65;}
							else if(tab[i]+przesuniecie>65)tab[i]+=przesuniecie;
							else if(tab[i]+przesuniecie<65){
								int pom = tab[i]+przesuniecie - 65 +1;
								tab[i]=90+pom;
							
							}	
						}
						else if(tab[i] +przesuniecie ==65)tab[i]=65;
					//	else if(tab[i]==65)tab[i]= 65;	
						else if(tab[i]+przesuniecie <65 && tab[i]>=65 &&tab[i]!=32)tab[i]=90+przesuniecie +1;
							//cout<<(char)tab[i] ;
							
							
						//MALE a-z
						if(tab[i]>97 && tab[i]<=122){
							if(tab[i]+przesuniecie==97){tab[i]=97;}
							else if(tab[i]+przesuniecie>97)tab[i]+=przesuniecie;
							else if(tab[i]+przesuniecie<97){
								int pom = tab[i]+przesuniecie - 97 +1;
								tab[i]=122+pom;
							
							}	
						}
						else if(tab[i] +przesuniecie ==97)tab[i]=97;
						//else if(tab[i]==97)tab[i]= 97;
						else if(tab[i]+przesuniecie <97 && tab[i]>=97 && tab[i]!=32)tab[i]=122+przesuniecie +1;
							cout<<(char)tab[i] ;	
					}
					
					break;
									
				default:
					break;
					
					
		}
		
		
		char tab3[w];
					
					for(int i=0;i<w;i++)tab3[i]= (char)tab[i];
					zlicz(tab3);
	}




int main(){

	string slowo;
	cout<<"Podaj tekst do zaszyfrowania : ";
	getline(cin,slowo);
	
	int wielkosc = slowo.size();
	//cout<<wielkosc;
	int tab[wielkosc];
	zlicz(slowo);
	
	//-------------------Asci--------------
	/*cout<<"\n W ASCI : \n";
	*/
	for(int i=0 ; i<slowo.length();i++){
		tab[i] = (int) slowo[i];
	//	cout<<tab[i]<<" ," ;
	}



	szyfrowanie(tab,wielkosc);
	
	
	return 0;
}

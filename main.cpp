#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Plansza{
private:
    int a1,a2,a3=0;
    int b1,b2,b3=0;
    int c1,c2,c3=0;
    int pola[9]={0,0,0,0,0,0,0,0,0};

public:
    int getPole(int polozenie);
    void reset();
    void setPole(int polozenie, int kto);
    bool czyWygrana();

};

int Plansza::getPole(int polozenie){
    return Plansza::pola[polozenie];
}
void Plansza::reset(){
    for(int i=0;i<9;i++){
        Plansza::pola[i]=0;
    }
}

void Plansza::setPole(int polozenie, int kto){
    Plansza::pola[polozenie]=kto;
}

bool Plansza::czyWygrana(){
    if(Plansza::pola[0]!=0 && Plansza::pola[0]==Plansza::pola[1]&&Plansza::pola[1]==Plansza::pola[2]){
        return true;
    }else if(Plansza::pola[3]!=0 && Plansza::pola[3]==Plansza::pola[4]&&Plansza::pola[3]==Plansza::pola[5]){
        return true;
    }else if(Plansza::pola[6]!=0 && Plansza::pola[6]==Plansza::pola[7]&&Plansza::pola[6]==Plansza::pola[8]){
        return true;
    }else if(Plansza::pola[0]!=0 && Plansza::pola[0]==Plansza::pola[3]&& Plansza::pola[0]==Plansza::pola[6]){
        return true;
    }else if(Plansza::pola[1]!=0 && Plansza::pola[1]==Plansza::pola[4]&& Plansza::pola[1]==Plansza::pola[7]){
        return true;
    }else if(Plansza::pola[2]!=0 && Plansza::pola[2]==Plansza::pola[5]&& Plansza::pola[2]==Plansza::pola[8]){
        return true;
    }else if(Plansza::pola[0]!=0 && Plansza::pola[0]==Plansza::pola[4]&& Plansza::pola[0]==Plansza::pola[8]){
        return true;
    }else if(Plansza::pola[2]!=0 && Plansza::pola[2]==Plansza::pola[4]&& Plansza::pola[2]==Plansza::pola[6]){
        return true;
    }else{
        return false;
    }

}

int main()
{
    system("color 9");

    string imie1, imie2;
    Plansza plansza;
    string ktoWygrywa[5];

    cout<<"Podaj imienia graczy: ";
    cin>>imie1;
    cin>>imie2;
    cout<<endl<<"Miejsce w ktorym chcemy podac znak podajemy wg nastepujacego schematu: "<<endl<<endl;
    for(int i=1;i<10;i++){
        cout<<i<<" ";
        if(i%3==0){
            cout<<endl;
        }
    }


    for(int kolejka=0; kolejka<5;kolejka++){
        bool wygrana = false;
        string wygranaKto = "";
        bool ktoTeraz = true;
        int miejsce=0;
        int liczbaWyborow=0;

    cout<<endl<<"====================================================================================";

        cout<<endl<<endl<<"Runda numer: "<<kolejka+1<<endl;

        while(!wygrana){
            if(liczbaWyborow==9){
                cout<<endl<<"Remis!"<<endl;
                cout<<endl<<endl;
                for(int i=0;i<9;i++){
                    if(plansza.getPole(i)==0){
                        cout<<"- ";
                    }else if(plansza.getPole(i)==1){
                        cout<<"x ";
                    }else{
                        cout<<"o ";
                    }
                    if((i+1)%3==0){
                        cout<<endl;
                    }

                }
                cout<<endl;

                wygranaKto="remis";
                break;
            }
            if(ktoTeraz){
                cout<<endl<<endl;
                for(int i=0;i<9;i++){
                    if(plansza.getPole(i)==0){
                        cout<<"- ";
                    }else if(plansza.getPole(i)==1){
                        cout<<"x ";
                    }else{
                        cout<<"o ";
                    }
                    if((i+1)%3==0){
                        cout<<endl;
                    }

                }
                cout<<endl;


                bool czyDobrePole = false;
                do{
                    cout<<endl<<"Kolejka gracza "<<imie1;
                    cout<<" podaj miejsce x od 1 do 9: ";
                    cin>>miejsce;

                    miejsce--;
                    if(plansza.getPole(miejsce)==1){
                        cout<<"Te pole jest juz wybrane! Jeszcze raz"<<endl;
                    }else if(plansza.getPole(miejsce)==2){
                        cout<<"Te pole jest juz wybrane! Jeszcze raz"<<endl;
                    }else{
                        plansza.setPole(miejsce, 1);
                        liczbaWyborow++;
                        if(plansza.czyWygrana()){
                            wygrana=true;
                            wygranaKto=imie1;
                            cout<<endl<<"Wygrana gracza "<<imie1<<endl;
                            cout<<endl<<endl;

                            for(int i=0;i<9;i++){
                                if(plansza.getPole(i)==0){
                                    cout<<"- ";
                                }else if(plansza.getPole(i)==1){
                                    cout<<"x ";
                                }else{
                                    cout<<"o ";
                                }
                                if((i+1)%3==0){
                                    cout<<endl;
                                }

                            }
                            cout<<endl;
                            for(int p=0;p<9;p++){
                                plansza.setPole(p, 0);
                            }
                            break;
                        }
                        ktoTeraz=false;
                        czyDobrePole=true;
                    }


                }while(!czyDobrePole);
            }else{

                cout<<endl<<endl;
                for(int i=0;i<9;i++){
                    if(plansza.getPole(i)==0){
                        cout<<"- ";
                    }else if(plansza.getPole(i)==1){
                        cout<<"x ";
                    }else{
                        cout<<"o ";
                    }
                    if((i+1)%3==0){
                        cout<<endl;
                    }

                }
                cout<<endl;

                bool czyDobrePole = false;
                do{
                    cout<<endl<<"Kolejka gracza "<<imie2;
                    cout<<" podaj miejsce x od 1 do 9: ";
                    cin>>miejsce;

                    miejsce--;
                    if(plansza.getPole(miejsce)==1){
                        cout<<"Te pole jest juz wybrane! Jeszcze raz"<<endl;
                    }else if(plansza.getPole(miejsce)==2){
                        cout<<endl<<"Te pole jest juz wybrane! Jeszcze raz"<<endl;
                    }else{
                        plansza.setPole(miejsce, 2);
                        liczbaWyborow++;
                        if(plansza.czyWygrana()){
                            wygrana=true;
                            wygranaKto=imie2;
                            cout<<endl<<"Wygrana gracza "<<imie2<<endl;
                            cout<<endl<<endl;

                            for(int i=0;i<9;i++){
                                if(plansza.getPole(i)==0){
                                    cout<<"- ";
                                }else if(plansza.getPole(i)==1){
                                    cout<<"x ";
                                }else{
                                    cout<<"o ";
                                }
                                if((i+1)%3==0){
                                    cout<<endl;
                                }

                            }
                            cout<<endl;
                            for(int p=0;p<9;p++){
                                plansza.setPole(p, 0);
                            }
                            break;
                        }
                        ktoTeraz=true;
                        czyDobrePole=true;
                    }


                }while(!czyDobrePole);
            }
        }

    }
    return 0;
}

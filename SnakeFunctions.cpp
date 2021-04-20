#include "headers/SnakeFunctions.h"


namespace SNAKE
{
///----------------------------------------------------------------------------------------------------------
void MenuSnake()
{
    TLength szerokosc = L_Srednia;
    THigh   Wysokosc = H_Srednia;
    TPredkosc szybkosc = Srednio;
    Color KolGl{czerwony}, KolOg{bialy};    //KolorGlowy, KolorOgona

    ZKoloru(bialy);
    short wybor = 1;
    while(true)
    {
        system("cls");
        fstream plik;   string linia;
        plik.open("TXT/logo.txt",ios::in);
        while(getline(plik,linia))
        {
            cout << linia << endl;
        }
        plik.close();
        cout << endl;

        ZKoloru((wybor == 1 ? czerwony : bialy));
        cout << "\t        "<<(wybor == 1 ? "-": " ")<< " GRAJ"<<endl<<endl;
        ZKoloru((wybor == 2 ? czerwony : bialy));
        cout << "\t"<<(wybor == 2 ? "-": " ")<< " ZMIANA ROZMIARU MAPY" << endl<<endl;
        ZKoloru((wybor == 3 ? czerwony : bialy));
        cout << "\t"<<(wybor == 3 ? "-": " ")<<" ZMIANA PREDKOSCI WEZA"<<endl<<endl;
        ZKoloru((wybor == 4 ? czerwony : bialy));
        cout << "\t "<<(wybor == 4 ? "-": " ")<<" ZMIANA KOLORU WEZA"<<endl <<endl;
        ZKoloru((wybor == 5 ? czerwony : bialy));
        cout << "\t      "<<(wybor == 5 ? "-": " ")<<" RANKING"<<endl <<endl;
        ZKoloru((wybor == 6 ? czerwony : bialy));
        cout << "\t"<<"       "<<(wybor == 4 ? "-": " ")<<" WYJDZ";
        ZKoloru(bialy);

        unsigned char znak;
        while(WyborKlawisza(znak))  ;
        switch(znak)
        {
        case 119:
            if(wybor >1)    wybor--;
            break;
        case 115:
            if(wybor <6)    wybor++;
            break;
        case 13:
            MenuSnake_Przekierowanie(wybor, szerokosc, Wysokosc, szybkosc,KolGl, KolOg);
            break;
        default:
            break;
        }
    }
}
///-----------------------------------------------------------------------------------------------------------
void zegnam()
{
    system("cls");
    cout << endl;
    fstream plik; string linia;
    plik.open("TXT/Zegnam1.txt",ios::in);
    while(getline(plik,linia))cout <<linia<<endl;
    plik.close();
    Sleep(1000);
    system("cls");
    cout << endl;
    plik.open("TXT/Zegnam2.txt",ios::in);
    while(getline(plik,linia))cout <<linia<<endl;
    plik.close();
    Sleep(1000);
    system("cls");
    cout << endl;
    plik.open("TXT/Zegnam3.txt",ios::in);
    while(getline(plik,linia))cout <<linia<<endl;
    plik.close();
    Sleep(1000);
    system("cls");
    cout << endl;
    plik.open("TXT/Zegnam4.txt",ios::in);
    while(getline(plik,linia))cout <<linia<<endl;
    plik.close();
    getch();
    exit(0);
}
///-----------------------------------------------------------------------------------------------------------
    void ZmianaRozmiaru(TLength & Lplanszy, THigh &Hplanszy )
    {
        static short wskaznik = 1;
        unsigned char znak;
        vector <string> rozmiar = {"Malutka", "Mala", "Srednia", "Duza", "Ogromna"};
        bool powrot = true;
        system("cls");
        while(powrot)
        {
            system("cls");
            cout << endl<< endl << "                      " << setw(rozmiar[wskaznik-1].length()/2 + 1) << "^"
                 << endl << "Wybierz rozmiar mapy: ";
            ZKoloru(blekitny);
            cout << rozmiar[wskaznik-1];
            ZKoloru(bialy);
            cout<< endl << "                      " << setw(rozmiar[wskaznik-1].length()/2 + 1) << "v";
            while(WyborKlawisza(znak))  ;
            switch(znak)
            {
            case 119:
                if(wskaznik >1)
                    wskaznik--;
                else
                    wskaznik = rozmiar.size();
                break;
            case 115:
                if(wskaznik <rozmiar.size())
                    wskaznik++;
                else wskaznik = 1;
                break;
            case 13:
                switch(wskaznik)
                {
                case 1:
                    Lplanszy = L_BardzoMala;
                    Hplanszy = H_BardzoMala;
                    return;
                case 2:
                    Lplanszy = L_Mala;
                    Hplanszy = H_Mala;
                    return;
                case 3:
                    Lplanszy = L_Srednia;
                    Hplanszy = H_Srednia;
                    return;
                case 4:
                    Lplanszy = L_Duza;
                    Hplanszy = H_Duza;
                    return;
                case 5:
                    Lplanszy = L_Ogromna;
                    Hplanszy = H_Ogromna;
                    return;
                }
            default:
                break;
            }

        }
    }
///-----------------------------------------------------------------------------------------------------------
void ZmianaKoloru(Color &KolGl,Color& KolOg)
{
    static short wskaznik[3] = {1,12,15};
    unsigned char znak;
    vector <string> kolorki = {"Granatowy", "Zielony", "Turkusowy", "Bordowy", "Fioletowy","Sino koperkowy-roz","Srebrny",
        "szary","niebieski", "limonkowy", "blekitny", "czerwony", "rozowy", "zolty", "bialy"};
    bool powrot = true;
    while(powrot)
    {
        system("cls");
        ZKoloru(bialy);
        cout << endl<< endl << "                          " << setw(kolorki[wskaznik[1]-1].length()/2 + 1) << (wskaznik[0] == 1? "^":" ")
             << endl << "Wybierz kolor glowy weza: ";
        ZKoloru(static_cast<Color>(wskaznik[1]));
        cout << kolorki[wskaznik[1]-1] ;
        ZKoloru(bialy);
        cout << endl << "                          " << setw(kolorki[wskaznik[1]-1].length()/2 + 1) << (wskaznik[0] == 1? "v":" ")
        <<endl <<endl<<"\t"<<setw(18)<<" "<< setw(kolorki[wskaznik[2]-1].length()/2 + 21) << (wskaznik[0] == 2? "^":" ")
        <<endl<< "\t\t\tLub kolor ogona weza: ";
        ZKoloru(static_cast<Color>(wskaznik[2]));
        cout << kolorki[wskaznik[2]-1];
        ZKoloru(bialy);
        cout <<endl<<"\t"<<setw(18)<<" "<< setw(kolorki[wskaznik[2]-1].length()/2 + 21) << (wskaznik[0] == 2? "v":" ");

        cout << endl << endl;
        ZKoloru(static_cast<Color>(wskaznik[2]));
        cout << setw(35) << "##"; ZKoloru(static_cast<Color>(wskaznik[1])); cout << "#\n";
        ZKoloru(static_cast<Color>(wskaznik[2]));
        cout << setw(34) <<   "#" << endl;
        cout << setw(35) <<"#  ##" << endl;
        cout << setw(35) <<"#   #" << endl;
        cout << setw(35) <<"#####" << endl;


        while(WyborKlawisza(znak))  ;
        switch(znak)
        {
        case 119:
            if(wskaznik[0] == 1)
            {
                if(wskaznik[1] >1)
                wskaznik[1]--;
                else wskaznik[1] = kolorki.size();
            }
            else
            {
                if(wskaznik[2] >1)
                    wskaznik[2]--;
                else wskaznik[2] = kolorki.size();
            }

            break;
        case 115:
            if(wskaznik[0] == 1)
            {
                if(wskaznik[1] <kolorki.size())
                    wskaznik[1]++;
                else
                    wskaznik[1] = 1;
            }
            else
            {
               if(wskaznik[2] <kolorki.size())
                    wskaznik[2]++;
                else
                    wskaznik[2] = 1;
            }
            break;
        case 100:
            if(wskaznik[0] == 1)
                wskaznik[0] ++;
            break;
        case 97:
            if(wskaznik[0] == 2)
                wskaznik[0] --;
            break;
        case 13:
            KolGl = static_cast<Color>(wskaznik[1]);
            KolOg = static_cast<Color>(wskaznik[2]);
            return;
            break;
        default:
            break;
        }
    }
}
///-----------------------------------------------------------------------------------------------------------
void ZmianaPredkosci(TPredkosc &Szybkosc)
{
    static short wskaznik = 1;
    unsigned char znak;
    vector <string> rozmiar = {"Slimak", "Wolno", "Srednia predkosc", "Szybko", "Tragicznie szybko", "Przyspieszona"};
    bool powrot = true;
    while(powrot)
    {
        system("cls");
        cout << endl<< endl << "                      " << setw(rozmiar[wskaznik-1].length()/2 + 1) << "^"
             << endl << "Wybierz predkosc weza: ";
        ZKoloru(blekitny);
        cout << rozmiar[wskaznik-1];
        ZKoloru(bialy);
        cout<< endl << "                      " << setw(rozmiar[wskaznik-1].length()/2 + 1) << "v";
        while(WyborKlawisza(znak))  ;
        switch(znak)
        {
        case 119:
            if(wskaznik >1)
                wskaznik--;
            else wskaznik = rozmiar.size();
            break;
        case 115:
            if(wskaznik <rozmiar.size())
                wskaznik++;
            else
                wskaznik = 1;
            break;
        case 13:
            switch(wskaznik)
            {
            case 1:
                Szybkosc = BardzoWolno;
                return;
            case 2:
                Szybkosc = Wolno;
                return;
            case 3:
                Szybkosc = Srednio;
                return;
            case 4:
                Szybkosc = Szybko;
                return;
            case 5:
                Szybkosc = TragicznieSzybko;
                return;
            case 6:
                Szybkosc = Przyspiesza;
                return;
            }
        default:
            break;
        }

    }
}
///-----------------------------------------------------------------------------------------------------------
void ShowRanking()
{
    system("cls");
    fstream plik;
    string linia;
    plik.open("TXT/Ranking", ios::in);
    short licznik = 1;
    while(getline(plik,linia))
    {
        if(licznik < 9)
            cout << "\t\t";
        licznik ++;
        cout << linia<<endl;
    }
    Sleep(2000);
    getch();
    return;

}
///-----------------------------------------------------------------------------------------------------------
void MenuSnake_Przekierowanie(short wybor,TLength & Lplanszy, THigh &Hplanszy, TPredkosc &Szybkosc, Color& KolGl, Color &KolOg)
{
    switch(wybor)
    {
    case 1:
        system("cls");
        PlaySnake(Lplanszy, Hplanszy, Szybkosc,KolGl, KolOg);
        break;
    case 2:
        ZmianaRozmiaru(Lplanszy, Hplanszy);
        break;
    case 3:
        ZmianaPredkosci(Szybkosc);
        break;
    case 4:
        ZmianaKoloru(KolGl,KolOg);
        break;
    case 5:
        ShowRanking();
        break;
    case 6:
        zegnam();
        break;
    }
}
///-----------------------------------------------------------------------------------------------------------
void odliczanie(const TLength& Lplanszy,const THigh& Hplanszy)
{
    fstream plik; string linia;
    for(int i=3;i>0;i--)
        {
            string shit = "TXT/" + to_string(i) + ".txt";
            plik.open(shit.c_str(),ios::in);
            vector<string> odliczanie;
            while(getline(plik,linia))
                odliczanie.push_back(linia);
            plik.close();
            ZKoloru(bialy);
            setCursor(Lplanszy + 12, 8 );
            cout << odliczanie[0];
            setCursor(Lplanszy + 12, 9);
            cout << odliczanie[1].substr(0,2);
            ZKoloru(i == 3 ? bordowy : (i == 2 ? czerwony: zolty));
            cout << odliczanie[1].substr(2,1);
            ZKoloru(bialy);
            cout << odliczanie[1].substr(3,1);
            setCursor(Lplanszy + 12, 10);
            cout << odliczanie[2];
            Sleep(1000);
        }
        plik.open("TXT/GO.TXT",ios::in);
            vector<string> odliczanie;
            while(getline(plik,linia))
                odliczanie.push_back(linia);
            plik.close();
            ZKoloru(bialy);
            setCursor(Lplanszy + 12, 8 );
            cout << odliczanie[0];
            setCursor(Lplanszy + 12, 9);
            cout << odliczanie[1].substr(0,2);
            ZKoloru(zielony);
            cout << odliczanie[1].substr(2,2);
            ZKoloru(bialy);
            cout << odliczanie[1].substr(4,1);
            setCursor(Lplanszy + 12, 10);
            cout << odliczanie[2];
            Sleep(1000);
            for(int j = 0;j<3;j++)
            {
                setCursor(Lplanszy + 12, 8 + j);
                cout << "     ";
            }
}
///-----------------------------------------------------------------------------------------------------------
void PlaySnake(const TLength & Lplanszy, const THigh &Hplanszy, const TPredkosc &Szybkosc, const Color &KolGl,const Color &KolOg)
{
    srand(time(NULL));
    bool WIN = false;   fstream plik;string linia;
    ///ZEBY ZAWSZE LECIAL NA POCZATKU W PRAWO
    SOT::Kierunek = 3;
    SOT::KierunekPotwierdzenie = 3;

    vector <SOT> ogon;  //tworzymy vector elemtow ogona
    ogon.push_back(NKO(Lplanszy/2 + 1,Hplanszy/2 + 1)); //pierwszy element na srodku
    ogon.push_back(NKO((Lplanszy/2),Hplanszy/2 + 1,false));

    vector<vector<bool>> plansza;
    for(int i=0;i < Lplanszy;i++)
    {
        vector <bool> aa;
        for(int j=0;j < Hplanszy ;j++)
        {
            aa.push_back(true);
        }
        plansza.push_back(aa);
    }
    plansza[Lplanszy/2-1][Hplanszy/2-1] = false;


    NPPO(&ogon,Lplanszy,Hplanszy, Szybkosc);
    NewGwiazdka(&ogon,Lplanszy,Hplanszy,&plansza);

    ///ODLICZANIE
    odliczanie(Lplanszy, Hplanszy);

    clock_t start, stop;
    int Przyspieszenie = 500, licznik = 0;
    start = clock();
    char klawisz = 0;
    while(true)
    {
        stop = clock();
        double czas = (stop - start) * 1000 / CLOCKS_PER_SEC;
    ///ZMIENIENIE KIERUNKU
        if(kbhit() == true)
        {
            Klikniecie();
        }
    ///ZMIANA KIERUNKU END
    ///RUCH PO 1S

        if(czas >=(Szybkosc != Przyspiesza ? Szybkosc : Przyspieszenie))
        {
            licznik += czas;
            if(licznik >= 4000)
            {
                licznik = 0;
                Przyspieszenie = Przyspieszenie * 0.95;
            }
            SOT::KierunekPotwierdzenie = SOT::Kierunek;
            switch(SOT::Kierunek)
            {
            case 3:
                ogon.insert(ogon.begin(),NKO(ogon[0].x+1,ogon[0].y));
                break;
            case 6:
                ogon.insert(ogon.begin(),NKO(ogon[0].x,ogon[0].y+1));
                break;
            case 9:
                ogon.insert(ogon.begin(),NKO(ogon[0].x-1,ogon[0].y));
                break;
            case 12:
                ogon.insert(ogon.begin(),NKO(ogon[0].x,ogon[0].y-1));
                break;
            }

            {
                short X = ogon[0].x - 2, Y = ogon[0].y - 2;
                if(X >= 0 && Y >= 0 && X <Lplanszy && Y<Hplanszy)
                {
                    plansza[X][Y] = false;
                }
            }
            if(ZjedzenieGwiazdki(&ogon,Lplanszy,Hplanszy, &plansza,&WIN))
            {
                if(WIN)
                {
                    goto wygrana;
                }

                ogon.pop_back();
                {short X = ogon[ogon.size()-1].x - 2, Y = ogon[ogon.size()-1].y - 2;
                if(X >= 0 && Y >= 0 && X <Lplanszy && Y<Hplanszy)
                {
                    plansza[X][Y] = true;

                }}
                ogon[ogon.size() - 1].visible = false;

            }

            ///sprawdzenie kolizji
            if(kolizja(&ogon,Lplanszy,Hplanszy))
                goto przegrana;


            ZKoloru(KolOg);
            setCursor(ogon[1].x, ogon[1].y);
            cout << "#";
            ZKoloru(KolGl);
            setCursor(ogon[0].x, ogon[0].y);
            cout << "#";
            ZKoloru(Color::bialy);
            if(ogon[ogon.size()-1].x != SOT::GwiazdkaX || ogon[ogon.size()-1].y != SOT::GwiazdkaY)
            {
                setCursor(ogon[ogon.size()-1].x, ogon[ogon.size()-1].y);
                cout << " ";
            }

            start = clock();

        }
    ///RUCH PO 1S END

    }
    przegrana:
    setCursor(1,Hplanszy+5);
    plik.open("TXT/Przegrana.txt",ios::in);
    while(getline(plik,linia))
    {
        cout << linia << endl;
    }
    plik.close();

    if(NowyRekord(Lplanszy, Szybkosc,ogon.size() - 1))
        cout <<endl<< "USTANOWILES\\AS NOWY REKORD NA TEJ PLANSZY, PRZY TEJ PREDKOSCI!" << ENDL;

    Sleep(3000);
    cout << endl << "Prosze kliknac dowolny przycisk aby powrocic do menu!"<<endl;
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    getch();
    return;

    wygrana:
    if(WIN == true)
    {
        NowyRekord(Lplanszy, Szybkosc,ogon.size() - 1);
        setCursor(1,Hplanszy+5);
        plik.open("TXT/WIN.txt",ios::in);
        while(getline(plik,linia))
        {
            cout << linia << endl;
        }
        plik.close();
        Sleep(3000);
        cout << endl << "Prosze kliknac dowolny przycisk aby powrocic do menu!"<<endl;
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        getch();
    }
}
///----------------------------------------------------------------------------------------
bool NowyRekord(const TLength &wielkosc ,const TPredkosc& speed,unsigned short pkt)
{
    fstream plik;   string linia, H, V; vector<string> lista;
    plik.open("TXT/Ranking", ios::in);
    while(getline(plik,linia))
        lista.push_back(linia);
    plik.close();
    int x, y;
    switch(wielkosc){case 10:y = 12;break;case 20:y = 18;break;case 30:y = 24;break;case 40:y = 30;break;case 60:y = 36;break;}
    if(speed == 500)    x = 3;
    else if(speed == 350)    x = 12;
    else if(speed == 200)    x = 21;
    else if(speed == 100)    x = 31;
    else if(speed == 50 )    x = 44;
    else    x = 62;
    if(atoi(lista[y].substr(x,3).c_str()) < pkt)
    {
        string zamiana = to_string(pkt);
        for(int i = zamiana.length();i < 3;i++) zamiana += " ";
        lista[y].replace(x,3, zamiana);

        plik.open("TXT/Ranking", ios::out);
        for(auto elem : lista)
            plik << elem <<endl;
        plik.close();
        return true;
    }
    return false;
}
///----------------------------------------------------------------------------------------
void setCursor(const int x,const int y)
{
    COORD c;
    c.X = x-1;
    c.Y = y-1;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}
///----------------------------------------------------------------------------------------
bool kolizja(const vector <SOT>* ogon, const TLength & Lplanszy, const THigh &Hplanszy)
{
//    fstream plik;
//    plik.open("test.txt",ios::out | ios:: app);

    int x = (*ogon)[0].x, y = (*ogon)[0].y;

    if(x <= 1 || x >= Lplanszy + 2 || y <= 1 || y >= Hplanszy + 2)
        return true;

    for(int i = 1 ;i<(*ogon).size()-1 ;i++) //-1 bo ostatni jest niewidzialny
    {
        if((*ogon)[i].x == x && (*ogon)[i].y == y)
        {
//            plik <<"Numer czesci ogona ktory podlegl kolizji: "<< i <<endl
//                 <<"Wspolrzedne tej czesci ogona (" << (*ogon)[i].x << ","<<(*ogon)[i].y<<")\n"
//                 <<"Wspolrzedne glowy (" << x << ","<<y<<")\n";
//            plik.close();
            return true;
        }
    }
    return false;
}
///-----------------------------------------------------------------------------
bool WyborKlawisza(unsigned char &znak)
{
    znak = getch();
    if(znak == 224) znak = getch();
    switch(znak)
    {
    case 65: case 75:
        znak = 97;
        return false;
        break;
    case 68: case 77:
        znak = 100;
        return false;
        break;
    case 87: case 72:
        znak = 119;
        return false;
        break;
    case 83: case 80:
        znak = 115;
        return false;
        break;
    case 97: case 100: case 119: case 115: case 13: case 8:
        return false;
        break;
    default:
        return true;
    }
}

///-----------------------------------------------------------------------------
struct STAR
{
    short x,y;
};

bool NewGwiazdka(const vector <SOT>* ogon, const TLength & Lplanszy, const THigh &Hplanszy,const vector<vector<bool>> * plansza)
{
    vector<STAR> pole;

    for(int i=0;i<Lplanszy;i++)
    {
        for(int j=0;j<Hplanszy;j++)
        {
           if((*plansza)[i][j] == true)
            {
                pole.push_back({i+2,j+2});
            }
        }
    }

    if(!pole.size())
        return true;

    int wybor = rand() % pole.size();

    SOT::GwiazdkaX = pole[wybor].x;
    SOT::GwiazdkaY = pole[wybor].y;
    ZKoloru(Color::zolty);
    setCursor(SOT::GwiazdkaX ,SOT::GwiazdkaY);
    cout << "*";
    ZKoloru(Color::bialy);
    return false;
}
///---------------------------------------------------------------------------------------
bool ZjedzenieGwiazdki(const vector <SOT>*ogon, const TLength & Lplanszy, const THigh &Hplanszy,const vector<vector<bool>> * plansza, bool* T)
{
    if((*ogon)[0].x == SOT::GwiazdkaX && (*ogon)[0].y == SOT::GwiazdkaY )
    {
        if(NewGwiazdka(ogon,Lplanszy,Hplanszy,plansza))
            *T = true;


        setCursor(Lplanszy+20,3);    cout << "   \b\b\b"<< (*ogon).size()-1;
        return false;
    }
    return true;
}
///--------------------------------------------------------------------------------------------
void NPPO(const vector<SOT>* ogon,  const TLength & Lplanszy, const THigh &Hplanszy, const TPredkosc &szybkosc)
{
    setCursor(1,1);
    //cout << "+"
    for(int i=1;i<=Hplanszy + 2;i++)
    {
        cout << ((i== 1 || i==Hplanszy+2) ? "+" : "|");
        for(int j=1;j<=Lplanszy;j++)
        {
            unsigned char T = 0/*46 - kropka */, X = 45;
            cout << (((i == 1) || (i == Hplanszy+2))  ? X : T);
        }
        cout << ((i== 1 || i==Hplanszy+2) ? "+" : "|") << endl;
    }
    for(int i=0;i<(*ogon).size();i++)
    {
        if((*ogon)[i].visible == true)
        {
            setCursor((*ogon)[i].x,(*ogon)[i].y);
            cout << "#";
        }
//        else
//        {
//            setCursor((*ogon)[i].x,(*ogon)[i].y);
//            cout << "?";
//        }
    }
    ///dorysowanie miejsca na punktacje
    string rozmiar = "Wielkosc: "+HB(Lplanszy),
        speed = "Predkosc: "+HF(szybkosc);
    short okienko = 18;
    if(rozmiar.length() > okienko)   okienko = rozmiar.length();
    if(speed.length() > okienko)   okienko = speed.length();
    for(int i=1;i<=7 ;i++)
    {
        setCursor(Lplanszy+4,i);
        cout << ((i== 1 || i==7) ? "+" : "|");
        for(int j=Lplanszy+5;j<=Lplanszy+5+okienko;j++)
        {
            unsigned char T = 0/*46 - kropka */, X = 45;
            setCursor(j,i);
            cout << (((i == 1) || (i == 7))  ? X : T);
        }
        cout << ((i== 1 || i==7) ? "+" : "|") << endl;
    }
    setCursor((Lplanszy+5+Lplanszy+okienko+5)/2 - 2,2);    cout << "SNAKE";
    setCursor(Lplanszy+5,3);    cout << "Ilosc punktow: "<< 1;
    setCursor(Lplanszy+5,5);    cout << rozmiar;
    setCursor(Lplanszy+5,6);    cout << speed;

}
///-----------------------------------------------------------------------------
string HB(const TLength Lplanszy)   //HowBig
{
    switch(Lplanszy)
    {
    case L_BardzoMala:
        return "Malutka";
    case L_Mala:
        return "Mala";
    case L_Srednia:
        return "Srednia";
    case L_Duza:
        return "Duza";
    case L_Ogromna:
        return "Ogromna";
    }
}
///-----------------------------------------------------------------------------
string HF(const TPredkosc szyba)
{
    switch(szyba)
    {
    case BardzoWolno:
        return "BardzoWolna";
    case Wolno:
        return "Wolna";
    case Srednio:
        return "Srednia";
    case Szybko:
        return "Szybko";
    case TragicznieSzybko:
        return "Tragicznie szybko";
    case Przyspiesza:
        return "Przyspieszona";
    }
}
///-----------------------------------------------------------------------------
void Klikniecie()
{
    unsigned char x = getch();
    if(x == 224 || x == 0 || kbhit() == true)
    {
        x = getch();
    }
    switch(x)
    {
    case 97:
    case 65:
    case 75:
        if(SOT::KierunekPotwierdzenie != 3)
            SOT::Kierunek = 9;
        break;
    case 100:
    case 68:
    case 77:
        if(SOT::KierunekPotwierdzenie != 9)
            SOT::Kierunek = 3;
        break;
    case 83:
    case 115:
    case 80:
        if(SOT::KierunekPotwierdzenie != 12)
            SOT::Kierunek = 6;
        break;
    case 119:
    case 87:
    case 72:
        if(SOT::KierunekPotwierdzenie != 6)
            SOT::Kierunek = 12;
        break;
    default:
        break;
    }
}
///-----------------------------------------------------------------------------
void ZKoloru(Color X)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast <int> (X));
}
///-----------------------------------------------------------------------------
SOT NKO(int x, int y, bool T)    //NowyKawalekOgona
{
    SOT * Twsk = new SOT(x,y,T);
    return *Twsk;
}
///----------------------------------------------------------------------------------------------------------
}

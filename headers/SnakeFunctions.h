#ifndef snakefun
    #define snakefun 1

    #include "SNAKE.h"
    #include "SnakeEnum.h"
    #include <iostream>
    #include <conio.h>
    #include <windows.h>
    #include <time.h>
    #include <vector>
    #include <fstream>
    #include <iomanip>

    #define ENDL endl
    #define Endl endl
    #define Azero nullptr  //adres zerowy

    using namespace std;
    namespace SNAKE
    {
    ///----------------------------------------------------------------------------------------------------------


        void setCursor(int, int);
        void NPPO(const vector<SOT>* ,  const TLength & , const THigh &, const TPredkosc &);
        SOT NKO(int, int, bool = true) ;
        bool kolizja(const vector <SOT>* , const TLength & , const THigh &);
        bool NewGwiazdka(const vector <SOT>* , const TLength & , const THigh &,const vector<vector<bool>> *);
        void ZKoloru(Color);
        void Klikniecie();
        bool ZjedzenieGwiazdki(const vector <SOT>*,const TLength & , const THigh &,const vector<vector<bool>> *,bool*);
        void PlaySnake(const TLength &, const THigh &, const TPredkosc &, const Color &,const Color &);
        void MenuSnake();
        bool WyborKlawisza(unsigned char &);
        void MenuSnake_Przekierowanie(short , TLength & ,THigh &,  TPredkosc &, Color&,Color&);
        void zegnam();
        void ZmianaRozmiaru(TLength &, THigh &);
        void ZmianaPredkosci(TPredkosc &);
        string HB(const TLength);
        string HF(const TPredkosc);
        void ZmianaKoloru(Color &,Color& );
        void ShowRanking();
        bool NowyRekord(const TLength &,const TPredkosc&,unsigned short);
        void odliczanie(const TLength&,const THigh&);
    ///----------------------------------------------------------------------------------------------------------
    }

#endif // snake

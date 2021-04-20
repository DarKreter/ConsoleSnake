#ifndef snake
    #define snake 1

    /*
        Jego deklaracja jest w SnakeFunctions.h !
    */

    #include <vector>

    using std::vector;
namespace SNAKE
{
///----------------------------------------------------------------------------------------------------------
        class SOT   //SliceOfTail
        {
            friend void NPPO(const vector<SOT>* ogon);
            friend bool kolizja(const vector <SOT>* ogon);

            public: ///PRIVATE!!!
            short x, y; //wspolrzedne gdzie teraz jest element ogona
            bool visible;

            public:
            static short Kierunek;
            static short KierunekPotwierdzenie;
            static short GwiazdkaX, GwiazdkaY;
            /**
                na 12 - w gore
                na 3  - w prawo
                na 6  - w dol
                na 9  - w lewo
            */
            SOT(short XxX, short YyY, bool NW);
            void przedstaw_sie();
        };
///----------------------------------------------------------------------------------------------------------
}


#endif // snake

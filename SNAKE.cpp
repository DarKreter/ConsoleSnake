#include "headers/SnakeFunctions.h"

namespace SNAKE
{
///----------------------------------------------------------------------------------------------------------
    short SOT::Kierunek = 3;   //statyczny obiekt musi byc zainicjializowany by dzialac poprawnie
    short SOT::KierunekPotwierdzenie = 3;
    short SOT::GwiazdkaX = 0, SOT::GwiazdkaY = 0;

    SOT::SOT(short XxX, short YyY, bool NW)
    {
        x = XxX;
        y = YyY;
        visible = NW;
    }

    void SOT::przedstaw_sie()
    {
        cout << "Witam, moje x=" << x<< ", a y="<<y<<endl;
    }
///----------------------------------------------------------------------------------------------------------
}

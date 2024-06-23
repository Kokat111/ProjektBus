#include "Bus.h"

void Bus::info() {
    cout << "Nazwa polaczenia: " << BusName << endl << "wyjazd o godzinie ";
    if ((DepartureMinutes / 60) < 10)
        cout << '0' << DepartureMinutes / 60;
    else
        cout << DepartureMinutes / 60;
    cout << ':';
    if ((DepartureMinutes % 60) < 10)
        cout << '0' << DepartureMinutes / 60;
    else
        cout << DepartureMinutes % 60;
    cout << ", " << DepartureDay << '.' << DepartureMonth << '.' << DepartureYear << ", " << endl << "przyjazd o godzinie ";
    if ((ArrivalMinutes / 60) < 10)
        cout << '0' << ArrivalMinutes / 60;
    else
        cout << ArrivalMinutes / 60;
    cout << ':';
    if ((ArrivalMinutes % 60) < 10)
        cout << '0' << ArrivalMinutes / 60;
    else
        cout << ArrivalMinutes % 60;
    cout << ", ";
    cout << ArrivalDay << '.' << ArrivalMonth << '.' << ArrivalYear << ", " << endl;
}

Bus::Bus(int DepMin, int DepDay, int DepMonth, int DepYear,
    int ArrMin, int ArrDay, int ArrMonth, int ArrYear,
    string BName) :ArrivalMinutes(ArrMin), ArrivalDay(ArrDay), ArrivalMonth(ArrMonth), ArrivalYear(ArrYear),
    DepartureMinutes(DepMin), DepartureDay(DepDay), DepartureMonth(DepMonth), DepartureYear(DepYear),
    BusName(BName) {}
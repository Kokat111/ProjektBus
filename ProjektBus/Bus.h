#pragma once
#include "Libs.h"

class Bus {
   /* string BusFrom, BusTo;*/
    int ArrivalMinutes, ArrivalDay, ArrivalMonth, ArrivalYear;
    int DepartureMinutes, DepartureDay, DepartureMonth, DepartureYear;
    string BusName;

public:
    Bus(int DepartureMinutes = 0, int DepartureDay = 1, int DepartureMonth = 1, int DepartureYear = 2024,
        int ArrivalMinutes = 23 * 60 + 59, int ArrivalDay = 31, int ArrivalMonth = 12, int ArrivalYear = 2024,
        string BusName = "muszkieter"/* string BusFrom = "Gliwice", string BusTo = "Katowice" */);
    void info();
};
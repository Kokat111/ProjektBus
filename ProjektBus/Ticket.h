#pragma once
#include "Libs.h"

class Ticket {
    double TicketPriceNormal, TicketPriceVIP;
    bool isBoughtNormal, isBoughtVIP;

public:
    Ticket(double TicketPriceNormal = 20, double TicketPriceVIP = 30, bool isBoughtNormal = false, bool isBoughtVIP = false);
    void info();
};
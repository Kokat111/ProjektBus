#include "Ticket.h"

void Ticket::info() {
    cout << "cena za bilet to " << TicketPriceNormal << "zl" << endl;
}
Ticket::Ticket(double TPriceNormal, double TPriceVIP, bool isBNormal, bool isBVIP) :
    TicketPriceNormal(TPriceNormal), TicketPriceVIP(TPriceVIP), isBoughtNormal(isBNormal), isBoughtVIP(isBVIP) {}
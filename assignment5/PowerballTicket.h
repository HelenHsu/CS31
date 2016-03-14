//PowerballTicket.h
#ifndef POWERBALLTICKET_INCLUDED
#define POWERBALLTICKET_INCLUDED

#include "RandomNumber.h"

class PowerballTicket
{
 public:
	PowerballTicket(int ball1,int ball2, int ball3,int ball4, int ball5, int powerball);
	~PowerballTicket(){};
	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getPowerball();
 private:
	int m_ball1,m_ball2,m_ball3,m_ball4,m_ball5,m_powerball;

};

#endif	//POWERBALLTICKET_INCLUDED

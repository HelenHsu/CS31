//PowerballLottery.h
#ifndef POWERBALLLOTTERY_INCLUDED
#define POWERBALLLOTTERY_INCLUDED

#include "RandomNumber.h"
#include "PowerballTicket.h"
class PowerballLottery
{
 public:
	PowerballLottery();	//use RandomNumber to generate numbers
	PowerballLottery(int ball1,int ball2, int ball3,int ball4, int ball5, int powerball);
	~PowerballLottery(){};
	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getPowerball();
	enum WinningPossibility{POWERBALL, ONEPLUSPOWERBALL,TWOPLUSPOWERBALL,THREE,THREEPLUSPOWERBALL,FOUR,FOURPLUSPOWERBALL,FIVE,FIVEPLUSPOWERBALL,NOTWINNING};
	PowerballTicket quickPick();
	WinningPossibility checkTicket(PowerballTicket ticket);
	void printWhatHappened(PowerballTicket ticket);
 private:
	int m_ball1,m_ball2,m_ball3,m_ball4,m_ball5,m_powerball;

};


#endif	//POWERBALLLOTTERY_INCLUDED

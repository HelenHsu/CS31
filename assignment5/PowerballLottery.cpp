//PowerballLottery.cpp
#include "PowerballLottery.h"
#include "PowerballTicket.h"
#include "RandomNumber.h"
#include <iostream>
using namespace std;

PowerballLottery::PowerballLottery(int ball1,int ball2, int ball3,int ball4, int ball5, int powerball):m_ball1(ball1),m_ball2(ball2),m_ball3(ball3),m_ball4(ball4),m_ball5(ball5),m_powerball(powerball){};
int PowerballLottery::getBall1(){return m_ball1;};
int PowerballLottery::getBall2(){return m_ball2;};
int PowerballLottery::getBall3(){return m_ball3;};
int PowerballLottery::getBall4(){return m_ball4;};
int PowerballLottery::getBall5(){return m_ball5;};
int PowerballLottery::getPowerball(){return m_powerball;};
PowerballLottery::PowerballLottery()
{
	//use RandomNumber to generate numbers

	//create a ball generator
	RandomNumber* BallGenerator= new RandomNumber(1,69,true,true);
	//cerr<<"example output of the generator is "<<BallGenerator->random()<<endl;
	int BallNumbers[6]={0,0,0,0,0};
	for(int i=0; i<5;i++){
		bool duplicate=false;
		//Generate a random first and then check if duplicate with other balls
		//if found duplicate, generate a number again
		do{	
			BallNumbers[i]=BallGenerator->random();
			for(int j=0;j<i;j++)			
				if(i!=0 && BallNumbers[i]==BallNumbers[j])
					duplicate = true;
				
		}while(duplicate);
		//cerr<< BallNumbers[i]<<endl;
	
	}
	delete BallGenerator;
	m_ball1=BallNumbers[1];
	m_ball2=BallNumbers[2];
	m_ball3=BallNumbers[3];
	m_ball4=BallNumbers[4];
	m_ball5=BallNumbers[5];

	//create a powerball generator 
	RandomNumber* PowerballGenerator= new RandomNumber(1,26,true,true);
	m_powerball=PowerballGenerator->random();
	delete PowerballGenerator;
}

PowerballTicket PowerballLottery::quickPick()
{
	PowerballTicket ticket(m_ball1,m_ball2,m_ball3,m_ball4,m_ball5,m_powerball);
	return ticket;
}

PowerballLottery::WinningPossibility PowerballLottery::checkTicket(PowerballTicket ticket)
{
	int numberOfSameBalls(0);
	bool samePowerball(false);
	//get the ball numbers and put them in arrays 
	int ballsToCheck[5];
	ballsToCheck[0]=ticket.getBall1();
	ballsToCheck[1]=ticket.getBall2();
	ballsToCheck[2]=ticket.getBall3();
	ballsToCheck[3]=ticket.getBall4();
	ballsToCheck[4]=ticket.getBall5();
	int ballsInLottery[5];
	ballsInLottery[0]=getBall1();
	ballsInLottery[1]=getBall2();
	ballsInLottery[2]=getBall3();
	ballsInLottery[3]=getBall4();
	ballsInLottery[4]=getBall5();
	//in case the ball numbers are not in order, use for loop to check every balls
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(ballsToCheck[i]==ballsInLottery[j])
				numberOfSameBalls++;
	//check if the same powerball
	if (ticket.getPowerball()==this->getPowerball())
		samePowerball=true;
	switch(numberOfSameBalls)
	{
		case 0:
			return (samePowerball?POWERBALL:NOTWINNING);
		case 1:
			return (samePowerball?ONEPLUSPOWERBALL:NOTWINNING);
		case 2:
			return (samePowerball?TWOPLUSPOWERBALL:NOTWINNING);
		case 3: 
			return (samePowerball?THREEPLUSPOWERBALL:THREE);
		case 4:
			return (samePowerball?FOURPLUSPOWERBALL:FOUR);
		case 5:
			return (samePowerball?FIVEPLUSPOWERBALL:FIVE);
		default:
			return NOTWINNING;

	}

}

void PowerballLottery::printWhatHappened(PowerballTicket ticket)
{
	WinningPossibility result = checkTicket(ticket);
	//use enum WinningPossibility as switch
	switch(result)
	{
	 case NOTWINNING:
		cout<<"You didn't win anything.  Please buy another ticket!"<<endl;break;
	 case POWERBALL:
		cout<<"You matched just the powerball.  Congratulations!"<<endl;break;
	 case ONEPLUSPOWERBALL:
		cout<<"You matched one ball plus the powerball.  Congratulations!"<<endl;break;
	 case TWOPLUSPOWERBALL:
		cout<<"You matched two balls plus the powerball.  Congratulations!"<<endl;break;
	 case THREEPLUSPOWERBALL:
		cout<<"You matched three balls plus the powerball.  Congratulations!"<<endl; break;
	 case THREE:
		cout<<"You matched three balls but not the powerball.  Congratulations!"<<endl; break;
	 case FOURPLUSPOWERBALL:
		cout<<"You matched four balls plus the powerball.  Congratulations!"<<endl; break;
	 case FOUR:
		cout<<"You matched four balls but not the powerball.  Congratulations!"<<endl;break;
	 case FIVE:
		cout<<"You matched five balls but not the powerball.  Congratulations!"<<endl;break;
	 case FIVEPLUSPOWERBALL:
		cout<<"You won the jackpot - all balls plus the powerball.  Congratulations!"<<endl;break;
	 default:
		cerr<<"Something is wrong!"<<endl;
	}
}

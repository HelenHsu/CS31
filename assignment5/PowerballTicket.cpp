//PowerballTicket.cpp
#include "PowerballTicket.h"

PowerballTicket::PowerballTicket(int ball1,int ball2, int ball3,int ball4, int ball5, int powerball):m_ball1(ball1),m_ball2(ball2),m_ball3(ball3),m_ball4(ball4),m_ball5(ball5),m_powerball(powerball){};
int PowerballTicket::getBall1(){return m_ball1;};
int PowerballTicket::getBall2(){return m_ball2;};
int PowerballTicket::getBall3(){return m_ball3;};
int PowerballTicket::getBall4(){return m_ball4;};
int PowerballTicket::getBall5(){return m_ball5;};
int PowerballTicket::getPowerball(){return m_powerball;};

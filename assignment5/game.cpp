//testcase example provided by CS31

#include <iostream>
#include <string>
#include <cassert>
using namespace std;
#include "PowerballTicket.h"
#include "PowerballLottery.h"
int main()
{
	// test PowerballTicket 
           PowerballTicket ticket( 1, 2, 3, 4, 5, 6 );
           assert( ticket.getBall1() == 1);
           assert( ticket.getBall2() == 2);
           assert( ticket.getBall3() == 3); 
           assert( ticket.getBall4() == 4);
           assert( ticket.getBall5() == 5);
           assert( ticket.getPowerball() == 6);
	// test PowerballLottery
           PowerballLottery lottery( 1, 2, 3, 4, 5, 6 );
           assert( lottery.getBall1() == 1);
           assert( lottery.getBall2() == 2); 
           assert( lottery.getBall3() == 3);
           assert( lottery.getBall4() == 4);
           assert( lottery.getBall5() == 5);
           assert( lottery.getPowerball() == 6);
           assert( lottery.checkTicket(ticket) == PowerballLottery::WinningPossibility::FIVEPLUSPOWERBALL);
	// check each output
           lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 2, 3, 4, 15, 6 );
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 2, 3, 14, 15, 6 );
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 2, 13, 14, 15, 6 );
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 12, 13, 14, 15, 6 );
	   lottery.printWhatHappened(ticket);		  
           ticket = PowerballTicket( 11, 12, 13, 14, 15, 6 );
	   lottery.printWhatHappened(ticket);		  
	   ticket = PowerballTicket( 1, 2, 3, 4, 5, 12 );
           assert( lottery.checkTicket(ticket) == PowerballLottery::WinningPossibility::FIVE);
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 2, 3, 4, 15, 16 );
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 2, 3, 14, 15, 16 );
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 2, 13, 14, 15, 16 );
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 1, 12, 13, 14, 15, 16 );
	   lottery.printWhatHappened(ticket);
           ticket = PowerballTicket( 11, 12, 13, 14, 15, 16 );
	   lottery.printWhatHappened(ticket);

	// check the balls that are not in order
	   ticket= PowerballTicket( 1, 2, 3, 4, 5, 6 );
	   PowerballTicket sameticket( 5, 4, 3, 2, 1, 6 );
	   assert(lottery.checkTicket(ticket)==lottery.checkTicket(sameticket));
                    
	// ckeck no duplicate in quickPick 
           PowerballTicket quickPickTicket( 1, 2, 3, 4, 5, 6);
           for (int i = 0; i < 20; i++)
           { 
               quickPickTicket = lottery.quickPick();
               // all the ball numbers need to be different...
               assert( quickPickTicket.getBall1() != quickPickTicket.getBall2() &&
                       quickPickTicket.getBall1() != quickPickTicket.getBall3() &&
                       quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
                       quickPickTicket.getBall1() != quickPickTicket.getBall5() &&
                       quickPickTicket.getBall2() != quickPickTicket.getBall3() &&
                       quickPickTicket.getBall2() != quickPickTicket.getBall4() &&
                       quickPickTicket.getBall2() != quickPickTicket.getBall5() &&
                       quickPickTicket.getBall3() != quickPickTicket.getBall4() &&
                       quickPickTicket.getBall3() != quickPickTicket.getBall5() &&
                       quickPickTicket.getBall4() != quickPickTicket.getBall5());
           }
           assert(quickPickTicket.getPowerball()<=26);
 	   assert(quickPickTicket.getBall1()<=69);
	 
	// test default constructor, play with quick pick  
	  PowerballLottery testNoInput;
	  PowerballLottery playWithQuickPick;
	  testNoInput.printWhatHappened(playWithQuickPick.quickPick());
	  

          cerr<< "all tests passed!" << endl;
          return 0;


}

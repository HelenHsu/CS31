//
//  main.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//
/*
//////////////////////////////////////////////////////////////
//						TEST								//
//////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cassert>
#include "Game.h"
#include "Player.h"
#include "Card.h"

using namespace std;

int main()
{
	using namespace std;
	using namespace cs31;

	// test code
	Player p;

	Card c(Face::ACE, Suit::DIAMONDS);
	Card d(Face::TEN, Suit::CLUBS);
	Card e(Face::THREE, Suit::SPADES);
	Card f(Face::EIGHT, Suit::HEARTS);

	assert(p.handcount() == 0);
	assert(p.hasBlackJack() == false);
	assert(p.cardCount() == 0);
	p.acceptCard(c);
	assert(p.handcount() == 11);
	assert(p.hasBlackJack() == false);
	assert(p.cardCount() == 1);
	assert(p.getCard(0) == c);
	p.acceptCard(d);
	assert(p.handcount() == 21);
	assert(p.hasBlackJack() == true);

	p = Player();
	p.acceptCard(c);
	p.acceptCard(c);
	p.acceptCard(c);
	assert(p.handcount()==13);
	//test the logic error when ask the cards that you dont have
	try {
		p.getCard(5);	//should throw an excption 
	}
	catch (std::logic_error & le)
	{
		cerr << le.what() << endl;
	}

	//test the logic error when deal too many cards
	p = Player(); 
	try {
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);
		p.acceptCard(c);	//should throw an excption 
	}
	catch (exception& e)
	{
		cerr << e.what()<<endl;
	}

	p = Player();
	Player dealer;
	Game g(p, dealer);
	g.playerStands();
	g.dealerStands();
	//no one should be busted at the beginning
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	//both has no cards
	assert(g.playerTied() == true);
	assert(g.playerWon() == false);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);

	//case when player got BlackJack
	p = Player();
	p.acceptCard(c);
	p.acceptCard(d);
	dealer = Player();
	dealer.acceptCard(e);
	dealer.acceptCard(f);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == true);
	assert(g.dealerHasBlackJack() == false);

	//case when player is busted
	p = Player();
	p.acceptCard(c);
	p.acceptCard(d);
	p.acceptCard(e);
	p.acceptCard(f);
	dealer = Player();
	dealer.acceptCard(e);
	dealer.acceptCard(f);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == true);
	assert(g.playerTied() == false);
	assert(g.playerWon() == false);
	assert(g.playerLost() == true);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);


	//case when both 21, with player having BlackJack
	p = Player();
	p.acceptCard(c);
	p.acceptCard(d);
	dealer = Player();
	dealer.acceptCard(d);
	dealer.acceptCard(e);
	dealer.acceptCard(f);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == true);
	assert(g.playerWon() == false);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == true);
	assert(g.dealerHasBlackJack() == false);

	//case when both black jack
	//case when both 21, with player having BlackJack
	p = Player();
	p.acceptCard(c);
	p.acceptCard(d);
	dealer = Player();
	dealer.acceptCard(d);
	dealer.acceptCard(c);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == true);
	//clearScreen();
	g.dealerPlays();
	if (g.playerWon())
	{
		g.display("WON!", true);
	}
	else if (g.playerLost())
	{
		g.display("LOST!", true);
	}
	else
	{
		g.display("TIED!", true);
	}

	cout << "all tests passed!" << endl;
	cin.get();
	return 0;

}

*/
//////////////////////////////////////////////////////////////
//				GAME START HERE								//	
//////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
void clearScreen();

int main(int argc, const char * argv[])
{

    using namespace cs31;
    using namespace std;
    string action;
    
    Game g;
	try {
		g.deal();
		clearScreen();
		if (g.playerHasBlackJack() || g.dealerHasBlackJack())
		{
			g.playerStands();
			g.dealerStands();
		}
		else
		{
			do
			{
				g.display("(h)it (s)tand or (q)uit:");
				getline(cin, action);
				if (action.size() == 0)
				{
					g.playerStands();
				}
				else
				{
					switch (action[0])
					{
					default:   // if bad move, nobody moves
						cout << '\a' << endl;  // beep
						continue;
					case 'Q':
					case 'q':
						return 0;
					case 'h':
					case 'H':
						g.playerHits();
						clearScreen();
						break;
					case 's':
					case 'S':
						g.playerStands();
						break;
					}
				}
			} while (!g.playerBusted() && !g.playerStood());

			clearScreen();
			g.dealerPlays();
		}
	}
	catch (exception& e)
	{
		cerr << e.what();
	}

    if (g.playerWon())
    {
        g.display( "WON!", true );
    }
    else if (g.playerLost())
    {
        g.display( "LOST!", true );
    }
    else
    {
        g.display( "TIED!", true );
    }
    
 
	cin.get();
    return 0;
}

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

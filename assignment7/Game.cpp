//
//  Game.cpp
//  HandHomework
//
//  Created by Howard Stahl on 12/6/15.
//  Copyright © 2015 Howard Stahl. All rights reserved.
//

#include "Game.h"
#include <iostream>

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{

Game::Game()
{
	//mPlayer = Player();// TODO : set the outcome of the game initially
	//mDealer = Player();
	mOutcome = NOOUTCOME;	
	mPlayerStood = false; //        set the player's turn is not yet over
}
 
Game::Game( Player player, Player dealer )
{
    mPlayer = player;
    mDealer = dealer;
	mOutcome = NOOUTCOME;// TODO : set the outcome of the game initially
	mPlayerStood = false;//        set the player's turn is not yet over
}

// did the Player win?
bool Game::playerWon()
{
    return( mOutcome == PLAYERWON );
}
    
// did the Player lose?
bool Game::playerLost()
{
    return( mOutcome == PLAYERLOST );
}
    
// did the Player and the Dealer tie?
bool Game::playerTied( )
{
    return( mOutcome == TIED );
}
    
void Game::deal()
{
	mDeck.shuffleDeck();// TODO : shuffle deck
	mPlayer.acceptCard(mDeck.dealCard());
	mPlayer.acceptCard(mDeck.dealCard());
	mDealer.acceptCard(mDeck.dealCard());
	mDealer.acceptCard(mDeck.dealCard());//        deal two cards to the player and two to the dealer
}
    
void Game::playerHits( )
{
	mPlayer.acceptCard(mDeck.dealCard());// TODO : deal another card to the player
}
    
// let the Game know that the Player's turn is over
void Game::playerStands()
{
    mPlayerStood = true;
}
 
// has the Player's turn ended?
bool Game::playerStood() const
{
    return( mPlayerStood );
}

void Game::dealerHits( )
{
	mDealer.acceptCard(mDeck.dealCard());// TODO : deal another card to the dealer
}
    
void Game::dealerStands( )
{
	int dealerCount = mDealer.handcount();
	int playerCount = mPlayer.handcount();
	if (playerBusted() && !dealerBusted())
		mOutcome = PLAYERLOST;
	else if (!playerBusted() && dealerBusted())
		mOutcome = PLAYERWON;
	else if (playerBusted() && dealerBusted())
		mOutcome = TIED;
	else //both not busted
	{
		if (playerCount > dealerCount)
			mOutcome = PLAYERWON;
		else if (playerCount < dealerCount)
			mOutcome = PLAYERLOST;
		else
			mOutcome=TIED;
	}
	return;
		// TODO : since the game is now over, determine the outcome
    //        store the outcome in the member mOutcome
}
    
bool Game::dealerBusted( ) const
{
    // TODO : did the dealer go over 21?
    /*bool result = false;
	result = (mDealer.handcount() > 21 ? true : false);
	return( result );
	*/
	return (mDealer.handcount() > 21 ? true : false);
}
    
bool Game::playerBusted( ) const
{
    // TODO : did the player go over 21?
   /* bool result = false;
	result = (mPlayer.handcount() > 21 ? true : false);
	return(result);
	*/
	return (mPlayer.handcount() > 21 ? true : false);

}
    
void Game::dealerPlays()
{
	if (!playerBusted())
		while (mDealer.handcount() < 17)
			dealerHits();
		// TODO : if the player hasn't busted,
    //        play the dealer's hand by taking cards until the
    //        dealer's cards total 17 or more or the dealer busts

    // let the Game know that play has ended
    dealerStands();
}
    
bool Game::playerHasBlackJack( ) const
{
    // TODO : does the player have blackjack?h
    //bool result = false;
	//result = 
	return (mPlayer.hasBlackJack() ? true : false);
	//return( result );
}
    
bool Game::dealerHasBlackJack( ) const
{
    // TODO : does the dealer have blackjack?
    //bool result = false;
    //return( result );
	return (mDealer.hasBlackJack() ? true : false);
}
    
//
// ALL THE CODE BELOW THIS POINT SHOULD NOT BE CHANGED!
//
void Game::display( std::string s , bool allCards )
{
    // when allCards is true  --> show all dealer cards
    // otherwise just show the one turned up dealer card
    // and then display the passed message at the bottom of the screen, if supplied
    using namespace std;
    int dealerCount = mDealer.handcount();
    int playerCount = mPlayer.handcount();
    cout << "DEALER'S HAND:" << endl;
    if (allCards)
    {
        cout << mDealer << endl;
    }
    else
    {
        cout << mDealer.getCard(0) << endl;
    }
    if (dealerBusted())
    {
        cout << "          --->dealer busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << dealerCount << endl;
    }
    cout << endl;
    cout << "PLAYER'S HAND:" << endl;
    cout << mPlayer << endl;
    if (playerBusted())
    {
        cout << "          --->player busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << playerCount << endl;
    }

    if (s != "")
        cout << s << endl;
}
    


    
}
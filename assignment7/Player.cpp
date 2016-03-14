//
//  Hand.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//
#include <stdexcept>
#include "Player.h"

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{

Player::Player( )
{
    // The Player has no Cards in his hand
    myNumberOfCards = 0;
}
    
std::ostream& operator <<( std::ostream& outs, const Player & p )
{
	for (int i = 0; i < p.cardCount(); i++)
		outs << p.getCard(i) <<std::endl;
		// TODO : print out all the actual cards in the array myCards
    return( outs );
}
    
void Player::acceptCard(Card c)
{
	if (myNumberOfCards < MAXCARDS)
	{
		myCards[myNumberOfCards] = c;
		myNumberOfCards++;
	}
	else
		throw(std::logic_error("Too many cards!"));		//////////////////////////how to write an excption?
		// TODO : as long as there is space in the array myCards, place Card c into myCards
    //        if there is not enough space for another card, throw an exception
}
    
Card Player::getCard( int index ) const
{
    // TODO : return the requested card
    //        if the index is bad, throw an exception
	if (index>myNumberOfCards)
		throw(std::logic_error("I don't have that many cards!"));
	if (index < 0)
		throw(std::logic_error("What do you mean by negative cards?"));
	return myCards[index];
	//Card c;
    //return( c );
}

int  Player::cardCount() const
{
	return myNumberOfCards; 
}

int  Player::handcount( ) const
{
    // TODO : total up the points in this player's hand
    //        you will need to figure out how to handle Ace's that might be worth 1 or 11
    int total = 0;
	int numberOfAce=0;
	for (int i = 0; i < myNumberOfCards; i++)
	{
		total += myCards[i].count();
		if (myCards[i].count() == 1)
			numberOfAce++;
	}
	while (numberOfAce>0 && total<12)
	{
		numberOfAce--;
		total += 10;
	}
		return( total );
}
    
    
bool Player::hasBlackJack( ) const
{
    bool result = false;
    if (myNumberOfCards == 2 && handcount() == 21)
    {
        result = true;
    }
    return( result );
}
    
}
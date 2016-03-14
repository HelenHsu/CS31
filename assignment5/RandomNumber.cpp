//
//  RandomNumber.cpp
//  Project5
//
//  Created by Howard Stahl on 1/11/16.
//

#include "RandomNumber.h"

#include <random>
#include <utility>

using namespace std;

RandomNumber::RandomNumber( int min, int max,
                            bool minInclusive, bool maxInclusive )
                            : mMinimum( min ), mMaximum( max )
{
    if (mMinimum > mMaximum)
    {
        swap( mMinimum, mMaximum );
    }
    if (!minInclusive)
    {
        mMinimum++;
    }
    if (!maxInclusive)
    {
        mMaximum--;
    }
}

int RandomNumber::random( )
{
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro( mMinimum, mMaximum );
    
    return( distro( generator ) );
}



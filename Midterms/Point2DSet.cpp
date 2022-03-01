/*

    Point, COS30008, 2021

 */

#include "Point2DSet.h"

#include <fstream>
#include <stdexcept>
#include <algorithm>                                                            // (6)

using namespace std;

bool orderByCoordinates( const Point2D& aLeft, const Point2D& aRight )
{
    return aLeft < aRight;                                                      // (4)
}

bool orderByPolarAngle( const Point2D& aLHS, const Point2D& aRHS )
{
    // on the same line (tie)
    if ( aLHS.isCollinear( aRHS ) )                                             // 6
    {
        return aLHS.magnitude() > aRHS.magnitude();                             // 6
    }

    // minimum polar angle
    return aLHS.direction() < aRHS.direction();                                 // 6(16)
}

void Point2DSet::add( const Point2D& aPoint )
{
    fPoints.push_back(aPoint);                                                  // (4)
}

void Point2DSet::add( Point2D&& aPoint )
{
    fPoints.push_back( std::move(aPoint) );                                     // (6)
}

void Point2DSet::removeLast()
{
    fPoints.pop_back();                                                         // (2)
}

bool Point2DSet::doesNotTurnLeft( const Point2D& aPoint ) const
{
    if ( size() < 2 )                                                           // 4
    {
        throw domain_error( "Insufficient data points." );                      // 4
    }

    const Point2D& p0 = fPoints[size() - 2];                                    // 6
    const Point2D& p1 = fPoints[size() - 1];                                    // 6

//    return p1.isClockwise( p0, aPoint );                                      // 6(26)

    // bug fix: check if not counterclockwise
    return !p1.isCounterClockwise( p0, aPoint );
}

void Point2DSet::populate( const std::string& aFileName )
{
    ifstream lInFile( aFileName );                                              // 4

    if ( lInFile )  // testing status                                           // 2
    {
        size_t lCount;                                                          // 2

        lInFile >> lCount;                                                      // 2

        while ( lCount-- )                                                      // 4
        {
            add( Point2D( lInFile ) );                                          // 6(20)
        }
    }
}

void Point2DSet::buildConvexHull( Point2DSet& aConvexHull )
{
    // empty result set
    aConvexHull.clear();                                                        // 2

    // If |Q| < 3 then CH consists of just those points. (optional)
    if ( size() < 3 )                                                           // 4
    {
        for ( size_t i = 0; i < size(); i++ )                                   // 4
        {
            aConvexHull.add( fPoints[i] );                                      // 4
        }

        return;                                                                 // 2
    }
    
    // sort by coordinates
    sort( orderByCoordinates );                                                 // 4
    
    const Point2D& lNewOrigin = fPoints[0];                                     // 2

    for ( size_t i = 0; i < fPoints.size(); i++ )                               // 6
    {
        fPoints[i].setOrigin( lNewOrigin );                                     // 4
    }

    // sort by polar angle
    sort( orderByPolarAngle );                                                  // 4

    // build convex hull
    
    aConvexHull.add( fPoints[0] ); // p0                                        // 3
    aConvexHull.add( fPoints[1] ); // p1                                        // 3

    // add p2 if not collinear
    if ( !fPoints[2].isCollinear( fPoints[1] ) )                                // 8
    {
        aConvexHull.add( fPoints[2] );                                          // 3
    }

    for ( size_t i = 3; i < size(); i++ )                                       // 8
    {
        const Point2D& pi = fPoints[i];                                         // 4

        // skip collinear points
        if ( fPoints[i-1].isCollinear( pi ) )                                   // 6
        {
            continue;                                                           // 2
        }

        while ( aConvexHull.doesNotTurnLeft( pi ) )                             // 6
        {
            aConvexHull.removeLast();                                           // 4
        }

        aConvexHull.add( pi );                                                  // 3(86)
    }
}

size_t Point2DSet::size() const
{
    return fPoints.size();                                                      // (3)
}

void Point2DSet::clear()
{
    fPoints.clear();                                                            // (3)
}

void Point2DSet::sort( Comparator aComparator )
{
    stable_sort( fPoints.begin(), fPoints.end(), aComparator );                 // (6)
}

const Point2D& Point2DSet::operator[]( size_t aIndex ) const
{
    return fPoints[aIndex];                                                     // (4)
}

Point2DSet::Iterator Point2DSet::begin() const
{
    return fPoints.begin();                                                     // (4)
}

Point2DSet::Iterator Point2DSet::end() const
{
    return fPoints.end();                                                       // (4)
}                                                                               // = (194)

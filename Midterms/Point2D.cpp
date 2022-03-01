/*

   Point2D, COS30008, 2021

*/

#include "Point2D.h"

#include <cmath>                                                                // (2)

using namespace std;

static const Point2D gCoordinateOrigin;                                         // (4)

double Point2D::directionTo( const Point2D& aOther ) const
{
    return (aOther.fPosition - fPosition).direction();                          // (6)
}

double Point2D::magnitudeTo( const Point2D& aOther ) const
{
    return (aOther.fPosition - fPosition).magnitude();                          // (6)
}

Point2D::Point2D() :
    fId( "" ),
    fPosition( 0.0, 0.0 ),
    fOrigin( &gCoordinateOrigin )                                               // (8)
{}

Point2D::Point2D( const std::string& aId, double aX, double aY ) :
    fId( aId ),
    fPosition( aX, aY ),
    fOrigin( &gCoordinateOrigin )                                               // (8)
{}

Point2D::Point2D( std::istream& aIStream ) :
    fOrigin( &gCoordinateOrigin )                                               // 2
{
    aIStream >> fId >> fPosition;                                               // 4(6)
}

const string& Point2D::getId() const
{
    return fId;                                                                 // (2)
}

void Point2D::setX( const double& aX )
{
    fPosition.setX( aX );                                                       // (3)
}

const double Point2D::getX() const
{
    return fPosition.getX();                                                    // (3)
}

void Point2D::setY( const double& aY )
{
    fPosition.setY( aY );                                                       // (3)
}

const double Point2D::getY() const
{
    return fPosition.getY();                                                    // (3)
}

void Point2D::setOrigin( const Point2D& aPoint )
{
    fOrigin = &aPoint;                                                          // (3)
}

const Point2D& Point2D::getOrigin() const
{
    return *fOrigin;                                                            // (3)
}

Vector2D Point2D::operator-( const Point2D& aRHS ) const
{
    return fPosition - aRHS.fPosition;                                          // (4)
}

double Point2D::direction() const
{
    // vector from origin to point
    return fOrigin->directionTo( *this );                                       // (6)
}

double Point2D::magnitude() const
{
    // vector from origin to point
    return fOrigin->magnitudeTo( *this );                                       // (6)
}

bool Point2D::isCollinear( const Point2D& aOther ) const
{
    return fabs( direction() - aOther.direction() ) < 0.0001;                   // (8)
}

bool Point2D::isClockwise( const Point2D& aP0, const Point2D& aP2 ) const
{
    Vector2D p0p1 = (*this) - aP0;                                              // 4
    Vector2D p0p2 = aP2 - aP0;                                                  // 4

    return p0p2.cross( p0p1 ) > 0.0;                                            // 6(14)
}

// bug fix: we need to check counterclockwise
bool Point2D::isCounterClockwise( const Point2D& aP0, const Point2D& aP2 ) const
{
    Vector2D p0p1 = (*this) - aP0;
    Vector2D p0p2 = aP2 - aP0;
    
    return p0p2.cross( p0p1 ) < 0.0;
}

bool Point2D::operator<( const Point2D& aRHS ) const
{
    // leftmost Point2D (tie)
    if ( fabs( getY() - aRHS.getY() ) < 0.0001 )                                // 8
    {
        return getX() < aRHS.getX();                                            // 4
    }
    
    // minimum y-coordinate
    return getY() < aRHS.getY();                                                // 4(16)
}

ostream& operator<<( std::ostream& aOStream, const Point2D& aObject )
{
    return aOStream
            << aObject.getId() << ": (" 
            << aObject.getX() << "," 
            << aObject.getY() << ")";                                           // (10)
}

istream& operator>>( std::istream& aIStream, Point2D& aObject )
{
    aIStream >> aObject.fId >> aObject.fPosition;                               // 12
    
    return aIStream;                                                            // 2(14)
}
                                                                                // = (138)

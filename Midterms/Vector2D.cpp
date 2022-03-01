/*

   2D Vectors, COS30008, 2021

*/

#include "Vector2D.h"

#include <cmath>                                                        // (2)

using namespace std;

Vector2D::Vector2D( double aX, double aY ) :
    fX( aX ),
    fY( aY )                                                            // (4)
{}

void Vector2D::setX( double aX )
{
    fX = aX;                                                            // (2)
}

double Vector2D::getX() const
{
    return fX;                                                          // (2)
}

void Vector2D::setY( double aY )
{
    fY = aY;                                                            // (2)
}

double Vector2D::getY() const
{
    return fY;                                                          // (2)
}

Vector2D Vector2D::operator+( const Vector2D& aRHS ) const
{
    return Vector2D( fX + aRHS.fX, fY + aRHS.fY );                      // (8)
}

Vector2D Vector2D::operator-( const Vector2D& aRHS ) const
{
    return Vector2D( fX - aRHS.fX, fY - aRHS.fY );                      // (8)
}

double Vector2D::magnitude() const
{
    // sqrt( x*x + y*y )
    return sqrt( fX*fX + fY*fY );                                       // (8)
}

double Vector2D::direction() const
{
    // tan a = opposite / adjacent
    return atan2( fY, fX );                                             // (6)
}

double Vector2D::dot( const Vector2D& aRHS ) const
{
    // [x1 y1] . [x2 y2] = sum (x1 * x2, y1 * y2)
    return fX * aRHS.fX + fY * aRHS.fY;                                 // (8)
}

double Vector2D::cross( const Vector2D& aRHS ) const
{
    /*
        The crossproduct is the determinate of the matrix

            | x1 x2 |
        det |       | = x1*y2 - x2*y1
            | y1 y2 |
    */

    return fX * aRHS.fY - aRHS.fX * fY;                                 // (6)
}

// test function
double Vector2D::angleBetween( const Vector2D& aRHS ) const
{
    double denominator = magnitude() * aRHS.magnitude();                // 4

    // both 2D vectors != [0,0]
    if ( denominator > 0.0 )                                            // 4
    {
        return acos( dot( aRHS ) / denominator );                       // 6
    }
    else
        // pi/2 as dot product is 0
        return 2 * atan( 1.0 );                                         // 6(20)
}

ostream& operator<<( ostream& aOutStream, const Vector2D& aObject )
{
    return aOutStream 
        << '[' << aObject.fX << " " << aObject.fY << ']';               // (8)
}

istream& operator>>( istream& aInStream, Vector2D& aObject )
{
    return aInStream >> aObject.fX >> aObject.fY;                       // (6)
}

                                                                        // = (92)

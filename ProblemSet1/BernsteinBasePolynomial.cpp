
// COS30008, Problem Set 1/3, 2021

#include "BernsteinBasePolynomial.h"

#include <cmath>

using namespace std;

BernsteinBasePolynomial::BernsteinBasePolynomial() :
    fFactor(0,0)                                                        // (2)
{}

BernsteinBasePolynomial::BernsteinBasePolynomial( unsigned int aV, unsigned int aN ) :
    fFactor(aN, aV)                                                     // (4)
{}

double BernsteinBasePolynomial::operator()( double aX ) const
{
    double Result = fFactor() * pow( aX, fFactor.getK() );              // 7
    
    return Result * pow( 1 - aX, fFactor.getN() - fFactor.getK() );     // 9(16)
}                                                                       // 2+4+16 = 22

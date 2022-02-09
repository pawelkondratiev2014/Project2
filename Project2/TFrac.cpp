#include <iostream>
#include <string>
#include <cassert>
#include "TFrac.h"



bool operator> (const TFrac& d1, const TFrac& d2)
{
    return (d1.numerator * d2.denominator) > (d2.numerator * d1.denominator);
};

bool operator< (const TFrac& d1, const TFrac& d2)
{
    return (d1.numerator * d2.denominator) < (d2.numerator * d1.denominator);
};



std::ostream& operator<< (std::ostream& out, const TFrac& d)
{
    out << d.numerator << "/" << d.denominator;
    return out;
};

TFrac operator+(const TFrac& d1, const TFrac& d2)
{
    double numerator = d1.numerator * d2.denominator + d2.numerator * d1.denominator;
    double denominator = d1.denominator * d2.denominator;

    return TFrac(numerator, denominator);
};


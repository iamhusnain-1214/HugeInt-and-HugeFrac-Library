#pragma once
#include "BSAI25005-HugeInteger.h"
#include <iostream>
using namespace std;

class HugeFraction
{
private:
    HugeInteger numerator;
    HugeInteger denominator;

    void reduce();
    HugeInteger gcd(HugeInteger a, HugeInteger b);

public:
    HugeFraction();
    HugeFraction(const HugeInteger& n, const HugeInteger& d);
    void fromDecimalString(const string& s);
    HugeFraction operator+(const HugeFraction& F) const;
    HugeFraction operator-(const HugeFraction& F) const;
    HugeFraction operator*(const HugeFraction& F) const;
    HugeFraction operator/(const HugeFraction& F) const;
    HugeFraction& operator+=(const HugeFraction& F);
    HugeFraction& operator-=(const HugeFraction& F);
    HugeFraction& operator*=(const HugeFraction& F);
    HugeFraction& operator/=(const HugeFraction& F);
    bool operator<(const HugeFraction& F) const;
    bool operator>(const HugeFraction& F) const;
    bool operator<=(const HugeFraction& F) const;
    bool operator>=(const HugeFraction& F) const;
    bool operator==(const HugeFraction& F) const;
    bool operator!=(const HugeFraction& F) const;

    HugeFraction operator-() const;

    HugeFraction& operator=(const HugeFraction& F);

    friend ostream& operator<<(ostream& out, const HugeFraction& F);
    friend istream& operator>>(istream& in, HugeFraction& F);
};
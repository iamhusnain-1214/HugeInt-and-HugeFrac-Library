#include "BSAI25005-HugeFraction.h"
HugeFraction::HugeFraction()
{
	numerator = HugeInteger::Zero();
	denominator = HugeInteger::One();	
}
HugeFraction::HugeFraction(const HugeInteger& n, const HugeInteger& d)
{
	if (d == HugeInteger::Zero())
	{
		throw("Divison by zero...!");
	}
	numerator = n;
	denominator = d;

	reduce();
}
HugeInteger HugeFraction::gcd(HugeInteger a, HugeInteger b)
{
	while (!(b == HugeInteger::Zero()))
	{
		HugeInteger r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void HugeFraction::reduce()
{
	HugeInteger g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
	if (denominator < HugeInteger::Zero())
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}
HugeFraction HugeFraction::operator+(const HugeFraction& F) const
{
	HugeInteger n = numerator * F.denominator + denominator * F.numerator;
	HugeInteger d = denominator * F.denominator;
	return HugeFraction(n, d);
}
HugeFraction HugeFraction::operator-(const HugeFraction& F) const
{
	HugeInteger n =
		numerator * F.denominator -
		F.numerator * denominator;
	HugeInteger d =
		denominator * F.denominator;
	return HugeFraction(n, d);
}
HugeFraction HugeFraction ::operator*(const HugeFraction& F) const
{

	HugeInteger n = numerator *F.numerator;
	HugeInteger d = denominator * F.denominator;
	return HugeFraction(n, d);
}
HugeFraction HugeFraction::operator/(const HugeFraction& F) const
{
	HugeInteger n = numerator * F.denominator;
	HugeInteger d = denominator * F.numerator;
	return HugeFraction(n, d);
}
HugeFraction& HugeFraction::operator+=(const HugeFraction& F)
{
	*this = *this + F;
	return *this;
}
HugeFraction& HugeFraction::operator-=(const HugeFraction& F)
{
	*this = *this - F;
	return *this;
}
HugeFraction& HugeFraction::operator*=(const HugeFraction& F)
{
	*this = *this * F;
	return *this;
}
HugeFraction& HugeFraction::operator/=(const HugeFraction& F)
{
	*this = *this / F;
	return *this;
}
bool HugeFraction::operator<(const HugeFraction& F) const
{
	return numerator * F.denominator <
		F.numerator * denominator;
}
bool HugeFraction::operator>(const HugeFraction& F) const
{
	return F < *this;
}
bool HugeFraction::operator<=(const HugeFraction& F) const
{
	return !( *this>F);
}
bool HugeFraction::operator>=(const HugeFraction& F) const
{
	return !(*this < F);
}
bool HugeFraction::operator==(const HugeFraction& F) const
{
	return numerator == F.numerator and denominator == F.denominator;
}
bool HugeFraction::operator!=(const HugeFraction& F) const
{
	return !(*this == F);
}
HugeFraction HugeFraction::operator-() const
{
	HugeFraction temp = *this;
	temp.numerator = -temp.numerator;
	return temp;
}
HugeFraction& HugeFraction::operator=(const HugeFraction& F)
{
	if (this != &F)
	{
		numerator = F.numerator;
		denominator = F.denominator;
	}
	return *this;
}
ostream& operator<<(ostream& out, const HugeFraction& F)
{
	out << F.numerator << "/" << F.denominator;
	return out;
}

void HugeFraction::fromDecimalString(const string& s)
{
	int dot = s.find('.');
	int lp = s.find('(');
	int rp = s.find(')');
	if (dot == string::npos)
	{
		numerator.assignString(s);
		denominator = HugeInteger::One();
		return;
	}
	string intPart = s.substr(0, dot);
	if (lp == string::npos)
	{
		string frac = s.substr(dot + 1);

		string numStr = intPart + frac;

		numerator.assignString(numStr);

		denominator = HugeInteger::One();

		HugeInteger ten;
		ten.assignString("10");

		for (int i = 0; i < frac.size(); i++)
			denominator *= ten;

		reduce();
		return;
	}
	string nonRepeat = s.substr(dot + 1, lp - dot - 1);
	string repeat = s.substr(lp + 1, rp - lp - 1);

	int k = nonRepeat.length();
	int r = repeat.length();

	string A = nonRepeat;
	string B = repeat;

	string AB = A + B;

	HugeInteger part1, part2;

	part1.assignString(intPart + AB);
	part2.assignString(intPart + A);

	numerator = part1 - part2;

	HugeInteger ten;
	ten.assignString("10");
	HugeInteger pow1 = HugeInteger::One();
	HugeInteger pow2 = HugeInteger::One();

	for (int i = 0; i < k + r; i++)
		pow1 *= ten;

	for (int i = 0; i < k; i++)
		pow2 *= ten;
	denominator = pow1 - pow2;

	reduce();
}
istream& operator>>(istream& in, HugeFraction& F)
{
	string s;
	in >> s;
	int slash = s.find('/');
	int dot = s.find('.');
	if (slash != string::npos)
	{
		string num = s.substr(0, slash);
		string den = s.substr(slash + 1);

		F.numerator.assignString(num);
		F.denominator.assignString(den);

		if (F.denominator == HugeInteger::Zero())
			throw("Division by zero!");

		F.reduce();
	}
	else if (dot != string::npos)
	{
		F.fromDecimalString(s);
	}
	else
	{
		F.numerator.assignString(s);
		F.denominator = HugeInteger::One();
	}

	return in;
}
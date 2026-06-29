#include "BSAI25005-HugeInteger.h"
#include<iostream>
#include<fstream>
using namespace std;
void HugeInteger::trim()
{
	while (Ds.size() > 1 and Ds.back() == 0)
	{
		Ds.pop_back();
	}
}
void HugeInteger:: assignString(string s)
{
	isNeg = false;
	if (s[0] == '-')
	{
		isNeg = true;
		s=s.substr(1);
	}
	else if (s[0] == '+')
	{
		s = s.substr(1);
	}
	for (int i = s.length() - 1; i >= 0; i--)
	{
		Ds.push_back(s[i] - '0');
	}
	trim();
	if (Ds.size() == 1 and Ds[0] == 0)
		isNeg = false;
}
HugeInteger::HugeInteger(int size) {
	if (size <= 0)
		size = 1;
	Ds.resize(size, 0);
	isNeg = false;
}
HugeInteger::HugeInteger(ifstream& rdr)
{
	string s;
	rdr >> s;
	if (!rdr)
	{
		cout << "file not found...!";
		exit(1);
	}
	assignString(s);
}
bool HugeInteger::GreaterThanQuantityWise(const HugeInteger& H2) const
{
	if (Ds.size() > H2.Ds.size())
	{
		return true;
	}
	if (Ds.size() < H2.Ds.size())
	{
		return false;
	}
	for (int i = Ds.size() - 1; i >= 0; i--)
	{
		if (Ds[i] > H2.Ds[i])
		{
			return true;
		}
		if (Ds[i] < H2.Ds[i])
		{
			return false;
		}
	}
	return false;
}
bool HugeInteger::LessThanQuantityWise(const HugeInteger& H2) const
{
	return H2.GreaterThanQuantityWise(*this);
}
bool HugeInteger:: EqualQuantityWise(const HugeInteger& H2) const
{
	return !GreaterThanQuantityWise(H2) and !LessThanQuantityWise(H2);
}
int& HugeInteger::operator[] (int i)
{
	if (i >= Ds.size())
		throw("Out of bounds...access");
	return Ds[i];
}
 int HugeInteger::operator[] (int i)const
{
	if (i >= Ds.size())
		return 0;
	return Ds[i];
}

HugeInteger HugeInteger::ADDQuantityWise(const HugeInteger& H2) const{

	int maxSize = max(Ds.size(), H2.Ds.size());
	HugeInteger result(maxSize+1);
	int carry = 0;
	for (int i = 0; i < maxSize; i++)
	{
		int d1 = (*this)[i];
		int d2 = H2[i];
		int sum = d1 + d2 + carry;
		result[i] = sum % 10;
		carry = sum / 10;
	}
	if (carry)
	{
		result[maxSize] = carry;
	}
	result.trim();
	return result;
}
HugeInteger HugeInteger::SUBQuantityWise(const HugeInteger& H2) const{


	HugeInteger result(Ds.size() + 1);
	int borrow = 0;
	for (int i = 0; i < Ds.size(); i++)
	{
		int d1 = (*this)[i];
		int d2 = H2[i];
		int diff = d1 - d2 - borrow;
		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		result[i] = diff;
	}
	
	result.trim();
	return result;
}
ostream& operator<<(ostream& out, const HugeInteger& H)
{
	if (H.isNeg and !(H.Ds.size() == 1 && H.Ds[0] == 0))
		out << "-";

	for (int i = H.Ds.size() - 1; i >= 0; i--)
		out << H.Ds[i];

	return out;
}
istream& operator>>(istream& in, HugeInteger& H)
{
	string s;
	in >> s;
	H.assignString(s);
	return in;
}
HugeInteger HugeInteger::operator+(const HugeInteger& H2) const
{
	HugeInteger R;
	if (isNeg == H2.isNeg)
	{
		R=ADDQuantityWise(H2);
		R.isNeg = isNeg;
	}
	else
	{
		if (GreaterThanQuantityWise(H2))
		{
			R = SUBQuantityWise(H2);
			R.isNeg = isNeg;
		}
		else if(LessThanQuantityWise(H2))
		{
			R = SUBQuantityWise(*this);
			R.isNeg = H2.isNeg;
		}
		else
		{
			R = HugeInteger(1);
			R[0] = 0;
			R.isNeg = false;
		}

	}
	return R;
}
HugeInteger& HugeInteger::operator+=(const HugeInteger& H2)
{
	*this = *this + H2;
	return *this;
}
HugeInteger HugeInteger::operator-() const
{
	HugeInteger temp = *this;
	if (!(Ds.size() == 1 and Ds[0] == 0))
	{
		temp.isNeg = !isNeg;
	}
	return temp;
}
HugeInteger HugeInteger::operator-(const HugeInteger& H2) const
{
	return *this + (-H2);
}
HugeInteger& HugeInteger::operator=(const HugeInteger& H2)
{
	if (this != &H2)
	{
		Ds = H2.Ds;
		isNeg = H2.isNeg;
	}
	return *this;
}
HugeInteger& HugeInteger::operator-=(const HugeInteger& H2)
{
	*this = *this - H2;
	return *this;
}
HugeInteger& HugeInteger::operator++()
{
	HugeInteger one;
	one.Ds = { 1 };
	*this += one;
	return *this;
}
HugeInteger HugeInteger::operator++(int)
{
	HugeInteger temp = *this;
	++(*this);
	return temp;
}
HugeInteger& HugeInteger::operator--()
{
	HugeInteger one;
	one.Ds = { 1 };
	*this -= one;
	return *this;
}
HugeInteger HugeInteger::operator--(int)
{
	HugeInteger temp = *this;
	--(*this);
	return temp;
}
bool HugeInteger::operator<(const HugeInteger& H2) const
{
	if (isNeg != H2.isNeg)
		return isNeg;

	if (!isNeg)
		return LessThanQuantityWise(H2);
	else
		return H2.LessThanQuantityWise(*this);
}
bool HugeInteger::operator>(const HugeInteger& H2) const
{
	return H2 < *this;
}
bool HugeInteger::operator<=(const HugeInteger& H2) const
{
	return !(*this > H2);
}
bool HugeInteger::operator>=(const HugeInteger& H2) const
{
	return !(*this < H2);
}
bool HugeInteger::operator==(const HugeInteger& H2) const
{
	return isNeg == H2.isNeg and EqualQuantityWise(H2);
}
HugeInteger HugeInteger:: Zero()
{
	HugeInteger z(1);
	z.Ds[0] = 0;
	z.isNeg = false;
	return z;
}
HugeInteger HugeInteger:: One()
{
	HugeInteger z(1);
	z.Ds[0] = 1;
	z.isNeg = false;
	return z;
}
HugeInteger HugeInteger::operator*(const HugeInteger& H2) const 
{
	bool sign = (this->isNeg != H2.isNeg);
	HugeInteger a = *this; a.isNeg = false;
	HugeInteger b = H2; b.isNeg = false;
	HugeInteger Total =Zero();
	while (!(b == Zero())) {
		HugeInteger r = a;
		HugeInteger c=One();
		while ((c + c) <= b) {
			r += r;
			c += c;
		}
		b -= c;
		Total += r;
	}
	Total.isNeg = sign;
	Total.trim();
	return Total;
}
void HugeInteger::div(HugeInteger dividend, HugeInteger divisor, HugeInteger& quotient, HugeInteger& remainder) const {
	if (divisor == Zero()) {
		cout << "Error: Division by zero!" << endl;
		return;
	}
	bool qNeg = (dividend.isNeg != divisor.isNeg);
	dividend.isNeg = false;
	divisor.isNeg = false;

	if (dividend < divisor) {
		quotient = Zero();
		remainder = dividend;
		return;
	}
	quotient = Zero();
	remainder = dividend;
	while (remainder >= divisor) {
		HugeInteger td = divisor;
		HugeInteger tq=One();
		tq[0] = 1;
		while (remainder >= (td + td)) {
			td += td;
			tq += tq;
		}
		remainder -= td;
		quotient += tq;
	}
	quotient.isNeg = qNeg;
	remainder.isNeg = this->isNeg;
	quotient.trim();
	remainder.trim();
}
HugeInteger HugeInteger::operator/(const HugeInteger& divisor) const {
	HugeInteger q, r;
	div(*this, divisor, q, r);
	return q;
}
HugeInteger HugeInteger:: operator%(const HugeInteger& divisor) const {
	HugeInteger q, r;
	div(*this, divisor, q, r);
	return r;
}
HugeInteger& HugeInteger::operator/=(const HugeInteger& divisor) {
	*this = *this / divisor;
	return *this;
}
HugeInteger& HugeInteger:: operator%=(const HugeInteger& divisor) {
	*this = *this % divisor;
	return *this;
}
HugeInteger& HugeInteger:: operator*=(const HugeInteger& H2)
{
	*this =*this * H2;
	return *this;
}
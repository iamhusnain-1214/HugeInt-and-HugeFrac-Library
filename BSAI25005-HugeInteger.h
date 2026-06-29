#pragma once
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;
class HugeInteger
{
private:
	bool isNeg;
	vector<int>Ds;
	void trim();
	void div(HugeInteger dividend, HugeInteger divisor, HugeInteger& quotient, HugeInteger& remainder)const;
	public:
		void assignString(string s);

	HugeInteger(int size = 0);
	HugeInteger(ifstream& rdr);
	HugeInteger ADDQuantityWise(const HugeInteger& H2) const;
	HugeInteger SUBQuantityWise(const HugeInteger& H2) const;
	bool LessThanQuantityWise(const HugeInteger& H2) const;
	bool GreaterThanQuantityWise(const HugeInteger& H2) const;
	bool EqualQuantityWise(const HugeInteger& H2) const;
	static HugeInteger Zero();
	static HugeInteger One();
	int& operator[] (int i);
	int operator[] (int i)const;
	friend ostream& operator<<(ostream& out, const HugeInteger& H);
	friend istream& operator>>(istream& in, HugeInteger& H);
	HugeInteger operator+(const HugeInteger& H2) const;
	HugeInteger operator-(const HugeInteger& H2) const;
	HugeInteger operator*(const HugeInteger& H2) const;
	HugeInteger operator/(const HugeInteger& H2) const;
	HugeInteger operator%(const HugeInteger& H2) const;
	HugeInteger& operator-=(const HugeInteger& H2);
	HugeInteger& operator/=(const HugeInteger& H2);
	HugeInteger& operator%=(const HugeInteger& H2);
	HugeInteger& operator*=(const HugeInteger& H2);
	HugeInteger& operator+=(const HugeInteger& H2);
	HugeInteger operator-() const;
	HugeInteger& operator=(const HugeInteger& H2);
	HugeInteger& operator++();
	HugeInteger operator++(int);
	HugeInteger& operator--();
	HugeInteger operator--(int);
	bool operator<(const HugeInteger& H2) const;
	bool operator>(const HugeInteger& H2) const;
	bool operator>=(const HugeInteger& H2) const;
	bool operator<=(const HugeInteger& H2) const;
	bool operator==(const HugeInteger& H2) const;
};


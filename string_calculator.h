#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class BigUnsignedInt {
string number; // Do not change the data type.
int size; // the actual length of the number
public:
//Constructors:
BigUnsignedInt();
BigUnsignedInt(const string&);
int getSize(); // return the length of number
string getNumber(); //returning the actual number
//Addition and Subtraction
BigUnsignedInt operator+(const BigUnsignedInt&); //addition
BigUnsignedInt operator-(const BigUnsignedInt&); //subtraction
BigUnsignedInt& operator=(const BigUnsignedInt& rightSide); // operator =
BigUnsignedInt operator*(const BigUnsignedInt&); //multiplication


};
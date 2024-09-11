#include "string_calculator.h"
using namespace std;

BigUnsignedInt::BigUnsignedInt() : number("0"), size(0) {} // Initialize members
BigUnsignedInt::BigUnsignedInt(const string& input)
{
    number = input;
    size = input.length();
}


int BigUnsignedInt::getSize()
{
    return number.length();
}

string BigUnsignedInt::getNumber()
{
    return number;
}


BigUnsignedInt BigUnsignedInt::operator+(const BigUnsignedInt& rightInt)
{
    //reversing strings so we start from the right
    string int1 = number;
    reverse(int1.begin(), int1.end());

    string int2 = rightInt.number;
    reverse(int2.begin(), int2.end());
    
    //finding out which number is longer
    int maxLength = max(int1.size(), int2.size());

    //variable setup for adding - final result and the carry over digit
    string result;
    int carryOver = 0;

    //main addition loop
    for (int i = 0; i < maxLength; i++)
    {
        //twp digits we are adding, but we need to make sure there are actually digits present. 
        int digit1 = (i < int1.size()) ? int1[i] - '0' : 0;
        int digit2 = (i < int2.size()) ? int2[i] - '0' : 0;

        //adding them plus the carry (if present) and calculating new carry over
        int sum = digit1 + digit2 + carryOver;
        carryOver = sum / 10;
        
        //adding on new added digit
        result.push_back(sum % 10 + '0');
    }

    //reversing again to obtain a correctly ordered result
    reverse(result.begin(), result.end());

    //returning result
    BigUnsignedInt temp(result);
    return temp;

}

BigUnsignedInt BigUnsignedInt::operator-(const BigUnsignedInt& rightInt)
{
    //similar to addition we reverse the numbers to start on the right
    string int1 = number;
    reverse(int1.begin(), int1.end());

    string int2 = rightInt.number;
    reverse(int2.begin(), int2.end());
    
    //finding which number is longer
    int maxLength = max(size, rightInt.size);

    //setting up borrow and result variable
    string result;
    int borrow = 0;

    //main subtraction loop
    for (int i = 0; i < maxLength; i++)
    {
        //getting the two digits we are subtracting - similar to addition, if the 
        //number has no digits left we just use a placeholding 0
        int digit1 = (i < size) ? int1[i] - '0' : 0;
        int digit2 = (i < rightInt.size) ? int2[i] - '0' : 0;

        //subtracting 
        int diff = digit1 - digit2 - borrow;
        
        //if the diff is negative then we need to borrow 10 from the next place over
        if(diff < 0)
        {
            diff += 10;
            borrow = 1;
        }else{
            borrow = 0;
        }
        
        //pushing back results
        result.push_back(diff + '0');
    }
    //reversing final result to put it back in order
    reverse(result.begin(), result.end());

    //returning result
    BigUnsignedInt temp(result);
    return temp;
}

BigUnsignedInt BigUnsignedInt::operator*(const BigUnsignedInt& rightSide)
{
    string int1 = number;
    reverse(int1.begin(), int1.end());

    string int2 = rightSide.number;
    reverse(int2.begin(), int2.end());

    vector <int> result(int1.size() + int2.size(), 0);
    vector<string> multiplcationSteps;

    for (int i = 0; i < int1.size(); i++)
    {
        int carry(0);
        int digit1 = int1[i] - '0';
        for (int j = 0; j < int2.size(); j++)
        {
            int digit2 = int2[j] - '0';
            int sum = result[i+j]+digit1*digit2+carry;
            carry = sum / 10;
            result[i+j] = sum % 10;
        }
        if (carry > 0) {
            result[i + int2.size()] += carry;
        }

    }
    
    string resultStr;
    bool leadingZero = true;

    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] == 0 && leadingZero) {
            continue;  // Skip leading zeroes
        }
        leadingZero = false;
        resultStr.push_back(result[i] + '0');
    }

    BigUnsignedInt temp(resultStr);
    return temp;


}

BigUnsignedInt& BigUnsignedInt::operator=(const BigUnsignedInt& rightSide)
{
    //assignment operator
    number = rightSide.number;
    size = rightSide.size;
    return *this;
}


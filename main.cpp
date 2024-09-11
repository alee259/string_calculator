#include "string_calculator.cpp"
#include <fstream>
using namespace std;

int main()
{   
    //file reading information
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream infile;

    infile.open(filename); //opening filestream
    if (infile.fail()) //make sure file opens successfully
    {   
        cout << "Input file 1 opening failed." << endl; //error message
        exit(1);
    }

    //taking in the integers we want to operate on
    string big1, big2;

    infile >> big1 >> big2;

    BigUnsignedInt int1(big1);
    BigUnsignedInt int2(big2);

    BigUnsignedInt add = int1+int2;
    BigUnsignedInt sub = int1-int2;
    BigUnsignedInt mult = int1 * int2;
    cout << "Original 1: " << big1 << endl;
    cout << "Original 2: " << big2 << endl;
    cout << "Addition: " << add.getNumber() << endl;
    cout << "Subtraction: " << sub.getNumber() << endl;
    cout << "Multiplication: " << mult.getNumber() << endl;


}
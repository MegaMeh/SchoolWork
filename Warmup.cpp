//Eric Peasley
//CSCI 238
//26 Jan 2022
//Program - Warmup
//
//Grade Version - N/A
//sum wont go higher than 161
//Will not read in numbers longer than 10 digits


#include <iostream>
#include <cmath>
using namespace std;

//checks for curzons and returns true or false
bool isCurzon(int input)
{
    bool curzon = false;
    int exponent = pow(2, input) + 1;
    int multiplied = 2 * input + 1;
    if (exponent % multiplied == 0)
    {
        curzon = true;
    }
    return curzon;
}

int main()
{
    while (true)
    {
        int input;
        cin >> input;
        if (input < 0)
        {
            cout << "Input not Valid." << endl;
        }else if(input > 0){
            int curzonSum = 0;
            while (input >= 0)
            {
                if(isCurzon(input))
                {
                    curzonSum = curzonSum + input;
                }
                input --;
            }
            cout << curzonSum << endl;
            cout << endl;
        }else{
            return 0;
        }
    }
}


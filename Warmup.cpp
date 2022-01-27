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
#include <chrono>
using namespace std;


using milliseconds = std::chrono::duration<int64_t, std::ratio<1, 1'000>>;
inline uint64_t NowAsTimestamp()
{
    return std::chrono::duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

//checks for curzons and returns true or false
bool isCurzon(int input)
{
    bool curzon = false;
    uint64_t exponent = powl(2, input) + 1;
    uint64_t multiplied = 2 * input + 1;
    if (exponent % multiplied == 0)
    {
        curzon = true;
    }

    return curzon;
}

bool isCurzonFast(int input)
{
    uint64_t exponent = (static_cast<uint64_t>(1) << input) | 1;   
    return !(exponent % ((input << 1) | 1));
}

int main()
{
    for(int i = 0; i <= 63; i++)
    {
        printf("%d agrees %d\n", i, isCurzonFast(i) == isCurzon(i));
    }

    uint64_t start = NowAsTimestamp();
    for(int iterations = 0; iterations < 1000000; iterations++)
    {
        for(int i = 0; i < 63; i++)
        {
            isCurzonFast(i);
        }
    }

    uint64_t end = NowAsTimestamp();
    uint64_t fastRunTime = (end - start);
    std::cout << "Fast run time = " << fastRunTime << std::endl;

    start = NowAsTimestamp();
    for(int iterations = 0; iterations < 1000000; iterations++)
    {
        for(int i = 0; i < 63; i++)
        {
            isCurzon(i);
        }
    }

    end = NowAsTimestamp();
    uint64_t naiveRunTime = (end - start);
    std::cout << "Naive run time = " << naiveRunTime << std::endl;
    std::cout << "Runs " << (float)naiveRunTime / (float)fastRunTime << " faster" << std::endl;

    /*
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
    */
}


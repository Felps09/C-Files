//Lab 0
//Monte Carlo simulation
//By Felipe Prudencio

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //maybe it is 50% + 12.5%; = 62.5%
    float x,y,percent;
    int count;

    float LO = -1.0;
    float HI = 1.0;

    //x = ((rand() % 10 / RAND_MAX) * 2) - 1;

    for (int i = 0; i <=1000; i++)
    {
    x = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
    y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));

        if (y < -x + 1)
        {
            count++;
        }
    }

    percent = (count * 100) / 1000;

    cout << "Probability is: " << percent << "%" << endl;
    
    
     return 0;
}

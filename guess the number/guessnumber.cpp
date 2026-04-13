#include <iostream>
#include <ctime>
using namespace std;
int main(){
    int randomnumber, attemptsleft=10, n, win=0;
    srand(time(0));
    randomnumber=rand() % 100 + 1;
    
    cout<<"Guess the Number"<<endl;

    while (win==0)
    { cin>>n;
    if (n<randomnumber)
    {cout<<"the number is higher"<<endl;
    attemptsleft--;}

    if (n>randomnumber)
    {cout<<"the number is lower"<<endl;
    attemptsleft--;}
    
    else if (n==randomnumber)
    {cout<<"You won!"<<endl;
    win=1;
    }

    if (attemptsleft==0)
    {cout<<"you lost :(";
    win=1;
    }
    }
    return 0;


    
}
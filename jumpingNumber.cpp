#include <iostream>

using namespace std;

#define MAX_NUMS    50

bool isJumpingNumber(unsigned int num) {
    unsigned int digit1 = 0, digit2 = 0;
    
    while (num >= 10) {
        digit1 = num%10;
        digit2 = (num/10)%10;
        int diff = digit1-digit2;
        if(diff != 1 || diff != -1)
            return false;
        
        num = num/10;
    }
    
    return true;
}

int main() {
	//code
	
	unsigned int numInput=0, allNums[MAX_NUMS];
	cin >> numInput;
	
	for(int i=0; i<numInput; i++)
	{
	    cin >> allNums[i];
	}

    for(int i=0; i<numInput; i++)
    {
        unsigned int num = allNums[i];
        for(int j=0; j<num; j++)
            if(isJumpingNumber(num))
                cout << num << " ";
        cout << endl;
    }
    
	return 0;
}
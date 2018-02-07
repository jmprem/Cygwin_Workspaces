#include <stdio.h>
#include <limits.h>

int main() {
	//code
	int inputCount=0, inputData=0, bitCount=0, totalBits=sizeof(int)*CHAR_BIT;
	
	scanf("%d", &inputCount);
    
	while(inputCount > 0) {
	    scanf("%d", &inputData);
	    bitCount = 0;
	    while(bitCount < totalBits && !((inputData>>bitCount++)&0x01));
	    printf("%d\n", bitCount);
	    inputCount--;
	}
	return 0;
}
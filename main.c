#include <stdio.h>

int num[12] = {13, 17, 22, 27, 32, 33, 38, 41, 45, 48, 54, 66};

int interpolation(int key)
{
	int count = 0;
	int low = 0;
	int high = 11;

	while (low <= high)
	{
		int middle = (float)(key - num[low])/(num[high] - num[low]) * (high - low) + low;
		count++;
		if (num[middle] < key)
		{
			low = middle + 1;
		}
		else if (num[middle] > key)
		{
			high = middle - 1;
		}
		else{
			break;
		}
		}
	return count;
}


int main(void){
printf("%d\n", interpolation(38));
		return (0);
}

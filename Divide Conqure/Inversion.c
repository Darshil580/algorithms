#include <stdio.h>
#define pf(a,n) for(int i=0;i<n;i++)printf("%d",a[i])


int Inversion(int *array, int size) {

	int x = 0, count = 0; // For Division Purpose......

	//Base Condition............
	if (size == 1) {
		return 0;
	}

	//Division Purpose
	if (size % 2 == 0) {
		x = 0;
	}
	else {
		x = 1;
	}


	//two new arrays......
	int array1[size / 2], array2[(size / 2) + x];
	//Dividing values into two different array......
	for (int i = 0; i < size / 2; ++i)
	{
		array1[i] = array[i];
	}
	for (int j = 0, i = size / 2; i < size ; ++i)
	{
		array2[j] = array[i];
		j++;
	}

	Inversion(array1, size / 2);
	Inversion(array2, (size / 2) + x);

	// pf(array1, size / 2);
	// printf("\n");
	// pf(array2, (size / 2) + x);
	// printf("\n");

	int j = 0, k = 0;
	for (int i = 0; i < size; i++) {
		if (array1[j] < array2[k]) {
			array[i] = array1[j];
			j++;
		}
		else {
			array[i] = array2[k];
			k++;
			count++;
		}
	}
	return count;

}

int main(int argc, char const *argv[])
{
	int n, inversion_cnt;
	printf("Enter the Size:");
	scanf("%d", &n);
	int array[n];
	for (int i = 0; i < n; ++i)
	{
		printf("Enter %d Elements of array:", i + 1);
		scanf("%d", &array[i]);
	}
	inversion_cnt = Inversion(array, n);
	printf("\nSorted Elements + Inversion count.....................\n");
	for (int i = 0; i < n; ++i)
	{

		printf("%d\n", array[i]);
	}
	printf("Number of Inversion:%d\n", inversion_cnt );
	return 0;
}
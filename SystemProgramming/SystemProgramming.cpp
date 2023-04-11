
#include <stdio.h>
//#include "t2.c"
//#include "linkList.c"
#include <iostream>
//#include "main.c"
//#include "tree.c"

#include "orders.c"

#include "main.c"
#include "treeimp.cpp"

using namespace std;

void inputSmallestPair() {
	int i,j, results=0;
	//cin >> size;
	i = 0;
	const int size = 5;
	/*int arr[3];
	for (; i < size; i++){
		cin >> arr[i];
	}*/
	
	int arr[] = {4,1,7,2,9};
	int minValue = arr[0];
	for (i=0; i < size; i++) {
		for ( j = i+1; j < size; j++)
		{
			results = (arr[i] + arr[j]) + (j+i);
			/*cout << "arr[" << i << "] : " << arr[i];
			cout << " arr[" << j << "] : " << arr[j] << endl;
			cout << "results: " << results << endl;*/

			if (results <minValue) {
				minValue = results;
			}
		}
	}
	cout << minValue<<endl;
}
void smallestPair() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		inputSmallestPair();
	}
}
void sheet1() {
	int num1,num2;
	cin >> num1 >> num2;
	for (int i = num1; i <= num2; i++) {
		int x = i;
		int luckly = 0;
		while (x) {
			if (x % 10 != 4 && x % 10 != 7)
				luckly++;
				
			x /= 10;
		}
		if (luckly == 0)
			cout << "x: " << x << " i luc: " << i << endl;
	}
	
	
}
int main()
{
	//switchTask2();
	//smallestPair();
	sheet1();
}


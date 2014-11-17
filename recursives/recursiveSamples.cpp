// sample applications for recursive logic

#include "stdafx.h"
#include <iostream> // input output stream ;) you know that
#include <iomanip> // for setw() method

using namespace std;

// n * n-1 * n-2 * n-3 ...
int factorial(int n) {
	return(n == 0 ? 1 : n * factorial(n - 1));
}

// 1 1 2 3 5 8 13 21 34 ..
int fibonacci(int n) {
	if (n <= 2) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

// 4 * 3 = 4 + 4 + 4
int multiplication(int a, int b) {
	return (b == 1 ? a : multiplication(a, b - 1) + a);
}

// x : searching item
// first and last value
// stack is array which searching in it
int binarySearch(int x, int first, int last, int stack[]) {
	if (first > last) return -1; // if first value bigger than last value it's mean of this is not sorted list, return -1 and go fuck yourself
	int mid = (first + last) / 2;
	return (stack[mid] == x ? stack[mid] : x > stack[mid] ? binarySearch(x, mid + 1, last, stack) : binarySearch(x,first, mid -1, stack));
}
/*
   Hanoi Towers

   #        #        #
  *#*       #        #
  *#*       #        #
  *#*       #        #
#######  #######  #######
  src     dest      aux

  n : disc count, for this case 3

*/
void hanoi(int n, char src, char dest, char aux) {
	if (n > 1) {
		hanoi(n - 1, src, aux, dest);
		hanoi(1, src, dest, aux);
		hanoi(n - 1, aux, dest, src);
	} else {
		cout << "Move top disc from " << src << " to " << dest << endl;
	}
}

// calculate next value for pascal triangle
long calculate(int n, int r) {
	if ((n == 0) || (r == 0) || (n == r)) return 1;
	else return calculate(n - 1, r - 1) + calculate(n - 1, r);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Factorial: 5! = "<<factorial(5) << endl; // 120
	
	cout << "Fibonacci Array's Fourth Item: "<<fibonacci(4) << endl; // 3

	cout << "Multiple 4 x 3 = 4 + 4 + 4 = " << multiplication(4, 3) << endl; // 12

	int lovelyArray[6] = {1,2,4,6,8,12};

	cout<< "Founded item is => "<<binarySearch(6, 1, 6, lovelyArray)<< endl; 
	cout << "Do this steps for move disc from A to B"<<endl;
	hanoi(3, 'A', 'B', 'C');
	cout << endl << "PASCAL TRIANGLE for 5 rows"<<endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 5; j > i; j--) cout << " ";
		for (int k = 0; k <= i; k++) cout << setw(6) << calculate(i,k);
		printf("\n");
	}

	return 0;
}


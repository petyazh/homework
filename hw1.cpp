// Petya Zhelyazkova, FN: 62052
// SI,II course, I group 

#include "iostream"

using namespace std;

//Imame eksponencialna slojnost-2^n, poneje se izvurshvat po 2 recursivni izvikvaniq pri vsqko izpulnenie na funkciqta
long int recursion_fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else return (recursion_fib(n - 1) + recursion_fib(n - 2));
}

//Lineina slojnost
long int recursion_fib_line(int n)
{
	long int number = 1;
	long int number1 = 1;
	long int number2 = 1;
	for (int i = 2; i < n; i++)
	{
		number = number1 + number2;
		number2 = number1;
		number1 = number;
	}
	return number;
}


int main()
{
	int n = 0;
	cout << "Input number: ";
	cin >> n;

	//print the line
	for (int i = 0; i<n; i++)
		cout << recursion_fib(i) << endl;

	return 0;
}


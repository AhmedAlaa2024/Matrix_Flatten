#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;

int main(void)
{
	int num_tests;

	cout << "Enter the number of tests: ";
	cin >> num_tests;

	int n, m, p, i, j, k;

	std::ofstream out("tests.txt");
	out << num_tests << endl;

	int t;
	for (t = 0; t < num_tests; t++)
	{
		n = (rand() % 5) + 1;
		m = (rand() % 5) + 1;
		p = (rand() % 5) + 1;

		out << n << "\t" << m << "\t" << p << endl;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				for (k = 0; k < p; k++)
				{
					if (k == p - 1)
						out << rand() % 1000;
					else
						out << rand() % 1000 << "\t";
				}
				out << endl;
			}
		}
	}

	out.close();
}
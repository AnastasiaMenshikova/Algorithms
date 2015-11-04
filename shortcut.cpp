/*

brief: Find the shortiest distance
input: Field size N*M
       Current position (x,y)
output:short distance

p.s.: "x" belongs to the long edge, "y" - to the short edge. 
      The edges mustn't be equal.

*/


#include <iostream>
using namespace std;

int main() {

	int N, M, x, y;
	cin >> N >> M >> x >> y;

	if (N != M)
	{
		if (M > N && y<=M && x<=N)
		{
			M -= y;
			N -= x;
		}
		if (N > M && y <= N && x <= M)
		{
			M -= x;
			N -= y;
		}
	}

	int min = x;
	if (y < M && y < N && y < min)
		min = y;
	else
		if (M < y || N < y)
		{
			if (M < min && M < N)
				min = M;
			if (N < min && N < M)
				min = N;
		}
	cout << min << " ";
	return 0;
}

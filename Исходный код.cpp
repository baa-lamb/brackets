#include <iostream>
#include <vector>
#include <stack>

using namespace std;

char op1 = '(';
char cl1 = ')';
char op2 = '[';
char cl2 = ']';

void print(vector<char> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
}

void f(int position, int toOpen, stack<char> st, vector<char> & res, int N)
{
	if (position == N)
	{
		if (st.empty())
			print(res);
		return;
	}
	if (toOpen < N / 2)
	{
		res[position] = op1;
		st.push(op1);
		position++;
		toOpen++;
		f(position, toOpen, st, res, N);
		st.pop();
		position--;
		toOpen--;

		res[position] = op2;
		st.push(op2);
		position++;
		toOpen++;
		f(position, toOpen, st, res, N);
		st.pop();
		position--;
		toOpen--;
	}	
	if (!st.empty())  // toOpen >= N/2
	{
		char c = st.top();
		st.pop();
		toOpen--;
		if (c == op1)
		{
			res[position] = cl1;
			position++;
			f(position, toOpen, st, res, N);
			position--;
		}
		else if (c == op2)
		{
			res[position] = cl2;
			position++;
			f(position, toOpen, st, res, N);
			position--;
		}
	}
}


int main()
{
	int n = 0;
	cin >> n;

	int toOpen = 0;
	vector<char> res(n);
	stack <char> st;

	f(0, toOpen, st, res, n);

	return 0;
}
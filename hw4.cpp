#include<cstdio>
#include<cstring>
#include<iostream>
#include <bitset>
#include <vector>

using namespace std;

bitset<2000> matrix[2000];

void readMatrix(int n)
{
	bool bit;

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> bit;

			matrix[i][j] = bit;
		}
	}
}

unsigned long long number(int n)
{
	unsigned long long numOfSycles = 0;
	int node = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			node = (matrix[i] & matrix[j]).count();
			numOfSycles += (node * (node - 1)) / 2;
		}
	}

	return numOfSycles / 2;
}

//
long long int m = pow(10, 9) + 7;

long long int power(long long int n, long long int p)
{
	long long int pro = 1;

	while (p != 0)
	{
		if (p & 1)
		{
			pro = ((pro%m) *(n%m)) % m;
		}
		p = p / 2;
		n = ((n%m)*(n%m)) % m;
	}

	return pro;
}

//

vector<int > vec[100001];
int  ta[100001] = {}, td[100001] = {};
int used[100001] = {};

void dfs(int x)
{
	int t = 1;
	ta[x] = t;
	used[x] = 1;

	for (int i = 0; i<vec[x].size(); i++)
	{
		int x1 = vec[x][i];
		if (!used[x1])
		{
			t++;
			dfs(x1);
		}
	}

	t++;
	td[x] = t;
}


//
bool adj[11][11];
bool vnode[11];
vector <int> nodes;

bool solve(int n, int curr) 
{
	if (nodes.size() == n)
	{
		return true;
	}

	for (int i = 1; i <= n; i++) 
	{
		if (adj[curr][i] && (!vnode[i])) 
		{
			vnode[i] = true;
			nodes.push_back(i);
			bool result = solve(n, i);
			
			if (result) 
			{
				return true;
			}
			
			vnode[i] = false;
			nodes.pop_back();
		}
	}
	
	return false;
}

int main()
{
	//Monk at the Graph Factory 
	int n = 0;
	int p = 0;
	cin >> n;
	int sum = 0;

	for (int i = 1; i <= n; i++) 
	{
		cin >> p;
		sum = sum + p;
	}
	if ((n - 1) * 2 == sum)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}



	//	Monk in the real estate
		int t;
		cin >> t;

		while (t--)
		{
			int k = 0;
			int c = 0;
			int i = 0;
			cin >> k;

			int a[10001] = { 0 };

			for (i = 0; i<k; i++)
			{
				int x = 0;
				int y = 0;

				cin >> x >> y;

				a[x] = 1;
				a[y] = 1;

			}

			for (i = 1; i<10001; i++)
			{
				if (a[i] == 1)
				{
					c++;
					a[i] = 0;
				}
			}
			cout << c << endl;
		}
	
	//


	//Utkarsh in Gardens
		
		int size = 0;
		cin >> size;

		bool** matrix = new bool*[size];
		readMatrix(size);

		cout << number(size);


	//Rhezo and HackerEarth

		long long int h = 0;
		string l;

		cin >> h >> l;
		long long int o = 0;

		for (int i = 0; i<l.size(); i++)
		{
			o = (((o % (m - 1))*(10 % (m - 1))) % (m - 1) + l[i] - '0') % (m - 1);
		}
		cout << power(h, o);

	//Oliver and the Game 

		std::ios_base::sync_with_stdio(0);
		cin.tie(NULL);
		
		int g;
		cin >> g;

		int alpha = g - 1;

		while (alpha--)
		{
			int d = 0;
			int b = 0;
			cin >> d >> b;
			vec[d].push_back(b);
			vec[b].push_back(d);
		}
		
		dfs(1);
		
		int q = 0;
		cin >> q;

		while (q--)
		{
			int a = 0;
			int b = 0;
			int c = 0;
			
			cin >> a >> b >> c;
		
			
			if (a == 1)
			{
				swap(b, c);
			}

			if (ta[b] <= ta[c] && td[b] >= td[c])
			{
				cout << "YES" << endl;
			}

			else {
				cout << "NO" << endl;
			}
		}


		//Micro and Coins

			int t;
			scanf("%d", &t);
			while (t--) {
				int n, m, a, b;
				scanf("%d %d", &n, &m);
				for (int i = 1; i <= n; i++) {
					vnode[i] = false;
					for (int j = 1; j <= n; j++) {
						adj[i][j] = false;
					}
				}
				while (m--) {
					scanf("%d %d", &a, &b);
					adj[a][b] = true;
					adj[b][a] = true;
				}
				nodes.clear();
				int flag = 0;
				for (int i = 1; i <= n; i++) {
					vnode[i] = true;
					nodes.push_back(i);
					if (solve(n, i)) {
						printf("Yes\n");
						flag = 1;
						break;
					}
					vnode[i] = false;
					nodes.pop_back();
				}
				if (flag == 0) printf("No\n");
			}
		







	return 0;
}
#include<stdio.h>
#include<string.h>
#include<cmath>
#define ll long long
#include<algorithm>
using namespace std;
// https://codeforces.com/problemset/problem/1578/E
int eEasyScheduling()
{
	ll t, h, p;
	scanf("%lld", &t);
	while (t--)
	{
		ll sum = 1, a = 0;
		scanf("%lld%lld", &h, &p);
		for (ll i = 1; i < h; i++)
		{
			ll k = pow(2, i) - a;
			a = 0;
			if (k <= p)
				sum++;
			else
			{
				if (k % p != 0)
				{
					sum++;
					a = p - (k % p);
				}
				sum += k / p;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}

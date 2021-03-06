#include <bits/stdc++.h>
#define mod 1000000007
#define Pi 3.14159265358979311599796346854
#define INF 0x3f3f3f3f
#define MAX 1000010
#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vii vector< pii >
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define endl '\n'
#define teto(a, b) (a+b-1)/b
 
using namespace std;
 
ll llrand()
{
	ll tmp = rand();
	return (tmp << 31) | rand();
}
 
ll add(ll a, ll b, ll c)
{
	return (a + b)%c;
}
 
ll mul(ll a, ll b, ll c)
{
	ll ans = 0;
	while(b)
	{
		if(b & 1)
			ans = add(ans, a, c);
		a = add(a, a, c);
		b /= 2;
	}
	return ans;
}
 
ll rho(ll n)
{
	ll x, c, y, d, k;
	int i;
	do{
		i = 1;
		x = llrand()%n;
		c = llrand()%n;
		y = x, k = 4;
		do{
			if(++i == k)
			{
				y = x;
				k *= 2;
			}
			x = add(mul(x, x, n), c, n);
			d = __gcd(abs(x - y), n);
		}
		while(d == 1);
	}
	while(d == n);
	
	return d;
}
 
ll fexp(ll a, ll b, ll c)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1)
			ans = mul(ans, a, c);
		a = mul(a, a, c);
		b /= 2;
	}
	return ans;
}
 
bool rabin(ll n)
{
	if(n <= 1)
		return 1;
	if(n <= 3)
		return 1;
 
	ll s=0, d=n-1;
	while(d%2==0)
	{
		d/=2;
		s++;
	}
 
	for(int k = 0; k < 64*4; k++)
	{
		ll a = (llrand()%(n - 3)) + 2;
		ll x = fexp(a, d, n);
		if(x != 1 and x != n-1)
		{
			for(int r = 1; r < s; r++)
			{
				x = mul(x, x, n);
				if(x == 1)
					return 0;
				if(x == n-1)
					break;
			}
			if(x != n-1)
				return 0;
		}
	}
 
	return 1;
}
 
 
int main()
{
	//sws;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	ll N, resp;
	vector<ll> div;
 
	cin >> N;
	resp = N;
 
	while(N>1 and !rabin(N))
	{
		ll d = rho(N);
		if(!rabin(d))
			continue;
		div.pb(d);
		while(N%d==0)
			N/=d;
	}
	if(N!=resp and N!=1)
		div.pb(N);
	

	if(div.empty())
		cout << resp << endl;
	else
	{
		for(int i=0;i<(int)div.size();i++)
			resp = __gcd(resp, div[i]);
 
		cout << resp << endl;
	}
 
	return 0;
 
}
/*
 * we solve it using dp bitmask , we will try to fill the table dp[2^N] the following way 
 * dp [mask] = we choose a submask from the main mask , we consider that the submask is a new group , so we check if the total wight is less than W 
 * dp [mask] = cost [submask] + dp [ (mask^submask) ] , this can be done in O ( n^3 ) by applying some tricks in the for loops 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+9;
const ld pai=acos(-1);
const int Sz = ( 1 << 17 ) + 9 ;
int n , Mx ;
int t [16] , w [16] ;
int ok [Sz] , cost [Sz] , dp [Sz] ; 
int main () {
	cin >> Mx >> n ;
	for ( int i = 0 ; i < n ; i ++ ) cin >> t[i] >> w[i] ; 
	for ( int mask = 1 ; mask < ( 1 << n ) ; mask ++ ) dp [mask] = 1e9 ;
	for ( int mask = 1 ; mask < ( 1 << n ) ; mask ++ ) {
		int W = 0 , T = 0 ; 
		for ( int bit = 0 ; bit < n ; bit ++ ) {
			if( ( mask & ( 1 << bit ) ) ) {
				W += w [bit] ;
				T = max ( T , t [bit] ) ;
			}
		}
		ok [mask] = ( W <= Mx ) ;
		cost [mask] = T ;
	}
	for ( int mask = 0 ; mask < ( 1 << n ) ; mask ++ ) {
		for ( int sub = mask ; sub > 0 ; sub = ( sub-1 ) & mask ) {
			if ( !ok [sub] ) C ;
			dp [mask] = min ( dp [mask] , dp [ ( mask ^ sub ) ] + cost [sub] ) ;
		}
	}
	cout << dp [ ( 1 << n ) -1 ] << endl ; 
}

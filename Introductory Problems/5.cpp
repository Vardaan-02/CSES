#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<endl;return;}

const int M = 1e9+7;
const int N = 1e5+10;

void precalc(){}

void solve(){
	int n;
    cin >> n;
    if(n==1) r(1)
    if(n<4) r("NO SOLUTION")
    for(int i=2 ; i<=n ; i+=2) cout << i << " ";
    for(int i=1 ; i<=n ; i+=2) cout << i << " ";
    cout << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	precalc();
	// int t;
	// cin >> t;
	// while(t--){
		solve();
	// }
	return 0;
}
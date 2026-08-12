#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>

#define INF 2e9
#define ll long long int

using namespace std;

void solve(){
	
	int n;
	cin>>n;
	vector<int>arr(n);
	for( int i=0; i<n; i++)
		
		cin>>arr[i];
		//cout<<arr[i];
		
	
	sort(arr.begin(),arr.end());
	ll ans=0;
	for(int i=1;i<n-1;i++){
		auto ubit=upper_bound(arr.begin(),arr.end(),arr[i]);
		int high =arr.end()-ubit;
		auto lbit=lower_bound(arr.begin(),arr.end(),arr[i]);
		int low =lbit-arr.begin();
		ans+=1LL*high*low;
	}	
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	while(tc--){
		solve();
	}
	return 0;
}

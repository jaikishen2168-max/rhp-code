
#include<iostream>
#define ll long long int

using namespace std;

void solve(){
	ll  x, y, k; cin>>x>>y>>k;
	ll  mo=0,ctr=0;
	
	while(ctr<k){
		ll rem=(y+ctr)%(x+ctr);
		if(rem == y-x) break;
		mo+= rem; ctr++;
		
	}
	if(k>ctr){
		mo+=(k-ctr)*(y-x);
	}
	
	
	
	cout<<mo<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	cin>>tc;
	while(tc--){
		solve();
	}
	return 0;
}  

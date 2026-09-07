#include<iostream>
#include<vector>
using namespace std;

int hcf(int a, int b){
    return b==0? a : hcf(b,b%a);
}


void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
      cin>>arr[i];
    }
    cout<< hcf(arr[0],arr[n-1])<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc; 
  cin>>tc;
  while(tc--){
     solve();
  }
 return 0;
}

#include <iostream>
using namespace std;

int main() {
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    int a,b;
    cout<<"Enter the ele pos"<<endl;
    cin>>a>>b;
    int sum =0;
    int diff[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for (int i=0;i<8;i++){
        int adjr=a+diff[i][0], adjc=b+diff[i][1];
        if(adjr>=0 && adjr<r && adjc>=0 && adjc<c){
            sum+=arr[adjr][adjc];
        }
    }
    cout<<sum;
    return 0;
}

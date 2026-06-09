#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int l=s.length();
    for(int ctr=1;ctr<(1<<l);ctr++){
        //check set bits
        string combi="";
        for(int sh=0;sh<l;sh++){
            if((ctr&(1<<sh))!=0){
                //it is a set bit
                combi+=s[sh];

            }
        }
        cout<< combi<<endl;
    }

    return 0;
}

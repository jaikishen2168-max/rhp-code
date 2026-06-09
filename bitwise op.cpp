#include <iostream>
using namespace std;
// bitwise op to check whether the string contains alphabets
int main() {
    string str;
    cin>>str;
    int flag=0;
    int flag1=0;
    for(char ch:str){
        if(ch>='a'&& ch<='z'){
        flag |= (1<<(ch-'a'));
    }
    
 if(ch>='A'&& ch<='Z'){
        flag1 |=(1<<(ch-'A'));
    }
    }
    cout<<(flag==(1<<26)-1?"Yes": "No");
    cout<<(flag1==(1<<26)-1?"Yes":"No");
    return 0;
}

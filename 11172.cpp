#include<bits/stdc++.h>

using namespace std;

int main(){
    int T,a,b;
    cin>>T;
    while(T--){
        cin>>a>>b;
        printf("%c\n",(a > b)?'>':(a<b)?'<':'=');
    }
}

#include<bits/stdc++.h>
using namespace std;

int pairs[100005][2];
int b,s;


int main(){
	//freopen("test.in","r",stdin);
	while(cin>>s>>b && (b!=0 && s!=0)){
		for(int i =1;i<=s;i++){
			pairs[i][0] = i-1;
			pairs[i][1] = i+1;
		}
		pairs[s][1] = pairs[1][0] = -1;
		
		for(int i = 0;i<b;i++){
			int l,r; cin>>l>>r;
			if(pairs[l][0]!=-1)cout<<pairs[l][0]<<' ';
			else cout<<"* ";
			if(pairs[r][1]!=-1)cout<<pairs[r][1]<<'\n';
			else cout<<"*\n";
			
			//update
			int lefty = pairs[l][0], righty=pairs[r][1];
			pairs[lefty][1]=righty;
			pairs[righty][0]=lefty;
		}
		cout<<"-\n";
		memset(pairs,0,sizeof(pairs));
		
	}
}

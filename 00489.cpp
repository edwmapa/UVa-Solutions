#include<bits/stdc++.h>
using namespace std;

bool c[26];
bool used[26];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t;
	while(cin>>t){
		if(t==-1)break;
		string sa,sb;
		cin>>sa>>sb;
		int tot=0;
		for(int i = 0;i<sa.size();i++){
			if(!c[sa[i]-'a'])tot++;
			c[sa[i]-'a']=true;
		}
		int left = 7;
		for(int i  = 0;i<sb.size();i++){
			if(!used[sb[i]-'a']){
				used[sb[i]-'a']=true;
				
				if(c[sb[i]-'a']){
					c[sb[i]-'a']=false;
					tot--;
				}else{
					left--;
				}
				
			}else continue;
			
			if(tot == 0 || left==0)break;
			
		}
		
		
		
		cout<<"Round "<<t<<'\n';
		if(left == 0 && tot>0){
			cout<<"You lose.\n";
		}else if(tot==0 && left>=0){
			cout<<"You win.\n";
		}else{
			cout<<"You chickened out.\n";
		}
		memset(used,0,sizeof(used));
		memset(c,0,sizeof(c));
	}
}

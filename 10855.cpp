#include<bits/stdc++.h>

using namespace std;
int n,m, ans[4];
string A[1000010],B[1000010];

void comp(int x,int y){
	bool failure[]={false,false,false,false};
//	cout<<"----\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			char ith = A[x+i][y+j];
//            cout<<ith;
			if(ith != B[i][j])failure[0]=true;
			if(ith != B[m-1-j][i])failure[1]=true;
			if(ith != B[m-1-i][m-1-j])failure[2]=true;
			if(ith != B[j][m-1-i])failure[3]=true;
			if(failure[0]&&failure[1]&&failure[2]&&failure[3])break;
		}
//		cout<<endl;
		if(failure[0]&&failure[1]&&failure[2]&&failure[3])break;
	}

	if(!failure[0])ans[0]++;
	if(!failure[1])ans[1]++;
	if(!failure[2])ans[2]++;
	if(!failure[3])ans[3]++;
}

int main(){

	while(cin>>n>>m && !(n==0 || m==0)){
		for(int i = 0;i<n;i++)cin>>A[i];
		for(int i = 0;i<m;i++)cin>>B[i];

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(i+m>n || j+m>n)continue;
				comp(i,j);
			}
		}
		cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<'\n';
		ans[0]=ans[1]=ans[2]=ans[3]=0;
	}
}

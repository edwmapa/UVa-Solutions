#include<bits/stdc++.h>

using namespace std;
bool used[54];
int sisC[3],broC[2];
int sis[3],bro[2];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(cin>>sis[0]>>sis[1]>>sis[2]>>bro[0]>>bro[1]){
		if(sis[0] ==0 && sis[1]==0 && sis[2]==0 && bro[0]==0 && bro[1]==0)break;
		
		used[sis[0]]=used[sis[1]]=used[sis[2]]=true;
		used[bro[0]]=used[bro[1]]=true;
		
		for(int i = 0 ; i<2;i++){
			for(int j = 0;j<3;j++){
				if(bro[i]<sis[j]){
					broC[i]++;
					sisC[j]++;
				}
			}
		}
		
		//cout<<sisC[0]<<" "<<sisC[1]<<" "<<sisC[2]<<" / "<<broC[0]<<" "<<broC[1]<<endl;
		int temp = 0;
		bool cond = true;
		if(broC[0]==0 && broC[1]==0){
			while(++temp<53){
				if(!used[temp])break;
			}
			if(!used[temp] && temp<53)cout<<temp<<'\n';
			else cout<<-1<<'\n';
		}
		else if((broC[0]>0 && broC[1]==0) || (broC[1]>0 && broC[0]==0)){
			int maxV = max(broC[0],broC[1]);
			if(maxV == 1){
				for(int i = 0;i<3;i++){
					if(sisC[i]==0){
						temp = max(temp,sis[i]);
					}
				}
			}else if(maxV >= 2){
				for(int i = 0;i<3;i++){
					if(sisC[i]!=0){
						temp = max(temp,sis[i]);
					}
				}
			}
			while(++temp<53){
				if(!used[temp])break;
			}
			if(!used[temp] && temp<53)cout<<temp<<'\n';
			else cout<<-1<<'\n';
		}else if(broC[0]>0 && broC[1]>0){
			for(int i = 0 ; i< 3;i++){
				if(sisC[i] == 0 && sisC[(i+1)%3] == 0 && sisC[(i+2)%3] > 0){
					temp = max(sis[i],sis[(i+1)%3]);
					cond = false;
					break;
				}
			}
			while(++temp<53){
				if(!used[temp])break;
			}
			if(!used[temp] && !cond && temp<53)cout<<temp<<'\n';
			else cout<<-1<<'\n';
		}else{
			cout<<-1<<'\n';
		}
		
		
		memset(sisC,0,sizeof(sisC));
		memset(broC,0,sizeof(broC));
		memset(used,0,sizeof(used));
	}
}

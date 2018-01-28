#include<bits/stdc++.h>

using namespace std;

int aPos(char ca){return (ca == 'S')?0 : (ca == 'H')?1 : (ca == 'D')?2 : 3;}
char suit[] = {'S','H','D','C'};

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	string data;
	while (getline(std::cin,data)){
		stringstream ss;
		ss<<data;
		
		string c;
		int point = 0;
		int nPoint = 0;
		int amount[] = {0,0,0,0};
		int special[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};//A,K,Q,J
		bool isStopped[] = {0,0,0,0};
		while(ss>>c){
			int val = (c[0] == 'A')?4 : (c[0] == 'K')?3 : (c[0] == 'Q')?2 : (c[0] == 'J')?1 : 0;
			point += val;
			if(val>=1)special[aPos(c[1])][val-1]++;
			amount[aPos(c[1])]++;
		}
		for(int i = 0;i<4;i++){
			if(amount[i]-1 == 0 && special[i][2] >= 1)point--; // king rule
			if(amount[i]-1 <=1 && special[i][1] >= 1)point--; // queen rule
			if(amount[i]-1 <=2 && special[i][0] >= 1)point--; // jack rule
			
			//stopped
			if((special[i][3]>=1) || (special[i][2]>=1 && amount[i]-1>=1) || (special[i][1]>=1 && amount[i]-1>=2))isStopped[i]=1;
			
		}
		nPoint = point;//rules 5,6,7
		for(int i = 0;i<4;i++){ // could be handled in the for loop above
			if(amount[i]==2)nPoint++;
			else if(amount[i]<=1)nPoint+=2;
		}
		
		//cout<<endl<<point<<" "<<nPoint<<endl;
		//cout<<"S "<<isStopped[0]<<endl;
		//cout<<"H "<<isStopped[1]<<endl;
		//cout<<"D "<<isStopped[2]<<endl;
		//cout<<"C "<<isStopped[3]<<endl;
		
		if(nPoint<14)cout<<"PASS\n";
		else{
			if(point>=16 && (isStopped[0]&&isStopped[1]&&isStopped[2]&&isStopped[3])){
				cout<<"BID NO-TRUMP\n";
				continue;
			}
			
			int mx = 0, id = 0;
			for(int i = 0;i<4;i++){
				if(amount[i]>mx){
					id=i;
					mx = amount[i];
				}
			}
			cout<<"BID "<<suit[id]<<'\n';
		}
		
	}
}

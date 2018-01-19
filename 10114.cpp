#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int months, records;
	double downPayment, amount;
	while(cin>>months>>downPayment>>amount>>records){
        if(months<=0)break;
        double pays = amount/months;
        double carValue = amount + downPayment;
        amount+=pays;
        double percent[102];
        while(records--){
            int m; double p;
            cin>>m>>p;
            for(int i=m;i<=months;i++){
                percent[i]=p;
            }
        }
        int curMonth = -1;
        while(carValue < amount || curMonth == -1){
            curMonth++;
            carValue *=(1-percent[curMonth]);
            amount -=pays;
        }
        cout<<curMonth;
        if(curMonth==1)cout<<" month\n";
        else cout<<" months\n";

	}
}

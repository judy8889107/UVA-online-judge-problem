//p911
#include<iostream>

using namespace std;
int main(){
	
	int n; // 1<= n <= 10
	long long int record[11] = {1,1,1,1,1,1,1,1,1,1};
	
	
	for(int i=0;i<11;i++){
		for(int j = 2*(i+1); j>(i+1);j--){
			record[i] *= j;
		}
		for(int k=1;k<=(i+1);k++){
			record[i] /= k;
		}
		record[i] /= (i+2);
	}
	int count = 0;
	while(cin >> n){
		
		if(count!=0) cout << endl;
		cout << record[n-1] << endl;
		count++;
	}
	
	
	
}
//p10036
#include<iostream>
#include<math.h>
#include<string.h>

int f[11000][100];

using namespace std;
int main(){
	
	int test_case;
	cin >> test_case;
	while(test_case--){
		
		int n; //1 <= n <= 10000
		int k; //2 <= k <= 100
		cin >> n >> k;
		
		int num[n]; //The integer's range is from -10000~10000
		memset(f,0,sizeof(f));
		
		//Input
		for(int i=0;i<n;i++){
			cin >> num[i];
			num[i] = abs(num[i])%k;
		}
		
		f[0][0] = 1;
		//The f[n+1] record i-th num[]
		//The [100] is record the reminder of num[i]/k, Why 100 because the k is from 2~100
		//So the reminder of any integer divides k is less than 100
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				if(f[i][j]){
					f[i+1][(j+k+num[i])%k] = 1;
					f[i+1][(j+k-num[i])%k] = 1;
					
				}
			}
		}
		
		if(f[n][0]) cout << "Divisible" << endl;
		else cout << "Not divisible" << endl;
		
		
	}
	
}
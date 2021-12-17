//p900
#include<iostream>

using namespace std;

int main(){
	
	int length;
	long long int f[51]={0,1,2}; 
	for(int i=3;i<51;i++){
		f[i] = f[i-1]+f[i-2];
	}
	
	while(cin>>length && length!=0){
		cout << f[length] << endl;
		
	}
	
}
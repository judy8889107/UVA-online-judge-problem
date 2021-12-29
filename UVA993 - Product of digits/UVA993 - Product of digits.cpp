//p993
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	
	int test_case;
	cin >> test_case;
		
	
	
	while(test_case--){
		
		int n; // 0 <= n <= 10^9
		int digits[100];
		int index = 0;
		bool find;
		
		cin >> n;
		if(n==0){
			cout << "0" << endl;
			continue;
		}
		if(n==1){
			cout << "1" << endl;
			continue;
		}
		
		//Initialize digits
		for(auto &d: digits) d = 0;
		while(n!=1){
			find = false;
			for(int i=9;i>1;i--){
				if(n%i==0){
					digits[index++] = i;
					n /= i;
					find = true;
					break;
				}
			}
			if(!find) break;
		}
		
		if(!find) cout << "-1" << endl;
		else{
			sort(digits,digits+100);
			for(const auto& d : digits){
				if(d!=0) cout << d;
			}
			cout << endl;
		}
		
		
	}
		
		
	
}
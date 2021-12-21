//p10162
#include<iostream>
#include<string>

using namespace std;
int main(){
	
	int map[20] = {0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4};
	string str;
	while(cin >> str && str !="0"){
		int d = str[str.length()-1]-'0';
		
		if(str.length() > 1)  d += (str[str.length()-2]-'0')*10;
		
		cout << (map[d%20]+4*(d/20))%10 << endl;
		
	}
	
	return 0 ;
}


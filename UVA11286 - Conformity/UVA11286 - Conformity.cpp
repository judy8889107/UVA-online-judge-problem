//p11286
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;


int main(){
	
	int n;
	while(cin >> n && n != 0){
		
		map<string, int> combinationMap;
		string tmp;
		int course[5];
		
		//Input
		for(int i=0;i<n;i++){
			tmp = "";
			for(int j=0;j<5;j++) cin >> course[j];
			sort(course, course+5);
			for(int k=0;k<5;k++) tmp += to_string(course[k]);
			combinationMap[tmp]++;
		}
		
		int maxStudentNum = 0;
		int total = 0;
		
		for(const auto &it : combinationMap){
				if(it.second > maxStudentNum){
					maxStudentNum = it.second;
					total = it.second;
				}
				else if(maxStudentNum == it.second) total += it.second;
		}
		
		cout << total << endl;
		
		
		
		
		
		
		
		
		
		
		
		
	}
}
//p10009
#include<iostream>
#include<vector>

using namespace std;
using std::cout;
using std::endl;
int main(){
	
	int test_case;
	int m,n;
	string str1, str2;
	cin >> test_case;
	
	while(test_case--){
		
		int a[26]; //record every city's parent
		vector<int> va[26]; //record path from each city to Rome through other nodes
		
		cin >> m >> n;
		
		for(int i=0;i<26;i++) a[i] = -1; //a[i] default = -1
		while(m--){
			cin >> str1 >> str2;
			a[str2[0]-'A'] = str1[0]-'A';
		}
		
		
		for(int i=0;i<26;i++){
			int tmp = i;
			
			va[i].push_back(tmp); //path includes itself
			
			while(a[tmp]!=-1){
				va[i].push_back(a[tmp]);
				tmp = a[tmp];	
			}
		}
		
		
		//Input two city and display the shortest path
		while(n--){
			
			cin >> str1 >> str2;
			int str1_index = str1[0]-'A';
			int str2_index = str2[0]-'A';
			int j,k; //record the str1,str2's index of cocity
			
			
			for(j=0;j<va[str1_index].size();j++){
				for(k=0;k<va[str2_index].size();k++){
					if(va[str1_index].at(j) == va[str2_index].at(k)){
						goto display; //break double loop
					}
				}
			}
			
			display:
			for(int i=0;i<j;i++) printf("%c", va[str1_index].at(i)+'A');
			for(int i=k;i>-1;i--) printf("%c", va[str2_index].at(i)+'A');
			
			cout << "" << endl;
			
			
		}
			
		if(test_case != 0) cout << endl;
		
	}
	
	
	return 0;
	
}

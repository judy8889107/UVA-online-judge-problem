//p997
#include<iostream>
#include<string>
#include<vector>
#include<ctype.h> //For isdigit() function

using namespace std;
int main(){
	
	string str;
	int n;
	
	while(cin >> str >> n){
		vector<int> seq;
		vector<int> m;
		vector<char> op;
		string tmp = "";
		
		
		
		for(int i=0;i<str.length();i++){
			if(str[i]=='-' || isdigit(str[i])){
				tmp += str[i];
			}
			if(str[i]=='+' || str[i] =='*'){
				m.push_back(stoi(tmp));
				tmp = "";
				op.push_back(str[i]);
			}
		}
		m.push_back(stoi(tmp)); //Because the last m will not meet the sign '+' or '*'
		
		for(int i=0;i<n;i++) seq.push_back(m.back());
		m.pop_back();
		
		while(op.size()!=0){
			if(op.back()=='+'){
				seq.push_back(m.back());
				for(int i=1;i<n;i++){
					seq.push_back(seq.front()+seq.back());
					seq.erase(seq.begin());
				}
				seq.erase(seq.begin()); //Beacause the si will not be erase in the front loop.
				op.pop_back();
				m.pop_back();
			}
			if(op.back()=='*'){
				seq[0] *= m.back();
				for(int i=1;i<seq.size();i++){
					seq[i] *= seq[i-1]; 
				}
				op.pop_back();
				m.pop_back();
			}
		}
		
		for(int i=0;i<seq.size();i++){
			cout << seq[i];
			if(i!=seq.size()-1) cout << " ";
		} 
		cout << endl;
		
		
		
	}
	
	
}
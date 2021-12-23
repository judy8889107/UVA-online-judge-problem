//p10183
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//Use vector to record the BigNum, and do operator
class BigNum{
	
	public:
		//Constructor
		BigNum(const string &str){
			for(int i=str.length()-1;i>-1;i--)
				_num.push_back(str[i]-'0');
		}
		
		//Copy a vector to the vector<int> num
		BigNum(const vector<int> &v){
			_num = v;
		}
		
		BigNum add(const BigNum &bigNum){
			vector<int> result;
			int index = 0;
			int carry = 0;
			//Because it is BigNum a.add BigNum b, So need to compare two digits
			int maxDigit = max(_num.size(), bigNum._num.size()); 
			
			for(index = 0;index < maxDigit;index++){
				int sum = carry ;
				if(index < _num.size()) sum += _num.at(index);
				if(index < bigNum._num.size()) sum += bigNum._num.at(index);
			
				result.push_back(sum%10);
				carry = sum/10;
				
			}
			
			//When out maxDigit and should carry
			if(carry>0) result.push_back(carry);
			
			//return the result
			return BigNum(result);
		}
		
		int compareTo(const BigNum &bigNum){
			
			//First compare digits
			if(_num.size() > bigNum._num.size()) return 1;
			if(_num.size() < bigNum._num.size()) return -1;
			
			//If the number of digits is the same
			for(int i=_num.size()-1;i>-1;i--){
				
				if(_num[i] > bigNum._num[i]) return 1;
				if(_num[i] < bigNum._num[i]) return -1;
				
			}
			
			//If a == b
			return 0;
			
		}
		
		int getSize(){
			return _num.size();
		}
		
		void display(){
			
			for(int i=_num.size()-1;i>-1;i--){
				cout << _num[i];
			}
			
		}
	
	private:
		vector<int> _num;
	
};

int main(){
	
	vector<BigNum> memorize;
	memorize.push_back(BigNum("1"));
	memorize.push_back(BigNum("2"));
	
	BigNum nextItem("0");
	
	
	//Calculate the all fibs in the range
	do{
		
		nextItem = memorize[memorize.size()-1].add(memorize[memorize.size()-2]);
		memorize.push_back(nextItem);
		
	}while(nextItem.getSize() <= 100); //Because the range is 10^100
	
	string a,b;
	
	while(cin>>a>>b && (a!="0" || b!="0")){
		
		BigNum A(a);
		BigNum B(b);
		
		int count = 0;
		
		for(int i=0;i<memorize.size();i++){
			
			int compareA = A.compareTo(memorize[i]);
			int compareB = B.compareTo(memorize[i]);
			
			
			
			if(compareB < 0) break;
			if(compareA <= 0 && compareB >= 0) count++;
			
		}
		
		cout << count << endl;
		
	}
	
}
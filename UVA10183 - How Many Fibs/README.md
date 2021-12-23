## 題目說明<br>
><br>f1 = 1
<br>f2 = 2
<br>fi = fi-1+fi-2

<br>給定兩整數a,b (a <= b <= 10^100 )
<br>找出在此區間中的 fi 有幾個並印出

## 解題<br>
<br>寫出BigNum class，將費式數列列出並記錄下，最後跟a,b compare後印出
<br>BigNum使用vector時，可以用v.max_size()去看可用capacity為多少
<br>**※系統預設超過可用的capacity，自動配置新的記憶體空間（預設是兩倍大)**
<br>**把資料拷過去，再把新資料寫入**
<br><br>**※注意index的地方小心，不要out vector range**

<br><br>**副程式(BigNum Class)：**
```cpp
class BigNum{
	
	public:
		//建構子
		BigNum(const string &str){
			for(int i=str.length()-1;i>-1;i--)
				_num.push_back(str[i]-'0');
		}
		
		//複製vetor到_num(建構子)
		BigNum(const vector<int> &v){
			_num = v;
		}
		
		//加法
		BigNum add(const BigNum &bigNum){
			vector<int> result;
			int index = 0;
			int carry = 0;
			
			//因為是BigNum a + BigNum b，需要compare誰的位數比較大
			int maxDigit = max(_num.size(), bigNum._num.size()); 
			
			for(index = 0;index < maxDigit;index++){
				int sum = carry ;
				
				//假設一個3位數、一個5位數，index判斷有沒有超過其size()，沒有就將該位數加入sum
				if(index < _num.size()) sum += _num.at(index);
				if(index < bigNum._num.size()) sum += bigNum._num.at(index);
				
				//把相加結果放進result中
				result.push_back(sum%10);
				
				//設定carry(進位)
				carry = sum/10;
				
			}
			
			//若兩者最後加完會多進位(超過maxDigit)，ex:9+9=18，本來一位數變成兩位數(carry = 1)
			//則多增加一位
			if(carry>0) result.push_back(carry);
			
			//傳回result
			return BigNum(result);
		}
		
		//兩數比較
		int compareTo(const BigNum &bigNum){
			
			//先比較位數多寡，a.compareTo(b)
			//a>b > 1 / a<b > -1
			if(_num.size() > bigNum._num.size()) return 1;
			if(_num.size() < bigNum._num.size()) return -1;
			
			//若兩數位數相同，則從高位開始比較
			for(int i=_num.size()-1;i>-1;i--){
				
				if(_num[i] > bigNum._num[i]) return 1;
				if(_num[i] < bigNum._num[i]) return -1;
				
			}
			
			//如果全部都一樣(a==b)，返回0
			return 0;
			
		}
		
		//返回_num(私有variable)的size()
		int getSize(){
			return _num.size();
		}
		
		//Debug用
		void display(){
			
			for(int i=_num.size()-1;i>-1;i--){
				cout << _num[i];
			}
			
		}
	
	//私有變數
	private:
		vector<int> _num;
	
};
```
<br>**主程式：**
```cpp
int main(){
	
	//利用vector<> memorize紀錄算出的fibs
	vector<BigNum> memorize;
	
	//f1=1,f2=2
	memorize.push_back(BigNum("1"));
	memorize.push_back(BigNum("2"));
	
	//紀錄fi-1+fi-2的結果
	BigNum nextItem("0");
	
	
	//計算範圍內所有fibs
	do{
		
		nextItem = memorize[memorize.size()-1].add(memorize[memorize.size()-2]);
		memorize.push_back(nextItem);
		
	}while(nextItem.getSize() <= 100); //當nextItem位數小於等於100時，繼續計算，因為b最多到10^100
	
	string a,b;
	
	while(cin>>a>>b && (a!="0" || b!="0")){
		
		BigNum A(a);
		BigNum B(b);
		
		int count = 0;
		
		//memorize中的所有元素跟a,b比較
		for(int i=0;i<memorize.size();i++){
			
			int compareA = A.compareTo(memorize[i]);
			int compareB = B.compareTo(memorize[i]);
			
			
			//若fi>b就會break
			if(compareB < 0) break;
			
			//若在區間內，count++
			if(compareA <= 0 && compareB >= 0) count++;
			
			
		}
		
		//印出結果
		cout << count << endl;
		
	}
	
}
```
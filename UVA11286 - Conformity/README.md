## 題目意思<br>
<br>每個學生有不同的課程組合，預設每人可以選五種課
<br>印出最受歡迎的課程組合的人數
<br>**※最受歡迎的課程組合為最多人修的那個組合**
<br>**(最受歡迎的課程組合可能不只有一個)**

## 解題<br>
<br>課程先由小排到大後，利用string列出課程組合，再利用map紀錄人數並印出：
<br>
```cpp
int main(){
	
	int n;
	while(cin >> n && n != 0){
		
		string tmp;
		map<string, int> combinationMap;
		.
		.
		.
		.	
			for(int k=0;k<5;k++) tmp += to_string(course[k]);	//to_string(int) 函數
			combinationMap[tmp]++;					//map插入值
```
<br>**因為最受歡迎的組合可能不只一種(假設人數相同)，所以還要進行判斷：**
<br>
```cpp
		int maxStudentNum = 0;
		int total = 0;
		
		for(const auto &it : combinationMap){		//不使用iterator作法
				if(it.second > maxStudentNum){
					maxStudentNum = it.second;
					total = it.second;
				}
				else if(maxStudentNum == it.second) total += it.second;
		}

```


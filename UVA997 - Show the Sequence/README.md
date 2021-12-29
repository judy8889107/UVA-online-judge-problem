## 題目意思<br>
<br>給定一串string和N，列出數列前N項
<br>依照公式[i]，會有 N 個 i
<br>譬如：[1] 5 = 1 1 1 1 1
<br>加法公式  **[m + S]**：第一項(v1)為 m，而v2 = s1 + v1...
<br>乘法公式  **[m * S]**：第一項(v1)為 m\*s1，而 v2 = s2 \* v1...

## 解題<br>
<br>因輸入會有[]字元，所以要先用vector做處理
<br>先利用兩個vector分別存vector \<int\>digits 和 vector\<char\>operator，vector\<int\> seq 則負責記錄數列：
```cpp
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
	m.push_back(stoi(tmp)); //當遇到+或*就會存tmp，但是最後一個數字不會再遇到+或*，所以要另外再存進vector
```
<br>第一步先將seq填滿[ i ]：
```cpp
for(int i=0;i<n;i++) seq.push_back(m.back());
	m.pop_back(); //都是利用vector的size去做判斷
```
<br>判斷符號(\* or +)，並做運算
<br>**(比較要注意的是加法的部分，因為會用到舊的數列，所以先不能取代掉，要先存在數列尾巴)：**
```cpp
while(op.size()!=0){ //因op char必搭配一個數字，每次做完都把vector的元素pop掉
	if(op.back()=='+'){
		seq.push_back(m.back()); //依照公式，s1等於m(新的數列先記錄在尾巴)
		for(int i=1;i<n;i++){
			seq.push_back(seq.front()+seq.back()); //s2 = 舊的s1 + 新的v1
			seq.erase(seq.begin());				   //消除舊的s1
		}
		seq.erase(seq.begin()); //最後舊的sn不會被消除，所以要另外消除
		op.pop_back();
		m.pop_back();
	}
	if(op.back()=='*'){
		seq[0] *= m.back();
		for(int i=1;i<seq.size();i++){
			seq[i] *= seq[i-1]; //s2 = v1(新的) * s2(舊的)
		}
		op.pop_back();
		m.pop_back();
	}
}
```

<br>自己寫出來真的很有成就感:DDDDD

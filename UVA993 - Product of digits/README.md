## 題目意思<br>
<br>給定一非負整數N( 0 <= N <= 10^9)
<br>印出最小的自然數Q，Q的所有digits的積會等於N
<br>
## 解題<br>
<br>把輸入的數字做因數分解
<br>從9~2，若都沒辦法整除則輸出-1
<br>**※不用大於9是因為如果是質數，不能再被分解**
<br>**而如果不是質數，可以再被分解成更小的數字**
<br>考慮要印出最小自然數，所以從9開始除會最小
<br>**須對0,1另外特別判斷**
<br>
<br>將result digits存在陣列後，再sort並印出：
```cpp
else{
		sort(digits,digits+100);
		for(const auto& d : digits){
			if(d!=0) cout << d;
		}
		cout << endl;
	}
```
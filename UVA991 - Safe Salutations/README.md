## 題目意思<br>
<br>給定一整數N( 1 <= N <= 10)，有N個pairs(2N)個人
<br>讓倆倆握手，但不cross的情況有幾種

## 解題<br>
<br>使用**卡塔蘭**公式解
<br>![""](https://s0.wp.com/latex.php?latex=C_n%3D%5Cfrac%7B1%7D%7Bn%2B1%7DC%5E%7B2n%7D_n&bg=ffffff&fg=000000&s=0&c=20201002)
<br>**※注意運算的range，使用long long int**
<br>[**卡塔藍公式詳細講解**](https://johnmayhk.wordpress.com/2014/02/03/cn/)
```cpp
....
long long int record[11] = {1,1,1,1,1,1,1,1,1,1}; //用array紀錄
	
	
	for(int i=0;i<11;i++){
		for(int j = 2*(i+1); j>(i+1);j--){
			record[i] *= j;	//階乘先乘
		}
		for(int k=1;k<=(i+1);k++){
			record[i] /= k;	//後除
		}
		record[i] /= (i+2);	//再除1/n+1
	}
```
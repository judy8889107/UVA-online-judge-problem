## 題目意思<br>
<br>給定一floating(浮點數) a，求出格子狀、條紋狀、點點狀面積
## 解題<br>
<br>!["替代文字"](https://pic.pimg.tw/a7069810/1474948098-2159512261.png)
<br>格子面積：正方形(ABCD) - 1/12圓(AED、BCE) - 正三角形(ABE) (一塊)
<br>點點面積：正方形(ABCD) - 1/4圓(ABD) - 2\*格子面積 (一塊)
<br>斜線面積：正方形(ABCD) - 4\*個子面積 - 4\*點點面積。

```cpp
#include<cmath>

using namespace std;
int main(){
	double pi = M_PI; //使用圓周率
}
```
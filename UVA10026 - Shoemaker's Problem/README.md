# 題目說明<br>
<br>本題是指鞋匠一次只能選一個工作做，以Sample Input為例
<br>如果先選第一件工作，它需要完成的時間為3天，那麼這3天就無法做其他工作
<br>罰金就為3\*(1000+2+5)元，本題要找出選擇工作的次序使得罰金最小。
<br>**若有多個解，則依照字母順序輸出**
# 解題<br>
<br>因此本題解法是將每個工作(Fi/Ti)由大到小排序
<br>* **輸出的是要做第幾個工作，(2,3,1)例如先做第2個、第1個、第3個**
<br>
```cpp
bool compare(Job a, Job b){
	if(a.weight > b.weight) return true;
	else if(a.weight == b.weight)			//若其權重相同時，則判斷index大小(因題目說多個解，則按照字母順序輸出)
		if(a.index < b.index) return true;
	
	return false;
}
```
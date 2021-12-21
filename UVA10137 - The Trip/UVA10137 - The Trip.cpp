//p10137
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b){
	return a>b;
}
int main(){
	
	int sum;
	int remain_cent;
	int average_cost;
	int total_exchange_cost;
	int n; //n is less than 1000
	while(cin>>n && n!=0){
		
		sum = 0;
		total_exchange_cost = 0;
		int cost[n]; //cost[n] less than 10,000
		
		
		
		
		for(int i=0;i<n;i++){
			int tmp1, tmp2;
			scanf("%d.%d", &tmp1, &tmp2);
			cost[i] = tmp1*100+tmp2;
			sum += cost[i];
		}
		
		
		
		sort(cost,cost+n,compare);
		
		remain_cent = sum%n;
		average_cost = sum/n;
		
		for(int i=0;i<remain_cent;i++){
			total_exchange_cost += abs(cost[i]-(average_cost+1));
		}
		for(int i=remain_cent;i<n;i++){
			total_exchange_cost += abs(cost[i]-average_cost);
		}
		
		printf("$%.2lf\n", total_exchange_cost/200.0);
		
	}
}
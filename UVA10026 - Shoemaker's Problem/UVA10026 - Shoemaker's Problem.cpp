//p10026
#include<iostream>
#include<algorithm>

using namespace std;

struct Job{
	float weight=0; //fine/time
	int index=0; //The i-th job
};

bool compare(Job a, Job b){
	if(a.weight > b.weight) return true;
	else if(a.weight == b.weight)
		if(a.index < b.index) return true;
	
	return false;
}

int main(){
	
	int test_case;
	cin >> test_case;
	
	while(test_case--){
			int n;
			cin >> n;
			float time, fine;
			Job job[n];
			
			for(int i=0;i<n;i++){
				cin >> time >> fine;
				job[i].weight = fine/time;
				job[i].index = i+1; 
			}
			
			sort(job,job+n,compare);
			
			for(int i=0;i<n;i++){
				cout << job[i].index;
				if(i!=n-1) cout << " ";
			}
			cout << endl;
			if(test_case!=0) cout << endl;
			
			
			
			
			
		
	}
}
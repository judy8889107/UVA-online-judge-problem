//p10209
#include<iostream>
#include<cmath>

using namespace std;
int main(){
	
	double pi = M_PI;
	double a; //0 <= r <= 10000
	while(cin >> a){
		
		double grid_area    = a*a - (a*a*pi/6.0) - (a*a*sqrt(3.0)/4.0);
		double dotted_area  = a*a - (a*a*pi/4.0) - (2.0*grid_area);
		double striped_area = a*a - (4.0*grid_area) - (4.0*dotted_area);
		printf("%.3f %.3f %.3f\n", striped_area, 4.0*dotted_area, 4.0*grid_area);
		
		
	}
	
}
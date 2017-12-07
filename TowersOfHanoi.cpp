#include <iostream>
#include <vector>
using namespace std;



void towersOfHanoi(int n){
	vector <int> t[3];
	int from = 0, moves = 0, candidate = 1, to;

	if(n % 2 == 0){
		to = 2;
	}
	else{
		to = 1;
	}

	//"n+1" is the platform
	for(int i = n+1 ; i > 0 ; i--)
		t[0].push_back(i);
	t[1].push_back(n+1);
	t[2].push_back(n+1);

	while(t[1].size() < n+1){
		cout<<++moves<<". We moved " << candidate << " from " << char(from+65) << " to "<<char(to+65)<<endl;

		t[to].push_back(t[from].back());
		t[from].pop_back();


		if(t[(to+1)%3].back() < t[(to+2)%3].back()){
			from = (to+1)%3;
			candidate = t[(to+1)%3].back();
		}
		else{
			from = (to+2)%3;
			candidate = t[(to+2)%3].back();
		}

		if(n%2==0){
			if(candidate < t[(from+2)%3].back())
				to = (from+2) % 3;
			else
				to = (from+1) %3;
		}
		else{
			if(candidate < t[(from+1)%3].back())
				to = (from+1) % 3;
			else
				to = (from+2) %3;
		}

	}

	cout<<"TOTAL NUMBER OF MOVES: " << moves << endl;
	return;
}

int main(){
	int n;
	cout<<"Give me an integer:";
	cin>>n;
	towersOfHanoi(n);
	return 0;
}



#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n = 15;
	vector<string> temp(15);

	for(int i=0; i<15; i++){
		temp[i] = to_string(i+1);
		if(i%3==2) temp[i] = "Fizz";
		if(i%5==4) temp[i] = "Buzz";
		if(i%15==14) temp[i] = "FizzBuzz";
	}

	vector<string> res(n);

	for(int i=0; i<n; i++){
		if(temp[i%15]!="Fizz" && temp[i%15]!="Buzz" && temp[i%15]!="FizzBuzz"){
			res[i] = to_string(i+1);
		} else {
			res[i] = temp[i%15];
		}
		cout<<res[i]<<endl;
	}
	

}
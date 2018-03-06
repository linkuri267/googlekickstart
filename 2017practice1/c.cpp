#include <iostream>
#include <cmath>
#include <algorithm>

int substring(int n){
	if(n == 0){
		return(0);
	}
	if(n == 1){
		return(1);
	}
	else{
		return(substring(n/2) + substring(n-(n/2)) + (n/2)*(n-n/2));
	}
}


int main(int argc, char const *argv[])
{
	int T;
	std::cin >> T;

	int nums[T][2];

	for(int t = 0; t < T; t++){
		std::cin >> nums[t][0];
		std::cin >> nums[t][1];
		//std::cout << nums[t][0];
		//std::cout << nums[t][1];
	}

	int max[T];
	for(int t = 0; t< T; t++){
		max[t] = substring(std::min(nums[t][0],nums[t][1]));
		std::cout << "Case #" << t+1 << ": " << max[t] << std::endl;
	}	


	return 0;
}
#include <iostream>
#include <unordered_map>
#include <unordered_set> 
#include <tuple>

//DOESNT WORK FOR LARGE M N

std::unordered_map <int, std::unordered_map<int,std::unordered_map<int,int>>> a;
//int aTest [1000][1000][500];

int solve(int n, int m, int ahead){
	//two base cases 
	//there is 1 vote left
	//if n is far enough ahead that the last m vote will not tie then last vote m is a valid
	//if n is at least ahead by 1 last vote n is a valid pattern
	if((n == 1)&&(m == 0)){
		return(1);
	}
	else if((n == 0)&&(m == 1)&&(ahead > 1)){
		return(1);
	}
	int ans;
	if((a[n][m]).find(ahead) == (a[n][m]).end()){
		//no more n votes 
		//some m votes left ;
		//not enough ahead 
		if((n == 0)&&(m > 0)&&(ahead <= 1)){
			ans = 0;
		}
		//no more n votes
		//enough ahead
		else if((n == 0)&&(m > 0)&&(ahead > 1)){
			ans = solve(n,m-1,ahead-1);
		}

		else if((n > 0) && (m == 0)){
			ans = solve(n-1,m,ahead+1);
		}

		//there are n and m votes left
		//n is only 1 ahead so cannot have another m vote
		else if((m > 0)&&(n > 0)&&(ahead <= 1)){
			ans = solve(n-1,m,ahead+1);
		}

		//there are n and m votes
		//n is more than 1 ahead so can have another m vote
		else if((m > 0) && (n > 0) && (ahead >1)){
			ans = solve(n-1,m,ahead+1) + solve(n,m-1,ahead-1);
		}
		return(ans);
		(a[n][m]).insert({ahead,ans});

	}
	else{
		return(a[n][m][ahead]);
	}

}

// int solve(int n, int m, int ahead){
// 	//two base cases 
// 	//there is 1 vote left
// 	//if n is far enough ahead that the last m vote will not tie then last vote m is a valid
// 	//if n is at least ahead by 1 last vote n is a valid pattern
// 	if((n == 1)&&(m == 0)){
// 		return(1);
// 	}
// 	else if((n == 0)&&(m == 1)&&(ahead > 1)){
// 		return(1);
// 	}
// 	int ans;
// 	if(aTest[n][m][ahead] == 0){
// 		//no more n votes 
// 		//some m votes left ;
// 		//not enough ahead 
// 		if((n == 0)&&(m > 0)&&(ahead <= 1)){
// 			ans = 0;
// 		}
// 		//no more n votes
// 		//enough ahead
// 		else if((n == 0)&&(m > 0)&&(ahead > 1)){
// 			ans = solve(n,m-1,ahead-1);
// 		}

// 		else if((n > 0) && (m == 0)){
// 			ans = solve(n-1,m,ahead+1);
// 		}

// 		//there are n and m votes left
// 		//n is only 1 ahead so cannot have another m vote
// 		else if((m > 0)&&(n > 0)&&(ahead <= 1)){
// 			ans = solve(n-1,m,ahead+1);
// 		}

// 		//there are n and m votes
// 		//n is more than 1 ahead so can have another m vote
// 		else if((m > 0) && (n > 0) && (ahead >1)){
// 			ans = solve(n-1,m,ahead+1) + solve(n,m-1,ahead-1);
// 		}
// 		std::cout << "n:" << n << " m:" << m << "ahead: " <<ahead <<std::endl;
// 		return(ans);
// 		aTest[n][m][ahead] = ans;

// 	}
// 	else{
// 		return(aTest[n][m][ahead]);
// 	}

// }
long double factorial(int n){
	if(n == 0)
		return(1);
	if(n == 1){
		return(1);
	}
	else{
		return(n*factorial(n-1));
	}
}

int main(int argc, char const *argv[])
{
	int T;
	std::cin >> T;


	int* n = new int [T];
	int* m = new int [T];

	for(int t = 0; t < T; t++){
		std::cin >> n[t];
		std::cin >> m[t];
	}


	int* c = new int [T];
	long double*ans = new long double [T];

	for(int t = 0;t < T; t++){
		c[t] = solve(n[t],m[t],0);
		//ans[t] = (long double)c[t]/(long double)factorial(n[t]+m[t]);
		ans[t] = (long double)c[t]*(factorial(n[t])*factorial(m[t]))/(long double)factorial(n[t]+m[t]);
		std::cout <<" 1 done" << std::endl;
	}

	for(int t = 0; t < T; t++){
		std::cout << "Case #" << t+1 << ": " << ans[t] << std::endl;
	}

	return 0;
}


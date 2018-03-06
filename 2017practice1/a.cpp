#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>


std::string tiebreak(std::string a, std::string b){
	//return winner
	int aindex = 0;
	int bindex = 0;
	while((aindex < a.size()) && (bindex < b.size())){
		if(a[aindex] == b[bindex]){
			aindex ++;
			bindex ++;
		}
		else if(a[aindex] < b[bindex]){
			return(a);
		}
		else{
			return(b);
		}
	}
	return(a);
	//returning a for now because not clear
}



int main(int argc, char const *argv[])
{
	int T,N;
	std::cin >> T;

	std::vector <std::vector <std::string>> names (T); 
	std::string temp;

	std::unordered_set <char> chars (20); 

	for(int t = 0; t < T; t++){
		std::cin >> N;
		for(int n = 0; n <= N; n++){
			std::getline(std::cin,temp);
			(names[t]).push_back(temp);
			//std::cout << temp << std::endl;
		}
	}

	std::vector <std::vector <int>> counts (T);
	std::vector<std::unordered_map <int, std::string>> diffCharsToName (T);
	std::string winner;
	std::string c1;
	std::string c2;

	for(int t = 0; t < T; t++){ //iterate through test cases
		for(int i = 0; i < names[t].size(); i++){ //iterate through all strings  in 1 test case
			counts[t].push_back(0);
			for(int n = 0; n < names[t][i].size(); n++){ //iterate through stirng
				if(names[t][i][n] == ' '){
					
				}
				else if(chars.find(names[t][i][n]) == chars.end()){
					chars.insert(names[t][i][n]);
					counts[t][i] = counts[t][i] + 1;
					//std::cout << "incremented"<< std::endl;
				}

			}	
			//tiebreaker
			if(diffCharsToName[t].find(counts[t][i]) != diffCharsToName[t].end()){ //if already exists
				c1 = diffCharsToName[t][counts[t][i]];
				c2 = names[t][i];
				winner = tiebreak(c1,c2);
				diffCharsToName[t].erase(counts[t][i]);
				diffCharsToName[t].insert({counts[t][i],winner});
			}
			else{
				diffCharsToName[t].insert({counts[t][i],names[t][i]});
			}
			chars.clear();

			//std::cout << "next name" << std::endl;
		}
	}

	std::vector <int> maxCounts (T);
	int tempMax;
	for(int t = 0; t < maxCounts.size(); t++){
		tempMax = 0;
		for(int i = 0; i < counts[t].size(); i++){
			if(counts[t][i] > tempMax){
				tempMax = counts[t][i];
			}
		}
		maxCounts[t] = tempMax;
	}

	std::vector <std::string> kings (T);
	//find strings corresponding to max chars
	for(int t = 0; t < maxCounts.size(); t++){
		kings[t] = diffCharsToName[t][maxCounts[t]];
		std::cout << "Case #" << t+1 << ": " << kings[t] << std::endl;
	}	


}	
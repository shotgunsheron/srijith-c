#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
//function to search a list for strings with the same length
vector<size_t> searchList(const vector<int>& theArray, int findFor)
{
    vector<size_t> indexes;
    for (size_t i = 0; i < theArray.size(); i++){
        if (theArray[i] == findFor){
            indexes.push_back(i + 1);
        }
    }
    return indexes;
}
//main function/algorithm
std::string consecutiveStrings(std::vector<std::string>strarr, int k){
		std::string result;
    	std::vector<int>lengths;
        int largestLengthFB;
        int count=2;
        while (count>0){
            lengths.clear();
    	    for (size_t i=0;i<strarr.size();i++){
      	        lengths.push_back((strarr[i]).length());
    	    }
            //return lengths;
            int largestLength=*max_element(lengths.begin(), lengths.end());
            
            largestLengthFB=largestLength;
            //std::cout<<largestLength<<'\n';
            //return largestLength;
            std::vector<size_t>indexes=searchList(lengths,largestLength);
            //return indexes;
            std::string x =strarr[indexes[0]-1];

            //std::cout<<x<<'\n';
            strarr[indexes[0]-1]="";
            result+=x;
            //std::cout<<strarr[0]<<"\n";
            //std::cout<<strarr[1]<<"\n";
            //std::cout<<strarr[2]<<"\n";
            //std::cout<<strarr[3]<<"\n";

            //return strarr;
        count-=1;
        }
        return result;
}



//driver function
int main() {
  std::vector<std::string> arr={"o","tw","tshfree","foursffff"};
  std::cout<<(consecutiveStrings(arr,2))<<'\n';
}
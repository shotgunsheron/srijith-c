#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<size_t> searchList(const vector<int>& theArray, int findFor)
{
    vector<size_t> indexes;
    for (size_t i = 0; i < theArray.size(); i++){
        if (theArray[i] == findFor){
            indexes.push_back(i+1);
        }
    }
    return indexes;
}

class LongestConsec
{
public:
    
    static std::string longestConsec(std::vector<std::string> &strarr, int k);
    

};  
 std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k){
    std::vector<int>lengths;
    std::vector<int>results;
    
    int x;
    for (size_t i=0;i<strarr.size()-k+1;i++){       
        

        for (int j=0;j<k+1;j++){
          if (j!=k){
            x+=strarr[i+j].length();

          }
        }
        
        results.push_back(x);
        x=0;
      
    }

    int largestLength=*max_element(results.begin(), results.end());
    vector<size_t> indexes=searchList(results,largestLength);
    
    std::string result=strarr[indexes[0]-1];
    for (int h=1;h<k;h++){
      result+=strarr[indexes[0]-1+k-1];
    }
    return result;
}

int main(){
    std::vector<std::string> x={"tree", "foling", "trashy", "blue", "abcdef", "uvwxyz"};
    x = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
    LongestConsec l;    
    std::string result;
    result = l.longestConsec(x,2 );
    std::cout<<result<<'\n';
}
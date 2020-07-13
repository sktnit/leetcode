//We are using sliding window concept and find the largest window size
//Whenever duplicate character appear in the same window, the starting 
//of new window from current position.
#include <vector>// vector include
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // store the position of each character when it last appears
        vector<int> lastpos(256,-1); 
        int i=0,res=0;
        int len= s.length();
        for(int j=0;j<len;j++){
            i=max(i,lastpos[s[j]]+1);
            res = max(res, j-i+1);
            lastpos[s[j]]=j;
        }
        return res;
    }
    int max(int p, int q){
        return (p>q ? p : q);
    }
};
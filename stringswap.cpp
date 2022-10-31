/*You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.



Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.


Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
*/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0,k=0;
        int arr[2];
        for(int i=0;i<s1.length();i++){
            if(s1[i]^s2[i]){
                count++;
                if(count>2)
                 return false; 
                arr[k]=i;
                k++;
            }   
        }
       if(count==1)
           return false;
       else if(count==0)
           return true;
        else{
            s2[arr[0]]^=s2[arr[1]];
            s2[arr[1]]^=s2[arr[0]];
            s2[arr[0]]^=s2[arr[1]];
            if(s1.compare(s2)==0)
                return true;
            else
                return false;
        }
    }
};

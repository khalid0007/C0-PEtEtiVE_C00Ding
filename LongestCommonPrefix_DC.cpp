#include<bits/stdc++.h>

#define len(s) s.length()

using namespace std;

string commonPrefixUtil(string str1, string str2){
    
    string result;

    int n1 = len(str1), n2 = len(str2);

    for(int i = 0, j = 0; i < n1 && j < n2; i++, j++){

        if(str1[i] != str2[j])
            break;

        result.push_back(str1[i]);
    }

    return result;
}

string common_prefix(string arr[], int left, int right){

    // If slice of array is length of 1
    // Return the only string
    if(left == right){
        return arr[left];
    }

    if(right > left){

        int mid = left + (right - left)/2;

        // Divide
        string str1 = common_prefix(arr, left, mid);
        string str2 = common_prefix(arr, mid + 1, right);

        // Conquer
        return (commonPrefixUtil(str1, str2));
    }
}


int main(){

    string arr[] = {"geeksforgeeks", "geeks", 
                    "geek", "geezer"}; 
    int n = sizeof (arr) / sizeof (arr[0]); 
  
    string ans = common_prefix(arr, 0, n-1); 
  
    if (ans.length()) 
        cout << "The longest common prefix is "
             << ans; 
    else
        cout << "There is no common prefix"; 

    return 0;
}
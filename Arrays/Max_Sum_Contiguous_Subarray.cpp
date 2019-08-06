/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
 */


int maxSubArray(const vector<int> &A) {
    int n = A.size();
    
    int max_here = 0 ;
    int max_result = INT_MIN ;
    for(int i = 0 ; i < n  ;  i++){
        
        max_here += A[i];
        
        if(max_here>max_result){
            max_result = max_here;
        }
        if(max_here<0)
            max_here = 0 ;
    }
    return max_result;
}

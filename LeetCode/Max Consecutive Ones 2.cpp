/*
1. Main thing is to understand is that we follow the idea of containing a valid segment between 'left' and 'right'
2. The only difference here is that we are given an option of flipping non-valid(0) to valid(1)
and by using this option/move we can make sure to always contain valid segment between left and right
by flipping the current 0 element to 1 and then moving the left pointer one position right to last used flipping (lastOptInd+1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // using the idea of contaning a valid segment between left and right pointer
        // plus we get one max flip operation
        int left=0,right=0,n=nums.size(),lastOptInd=-1,maxConsOnes=0;
        while(right<=n-1){
            if(nums[right]==0){
                // whenever we meet non-valid we always try to use flip operation
                if(lastOptInd!=-1){
                    // means the flip operation has been used
                    // and segment from left to right-1 was valid
                    maxConsOnes=max(maxConsOnes,(right-1)-left+1);
                    // we move left to one right of last used flip op index
                    left=lastOptInd+1;
                }
                lastOptInd=right;
            }
            // here we don't need else condition to check when nums[right]==1
            // as we have always made sure that left is pointing a valid position

            // since we have made sure that segment from left to right is valid
            if(right==n-1)
                maxConsOnes=max(maxConsOnes,right-left+1);

            right++;
        }
        return maxConsOnes;
    }
};

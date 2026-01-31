//TODO: Solution is still incorrect and missing one major concept, Hint: think in terms of graphs 
class Solution {
    public void rotate(int[] nums, int k) {
        // in-place rotation where we actually rotate/move elements one by one
        int i,n=nums.length,desiredInd,times,element,tmpEle;

        times=n;
        element=nums[0];
        desiredInd=k%n; // k is reduced to just remainder and actually it is i+k,0+k

        // we have to rotate/move n elements and we start from 0th element
        // so here element to move is 0th element and desired index is 0+k
        while(times>0){
            // move the element to its desired index
            tmpEle=nums[desiredInd];
            nums[desiredInd]=element;

            // update the element and the desired index
            element=tmpEle;
            desiredInd=(desiredInd+k)%n; // use % to handle cases when it index jumps out of bounds

            times--;
        }
    }
}

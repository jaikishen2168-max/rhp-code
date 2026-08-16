class Solution {
    public int maxRotateFunction(int[] nums) {
        int N = nums.length;
        int sum=0;
        long fnval=0;
        long max=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
            fnval+=(nums[i]*i);
        }
        max=fnval;
        for(int li=N-1;li>0;li--){
            fnval=fnval-(nums[li]*(N-1))+ (sum-nums[li]);
            max=Math.max(max,fnval);
        }
        return (int)max;

        
    }
}

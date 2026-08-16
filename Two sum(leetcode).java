class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> a = new HashMap<>();
        for (int i=0;i<nums.length;i++){
            int oth=(target-nums[i]);
            if(a.containsKey(oth)){
                return new int [] {a.get(oth),i};
            }else{
                a.put(nums[i],i);
            }

        }
        return new int []{-1,-1};
            }
        }

    

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        int count=0;
        left[0] = height[0];

        for(int i=1; i<height.size(); i++){
            left[i] = max(left[i-1], height[i]);
        }
        int n=height.size();
        right[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        for(int i=0;i<height.size();i++){
            count+=min(left[i],right[i])-height[i];
        }
        return count;
    }
};

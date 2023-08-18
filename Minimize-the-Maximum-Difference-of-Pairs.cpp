//  Let n be the size of `nums` and `V` be the maximum value in `nums`.

//Time complexity: O(n⋅log⁡V)

//  Space complexity: O(1)



class Solution {
public:


// function to check the pair_count 
        // if the count is >=p, then store the value of the maximum 
        //  and try to minimize
    bool check_pairs(int &p, int& mid,vector<int>& nums ){
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i++;
            }

        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {

        //  sorting the array because the minimum difference 
        //  can be found between two consecutive elemetns when it is sorted.
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // minimun difference
        int left=0; 
        //maximum difference
        int right=nums[n-1];

        int mid=left+(right-left)/2;
        int ans;

        while(left<=right){
        int mid=left+(right-left)/2;
        
        if (check_pairs(p,mid,nums)){
            ans=mid;
            right=mid-1;        // if count is >=p, then store the value of maximum 
                                 //  and try to minimize
        }
        else{
            left=mid+1;
        }
        }
        return ans;
    }
};

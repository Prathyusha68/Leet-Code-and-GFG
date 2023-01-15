class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(auto it=hash.begin();it!=hash.end();it++){
            if(k==0){
                if(it->second>=2)
                    cnt++;
            }          
            else if(hash.find(it->first+k)!=hash.end())
                cnt++;
        }
        return cnt;
            
        
    }
};
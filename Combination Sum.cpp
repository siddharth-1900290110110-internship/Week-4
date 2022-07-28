class Solution {
public:
    void combinationSumRec(const vector<int>& n, vector<vector<int>>& res, vector<int>& partial, int start, int target){
        if (target<0) return;
        if (target==0){
        
            res.push_back(partial);
            return;
            
        }
        
        for (auto i=start;i<n.size();++i){
        
            target-=n[i];
            
            
            partial.push_back(n[i]);
            
            combinationSumRec(n,res,partial,i,target);
            
            partial.pop_back();
            target+=n[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
          vector<vector<int>> result;
          
        vector<int> partial;
        
        combinationSumRec(candidates,result,partial,0,target);
        return result;
    }
};

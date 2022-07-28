class Solution {
public:
    void dfs(list<int> unusedNum, vector<vector<int> >& results,
             vector<int>& r, int depth) {
      
        if(depth == r.size()) {
            results.push_back(r);
          
            return;
        }

        list iterator it;
      
        for(it = unusedNum.begin(); it != unusedNum.end();) {
          
                r[depth] = *it;
                it = unusedNum.erase(it);
                dfs(unusedNum, results, r, depth+1);
          
                unusedNum.insert(it, r[depth]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
      
        vector<vector<int> > results;
      
        if(num.empty()) return results;
      

        vector<int> r(num.size());

        list<int> unusedNum(num.begin(), num.end());

        dfs(unusedNum, results, r, 0);            

        return results;
    }
};

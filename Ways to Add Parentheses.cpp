class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
      
          vector<int> res;
      
        for (int i = 0; i < expression.length(); i++) {
          
            if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*') {
                continue;
              
            }
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
          
            vector<int> right = diffWaysToCompute(expression.substr(i + 1, expression.length() - 1 - i));
          
            for (auto num1 : left) {
              
                for (auto num2 : right) {
                  
                    switch (expression[i]) {
                        
                        case '+':
                        
                            res.push_back(num1 + num2);
                            break;
                        case '-':
                        
                            res.push_back(num1 - num2);
                            break;
                        
                        case '*':
                            res.push_back(num1 * num2);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};

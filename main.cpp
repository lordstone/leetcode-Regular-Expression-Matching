class Solution {
public:

    int *arr;
    
    void init(int n){
        arr = new int [n];
        for(int i = 0; i < n; i++){
            arr[i] = -1;
        }
    }

    int btoi(bool jiji){
        if (jiji){
            return 1;
        }else{
            return 0;
        }
    }

    bool itob(int jiji){
        if (jiji == 1){
            return true;
        }else{
            return false;
        }
    }

    bool isMatch(string s, string p) {
        if(p.length() == 0){
            return s.length() == 0;
        }
        if(p.length() == 1){
            return s.length() == 1 && (p[0] == '.'|| s[0] == p[0]);
        }
        
        if(arr == NULL) init(s.length()+1);

        if(p[1] != '*'){
            if(arr[s.length() - 1] == -1){
                arr[s.length() - 1] = btoi(isMatch(s.substr(1), p.substr(1)));
            }
            return s.length()>0 && (p[0] == '.'|| s[0] == p[0]) && itob(arr[s.length()-1]);
        }else{
            if (arr[s.length()] == -1){
                arr[s.length()] = btoi(isMatch(s, p.substr(2)));
            }    
            if(arr[s.length()]){
                return true;
            }
            if (arr[s.length()-1] == -1){
                arr[s.length()-1] = btoi(isMatch(s.substr(1), p));
            }    
            return s.length()>0 && (p[0] == '.'|| s[0] == p[0]) && itob(arr[s.length()-1]) ;
        }
    }
};

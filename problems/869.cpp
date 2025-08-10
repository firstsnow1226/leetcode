class Solution {
public:
    vector<int> nums;

    bool cmp(int x,int y){
        
        for(int i=0;i<=9;i++){
            int a = x;
            int b = y;
            int cnt_a = 0;
            int cnt_b = 0;
            while( a>0 or b>0 ){
                if( a!=0 and a%10 == i )
                    cnt_a++;
                if( b!=0 and b%10 == i )
                    cnt_b++;
                a /= 10;
                b /= 10;
            }
            if( cnt_a != cnt_b )
                return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        int cnt = 1;
        while( cnt <= 1000000000 ){
            nums.push_back(cnt);
            cnt *= 2;
        }
        for(auto num:nums){
            if( cmp(n,num) )
                return true;
        }
        return false;
    }
};

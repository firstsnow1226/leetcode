class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long num = num1;
        long long cnt = 1;
        while( num >= 0 ){
            num -= num2;

            if( num < cnt  ) break;
            long long tmp = num;
            long long count = 0;
            while( tmp > 0 ){
                tmp -= (tmp&-tmp);
                count += 1;
            }
            if( count <= cnt ) return cnt;
            cnt += 1;
        }
        return -1;
    }
};

typedef long long int ll;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        ll x = numerator;
        ll y = denominator;

        bool minus = false;
        if( x == 0 )
            return "0";
        if( x < 0  and y < 0 ){
            x = -x;
            y = -y;
        }
        else if( x < 0 or y < 0 ){
            x = abs(x);
            y = abs(y);
            minus = true;
        }

        vector<ll> ans;
        unordered_map<ll,ll> mp;
        ll cnt = 0;

        while( x != 0 ){
            if( mp.count(x) != 0 ){
                //cout<<"pos:"<<mp[x]<<'\n';
                ans.insert(ans.begin()+mp[x],-1);
                ans.push_back(-3);
                break;
            }
            if( cnt >= 1 )
                mp[x] = cnt;
            
            ll num = x/y;
            x -= num*y;
            x *= 10;
            ans.push_back(num);
            cnt += 1;
        }

        string s = "";
        if( minus )
            s += '-';

        if( ans.size()==1 )
            return s + to_string(ans[0]);


        ans.insert(ans.begin()+1,-2);
        for(auto x:ans){
            if( x == -2 )
                s += '.';
            else if( x == -1 )
                s += '(';
            else if( x == -3 )
                s += ')';
            else
                s += to_string(x);
        }

        return s;
    }
};

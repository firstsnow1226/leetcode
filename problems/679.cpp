class Solution {
public:
    vector<char> operators = {'+','-','*','/'};
    bool ans = false;
    double count(int L,int R,const vector<double>& cards, const vector<char>& oper){
        deque<double> num;
        deque<char> op;
        num.push_back(cards[L]);
        for(int i=L;i<R;i++){
            if( oper[i] == '*' ){
                double a = num.back();
                double b = cards[i+1];
                num.pop_back();
                num.push_back(a*b);
            }else if( oper[i] == '/' ){
                double a = num.back();
                double b = cards[i+1];
                if (fabs(b) < 1e-9) return 1e9;
                num.pop_back();
                num.push_back(a/b);
            }else{
                op.push_back(oper[i]);
                num.push_back(cards[i+1]);
            }
        }
        while(!op.empty()){
            double a = num.front();
            num.pop_front();
            double b = num.front();
            num.pop_front();
            if( op.front() == '+' ){
                num.push_front(a+b);
            }else{
                num.push_front(a-b);
            }
            op.pop_front();
        }
        return num.front();
    }

    void f(const vector<double>& cards, const vector<char>& oper){
        if( ans ) return;
        if( oper.empty() ){
            if( fabs(cards[0] - 24) < 1e-6 ){
                ans = true;
            }
            return;
        }

        for(int L=0;L<cards.size();L++){
            for(int R=L+1;R<cards.size();R++){
                double cnt = count(L,R,cards,oper);
                vector<double> new_cards;
                vector<char> new_oper;
                for(int i=0;i<L;i++){
                    new_cards.push_back(cards[i]);
                    new_oper.push_back(oper[i]);
                }
                new_cards.push_back(cnt);
                for(int i=R+1;i<cards.size();i++){
                    new_cards.push_back(cards[i]);
                    new_oper.push_back(oper[i-1]);
                }
                f(new_cards,new_oper);
            }
        }
    }

    bool judgePoint24(vector<int>& cards) {
        ans = false;
        vector<double> new_cards;
        for(int a=0;a<4;a++){
            for(int b=0;b<4;b++){
                if( b == a ) continue;
                for(int c=0;c<4;c++){
                    if( c == b or c == a ) continue;
                    for(int d=0;d<4;d++){
                        if( d == a or d == b or d == c ) continue;
                        new_cards.clear();
                        new_cards.push_back(cards[a]);
                        new_cards.push_back(cards[b]);
                        new_cards.push_back(cards[c]);
                        new_cards.push_back(cards[d]);
                        for(int i=0;i<64;i++){
                            vector<char> oper;
                            oper.push_back(operators[i%4]);
                            oper.push_back(operators[(i%16)/4]);
                            oper.push_back(operators[i/16]);
                            //for(auto x:oper)
                            //    cout<<x<<' ';
                            f(new_cards,oper);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

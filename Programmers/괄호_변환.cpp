/*
사이트: 프로그래머스, 2020 KAKAO BLIND RECRUITMENT, 괄호 변환
분류: stack, 자료구조
코멘트
문제에서 설명한 동작 방식 그대로 구현하면 된다.
*/

#include <deque>
#include <string>

using namespace std;

bool balanceStr(string st){
    int l = 0;
    int r = 0;
    
    for(int i = 0; i < st.length(); ++i){
        if (st.at(i) == '('){
            ++l;
        }else{
            ++r;
        }
    }
    
    return l == r;
}

bool checkStr(string st){
    deque<char> stack;
    
    for(int i = 0; i < st.length(); ++i){
        if (st.at(i) == '('){
            stack.push_back('(');
        } else{
            if (stack.empty() || stack.back() != '('){
                return false;
            } else{
                stack.pop_back();
            }
        }
    }
    return true;
}

string uStr(string u){
    string st = "";
    
    for(int i = 1; i < u.length() - 1; ++i){
        if (u.at(i) == '('){
            st += ")";
        }else{
            st += "(";
        }
    }
    
    return st;
}

string solution(string p) {
    string ans = "";
    
    if (p.compare(ans) == 0 ){
        return ans;
    }
    
    int i, j;
    for(i = 0; i < p.length(); i += j){
        for(j = 2; j <= p.length(); j += 2){
            if (balanceStr(p.substr(i, j))){
                if (checkStr(p.substr(i, j))){
                    ans += p.substr(i, j);
                } else {
                    // 여기에서 바꿔야함
                    return ans += ("(" + solution(p.substr(i + j, p.length() - j)) + ")" + uStr(p.substr(i, j)));
                }
                break;
            }
        }
    }
    
    return ans;
}
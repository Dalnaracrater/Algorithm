/*
사이트: SWEA, 11445번
분류: string
코멘트
문제에서 주어진 예외 사항을 참고해야 한다. (문제를 잘 읽자)
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool FindDict(string p, string q){
    int gap = abs(int(p.length() - q.length()));
    
    if (gap > 1){
        return true;
    }
    
    if (p.length() > q.length()){
        q += "a";
    }else{
        p += "a";
    }
    
    if (q.compare(p) == 0){
        return false;
    } else{
        return true;
    }
}

int main(void){
    
    int t;
    cin.tie(0);
    
    cin >> t;
    for(int T = 1; T <= t; ++T){
        string p, q;
        
        cin >> p >> q;

        cout << "#" << T << " ";
        if (FindDict(p, q)){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    
    return 0;
}

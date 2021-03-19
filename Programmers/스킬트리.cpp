/*
사이트: 프로그래머스, Summer/Winter Coding(~2018), 스킬트리
분류: 문자열 비교?
코멘트
나는 두 배열을 비교하는 방식처럼 구현했는데, 다른 사람들의 풀이를 보니
skill 변수에 존재하는 스킬이면 따로 저장하여 두 배열의 비교가 끝나면
따로 저장된 배열과 skill을 비교하는 알고리즘으로 구현하였다.
나는 다소 어렵게 푼 경항이 있는 것 같다.
*/

#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int SIZE = 26;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int s[SIZE];
    
    memset(s, 0, sizeof(s));
    for(int i = 0; i < skill.length(); ++i){
        s[skill.at(i) - 'A'] = 1;
    }
    
    for(int i = 0; i < skill_trees.size(); ++i){
        
        int pointer = 0;
        
        string user = skill_trees[i];
        
        int check = 0;
        for(int j = 0; j < skill.length(); ++j){
            
            while(pointer < user.length()){
                if (skill.at(j) != user.at(pointer) && s[user.at(pointer) - 'A']){
                    check = 1;
                    break;
                } else if (skill.at(j) == user.at(pointer)){
                    ++pointer;
                    break;
                } else{
                    ++pointer;
                }
            }
            if (check){
                break;
            }
        }
        
        answer += (1 - check);
    }
    
    return answer;
}
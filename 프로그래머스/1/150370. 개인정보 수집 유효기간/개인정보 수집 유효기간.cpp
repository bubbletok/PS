#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

void deposeDate(string& date, int& year, int& month, int& day){
    //cout << date << endl;
    year += (date[0]-'0')*1000;
    year += (date[1]-'0')*100;
    year += (date[2]-'0')*10;
    year += (date[3]-'0');
    //for(int i=3; i>=0; i--) year += (date[i]-'0')*pow(10,i);
    month = (date[5]-'0')*10 + (date[6]-'0');
    day = (date[8]-'0')*10 + (date[9]-'0');
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int tyear=0,tmonth=0,tday=0;
    deposeDate(today,tyear,tmonth,tday);
    //cout << tyear << " " << tmonth << " " << tday << endl;
    int ttotal = tyear*12*28+tmonth*28+tday;
    
    map<char,int> period;
    for(int i=0; i<terms.size(); i++){
        char name = terms[i][0];
        int per = 0;
        int len = terms[i].size();
        for(int exp = 0, j=len-1; j>=2; j--, exp++){
            per += (terms[i][j]-'0') * pow(10,exp);
        }
        period[name] = per;
    }
    int i = 1;
    for(string& pri : privacies){
        int year=0,month=0,day=0;
        deposeDate(pri,year,month,day);
        char termName = pri[11];
        
        int termPer = period[termName];
        //cout << year << " " << month << " " << day << endl;
        int total = year*12*28+month*28+day + termPer*28;
        //cout << ttotal << " " << total << endl;
        
        bool check = total<=ttotal;
        if(check) answer.push_back(i);
        i++;
    }
    return answer;
}
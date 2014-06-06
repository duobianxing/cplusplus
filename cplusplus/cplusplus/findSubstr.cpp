#include <iostream>

using namespace std;
#include <cstring>
char * findSubstr(const char *s, const char *pattern){
     if(s == NULL || pattern == NULL) return NULL;
     char *p1 = (char *)s;
     while(*p1){
        char *matchbegin = p1;
        char *p2 = (char *)pattern;  
        bool fromMatch = false;
        cout<<"p1 "<<*p1<<'\n';
        cout<<"p2 "<<*p2<<'\n'<<'\n';
        while(*p1 && *p2 && *p1 == *p2){
            p1++;
            p2++;
            fromMatch = true;
        }
        if(!*p2){
            return matchbegin;
        }
        if(!fromMatch) p1 = matchbegin +1;
     }
     cout<<"not find matching"<<'\n';
     return NULL;
}

int main(){
    char s[] = "badssdfadcbcadc", pattern[] = "adc";
    cout<<findSubstr(s, pattern)<<'\n';
    
    
}

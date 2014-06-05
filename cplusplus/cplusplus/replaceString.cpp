bool isMatch(char *str, char *pattern){
      while(*pattern){
          if(*str++ != *pattern++){
              return false;
          }
      }
      return true;
}

void replaceString(char s[], char p[]){
         char *p2, *p1;
         const char *pattern = &p;
         plength = strlen(p);
         p2 = &s;
         p1 = p2;
         char *temp = &s;
         while(temp != "\0"){
              bool matched = false;
              while(isMatch(p1, pattern)){
                  p1 = p1 + plength;
                  matched = true;
              }
              temp = p1;
              if (matched){
                *p2++ = "X";
                while(*p1 != "\0"){
                  *p2++ = *p1++;   
                }
              }
         }

}

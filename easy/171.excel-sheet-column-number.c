/*
 * @lc app=leetcode id=171 lang=c
 *
 * [171] Excel Sheet Column Number
 */


int power(int a){
    int res = 1;
    for(int i=0;i<a;i++){
        res*=26;
    }
    return res;
}

int titleToNumber(char* s) {
    int length = strlen(s);
    int res = 0;
    for(int i=length-1;i>=0;i--){
        res+=((*s-'A'+1)*power(i));
        s++;
    }
    return res;
}




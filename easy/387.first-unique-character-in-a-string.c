/*
 * @lc app=leetcode id=387 lang=c
 *
 * [387] First Unique Character in a String
 */


int firstUniqChar(char* s) {
    int mark[26];
    for(int i = 0;i < 26;i++){
        mark[i] = -1;
    }
    int length = strlen(s);
    for(int i = 0;i < length;i++){
        if(mark[s[i]-'a'] == -1){
            mark[s[i]-'a'] = 0;
        }else{
            mark[s[i]-'a'] = -2;
        }
    }
    for(int i = 0;i < length;i++){
        if(mark[s[i]-'a'] == 0){
            return i;
        }
    }
    return -1;
}



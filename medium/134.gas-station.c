/*
 * @lc app=leetcode id=134 lang=c
 *
 * [134] Gas Station
 */


int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int *diff = (int *)malloc(sizeof(int)*gasSize);
    for(int i = 0; i< gasSize;i++){
        diff[i] = gas[i] - cost[i];
    }
    for(int i = 0; i<gasSize;i++){
        int j = i+1;
        int balance = diff[i];
        bool isEmpty = false;
        while(j%gasSize != i){
            if(balance < 0){
                isEmpty = true;
                break;
            }else{
                balance+=diff[j%gasSize];
                j++;
            }
        }
        if(!isEmpty&&balance>=0){
            return i;
        }
    }
    return -1;
}



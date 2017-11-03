// Implement atoi to convert a string to an integer.
//
// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//
// Notes: 
// It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
//
//
// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//
//
// spoilers alert... click to show requirements for atoi.
//
// Requirements for atoi:
//
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
//
//


class Solution {

const int NA = 0;
const unsigned long MAX=0X80000000;

public:
    int atoi(const char *str) {
    long long res = 0;
    int j=0;
    int code=1;
    bool getCode=false;
    long long once=0;
    if(strlen(str)==0)
        return 0;
    int start=0;
    for (start=0; start<strlen(str); start++) {
        if (str[start]!=' ') {
            break;
        }
    }
    
    for (int i=strlen(str)-1; i>=start; i--) {
        //
        if ((str[i]==' ')&&(j==0))
            continue;
        
        if ((str[i]=='-')&&(!getCode)) {
            code=-1;
            getCode=true;
            continue;
        }
        if ((str[i]=='+')&&(!getCode)) {
            code=1;
            getCode=true;
            continue;
        }
        
        if((str[i]<0x30)||(str[i]>0x39))
        {
            res=0;
            j=0;
            continue;
        }
        
        j++;
        if(once>MAX)
        {
            res=MAX;
            continue;
        }
        once=(str[i]-0x30);
        for (int z=0; z<j-1; z++) {
            once*=10;
        }

        res+=once;
    }
    
    if (j==0)
        return NA;
    if (res >= MAX)
    {
        if(code==1)
            res=MAX-1;
        else
            res=MAX;
    }
    
    return res*code;


    }
};

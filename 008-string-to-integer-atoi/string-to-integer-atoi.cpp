// Implement atoi which converts a string to an integer.
//
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
// If no valid conversion could be performed, a zero value is returned.
//
// Note:
//
//
// 	Only the space character ' ' is considered as whitespace character.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
//
//
// Example 1:
//
//
// Input: "42"
// Output: 42
//
//
// Example 2:
//
//
// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
//              Then take as many numerical digits as possible, which gets 42.
//
//
// Example 3:
//
//
// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
//
//
// Example 4:
//
//
// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical 
//              digit or a +/- sign. Therefore no valid conversion could be performed.
//
// Example 5:
//
//
// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.
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

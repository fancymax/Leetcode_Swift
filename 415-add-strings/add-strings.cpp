// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string addStrings(string num1, string num2) {
        string result(max(num1.size(), num2.size()) + 1,'0');
        long l1 = num1.size() - 1;
        long l2 = num2.size() - 1;
        long l3 = result.size() - 1;
        
        int addon = 0;
        while ((l1 >=0)||(l2 >= 0)) {
            int v1 = 0;
            if (l1 >= 0) {
                v1 = num1[l1] - '0';
            }
            
            int v2 = 0;
            if (l2 >= 0) {
                v2 = num2[l2] - '0';
            }

            
            result[l3] = '0' + (v1 + v2 + addon) % 10;
            addon = (v1 + v2 + addon) / 10;
            
            l1 -= 1;
            l2 -= 1;
            l3 -= 1;
        }
        result[l3] = addon + '0';
        
        if (result[0] == '0') {
            result.erase(0,1);
        }
        
        return result;
    }
};

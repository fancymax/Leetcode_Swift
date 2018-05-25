// There are N children standing in a line. Each child is assigned a rating value.
//
// You are giving candies to these children subjected to the following requirements:
//
//
// 	Each child must have at least one candy.
// 	Children with a higher rating get more candies than their neighbors.
//
//
// What is the minimum candies you must give?
//
// Example 1:
//
//
// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
//
//
// Example 2:
//
//
// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.
//
//


public class Solution {
    public int Candy(int[] ratings) {
        
        if(ratings.Length == 1)
        {
            return 1;
        }
        
        //left
        int[] leftCandys = new int[ratings.Length];
        int startCandy = 1;
        leftCandys[0] = 1;
        for(int i=1; i<ratings.Length; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                leftCandys[i] = ++startCandy;
            }
            else
            {
                leftCandys[i] = 1;
                startCandy = 1;
            }
        }
        //right
        int[] rightCandys = new int[ratings.Length];
        startCandy = 1;
        rightCandys[ratings.Length-1] = 1;
        for(int i=ratings.Length-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                rightCandys[i] = ++startCandy;
            }
            else
            {
                rightCandys[i] = 1;
                startCandy = 1;
            }
        }
        
        int sum = 0;
        for(int i=0; i<ratings.Length; i++)
        {
            sum += Math.Max(leftCandys[i],rightCandys[i]);
        }
        
        return sum;
        
    }
}

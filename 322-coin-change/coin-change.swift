// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
// Example 1:
//
//
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
//
// Example 2:
//
//
// Input: coins = [2], amount = 3
// Output: -1
//
//
// Note:
// You may assume that you have an infinite number of each kind of coin.
//


class Solution {
    func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        if amount == 0 {
            return 0
        }
     
        var coinNums = Array(repeating: -1, count: amount + 1)
        for coin in coins {
            if coin < amount {
                coinNums[coin] = 1
            }
            else if coin == amount {
                return 1
            }
        }
        
        var numsQueue = coins
        while !numsQueue.isEmpty {
            let val = numsQueue.first!
            numsQueue.remove(at: 0)
            
            for coin in coins {
                let newValue = coin + val
                if newValue == amount {
                    return coinNums[val] + 1
                }
                else if newValue < amount {
                    if coinNums[newValue] == -1 {
                        if coinNums[val] != -1 {
                            coinNums[newValue] = coinNums[val] + 1
                            numsQueue.append(newValue)
                        }
                    }
                }
            }
        }
        
        return -1
    }
}

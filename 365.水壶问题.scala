/*
 * @lc app=leetcode.cn id=365 lang=scala
 *
 * [365] 水壶问题
 */

// @lc code=start
object Solution {
    private def gcd(x:Int, y:Int):Int={
        if (y==0) x else gcd(y, x%y)
    }

    def canMeasureWater(x: Int, y: Int, z: Int): Boolean = {
        if(x+y<z) false
        else if(x==0||y==0) z==0||x+y==z
        else{
            z%gcd(x,y)==0
        }
    }
}
// @lc code=end


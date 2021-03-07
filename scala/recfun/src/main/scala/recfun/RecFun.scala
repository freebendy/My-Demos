package recfun

import scala.annotation.tailrec

object RecFun extends RecFunInterface {

  def main(args: Array[String]): Unit = {
    println("Pascal's Triangle")
    for (row <- 0 to 10) {
      for (col <- 0 to row)
        print(s"${pascal(col, row)} ")
      println()
    }
  }

  /**
   * Exercise 1
   */
  def pascal(c: Int, r: Int): Int = {
    if (c == 0 || c == r) 1
    else if (c > r) 0
    else pascal(c - 1 , r - 1) + pascal(c, r - 1)
  }


  /**
   * Exercise 2
   */
  def balance(chars: List[Char]): Boolean = {
    @tailrec
    def balanceInner(chars: List[Char], level: Int): Boolean = {
      if (level < 0) false
      else if (chars.isEmpty) level == 0
      else if (chars.head == '(') {
        balanceInner(chars.tail, level + 1)
      } else {
        balanceInner(chars.tail, level - 1)
      }
    }

    val newChars = chars.filter(char => char == ')' || char == '(')
    balanceInner(newChars, 0)
  }

  /**
   * Exercise 3
   */
  def countChange(money: Int, coins: List[Int]): Int = {
    def loop(money: Int, coins: List[Int]): Int = {
      if (money < 0) 0
      else if (coins.isEmpty) 0
      else if (money == 0) 1
      else loop(money, coins.tail) + loop(money - coins.head, coins)
    }

    loop(money, coins)
  }
}

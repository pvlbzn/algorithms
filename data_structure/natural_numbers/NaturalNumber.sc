import java.util.NoSuchElementException


abstract class Nat {
  def isZero: Boolean
  def pred: Nat
  def succ: Nat = new Number(this)
  def +(that: Nat): Nat
  def -(that: Nat): Nat
  override def toString: String = {
    def acc(n: Nat, s: String): String = {
      if (n.isZero) s + "Zero"
      else acc(n.pred, s + "Nat ")
    }
    acc(this, "")
  }
}


object Zero extends Nat {
  def isZero = true
  def pred = throw new NoSuchElementException("natural number can not be negative")
  def +(that: Nat): Nat = that
  def -(that: Nat): Nat =
    if
      (that.isZero) this
    else
      throw new NoSuchElementException("natural number can not be negative")
}


class Number(n: Nat) extends Nat {
  def isZero = false
  def pred = n
  def +(that: Nat): Nat = new Number(n + that)
  def -(that: Nat): Nat = if (that.isZero) this else n - that.pred
}


// Test it
val three = new Number(new Number (new Number(Zero)))
val two = new Number(new Number(Zero))

println(two + three)

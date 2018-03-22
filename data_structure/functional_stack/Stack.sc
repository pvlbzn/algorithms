/**
  * Functional list based stack implementation.
  */

import java.util.NoSuchElementException


trait List[T] {
  def isEmpty: Boolean
  def head: T
  def tail: List[T]
}


class Cons[T](val head: T, val tail: List[T]) extends List[T] {
  def isEmpty: Boolean = false
  override def toString: String = s"${head} -> ${tail}"
}


class Nil[T] extends List[T] {
  def isEmpty: Boolean = true
  def head: Nothing = throw new NoSuchElementException("Nil.head")
  def tail: Nothing = throw new NoSuchElementException("Nil.tail")
  override def toString: String = "Nil"
}


class Stack[T](val data: List[T] = new Nil[T]) {
  def push(item: T): Stack[T] = new Stack (new Cons(item, data))
  def pop: (T, Stack[T]) = (data.head, new Stack(data.tail))

  def length: Int = {
    def acc(n: Int, list: List[T]): Int = {
      if (! (list isEmpty)) acc(n+1, list.tail)
      else n
    }
    acc(0, data)
  }

  override def toString: String = s"${data}"
}


// s: Stack[Int] = 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> Nil
val s = new Stack push 5 push 4 push 3 push 2 push 1 push 0

assert((s length) == 6)

// zero: Int = 0
// stack: Stack[Int] = 1 -> 2 -> 3 -> 4 -> 5 -> Nil
val (zero, stack) = s pop

assert((stack length) == 5)

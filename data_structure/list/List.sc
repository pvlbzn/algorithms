import java.util.NoSuchElementException

/**
 * Implementation
 */
trait List[T] {
  def isEmpty: Boolean
  def head: T
  def tail: List[T]
}

class Cons[T] (val head: T, val tail: List[T]) extends List[T] {
  def isEmpty: Boolean = false

  override def toString: String = s"${head} -> ${tail}"
}

class Nil[T] extends List[T] {
  def isEmpty: Boolean = true
  def head: Nothing = throw new NoSuchElementException("Nil.head")
  def tail: Nothing = throw new NoSuchElementException("Nil.tail")

  override def toString: String = "Nil"
}

def singleton[T](elem: T): Cons[T] = new Cons[T](elem, new Nil[T])

def at[T](n: Int, list: List[T]): T = {
  if (n == 0) list.head
  else at(n-1, list.tail)
}


/**
 * Testing
 */ 
val one   = new Cons(head = 1, tail = new Nil)
val two   = new Cons(head = 2, tail = one)
val three = new Cons(head = 3, tail = two)
val four  = new Cons(head = 4, tail = three)
val five  = new Cons(head = 5, tail = four)

println(five)
println(at(2, five))

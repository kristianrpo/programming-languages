sealed trait Tree[+A]
case object Nil extends Tree[Nothing]
case class Leaf[A](value: A) extends Tree[A] //caso hoja
case class Branch[A](value: A,left:Tree[A],right:Tree[A]) extends Tree[A] //caso rama --> nodo con hijos
object arbol
{
  def apply(cadena:String): Tuple2[Tree[Char],String] =
  {
    if (cadena.charAt(0).equals('+') || cadena.charAt(0).equals('-') || cadena.charAt(0).equals('/') || cadena.charAt(0).equals('*'))
      {
        val leftt = apply(cadena.substring(1))
        val rightt = apply(leftt._2)
        (Branch(cadena.charAt(0),leftt._1,rightt._1), rightt._2)
      }
    else (Leaf(cadena.charAt(0)), cadena.substring(1))
  }

  def printear(Arbol: Tree[Char]): Unit = Arbol match
  {
    case Branch(valor,izquierda,derecha) =>
    {
      printear(izquierda)
      println(valor)
      printear(derecha)
    }
    case Leaf(valor)=> println(valor)
  }

  def operaciones(Arbol:Tree[Char]): Int = Arbol match
  {
    case Leaf(value) => value.toInt-'0'
    case Branch(value,left,right) =>
    {
      val first_position = operaciones(left)
      val second_position = operaciones(right)
      value match
      {
        case '+' => first_position + second_position
        case '-' => first_position - second_position
        case '*' => first_position * second_position
        case '/' => first_position / second_position
      }
    }
  }

  def main(args: Array[String]): Unit = {
    println("Ingrese por favor la expresion en notacion prefija: ")
    val stringg = scala.io.StdIn.readLine()
    val tuple = apply(stringg)
    println("Operacion organizada en el arbol:" )
    printear(tuple._1)
    println("El resultado es: " + operaciones(tuple._1))
  }
}

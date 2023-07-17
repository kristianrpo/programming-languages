# Programming languages
Resumen de los proyectos propuestos por el docente Johnathan Mauricio Calle Gallego en la asignatura Lenguajes de Programación de la universidad EAFIT.

# Sobre el repositorio.
En el repositorio se encuentran tres carpetas correspondientes a cada proyecto, cada una de ellas contiene el enunciado de lo propuesto por el docente y el codigo de la solución al mismo.

# Wordle C++
Wordle es un juego de palabras donde el usuario busca **adivinar** una palabra de n letras en **6 intentos**. en cada uno de estos intentos, el juego le provee pistas informativas al jugador indicando cuantas letras de la palabra del intento efectivamente corresponden a las letras de la palabra a adivinar, teniendo en cuenta su posición. **Si la letra no tiene color, significa que no está en la palabra a adivinar. Si la letra es de color amarillo, significa que aparece en la palabra a adivinar, pero no está en la posición correcta. Si la letra es de color verde, significa que está en la palabra a adivinar y está en la posicion correcta.**

Este trabajo se realizó enfocado al uso de **listas enlazadas** en C++.

Ahora bien, **sobre como usar el codigo creado:**
1. Ejecutar el archivo 'main.cpp' para el inicio del juego. Posteriormente en la consola se da la bienvenida al juego, y se elige la opción de jugar o salir del mismo.
2. Si se desea jugar, se genera una palabra automatica entre 4 y 7 caracteres, y se le pide al usuario palabras para adivinar la generada. Si se desea salir del juego, finaliza la ejecución del programa.
3. Se colorea las letras de la palabra ingresada por el usuario segun lo mencionado en el primer parrafo. Si la palabra excede el numero de caracteres, se informa el problema y no se le elimina el intento al usuario. Si advina la palabra, se colorea la misma completamente de verde y se da las felicitaciones por ganar el juego. Si no se adivina la palabra en los 6 intentos establecidos, se informa que se acabaron los intentos y se colorea la palabra a adivinar en rojo.
4. Finalmente, sea que se ganó o no el juego, se pregunta si iniciar un juego nuevo o salir para finalizar la ejecución del programa.

# Calculadora prefija SCALA
Calculadora que en lugar de utilizar la notación tradicional, en la que los operadores se colocan entre los operandos (notación infija), **se colocan los operadores antes de los operandos**.

Se utiliza un **arbol binario puramente funcional** para almacenar, organizar y valuar la expresión asignada por el usuario**.

Ahora bien, **sobre como usar el codigo creado:**
1. En la terminal: scala main.scala
2. Ingresar operación.

# Wikipedia Game PYTHON
En base a la teoria de los seis grados de separación propuesta por Frigyes Karinthy, se emula un experimento que determine si una persona esta conectada con otra persona. Esta conexión se determinará a partir de una red de contactos que se formará de manera automática con base a las personas que aparecen en las paginas de wikipedia de las personas correspondientes y sus contactos derivados.

Se realiza un grafo representado con una lista de adyasencia, donde las 'keys' son el nombre de la personas, y los 'values' son las personas con las que están relacionadas. Luego, para encontrar que existe una relación entre p1 y p2, se utiliza una **inteligencia artificial**, para almacenar los nombres de personas encontrados en toda la pagina. Si encuentra a la persona p2, finaliza el programa y muestra el camino realizado para llegar a dicha persona. De lo contrario, se realiza el mismo proceso para cada uno de los contactos, y de los que se vayan derivando a partir de el, hasta encontrar una solución (mientras no exceda el limite de busquedas establecido).

Ahora bien, **sobre como usar el codigo creado:**
1. Instalar las dependencias: requests, bs4, spacy
2. Ejecutar el archivo.
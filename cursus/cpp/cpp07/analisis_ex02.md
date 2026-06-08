# Análisis ex02: Array

## 1. ¿De qué trata el ejercicio?
El ejercicio `ex02` es el reto final y más importante del módulo 07. Trata sobre desarrollar nuestra propia **Plantilla de Clase (Class Template)** a la que llamaremos `Array<T>`. El objetivo es simular el comportamiento de un contenedor estándar de C++ (como `std::vector`), pero controlando y comprendiendo la gestión estricta de su memoria de forma manual bajo el capó.

## 2. ¿Qué vamos a aprender?
- **Plantillas de Clases:** En lugar de una simple función, definiremos la arquitectura de un objeto entero capaz de contener internamente datos de cualquier tipo `T`.
- **Forma Canónica en Tipos Genéricos:** Dominaremos la "Regla de los 3 (o 4)" aplicándola a memoria dinámica. Aseguraremos que el Constructor de Copia y la Sobrecarga de Asignación realizan un *Deep Copy* (copia profunda) impecable, algo crucial para no compartir el mismo bloque de memoria por accidente.
- **Alojamiento Dinámico Restringido:** Reforzaremos el uso de los operadores `new[]` y `delete[]`, evitando por completo cualquier fuga de memoria (memory leak), punteros colgantes o asignaciones "preventivas" no autorizadas.
- **Sobrecarga de Operadores Complejos:** Implementaremos el comportamiento del operador de corchetes `operator[]` para imitar el acceso de un array nativo clásico (`miArray[3] = 42;`).
- **Manejo Excepcional de Errores:** Diseñaremos protección activa contra el infame "Segmentation Fault" usando mecanismos `try/catch/throw` para lanzar excepciones de C++ si se intentan acceder índices fuera del tamaño reservado.

## 3. ¿Qué vamos a realizar?
Se nos solicita la carpeta `ex02/` que englobe:
1. **`Array.hpp`**: La declaración (y quizás la implementación) de nuestra plantilla de clase. A diferencia de las clases regulares de C++, en las plantillas el compilador exige ver su implementación a la vez que su declaración en los *headers*. El *subject* autoriza también el uso de un archivo `Array.tpp` anexo si deseamos aislar la lógica y dejar el `.hpp` más estético.
2. **`main.cpp`**: Pruebas robustas. Será un archivo enorme que testeará todos los escenarios: creación vacía, creación por tamaño predeterminado, validación del operador `=`, y la forzada de lanzar la excepción para comprobar que funciona.
3. **`Makefile`**: Estándar (`all`, `clean`, `fclean`, `re`) con flags `-Wall -Wextra -Werror -std=c++98`.

## 4. ¿Cómo vamos a afrontarlo? (Consideraciones Técnicas)

### a) La Estructura Interna (Atributos)
La clase requerirá minimalísticamente dos variables privadas genéricas:
- `T* _elements`: Puntero dinámico que representará nuestro vector en memoria.
- `unsigned int _size`: Entero sin signo que almacena la longitud estricta del array.

### b) El Ciclo de Vida (Reglas Canonical)
- **Constructor Vacío `Array()`**: Inicializará el objeto. El puntero `_elements` apuntará a la nada (`NULL`) y `_size` será `0`.
- **Constructor Parametrizado `Array(unsigned int n)`**: Invocará obligatoriamente a `new T[n]()`. El detalle de incluir los paréntesis `()` aquí es vital (y sugerido en un pequeño *tip* del pdf), ya que le dice al compilador de C++ que efectúe una "value-initialization". Esto asegura que si `T` es un tipo elemental (como `int`), sus elementos nazcan siendo un `0` en vez de guardar basura informática de la RAM.
- **Destructor `~Array()`**: Encargado incondicional de lanzar el `delete[] _elements`.
- **Deep Copies**: Si copiamos `A` hacia `B`, `B` debe llamar internamente a `new T[_size]` y hacer un bucle `for` para fotocopiar uno a uno los elementos de `A`. Si se modificara `A[0]` a posteriori, `B[0]` **no** deberá alterarse de ninguna forma.

### c) Reglas Estrictas del Subject
- **Asignación Preventiva Prohibida:** Si el array es de tamaño `N`, la instrucción en memoria será invariablemente `new T[N]`. Ni un byte de más.
- **`operator[]` Seguro:** Este operador es la joya del ejercicio. Dentro de él evaluaremos si el índice solicitado es `>= _size`. En caso afirmativo, se desencadenará un `throw std::exception` que bloquee el acceso ilegal antes de corromper la memoria. Definiremos además dos versiones del `operator[]`: una normal y una terminada en `const` para acomodar los *arrays* de lectura.
- **El método `size()`:** Simplemente retornará la variable `_size`. Es obligatorio que lleve la firma `const` ya que solo ojea datos sin corromper la instancia actual.

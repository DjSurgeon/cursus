# Análisis ex01: Iter

## 1. ¿De qué trata el ejercicio?
El ejercicio `ex01` se enfoca en crear una función plantilla llamada `iter` que recorra (itere) sobre los elementos de un array y aplique una función específica a cada uno de ellos. Básicamente, vamos a recrear el comportamiento del algoritmo estándar `std::for_each`, pero implementado desde cero por nosotros.

## 2. ¿Qué vamos a aprender?
- **Manejo de Arrays Genéricos:** Trabajar con punteros genéricos (`T*`) para recorrer arrays cuyo tipo exacto no se conoce hasta el tiempo de compilación.
- **Paso de Funciones como Parámetro:** Aprender a pasar una función como argumento a otra función genérica (un concepto muy común en la programación funcional que C++ permite mediante punteros a función o templates).
- **Const Correctness en Plantillas:** Este es el mayor desafío que plantea el subject ("*Think carefully about how to support both const and non-const elements...*"). Aprenderemos a manejar arrays mutables (cuyos elementos queremos cambiar) y arrays inmutables (`const T*`, que solo podemos leer) con la misma interfaz.

## 3. ¿Qué vamos a realizar?
Deberemos crear un directorio `ex01/` y entregar:
1. **`iter.hpp`**: Contendrá la implementación de la plantilla `iter`. (Dado que son plantillas, todo va en el header).
2. **`main.cpp`**: Contendrá pruebas sólidas para demostrar que `iter` funciona con distintos tipos de arrays (enteros, strings, etc.) y con diferentes tipos de funciones (constantes y no constantes).
3. **`Makefile`**: Con las reglas estándar (`all`, `clean`, `fclean`, `re`) compilando con `-Wall -Wextra -Werror -std=c++98`.

## 4. ¿Cómo vamos a afrontarlo? (Consideraciones Técnicas)

### a) Los parámetros de `iter`
El *subject* especifica explícitamente 3 parámetros:
1.  **Dirección del array:** Será un puntero, representable como genérico (`T*` o `const T*`).
2.  **Longitud del array:** Especificada como un valor constante, utilizaremos un tipo sin signo estandarizado como `size_t` o `unsigned int`.
3.  **Función a invocar:** Una función que recibe un elemento del array.

### b) El problema del `const` y el `non-const`
Para poder aplicar una función tanto a arrays de sólo lectura (`const T*`) como a arrays mutables (`T*`), y para aceptar funciones que reciben parámetros de forma variada (`T&`, `const T&` o por valor), existen dos estrategias principales en C++98:

**Estrategia 1: Parametrizar el tipo de la función (Recomendada y Robusta)**
Hacer que el tercer parámetro tenga su propio tipo genérico `Func`:
```cpp
template <typename T, typename Func>
void iter(T* array, size_t length, Func f) {
    for (size_t i = 0; i < length; ++i) {
        f(array[i]);
    }
}
```
*Por qué funciona:* El compilador deduce el tipo `Func` de manera automática, aceptando cualquier puntero a función (tome `T&` o `const T&`). Si el array es declarado como constante, el tipo deducido `T` simplemente pasará a ser `const Tipo`, logrando una adaptación perfecta.

**Estrategia 2: Sobrecargar la función `iter` con punteros estrictos**
Definir explícitamente dos versiones de `iter` para forzar las firmas de puntero a función:
```cpp
template <typename T>
void iter(T* array, size_t length, void (*f)(T&)) { ... }

template <typename T>
void iter(const T* array, size_t length, void (*f)(const T&)) { ... }
```
*Por qué funciona:* Es más rígida y cumple con forzar el uso de punteros a función. Sin embargo, puede dar problemas si la función pasada recibe argumentos por valor en lugar de por referencia, lo cual obligaría a hacer cast explícito o fallaría en la compilación.

**Conclusión:** La **Estrategia 1** suele ser la más adoptada por la comunidad C++ debido a su enorme flexibilidad, y es totalmente válida según el estándar C++98. A la hora de hacer el plan de implementación, elegiremos la que consideres más intuitiva.

### c) Testing (main.cpp)
Para probar rigurosamente esto crearemos al menos tres escenarios en el `main`:
- Un array de tipo básico (ej. `int`) modificado por una función (ej. sumarle 1 a cada elemento).
- Un array de un tipo más complejo (ej. `std::string`) y una función plantilla instanciada (tal como sugiere el subject: "*The third parameter can be an instantiated function template*") que sirva simplemente para imprimir sus elementos por consola recibiendo una referencia constante (`const T&`).
- Probar un array instanciado inicialmente como `const` para verificar que compila y que no se rompe la protección inmutable.

# Análisis del Ejercicio 02: Identify Real Type

## 1. El Objetivo del Ejercicio
El último ejercicio del módulo trata sobre el **Polimorfismo** y el uso del **Run-Time Type Information (RTTI)** en C++. El objetivo es recibir un puntero genérico (de una clase base) que no sabemos exactamente qué tiene debajo, y descubrir cuál es su "verdadero tipo" (A, B o C) en tiempo de ejecución. 

Todo esto hay que hacerlo sin usar la forma fácil (`std::typeinfo`), obligándonos a dominar el último cast de C++ que nos queda por ver: `dynamic_cast`.

## 2. El Reparto (Actores Principales)

### La clase `Base`
El subject pide que creemos una clase `Base` que solo tenga un **destructor virtual público**. 
- *¿Por qué un destructor virtual?* Porque `dynamic_cast` **solo funciona si la clase es polimórfica**. Para que una clase en C++ se considere polimórfica, debe tener al menos una función virtual. Al poner el destructor como virtual (que de todas formas es una buena práctica en clases padre), habilitamos que el compilador cree una "Vtable" (Tabla Virtual) que guarda la información de los tipos reales en tiempo de ejecución.

### Las clases derivadas (`A`, `B`, `C`)
Heredarán de `Base`. El subject especifica claramente que **NO necesitan** la forma canónica ortodoxa (Orthodox Canonical Form). Estarán vacías.

## 3. Las Tres Funciones a Implementar

### `Base* generate(void)`
Esta función debe actuar como una "fábrica aleatoria". Deberemos instanciar `new A`, `new B`, o `new C` al azar.
- *Cómo lo haremos:* Utilizaremos `std::srand` y `std::rand()` combinados con `time(NULL)` (de `<ctime>`) para generar un número aleatorio del 0 al 2, y basándonos en eso, devolveremos la clase correspondiente.

### `void identify(Base* p)` (Versión con Punteros)
- **El secreto:** Cuando aplicamos un `dynamic_cast` a un puntero, si la conversión falla (es decir, el objeto no es realmente de ese tipo), `dynamic_cast` devuelve **`NULL`**.
- *Cómo lo haremos:* Haremos una cadena de condicionales intentando castear el puntero `p` a `A*`, `B*` y `C*`. Si el resultado de `dynamic_cast<A*>(p)` no es `NULL`, ¡hemos encontrado el tipo verdadero! E imprimiremos "A".

### `void identify(Base& p)` (Versión con Referencias)
Aquí está la verdadera trampa del ejercicio:
- El subject dice: *"Usar un puntero dentro de esta versión está prohibido"*. Por tanto, no podemos hacer trampa sacando la dirección de `p` (`&p`) y llamar a la función anterior.
- **El secreto:** En C++ **no existen las referencias nulas**. Si aplicamos un `dynamic_cast` a una referencia y falla, el lenguaje no puede devolver "referencia a NULL". En su lugar, **lanza una excepción de tipo `std::bad_cast`**.
- *Cómo lo haremos:* Usaremos bloques `try...catch` de forma consecutiva. Intentaremos castear a `A&` dentro de un `try`. Si salta al `catch`, intentamos con `B&` en otro `try`, y así sucesivamente.

## 4. Reglas Estrictas a Respetar a Rajatabla
1. **Prohibido `<typeinfo>`**: El compilador fallará si detecta `#include <typeinfo>`. No podemos usar el operador `typeid(p).name()`.
2. **Forma Ortodoxa**: La clase `Base` y las derivadas no necesitan forma ortodoxa, lo que nos ahorrará tener que escribir constructores vacíos que no sirven de nada.
3. **NoLeaks**: Aunque no lo dice explícitamente en este apartado, es la regla general. Todo lo que generemos con `new` en la función `generate()` tendrá que ser eliminado con `delete` en el `main.cpp` después de ser identificado.

## 5. Resumen del Plan de Acción
1. Crear `Base.hpp`, `A.hpp`, `B.hpp`, `C.hpp` (O incluso meter A, B y C junto a Base para mayor limpieza si preferimos, aunque clases separadas siempre es mejor práctica, pero el subject no exige archivos separados para las derivadas). Lo más común y limpio aquí suele ser un archivo `Base.hpp` y otro `Base.cpp` que contenga las clases A, B y C o `Base.hpp`, `A.hpp`, etc. y un archivo con las funciones de identificación.
2. Implementar `generate` usando `std::rand`.
3. Implementar las dos versiones de `identify` (Una usando `if(NULL)` y otra usando `try/catch(std::bad_cast)`).
4. Crear un `main.cpp` que pruebe a generar varios objetos en bucle y pasarlos por ambas funciones de identificación para validar que ambas aciertan el tipo por igual.

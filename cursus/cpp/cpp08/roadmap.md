# Roadmap: C++ Module 08 - Contenedores, Iteradores y Algoritmos de la STL

## 🎯 Objetivo General
A partir de este módulo **(C++08)**, las reglas del juego cambian drásticamente. Hasta ahora, teníamos prohibido utilizar la **Standard Template Library (STL)**. Ahora, **ES OBLIGATORIO** utilizarla siempre que sea apropiado. Esto incluye:
- **Contenedores:** `std::vector`, `std::list`, `std::map`, etc.
- **Iteradores:** El puente entre contenedores y algoritmos.
- **Algoritmos:** Funciones definidas en `<algorithm>` (ej. `std::find`, `std::sort`, `std::min_element`, etc.).

**Regla de oro:** No reinventar la rueda. Si existe un algoritmo o contenedor de la STL que haga el trabajo, debemos usarlo. Implementar la lógica a mano con bucles `for` simples cuando existe un `std::algoritmo` que lo hace, será penalizado.

---

## 🛠️ Ejercicio 00: Easy find (`ex00`)

### Descripción
Crear una **función plantilla** (template) llamada `easyfind`. Esta función debe tomar como parámetros un contenedor `T` (cuyos elementos sean enteros) y un número entero a buscar. Su objetivo es encontrar la **primera ocurrencia** del número dentro del contenedor.

### Conceptos Clave
- **Templates de funciones:** Para aceptar cualquier tipo de contenedor secuencial (ej. `std::vector<int>`, `std::list<int>`, `std::deque<int>`).
- **Algoritmos de la STL:** Utilizaremos `std::find` de `<algorithm>`.
- **Iteradores:** `std::find` devuelve un iterador al elemento encontrado, o el iterador `end()` del contenedor si no lo encuentra.
- **Manejo de Errores:** Si no se encuentra el elemento, debemos lanzar una excepción (ej. `std::runtime_error` o una excepción personalizada).
- *Nota:* El subject especifica que no necesitamos soportar contenedores asociativos (como `std::map` o `std::set`) para este ejercicio.

### Plan de Acción
1. Crear `easyfind.hpp` (y opcionalmente `easyfind.tpp`) con la declaración e implementación del template.
2. Definir una excepción personalizada `NotFoundException`.
3. Implementar `easyfind` utilizando `std::find`.
4. Crear un `main.cpp` exhaustivo probando con `std::vector` y `std::list`, testeando casos de éxito y de fallo (excepciones).

---

## 📏 Ejercicio 01: Span (`ex01`)

### Descripción
Desarrollar una clase `Span` que almacene un máximo de `N` enteros. La clase podrá calcular la distancia (span) más corta y más larga entre todos los números almacenados.

### Atributos y Métodos
- Constructor que reciba el tamaño máximo (`unsigned int N`).
- `addNumber(int n)`: Añade un número. Lanza excepción si ya está lleno.
- `shortestSpan()`: Devuelve la menor diferencia entre cualesquiera dos números almacenados. (Lanza excepción si hay 0 o 1 elemento).
- `longestSpan()`: Devuelve la mayor diferencia entre cualesquiera dos números almacenados. (Lanza excepción si hay 0 o 1 elemento).
- **Sobrecarga / Template para rango:** Una función que permita añadir muchos números de golpe utilizando un rango de iteradores (ej. pasando `.begin()` y `.end()` de un `std::vector`).

### Conceptos Clave
- **Contenedores:** Usaremos internamente un `std::vector<int>` o similar para almacenar los números.
- **Algoritmos:**
  - `longestSpan`: Puede calcularse fácilmente encontrando el máximo y el mínimo del contenedor (`std::max_element` y `std::min_element`) y restándolos.
  - `shortestSpan`: La forma más eficiente (en C++98) es ordenar el contenedor (`std::sort`) y luego iterar calculando la diferencia entre elementos adyacentes, quedándonos con la menor.
- **Eficiencia:** El programa debe soportar al menos 10.000 números sin problemas de rendimiento.

### Plan de Acción
1. Crear `Span.hpp` y `Span.cpp` siguiendo la forma canónica ortodoxa.
2. Implementar `addNumber()` básico controlando el tamaño con excepciones.
3. Implementar la inserción por rango usando iteradores (puede ser un template de función miembro).
4. Implementar `longestSpan()` y `shortestSpan()` apoyándonos fuertemente en `<algorithm>`.
5. Crear un `main.cpp` que pruebe con pocos elementos y luego una prueba de estrés con 10.000 o más elementos (usando `std::rand` y `std::generate`).

---

## 🧬 Ejercicio 02: Mutated abomination (`ex02`)

### Descripción
La clase `std::stack` en C++ es un adaptador de contenedor (container adaptor). Por defecto, **no permite la iteración**. El objetivo es crear una clase `MutantStack` que se comporte exactamente igual que un `std::stack`, pero que además **exponga iteradores**.

### Conceptos Clave
- **Herencia:** `MutantStack` debe heredar de `std::stack`.
- **Anatomía de `std::stack`:** Internamente, `std::stack` utiliza un contenedor subyacente (por defecto `std::deque`) para almacenar sus datos. En la implementación estándar de C++, este contenedor interno está definido como un miembro protegido llamado `c`.
- **Iteradores:** Como tenemos acceso a `c` (por herencia), podemos exponer sus métodos `begin()`, `end()`, `rbegin()`, y `rend()` a través de nuestra clase `MutantStack`.
- **Tipado:** Deberemos usar `typedef` para exponer los tipos de iteradores del contenedor subyacente de forma limpia (`typedef typename std::stack<T>::container_type::iterator iterator;`).

### Plan de Acción
1. Crear `MutantStack.hpp` (clase plantilla) que herede de `std::stack<T>`.
2. Implementar los constructores, operador de asignación y destructor (Forma Canónica Ortodoxa).
3. Definir los alias para los iteradores (`iterator`, `const_iterator`, `reverse_iterator`, `const_reverse_iterator`).
4. Implementar los métodos `begin()` y `end()` devolviendo `this->c.begin()` y `this->c.end()`.
5. Crear un `main.cpp` utilizando el test provisto en el subject y añadiendo pruebas adicionales para asegurar su total compatibilidad con la iteración.

---

## 📋 Resumen de la estrategia general
1. **Comprender la STL a fondo:** Antes de implementar la lógica manual, buscaremos si existe algo en `<algorithm>` que lo solucione.
2. **Uso de Excepciones:** Acostumbrarnos a lanzar y atrapar excepciones para los errores lógicos (contenedor lleno, elemento no encontrado, etc).
3. **Forma Canónica Ortodoxa:** A pesar de ser templates y contenedores, no podemos olvidar la estructura básica de las clases (ex01 y ex02).
4. **Makefile y Estructura:** Mantener la organización de directorios y compilación impecable como en módulos anteriores.

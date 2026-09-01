# Roadmap: C++ Module 09 (STL)

## 📌 Introducción y Reglas Generales del Módulo

El **Módulo 09** es el culmen de tu aprendizaje de C++ en el Common Core. En este módulo nos centraremos puramente en la **Standard Template Library (STL)**, en concreto en el uso de **contenedores** y **algoritmos**.

### ⚠️ Regla de Oro (CRÍTICA)
**"Una vez que un contenedor es utilizado, no puedes usarlo para el resto del módulo."**

Esto significa que debes planificar desde el principio qué contenedores vas a usar para cada ejercicio:
- **ex00 (Bitcoin Exchange):** Requiere al menos **1** contenedor.
- **ex01 (Reverse Polish Notation):** Requiere al menos **1** contenedor (diferente al de ex00).
- **ex02 (PmergeMe):** Requiere al menos **2** contenedores (diferentes a los usados en ex00 y ex01).

> **💡 Estrategia Sugerida de Contenedores:**
> - `ex00`: `std::map` (ideal para asociar fechas con valores financieros, ya que ordena las claves y permite buscar "la fecha anterior más cercana" eficientemente con `lower_bound`).
> - `ex01`: `std::stack` (la estructura de datos natural y canónica para resolver una notación polaca inversa).
> - `ex02`: `std::vector` y `std::deque` (o `std::list`), ideales para secuencias donde implementaremos el algoritmo de ordenación manual (Ford-Johnson).

---

## 🪙 Ejercicio 00: Bitcoin Exchange (`btc`)

### Objetivo
Crear un programa que lea un archivo de entrada con fechas y valores (ej. `2011-01-03 | 3`), busque el precio del Bitcoin en esa fecha exacta (o la anterior más cercana) en una base de datos CSV (`data.csv`), y muestre el valor calculado.

### Teoría a desarrollar
1. **Lectura y Parsing de Archivos (`std::ifstream` y `std::getline`)**: Necesitas manejar lectura de archivos eficientemente, comprobando su validez (fechas correctas, rangos de números válidos).
2. **Contenedores Asociativos Árbol-Binario (`std::map`)**: Un `std::map` ordena automáticamente sus elementos por su clave (la fecha en este caso).
3. **Búsqueda Óptima (`lower_bound` / `upper_bound`)**: La lógica principal radica en buscar en el mapa. Si no encuentras la fecha exacta, el subject dicta buscar "la fecha anterior más cercana".

```cpp
// Ejemplo conceptual de cómo buscar la fecha anterior más cercana
std::map<std::string, float> db;
std::map<std::string, float>::iterator it = db.lower_bound("2011-01-04");

if (it == db.end() || it->first != "2011-01-04") {
    if (it == db.begin()) {
        // Error: No hay fechas anteriores
    }
    --it; // Retrocedemos al elemento inmediatamente inferior
}
// `it->second` contiene el ratio correcto.
```

---

## 🧮 Ejercicio 01: Reverse Polish Notation (`RPN`)

### Objetivo
Procesar una expresión matemática escrita en Notación Polaca Inversa (Postfija). Ej: `"8 9 * 9 - 9 - 9 - 4 - 1 +"` y devolver su resultado.

### Teoría a desarrollar
1. **Algoritmo de RPN**: La notación postfija se resuelve leyendo de izquierda a derecha.
   - Si es un número (token < 10): Se apila (push).
   - Si es un operador (`+`, `-`, `*`, `/`): Se desapilan los dos últimos números (pop), se realiza la operación, y se apila el resultado.
2. **Uso de LIFO (`std::stack`)**: El stack es la estructura de datos perfecta para este escenario (Last In, First Out).

```cpp
// Ejemplo conceptual del algoritmo RPN
std::stack<int> s;

// Cuando encuentras un operador (ej. '+')
if (s.size() < 2) { /* Error de sintaxis */ }
int a = s.top(); s.pop();
int b = s.top(); s.pop();
s.push(b + a); // Cuidado con el orden de operandos (especialmente en '-' y '/')
```

---

## 🧬 Ejercicio 02: PmergeMe

### Objetivo
Ordenar una secuencia de números enteros positivos (hasta 3000 o más) utilizando el **algoritmo Merge-Insert Sort (Ford-Johnson algorithm)**, implementándolo con dos contenedores distintos y mostrando la diferencia de tiempo entre ambos.

### Teoría a desarrollar
1. **Merge-Insert Sort (Algoritmo de Ford-Johnson)**: Es un algoritmo híbrido publicado en 1959. Es conocido por usar el mínimo número teórico de comparaciones posibles para ordenar una lista pequeña.
   - **Fase 1 (Agrupación)**: Emparejar los elementos de la entrada dos a dos y comparar cada par.
   - **Fase 2 (Ordenación de los grandes)**: Ordenar recursivamente la lista de los números mayores de cada par.
   - **Fase 3 (Inserción binaria)**: Insertar los números pequeños restantes en la lista ya ordenada utilizando los números de Jacobsthal para minimizar las comparaciones (búsqueda binaria `std::lower_bound`).
2. **Generics vs Plantillas (C++)**: Aunque el subject aconseja no hacer una plantilla de la función de ordenamiento (para poder adaptar la lógica a cada contenedor de forma óptima), puedes usar macros o sobrecarga si comparten lógica muy similar.
3. **Manejo del Tiempo (`clock_t` / `gettimeofday`)**: Necesitas cronometrar el proceso de ordenación y parseo con microsegundos de precisión.

```cpp
// El algoritmo Ford-Johnson es extenso, pero conceptualmente requiere:
// - Crear pares (ej. std::vector<std::pair<int, int> >)
// - Ordenar la lista principal (los mayores) iterativamente/recursivamente.
// - Insertar los menores (pendientes) basándote en la secuencia de Jacobsthal:
//   0, 1, 1, 3, 5, 11, 21, 43, 85, 171... (usada para optimizar las áreas de búsqueda binaria).
```

### Plan de Acción para PmergeMe
1. Entiende profundamente cómo funciona Ford-Johnson en papel (dibuja el diagrama de árbol).
2. Hazlo funcionar para `std::vector` primero.
3. Transfiere la misma lógica o adáptala para tu segundo contenedor (ej. `std::deque`), prestando atención a cómo funcionan los iteradores de ese contenedor.
4. Asegúrate de capturar bien el tiempo de inicio y fin incluyendo el almacenamiento inicial, como dicta el subject.

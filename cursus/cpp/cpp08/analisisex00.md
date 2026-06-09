# Análisis Exhaustivo - Ejercicio 00: Easy find

## 🎯 1. Objetivo del Ejercicio
El objetivo principal es implementar nuestra primera **función plantilla (template)** que interactúe directamente con contenedores de la STL. 
La función `easyfind` debe ser capaz de recibir **cualquier tipo de contenedor de enteros** (secuencial) y un número entero a buscar. Debe encontrar la primera ocurrencia de ese número dentro del contenedor y devolver su posición (iterador), o reportar un error si no lo encuentra.

## 🧠 2. Conceptos Teóricos Involucrados

### A. Plantillas de Funciones (Function Templates)
A diferencia de las clases plantilla, las funciones plantilla pueden deducir automáticamente el tipo de sus argumentos en tiempo de compilación.
```cpp
template <typename T>
/* tipo de retorno */ easyfind(T& container, int value);
```
Aquí `T` representará el tipo completo del contenedor, por ejemplo, `std::vector<int>` o `std::list<int>`.

### B. Iteradores (El pegamento de la STL)
Para interactuar con el contenedor genérico `T`, no podemos usar índices `[]` porque no todos los contenedores los soportan (ej. `std::list` no tiene `[]`). Debemos usar **Iteradores**.
- Un iterador marca una posición dentro del contenedor.
- Se obtienen mediante `container.begin()` y `container.end()`.
- El tipo del iterador para un contenedor `T` es `typename T::iterator`. La palabra clave `typename` es obligatoria aquí para decirle al compilador que `iterator` es un tipo anidado dentro de `T`.

### C. Algoritmos de la STL: `std::find`
El módulo 08 nos *obliga* a usar algoritmos cuando sea apropiado. Para buscar un elemento, la STL nos proporciona `std::find` en la librería `<algorithm>`.
- **Firma simplificada:** `std::find(iterator first, iterator last, const value_type& val)`
- **Comportamiento:** Busca linealmente desde `first` hasta `last`. Si encuentra el valor, devuelve un iterador apuntando a él. Si no lo encuentra, devuelve el iterador `last` (que suele ser `container.end()`).

## 🛠️ 3. Diseño e Implementación

### Firma de la Función
```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value)
```
- **Retorno:** `typename T::iterator`. Devolver un iterador es el estándar en C++ (igual que `std::find`).
- **Parámetros:** `T& container` (referencia para no copiar el contenedor) y el entero a buscar.

*(Nota: Opcionalmente se puede hacer una sobrecarga para `const T& container` que devuelva `typename T::const_iterator`, aunque para este ejercicio suele ser suficiente la versión no constante).*

### Manejo de Errores
El subject indica: *"If no occurrence is found, you can either throw an exception or return an error value of your choice."*
- **¿Retornar un valor de error?** Si devolvemos un entero, ¿qué pasa si devolvemos `-1` pero `-1` es una posición válida o el valor esperado?
- **¿Devolver `.end()`?** Es lo que hace la STL, pero el subject pide que o lancemos excepción o un valor de error.
- **La mejor opción (Excepciones):** Lanzar una excepción (ej. `std::runtime_error("Element not found")` o una clase de excepción propia como `NotFoundException`). Esto es más robusto y se alinea con el manejo de errores de C++.

## 🧪 4. Estrategia de Testing (main.cpp)

El `main.cpp` debe ser robusto y demostrar que el código funciona para diferentes contenedores.

**Casos a probar:**
1. **`std::vector<int>`:** 
   - Elemento en el medio del vector.
   - Elemento inexistente (debe atrapar excepción).
2. **`std::list<int>`:**
   - Elemento al principio.
   - Elemento al final.
3. **`std::deque<int>`** (Opcional pero recomendable).
4. **Contenedor vacío:**
   - Intentar buscar en un contenedor sin elementos.

## 📂 5. Estructura de Archivos
- `easyfind.hpp`: Contendrá la definición del template y la clase de la excepción. **(Los templates de funciones SIEMPRE se implementan en el .hpp)**.
- `easyfind.tpp` (Opcional): Si queremos separar la declaración de la implementación, aunque no es estrictamente necesario para una función tan corta.
- `main.cpp`: Toda la batería de pruebas.
- `Makefile`: Sistema de compilación estándar (Wall Wextra Werror, c++98).

---

## 🚦 Conclusión del Análisis
El `ex00` es el puente de transición hacia la programación genérica. La clave no está en escribir bucles complicados, sino en escribir un template muy limpio que utilice `std::find` y lance una excepción adecuada. Con solo un par de líneas en el `easyfind`, todo el peso recaerá sobre las pruebas en el `main.cpp`.

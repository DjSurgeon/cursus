# Análisis Exhaustivo - Ejercicio 02: Mutated abomination

## 🎯 1. Objetivo del Ejercicio
El objetivo principal es resolver una limitación de la STL. El contenedor `std::stack` (pila) es muy útil, pero por diseño **no es iterable** (no tiene iteradores `.begin()` ni `.end()`). 

Nuestra misión es crear una nueva clase llamada `MutantStack` que se comporte exactamente igual que un `std::stack` estándar, pero añadiéndole la característica faltante: **la capacidad de ser iterado**.

## 🧠 2. Conceptos Teóricos Involucrados

### A. Contenedores Adaptadores (Container Adaptors)
En C++, `std::stack`, `std::queue` y `std::priority_queue` no son contenedores reales por sí mismos. Son "adaptadores". Esto significa que por debajo utilizan un contenedor real (por defecto `std::deque` en el caso del stack) y simplemente ocultan parte de su funcionalidad para forzar un comportamiento LIFO (Last In, First Out).
Al ocultar esta funcionalidad, ocultan también los iteradores.

### B. El Atributo Protegido `c`
Si miramos el código fuente de la STL para `std::stack`, veremos algo como esto:
```cpp
template <class T, class Container = deque<T> >
class stack {
protected:
    Container c; // ¡El contenedor real subyacente!
// ...
};
```
La clave del ejercicio reside en ese atributo `c`. Al estar marcado como `protected`, si nuestra clase hereda de `std::stack`, tendremos acceso directo al contenedor real subyacente y, por tanto, a sus iteradores.

## 🛠️ 3. Diseño e Implementación

### Herencia y Templates
Nuestra clase será un template (ya que la pila puede guardar cualquier tipo de dato) y heredará del stack original:
```cpp
template <typename T>
class MutantStack : public std::stack<T>
```

### Exponiendo los Iteradores
Para que nuestra clase devuelva iteradores, primero debemos decirle al compilador qué tipo de iterador es. Usaremos `typedef` para acortar nombres larguísimos:
```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```
Esto significa: "El tipo de iterador de mi pila será el iterador del contenedor que la pila esté usando por debajo".

A partir de ahí, solo tenemos que crear los métodos `begin()` y `end()` (y sus variantes) y devolver el iterador del atributo protegido `c`:
```cpp
iterator begin() {
    return this->c.begin();
}
```

### Forma Canónica Ortodoxa
Aunque sea un template, debe respetar la forma canónica (Constructor por defecto, copia, asignación y destructor). En la herencia, esto es muy sencillo porque podemos simplemente llamar a los constructores y operadores de la clase padre (`std::stack`).

## 🧪 4. Estrategia de Testing (main.cpp)

El testing debe demostrar sin lugar a dudas que la pila iterada devuelve los valores correctos en el orden correcto.

**Casos a probar:**
1. **Prueba Base (Subject):** Copiar literalmente el bloque de código que viene en las instrucciones (página 67/68 del subject).
2. **Prueba de Equivalencia:** El subject dice: *"Si ejecutas una segunda vez reemplazando el MutantStack con, por ejemplo, un `std::list`, los dos outputs deberían ser iguales"*. Crearemos un segundo bloque en el main usando `std::list` en lugar de `MutantStack` para comparar las salidas y confirmar que son idénticas.
3. **Iteradores adicionales (Bonus/Robustez):** 
   - Probar iteradores constantes (`const_iterator`).
   - Probar iteradores inversos (`reverse_iterator`), muy útiles en pilas para leer desde el fondo.

## 📂 5. Estructura de Archivos
- `MutantStack.hpp`: Contendrá tanto la declaración de la clase (Orthodox Canonical Form) como la implementación de los métodos y templates (no es estrictamente necesario separar en `.tpp` si la clase es muy concisa, aunque se puede hacer por limpieza).
- `MutantStack.tpp` (Opcional): Si decidimos separar la implementación.
- `main.cpp`: Toda la batería de pruebas cruzadas con `std::list`.
- `Makefile`: Mismo estilo estándar.

---

## 🚦 Conclusión del Análisis
El `ex02` es un ejercicio conceptualmente elegante. No requiere escribir algoritmos complejos ni lidiar con excepciones. Se trata puramente de entender la herencia en C++, cómo la STL estructura sus adaptadores de contenedores y cómo usar `typename` y `typedef` para exponer los iteradores ocultos en las entrañas de la biblioteca estándar.

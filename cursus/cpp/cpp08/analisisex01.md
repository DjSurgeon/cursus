# Análisis Exhaustivo - Ejercicio 01: Span

## 🎯 1. Objetivo del Ejercicio
El objetivo es crear una clase llamada `Span` capaz de almacenar un máximo de `N` números enteros (`unsigned int N`). La clase debe proporcionar funcionalidad para añadir números (individualmente o en bloque) y calcular dos métricas fundamentales sobre el conjunto de datos:
- **El span más corto:** La diferencia mínima absoluta entre cualesquiera dos números del contenedor.
- **El span más largo:** La diferencia máxima absoluta entre cualesquiera dos números del contenedor.

Este ejercicio nos empuja a utilizar de forma intensiva la **STL** (Contenedores, Iteradores y Algoritmos) para lidiar eficientemente con grandes volúmenes de datos (10,000 elementos o más).

## 🧠 2. Conceptos y Arquitectura Interna

### A. Almacenamiento Interno (El Contenedor)
Aunque podríamos usar arrays dinámicos, estamos en el módulo de la STL. El candidato ideal para el almacenamiento interno es `std::vector<int>`.
- ¿Por qué `std::vector`? Porque ofrece acceso aleatorio continuo, lo que hace que los algoritmos de ordenación (`std::sort`) sean extremadamente rápidos (O(N log N)), algo crucial para buscar el "shortest span".

### B. Funciones y Algoritmos de la STL Clave
1. **Para `longestSpan()`:**
   - La distancia máxima siempre será la diferencia entre el número más grande y el número más pequeño.
   - Algoritmos a usar: `std::min_element` y `std::max_element` de `<algorithm>`.
   - *Complejidad:* O(N). Muy eficiente.

2. **Para `shortestSpan()`:**
   - La distancia más corta requiere que ordenemos el contenedor para que los números similares queden adyacentes.
   - Algoritmo 1: `std::sort(vec.begin(), vec.end())`.
   - Después de ordenar, iteraremos el vector restando los elementos adyacentes y guardaremos el valor mínimo encontrado. Podemos usar un bucle tradicional o, si queremos lucirnos, algoritmos de `<numeric>` si no estuvieran limitados (pero con un simple bucle O(N) tras el sort sobra).
   - *Complejidad:* O(N log N) debido a la ordenación.

3. **Para `addNumber()` por Rango (Bonus/Requirement avanzado):**
   - El subject nos pide explícitamente evitar llamar a `addNumber` miles de veces en un bucle.
   - Crearemos un **template de función miembro** `template <typename Iterator> void addNumber(Iterator begin, Iterator end)` que inserte un rango completo de golpe usando el método `insert()` del `std::vector`.
   - Deberemos comprobar antes con `std::distance(begin, end)` si los nuevos elementos exceden el espacio restante (`N - current_size`).

## ⚠️ 3. Manejo de Errores (Excepciones)
Cualquier comportamiento ilícito debe ser bloqueado con Excepciones de C++. Necesitaremos lanzar errores en los siguientes casos:
1. **Container Full Exception:** Cuando se llama a `addNumber` pero el contenedor ya ha alcanzado la capacidad `N`.
2. **Not Enough Elements Exception:** Cuando se llama a `shortestSpan` o `longestSpan` pero el contenedor está vacío o solo tiene 1 elemento (no se puede calcular la distancia).

## 🧪 4. Estrategia de Testing (main.cpp)

El testing de este ejercicio es crucial por las demandas de rendimiento.

**Casos a probar:**
1. **Prueba Base (Subject):** Reproducir el código del ejemplo del subject con 5 elementos exactos y comprobar que la salida coincide con la esperada.
2. **Pruebas de Excepciones:**
   - Intentar añadir un 6º elemento en un `Span(5)`.
   - Llamar a los Spans en un `Span(1)`.
3. **Prueba de Estrés (Stress Test):**
   - Crear un `Span(100000)`. (100.000 números).
   - Rellenarlo de golpe usando el `addNumber` con rango (podemos generar un `std::vector` de 100.000 números aleatorios usando `std::rand` y pasárselo de golpe a `Span`).
   - Comprobar que los spans se calculan en un tiempo casi instantáneo, sin sobrecargar la CPU.

## 📂 5. Estructura de Archivos
- `Span.hpp`: Declaración de la clase `Span` (Forma Canónica Ortodoxa obligatoria), sus excepciones anidadas y la implementación en el mismo header del template del método `addNumber` (rango).
- `Span.cpp`: Implementación de constructores, `addNumber` normal, `shortestSpan` y `longestSpan`.
- `main.cpp`: Batería de pruebas.
- `Makefile`: Mismo estilo estándar que creamos para el ex00.

---

## 🚦 Conclusión del Análisis
A diferencia del `ex00` que era solo un template genérico, el `ex01` requiere **arquitectura de clases**. El rendimiento es un factor clave aquí. Si logramos un `shortestSpan` que no tarde más de 1 o 2 segundos con 100.000 elementos, el ejercicio será un éxito rotundo. Para ello, el binomio `std::sort` y `std::vector` será nuestro mejor aliado.

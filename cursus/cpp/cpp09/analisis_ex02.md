# Análisis Exhaustivo - Ejercicio 02: PmergeMe

## 🎯 1. Objetivo del Ejercicio
El objetivo de **PmergeMe** es crear un programa que ordene una secuencia de números enteros positivos (proporcionados por argumentos de terminal) utilizando el algoritmo de **Merge-Insert Sort (Algoritmo de Ford-Johnson)**. 

Este es, con diferencia, el ejercicio más complejo de toda la piscina de C++. Las reglas obligatorias son:
1. Usar el algoritmo matemático de **Ford-Johnson**.
2. Ordenar la secuencia usando **dos contenedores distintos** (ej: `std::vector` y `std::deque` o `std::list`). No podemos usar los contenedores que ya gastamos en `ex00` (`std::map`) y en `ex01` (`std::stack`).
3. Medir el **tiempo de ejecución total** (incluyendo el parseo de datos) para cada contenedor y mostrarlo con precisión por consola, demostrando la diferencia de rendimiento entre ambos.
4. Soportar al menos **3000 números enteros**.
5. No usar una plantilla general que haga todo por igual (el subject *"aconseja fuertemente implementar el algoritmo para cada contenedor y evitar usar una función genérica"*).

## 🧠 2. Conceptos Teóricos: El Algoritmo de Ford-Johnson

El **Merge-Insert Sort** (Ford-Johnson) fue inventado en 1959. Su objetivo es ordenar una lista realizando el **mínimo número teórico de comparaciones posibles**.

El algoritmo se divide en tres fases principales. Asumamos que tenemos esta lista desordenada: `[5, 2, 9, 1, 7, 6, 8, 3, 4]`

### Fase 1: Creación de Pares y Ordenación Inicial (Agrupación)
Dividimos la secuencia en pares. Si el número de elementos es impar, el último elemento se queda "huérfano" (lo llamaremos *straggler*).
Comparamos los dos números de cada par y los ordenamos de modo que el **mayor** se quede a la derecha (o izquierda, según decidas la convención).
- Pares: `(5, 2)`, `(9, 1)`, `(7, 6)`, `(8, 3)` | *Straggler*: `4`
- Ordenando cada par internamente (mayor a la derecha): `(2, 5)`, `(1, 9)`, `(6, 7)`, `(3, 8)`

Ahora, separamos estos pares en dos listas:
- **Main Chain (S)**: Los números mayores de cada par. -> `[5, 9, 7, 8]`
- **Pendientes (Pend)**: Los números menores de cada par. -> `[2, 1, 6, 3]`

### Fase 2: Recursividad en la Main Chain
Llamamos recursivamente al algoritmo Ford-Johnson **solamente** sobre la *Main Chain* (`S`). El objetivo es que la cadena principal quede perfectamente ordenada. 
(En la práctica, esto implica seguir agrupando en pares hasta que quede 1 elemento, y luego ir desenrollando la recursividad).
- Tras la recursividad, nuestra Main Chain ordenada quedará: `[5, 7, 8, 9]`.
- Sus correspondientes números menores (Pend) siguen atados a ellos lógicamente.

### Fase 3: Inserción Binaria usando Secuencia de Jacobsthal
Ahora viene la magia. Tenemos una lista ordenada `S` (`[5, 7, 8, 9]`) y una lista de números pendientes `Pend` (`[2, 1, 6, 3]`, más el *straggler* `4`).
Hay que insertar los números de `Pend` dentro de `S` usando **Búsqueda Binaria** (`std::lower_bound`).

¿En qué orden insertamos los pendientes? Si insertamos el primero, el tamaño de `S` crece, haciendo que la búsqueda binaria para los siguientes sea más costosa.
Para minimizar el costo, Ford-Johnson dice que debemos insertarlos siguiendo los **Números de Jacobsthal**:
`0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341...`

Usamos estos números como índices para saber en qué orden procesar la lista `Pend`. Se insertan en "grupos" definidos por Jacobsthal, procesando cada grupo de atrás hacia adelante. 
Por ejemplo, si los índices Jacobsthal nos dictan insertar los elementos 3º, 2º y 1º de `Pend`, la búsqueda binaria será matemáticamente óptima.

## 📦 3. Elección de Contenedores

Debemos elegir dos contenedores.
1. **`std::vector`**: Es el estándar de facto. Al estar contiguo en memoria, la lectura, el swap de pares y la búsqueda binaria (`std::lower_bound`) son extremadamente rápidos gracias a la memoria caché de la CPU. Su talón de Aquiles es la inserción en medio, ya que tiene que desplazar toda la memoria.
2. **`std::deque`** (Double Ended Queue): Es muy similar al vector (acceso aleatorio $O(1)$), pero su memoria está fragmentada en bloques. Sus inserciones teóricas en el medio son ligeramente mejores, pero al no ser contiguo, las cachés de CPU sufren más en operaciones masivas. 
*(Nota: Aunque `std::list` permite inserciones muy rápidas en $O(1)$, **no soporta acceso aleatorio**, lo que hace que implementar Ford-Johnson y Búsqueda Binaria sea una pesadilla de iteradores en C++98. Por eso, el combo `vector` + `deque` es el rey indiscutible de este ejercicio).*

## ⏱️ 4. Medición del Tiempo
El subject especifica:
- Debemos imprimir "Before: [lista desordenada]".
- "After: [lista ordenada]".
- El tiempo que ha tardado `std::vector` (incluyendo parseo).
- El tiempo que ha tardado `std::deque` (incluyendo parseo).

Para medir microsegundos de forma precisa en C++98 (tanto en Linux como en macOS), utilizaremos la librería `<sys/time.h>` y la estructura `timeval` con la función `gettimeofday()`.

## 📂 5. Estructura del Proyecto

1. **`PmergeMe.hpp` / `PmergeMe.cpp`**: 
   - Clase en Forma Canónica.
   - Tendrá métodos separados para cada contenedor (`sortVector` y `sortDeque`) para cumplir la regla de evitar una plantilla genérica abusiva, aunque compartan la misma estructura lógica.
   - Algoritmos para generar la secuencia de Jacobsthal.
2. **`main.cpp`**:
   - Pasará `argv` a la clase.
   - La clase se encargará de cronometrar, parsear (validando duplicados y negativos), ordenar e imprimir el bloque final tal y como pide el subject.

---

## 🚦 6. Conclusión y Defensa
Este algoritmo es matemáticamente brillante pero logísticamente tedioso. El evaluador te pedirá que expliques:
1. **¿Por qué Ford-Johnson?** Para minimizar el número total de comparaciones de elementos.
2. **¿Por qué usamos Jacobsthal?** Porque al insertar en ese orden específico, optimizamos el tamaño del área de búsqueda binaria, reduciendo comparaciones en el peor de los casos.
3. **¿Por qué tarda menos el Vector que la Deque?** (Generalmente el vector aplastará a la deque en velocidad). La respuesta es el **Caché Miss / Locality of Reference**: el vector es memoria contigua, la CPU carga grandes bloques a la L1 Caché, haciendo las lecturas instantáneas. La deque está fragmentada, provocando fallos de caché.

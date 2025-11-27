# Push Swap

[![42 Project](https://img.shields.io/badge/42-Project-00babc?style=flat-square&logo=42)](https://github.com/DjSurgeon/push_swap)
[![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=flat-square)](https://github.com/42School/norminette)

**Algoritmo de ordenamiento optimizado para estructuras de datos stack con operaciones restringidas.**

Proyecto desarrollado como parte del currículum de 42 Madrid - Fundación Telefónica, enfocado en la implementación eficiente de algoritmos de ordenamiento bajo restricciones específicas.

---

## Índice

1. [Descripción](#descripción)
2. [Requisitos del sistema](#requisitos-del-sistema)
3. [Instalación](#instalación)
4. [Uso](#uso)
5. [Arquitectura del proyecto](#arquitectura-del-proyecto)
6. [Operaciones permitidas](#operaciones-permitidas)
7. [Algoritmos implementados](#algoritmos-implementados)
8. [Análisis de complejidad](#análisis-de-complejidad)
9. [Validación de entrada](#validación-de-entrada)
10. [Autor](#autor)

---

## Descripción

Push Swap es un proyecto que implementa un algoritmo de ordenamiento para números enteros utilizando dos stacks (pilas) y un conjunto limitado de operaciones. El objetivo es ordenar una secuencia de números en el menor número de movimientos posible.

### Objetivo

Dado un stack A con números desordenados y un stack B inicialmente vacío, el programa debe generar la secuencia óptima de operaciones para ordenar los números en el stack A en orden ascendente.

### Desafío técnico

- **Restricción de operaciones**: Solo se permiten operaciones específicas de stack (swap, push, rotate, reverse rotate)
- **Optimización**: Minimizar el número de operaciones necesarias
- **Adaptabilidad**: Implementar diferentes estrategias según el tamaño del conjunto de datos

---

## Requisitos del sistema

- **Sistema operativo**: Linux (probado en Ubuntu 24.04)
- **Compilador**: `gcc` o `cc` con soporte para C99
- **Make**: GNU Make 4.0 o superior
- **Dependencias**: libft (librería estática personalizada de 42)

---

## Instalación

```bash
# Clonar el repositorio
git clone https://github.com/DjSurgeon/push_swap.git
cd push_swap

# Compilar el proyecto
make

# El ejecutable push_swap se generará en el directorio raíz
```

### Comandos de compilación

```bash
make        # Compila el proyecto
make clean  # Elimina archivos objeto
make fclean # Elimina archivos objeto y ejecutable
make re     # Recompila el proyecto desde cero
```

---

## Uso

### Sintaxis básica

```bash
./push_swap [números]
```

### Validación con checker

El proyecto incluye `checker_linux`, una herramienta para validar que la secuencia de operaciones ordena correctamente el stack:

```bash
# Generar operaciones y validarlas
./push_swap 3 2 1 | ./checker_linux 3 2 1
OK

# Ejemplo con error
echo "sa\npb" | ./checker_linux 3 2 1
KO
```

### Ejemplos

```bash
# Argumento único con varios números
./push_swap "3 2 5 1 4"

# Múltiples argumentos
./push_swap 3 2 5 1 4

# Números negativos
./push_swap -5 2 -1 8 3

# Con espacios adicionales (se procesan correctamente)
./push_swap "  3   2    5  1   4  "
```

### Salida

El programa imprime en la salida estándar la secuencia de operaciones necesarias para ordenar los números:

```bash
$ ./push_swap 3 2 1
sa
rra

$ ./push_swap 5 4 3 2 1
pb
pb
sa
pa
pa
```

---

## Arquitectura del proyecto

### Estructura de datos

El proyecto utiliza una estructura de lista enlazada simple para implementar los stacks:

```c
typedef struct s_stack
{
    int             value;      // Valor original del número
    int             index;      // Índice normalizado (0 a n-1)
    struct s_stack  *next;      // Puntero al siguiente nodo
}                   t_stack;
```

**Características:**
- **value**: Almacena el número original ingresado por el usuario
- **index**: Posición relativa en el ordenamiento final (0 = menor, n-1 = mayor)
- **next**: Puntero al siguiente elemento (NULL si es el último)

Esta estructura permite:
- Operaciones O(1) en el tope del stack (push, pop, swap)
- Rotaciones eficientes recorriendo la lista
- Indexación para optimizar el algoritmo K-Sort

### Estructura de archivos

```
push_swap/
├── Makefile                    # Sistema de compilación
├── README.md                   # Documentación del proyecto
├── checker_linux               # Herramienta de validación (binario)
│
├── include/
│   └── push_swap.h             # Definiciones, estructuras y prototipos
│
├── src/                        # Código fuente principal
│   ├── main.c                  # Punto de entrada del programa
│   ├── create_array.c          # Parseo de argumentos desde línea de comandos
│   ├── check_array.c           # Validación de entrada (duplicados, formato)
│   ├── create_stack.c          # Creación e inicialización de stacks
│   ├── free_array.c            # Liberación de memoria de arrays
│   ├── free_stack.c            # Liberación de memoria de stacks
│   │
│   ├── ps_push.c               # Implementación de operaciones pa/pb
│   ├── ps_swap.c               # Implementación de operaciones sa/sb/ss
│   ├── ps_rotate.c             # Implementación de operaciones ra/rb/rr
│   ├── ps_reverse.c            # Implementación de operaciones rra/rrb/rrr
│   │
│   ├── sort_bubble.c           # Algoritmo auxiliar (sorting de índices)
│   ├── sort_selection.c        # Algoritmos para conjuntos pequeños (2-5 elementos)
│   ├── sort_k.c                # Algoritmo K-Sort para conjuntos grandes
│   └── sort_utils.c            # Funciones auxiliares de ordenamiento
│
├── libft/                      # Librería estática personalizada (42)
│   ├── Makefile                # Compilación de libft
│   ├── libft.a                 # Librería compilada
│   ├── include/
│   │   └── libft.h             # Cabecera de libft
│   └── src/                    # Implementaciones (65 funciones)
│       ├── ft_atoi.c           # Conversión string a int
│       ├── ft_atol.c           # Conversión string a long
│       ├── ft_split.c          # División de strings
│       ├── ft_printf.c         # Implementación de printf
│       ├── ft_sqroot.c         # Cálculo de raíz cuadrada
│       ├── ft_isdigit.c        # Validación de dígitos
│       ├── ft_isspace.c        # Validación de espacios
│       ├── get_next_line.c     # Lectura de líneas
│       └── ...                 # Funciones de manipulación de memoria y strings
│
└── build/                      # Archivos objeto (generados por make)
    └── *.o
```

### Componentes principales

El proyecto está organizado modularmente con separación clara de responsabilidades según la arquitectura definida en `push_swap.h`:

#### 1. **Parsing and Validation Module** (Módulo de análisis y validación)
- `create_array.c`: 
  - `argument_to_array()`: Parseo de argumentos desde línea de comandos
  - `char_array_to_int_array()`: Conversión y validación de strings a enteros
- `check_array.c`: 
  - `check_array()`: Validación exhaustiva (duplicados, formato, desbordamiento)
  - Detección de errores: números inválidos, fuera de rango, duplicados
- `create_stack.c`: 
  - `create_stack()`: Construcción de estructuras de datos stack (lista enlazada)
- `free_array.c` / `free_stack.c`: 
  - `free_array_c()` / `free_stack()`: Gestión de memoria y prevención de leaks

#### 2. **Stack Operations Module** (Implementación de las 11 operaciones permitidas)

Cada operación implementa la lógica del subject con flag `bool print` para control de salida:

- `ps_push.c`: 
  - `ps_push_a()`: Transferencia de B → A
  - `ps_push_b()`: Transferencia de A → B
  
- `ps_swap.c`: 
  - `ps_swap_a()`: Intercambio de primeros 2 elementos en A
  - `ps_swap_b()`: Intercambio de primeros 2 elementos en B
  - `ps_swap_ss()`: Ejecuta `sa` y `sb` simultáneamente
  
- `ps_rotate.c`: 
  - `ps_rotate_a()`: Desplazamiento ascendente en A (primero → último)
  - `ps_rotate_b()`: Desplazamiento ascendente en B
  - `ps_rotate_rr()`: Ejecuta `ra` y `rb` simultáneamente
  
- `ps_reverse.c`: 
  - `ps_reverse_a()`: Desplazamiento descendente en A (último → primero)
  - `ps_reverse_b()`: Desplazamiento descendente en B
  - `ps_reverse_rr()`: Ejecuta `rra` y `rrb` simultáneamente

#### 3. **Sorting Algorithms Module** (Algoritmos de ordenamiento)

- `sort_selection.c`: 
  - Estrategias optimizadas para 2-5 elementos
  - `check_sort()`: Determina qué algoritmo usar según tamaño
  - `is_sort()`: Verifica si el stack está ordenado
  
- `sort_k.c`: 
  - `k_sort()`: Implementación del algoritmo K-Sort para conjuntos grandes
  - Distribución en rangos y reconstrucción ordenada
  
- `sort_bubble.c`: 
  - `add_correct_index()`: Indexación normalizada (0 a n-1)
  - Mapeo de valores a índices para optimización
  
- `sort_utils.c`: 
  - `stack_size()`: Cálculo del tamaño del stack
  - `max_stack_index()` / `min_stack_value()`: Búsqueda de extremos
  - `rb_count()`: Cálculo de rotaciones óptimas

#### 4. **Libft - Librería estática personalizada**

La librería incluye 65 funciones implementadas desde cero como parte del currículum de 42:

**Funciones clave utilizadas en Push Swap:**
- `ft_atol()`: Conversión segura de strings a long (detección de desbordamiento)
- `ft_split()`: Parseo de argumentos con múltiples números
- `ft_isdigit()` / `ft_isspace()`: Validación de caracteres
- `ft_sqroot()`: Cálculo de raíz cuadrada para el algoritmo K-Sort
- `ft_printf()`: Salida formateada de operaciones
- Funciones de listas enlazadas (`ft_lst*`): Gestión de estructuras de stack
- `ft_strlen()`, `ft_strdup()`, `ft_strjoin()`: Manipulación de strings

#### 5. **Sistema de compilación (Makefile)**

El sistema de compilación está estructurado de la siguiente manera:
```makefile
SRC_DIR    := src          # Código fuente (*.c)
INC_DIR    := include      # Cabeceras (*.h)
OBJ_DIR    := build        # Archivos objeto (*.o)
LIBFT_DIR  := libft        # Librería estática
```

**Configuración del compilador**
```makefile
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIBFT_DIR)
```

- `-Wall -Wextra`: Habilita advertencias adicionales del compilador
- `-Werror`: Trata todas las advertencias como errores
- `-g`: Genera información de depuración para herramientas como GDB
- `-I<directorio>`: Añade directorios a la búsqueda de cabeceras

**Proceso de compilación**

1. **Compilación de libft**: Se invoca `make` en el directorio `libft/` para generar `libft.a`
2. **Compilación de archivos fuente**: Cada archivo `src/*.c` se compila a `build/*.o`
3. **Enlazado**: Los archivos objeto se enlazan con `libft.a` para generar el ejecutable `push_swap`

---

## Operaciones permitidas

El programa puede ejecutar las siguientes operaciones sobre los stacks:

### Operaciones de intercambio (swap)

- **`sa`** (swap a): Intercambia los dos primeros elementos del stack A
- **`sb`** (swap b): Intercambia los dos primeros elementos del stack B
- **`ss`**: Ejecuta `sa` y `sb` simultáneamente

### Operaciones de transferencia (push)

- **`pa`** (push a): Toma el primer elemento de B y lo coloca primero en A
- **`pb`** (push b): Toma el primer elemento de A y lo coloca primero en B

### Operaciones de rotación (rotate)

- **`ra`** (rotate a): Desplaza todos los elementos de A una posición hacia arriba (el primero se convierte en el último)
- **`rb`** (rotate b): Desplaza todos los elementos de B una posición hacia arriba
- **`rr`**: Ejecuta `ra` y `rb` simultáneamente

### Operaciones de rotación inversa (reverse rotate)

- **`rra`** (reverse rotate a): Desplaza todos los elementos de A una posición hacia abajo (el último se convierte en el primero)
- **`rrb`** (reverse rotate b): Desplaza todos los elementos de B una posición hacia abajo
- **`rrr`**: Ejecuta `rra` y `rrb` simultáneamente

**Nota**: Las operaciones no realizan ninguna acción si el stack está vacío o tiene menos elementos de los necesarios.

---

## Algoritmos implementados

La implementación utiliza diferentes estrategias de ordenamiento según el tamaño del conjunto de datos de entrada.

### Algoritmos para conjuntos pequeños

#### Stack de 2 elementos

Estrategia directa mediante comparación:
- Si `A[0] > A[1]`: ejecutar `sa`
- Complejidad: O(1)

#### Stack de 3 elementos

Algoritmo optimizado que considera las 6 permutaciones posibles (una ya ordenada):

```
Casos posibles:
[3,2,1] → sa + rra
[3,1,2] → ra
[2,3,1] → rra
[2,1,3] → sa
[1,3,2] → sa + ra
[1,2,3] → (ordenado)
```

- Máximo de movimientos: 2
- Complejidad: O(1)

#### Stack de 5 elementos

Estrategia de reducción:

1. Identificar los dos elementos más pequeños
2. Transferir el menor elemento a B (`pb`)
3. Transferir el segundo menor a B (`pb`)
4. Aplicar algoritmo de 3 elementos en A
5. Devolver elementos de B a A en orden (`pa`, `pa`)

- Máximo de movimientos: ~12
- Complejidad: O(1)

### K-Sort: Algoritmo principal para conjuntos grandes

El K-Sort es una adaptación del algoritmo Radix Sort optimizada para trabajar con stacks y operaciones restringidas.

#### Fundamento matemático

El algoritmo utiliza indexación normalizada y distribución en rangos:

**Cálculo del rango óptimo:**
```c
range = sqrt(size) * 1.3
```

Donde:
- `size`: Número de elementos del stack
- `1.3`: Factor de optimización empírico
- `range`: Determina cuántos elementos se procesan por ronda

Este cálculo balancea el número de pasadas con la eficiencia por operación. Un rango muy pequeño genera muchas iteraciones; un rango muy grande produce distribuciones ineficientes.

#### Fase 1: Indexación y distribución

**Indexación de elementos**

Los valores originales se mapean a índices normalizados (0 a n-1) según su posición en el orden final:

```
Valores originales:  [5, 2, 8, 1, 9, 3, 7, 4, 6]
Índices asignados:   [4, 1, 7, 0, 8, 2, 6, 3, 5]
```

**Distribución en rangos**

Para `size = 9`: `range = sqrt(9) * 1.3 = 3.9 ≈ 4`

Proceso iterativo (para cada incremento `i` del rango):

```
i = 0, rango actual = [0, 4]
┌─────────────────────────────────────────┐
│ Para cada elemento en A:                │
│  ┌──────────────────────────────────────┤
│  │ Si índice ≤ i:                       │
│  │   pb + rb (push y rotar B)           │
│  │ Si índice ≤ (i + range):             │
│  │   pb (solo push)                     │
│  │ Si índice > (i + range):             │
│  │   ra (rotar A)                       │
│  └──────────────────────────────────────┤
└─────────────────────────────────────────┘
```

Resultado: Los elementos se distribuyen gradualmente de A a B, con los menores cerca del fondo de B y los mayores cerca del tope.

#### Fase 2: Reconstrucción ordenada

El stack B contiene elementos semi-ordenados. La estrategia es extraerlos en orden descendente (del mayor al menor) hacia A:

**Proceso iterativo:**

1. **Identificar el elemento con mayor índice** en B
2. **Calcular la posición óptima de rotación:**
   - Posición desde arriba: `pos`
   - Posición desde abajo: `size_b - pos`
   - Elegir el camino con menos operaciones
3. **Rotar B** hasta colocar el elemento al tope:
   - `rb` (rotate) si está en la mitad superior
   - `rrb` (reverse rotate) si está en la mitad inferior
4. **Transferir a A:** `pa`
5. **Repetir** hasta vaciar B

**Ejemplo de reconstrucción:**

```
Stack B: [3, 7, 1, 5, 9, 2]  (índices)
         ↑
         tope

Iteración 1: Buscar índice 9 (mayor)
  → Posición 4 (desde arriba)
  → Ejecutar: rb, rb, rb, rb, pa

Stack B: [3, 7, 1, 5, 2]
Stack A: [9]

Iteración 2: Buscar índice 7
  → Posición 1
  → Ejecutar: rb, pa

Stack B: [3, 1, 5, 2]
Stack A: [7, 9]

[continúa hasta vaciar B...]
```

#### Complejidad temporal

- **Mejor caso**: O(n√n) - distribución uniforme
- **Caso promedio**: O(n√n)
- **Peor caso**: O(n²) - degeneración rara debido a indexación normalizada

---

## Análisis de complejidad

### Rendimiento observado

| Tamaño del conjunto | Movimientos promedio | Complejidad teórica |
|--------------------:|---------------------:|--------------------:|
| 3 números           | ≤ 3                  | O(1)                |
| 5 números           | ≤ 12                 | O(1)                |
| 100 números         | ~585                 | O(n√n)              |
| 500 números         | ~5,201               | O(n√n)              |

### Comparación con límites del proyecto (42)

Los límites establecidos para aprobar el proyecto son:

- **100 números**: < 700 movimientos → **Resultado: 585 (16% mejor)**
- **500 números**: < 5500 movimientos → **Resultado: 5,201 (5% mejor)**

---

## Validación de entrada

El programa implementa un sistema robusto de validación que detecta múltiples tipos de errores.

### Errores detectados

#### 1. Formato inválido de números

```bash
./push_swap 2 six 9              # Error: contiene texto
./push_swap 1 ++3 35 80 -3       # Error: múltiples signos
./push_swap hello                # Error: no es un número
./push_swap 1 2 s3 5 67b778      # Error: mezcla de dígitos y letras
./push_swap "12asd 4 6 8"        # Error: formato inválido
./push_swap 1 --45 32            # Error: doble signo negativo
```

#### 2. Desbordamiento de enteros

El programa solo acepta valores dentro del rango de `int` en C:

```bash
./push_swap 54867543867438 3           # Error: > INT_MAX
./push_swap -2147483647765 4 5         # Error: < INT_MIN
./push_swap 3 2 1 18446744073709551615 # Error: desbordamiento
```

Rango válido: `[-2147483648, 2147483647]`

#### 3. Argumentos vacíos

```bash
./push_swap ""                   # Error: argumento vacío
./push_swap "     "              # Error: solo espacios
```

#### 4. Números duplicados

```bash
./push_swap 2 8 2                # Error: 2 duplicado
./push_swap 007 98 7             # Error: 007 y 7 son el mismo número
```

### Manejo de errores

Cuando se detecta cualquier error de validación:
- El programa imprime `Error\n` en la salida de errores estándar (`stderr`)
- Retorna con código de salida `1`
- No ejecuta ninguna operación de ordenamiento

**Ejemplo:**
```bash
$ ./push_swap 1 2 3 2
Error
$ echo $?
1
```

---

## Autor

**Sergio Jiménez**

- GitHub: [@DjSurgeon](https://github.com/DjSurgeon)
- LinkedIn: [sergiojimenez42dev](https://www.linkedin.com/in/sergiojimenez42dev/)
- Proyecto: [Push Swap Repository](https://github.com/DjSurgeon/push_swap)

---

## Recursos y referencias

### Herramientas de validación y testing

- **Checker incluido**: `checker_linux` - Validador oficial de 42
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - Visualización gráfica del algoritmo
- [Push Swap Tester](https://github.com/lmalki-h/push_swap_tester) - Suite de tests automatizados

### Referencias técnicas

- [42 School - Norminette](https://github.com/42School/norminette) - Estándar de código de 42
- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm) - Teoría de algoritmos de ordenamiento
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) - Fundamentos de stacks

---

*Proyecto desarrollado como parte del currículum de 42 Madrid - Fundación Telefónica*
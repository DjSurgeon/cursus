# Push Swap

El propósito de este proyecto es organizar un stack (pila) de números desordenados en la menor cantidad de movimientos, dados unos movimientos prefijados.

```bash
Push_swap
 ├── Makefile
 ├── src/
 │    └── main.c
 │    └── create_array.c
 │    └── check_array.c
 ├── libft/
 │    └── .all_libft_archives
 ├── include/
 │    └── push_swap.h
```
## Makefile

```Makefile
# Directories ================================================================ #

SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR		:= build
LIBFT_DIR	:= libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a
```
- **src**: Carpeta sdonde se incluye el código fuente del programa (*.c)
- **include**: Carpeta donde se incluyen las cabeceras del programa (*.h)
- **build**: Carpeta donde se guardarán los archivos objeto del programa (*.o)
- **libft**: Carpeta donde se encuentra la librería estática para poder trabajar.

```Makefile
# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIBFT_DIR)
```
- **cc**: Compilador estándar en sistemas basador en Unix y Linux
- -**Wall** -**Wextra**: Habilita advertencias adicionales
- -**Werror**: Trata las advertencias como errores
- -**g**: Genera información de depuración
- -**I<directorio>**: Flag para poder añadir carpetas a la búsqueda de cabeceras.

```Makefile
# Files ====================================================================== #

SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)
```

- `$(wildcar $SRC_DIR)/*.c`: busca todos los `*.c` dentro de la carpeta `src`

```Makefile
# Objects ===================================================================== #

OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
```

- `$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))`: toma cada ruta de archivo fuente en src/ (src/main.c) y genera la correspondiente ruta de objeto en build/ (build/main.o).

```Makefile
# Rules ====================================================================== #

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
```

- `all`: Primero se construye la librería estática `libft.a` y luego el ejecutable `push_swap`.
- `(LIBFT_A)`: Invoca `make` dentro del directorio `libft/`, construyendo la librería estática.
- `$(NAME): $(OBJ_FILES)`: Enlaza todos los archivos objeto `($(OBJ_FILES))` con la librería estática `$(LIBFT_A)` para generar el ejecutable `push_swap`.
- `$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h`: Regla de patrón para compilar cualquier `%.c` dentro de `src/` a su correspondiente `%.o` dentro de `build/`.
- `@mkdir -p $(OBJ_DIR)`: crea la carpeta `build/` si no existe.

## Parseo

El primer paso del programa sera analizar los argumentos que se pasan por la terminal y gestionar los errores posibles.
El programa sera capaz de gestionar los argumentos como uno sólo.
- `./push_swap "81 22 35 44"`: argumento correcto.

O como varios argumentos.
- `./push_swap 31 74 46 08`: argumento correcto.

### Manejo de errores

Cada vez que el programa detecta que los argumentos no son los correctos, deberá mostrar `Error\n` en la salida de errores estándar.

El programa no aceptara argumentos que no sean numeros enteros correctamente formateados (con un solo signo delante del digito).

- `./push_swap 2 six 9`
- `./push_swap 1 ++3 % 35 80 -3`
- `./push_swap hello`
- `./push_swap 1 2 s3 5 67b778 947`
- `.push_swap " 12asd 4 6 8 54 4354"`
- `./push_swap 1     --45 32`

El programa no aceptara numeros por encima o por debajo de los limites del INT_MAX y INT_MIN.

- `./push_swap 54867543867438 3`
- `./push_swap -2147483647765 4 5`
- `./push_swap 3 2 1 18446744073709551615`

El programa no aceptara argumentos "vacios".

- `./push_swap ""`
- `./push_swap "     "`

El programa no aceptara ningún nñumero duplicado.

- `./push_swap 2 8 2`
- `./push_swap 007 98 7`

## Algoritmos

Dependiendo de la cantidad de elementos a colocar el programa elegira el algoritmo de ordenación más optimo.

### Pequeños algoritmos

Para tamaños entre 2 y 5 elementos.
- Para un stack de 2 elementos, se ejecuta una comparación directa entre los elementos y se ejecuta un swap a (sa) si es necesario.
- Para un stack de 3 elementos, sólamente existen 6 posibles permutaciones, una de las cuales ya está ordenada. Por lo que se calculan las otras 5 posibilidades y se ejecuta la mas optima.
- Para un stack de 5 elementos, se buscan los dos elementos más pèqueños del stack y pasan en orden al stack B, primero el menor y depues el segundo menor. Una vez que en el stack hay 3 elementos se ejecuta el algoritmo de 3 elementos y una vez ordenados se devuelven los elementos del stack B al A.

### K-sort

El K-Sort es un algoritmo de ordenamiento especializado diseñado para trabajar con estructuras de datos de tipo stack (pila) con operaciones limitadas. Es una adaptación inteligente del algoritmo Radix Sort optimizada para el contexto de ordenamiento con dos stacks y operaciones restringidas.

Uno de los elementos mas importantes es el tamaño o rango en el que se dividen los elementos.
```c
int	range;
int size;
range = ft_sqroot(size) * (13 / 10);
// size es el número de elementos del stack
// 1.3 es un factor de optimización
// range determina cuántos elementos procesamos cada ronda
```
El calculo del rango es fundamental para optimizar el número de operaciones, si el rango es muy pequeño se producirian muchas operaciones, si en cambio es demasiado grande la distribucion podria ser ineficiente.

#### Paso 1

Indexación de los elementos y distribucion en rangos.

| Stack | valores / indices |
| --- | --- |
| Stack A (valores): | [5, 2, 8, 1, 9, 3, 7, 4, 6] |
| ↓ Indexación ↓ |
| Stack A (indices): | [4, 1, 7, 0, 8, 2, 6, 3, 5] |

Rango = √9 * 1.3 = 3 * 1.3 = 4

Proceso:

| i=0 | range=4 | movimiento |
| --- | --- | --- |
| ¿elemento ≤ 0? | Sí | Push B + Rotate B |
| ¿elemento ≤ 4? | Sí | Push B |
| ¿elemento > 4? | Sí | Rotate A |

#### Paso 2

Reconstruccion ordenada.

Se busca el elemento con el indice mas alto. Se calcula la cantidad de rotaciones que se necesitan para colocarlo el primero y enviarlo al stack A. La busqueda del elemento ira iterando hasta vaciar el stack B.
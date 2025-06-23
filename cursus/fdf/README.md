# FDF

Este proyecto, conocido como **FDF** (del francés '*fil de fer*' o 'modelo de estructura alámbrica'), es una iniciativa fundamental en el campo de la programación gráfica. Su objetivo principal es la creación y visualización de un paisaje tridimensional mediante un modelo de estructura alámbrica, conectando puntos definidos por coordenadas (x, y, z) a través de segmentos de línea. Este trabajo sirve como una introducción práctica a la programación gráfica básica, familiarizando al desarrollador con la biblioteca **MiniLibX** y conceptos esenciales como la gestión de ventanas, la creación de imágenes y la manipulación de eventos de teclado y ratón.

Ls principales carácteristicas del proyecto son:
- Renderizado de un paisaje 3D a partir de un archivo `*.fdf`.
- Implementación obligatoria de una proyección isométrica.
- Gestión interactiva de la ventana gráfica.

## Conceptos iniciales

### Wireframe Modelling o Modelado de Estructura Alámbrica

El modelado de estructura alámbrica es una técnica de renderización en gráficos 3D que representa objetos mediante la visualización de sus aristas o 'segmentos de línea' (*edges*), sin rellenar las superficies. Esto resulta en una imagen **semitransparente** donde la estructura interna del objeto es visible. Para FDF, esto implica conectar cada punto (x, y, z) con sus vecinos adyacentes para formar una malla visible. Esta técnica es valorada en proyectos gráficos iniciales por su simplicidad computacional, ya que evita la complejidad de los algoritmos de renderizado de superficies.

### Proyecciones Geométricas

Las proyecciones geométricas son métodos matemáticos utilizados para transformar objetos **tridimensionales** en una representación **bidimensional**, permitiendo su visualización en una pantalla.

#### Proyección Ortográfica

Representa objetos mediante vistas separadas (frontal, superior, lateral), proyectando los puntos perpendicularmente a un plano. No hay efecto de perspectiva, y las líneas paralelas permanecen paralelas. Aunque no es la proyección principal de FDF, es fundamental para entender la base de las proyecciones paralelas.

#### Proyeccion Isométrica

Es una **proyección paralela** donde los **tres ejes** principales (X, Y, Z) forman **ángulos de 120 grados** entre sí. Las líneas paralelas a estos ejes se dibujan a la misma escala, sin puntos de fuga. Esta proyección es la obligatoria para el renderizado del modelo en FDF. Se elige por su capacidad de ofrecer una percepción de profundidad sin la complejidad computacional de la perspectiva real, lo que la hace ideal para un proyecto gráfico introductorio que se enfoca en las transformaciones 3D básicas.

#### Perspectiva

Intenta **simular la visión humana**, donde los objetos se hacen más pequeños a medida que se alejan del observador. Requiere uno o más puntos de fuga donde las líneas paralelas convergen. En FDF, la implementación de la perspectiva es una característica extra (bonus) , lo que subraya su mayor complejidad computacional y su naturaleza opcional.

## Estructura del proyecto

```bash
fdf/
├── libft/
│   └── .all libft archives 
├── minilibx-linux/
│   └── .all minilibx archives 
├── include/
│   └── fdf.h
├── src/
│   ├── main.c
│   ├── parser.c
│   ├── draw.c
│   ├── bresenham.c
│   ├── projection.c
│   ├── controls.c
├── Makefile
```

## Makefile

```Makefile
# Directories ================================================================ #

SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR		:= build
LIBFT_DIR	:= libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a
MLX_DIR		:= minilibx-linux
```
- **src**: Carpeta donde se incluye el código fuente del programa (*.c)
- **include**: Carpeta donde se incluyen las cabeceras del programa (*.h)
- **build**: Carpeta donde se guardarán los archivos objeto del programa (*.o)
- **libft**: Carpeta donde se encuentra la librería estática para poder trabajar.
- **mlx**: Carpeta donde se encuentra la minilibx en su version Linux para la biblioteca gráfica.

```Makefile
# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS		:= -lm
MLXFLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11
```
- **cc**: Compilador estándar en sistemas basador en Unix y Linux
- -**Wall** -**Wextra**: Habilita advertencias adicionales
- -**Werror**: Trata las advertencias como errores
- -**g**: Genera información de depuración
- -**I<directorio>**: Flag para poder añadir carpetas a la búsqueda de cabeceras.
- -**lm**: Para la libreria math.h el compilador sabe la firma de las funciones, pero la implementacion está en la libreria matematica `libm`. `-l<nombre>` busca y enlaza con la libreria `-lm` => `libm`.
- -**lmlx**: busca `libmlx.a` en `minilibx-linux/`
- -**lXext** -**lX11**: flags necesarias para X11
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
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME) $(MLXFLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fdf.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
```

- `all`: Primero se construye la librería estática `libft.a` y luego el ejecutable `./fdf`.
- `(LIBFT_A)`: Invoca `make` dentro del directorio `libft/`, construyendo la librería estática.
- `$(MAKE) -C $(MLX_DIR)`: Invoca make dentro de la carpeta de la minilibx.
- `$(NAME): $(OBJ_FILES)`: Enlaza todos los archivos objeto `($(OBJ_FILES))` con la librería estática `$(LIBFT_A)` para generar el ejecutable `./fdf`.
- `$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fdf.h`: Regla de patrón para compilar cualquier `%.c` dentro de `src/` a su correspondiente `%.o` dentro de `build/`.
- `@mkdir -p $(OBJ_DIR)`: crea la carpeta `build/` si no existe.

## fdf.h

### <stdlib.h>

Utilizado para la funciones de reserva de memoria y control de flujo.

- `malloc(size_t size)`: Reserva `size` bytes en el heap y devuelve un puntero.
- `free(void *ptr)`: Libera la memoria previavemente reservada con `malloc`
- `exit(int status)`: Termina inmediatamente el proceso con el código de salida `status`

### <fcntl.h>

Biblioteca necesaria para realizar operaciones sobre los file descriptors.

- `open(const char *path name, int flags)`: Abrir (o crear) un fichero y obtener un file descriptor (entero) para operaciones posteriores de lectura/escritura.

### <unistd.h>

Llamadas al sistema de Linux 2.4.

- `close(int fd)`: Cerrar un file descriptor para liberar recursos del sistema.
- `read(int fd, void *buffer, size_t nbytes)`: Intenta  leer  hasta nbytes bytes del fichero cuyo descriptor de fichero es fd y guardarlos en la zona de memoria que empieza en buffer.
- `write(int fd, const void *buf, size_t num)`: Escribir bytes desde un búfer en memoria hacia un file descriptor.

### <stdio.h>

Funciones de biblioteca de entrada/salida estándar.

- `perror(const char *s)`: Imprimir en stderr un mensaje de error personalizado seguido de : y la descripción de errno.

### <string.h>

Operaciones con strings.

- `*strerror(int errnum)` :  Devolver un puntero a cadena estática con la descripción textual de un errno específico.

### <math.h>

La biblioteca estándar <math.h> es la que provee funciones matemáticas avanzadas (trigonometría, exponenciales, raíces, etc.) que no forman parte del núcleo de C.

| Categoria | Funciones | Usos |
| -- | -- | -- |
| Trigonometría | `sin`, `cos`, `tan` | Cálculo de proyección isométrica |
| Exponenciación | `pow`, `exp`, `log` | Ajustes de escalado |
| Redondeo | `floor`, `ceil`, `round` | Ajustes de coordenadas |

## MiniLibX

MiniLibX es una pequeña biblioteca gráfica que permite realizar ls tareas mas basicas para renderizar elementos en pantalla sin necesidad de conocimientos en X-Window.

Algunas de las funciones son las siguientes:

- `void *mlx_init(void)`: Arranca la conexión con el servidor gráfico.
- `void *mlx_new_window(void *mlx, int w, int h, char *t)`: Crea una ventana de ancho `w`, alto `h`, titulo `t`. Retorna un puntero `void *win`.
- `int mlx_destroy_window(void *mlx, void *win)`: Cierra y libera los recursos asociados a la ventana `win`.
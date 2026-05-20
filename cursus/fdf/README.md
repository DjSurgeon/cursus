# FDF - Wireframe Model Viewer

Este proyecto, conocido como **FDF** (del francés '*fil de fer*' o 'modelo de estructura alámbrica'), es una iniciativa fundamental en el campo de la programación gráfica. Su objetivo principal es la creación y visualización de un paisaje tridimensional mediante un modelo de estructura alámbrica, conectando puntos definidos por coordenadas (x, y, z) a través de segmentos de línea. Este trabajo sirve como una introducción práctica a la programación gráfica básica, familiarizando al desarrollador con la biblioteca **MiniLibX** y conceptos esenciales como la gestión de ventanas, la creación de imágenes y la manipulación de eventos de teclado y ratón.

Las principales características del proyecto son:
- Renderizado de un paisaje 3D a partir de un archivo `*.fdf`.
- Proyección isométrica y proyección paralela (conmutables en tiempo real).
- Gestión interactiva de la ventana gráfica (rotaciones, traslación, zoom y escalado de altitud).
- Parser optimizado de una sola pasada y libre de fugas de memoria (0 leaks).

---

## Conceptos Iniciales

### Wireframe Modelling o Modelado de Estructura Alámbrica
El modelado de estructura alámbrica es una técnica de renderización en gráficos 3D que representa objetos mediante la visualización de sus aristas o 'segmentos de línea' (*edges*), sin rellenar las superficies. Esto resulta en una imagen **semitransparente** donde la estructura interna del objeto es visible. Para FDF, esto implica conectar cada punto (x, y, z) con sus vecinos adyacentes para formar una malla visible. Esta técnica es valorada en proyectos gráficos iniciales por su simplicidad computacional, ya que evita la complejidad de los algoritmos de renderizado de superficies.

### Proyecciones Geométricas
Las proyecciones geométricas son métodos matemáticos utilizados para transformar objetos **tridimensionales** en una representación **bidimensional**, permitiendo su visualización en una pantalla.

#### Proyección Ortográfica (Paralela)
Representa objetos mediante vistas separadas (frontal, superior, lateral), proyectando los puntos perpendicularmente a un plano. No hay efecto de perspectiva, y las líneas paralelas permanecen paralelas. En este proyecto, se implementa como modo alternativo plano para inspección cartográfica.

#### Proyección Isométrica
Es una **proyección paralela** donde los **tres ejes** principales (X, Y, Z) forman **ángulos de 120 grados** entre sí. Las líneas paralelas a estos ejes se dibujan a la misma escala, sin puntos de fuga. Esta proyección es la obligatoria para el renderizado del modelo en FDF. Se elige por su capacidad de ofrecer una percepción de profundidad sin la complejidad computacional de la perspectiva real, lo que la hace ideal para un proyecto gráfico introductorio que se enfoca en las transformaciones 3D básicas.

#### Perspectiva
Intenta **simular la visión humana**, donde los objetos se hacen más pequeños a medida que se alejan del observador. Requiere uno o más puntos de fuga donde las líneas paralelas convergen. En FDF, la implementación de la perspectiva o proyecciones más complejas es una característica extra (bonus), lo que subraya su mayor complejidad computacional.

---

## Estructura del Proyecto

```bash
fdf/
├── libft/              # Biblioteca de utilidades estándar de C y GNL
├── minilibx-linux/     # Biblioteca gráfica de X11 para Linux/WSL
├── include/
│   └── fdf.h           # Cabecera principal con macros, structs y firmas
├── src/
│   ├── main.c              # Punto de entrada del programa
│   ├── check_arguments.c   # Validaciones de argumentos y rutas de mapa
│   ├── check_errors.c      # Manejo centralizado de errores
│   ├── check_utils.c       # Funciones auxiliares de verificación
│   ├── parse_map.c         # Parser de alto rendimiento y cálculo de cotas
│   ├── mlx_init.c          # Inicialización de ventana, buffer de imagen y estado
│   ├── mlx_draw.c          # Pipeline matemático de rotación y proyección 3D
│   ├── mlx_bresenham.c     # Algoritmo de trazado de líneas ultra-rápido
│   ├── mlx_hooks.c         # Manejo modular de eventos de teclado y ventana
│   ├── mlx_utils.c         # Funciones gráficas de refresco de pantalla
│   └── free_structs.c      # Liberación ordenada de memoria y listas enlazadas
├── maps/               # Colección de mapas .fdf para pruebas
└── Makefile            # Sistema de compilación con flags optimizados
```

---

## Makefile Detallado

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
- **mlx**: Carpeta donde se encuentra la minilibx en su versión Linux para la biblioteca gráfica.

```Makefile
# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -D BUFFER_SIZE=4096 -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS		:= -lm
MLXFLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11
```
- **cc**: Compilador estándar en sistemas basados en Unix y Linux.
- **-Wall -Wextra**: Habilita advertencias adicionales.
- **-Werror**: Trata las advertencias como errores.
- **-g**: Genera información de depuración.
- **-D BUFFER_SIZE=4096**: Define la lectura del buffer optimizada de 4KB para GNL.
- **-I<directorio>**: Flag para poder añadir carpetas a la búsqueda de cabeceras.
- **-lm**: Para la librería math.h el compilador sabe la firma de las funciones, pero la implementación está en la librería matemática `libm`. `-l<nombre>` busca y enlaza con la librería `-lm` => `libm`.
- **-lmlx**: Busca `libmlx.a` en `minilibx-linux/`.
- **-lXext -lX11**: Flags necesarias para interactuar con el servidor gráfico X11.

```Makefile
# Files ====================================================================== #

SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)
```
- `$(wildcard $SRC_DIR)/*.c`: Busca dinámicamente todos los archivos `*.c` dentro de la carpeta `src/`.

```Makefile
# Objects ===================================================================== #

OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
```
- `$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))`: Toma cada ruta de archivo fuente en `src/` (ej. `src/main.c`) y genera la correspondiente ruta de objeto en `build/` (ej. `build/main.o`).

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
- `$(LIBFT_A)`: Invoca `make` dentro del directorio `libft/`, construyendo la librería estática.
- `$(MAKE) -C $(MLX_DIR)`: Invoca `make` dentro de la carpeta de la minilibx.
- `$(NAME): $(OBJ_FILES)`: Enlaza todos los archivos objeto con la librería estática `$(LIBFT_A)` y flags para generar el ejecutable `./fdf`.
- `$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fdf.h`: Regla de patrón para compilar cualquier `%.c` dentro de `src/` a su correspondiente `%.o` dentro de `build/`.
- `@mkdir -p $(OBJ_DIR)`: Crea la carpeta `build/` si no existe.

---

## Bibliotecas Utilizadas en fdf.h

### `<stdlib.h>`
Utilizado para las funciones de reserva de memoria y control de flujo:
- `malloc(size_t size)`: Reserva `size` bytes en el heap y devuelve un puntero.
- `free(void *ptr)`: Libera la memoria previamente reservada con `malloc`.
- `exit(int status)`: Termina inmediatamente el proceso con el código de salida `status`.

### `<fcntl.h>`
Biblioteca necesaria para realizar operaciones sobre los file descriptors:
- `open(const char *pathname, int flags)`: Abre un fichero y obtiene un descriptor para operaciones posteriores.

### `<unistd.h>`
Llamadas al sistema de Unix/Linux:
- `close(int fd)`: Cierra un descriptor de archivo para liberar recursos del sistema.
- `read(int fd, void *buffer, size_t nbytes)`: Lee hasta `nbytes` de un descriptor y los guarda en el búfer.
- `write(int fd, const void *buf, size_t num)`: Escribe bytes desde memoria en un descriptor.

### `<stdio.h>`
Funciones de biblioteca de entrada/salida estándar:
- `perror(const char *s)`: Imprime en stderr un mensaje personalizado seguido del error del sistema (`errno`).

### `<string.h>`
Operaciones con cadenas de texto:
- `strerror(int errnum)`: Devuelve la descripción textual de un `errno` específico.

### `<math.h>`
Provee funciones matemáticas avanzadas utilizadas en la proyección y rotación 3D:

| Categoría | Funciones | Usos |
| :--- | :--- | :--- |
| **Trigonometría** | `sin`, `cos`, `tan` | Cálculo de rotación en ejes X, Y, Z y proyección isométrica |
| **Exponenciación** | `pow`, `exp`, `log` | Ajustes de escalado y perspectiva |
| **Redondeo** | `floor`, `ceil`, `round`, `fmin`, `fmax` | Ajustes de coordenadas de pantalla e inicializaciones |

---

## Funciones Principales de MiniLibX

MiniLibX permite realizar tareas básicas para renderizar elementos en pantalla sin necesidad de conocimientos profundos en X-Window:
- `void *mlx_init(void)`: Arranca la conexión con el servidor gráfico.
- `void *mlx_new_window(void *mlx, int w, int h, char *t)`: Crea una ventana gráfica de ancho `w`, alto `h` y título `t`.
- `int mlx_destroy_window(void *mlx, void *win)`: Cierra y libera la ventana especificada.
- `int mlx_new_image(void *mlx, int width, int height)`: Crea una imagen en memoria para renderizado en buffer secundario (evita parpadeo).
- `char *mlx_get_data_addr(void *img_ptr, int *bpp, int *size_line, int *endian)`: Devuelve la dirección de memoria de la imagen para manipulación de píxeles a bajo nivel.

---

## Controles Interactivos (Bonus)

El visor responde de forma inmediata a los siguientes controles de teclado:

| Acción | Teclas | Descripción |
| :--- | :--- | :--- |
| **Traslación** | `←` `↑` `→` `↓` | Desplaza el mapa en las cuatro direcciones |
| **Zoom** | `+` / `-` | Aumenta o disminuye el tamaño del mapa en pantalla |
| **Rotación X** | `W` / `S` | Gira el objeto alrededor del eje horizontal |
| **Rotación Y** | `A` / `D` | Gira el objeto al rededor del eje vertical |
| **Rotación Z** | `Q` / `E` | Gira el objeto de forma plana (rotación Z) |
| **Escala Z** | `[` / `]` | Modifica dinámicamente la altura de los picos |
| **Proyección** | `P` | Alterna entre Proyección Isométrica y Paralela |
| **Salir** | `ESC` | Cierra la ventana y libera todos los recursos limpiamente |

---

## Evolución y Optimización del Parser (Rendimiento Extremo)

Para comprender el impacto del trabajo realizado, es valioso analizar la transición técnica desde el parser original de la escuela hasta la solución de alto rendimiento implementada actualmente.

### El Parser Original (Doble Pasada y Fragmentación por `ft_split`)
El parser original utilizaba una aproximación en dos fases:
1. **Fase 1 (Doble lectura)**: Se abría el archivo del mapa una primera vez completa para contar el número de líneas (filas) y de palabras en una línea (columnas).
2. **Fase 2 (Procesamiento)**: Se volvía a abrir el archivo desde el inicio. Para cada línea, se llamaba a `ft_split(line, ' ')` para dividir la línea en cadenas individuales por espacio. Luego, para cada subcadena, se llamaba a `ft_atoi` para la altura y se parseaba el color.

**Los Problemas**:
- **Fragmentación del Heap**: `ft_split` genera un puntero para cada número. En un mapa como `mars.fdf` (muchas coordenadas), esto suponía **cientos de miles de llamadas individuales a `malloc`**. Esto causaba una fragmentación masiva en memoria y penalizaba gravemente el rendimiento del sistema operativo.
- **Tiempos de carga altos**: Mapas de mediano/gran tamaño tardaban entre **15 y 45 segundos** en procesarse y cargar en la pantalla.
- **Doble Entrada/Salida (I/O)**: La necesidad de leer el archivo dos veces obligaba al disco a trabajar el doble.

### El Parser Nuevo (Una Sola Pasada y Escaneo de Caracteres Lineal)
La nueva solución realiza una lectura lineal en streaming optimizada para sistemas UNIX:
1. **Lectura lineal única**: El archivo se lee una sola vez de principio a fin usando `get_next_line` alimentado con un buffer óptimo de `4096 bytes`.
2. **Lista enlazada temporal (`t_row_node`)**: En lugar de hacer una doble lectura de archivo, cada línea leída se procesa de inmediato en un nodo de lista temporal.
3. **Escaneo sin `ft_split`**: Se precalcula el ancho de la línea barriendo directamente los espacios en blanco. Posteriormente, un puntero recorre la línea de caracteres de forma continua:
   - Extrae el entero Z directamente con `ft_atoi` desde su posición actual.
   - Salta los caracteres numéricos y, si detecta una coma `,`, convierte el color hexadecimal utilizando un convertidor numérico de bases (`ft_atoi_base`) directo en la dirección del puntero.
   - **Cero subcadenas asignadas**: No se fragmenta el heap; no se realiza ningún `ft_split`. Se asigna únicamente un array contiguo de coordenadas por cada fila.
4. **Construcción final**: Al finalizar la lectura, los punteros de filas se vuelcan directamente en la matriz principal `matrix` en tiempo constante $O(1)$ por fila.

**Los Resultados**:
- **Carga instantánea**: Mapas gigantescos como `mars.fdf` pasaron de cargar en **más de 30 segundos** a renderizarse de manera **instantánea (milisegundos)**.
- **Consumo mínimo de memoria**: Las asignaciones dinámicas se redujeron drásticamente, previniendo cuellos de botella por recolección de basura o gestión de fragmentación de bloques.

---

## Escalado Adaptativo Automático

El sistema analiza el rango de altitud del mapa (`z_max` y `z_min`) y adapta la elevación inicial de forma proporcional a la cuadrícula (`max(width, height) / z_range * 0.15`). Esto corrige la deformación visual de terrenos altos como `brazil.fdf` por defecto.

---

## Fugas de Memoria Cero

El ciclo de vida del visor cuenta con liberación completa de recursos tanto en el parser como en la interfaz gráfica:
```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```
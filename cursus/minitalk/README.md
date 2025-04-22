# Minitalk

El propósito de este proyecto es crear un pequeño programa de intercambio de datos utilizando señales UNIX.

```bash
Minitalk
 ├── Makefile
 ├── src/
 │    └── client.c
 │    └── server.c
 ├── lib/
 │    └── minitalk_prints.c
 │    └── minitalk_utils.c
 ├── include/
 │    └── minitalk.h
```

## Makefile

```Makefile
# Compiler =================================================================== #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -I include
```

- cc: Compilador estándar en sistemas basador en Unix y Linux
- -Wall -Wextra: Habilita advertencias adicionales
- -Werror: Trata las advertencias como errores
- -g: Genera información de depuración
- -I include: añade la carpeta `include/` a la búsqueda de cabeceras

```Makefile
# Files ====================================================================== #

SRC_LIB		:= $(wildcard $(LIB_DIR)*.c)
SRC_CLIENT	:= $(SRC_DIR)client.c
SRC_SERVER	:= $(SRC_DIR)server.c
```

- `$(wildcard $(LIB_DIR)*.c)`: busca todos los `*.c` dentro de la carpeta `lib/`
- `$(SRC_LIB:.c=.o)`: convierte todos los `*.c` en `*.o`
```Makefile
# Objects ===================================================================== #

OBJ_LIB		:= $(patsubst $(LIB_DIR)%.c,$(OBJ_DIR)lib/%.o,$(SRC_LIB))
OBJ_CLIENT	:= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)src/%.o,$(SRC_CLIENT))
OBJ_SERVER	:= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)src/%.o,$(SRC_SERVER))

ALL_OBJS	:= $(OBJ_LIB) $(OBJ_CLIENT) $(OBJ_SERVER)
```

- La carpeta `OBJ_DIR		:= build/` es el directorio designado para almacenar todos los archivos `*.o` generados
- `OBJ_LIB		:= $(patsubst $(LIB_DIR)%.c,$(OBJ_DIR)lib/%.o,$(SRC_LIB))`: genera una lista de archivos `*.o` para cada archivo de `*.c` de la carpeta `lib/`
- `$(patsubst patrón_búsqueda, patrón_reemplazo, lista)`: La función `patsubst` busca y reemplaza


```Makefile
# Rules ====================================================================== #

$(OBJ_DIR)lib/%.o: $(LIB_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
```

- `%.o: %.c`: indica que cualquier `*.o` depende de cualquier `*.c`, en este ejemplo generar `build/lib/archivo.o` a partir de `lib/archivo.c`
- `$<`: primer prerequesito (archivo `*.c`)
- `$@`: nombre del target (archivo `*.o`)

La estructura final tras ejecutar `make` sería la siguiente:

```bash
Minitalk
 ├── Makefile
 ├── server
 ├── client
 ├── src/
 │    ├── client.c
 │    └── server.c
 ├── lib/
 │    └── utils.c
 ├── build/
 │    ├── lib/
 │    │    └── utils.o
 │    └── src/
 │         ├── client.o
 │         └── server.o
```

## minitalk.h

### <unistd.h>

Proporciona los prototipos de las llamadas al sistema POSIX básicas que necesitamos para interactuar con el kernel y los descriptores de fichero.

- `write(int fd, const void *buf, size_t count)`: Utilizamos write para enviar mensajes en la pantalla de la terminal. Evitamos el uso de `printf` ya que no es una función **async-signal-safe**, y podría provocar comportamientos inesperados.
- `getpid(void)`: Devuelve el **PID** (Process ID) del proceso que lo llama.
El servidor imprime su número de proceso para que el cliente pueda comunicarse usando el **PID** como prefijo de la señal.
- `pause(void)`: Bloquea la ejecución del proceso hasta que llegue **cualquier** señal.
- `sleep(unsigned int seconds)`: Suspende el proceso `seconds` segundos.
- `usleep(useconds_t usec)`: Suspende el proceso `usec` microsegundos. Es una funcion que tampoco es **async-signal-safe**, se utiliza para espaciar el envio de señales.

### <signal.h>

Funciones y macros para manejar señales, esenciales para la comunicación bit-a-bit entre procesos.

- `signal(int signum, void (*handler)(int))`: Asocia una señal a una función manejadora, es una función que no permite recoger información extra por lo tanto es mejor usar `sigaction()`.
- `sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)`: Es un método más robusto y configurable de establecer una función manejadora.
	- `signum`: Indica el número de la señal cuya acción se desea modificar.
	- `act`: Un puntero a una estructura `struc sigaction` que define la nueva acción a tomar cuando se reciba la señal especificada.
	- `oldact`: Un puntero a una estructura donde se almacenará la acción anterior asociada a la señal.
	- `@return`: 0 si tuvo exito, -1 si se produjo algún error.
	- `struct sigaction`:
```c
struct sigaction
{
	void (*sa_handler)(int);						// Puntero a la función manejadora simple
	void (*sa_sigaction)(int, siginfo_t *, void *);	// Manejador con información adicional
	sigset_t sa_mask;								// Conjunto de señales a bloquear durante el manejador
	int sa_flags;									// Opciones que modifican el comportamiento
};
```
- `sigemptyset(sigset_t *set)`: Inicializa un conjunto de señales `set` dejandolo **vacio**, ninguna señal bloqueada.
- `sigaddset(sigset_t *set, int signum)`: Añade una señal al `set`, por ejemplo si quisieramos bloquear alguna señal mientras procesamos un bit.
- `kill(pid_t pid, int sig)`: Envia la señal `sig` al proceso `PID`.
- `SIGUSR1` y `SIGUSR2`: Señales predefinidas para el uso de usuarios, son perfectas para el protocolo de bits de la minitalk.

### <stdlib.h>

Utilizado para la funciones de reserva de memoria y control de flujo.

- `malloc(size_t size)`: Reserva `size` bytes en el heap y devuelve un puntero.
- `free(void *ptr)`: Libera la memoria previavemente reservada con `malloc`
- `exit(int status)`: Termina inmediatamente el proceso con el código de salida `status`

### Utils

```c
size_t	ft_strlen(const char *s);					// Devuelve la longitud de una cadena
char	*ft_strjoin(const char *s1, const char *s2);// Concatena s1 + s2 en una nueva cadena.
char	*ft_strdup(const char *s);					// Reserva memoria y copia la cadena s.
int		ft_isspace(int c);							// Detecta espacios, tabs, saltos de línea… 
int		ft_atoi(const char *str);					// Convierte cadena a entero
void	ft_putchar_fd(unsigned char c, int fd);		// Envía un byte (unsigned char) al descriptor fd (stdout o stderr).
void	ft_putnbr_fd(int n, int fd);				// Envía un número entero como texto al descriptor fd
void	ft_putstr_fd(const char *s, int fd);		// Envía una cadena de caracteres al descriptor fd.
```

### struct s_buffer

```c
typedef struct s_buffer
{
	char	*str;			// Acumula el mensaje recibido
	int		bit_count;		// Lleva la cuenta de bits recibidos (1–8). Cuando llega a 8, sabes que has completado un byte.
	char	current_char;	// Variable temporal donde ensamblas cada bit en un carácter.
	pid_t	client_pid;		// Almacena el PID del proceso cliente que envía las señales.
}			t_buffer;
```

- `static t_buffer	g_buffer = {0};`: Declaramos e inicializamos la variable `g_buffer` como estática para mantener el estado entre llamadas y formar la string.

## client.c

Este módulo implementa el **cliente** de `minitalk`, encargado de:
-  Leer el PID del servidor y el mensaje de la línea de comandos.  
-  Transformar cada carácter del mensaje (incluido el terminador `'\0'`) en una serie de señales `SIGUSR1`/`SIGUSR2` que el servidor interpretará como bits.  
-  Espaciar los envíos para permitir al servidor procesarlos.

### Pseudocódigo

```
function send_signals(pid, c):
	Inicializar i = 7
	Mientras i >= 0:
		bit = (c desplazado i bits a la derecha) AND 1
		Si bit es 0:
			Enviar SIGUSR1 a pid
		Sino:
			Enviar SIGUSR2 a pid
		Esperar 300 microsegundos
		Decrementar i

function main(argc, argv):
	Si argc == 3:
		Convertir argv[1] a PID
		Para cada carácter en argv[2]:
			Llamar a send_signals(PID, carácter)
		Enviar carácter nulo ('\0')
	Sino:
		Mostrar mensaje de error
	Terminar programa
```

## server.c

El **servidor** de `minitalk` escucha señales de un cliente, reconstruye cada bit en caracteres y va formando el mensaje completo. 

### Pseudocódigo

```

Variable global g_buffer inicializada a {0}

function reset_buffer():
	Liberar memoria de str
	str = cadena vacía
	bit_count = 0
	current_char = 0
	client_pid = 0

function get_str():
	Si current_char es '\0':
		Imprimir str
		reset_buffer()
	Sino:
		Crear cadena temporal con current_char
		Concatenar temp a str
	Resetear bit_count y current_char

function handler_signs(signum, info, context):
	Si el PID del cliente es diferente al almacenado:
		reset_buffer()
		Actualizar client_pid
	Shift left de current_char
	Si la señal es SIGUSR2:
		Agregar 1 al LSB de current_char
	Incrementar bit_count
	Si bit_count == 8:
		Llamar a get_str()

function main():
	Configurar struct sigaction:
		sa_sigaction = handler_signs
		sa_flags = SA_SIGINFO
	Registrar manejadores para SIGUSR1/SIGUSR2
	Mostrar PID y mensajes de bienvenida
	Bucle infinito:
		pause() // Esperar señales
```

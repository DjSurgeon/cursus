# C++ Module 01 - Memory Management & References

<div align="center">

> **Segundo módulo de la piscina de C++** - Escuela 42  
> Gestión de memoria dinámica, punteros a miembros, referencias y sentencias switch

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://www.42.fr/)
[![C++98](https://img.shields.io/badge/C++-98-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)

</div>

## Tabla de Contenidos

- [Descripción](#-descripción)
- [Ejercicios](#-ejercicios-implementados)
- [Conceptos](#-conceptos-clave-aprendidos)
- [Aplicaciones](#-aplicaciones-prácticas)
- [Compilación](#-compilación-y-uso)

## Descripción General

Segundo módulo del currículum de C++ de 42, enfocado en la gestión de memoria dinámica y las diferencias fundamentales entre **Stack** y **Heap**. Este proyecto profundiza en el uso de referencias, punteros a miembros de clase y estructuras de control avanzadas, construyendo las bases para la programación orientada a objetos en C++.

### Objetivos Pedagógicos

- Diferencias críticas entre Stack y Heap  
- Gestión manual de memoria con `new`/`delete`  
- Referencias como alternativa segura a punteros  
- Diseño de dependencias (obligatorias vs opcionales)  
- Punteros a miembros para dispatch tables  
- Manipulación avanzada de strings  
- File I/O con streams de C++  


## Ejercicios

### ex00: BraiiiiiiinnnzzzZ

**Conceptos:** Stack vs Heap, constructores/destructores, gestión de memoria

Implementación de una clase `Zombie` que demuestra la diferencia crítica entre asignación de memoria en **Stack** (automática) vs **Heap** (dinámica):
- `newZombie()`: Crea zombies en el **Heap** con `new` → Persisten fuera del scope
- `randomChump()`: Crea zombies en el **Stack** → Se destruyen automáticamente al salir de la función

**Aprendizaje clave:** Entender cuándo usar cada tipo de memoria según el ciclo de vida requerido del objeto.

---

### ex01: Moar brainz!

**Conceptos:** Arrays dinámicos, `new[]`, `delete[]`, memory leaks

Creación de una **horda de zombies** mediante asignación dinámica de arrays:
```cpp
Zombie* zombieHorde(int N, std::string name);
```

**Puntos críticos:**
- Uso obligatorio de `new[]` / `delete[]` emparejados (nunca `delete` solo)
- Cada zombie del array invoca su constructor/destructor individualmente
- Detección de memory leaks con herramientas como **Valgrind**

---

### ex02: HI THIS IS BRAIN
**Conceptos:** Referencias vs Punteros, operadores `&` y `*`, direcciones de memoria

Uso de las **referencias** a través de comparación directa:
```cpp
std::string brain = "HI THIS IS BRAIN";
std::string* stringPTR = &brain;  // Puntero
std::string& stringREF = brain;   // Referencia (alias)
```

**Demostración:**
- Mismo valor, misma dirección de memoria
- Las referencias son "azúcar sintáctica" sobre punteros más seguros
- No pueden ser NULL ni reasignadas

---

### ex03: Unnecessary violence

**Conceptos:** Referencias en constructores, punteros opcionales, diseño de dependencias

Implementación de clases `HumanA` y `HumanB` que ilustran cuándo usar **referencias** vs **punteros**:

| Clase | Weapon | Razón |
|-------|--------|-------|
| **HumanA** | `Weapon&` | Siempre armado → Referencia obligatoria en constructor |
| **HumanB** | `Weapon*` | Arma opcional → Puntero (puede ser `nullptr`) |

**Lección de diseño:**
- **Referencias:** Dependencias obligatorias e inmutables
- **Punteros:** Dependencias opcionales o cambiantes

---

### ex04: Sed is for losers

**Conceptos:** File streams, manipulación de strings sin `replace()`, `find()`, `erase()`, `insert()`

Reemplazo de texto en archivos usando solo operaciones básicas de `std::string`:

**Algoritmo implementado:**
```cpp
while ((pos = texto.find(s1, pos)) != std::string::npos) {
    texto.erase(pos, s1.length());
    texto.insert(pos, s2);
    pos += s2.length();  // Evita bucles infinitos
}
```

**Gestión de archivos:**
- `std::ifstream` + `.rdbuf()` para lectura eficiente completa
- `std::ofstream` para escritura
- Validación con `.is_open()`

---

### ex05: Harl 2.0

**Conceptos:** Punteros a funciones miembro, arrays de punteros, operadores `.*` y `->*`

Sistema de logging con niveles mediante **punteros a métodos de clase**:

```cpp
void (Harl::*funciones[])() = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};

(this->*funciones[nivel])();  // Invocación dinámica
```

**Ventaja:** Elimina la "selva de if/else" usando dispatch table.

---

### ex06: Harl filter

**Conceptos:** Sentencia `switch`, fall-through intencional, enums

Filtro de logs jerárquico usando **switch sin break** para lógica acumulativa:

```cpp
switch (nivel) {
    case 0: // DEBUG
        mostrarDebug();
        [[fallthrough]];  // C++17
    case 1: // INFO
        mostrarInfo();
        [[fallthrough]];
    case 2: // WARNING
        mostrarWarning();
        // ... (cae hasta ERROR)
}
```

**Aplicación:** Cuando un nivel superior incluye todos los inferiores.

---

## Conceptos Clave Aprendidos

### 1 Stack vs Heap

| Característica | Stack | Heap |
|----------------|-------|------|
| **Gestión** | Automática (RAII) | Manual (`new`/`delete`) |
| **Velocidad** | Muy rápida | Más lenta |
| **Tamaño** | Limitado (~1-8MB) | Limitado por RAM |
| **Vida útil** | Scope de la función | Hasta `delete` manual |
| **Riesgo** | Stack overflow | Memory leaks |

**Regla de oro:** Usa Stack siempre que sea posible; Heap solo cuando:
- El tamaño se determina en runtime
- El objeto debe sobrevivir al scope
- El objeto es muy grande

---

### 2 Operadores de Memoria Dinámica

#### `new` / `delete`
```cpp
Zombie* z = new Zombie("Foo");  // Heap + Constructor
delete z;                        // Destructor + Liberar
```

#### `new[]` / `delete[]`
```cpp
Zombie* horde = new Zombie[10];  // Array en Heap
delete[] horde;                  // ¡OBLIGATORIO usar []!
```

**Error crítico:** Usar `delete` en vez de `delete[]` → Undefined Behavior (solo destruye el primer elemento).

---

### 3 Referencias: Alias Seguros

**Declaración e Inicialización:**
```cpp
int original = 42;
int& ref = original;  // Debe inicializarse SIEMPRE

ref = 100;  // Modifica 'original'
// int& ref2;  // ERROR: Referencias no pueden estar sin inicializar
```

**Reglas inmutables:**
1. No pueden ser `NULL`
2. No pueden reasignarse a otro objeto
3. Deben inicializarse en declaración

**Referencias constantes (`const T&`):**
```cpp
const std::string& getType() const {
    return type;  // Eficiente (no copia) + Seguro (no modifica)
}
```
**Ventaja:** Usadas en getters para evitar copias innecesarias de objetos grandes.

---

### 4 Referencias vs Punteros

| Aspecto | Referencias | Punteros |
|---------|-------------|----------|
| Sintaxis | Limpia (`ref.method()`) | Requiere `*` y `->` |
| Nullable | Nunca | Puede ser `nullptr` |
| Reasignación | Inmutable | Puede cambiar |
| Uso típico | Parámetros, alias | Arrays dinámicos, opcional |

**Cuándo usar cada uno:**
```cpp
// Referencia: Parámetro obligatorio y no nulo
void procesar(Weapon& arma);

// Puntero: Parámetro opcional
void setWeapon(Weapon* arma);  // Puede pasar nullptr

// Puntero: Reasignación necesaria
Weapon* current = &espada;
current = &hacha;  // Cambiar de arma
```

---

### 5 Punteros a Miembros de Clase

#### Punteros a Funciones Miembro
```cpp
class Robot {
public:
    void caminar() { /*...*/ }
};

// Declaración
void (Robot::*ptrMetodo)() = &Robot::caminar;

// Invocación
Robot r;
(r.*ptrMetodo)();     // Con objeto
(ptr->*ptrMetodo)();  // Con puntero a objeto
```

**Precedencia crítica:** Los paréntesis son **obligatorios** porque `()` tiene mayor precedencia que `.*`

#### Punteros a Datos Miembro
```cpp
class Punto {
public:
    int x, y;
};

int Punto::*ptrX = &Punto::x;

Punto p;
p.*ptrX = 10;  // Equivale a p.x = 10;
```

---

### 6 File Streams (`<fstream>`)

**Lectura eficiente completa:**
```cpp
std::ifstream infile("data.txt");
if (!infile.is_open()) {
    // Error handling
}

std::ostringstream buffer;
buffer << infile.rdbuf();  // Truco: Copia TODO el búfer
std::string contenido = buffer.str();
```

**Escritura:**
```cpp
std::ofstream outfile("output.txt");
outfile << contenido;
outfile.close();  // Buena práctica aunque sea automático
```

**¿Por qué cerrar manualmente?**
- Liberación inmediata de recursos
- Verificación de errores en escritura
- Reutilización del objeto stream

---

### 7 Sentencia `switch` y Fall-Through

**Limitación:** Solo acepta tipos integrales (`int`, `char`, `enum`), **NO strings**

**Solución para strings:**
```cpp
int mapearNivel(std::string nivel) {
    if (nivel == "DEBUG") return 0;
    if (nivel == "INFO") return 1;
    // ...
    return -1;  // No encontrado
}
```

**Fall-Through intencional:**
```cpp
switch (nivel) {
    case 2:  // WARNING
        mostrarWarning();
        // SIN break → Cae a ERROR
    case 3:  // ERROR
        mostrarError();
        break;
}
```

**Atributo moderno (C++17):**
```cpp
case 2:
    mostrarWarning();
    [[fallthrough]];  // Documenta intención
case 3:
    mostrarError();
```

---

## Aplicaciones Prácticas

### Gestión de Recursos (RAII - Resource Acquisition Is Initialization)

Los conceptos de este módulo son la base del patrón RAII, fundamental en C++ moderno:

```cpp
class FileHandler {
private:
    std::ifstream file;
public:
    FileHandler(const std::string& path) : file(path) {
        if (!file.is_open()) throw std::runtime_error("Error");
    }
    ~FileHandler() {
        // Cierre automático garantizado
    }
};
```

**Aplicaciones reales:**
- Gestión de archivos (ofstream/ifstream)
- Conexiones de red (sockets)
- Bloqueos de hilos (mutexes)
- Smart pointers (unique_ptr, shared_ptr)

---

### Sistemas de Eventos y Callbacks

Los punteros a funciones miembro son esenciales en:

**Game Engines:**
```cpp
class GameObject {
    void (GameObject::*updateFunc)();
public:
    void setUpdateBehavior(void (GameObject::*func)()) {
        updateFunc = func;
    }
    void update() { (this->*updateFunc)(); }
};
```

**GUI Frameworks:**
```cpp
button.onClick(&Window::handleClick);
```

---

### Logging y Debugging

El patrón Harl se usa ampliamente en sistemas de logging:

```cpp
class Logger {
    enum Level { DEBUG, INFO, WARN, ERROR };
    void log(Level lvl, const std::string& msg);
};
```

**Librerías reales que usan este patrón:**
- spdlog
- log4cpp
- Boost.Log

---

### Procesamiento de Texto

Las técnicas de manipulación de strings del ex04 son fundamentales para:

**Parsers de configuración:**
```cpp
// Reemplazar variables en templates
config.replace("${USER}", getenv("USER"));
```

**Sanitización de entrada:**
```cpp
// Eliminar caracteres peligrosos
texto.erase(std::remove(texto.begin(), texto.end(), ';'), texto.end());
```

**Serialización:**
```cpp
// Convertir objetos a JSON/XML manualmente
```

---

### Diseño de APIs

**Referencias const en interfaces públicas:**
```cpp
class Database {
public:
    const Record& getRecord(int id) const;  // Eficiente + Seguro
};
```

**Punteros para dependencias opcionales:**
```cpp
class HTTPRequest {
    void setProxy(Proxy* proxy);  // nullptr = sin proxy
};
```

---

## Compilación y Uso

### Requisitos
- Compilador: `c++` (g++ o clang++) con soporte para C++98
- Make: GNU Make o compatible

### Compilar un ejercicio específico
```bash
cd ex00
make
./zombie
```

### Compilar todos los ejercicios
```bash
for dir in ex*/; do
    (cd "$dir" && make)
done
```

### Limpiar
```bash
make clean   # Elimina objetos
make fclean  # Elimina objetos + ejecutables
make re      # Recompila desde cero
```

### Verificar memory leaks
```bash
# Con Valgrind (Linux)
valgrind --leak-check=full ./zombie

# Con leaks (macOS)
leaks -atExit -- ./zombie
```

---

## Notas Técnicas

### Flags de Compilación Obligatorios
```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

- `-Wall -Wextra`: Habilita warnings exhaustivos
- `-Werror`: Trata warnings como errores (código limpio obligatorio)
- `-std=c++98`: Estándar legacy (sin auto, lambda, nullptr, etc.)

### Restricciones del Módulo
**Prohibido**:
- `using namespace std;`
- Funciones de C: `printf`, `malloc`, `free`
- STL containers (hasta CPP08/09)
- C++11+ features

**Permitido**:
- Standard library: `<iostream>`, `<string>`, `<iomanip>`
- Funciones C++ de `<cstring>`, `<ctime>`
- Gestión manual de memoria con `new`/`delete`

---

## Recursos Adicionales

### Documentación oficial
- [C++ Reference](https://en.cppreference.com/)
- [C++98 Standard](https://www.open-std.org/jtc1/sc22/wg21/)

### Herramientas de debugging
- **Valgrind:** Detección de memory leaks
- **GDB:** Depurador
- **AddressSanitizer:** `-fsanitize=address`

---

## Autor

**Sergio Jiménez de la Cruz**

- [Github](https://github.com/DjSurgeon)
- [Linkedin](https://www.linkedin.com/in/sergiojimenez42dev/)
- [Email](djsurgeon83@gmail.com)

---

## Licencia

Este proyecto es parte del curriculum de 42 School y está sujeto a sus políticas académicas.  
El código está disponible con fines educativos.

---

<div align="center">

**⭐ Si este repositorio te ayudó, considera darle una estrella ⭐**

[⬆ Volver arriba](#-cpp-module-00---fundamentos-de-c-y-poo)

</div>
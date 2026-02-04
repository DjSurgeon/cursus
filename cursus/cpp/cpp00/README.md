# CPP Module 00 - Fundamentos de C++ y POO

<div align="center">

> **Primer módulo de la piscina de C++** - Escuela 42  
> Introducción a la Programación Orientada a Objetos en C++98

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://www.42.fr/)
[![C++98](https://img.shields.io/badge/C++-98-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)

</div>

## Tabla de Contenidos

- [Descripción General](#-descripción-general)
- [Ejercicios](#-ejercicios)
- [Conceptos Clave Aprendidos](#-conceptos-clave-aprendidos)
- [Aplicaciones Prácticas](#-aplicaciones-prácticas)
- [Compilación y Uso](#-compilación-y-uso)
- [Notas Técnicas](#-notas-técnicas)
- [Recursos](#-recursos)

## Descripción General

Este módulo representa **mi transición de C a C++**, introduciendo los fundamentos de la Programación Orientada a Objetos. A través de ejercicios progresivos, he explorado los pilares básicos de C++ mientras mantengo compatibilidad con el estándar C++98.

### Objetivos Pedagógicos
- Comprender la diferencia entre C y C++
- Dominar clases, objetos y encapsulación
- Gestionar memoria con constructores/destructores
- Aplicar const correctness y referencias
- Implementar ingeniería inversa de código

## Ejercicios

### 00 - Megaphone
**Conceptos**: Argumentos de línea de comandos, manipulación de strings, funciones estándar de C++
```bash
./megaphone "hello world"
# Output: HELLO WORLD
```
**Aprendizaje clave**: Uso de `std::cout`, `std::toupper()` y manejo de `argc/argv`.

---

### 01 - My Awesome PhoneBook

**Conceptos**: Clases, encapsulación, arrays estáticos, I/O formatting

**Estructura del proyecto**:
```
ex01/
├── Contact.hpp/cpp    # Clase para gestionar contactos individuales
├── PhoneBook.hpp/cpp  # Clase para gestionar la agenda (max 8 contactos)
└── main.cpp           # Loop de comandos (ADD/SEARCH/EXIT)
```

**Características implementadas**:
- Gestión de hasta 8 contactos con buffer circular
- Búsqueda y visualización formateada (columnas de 10 caracteres)
- Truncado de texto con punto final cuando excede el ancho
- Validación de entrada (campos no vacíos)

**Conceptos aplicados**:
```cpp
// Encapsulación: atributos privados, interfaz pública
class Contact {
private:
    std::string _firstName;  // Convención: _ para privados
public:
    void setFirstName(const std::string& name);  // Setter con referencia constante
    std::string getFirstName() const;            // Getter const
};
```
---

### 02 - The Job Of Your Dreams

**Conceptos**: Ingeniería inversa, miembros estáticos, timestamps, análisis de logs

**Desafío**: Recrear `Account.cpp` usando solo:
- `Account.hpp` (header con declaraciones)
- `tests.cpp` (programa de prueba)
- Log file (salida esperada)

**Técnicas de ingeniería inversa aplicadas**:
1. Análisis de declaraciones en el header
2. Deducción de comportamiento desde tests
3. Matching de output con el log file
4. Implementación de timestamps Unix

**Conceptos avanzados**:
```cpp
// Miembros estáticos: compartidos por todas las instancias
class Account {
private:
    static int _nbAccounts;      // Declaración en .hpp
    static int _totalAmount;
};

// Definición obligatoria en .cpp (fuera de la clase)
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
```

---

## Conceptos Clave Aprendidos

### 1 **Namespaces**
> Organización del código en regiones declarativas para evitar colisiones de nombres

```cpp
// Prohibido en 42 (contamina el scope global)
using namespace std;

// Correcto: uso explícito
std::cout << "Hello" << std::endl;
```

**Por qué importa**: Previene conflictos en proyectos grandes y mejora la legibilidad del origen de cada identificador.

---

### 2 **Clases y Encapsulación**
> Agrupar datos y funciones en una unidad lógica con control de acceso

**Niveles de acceso**:
- `private` (default en `class`): Solo accesible dentro de la clase
- `protected`: Accesible en la clase y sus derivadas
- `public`: Interfaz pública de la clase

```cpp
class SistemaSeguridad {
private:
    int _codigoSecreto;  // Dato oculto (implementación)
    
public:
    bool validarAcceso(int intento);  // Interfaz controlada
};
```

**Ventaja**: Separación entre interfaz (qué hace) e implementación (cómo lo hace).

---

### 3 **Constructores y Destructores**
> Gestión automática del ciclo de vida de objetos

**Constructor**: Inicializa el objeto
```cpp
class Usuario {
public:
    // Lista de inicialización (más eficiente)
    Usuario(std::string nombre) : _nombre(nombre), _id(++_contador) {
        std::cout << "Usuario creado" << std::endl;
    }
};
```

**Destructor**: Limpia recursos antes de destruir el objeto
```cpp
~Usuario() {
    std::cout << "Usuario destruido" << std::endl;
    // Liberar memoria dinámica, cerrar archivos, etc.
}
```

**Por qué importa**: RAII (Resource Acquisition Is Initialization) - patrón fundamental en C++.

---

### 4 **Const Correctness**
> Garantizar que funciones no modifiquen datos cuando no deben

```cpp
class Contact {
public:
    // Método const: promete no modificar el objeto
    std::string getName() const { return _name; }
    
    // Parámetro const&: no copia, no modifica
    void setName(const std::string& name) { _name = name; }
};
```

**Beneficios**:
- Previene modificaciones accidentales
- Optimización (evita copias innecesarias)
- Documentación implícita (el tipo indica la intención)

---

### 5 **Miembros Estáticos**
> Datos/funciones compartidos por todas las instancias de una clase

```cpp
class Contador {
private:
    static int _total;  // Compartido entre TODAS las instancias
    int _individual;    // Específico de cada objeto
    
public:
    static int getTotal() { return _total; }  // Llamable sin objeto
};

// Definición obligatoria fuera de la clase
int Contador::_total = 0;
```

**Casos de uso**:
- Contadores globales de instancias
- Configuración compartida
- Factory patterns

---

### 6 **Referencias vs Punteros**
> Dos formas de referirse a objetos existentes

| Característica | Referencia (`&`) | Puntero (`*`) |
|----------------|------------------|---------------|
| Reasignación | No puede cambiar | Puede apuntar a otro objeto |
| Valor nulo | Debe ser válida siempre | Puede ser `NULL` |
| Sintaxis | Transparente (`obj.metodo()`) | Requiere desreferencia (`ptr->metodo()`) |
| Uso preferido | Parámetros de función | Gestión dinámica de memoria |

**Ejemplo práctico**:
```cpp
void procesarContacto(const Contact& c);  // Referencia constante (eficiente, seguro)
void procesarContacto(Contact* c);        // Puntero (permite NULL, menos seguro)
```

---

### 7 **Ingeniería Inversa de Código**
> Reconstruir implementación desde interfaces y comportamiento observable

**Proceso aplicado en ex02**:
1. **Análisis estático**: Leer `Account.hpp` para identificar métodos y atributos
2. **Análisis dinámico**: Ejecutar `tests.cpp` mentalmente para deducir flujo
3. **Pattern matching**: Comparar salida esperada (log) con implementación
4. **Implementación iterativa**: Codificar, compilar, ajustar hasta match perfecto

**Habilidades desarrolladas**:
- Lectura de código sin documentación
- Deducción de especificaciones desde tests
- Debugging por comparación de outputs

---

## Aplicaciones Prácticas

### En el Mundo Real

#### **Sistema Bancario** (ex02 - Account)
Los conceptos de miembros estáticos son fundamentales en sistemas que rastrean totales globales:
```cpp
// Aplicación real: Banking Core System
class Account {
    static double _totalDepositsToday;  // Límite de liquidez diaria
    static int _activeAccounts;         // Compliance reporting
};
```

#### **CRM / Contact Management** (ex01 - PhoneBook)
La estructura de gestión de contactos se aplica en:
- Aplicaciones de CRM (Customer Relationship Management)
- Sistemas de mensajería (WhatsApp, Telegram)
- Directorios corporativos

**Escalabilidad aprendida**:
- Buffer circular para datos de tamaño fijo
- Formateo de tablas para UI/reporting
- Validación de entrada de usuario

## Compilación y Uso

### Requisitos
- Compilador: `c++` (g++ o clang++) con soporte para C++98
- Make: GNU Make o compatible

### Compilar todos los ejercicios
```bash
# Desde la raíz del módulo
make -C ex00 && make -C ex01 && make -C ex02
```

### Ejecutar ejercicios individuales
```bash
# Ejercicio 00
cd ex00 && make
./megaphone "test your voice"

# Ejercicio 01
cd ex01 && make
./phonebook
# Comandos: ADD, SEARCH, EXIT

# Ejercicio 02
cd ex02 && make
./account_test
# Compara la salida con el log proporcionado
```

### Verificar memoria (Valgrind)
```bash
valgrind --leak-check=full ./phonebook
# Debe mostrar: All heap blocks were freed -- no leaks are possible
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

## Recursos

### Documentación Oficial
- [cppreference.com](https://en.cppreference.com/) - Referencia exhaustiva de C++
- [cplusplus.com](http://www.cplusplus.com/) - Tutoriales y ejemplos

### Conceptos Clave
- [RAII Pattern](https://en.cppreference.com/w/cpp/language/raii)
- [Const Correctness](https://isocpp.org/wiki/faq/const-correctness)
- [Static Members](https://en.cppreference.com/w/cpp/language/static)

### Herramientas de Desarrollo
- **Valgrind**: Detección de memory leaks
- **GDB/LLDB**: Debugging
- **clang-format**: Formateo de código

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
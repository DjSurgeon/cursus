# C++ Module 02 - Fixed Point & Operator Overloading

<div align="center">

> **Tercer módulo de la piscina de C++** - Escuela 42  
> Polimorfismo ad-hoc, sobrecarga de operadores y la Forma Canónica Ortodoxa

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

Tercer módulo del currículum de C++ de 42, centrado en **polimorfismo ad-hoc** a través de la sobrecarga de operadores y la implementación de la **Forma Canónica Ortodoxa (OCF)**. Este proyecto introduce los números de punto fijo como alternativa a los tipos flotantes nativos, demostrando el poder del diseño de tipos personalizados en C++.

### Objetivos Pedagógicos

- Forma Canónica Ortodoxa (Orthodox Canonical Form)
- Sobrecarga de operadores aritméticos y de comparación
- Números de punto fijo y aritmética binaria
- Conversión entre tipos (int ↔ float ↔ fixed)
- Gestión de precisión y overflow
- Operadores de incremento/decremento (pre/post)
- Funciones miembro estáticas
- Geometría computacional (BSP)

---

## Ejercicios Implementados

### ex00: My First Class in Orthodox Canonical Form

**Conceptos:** OCF, constructores/destructores, encapsulación, getters/setters

Implementación básica de una clase `Fixed` que respeta la **Forma Canónica Ortodoxa**:

```cpp
class Fixed {
private:
    int _fixedValue;                    // Valor en formato Q24.8
    static const int _fractionalBits = 8; // 8 bits para decimales

public:
    Fixed();                            // Constructor por defecto
    Fixed(const Fixed& other);          // Constructor de copia
    Fixed& operator=(const Fixed& other); // Operador de asignación
    ~Fixed();                           // Destructor
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
```

**Los 4 pilares de OCF:**

| Miembro | Propósito | Cuándo se invoca |
|---------|-----------|------------------|
| **Constructor por defecto** | Inicializa el objeto en estado válido | `Fixed a;` |
| **Constructor de copia** | Crea una copia profunda | `Fixed b(a);` |
| **Operador de asignación** | Copia entre objetos existentes | `c = b;` |
| **Destructor** | Libera recursos | Al salir del scope |

**Aprendizaje clave:** OCF garantiza que los objetos de tu clase se comporten como tipos nativos (`int`, `float`), siendo copiables, asignables y destruibles de forma segura.

---

### ex01: Towards a more useful fixed-point number class

**Conceptos:** Conversión de tipos, bit shifting, roundf, sobrecarga de `<<`

Extensión de la clase `Fixed` con constructores de conversión y métodos de transformación:

#### Constructores de Conversión

```cpp
Fixed::Fixed(const int value) {
    // Multiplicar por 2^8 = 256 mediante desplazamiento
    _fixedValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    // Redondeo crítico para evitar truncamiento
    _fixedValue = (int)roundf(value * (1 << _fractionalBits));
}
```

**Matemática del punto fijo:**
```
Valor Real = Valor Interno / 2^fractionalBits
Valor Interno = Valor Real × 2^fractionalBits

Ejemplo:
  12.34f → 12.34 × 256 = 3159 (valor almacenado)
  3159 → 3159 / 256 = 12.339... (recuperado)
```

#### Métodos de Conversión Inversa

```cpp
float Fixed::toFloat(void) const {
    // División en float para recuperar decimales
    return (float)_fixedValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    // División entera → trunca decimales
    return _fixedValue >> _fractionalBits;
}
```

#### Sobrecarga del Operador de Inserción

```cpp
std::ostream& operator<<(std::ostream& output, const Fixed& value) {
    output << value.toFloat();
    return output;
}
```

**¿Por qué fuera de la clase?**
- El operador `<<` toma `std::ostream` como primer operando (izquierda)
- No puede ser miembro porque no controlamos `std::ostream`
- Permite encadenar: `std::cout << a << " " << b << std::endl;`

---

### ex02: Now we're talking

**Conceptos:** Sobrecarga de operadores aritméticos, comparación, incremento/decremento, funciones estáticas

Clase `Fixed` completamente funcional con aritmética completa:

#### Operadores de Comparación

```cpp
bool Fixed::operator>(const Fixed& other) const {
    return this->_fixedValue > other._fixedValue;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_fixedValue == other._fixedValue;
}
```

**¿Por qué `const` al final?**
- Promete no modificar el objeto `this`
- Permite usar con objetos constantes: `const Fixed a(10);`
- Operaciones de lectura → siempre `const`

#### Operadores Aritméticos

```cpp
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedValue + other._fixedValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    // (A × 2^8) × (B × 2^8) = (A×B) × 2^16
    // Necesitamos volver a 2^8 → dividir por 2^8
    long long temp = (long long)this->_fixedValue * other._fixedValue;
    result.setRawBits(temp >> _fractionalBits);
    return result;
}
```

**¿Por qué devolver por valor (`Fixed`) y no referencia (`Fixed&`)?**
- `result` es una variable **local** que se destruye al salir
- Devolver referencia a objeto destruido → **Undefined Behavior**
- La copia se optimiza con RVO (Return Value Optimization)

#### Pre-incremento vs Post-incremento

La diferencia más sutil:

```cpp
// PRE-INCREMENTO: ++a (Incrementa ANTES, devuelve YA modificado)
Fixed& Fixed::operator++(void) {
    this->_fixedValue++;
    return *this;  // Referencia al objeto modificado
}

// POST-INCREMENTO: a++ (Devuelve copia del ANTIGUO valor, luego incrementa)
Fixed Fixed::operator++(int) {  // int = flag para distinguir
    Fixed temp(*this);  // 1. Copia del estado actual
    this->_fixedValue++; // 2. Incrementa el original
    return temp;        // 3. Devuelve la "foto" antigua
}
```

**Tabla comparativa:**

| Operador | Devuelve | Eficiencia | Uso típico |
|----------|----------|------------|------------|
| `++a` | `Fixed&` (referencia) | Rápido | Bucles, cuando no necesitas el valor antiguo |
| `a++` | `Fixed` (copia) | Lento (crea copia + destructor) | Cuando necesitas el valor original |

**Ejemplo en acción:**
```cpp
Fixed a(5);
Fixed b = ++a; // a=6, b=6 (referencia al mismo objeto modificado)
Fixed c = a++; // a=7, c=6 (c tiene copia del valor antiguo)
```

#### Funciones Miembro Estáticas (min/max)

```cpp
// Versión NO-CONST: Permite modificar el resultado
static Fixed& min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

// Versión CONST: Para objetos constantes o temporales
static const Fixed& min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
```

**¿Por qué dos versiones?**

1. **Objetos constantes:** `const Fixed a(10);` no puede pasarse a función que pide `Fixed&` (permisos de escritura)
2. **Temporales:** `Fixed::min(Fixed(5), Fixed(3))` → temporales solo se unen a `const &`
3. **Permiso de modificación:** La versión no-const permite hacer `Fixed::min(a, b) = Fixed(0);`

**Ejemplo de uso:**
```cpp
Fixed a(42.42f);
Fixed b(10);

// Usa versión no-const → devuelve referencia modificable
Fixed::min(a, b).setRawBits(100); // Modifica b directamente

const Fixed c(30);
// Usa versión const → devuelve referencia de solo lectura
Fixed result = Fixed::min(a, c); // OK: solo lectura
// Fixed::min(a, c).setRawBits(100); // ERROR: devuelve const
```

---

### ex03: BSP (Binary Space Partitioning)

**Conceptos:** Geometría computacional, producto cruzado, inmutabilidad con `const`

Implementación de detección de punto dentro de triángulo usando **algoritmo del producto cruzado**:

#### Clase Point (Inmutable)

```cpp
class Point {
private:
    const Fixed x;  // Atributo CONST → inmutable después de construcción
    const Fixed y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    
    Fixed getX() const { return this->x; }
    Fixed getY() const { return this->y; }
};
```

**Inmutabilidad con atributos `const`:**

**Correcto (lista de inicialización):**
```cpp
Point::Point(const float px, const float py) : x(px), y(py) {
    // x e y YA están inicializados aquí
}
```

**Incorrecto (asignación en cuerpo):**
```cpp
Point::Point(const float px, const float py) {
    x = px; // ERROR: no puedes reasignar una const
    y = py;
}
```

**¿Por qué inmutabilidad?**
- Los puntos geométricos no cambian sus coordenadas → semántica matemática
- Evita bugs accidentales: `point.setX(42); // No existe, compilador te protege`
- Thread-safe: múltiples threads pueden leer sin sincronización

#### Algoritmo BSP: Producto Cruzado 2D

**Teoría matemática:**

El producto cruzado de dos vectores en 2D da un **escalar** cuyo **signo** indica orientación:

```
Vector AB × Vector AP = (Bx - Ax)(Py - Ay) - (By - Ay)(Px - Ax)

Resultado > 0 → P está a la IZQUIERDA de AB
Resultado < 0 → P está a la DERECHA de AB
Resultado = 0 → P está SOBRE la línea AB
```

**Lógica del triángulo:**
Para que un punto esté **dentro** del triángulo ABC, debe estar en el **mismo lado** de los tres bordes:

```cpp
float crossProduct(const Point& a, const Point& b, const Point& p) {
    return ((b.getX() - a.getX()) * (p.getY() - a.getY()) - 
            (b.getY() - a.getY()) * (p.getX() - a.getX())).toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float cp1 = crossProduct(a, b, point);
    float cp2 = crossProduct(b, c, point);
    float cp3 = crossProduct(c, a, point);
    
    // Todos deben tener el mismo signo (o cero = borde → excluir)
    bool has_neg = (cp1 < 0) || (cp2 < 0) || (cp3 < 0);
    bool has_pos = (cp1 > 0) || (cp2 > 0) || (cp3 > 0);
    
    // Si hay mezcla de signos → fuera
    // Si alguno es 0 → sobre borde → fuera (según subject)
    return !(has_neg && has_pos) && cp1 != 0 && cp2 != 0 && cp3 != 0;
}
```

**Diagrama visual:**
```
        B
       /|\
      / | \
     /  P  \    Si P está dentro:
    /   |   \   - cp1, cp2, cp3 > 0 (todos positivos)
   A---------C  O cp1, cp2, cp3 < 0 (todos negativos)

        B
       /|\
      / | Q    Si Q está fuera:
     /  |  \   - Signos mezclados (ej: cp1>0, cp2<0)
    A---------C
```

---

## Conceptos Clave Aprendidos

### 1. La Forma Canónica Ortodoxa (Orthodox Canonical Form)

La OCF es un **contrato de diseño** que garantiza que una clase se comporte como un tipo de dato concreto (similar a `int` o `float`).

#### ¿Por qué es necesaria?

**Problema sin OCF:**
```cpp
class Cadena {
    char* datos;
public:
    Cadena(const char* s) {
        datos = new char[strlen(s) + 1];
        strcpy(datos, s);
    }
    // ⚠️ Falta destructor, constructor de copia y operador de asignación
};

int main() {
    Cadena a("Hola");
    Cadena b = a;  // Usa constructor de copia GENERADO POR DEFECTO
    // b.datos apunta a LA MISMA memoria que a.datos (shallow copy)
    // Al destruirse b, libera la memoria
    // Al destruirse a, intenta liberar LA MISMA memoria → DOUBLE FREE ☠️
}
```

**Solución con OCF:**
```cpp
class Cadena {
private:
    char* datos;

public:
    // 1. Constructor por defecto
    Cadena() : datos(new char[1]) { datos[0] = '\0'; }
    
    // 2. Constructor de copia (Deep Copy)
    Cadena(const Cadena& other) {
        datos = new char[strlen(other.datos) + 1];
        strcpy(datos, other.datos);
    }
    
    // 3. Operador de asignación
    Cadena& operator=(const Cadena& other) {
        if (this != &other) {  // Protección auto-asignación
            delete[] datos;    // Liberar memoria antigua
            datos = new char[strlen(other.datos) + 1];
            strcpy(datos, other.datos);
        }
        return *this;
    }
    
    // 4. Destructor
    ~Cadena() { delete[] datos; }
};
```

#### Regla de los Tres (Rule of Three)

> Si necesitas definir **uno** de estos tres, probablemente necesites los **tres**:
> 1. Destructor
> 2. Constructor de copia
> 3. Operador de asignación

**Extensión moderna:** En C++11+ se convierte en la "Regla de los Cinco" (añade move constructor y move assignment).

#### Casos de Uso Críticos

| Escenario | ¿Necesita OCF? | Razón |
|-----------|----------------|-------|
| Clase con punteros (`char*`, objetos dinámicos) | **SÍ** | Evitar double-free y memory leaks |
| Clase con manejo de archivos/sockets | **SÍ** | Evitar cerrar el mismo descriptor dos veces |
| Clase solo con tipos primitivos (`int`, `float`) | **Opcional** | El compilador genera versiones correctas, pero OCF es buena práctica |
| Clase base para herencia | **SÍ** | Destructor virtual necesario |

---

### 2. Números de Punto Fijo (Fixed-Point Arithmetic)

#### ¿Por qué existen?

**Limitaciones de `int` y `float`:**

| Tipo | Problema | Ejemplo |
|------|----------|---------|
| `int` | No representa decimales | `int x = 10.5;` → `x = 10` (trunca) |
| `float` | Inexacto en binario | `0.1f + 0.2f ≠ 0.3f` (error de redondeo) |
| `float` | Lento en hardware sin FPU | Sistemas embebidos, DSP, GPUs antiguas |

**Solución del punto fijo:**
- Usar un **entero** para almacenar el valor
- Asumir implícitamente un "punto decimal" en posición fija
- Operaciones aritméticas de enteros (ALU) → **muy rápidas**

#### Formato Q24.8

En este proyecto usamos **8 bits fraccionarios** en un `int` de 32 bits:

```
┌─────────────────────────────┬─────────────┐
│  24 bits (parte entera)     │  8 bits (decimales) │
└─────────────────────────────┴─────────────┘
  Rango: -8388608 a 8388607     Precisión: 1/256 ≈ 0.0039
```

**Conversión:**
```cpp
Factor de escala = 2^8 = 256

// Float → Fixed
12.34f → 12.34 × 256 = 3159 (almacenado como int)

// Fixed → Float
3159 → 3159 / 256.0f = 12.339843... (pequeño error de redondeo)
```

#### Operaciones Aritméticas

**Suma/Resta: Directo**
```cpp
Fixed a(10.5f);  // Interno: 10.5 × 256 = 2688
Fixed b(2.25f);  // Interno: 2.25 × 256 = 576
Fixed c = a + b; // Interno: 2688 + 576 = 3264
                 // Externo: 3264 / 256 = 12.75
```

**Multiplicación: Ajuste necesario**
```cpp
Fixed a(2.0f);   // Interno: 512
Fixed b(3.0f);   // Interno: 768
// Multiplicación naive:
// 512 × 768 = 393216
// 393216 / 256 = 1536 (debería ser 6, pero da 1536!)

// CORRECTO:
// (a × 2^8) × (b × 2^8) = (a×b) × 2^16
// Necesitamos dividir por 2^8 para volver a formato correcto
long long temp = (long long)512 * 768; // 393216
int result = temp >> 8;                 // 393216 / 256 = 1536
                                        // Oops, aún incorrecto...

// La fórmula REAL:
result = (temp >> _fractionalBits);
// 393216 >> 8 = 1536 (valor interno)
// 1536 / 256 = 6.0 CORRECTO
```

**¿Por qué `long long`?**
- Multiplicar dos `int` de 32 bits puede producir overflow
- `long long` (64 bits) garantiza rango suficiente

#### Aplicaciones Reales

1. **Gráficos 2D/3D antiguos:**
   - PlayStation 1, Game Boy Advance
   - Cálculos de transformaciones sin FPU

2. **Procesamiento de audio:**
   - DSP (Digital Signal Processing)
   - Efectos en tiempo real (reverb, delay)

3. **Finanzas:**
   - Evitar errores de redondeo en dinero
   - Precisión decimal exacta (ej: centavos)

4. **Física de videojuegos:**
   - Determinismo multiplayer
   - Reproducibilidad exacta

---

### 3. Sobrecarga de Operadores

#### Reglas de Sobrecarga

**Operadores que PUEDEN sobrecargarse:**
```
Aritméticos:    +  -  *  /  %  ++  --
Comparación:    ==  !=  <  >  <=  >=
Lógicos:        &&  ||  !
Bitwise:        &  |  ^  ~  <<  >>
Asignación:     =  +=  -=  *=  /=  %=  &=  |=  ^=  <<=  >>=
Otros:          []  ()  ->  ,  new  delete  new[]  delete[]
```

**Operadores que NO PUEDEN sobrecargarse:**
```
::  (scope resolution)
.*  (member pointer)
.   (member access)
?:  (ternary operator)
sizeof
typeid
```

#### Cuándo Usar Miembro vs Función Global

| Operador | Implementación | Razón |
|----------|----------------|-------|
| `=`, `[]`, `()`, `->` | **Miembro obligatorio** | Estándar del lenguaje |
| `<<`, `>>` (I/O) | **Global** | Primer operando es `std::ostream` |
| `+`, `-`, `*`, `/` | **Global (amigo)** | Simetría: permite `2 + Fixed(3)` |
| `+=`, `-=`, `==`, `<` | **Miembro preferido** | Modifican o consultan `this` |

**Ejemplo de simetría:**
```cpp
// Como miembro:
class Fixed {
    Fixed operator+(const Fixed& other) const;
};

Fixed a(10);
Fixed b = a + Fixed(5); // OK
Fixed c = Fixed(5) + a; // ERROR: Fixed temporal no tiene método operator+

// Como función global amiga:
Fixed operator+(const Fixed& lhs, const Fixed& rhs) {
    Fixed result;
    result.setRawBits(lhs.getRawBits() + rhs.getRawBits());
    return result;
}

Fixed d = a + Fixed(5); // OK
Fixed e = Fixed(5) + a; // OK también
```

---

### 4. Const-Correctness

La disciplina de marcar correctamente métodos y parámetros como `const`.

#### Niveles de Constness

**1. Métodos constantes:**
```cpp
class Fixed {
    int getRawBits() const;  // Promete no modificar this
    void setRawBits(int);    // Puede modificar this
};

const Fixed a(10);
a.getRawBits();  // OK
a.setRawBits(20); // ERROR: método no-const en objeto const
```

**2. Parámetros constantes:**
```cpp
// Eficiencia: pasa por referencia (no copia)
// Seguridad: no puede modificar el parámetro
void print(const Fixed& value) {
    std::cout << value.toFloat() << std::endl;
}
```

**3. Retorno constante:**
```cpp
const Fixed& max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& result = max(x, y);
result.setRawBits(100); // ERROR: referencia const
```

#### Sobrecarga por Constness

C++ permite sobrecargar basándose en si `this` es constante:

```cpp
class Vector {
    int* data;
public:
    // Versión no-const: devuelve referencia modificable
    int& operator[](size_t i) { return data[i]; }
    
    // Versión const: devuelve referencia de solo lectura
    const int& operator[](size_t i) const { return data[i]; }
};

Vector v;
v[0] = 10;  // Usa versión no-const

const Vector cv;
cv[0] = 10; // ERROR: usa versión const, devuelve const int&
int x = cv[0]; // OK: solo lectura
```

---

### 5. this Pointer

#### ¿Qué es `this`?

Un **puntero implícito** a la instancia actual del objeto. Su tipo es `ClassName* const` (puntero constante a objeto).

```cpp
class Fixed {
    int _value;
public:
    void setValue(int value) {
        // Estas tres líneas son equivalentes:
        _value = value;
        this->_value = value;
        (*this)._value = value;
    }
};
```

#### ¿Cuándo es necesario usarlo explícitamente?

**1. Desambiguación de nombres:**
```cpp
class Point {
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;  // Necesario para distinguir parámetro vs miembro
        this->y = y;
    }
};
```

**2. Devolver el objeto actual:**
```cpp
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {  // Protección auto-asignación
        _fixedValue = other._fixedValue;
    }
    return *this;  // Devuelve el objeto actual
}
```

**3. Comparación de direcciones:**
```cpp
bool Fixed::operator==(const Fixed& other) const {
    if (this == &other) return true;  // Mismo objeto
    return _fixedValue == other._fixedValue;
}
```

#### ¿Punto o Flecha?

```cpp
this->member    // this es puntero → usa flecha
(*this).member  // Desreferencia el puntero → usa punto
```

**Regla mnemotécnica:**
- `this` (puntero) → `->` (flecha)
- `*this` (objeto) → `.` (punto)

---

### 6. Listas de Inicialización

#### Sintaxis
```cpp
class Point {
    const int x;
    const int y;
public:
    // Lista de inicialización (después del :)
    Point(int px, int py) : x(px), y(py) {
        // Cuerpo del constructor (x e y YA están inicializados aquí)
    }
};
```

#### ¿Por qué usarlas?

**1. Atributos constantes (obligatorio):**
```cpp
class Config {
    const int MAX_SIZE;
public:
    // CORRECTO
    Config(int size) : MAX_SIZE(size) {}
    
    // ERROR: no puedes asignar a const en el cuerpo
    Config(int size) {
        MAX_SIZE = size; // ERROR de compilación
    }
};
```

**2. Referencias (obligatorio):**
```cpp
class HumanA {
    Weapon& weapon;
public:
    HumanA(Weapon& w) : weapon(w) {}  // OK
    
    // ERROR: referencias deben inicializarse
    HumanA(Weapon& w) { weapon = w; }
};
```

**3. Eficiencia (tipos complejos):**
```cpp
class Person {
    std::string name;
public:
    // Ineficiente: 1 construcción + 1 asignación
    Person(const std::string& n) {
        name = n;  // Constructor vacío + operador=
    }
    
    // Eficiente: 1 construcción directa
    Person(const std::string& n) : name(n) {}
};
```

**4. Objetos sin constructor por defecto:**
```cpp
class Engine {
public:
    Engine(int power);  // No tiene Engine()
};

class Car {
    Engine engine;
public:
    // CORRECTO
    Car(int power) : engine(power) {}
    
    // ERROR: intenta llamar Engine() que no existe
    Car(int power) {
        engine = Engine(power);
    }
};
```

#### Orden de Inicialización

**CRÍTICO:** Los miembros se inicializan en el **orden de declaración**, NO en el orden de la lista.

```cpp
class Dangerous {
    int y;
    int x;
public:
    // x se inicializa PRIMERO (declarado primero)
    // ¡Pero y aún no tiene valor válido!
    Dangerous(int val) : y(val), x(y * 2) {}  // BUG
};
```

**Solución:** Reordenar declaración o evitar dependencias:
```cpp
class Safe {
    int x;  // Declarado primero
    int y;  // Declarado segundo
public:
    Safe(int val) : x(val), y(x * 2) {}  // OK
};
```

---

### 7. Epsilon (ε) en Punto Fijo

#### ¿Qué es epsilon?

El **valor más pequeño representable** tal que `1 + ε > 1`.

En punto fijo Q24.8:
```cpp
static const int _fractionalBits = 8;
// El bit menos significativo representa 1/256
Fixed epsilon;
epsilon.setRawBits(1);  // Valor interno = 1
// Valor real = 1 / 256 = 0.00390625
```

#### Uso en incremento/decremento

```cpp
Fixed& Fixed::operator++(void) {
    _fixedValue++;  // Incrementa en 1 (la unidad interna)
    return *this;   // Valor real aumenta en ε = 0.00390625
}
```

**Ejemplo:**
```cpp
Fixed a(1.0f);      // Interno: 256
std::cout << a;     // 1

++a;                // Interno: 257
std::cout << a;     // 1.00390625

++a;                // Interno: 258
std::cout << a;     // 1.0078125
```

---

## Aplicaciones Prácticas

### 1. Sistemas de Procesamiento de Señales (DSP)

**Audio Digital:**
```cpp
class AudioSample {
    Fixed amplitude;  // Rango [-1.0, 1.0] en punto fijo
public:
    void applyGain(Fixed gain) {
        amplitude = amplitude * gain;  // Multiplicación rápida sin FPU
    }
};
```

**Filtros FIR (Finite Impulse Response):**
```cpp
Fixed firFilter(const Fixed* samples, const Fixed* coefficients, int taps) {
    Fixed result;
    for (int i = 0; i < taps; ++i) {
        result = result + (samples[i] * coefficients[i]);
    }
    return result;
}
```

---

### 2. Motores de Videojuegos

**Física Determinista (Multiplayer):**
```cpp
class RigidBody {
    Fixed posX, posY;
    Fixed velX, velY;
public:
    void update(Fixed deltaTime) {
        posX = posX + (velX * deltaTime);
        posY = posY + (velY * deltaTime);
    }
};
```

**Ventaja:** Mismos resultados en todas las máquinas (sincronización).

**Ejemplo real:** *Age of Empires*, *Starcraft* usaban punto fijo para sincronización.

---

### 3. Sistemas Embebidos y FPGAs

**Control PID sin FPU:**
```cpp
class PIDController {
    Fixed Kp, Ki, Kd;
    Fixed integral, previousError;
public:
    Fixed compute(Fixed setpoint, Fixed measured) {
        Fixed error = setpoint - measured;
        integral = integral + error;
        Fixed derivative = error - previousError;
        
        previousError = error;
        return Kp * error + Ki * integral + Kd * derivative;
    }
};
```

**Aplicación:** Drones, robótica, automoción.

---

### 4. Gráficos 2D/3D

**Transformaciones Afines:**
```cpp
class Matrix2D {
    Fixed m[2][2];
public:
    Point transform(const Point& p) const {
        Fixed x = m[0][0] * p.getX() + m[0][1] * p.getY();
        Fixed y = m[1][0] * p.getX() + m[1][1] * p.getY();
        return Point(x.toFloat(), y.toFloat());
    }
};
```

**Rasterización de Triángulos (BSP):**
```cpp
// Determinar qué píxeles pintar en un triángulo
for (int y = yMin; y <= yMax; ++y) {
    for (int x = xMin; x <= xMax; ++x) {
        Point pixel(x, y);
        if (bsp(v0, v1, v2, pixel)) {
            setPixel(x, y, color);
        }
    }
}
```

---

### 5. Cálculos Financieros

**Dinero sin errores de redondeo:**
```cpp
class Money {
    Fixed amount;  // Centavos en punto fijo
public:
    Money(float dollars) : amount(dollars) {}
    
    Money operator+(const Money& other) const {
        Money result;
        result.amount = this->amount + other.amount;
        return result;
    }
    
    float toDollars() const { return amount.toFloat(); }
};

// Evita: 0.1 + 0.2 = 0.30000000000000004 (float)
// Da:     0.10 + 0.20 = 0.30 (punto fijo)
```

---

### 6. Algoritmos Geométricos

**Detección de Colisiones (BSP):**

```cpp
bool checkCollision(const Triangle& t, const Point& p) {
    return bsp(t.v0, t.v1, t.v2, p);
}
```

**Navegación y Pathfinding:**
- Dividir mapas en regiones convexas
- Determinar si un punto está en una zona segura/peligrosa

**Ejemplo real:**
- **Doom** (1993): BSP trees para renderizado y colisiones
- **Quake** (1996): BSP para visibilidad (PVS - Potentially Visible Set)

---

## Recursos Adicionales

### Sobre Punto Fijo
- [Fixed-Point Arithmetic - Berkeley](https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html)
- [Fixed-Point Numbers - Wikipedia](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- [Q Number Format](https://en.wikipedia.org/wiki/Q_(number_format))

### Sobre OCF y Diseño
- [Rule of Three/Five - cppreference](https://en.cppreference.com/w/cpp/language/rule_of_three)
- [Const Correctness - C++ FAQ](https://isocpp.org/wiki/faq/const-correctness)

### Sobre BSP
- [Binary Space Partitioning - Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs)
- [Doom Engine Black Book](https://fabiensanglard.net/gebbdoom/)

---

## Compilación y Uso

### Requisitos
- Compilador: `c++` (g++ o clang++) con soporte para C++98
- Make: GNU Make o compatible

### Compilar un ejercicio específico
```bash
cd ex00
make
./fixed
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

### Testing
```bash
# Ejecutar con logs de constructores/destructores
./fixed

# Verificar valores de conversión
./fixed | grep "is" | awk '{print $3}'
```

---

## Notas Técnicas

### Flags de Compilación Obligatorios
```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

- `-Wall -Wextra`: Warnings exhaustivos
- `-Werror`: Warnings como errores (código limpio obligatorio)
- `-std=c++98`: Estándar legacy

### Restricciones del Módulo

**Prohibido:**
- `using namespace std;`
- Funciones de C: `printf`, `malloc`, `free`
- STL containers (hasta CPP08/09)
- C++11+ features (auto, lambda, nullptr)
- `*printf()`, `*alloc()`, `free()`

**Permitido:**
- Standard library: `<iostream>`, `<string>`, `<cmath>`
- Función `roundf()` de `<cmath>`

---

## Preguntas de Defensa

### Sobre OCF

**P: ¿Por qué necesitas un constructor de copia si ya tienes operador de asignación?**

R: El constructor de copia se usa al **crear** un objeto nuevo: `Fixed b(a);` o `Fixed b = a;`
El operador de asignación se usa al **asignar** entre objetos existentes: `c = b;`

---

**P: ¿Qué pasa si olvidas el operador de asignación?**

R: El compilador genera uno por defecto que hace **shallow copy** (copia bit a bit). Si tu clase tiene punteros, dos objetos apuntarán a la misma memoria → **double free** al destruirse.

---

**P: ¿Por qué devolver `*this` en el operador de asignación?**

R: Para permitir **asignaciones encadenadas**: `a = b = c;`
Internamente: `a.operator=(b.operator=(c))`

---

### Sobre Punto Fijo

**P: ¿Por qué usar punto fijo en vez de float?**

R: 
1. **Performance:** Operaciones de enteros (ALU) más rápidas que FPU
2. **Determinismo:** Mismo resultado en todas las máquinas
3. **Hardware sin FPU:** Sistemas embebidos, DSP, consolas antiguas
4. **Precisión controlada:** Resolución constante en todo el rango

---

**P: ¿Cuál es el rango y precisión de tu Fixed?**

R:
- **Rango:** `-8388608.0` a `8388607.996` (24 bits enteros con signo)
- **Precisión:** `1/256 ≈ 0.00390625` (8 bits fraccionarios)
- **Epsilon:** `0.00390625` (el incremento mínimo)

---

**P: ¿Por qué la multiplicación necesita `long long`?**

R: Multiplicar dos `int` de 32 bits puede producir overflow:
```
INT_MAX × INT_MAX = 4,611,686,014,132,420,609 (requiere 64 bits)
```
`long long` garantiza 64 bits para almacenar el resultado temporal.

---

### Sobre Operadores

**P: ¿Cuál es la diferencia entre `++a` y `a++`?**

R:
- `++a` (pre): Incrementa primero, devuelve referencia al objeto modificado
- `a++` (post): Devuelve copia del valor antiguo, luego incrementa
- Post-incremento es **más lento** (crea copia temporal)

---

**P: ¿Por qué el operador `<<` no es miembro de la clase?**

R: Porque el primer operando (izquierda) es `std::ostream`, no `Fixed`. No podemos modificar la clase `std::ostream` del estándar, así que debe ser función global (usualmente amiga).

---

**P: ¿Por qué algunos operadores devuelven por valor y otros por referencia?**

R:
- **Referencia:** Operadores que modifican el objeto actual (`operator=`, `operator++`)
- **Valor:** Operadores que crean nuevos objetos (`operator+`, `operator*`)
  - No puedes devolver referencia a variable local (se destruye al salir)

---

### Sobre BSP

**P: ¿Qué devuelve tu función `bsp` si el punto está en el borde?**

R: `false`. El subject especifica que puntos en vértices o bordes deben devolver `false`.

---

**P: ¿Por qué usas producto cruzado en vez de calcular el área?**

R: El producto cruzado es más eficiente (3 multiplicaciones vs. cálculos de área + raíces cuadradas). Además, solo necesitamos el **signo**, no la magnitud.

---

**P: ¿Qué pasa si el triángulo está definido en sentido horario?**

R: Los signos de los productos cruzados se invierten, pero la lógica sigue funcionando: todos deben tener el mismo signo (ahora negativo en vez de positivo).

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

[⬆ Volver arriba](#-c-module-02---fixed-point--operator-overloading)

</div>
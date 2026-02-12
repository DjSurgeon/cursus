# C++ Module 03 - Inheritance

<div align="center">

> **Cuarto módulo de la piscina de C++** - Escuela 42  
> Herencia, modificadores de acceso y el problema del diamante

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

Cuarto módulo del currículum de C++ de 42, centrado en la **herencia** como pilar fundamental de la Programación Orientada a Objetos. Este proyecto explora jerarquías de clases, reutilización de código, polimorfismo y el infame **problema del diamante** en herencia múltiple.

### Objetivos Pedagógicos

- Herencia simple (`class Derived : public Base`)
- Modificadores de acceso (`public`, `protected`, `private`)
- Orden de construcción/destrucción en jerarquías
- Sobrescritura de métodos (method overriding)
- Palabra clave `virtual`
- Herencia múltiple
- Problema del diamante y herencia virtual
- Relación "Es un" (Is-a) vs "Tiene un" (Has-a)

---

## Ejercicios Implementados

### ex00: Aaaaand... OPEN!

**Conceptos:** Clase base, encapsulación, Orthodox Canonical Form, validación de estado

Implementación de la clase base `ClapTrap` que servirá como fundamento para las clases derivadas:

```cpp
class ClapTrap {
private:
    std::string _name;
    unsigned int _hitPoints;      // 10
    unsigned int _energyPoints;   // 10
    unsigned int _attackDamage;   // 0

public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
```

#### Lógica de Acciones

**Restricciones de recursos:**
- Atacar cuesta **1 punto de energía**
- Repararse cuesta **1 punto de energía**
- Sin **Hit Points** → El ClapTrap está "muerto", no puede hacer nada
- Sin **Energy Points** → No puede realizar acciones

```cpp
void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy!" << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" 
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0 || _energyPoints == 0) return;
    
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself, gaining "
              << amount << " hit points!" << std::endl;
}
```

**Aprendizaje clave:** Esta clase establece el contrato base que heredarán las especializaciones. Los mensajes de constructor/destructor son críticos para entender el orden de construcción.

---

### ex01: Serena, my love!

**Conceptos:** Herencia simple, orden de construcción/destrucción, `protected`, sobrescritura

Primera clase derivada que hereda de `ClapTrap`:

```cpp
class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void attack(const std::string& target);  // Sobrescribe
    void guardGate();                         // Nuevo método
};
```

#### Valores Especializados

| Atributo | ClapTrap | ScavTrap |
|----------|----------|----------|
| **Hit Points** | 10 | **100** |
| **Energy Points** | 10 | **50** |
| **Attack Damage** | 0 | **20** |

#### Implementación del Constructor

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called" << std::endl;
    
    // ScavTrap sobrescribe los valores heredados
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}
```

**¿Por qué llamar al constructor base?**
- La clase base (`ClapTrap`) debe inicializarse **antes** que la derivada
- Sin `: ClapTrap(name)`, se llamaría al constructor por defecto de `ClapTrap`
- Si `ClapTrap` no tiene constructor por defecto → **Error de compilación**

#### Orden de Construcción/Destrucción

**Al crear `ScavTrap robot("Serena")`:**
```
1. Constructor ClapTrap llamado   (Base primero)
2. Constructor ScavTrap llamado   (Derivada después)
```

**Al destruirse el objeto:**
```
1. Destructor ScavTrap llamado    (Derivada primero)
2. Destructor ClapTrap llamado    (Base después)
```

**Regla mnemotécnica:** "Se construye de la base a la cima, se destruye de la cima a la base" (como un edificio).

#### Sobrescritura del Método `attack()`

```cpp
void ScavTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) return;
    
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " furiously attacks " << target
              << ", causing " << _attackDamage << " points of damage!" 
              << std::endl;
}
```

**Nota:** Este NO es polimorfismo (falta `virtual`). Es **ocultación de métodos** (name hiding).

---

### ex02: Repetitive work

**Conceptos:** Múltiples clases derivadas, jerarquías paralelas, especialización

Segunda clase derivada de `ClapTrap`, similar a `ScavTrap` pero con valores distintos:

```cpp
class FragTrap : public ClapTrap {
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);  // Método único
};
```

#### Valores de FragTrap

| Atributo | ClapTrap | FragTrap |
|----------|----------|----------|
| **Hit Points** | 10 | **100** |
| **Energy Points** | 10 | **100** |
| **Attack Damage** | 0 | **30** |

#### Jerarquía Actual

```
        ClapTrap
         /    \
        /      \
   ScavTrap  FragTrap
```

**Características:**
- `ScavTrap` y `FragTrap` son **clases hermanas** (siblings)
- Heredan de la misma base pero **no se conocen entre sí**
- Cada una tiene su propia especialización

**Aprendizaje clave:** Entender que la herencia crea **jerarquías**, no solo pares padre-hijo. Múltiples clases pueden heredar de la misma base para especializarse de formas diferentes.

---

### ex03: Now it's weird! 💎

**Conceptos:** Herencia múltiple, problema del diamante, herencia virtual, shadowing

El ejercicio más complejo: una clase que hereda de **dos padres** que comparten un ancestro común.

#### El Problema del Diamante

```
      ClapTrap (Abuelo)
       /     \
      /       \
 ScavTrap   FragTrap (Padres)
      \       /
       \     /
     DiamondTrap (Nieto)
```

**Sin herencia virtual:**
```cpp
class ScavTrap : public ClapTrap { /* ... */ };
class FragTrap : public ClapTrap { /* ... */ };
class DiamondTrap : public ScavTrap, public FragTrap { /* ... */ };
```

**Problema:** `DiamondTrap` contendría **DOS copias** de `ClapTrap`:
- Una vía `ScavTrap`
- Otra vía `FragTrap`

**Síntomas:**
```cpp
DiamondTrap robot("Diamond");
robot._hitPoints = 100;  // ERROR: ¿robot.ScavTrap::_hitPoints o robot.FragTrap::_hitPoints?
```

#### La Solución: Herencia Virtual

```cpp
class ScavTrap : virtual public ClapTrap {
    // ...
};

class FragTrap : virtual public ClapTrap {
    // ...
};

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;  // Nombre propio del DiamondTrap

public:
    DiamondTrap(std::string name);
    
    void whoAmI();
};
```

**La palabra clave `virtual`:**
- Le dice al compilador: "Si aparece múltiple herencia de esta base, **fusiona las copias**"
- Garantiza una **única instancia** de `ClapTrap` compartida

#### Constructor de DiamondTrap

**Regla crítica:** En herencia virtual, la clase **más derivada** (la última en la jerarquía) es responsable de inicializar la base virtual.

```cpp
DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"),  // Inicializa al abuelo DIRECTAMENTE
      ScavTrap(name),                  // Estas llamadas se IGNORAN
      FragTrap(name),                  // para la construcción del ClapTrap
      _name(name)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    
    // Composición de atributos de ambos padres
    _hitPoints = FragTrap::_hitPoints;       // 100 (de FragTrap)
    _energyPoints = ScavTrap::_energyPoints; // 50 (de ScavTrap)
    _attackDamage = FragTrap::_attackDamage; // 30 (de FragTrap)
}
```

**¿Por qué se ignoran las llamadas a `ScavTrap(name)` y `FragTrap(name)`?**
- Normalmente, `ScavTrap` llamaría a `ClapTrap(name)`
- Pero como usamos **herencia virtual**, C++ sabe que `ClapTrap` ya fue construido por `DiamondTrap`
- Evita la **doble inicialización** del ancestro común

#### Orden de Construcción con Herencia Virtual

**Al crear `DiamondTrap diamond("Bob")`:**
```
1. ClapTrap constructor ("Bob_clap_name")  ← Abuelo primero
2. ScavTrap constructor                     ← Padre izquierdo
3. FragTrap constructor                     ← Padre derecho
4. DiamondTrap constructor                  ← Nieto último
```

**Destrucción (inverso):**
```
1. DiamondTrap destructor
2. FragTrap destructor
3. ScavTrap destructor
4. ClapTrap destructor
```

#### Atributo `_name` y Shadowing

El subject pide que `DiamondTrap` tenga un atributo `_name` **con el mismo nombre** que el de `ClapTrap`.

```cpp
class ClapTrap {
protected:
    std::string _name;  // Nombre del ClapTrap
    // ...
};

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;  // ⚠️ SOMBREA (shadows) al _name del padre
    // ...
};
```

**Consecuencia del shadowing:**
```cpp
void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name              // DiamondTrap::_name
              << " and my ClapTrap name is " 
              << ClapTrap::_name               // ClapTrap::_name (requiere ::)
              << std::endl;
}
```

**Flags del compilador:**
- `-Wshadow`: **Advierte** sobre variables sombreadas (warning)
- `-Wno-shadow`: **Silencia** esas advertencias

**En este ejercicio:** Se menciona `-Wshadow` porque el sombreado es **intencional** según el subject, pero normalmente es una **mala práctica**.

#### Método `whoAmI()`

```cpp
void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->_name 
              << " and my ClapTrap name is " << ClapTrap::_name 
              << std::endl;
}
```

**Ejemplo de salida:**
```
I am Bob and my ClapTrap name is Bob_clap_name
```

#### Herencia de Métodos

| Método | Origen | Justificación |
|--------|--------|---------------|
| `attack()` | `ScavTrap` | El subject especifica que use el ataque de ScavTrap |
| `guardGate()` | `ScavTrap` | Heredado automáticamente |
| `highFivesGuys()` | `FragTrap` | Heredado automáticamente |
| `whoAmI()` | `DiamondTrap` | Único de esta clase |

**Para forzar el uso del método específico de ScavTrap:**
```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
public:
    using ScavTrap::attack;  // Resuelve la ambigüedad
    // O bien:
    void attack(const std::string& target) {
        ScavTrap::attack(target);  // Delegación explícita
    }
};
```

---

## 🧠 Conceptos Clave Aprendidos

### 1. Herencia (Inheritance)

#### ¿Qué es la Herencia?

La herencia es un mecanismo que permite definir una nueva clase (derivada/hija) basándose en una clase existente (base/padre), reutilizando y extendiendo su funcionalidad.

**Beneficios:**
1. **Reutilización de código:** No reescribir lo que ya existe
2. **Especialización:** Añadir comportamiento específico
3. **Mantenibilidad:** Cambios en la base se propagan a las derivadas
4. **Polimorfismo:** Base para el polimorfismo en tiempo de ejecución

#### Sintaxis Básica

```cpp
class Base {
protected:
    int valor;
public:
    Base(int v) : valor(v) {}
    void mostrar() { std::cout << valor << std::endl; }
};

class Derivada : public Base {
public:
    Derivada(int v) : Base(v) {}  // Llama al constructor de la base
    void duplicar() { valor *= 2; }  // Accede a 'valor' protegido
};
```

#### La Relación "Es un" (Is-a)

**Regla de oro:** Usa herencia solo si la relación es "Es un".

✅ **Correcto:**
- `Perro` es un `Animal` → Herencia
- `ScavTrap` es un `ClapTrap` → Herencia
- `Coche` es un `Vehículo` → Herencia

❌ **Incorrecto:**
- `Coche` tiene un `Motor` → **Composición**, no herencia
- `Persona` tiene una `Dirección` → **Composición**

**Ejemplo de composición (Has-a):**
```cpp
class Motor {
    int caballos;
};

class Coche {
private:
    Motor motor;  // Composición: Coche TIENE UN Motor
};
```

---

### 2. Modificadores de Acceso

Los modificadores controlan **quién** puede acceder a los miembros de una clase.

#### Tabla de Accesibilidad

| Modificador | Propia Clase | Clases Derivadas | Mundo Exterior |
|-------------|--------------|------------------|----------------|
| `public` | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private` | ✅ | ❌ | ❌ |

#### `private` (Privado)

**Acceso:** Solo desde la propia clase.

```cpp
class CuentaBancaria {
private:
    double saldo;  // Nadie puede tocar esto directamente

public:
    void depositar(double cantidad) {
        saldo += cantidad;  // OK: estamos DENTRO de la clase
    }
};

int main() {
    CuentaBancaria cuenta;
    // cuenta.saldo = 1000000;  // ERROR: saldo es privado
    cuenta.depositar(100);      // OK: método público
}
```

**Uso:** Proteger datos críticos que no deben ser modificados arbitrariamente.

#### `public` (Público)

**Acceso:** Desde cualquier parte del código.

```cpp
class Punto {
public:
    int x, y;  // Acceso libre
    
    void mostrar() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Punto p;
    p.x = 10;  // OK: x es público
    p.mostrar();  // OK: mostrar() es público
}
```

**Uso:** Interfaz pública de la clase (métodos que los usuarios deben usar).

#### `protected` (Protegido)

**Acceso:** Solo desde la propia clase **y clases derivadas**.

```cpp
class Vehiculo {
protected:
    int velocidadMaxima;  // Hijos pueden acceder, mundo exterior no

public:
    Vehiculo(int vel) : velocidadMaxima(vel) {}
};

class Deportivo : public Vehiculo {
public:
    Deportivo(int vel) : Vehiculo(vel) {}
    
    void turbo() {
        velocidadMaxima += 50;  // OK: acceso a miembro protegido del padre
    }
};

int main() {
    Deportivo ferrari(300);
    // ferrari.velocidadMaxima = 500;  // ERROR: es protected
    ferrari.turbo();  // OK: método público que internamente usa protected
}
```

**Uso crítico:** Es la **clave de la herencia**. Permite que las clases hijas extiendan funcionalidad sin exponer detalles al mundo exterior.

**Regla de diseño:**
- **Datos:** `private` o `protected` (nunca `public` a menos que sean constantes)
- **Métodos:** `public` (interfaz) o `protected` (utilidades para hijos)

---

### 3. Orden de Construcción y Destrucción

#### Regla Fundamental

**Construcción:** De la base a la derivada (abajo → arriba en el diagrama).  
**Destrucción:** De la derivada a la base (arriba → abajo en el diagrama).

#### Ejemplo con Jerarquía

```cpp
class Abuelo {
public:
    Abuelo() { std::cout << "1. Abuelo constructor\n"; }
    ~Abuelo() { std::cout << "6. Abuelo destructor\n"; }
};

class Padre : public Abuelo {
public:
    Padre() { std::cout << "2. Padre constructor\n"; }
    ~Padre() { std::cout << "5. Padre destructor\n"; }
};

class Hijo : public Padre {
public:
    Hijo() { std::cout << "3. Hijo constructor\n"; }
    ~Hijo() { std::cout << "4. Hijo destructor\n"; }
};

int main() {
    Hijo h;  // Crea el objeto
    return 0;  // Sale del scope → destruye el objeto
}
```

**Salida:**
```
1. Abuelo constructor
2. Padre constructor
3. Hijo constructor
4. Hijo destructor
5. Padre destructor
6. Abuelo destructor
```

#### ¿Por qué este orden?

**Construcción (base → derivada):**
- La clase derivada **depende** de la base (usa sus miembros)
- Primero debes construir los cimientos (base) antes del edificio (derivada)
- Sin la base inicializada, la derivada no tiene sobre qué construirse

**Destrucción (derivada → base):**
- La derivada puede estar usando recursos de la base
- Primero destruyes lo que depende (derivada)
- Luego destruyes aquello de lo que dependía (base)
- Es el orden inverso de construcción

**Analogía:** Un edificio se construye de los cimientos al tejado, pero se derriba del tejado a los cimientos.

---

### 4. Sobrescritura de Métodos (Method Overriding)

#### Definición

La sobrescritura permite que una clase derivada **redefina** el comportamiento de un método heredado de la base.

#### Sin `virtual` (Ocultación, no sobrescritura)

```cpp
class Animal {
public:
    void hacerSonido() {  // NO es virtual
        std::cout << "Sonido genérico\n";
    }
};

class Perro : public Animal {
public:
    void hacerSonido() {  // Oculta (hide) el método de la base
        std::cout << "¡Guau!\n";
    }
};

int main() {
    Perro miPerro;
    miPerro.hacerSonido();  // "¡Guau!" (OK, llama a Perro::hacerSonido)
    
    Animal* ptrAnimal = &miPerro;  // Puntero de tipo base apuntando a derivada
    ptrAnimal->hacerSonido();  // "Sonido genérico" ❌ (enlace estático)
}
```

**Problema:** El puntero de tipo `Animal*` llama a `Animal::hacerSonido()` aunque apunte a un `Perro`. Esto se llama **enlace estático** (static binding).

#### Con `virtual` (Sobrescritura real)

```cpp
class Animal {
public:
    virtual void hacerSonido() {  // ✅ Ahora es virtual
        std::cout << "Sonido genérico\n";
    }
    virtual ~Animal() {}  // Destructor virtual (obligatorio)
};

class Perro : public Animal {
public:
    void hacerSonido() override {  // C++11: confirma sobrescritura
        std::cout << "¡Guau!\n";
    }
};

int main() {
    Animal* ptrAnimal = new Perro();
    ptrAnimal->hacerSonido();  // "¡Guau!" ✅ (enlace dinámico)
    delete ptrAnimal;  // Llama al destructor de Perro, luego de Animal
}
```

**Solución:** Con `virtual`, el compilador usa **enlace dinámico** (dynamic binding) mediante la **vtable** (tabla virtual).

#### Palabra Clave `override` (C++11)

```cpp
class Base {
public:
    virtual void funcion(int x);
};

class Derivada : public Base {
public:
    void funcion(int x) override;  // ✅ Confirma que sobrescribe
    // void funcion(float x) override;  // ❌ ERROR: no sobrescribe nada (parámetro distinto)
};
```

**Beneficios:**
1. **Documentación:** Deja claro que intentas sobrescribir
2. **Seguridad:** Si te equivocas en la firma, el compilador te avisa

#### Llamar a la Versión Base

A veces quieres **extender** el comportamiento, no reemplazarlo:

```cpp
class Animal {
public:
    virtual void hacerSonido() {
        std::cout << "El animal hace un sonido\n";
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        Animal::hacerSonido();  // Llama a la versión de la base
        std::cout << "Y ese sonido es: ¡Guau!\n";
    }
};
```

**Salida:**
```
El animal hace un sonido
Y ese sonido es: ¡Guau!
```

#### Sobrescritura vs Sobrecarga

| Concepto | Definición | Dónde ocurre | Cuándo se resuelve |
|----------|------------|--------------|---------------------|
| **Overriding** (Sobrescritura) | Misma función, diferente clase (herencia) | Clase derivada | Runtime (dinámico) |
| **Overloading** (Sobrecarga) | Mismo nombre, diferentes parámetros | Misma clase/namespace | Compile time (estático) |

**Ejemplo de sobrecarga:**
```cpp
class Calculadora {
public:
    int sumar(int a, int b) { return a + b; }
    float sumar(float a, float b) { return a + b; }  // Sobrecarga
};
```

---

### 5. Herencia Múltiple

#### Concepto

Una clase puede heredar de **más de una clase base** simultáneamente.

```cpp
class A {
public:
    void funcionA() { std::cout << "A\n"; }
};

class B {
public:
    void funcionB() { std::cout << "B\n"; }
};

class C : public A, public B {  // Hereda de A Y B
public:
    void funcionC() {
        funcionA();  // De A
        funcionB();  // De B
        std::cout << "C\n";
    }
};
```

**Casos de uso válidos:**
- Interfaces múltiples (aunque en C++98 no hay `interface` formal)
- Combinar funcionalidades ortogonales (ej: `Serializable` + `Drawable`)

---

### 6. El Problema del Diamante

#### Escenario

```
      Dispositivo
       /     \
      /       \
  Escaner   Impresora
      \       /
       \     /
    Fotocopiadora
```

**Sin herencia virtual:**

```cpp
class Dispositivo {
public:
    int id;
};

class Escaner : public Dispositivo {};
class Impresora : public Dispositivo {};

class Fotocopiadora : public Escaner, public Impresora {};

int main() {
    Fotocopiadora multi;
    // multi.id = 10;  // ERROR: ambiguo (¿Escaner::id o Impresora::id?)
    
    // Solución fea (desambiguación manual):
    multi.Escaner::id = 10;
    multi.Impresora::id = 20;  // ¡Ahora hay DOS variables 'id' en memoria!
}
```

**Problemas:**
1. **Duplicación de memoria:** Dos copias de `Dispositivo`
2. **Ambigüedad:** ¿A cuál `id` te refieres?

#### Solución: Herencia Virtual

```cpp
class Dispositivo {
public:
    int id;
    Dispositivo(int x) : id(x) {}
};

class Escaner : virtual public Dispositivo {  // ✅ virtual
public:
    Escaner(int x) : Dispositivo(x) {}
};

class Impresora : virtual public Dispositivo {  // ✅ virtual
public:
    Impresora(int x) : Dispositivo(x) {}
};

class Fotocopiadora : public Escaner, public Impresora {
public:
    // La clase más derivada inicializa al ancestro común
    Fotocopiadora(int x) : Dispositivo(x), Escaner(x), Impresora(x) {}
};

int main() {
    Fotocopiadora multi(42);
    multi.id = 100;  // ✅ OK: Solo hay UNA copia de 'id'
}
```

**Cómo funciona:**
- `virtual` le dice al compilador: "Fusiona las copias de esta base si aparece múltiples veces"
- La clase **más derivada** (`Fotocopiadora`) es responsable de llamar al constructor de la base virtual (`Dispositivo`)
- Las llamadas a `Dispositivo(x)` dentro de `Escaner` e `Impresora` se **ignoran** en este contexto

#### Orden de Construcción con Herencia Virtual

**Para `Fotocopiadora multi(42)`:**
```
1. Dispositivo(42)      ← Base virtual primero (una sola vez)
2. Escaner(42)          ← Padre izquierdo
3. Impresora(42)        ← Padre derecho
4. Fotocopiadora(42)    ← Clase derivada
```

**Destrucción (inverso):**
```
1. Fotocopiadora
2. Impresora
3. Escaner
4. Dispositivo
```

---

### 7. Shadowing (Sombreado de Variables)

#### Definición

Ocurre cuando una clase derivada declara un miembro con el **mismo nombre** que un miembro de la clase base.

```cpp
class Base {
protected:
    std::string nombre;
};

class Derivada : public Base {
private:
    std::string nombre;  // ⚠️ SOMBREA (shadows) a Base::nombre
};
```

**Consecuencia:**
```cpp
void Derivada::mostrar() {
    std::cout << nombre;         // Derivada::nombre (la local)
    std::cout << Base::nombre;   // Base::nombre (requiere ::)
}
```

#### ¿Cuándo es aceptable?

**Normalmente:** Es una **mala práctica** (confuso y propenso a errores).

**En ex03:** Es **intencional** según el subject (para demostrar comprensión del sombreado).

**Flags del compilador:**
- `-Wshadow`: Activa warnings sobre shadowing
- `-Wno-shadow`: Silencia esos warnings (útil si el shadowing es deliberado)

---

## 🚀 Aplicaciones Prácticas

### 1. Jerarquías de Clases en GUIs

**Frameworks gráficos** (Qt, GTK, wxWidgets) usan herencia extensivamente:

```cpp
class Widget {  // Clase base
protected:
    int x, y, width, height;
public:
    virtual void draw() = 0;  // Método puro virtual
    virtual void handleEvent(Event& e) = 0;
};

class Button : public Widget {
public:
    void draw() override {
        // Dibuja un botón
    }
    void handleEvent(Event& e) override {
        if (e.type == CLICK) {
            onClick();
        }
    }
private:
    void onClick() { /* acción */ }
};

class TextBox : public Widget {
public:
    void draw() override { /* dibuja cuadro de texto */ }
    void handleEvent(Event& e) override { /* maneja teclado */ }
};
```

**Ventaja:** El sistema puede manejar todos los widgets de forma uniforme mediante punteros `Widget*`.

---

### 2. Sistemas de Entidades en Videojuegos

**Motor de juego típico:**

```cpp
class GameObject {  // Base
protected:
    float posX, posY;
    bool active;
public:
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
    virtual ~GameObject() {}
};

class Enemy : public GameObject {
    int health;
public:
    void update(float deltaTime) override {
        // IA del enemigo
    }
    void render() override {
        // Renderizar sprite de enemigo
    }
};

class Player : public GameObject {
    int lives;
    std::vector<Item*> inventory;
public:
    void update(float deltaTime) override {
        // Procesar input del jugador
    }
    void render() override {
        // Renderizar personaje
    }
};
```

**Gestión centralizada:**
```cpp
class GameWorld {
    std::vector<GameObject*> objects;
public:
    void updateAll(float deltaTime) {
        for (GameObject* obj : objects) {
            obj->update(deltaTime);  // Polimorfismo
        }
    }
};
```

---

### 3. Patrones de Diseño

#### Patrón Strategy

```cpp
class SortStrategy {  // Base
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortStrategy() {}
};

class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        // Implementación de QuickSort
    }
};

class MergeSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        // Implementación de MergeSort
    }
};

class Sorter {
    SortStrategy* strategy;
public:
    void setStrategy(SortStrategy* s) { strategy = s; }
    void sortData(std::vector<int>& data) {
        strategy->sort(data);  // Polimorfismo
    }
};
```

#### Patrón Template Method

```cpp
class DataProcessor {  // Base
public:
    void process() {  // Método plantilla
        loadData();
        processData();  // Paso variable (virtual)
        saveData();
    }
protected:
    virtual void processData() = 0;  // Sobrescrito por derivadas
private:
    void loadData() { /* siempre igual */ }
    void saveData() { /* siempre igual */ }
};

class CSVProcessor : public DataProcessor {
protected:
    void processData() override {
        // Lógica específica para CSV
    }
};
```

---

### 4. Sistemas de Tipos en Compiladores

**AST (Abstract Syntax Tree):**

```cpp
class ASTNode {  // Base
public:
    virtual void codegen() = 0;  // Generar código
    virtual ~ASTNode() {}
};

class NumberNode : public ASTNode {
    int value;
public:
    void codegen() override {
        // Emitir instrucción para cargar número
    }
};

class BinaryOpNode : public ASTNode {
    ASTNode* left;
    ASTNode* right;
    char op;
public:
    void codegen() override {
        left->codegen();
        right->codegen();
        // Emitir instrucción de operación
    }
};
```

---

### 5. Frameworks de Testing

```cpp
class TestCase {  // Base
public:
    void run() {
        setUp();
        runTest();  // Virtual
        tearDown();
    }
protected:
    virtual void setUp() {}
    virtual void runTest() = 0;
    virtual void tearDown() {}
};

class DatabaseTest : public TestCase {
protected:
    void setUp() override {
        // Conectar a BD de prueba
    }
    void runTest() override {
        // Probar operaciones CRUD
    }
    void tearDown() override {
        // Limpiar BD
    }
};
```

---

### 6. Herencia Múltiple en Mixins

**Mixins** son clases que añaden funcionalidad específica:

```cpp
class Serializable {  // Mixin
public:
    virtual std::string serialize() = 0;
    virtual ~Serializable() {}
};

class Loggable {  // Mixin
public:
    void log(const std::string& msg) {
        std::cout << "[LOG] " << msg << std::endl;
    }
};

class User : public Serializable, public Loggable {
    std::string name;
public:
    std::string serialize() override {
        log("Serializando usuario");
        return "{\"name\":\"" + name + "\"}";
    }
};
```

---

## 📚 Recursos Adicionales

### Sobre Herencia
- [Inheritance - cppreference](https://en.cppreference.com/w/cpp/language/inheritance)
- [Virtual Functions - LearnCpp](https://www.learncpp.com/cpp-tutorial/virtual-functions/)
- [Diamond Problem - Wikipedia](https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem)

### Sobre Diseño
- [Composition vs Inheritance](https://www.thoughtworks.com/insights/blog/composition-vs-inheritance-how-choose)
- [SOLID Principles](https://en.wikipedia.org/wiki/SOLID)

---

## 🛠️ Compilación y Uso

### Requisitos
- Compilador: `c++` (g++ o clang++) con soporte para C++98
- Make: GNU Make o compatible

### Compilar un ejercicio específico
```bash
cd ex00
make
./claptrap
```

### Compilar todos los ejercicios
```bash
for dir in ex0{0,1,2,3}; do
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
# Verificar orden de construcción/destrucción
./claptrap | grep "constructor\|destructor"

# Para ex03 (DiamondTrap)
c++ -Wall -Wextra -Werror -Wshadow -std=c++98 *.cpp
```

---

## ⚙️ Notas Técnicas

### Flags de Compilación Obligatorios
```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

**Para ex03:**
```makefile
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
# O si quieres silenciar las advertencias de shadowing:
CXXFLAGS = -Wall -Wextra -Werror -Wno-shadow -std=c++98
```

### Restricciones del Módulo

**Prohibido:**
- `using namespace std;`
- Funciones de C: `printf`, `malloc`, `free`
- STL containers (hasta CPP08/09)
- C++11+ features
- Implementaciones en headers (excepto templates)

**Permitido:**
- Standard library: `<iostream>`, `<string>`
- Orthodox Canonical Form (OCF)
- Herencia virtual

---

## 🎓 Preguntas de Defensa

### Sobre Herencia

**P: ¿Cuál es la diferencia entre herencia y composición?**

R: 
- **Herencia (Is-a):** `Perro` **es un** `Animal` → `class Perro : public Animal`
- **Composición (Has-a):** `Coche` **tiene un** `Motor` → `class Coche { Motor motor; }`

La herencia crea una relación jerárquica donde la derivada puede ser tratada como la base. La composición es más flexible (cambiar componentes en runtime) y suele ser preferida según el principio "Favor composition over inheritance".

---

**P: ¿Por qué el orden de destrucción es inverso al de construcción?**

R: Porque la clase derivada **depende** de la base. Si destruyeras la base primero, la derivada quedaría con referencias a memoria ya liberada. Es como derribar un edificio: primero quitas el tejado (derivada) y luego los cimientos (base).

---

**P: ¿Qué pasa si olvidas llamar al constructor de la base en la derivada?**

R: Si la base tiene constructor por defecto, se llama automáticamente (pero puede no inicializar correctamente). Si la base **NO** tiene constructor por defecto, obtienes un **error de compilación**.

```cpp
class Base {
public:
    Base(int x) {}  // No hay constructor por defecto
};

class Derivada : public Base {
public:
    Derivada() {}  // ERROR: no se puede construir Base
    
    // CORRECTO:
    Derivada() : Base(10) {}
};
```

---

### Sobre Modificadores de Acceso

**P: ¿Cuándo usar `protected` vs `private`?**

R:
- **`private`:** Si **nadie** (ni siquiera las clases derivadas) debe acceder directamente al miembro.
- **`protected`:** Si las clases derivadas necesitan acceder para **extender** funcionalidad, pero el mundo exterior no debe verlo.

**Regla general:** Empieza con `private`. Solo usa `protected` si tienes una razón clara para permitir acceso a las derivadas.

---

**P: ¿Los miembros `private` se heredan?**

R: **Técnicamente sí, pero no son accesibles.** La clase derivada contiene el miembro `private` en memoria, pero no puede usarlo directamente. Solo puede acceder a través de métodos `public` o `protected` de la base.

```cpp
class Base {
private:
    int secreto = 42;
public:
    int getSecreto() { return secreto; }
};

class Derivada : public Base {
    void intentar() {
        // std::cout << secreto;  // ERROR: secreto es privado
        std::cout << getSecreto();  // OK: método público
    }
};
```

---

### Sobre Sobrescritura

**P: ¿Qué pasa si sobrescribes un método sin `virtual`?**

R: Obtienes **ocultación** (name hiding), no sobrescritura polimórfica:

```cpp
class Base { void func() { } };  // NO virtual
class Derivada : public Base { void func() { } };

Base* ptr = new Derivada();
ptr->func();  // Llama a Base::func (enlace estático)
```

Sin `virtual`, el método que se llama depende del **tipo del puntero**, no del tipo real del objeto.

---

**P: ¿Por qué usar `override` si es opcional?**

R: Porque **previene errores silenciosos**:

```cpp
class Base {
    virtual void procesar(int x);
};

class Derivada : public Base {
    void procesar(float x) override;  // ERROR: no sobrescribe nada (tipo distinto)
    // Sin override, esto compilaría pero sería una nueva función (sobrecarga)
};
```

`override` fuerza al compilador a verificar que realmente estás sobrescribiendo algo de la base.

---

### Sobre Herencia Múltiple

**P: ¿Cuándo es apropiado usar herencia múltiple?**

R: 
✅ **Casos válidos:**
- Interfaces/Mixins (añadir capacidades ortogonales): `Serializable`, `Loggable`
- Combinar funcionalidades independientes: `Volador` + `Nadador` para `Pato`

❌ **Evitar si:**
- Crea ambigüedad confusa
- Puedes lograr lo mismo con composición
- No tienes claro cómo resolver el problema del diamante

**Principio:** Prefiere composición sobre herencia múltiple.

---

**P: ¿Qué es la vtable y cómo funciona?**

R: La **vtable** (virtual table) es una tabla de punteros a funciones virtuales, creada por el compilador para implementar polimorfismo:

1. Cada clase con funciones virtuales tiene una vtable
2. Cada objeto tiene un puntero oculto (**vptr**) que apunta a la vtable de su clase
3. Al llamar a una función virtual, se sigue el vptr → vtable → función correcta

```cpp
class Base {
    virtual void func();  // Crea vtable
};

class Derivada : public Base {
    void func() override;  // Actualiza entrada en vtable
};

Base* ptr = new Derivada();
ptr->func();  // vptr → vtable de Derivada → Derivada::func()
```

---

### Sobre el Problema del Diamante

**P: ¿Qué hace exactamente la palabra clave `virtual` en herencia?**

R: Le dice al compilador: "Si esta clase base aparece múltiples veces en la jerarquía, **fusiónalas en una sola instancia compartida**".

Sin `virtual`:
```
     ClapTrap (Copia 1)
         |
    ScavTrap
         |              ClapTrap (Copia 2)
          \                 /
           \               /
            \             /
             \           /
              DiamondTrap
```

Con `virtual`:
```
         ClapTrap (UNA sola copia)
          /      \
         /        \
    ScavTrap   FragTrap
         \        /
          \      /
       DiamondTrap
```

---

**P: ¿Por qué DiamondTrap debe inicializar ClapTrap directamente?**

R: Porque con herencia virtual, la clase **más derivada** es responsable de construir la base virtual. Esto evita que `ClapTrap` se construya dos veces (una vía `ScavTrap` y otra vía `FragTrap`).

```cpp
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap"),  // ← Responsabilidad de DiamondTrap
      ScavTrap(name),             // Su llamada a ClapTrap() se ignora
      FragTrap(name)              // Su llamada a ClapTrap() se ignora
{ }
```

---

**P: ¿Hay overhead de rendimiento con herencia virtual?**

R: **Sí, un poco:**
- Se necesita un puntero extra (vptr) para la base virtual
- Indirección adicional al acceder a miembros de la base

Pero es **irrelevante** en la mayoría de aplicaciones. Solo importa en código crítico de rendimiento (kernel, motores gráficos).

---

## 👨‍💻 Autor

**Sergio Jiménez de la Cruz**

- [Github](https://github.com/DjSurgeon)
- [Linkedin](https://www.linkedin.com/in/sergiojimenez42dev/)
- [Email](djsurgeon83@gmail.com)

---

## 📝 Licencia

Este proyecto es parte del curriculum de 42 School y está sujeto a sus políticas académicas.  
El código está disponible con fines educativos.

---

<div align="center">

**⭐ Si este repositorio te ayudó, considera darle una estrella ⭐**

[⬆ Volver arriba](#-c-module-03---inheritance)

</div>
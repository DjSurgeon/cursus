### 1. Herencia (Inheritance)

**¿Qué es?**
La herencia es una de las piedras angulares de la Programación Orientada a Objetos (POO) en C++. Es un mecanismo que permite definir una nueva clase (llamada **clase derivada** o subclase) basándose en una clase que ya existe (llamada **clase base** o superclase),.

La clase derivada hereda ("adquiere") automáticamente todos los atributos y métodos de la clase base,. Esto permite crear clasificaciones jerárquicas, yendo de lo general a lo específico.

**La relación "Es un" (Is-a):**
Para saber si debes usar herencia, aplica la prueba "es un". Si la Clase B "es un" tipo de Clase A (ej. un Auto *es un* Vehículo), entonces la herencia es correcta. Si la relación es "tiene un" (ej. un Auto *tiene un* Motor), se debe usar **composición**, no herencia,.

### Beneficios Principales

1.  **Reutilización de código:** No necesitas volver a escribir el código que ya existe y ha sido probado en la clase base. La clase derivada aprovecha esa funcionalidad inmediatamente,.
2.  **Especialización:** Puedes añadir nuevos atributos y métodos a la clase derivada para hacerla más específica, o redefinir (override) el comportamiento de los métodos heredados,.
3.  **Consistencia de la interfaz:** Al heredar de una misma clase base, se garantiza que un conjunto de clases comparta una interfaz común, facilitando su uso y el polimorfismo.
4.  **Mantenibilidad:** Si hay un error en la lógica común (clase base), se corrige en un solo lugar y la corrección se propaga a todas las clases derivadas.

### Sintaxis Básica y Modificadores de Acceso

La sintaxis general para declarar una herencia es:

```cpp
class ClaseDerivada : acceso ClaseBase {
    // Cuerpo de la clase derivada
};
```

El especificador de `acceso` (public, private, protected) determina cómo la clase derivada "ve" los miembros de la clase base.

*   **: public Base** (El más común):
    *   Los miembros `public` de la base siguen siendo `public` en la derivada.
    *   Los miembros `protected` de la base siguen siendo `protected` en la derivada.
    *   Los miembros `private` de la base **nunca** son accesibles directamente por la derivada.

**El modificador `protected` (Protegido):**
Para que una clase hija pueda acceder a los atributos de su padre, pero estos sigan ocultos para el resto del mundo, se deben declarar como `protected` en la clase base,.

### Ejemplo de Código

A continuación, un ejemplo completo combinando los conceptos de las fuentes (Operaciones) y (Animales) para ilustrar la sintaxis, el acceso `protected` y la reutilización.

```cpp
#include <iostream>
#include <string>

// --- CLASE BASE ---
class Animal {
protected: 
    // 'protected' permite que las clases hijas (como Perro) accedan a 'nombre',
    // pero impide que se acceda desde el main() directamente.
    std::string nombre; 

public:
    Animal(std::string n) : nombre(n) { // Constructor base
        std::cout << "-> Constructor Animal llamado para " << nombre << "\n";
    }

    // Método que será heredado
    void comer() {
        std::cout << nombre << " esta comiendo generica-mente.\n";
    }
};

// --- CLASE DERIVADA ---
// Sintaxis: class Derivada : public Base
class Perro : public Animal { 
public:
    // El constructor de la derivada debe invocar al constructor de la base.
    Perro(std::string n) : Animal(n) { 
        std::cout << "-> Constructor Perro llamado\n";
    }

    // Método propio de la subclase (Especialización)
    void ladrar() {
        // Podemos acceder a 'nombre' porque es protected en la base
        std::cout << nombre << " dice: ¡Guau, guau!\n";
    }
};

int main() {
    std::cout << "--- Creando objeto ---\n";
    Perro miPerro("Rex"); // Se llama primero al constructor de Animal, luego al de Perro

    std::cout << "\n--- Usando metodos ---\n";
    miPerro.comer();  // Método reutilizado de la clase Animal
    miPerro.ladrar(); // Método propio de la clase Perro

    return 0;
}
```

**Detalles importantes del ejemplo:**
1.  **Orden de construcción:** Al crear `miPerro`, primero se ejecuta el constructor de `Animal` y luego el de `Perro`. Al destruir el objeto, el orden es inverso (primero `Perro`, luego `Animal`).
2.  **Inicialización:** La clase derivada utiliza la lista de inicialización `: Animal(n)` para pasar argumentos al constructor de la clase base.

---

### Definiciones Concretas

En la Programación Orientada a Objetos (POO), la **herencia** permite crear nuevas clases a partir de clases existentes. Esto establece una relación jerárquica:

1.  **Clase Base (Padre o Superclase):**
    Es la clase original que define atributos y comportamientos generales. Actúa como una plantilla genérica. No depende de las clases que heredan de ella,.

2.  **Clase Derivada (Hija o Subclase):**
    Es la nueva clase que "nace" de la clase base. Hereda automáticamente los miembros (atributos y métodos) de la base y puede añadir sus propios miembros nuevos o modificar los heredados. Es una **especialización** de la clase base,.

**Regla de Oro ("Es un"):**
Para saber si debes usar herencia, aplica la prueba "Es un". Si la Clase B *es un* tipo de Clase A (ej. un *Perro* es un *Animal*, o una *Novela* es un *Libro*), entonces la herencia es correcta.

---

### Sintaxis Básica

Para derivar una clase de otra, se utilizan dos puntos (`:`) seguidos del tipo de acceso (usualmente `public`) y el nombre de la clase base.

```cpp
class ClaseDerivada : public ClaseBase {
    // Nuevos miembros específicos
};
```

---

### Ejemplo de Código

Vamos a usar un ejemplo clásico de jerarquía: Una clase general `Animal` y una clase específica `Perro`. Usaremos el modificador de acceso `protected` para permitir que la clase hija acceda a los datos de la madre, pero que sigan privados para el resto del mundo,.

```cpp
#include <iostream>
#include <string>

// --- CLASE BASE ---
class Animal {
protected:
    std::string nombre; // 'protected' permite acceso a las clases derivadas

public:
    Animal(std::string n) : nombre(n) {
        std::cout << "-> Constructor de Animal llamado." << std::endl;
    }

    void comer() {
        std::cout << nombre << " esta comiendo." << std::endl;
    }
    
    // Destructor (debería ser virtual en herencia real, explicado luego)
    ~Animal() {
        std::cout << "-> Destructor de Animal llamado." << std::endl;
    }
};

// --- CLASE DERIVADA ---
// Perro HEREDA de Animal
class Perro : public Animal {
public:
    // El constructor de la derivada debe llamar al constructor de la base
    Perro(std::string n) : Animal(n) { 
        std::cout << "-> Constructor de Perro llamado." << std::endl;
    }

    // Método propio (Especialización)
    void ladrar() {
        // Puede acceder a 'nombre' porque es protected en la base
        std::cout << nombre << " dice: ¡Guau!" << std::endl;
    }
    
    ~Perro() {
        std::cout << "-> Destructor de Perro llamado." << std::endl;
    }
};

int main() {
    std::cout << "--- Creando un Perro ---" << std::endl;
    Perro miMascota("Firulais");

    std::cout << "\n--- Usando metodos ---" << std::endl;
    // Accede a método de la base (reutilización)
    miMascota.comer(); 
    
    // Accede a método propio (especialización)
    miMascota.ladrar(); 

    std::cout << "\n--- Destruyendo objetos ---" << std::endl;
    return 0;
}
```

### Puntos Clave del Ejemplo

1.  **Reutilización:** La clase `Perro` no tuvo que definir la función `comer()` ni la variable `nombre`; las obtuvo gratis de `Animal`.
2.  **Inicialización:** Al crear el objeto `Perro`, primero se ejecuta el constructor de `Animal` (para cimentar la base) y luego el de `Perro`.
3.  **Destrucción:** Al finalizar el programa, el orden es inverso: primero se destruye `Perro` (limpiando lo específico) y luego `Animal`,.
4.  **Acceso `protected`:** La variable `nombre` es accesible dentro de `Perro::ladrar` porque fue declarada como `protected` en `Animal`. Si fuera `private`, `Perro` no podría tocarla directamente,.

### Tipos de Miembros en la Herencia

*   **Heredados:** Son los miembros de la clase base que la derivada puede usar como si fueran suyos (ej. `comer()`).
*   **Agregados:** Son miembros nuevos que solo existen en la derivada (ej. `ladrar()`).
*   **Sobrescritos (Overridden):** (No mostrado en el código simple, pero importante) La derivada puede cambiar el comportamiento de una función de la base si esta se declara como `virtual`.

---

Explicación detallada de los **Modificadores de Acceso** en C++, definidos como las palabras clave que controlan la visibilidad y accesibilidad de los miembros (atributos y métodos) de una clase desde diferentes partes del programa,.

Estos modificadores son fundamentales para el **encapsulamiento**, un pilar de la programación orientada a objetos que protege la integridad de los datos ocultando los detalles internos de implementación,.

---

### 1. Private (Privado)

**Definición:**
Los miembros declarados como `private` son accesibles **únicamente desde dentro de la propia clase** (sus propios métodos) o desde clases/funciones amigas (`friends`). Son invisibles para el mundo exterior y **no se heredan** (no son accesibles) en las clases derivadas,.

**Uso:**
Se utiliza para proteger atributos sensibles (como el saldo de una cuenta) o métodos internos auxiliares, asegurando que no se modifiquen arbitrariamente desde fuera,. En una `class`, el acceso por defecto es `private` si no se especifica lo contrario,.

**Ejemplo:**
```cpp
#include <iostream>
#include <string>

class CuentaBancaria {
private:
    double saldo; // Privado: Nadie fuera de la clase puede tocar esto directamente

public:
    CuentaBancaria(double saldoInicial) : saldo(saldoInicial) {}

    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad; // Acceso permitido: estamos DENTRO de la clase
        }
    }

    double getSaldo() const {
        return saldo; // Acceso de lectura permitido vía método público
    }
};

int main() {
    CuentaBancaria cuenta(1000.0);
    
    // cuenta.saldo = 5000; // ERROR: 'saldo' es privado
    cuenta.depositar(500);  // OK: usamos la interfaz pública
    
    std::cout << "Saldo: " << cuenta.getSaldo() << std::endl;
    return 0;
}
```

---

### 2. Public (Público)

**Definición:**
Los miembros declarados como `public` son accesibles desde **cualquier parte del código**: dentro de la clase, en clases derivadas y desde instancias externas (como en la función `main`),.

**Uso:**
Define la **interfaz pública** de la clase. Son los métodos y atributos que queremos que los usuarios de la clase utilicen para interactuar con ella,.

**Ejemplo:**
```cpp
#include <iostream>
#include <string>

class Coche {
public: // Todo lo que sigue es accesible por todos
    std::string modelo;
    
    void acelerar() {
        std::cout << modelo << " esta acelerando." << std::endl;
    }
};

int main() {
    Coche miCoche;
    
    // Acceso directo permitido porque son públicos
    miCoche.modelo = "Toyota"; 
    miCoche.acelerar(); 
    
    return 0;
}
```

---

### 3. Protected (Protegido)

**Definición:**
Los miembros `protected` tienen un comportamiento híbrido:
1.  Son **inaccesibles** desde fuera de la clase (igual que `private`).
2.  Son **accesibles** desde las **clases derivadas** (hijas),.

**Uso:**
Es crucial en la **herencia**. Se usa cuando quieres ocultar datos al usuario final, pero necesitas que las subclases puedan manipular esos datos internos para extender la funcionalidad,.

**Ejemplo:**
```cpp
#include <iostream>
#include <string>

class Vehiculo {
protected:
    int velocidadMaxima; // Accesible por Vehiculo y sus hijos (como Deportivo)

public:
    Vehiculo(int vel) : velocidadMaxima(vel) {}
};

class Deportivo : public Vehiculo {
public:
    Deportivo(int vel) : Vehiculo(vel) {}

    void usarTurbo() {
        // Podemos acceder a 'velocidadMaxima' porque es protected en la clase padre
        velocidadMaxima += 50; 
        std::cout << "Turbo activado. Vel Max: " << velocidadMaxima << std::endl;
    }
};

int main() {
    Deportivo ferrari(300);
    ferrari.usarTurbo(); // OK: método público de la hija
    
    // ferrari.velocidadMaxima = 0; // ERROR: es protected, no accesible desde main
    return 0;
}
```

---

### Resumen de Accesibilidad

| Modificador | Dentro de la propia clase | Clases Derivadas (Hijas) | Mundo Exterior (main/otros) |
| :--- | :---: | :---: | :---: |
| **public** | Sí | Sí | Sí |
| **protected** | Sí | Sí | No |
| **private** | Sí | No | No |

### Nota sobre Herencia y Acceso
Es importante notar que cuando una clase hereda de otra, también se usa un modificador de acceso (ej. `class Hija : public Padre`). Esto afecta cómo se ven los miembros heredados en la clase hija:
*   Si heredas como **public** (lo más común): Lo `public` se queda `public`, lo `protected` se queda `protected`.
*   Si heredas como **private**: Todos los miembros heredados se vuelven `private` en la clase hija.

---

Aquí tienes una explicación detallada sobre la **Sobrescritura de Métodos (Method Overriding)** en C++, basada en las definiciones y prácticas fundamentales del lenguaje.

### ¿Qué es la Sobrescritura de Métodos?

La sobrescritura es un mecanismo fundamental de la programación orientada a objetos que permite a una **clase derivada** (hija) proporcionar una implementación específica de una función que ya ha sido definida en su **clase base** (padre).

Su objetivo principal es permitir el **polimorfismo en tiempo de ejecución**. Esto significa que el programa puede decidir qué versión de la función ejecutar basándose en el tipo real del objeto en memoria, no en el tipo del puntero o referencia que lo señala.

### Requisitos Técnicos

Para que ocurra una sobrescritura correcta en C++, se deben cumplir estas condiciones:
1.  **Función Virtual:** La función en la clase base debe estar declarada con la palabra clave `virtual`.
2.  **Misma Firma:** La función en la clase derivada debe tener exactamente el mismo nombre, los mismos parámetros y el mismo tipo de retorno que en la clase base.
3.  **Acceso:** Normalmente se realiza a través de punteros o referencias a la clase base.

---

### Ejemplo Práctico: Animales y Sonidos

Este ejemplo ilustra cómo funciona la sobrescritura para cambiar el comportamiento de una clase general (`Animal`) a una específica (`Perro`).

```cpp
#include <iostream>
#include <string>

// Clase Base
class Animal {
public:
    // La palabra clave 'virtual' indica que este método puede ser sobrescrito
    virtual void hacerSonido() {
        std::cout << "El animal hace un sonido genérico." << std::endl;
    }
    
    // Destructor virtual (importante en herencia para evitar fugas de memoria)
    virtual ~Animal() {}
};

// Clase Derivada
class Perro : public Animal {
public:
    // 'override' confirma que estamos sobrescribiendo intencionalmente
    void hacerSonido() override { 
        std::cout << "El perro ladra: ¡Guau!" << std::endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        std::cout << "El gato maúlla: ¡Miau!" << std::endl;
    }
};

int main() {
    // Puntero de tipo Base apuntando a un objeto Derivado
    Animal* miMascota = new Perro();
    Animal* miGato = new Gato();

    // POLIMORFISMO EN ACCIÓN:
    // Aunque el puntero es de tipo 'Animal', se ejecuta la versión de 'Perro'
    // gracias a la sobrescritura y la tabla virtual (vtable).
    miMascota->hacerSonido(); // Salida: El perro ladra: ¡Guau!
    miGato->hacerSonido();    // Salida: El gato maúlla: ¡Miau!

    delete miMascota;
    delete miGato;
    return 0;
}
```
,

### Conceptos Clave

#### 1. Palabra clave `virtual`
Si no usas `virtual` en la clase base, no ocurre sobrescritura, sino **ocultación** (hiding) o redefinición estática. En ese caso, si llamas a la función desde un puntero de la clase base, se ejecutará la versión de la base, ignorando la versión de la hija, lo cual rompe el polimorfismo,.

**Ejemplo sin `virtual` (Incorrecto para polimorfismo):**
```cpp
class Base { void func() { cout << "Base"; } }; // No es virtual
class Derivada : public Base { void func() { cout << "Derivada"; } };

Base* ptr = new Derivada();
ptr->func(); // Imprime "Base" porque el enlace es estático.
```

#### 2. Palabra clave `override` (C++11)
Aunque es opcional, es muy recomendable usar `override` en la declaración de la función derivada. Esto le dice al compilador que verifique si realmente estás sobrescribiendo una función virtual de la base. Si te equivocas en el nombre o en los parámetros, el compilador lanzará un error, evitando bugs difíciles de detectar,.

#### 3. Diferencia con la Sobrecarga (Overloading)
Es vital no confundir estos dos términos:
*   **Sobrescritura (Overriding):** Misma función, diferente clase (herencia), comportamiento polimórfico.
*   **Sobrecarga (Overloading):** Mismo nombre de función, **diferentes parámetros**, dentro del mismo ámbito (o clase). Se resuelve en tiempo de compilación,.

### Invocación de la versión base
A veces, al sobrescribir un método, quieres conservar la lógica original y añadir algo más. Puedes llamar a la versión de la clase base usando el operador de resolución de ámbito `::`.

```cpp
void Perro::hacerSonido() override {
    Animal::hacerSonido(); // Llama a la lógica base ("Hace sonido genérico")
    std::cout << "Y además ladra." << std::endl;
}
```

----


### 1. Herencia Múltiple

**Definición:**
La herencia múltiple es la capacidad de una clase derivada para heredar atributos y comportamientos de **más de una clase base** simultáneamente,. Esto permite combinar funcionalidades distintas en una sola entidad; por ejemplo, un `Smartphone` podría heredar tanto de `Teléfono` como de `Computadora`.

**Sintaxis:**
Se separan las clases base con comas en la declaración de la clase derivada.

```cpp
class Base1 {
public:
    void funcion1() { /*...*/ }
};

class Base2 {
public:
    void funcion2() { /*...*/ }
};

// Herencia Múltiple: Hereda de Base1 Y Base2
class Derivada : public Base1, public Base2 { //
public:
    void funcionPropia() {
        funcion1(); // Acceso a Base1
        funcion2(); // Acceso a Base2
    }
};
```

---

### 2. El Problema del Diamante

**Definición:**
El problema del diamante surge cuando una clase (D) hereda de dos clases base (B y C), las cuales a su vez heredan de una **misma clase ancestro común** (A),.
Se llama así por la forma del diagrama de herencia:
      A
     / \
    B   C
     \ /
      D

**El Conflicto:**
Por defecto, C++ no fusiona la clase ancestro. Esto provoca dos problemas graves:
1.  **Duplicidad:** El objeto final (D) contiene **dos copias** de los miembros de A (una vía B y otra vía C),. Esto desperdicia memoria.
2.  **Ambigüedad:** Si intentas acceder a un miembro de A desde D, el compilador no sabe qué "camino" tomar (¿el de B o el de C?) y lanza un error,.

**Ejemplo del Problema (Sin Solución):**

```cpp
#include <iostream>

class Dispositivo { // Clase A (Ancestro)
public:
    int id;
    Dispositivo() : id(10) {}
};

class Escaner : public Dispositivo { // Clase B
    // Hereda una copia de 'id'
};

class Impresora : public Dispositivo { // Clase C
    // Hereda OTRA copia de 'id' independiente
};

class Fotocopiadora : public Escaner, public Impresora { // Clase D
    // Hereda de ambos. Ahora tiene DOS variables 'id'.
};

int main() {
    Fotocopiadora maquina;
    
    // ERROR: ¿A qué 'id' te refieres? 
    // ¿maquina.Escaner::id o maquina.Impresora::id?
    // std::cout << maquina.id << std::endl; //
    
    // Solución parcial (parche): Especificar la ruta con ::
    std::cout << maquina.Escaner::id << std::endl; // Funciona, pero es incómodo
    
    return 0;
}
```

---

### 3. La Solución: Herencia Virtual

Para resolver esto correctamente y tener una **única instancia** compartida de la clase ancestro (A), se utiliza la **herencia virtual**.

**Cómo funciona:**
Las clases intermedias (B y C) deben declarar que heredan de A usando la palabra clave `virtual`,. Esto indica al compilador que, si aparecen múltiples herencias de A en la jerarquía, deben fusionarse en un solo sub-objeto compartido,.

**Detalle Importante sobre Constructores:**
Cuando se usa herencia virtual, la clase más derivada (D, `Fotocopiadora`) se vuelve responsable de llamar al constructor de la clase ancestro común (A, `Dispositivo`) directamente. Las llamadas a constructores de A desde B y C son ignoradas para evitar la doble inicialización,.

**Ejemplo Corregido (Con Herencia Virtual):**

```cpp
#include <iostream>

class Dispositivo {
public:
    int id;
    Dispositivo(int x) : id(x) { std::cout << "Constructor Dispositivo\n"; }
};

// 1. Usamos 'virtual' al heredar del ancestro común
class Escaner : virtual public Dispositivo { //
public:
    Escaner(int x) : Dispositivo(x) {} 
};

class Impresora : virtual public Dispositivo { //
public:
    Impresora(int x) : Dispositivo(x) {}
};

class Fotocopiadora : public Escaner, public Impresora {
public:
    // 2. La clase final DEBE inicializar al "abuelo" (Dispositivo) explícitamente.
    // Si no lo hacemos, C++ intentaría llamar al constructor por defecto.
    Fotocopiadora(int x) : Dispositivo(x), Escaner(x), Impresora(x) {} //
};

int main() {
    Fotocopiadora maquina(1234);
    
    // AHORA FUNCIONA: Solo hay una copia de 'id' en memoria.
    // No hay ambigüedad.
    std::cout << "ID Maquina: " << maquina.id << std::endl; 
    
    return 0;
}
```

**Salida del programa:**
```text
Constructor Dispositivo
ID Maquina: 1234
```
Nota que el constructor de `Dispositivo` se ejecuta una sola vez, confirmando que solo existe una instancia base.
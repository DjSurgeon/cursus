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
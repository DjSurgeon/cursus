Aquí tienes una explicación detallada sobre el **Polimorfismo en C++**, dividida en los dos tipos principales que soporta el lenguaje: estático (en tiempo de compilación) y dinámico (en tiempo de ejecución), basada en las fuentes proporcionadas.

### ¿Qué es el Polimorfismo?

El término **polimorfismo** proviene del griego y significa "muchas formas". En programación, se refiere a la capacidad de proporcionar una interfaz única para entidades de diferentes tipos. Permite que objetos de diferentes clases, relacionadas mediante herencia, respondan de manera distinta al mismo mensaje o llamada de función.

En C++, el polimorfismo se divide en dos categorías principales:

1.  **Polimorfismo Estático (Tiempo de Compilación):** Se logra mediante la **sobrecarga de funciones** y **plantillas** (templates),.
2.  **Polimorfismo Dinámico (Tiempo de Ejecución):** Se logra mediante la **herencia** y las **funciones virtuales**. Este es el tipo más común cuando se habla de POO (Programación Orientada a Objetos).

---

### 1. Polimorfismo Dinámico (Tiempo de Ejecución)

Este es el mecanismo que permite que un programa decida qué función invocar mientras se está ejecutando, basándose en el tipo real del objeto y no en el tipo de la variable (puntero o referencia) que lo contiene.

#### Requisitos para que funcione:
Para lograr el polimorfismo dinámico en C++ se deben cumplir tres condiciones:
1.  Debe existir una jerarquía de **herencia** (clase base y clases derivadas).
2.  Las funciones en la clase base deben declararse como **`virtual`**,.
3.  Se debe acceder a los objetos mediante **punteros** o **referencias** a la clase base,.

#### Concepto de Función Virtual
Una función virtual es una función miembro declarada en la clase base que se espera sea redefinida (sobrescrita) en las clases derivadas. Si una función no es virtual, el compilador decide cuál llamar basándose en el tipo del puntero (vinculación estática). Si es virtual, el programa busca la implementación correcta del objeto en tiempo de ejecución (vinculación dinámica).

#### Ejemplo de Código: Animales

Este ejemplo muestra cómo un puntero de tipo `Animal` puede comportarse como un `Perro` o un `Gato`,,:

```cpp
#include <iostream>
using namespace std;

// Clase Base
class Animal {
public:
    // La palabra clave 'virtual' activa el polimorfismo
    virtual void hacerSonido() const { 
        cout << "El animal hace un sonido genérico." << endl;
    }
    
    // Es CRÍTICO usar un destructor virtual en clases polimórficas
    virtual ~Animal() {} 
};

// Clase Derivada 1
class Perro : public Animal {
public:
    // 'override' asegura que estamos sobrescribiendo correctamente la función base
    void hacerSonido() const override { 
        cout << "El perro ladra: ¡Guau!" << endl;
    }
};

// Clase Derivada 2
class Gato : public Animal {
public:
    void hacerSonido() const override { 
        cout << "El gato maúlla: ¡Miau!" << endl;
    }
};

int main() {
    Animal* miMascota; // Puntero a la clase base

    // 1. Apuntamos a un Perro
    miMascota = new Perro();
    
    // Polimorfismo en acción:
    // Aunque el puntero es 'Animal*', se ejecuta el método de 'Perro'
    miMascota->hacerSonido(); // Salida: El perro ladra: ¡Guau!
    delete miMascota;

    // 2. Apuntamos a un Gato
    miMascota = new Gato();
    
    // El mismo puntero ahora se comporta como Gato
    miMascota->hacerSonido(); // Salida: El gato maúlla: ¡Miau!
    delete miMascota;

    return 0;
}
```

**¿Qué pasaría sin `virtual`?**
Si `hacerSonido` no tuviera `virtual` en la clase `Animal`, al llamar a `miMascota->hacerSonido()`, el programa imprimiría "El animal hace un sonido genérico" en ambos casos, porque el compilador solo vería que el puntero es de tipo `Animal`,.

---

### 2. Polimorfismo Estático (Tiempo de Compilación)

#### Sobrecarga de Funciones (Ad-hoc Polymorphism)
Permite definir varias funciones con el mismo nombre pero con diferentes listas de parámetros (diferente cantidad o tipos),. El compilador decide qué función llamar basándose en los argumentos que le pasas.

```cpp
#include <iostream>

void imprimir(int i) {
    std::cout << "Entero: " << i << std::endl;
}

void imprimir(double f) {
    std::cout << "Flotante: " << f << std::endl;
}

int main() {
    imprimir(10);   // Llama a la versión int
    imprimir(3.14); // Llama a la versión double
    return 0;
}
```

---

### Conceptos Avanzados Importantes

1.  **Clases Abstractas y Funciones Virtuales Puras:**
    Si una función virtual se iguala a cero (ej. `virtual void draw() = 0;`), se convierte en una **función virtual pura**. Esto hace que la clase sea **Abstracta**, lo que significa que no se pueden crear objetos de ella directamente; solo sirve como molde o interfaz para las clases derivadas,.

    ```cpp
    class Forma {
    public:
        virtual void dibujar() = 0; // Método puro
    };
    // Forma f; // Error: No se puede instanciar una clase abstracta
    ```

2.  **Destructores Virtuales:**
    Cuando usas polimorfismo dinámico y eliminas un objeto derivado a través de un puntero base (`delete punteroBase`), el destructor de la clase base **debe** ser virtual. Si no lo es, solo se llamará al destructor de la base y no al del hijo, lo que puede causar fugas de memoria,.

3.  **Override:**
    Desde C++11, se recomienda usar la palabra clave `override` en las funciones de las clases derivadas. Esto ayuda al compilador a verificar que realmente estás sobrescribiendo una función virtual de la base y no creando una nueva por error (por ejemplo, por escribir mal el nombre),.

---

Aquí tienes una explicación detallada sobre el **Polimorfismo de Subtipo** en C++, cómo funciona bajo el capó y ejemplos prácticos.

### 1. Polimorfismo de Subtipo (Subtype Polymorphism)

El **Polimorfismo de Subtipo**, también conocido como *polimorfismo de inclusión*, es la capacidad de utilizar un objeto de una clase derivada (hija) en cualquier lugar donde se espere un objeto de su clase base (padre).

En términos simples: **El código escrito para la clase padre puede funcionar con cualquiera de sus clases hijas sin saberlo.**

#### ¿Por qué es importante?
Permite escribir código genérico y reutilizable. No necesitas escribir una función diferente para cada tipo de objeto; escribes una función que acepta la clase base y automáticamente funcionará con todas las clases derivadas futuras.

#### Requisitos en C++
Para que el polimorfismo de subtipo funcione correctamente (es decir, que se ejecute el método del hijo y no el del padre), se requieren tres condiciones:
1.  **Herencia:** Debe existir una jerarquía de clases.
2.  **Funciones Virtuales:** Los métodos en la clase base deben declararse con la palabra clave `virtual`.
3.  **Punteros o Referencias:** Se debe acceder a los objetos a través de punteros (`Base*`) o referencias (`Base&`) a la clase base.

---

### Ejemplo de Código: Figuras Geométricas

Imaginemos un sistema gráfico donde queremos dibujar diferentes figuras.

```cpp
#include <iostream>
#include <vector>

// 1. CLASE BASE
class Figura {
public:
    // 'virtual' es la clave mágica para el polimorfismo dinámico
    virtual void dibujar() const {
        std::cout << "Dibujando una figura genérica." << std::endl;
    }

    // Destructor virtual: OBLIGATORIO en clases base polimórficas
    // para evitar fugas de memoria al usar delete en un puntero base.
    virtual ~Figura() {
        std::cout << "Destruyendo figura." << std::endl;
    }
};

// 2. CLASES DERIVADAS (SUBTIPOS)
class Circulo : public Figura {
public:
    // 'override' (C++11) asegura que estamos sobrescribiendo correctamente
    void dibujar() const override {
        std::cout << "Dibujando un Círculo O" << std::endl;
    }
};

class Rectangulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un Rectángulo []" << std::endl;
    }
};

// 3. FUNCIÓN POLIMÓRFICA
// Acepta una referencia a la BASE, pero funciona con cualquier HIJA.
// El compilador no sabe qué tipo real pasaremos hasta que se ejecute.
void renderizarEscena(const Figura& f) {
    f.dibujar(); 
}

int main() {
    Circulo c;
    Rectangulo r;

    std::cout << "--- Polimorfismo con Referencias ---" << std::endl;
    // Pasamos subtipos (Círculo, Rectángulo) donde se espera el supertipo (Figura)
    renderizarEscena(c); // Salida: Dibujando un Círculo O
    renderizarEscena(r); // Salida: Dibujando un Rectángulo []

    std::cout << "\n--- Polimorfismo con Punteros y Colecciones ---" << std::endl;
    // Podemos tener una lista heterogénea gracias al polimorfismo
    std::vector<Figura*> figuras;
    figuras.push_back(new Circulo());
    figuras.push_back(new Rectangulo());

    for (Figura* fig : figuras) {
        fig->dibujar(); // Despacho dinámico: llama a la versión correcta
    }

    // Limpieza
    for (Figura* fig : figuras) {
        delete fig;
    }

    return 0;
}
```

### ¿Cómo funciona internamente? (Despacho Dinámico)

Cuando llamas a `fig->dibujar()`, el compilador no sabe en tiempo de compilación a qué función saltar (¿a la de Círculo o a la de Rectángulo?). Esto se resuelve en tiempo de ejecución mediante la **vtable (Tabla Virtual)**:

1.  **vtable:** Cada clase que tiene métodos virtuales tiene una tabla oculta en memoria (vtable) que contiene las direcciones de sus funciones virtuales.
2.  **vptr:** Cada *objeto* de esa clase tiene un puntero oculto (vptr) que apunta a la vtable de su clase real.
3.  **Ejecución:**
    *   Si tienes un `Figura* p` que apunta a un `Circulo`.
    *   Al llamar `p->dibujar()`, el programa sigue el `vptr` del objeto.
    *   Llega a la vtable de `Circulo`.
    *   Encuentra la dirección de `Circulo::dibujar` y la ejecuta.

Este proceso se llama **Despacho Dinámico (Dynamic Dispatch)**. Es ligeramente más lento que una llamada a función normal, pero permite esta flexibilidad potente.

### Errores Comunes

1.  **Slicing (Recorte de objetos):** Si pasas el objeto **por valor** en lugar de por referencia o puntero, el polimorfismo se pierde. Solo se copia la parte "base" del objeto y se pierde la identidad del subtipo.
    ```cpp
    void funcionMal(Figura f) { // Paso por VALOR
        f.dibujar(); 
    }
    // Si pasas un Circulo, se copia solo como Figura. 
    // Imprimirá "Dibujando una figura genérica".
    ```
2.  **Olvidar el Destructor Virtual:** Si borras un objeto derivado a través de un puntero a la base (`delete ptrBase`), y el destructor base no es `virtual`, el destructor de la clase derivada no se ejecutará, causando fugas de recursos.

---

Aquí tienes una explicación detallada sobre las **Clases Abstractas** en C++, basada en las fuentes proporcionadas.

### 1. ¿Qué es una Clase Abstracta?

Una clase abstracta es una clase diseñada específicamente para actuar como una **clase base** (padre) en una jerarquía de herencia. Su característica definitoria es que **no se puede instanciar**, es decir, no puedes crear un objeto directo de ese tipo (ej. `ClaseAbstracta obj;` daría error).

Para que una clase sea considerada abstracta en C++, debe contener al menos una **función virtual pura**.

#### La Función Virtual Pura
Es una función que se declara en la clase base pero no tiene implementación en ella (o no necesariamente). Se indica mediante la sintaxis `= 0` al final de la declaración.

**Sintaxis:**
```cpp
virtual tipo nombreFuncion() = 0;
```

### 2. ¿Para qué sirven y por qué usarlas?

Las clases abstractas sirven para definir un **concepto general** o una interfaz común que será compartida por varias clases derivadas más específicas.

*   **Abstracción y Generalización:** Permiten modelar conceptos que no existen por sí mismos como objetos concretos. Por ejemplo, el concepto de "Figura" es abstracto; no puedes tener "una figura" genérica en la mano, tienes un "Círculo" o un "Cuadrado".
*   **Contrato de Interfaz:** Obligan a las clases hijas a implementar ciertos métodos. Si una clase derivada no implementa todas las funciones virtuales puras de su padre, ella también será considerada abstracta y no se podrá instanciar.
*   **Polimorfismo:** Aunque no puedes crear objetos de la clase abstracta, sí puedes usar **punteros** y **referencias** de su tipo. Esto permite manipular diferentes objetos derivados (Círculo, Rectángulo) a través de una interfaz común (Figura).
*   **Desacoplamiento:** Sirven para desacoplar el código. El cliente puede interactuar con la interfaz (clase abstracta) sin importar qué implementación específica (DirectX, OpenGL) se esté usando por debajo.

### 3. Ejemplo de Código

A continuación, un ejemplo basado en las fuentes que ilustra una clase abstracta `Figura` y una clase concreta `Circulo`.

```cpp
#include <iostream>
#include <cmath>

// 1. Definición de la Clase Abstracta
class Figura {
public:
    // Función virtual pura: Esto hace que la clase sea abstracta.
    // Obliga a los hijos a definir cómo calcular su área.
    virtual double calcularArea() const = 0;

    // Método concreto: Las clases abstractas pueden tener métodos normales
    // con implementación que heredan los hijos.
    void mostrarTipo() const {
        std::cout << "Soy una figura." << std::endl;
    }

    // Es vital un destructor virtual en clases base polimórficas
    virtual ~Figura() {} 
};

// 2. Definición de una Clase Concreta (Derivada)
class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    // Implementación obligatoria de la función virtual pura
    // 'override' ayuda a asegurar que estamos sobrescribiendo correctamente
    double calcularArea() const override {
        return 3.1416 * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}

    // Implementación obligatoria
    double calcularArea() const override {
        return ancho * alto;
    }
};

int main() {
    // Figura f; // ¡ERROR! No se puede instanciar una clase abstracta

    // Uso mediante polimorfismo (Punteros)
    Circulo c(5.0);
    Rectangulo r(4.0, 2.0);

    Figura* figura1 = &c; // Puntero de tipo abstracto apuntando a objeto concreto
    Figura* figura2 = &r;

    // Se ejecuta el método mostrarTipo() de la base (reutilización)
    figura1->mostrarTipo(); 
    
    // Se ejecuta el calcularArea() específico de Circulo (polimorfismo)
    std::cout << "Area Circulo: " << figura1->calcularArea() << std::endl; 
    std::cout << "Area Rectangulo: " << figura2->calcularArea() << std::endl;

    return 0;
}
```

### 4. Puntos Importantes a Recordar

*   **Interfaces:** Si una clase abstracta solo contiene funciones virtuales puras y ningún dato miembro, se comporta como lo que en otros lenguajes (como Java) se llama una **Interfaz**.
*   **Restricciones:** No se pueden usar clases abstractas como tipos de argumentos o tipos de retorno por valor (porque no se pueden instanciar), pero sí como punteros (`Figura*`) o referencias (`Figura&`).
*   **Constructores:** Una clase abstracta puede tener un constructor (para inicializar sus variables internas), pero este solo será llamado por los constructores de las clases derivadas. Nunca llames a una función virtual pura dentro de un constructor, ya que el resultado es indefinido.

---

En C++, y específicamente bajo el estándar **C++98**, el concepto de "Interfaz" no existe como una palabra clave nativa del lenguaje (a diferencia de Java o C# que usan `interface`). Sin embargo, el concepto se implementa utilizando **Clases Abstractas Puras**,.

Aquí te explico detalladamente qué son, cómo se construyen en C++98 y por qué son fundamentales.

### 1. ¿Qué es una Interfaz en C++?

Una interfaz es un "contrato". Define **qué** comportamientos debe tener un objeto, pero no **cómo** se implementan esos comportamientos. Sirve para desacoplar la definición de las operaciones de su implementación concreta, permitiendo el polimorfismo,.

En C++, una interfaz es técnicamente una **Clase Base Abstracta** que cumple dos condiciones estrictas,:
1.  **Métodos Virtuales Puros:** Todos sus métodos son funciones virtuales puras (terminan en `= 0`).
2.  **Sin Estado:** No contiene atributos (variables miembro) ni implementaciones de métodos (salvo, a veces, el destructor).

### 2. Implementación en C++98

En el estándar C++98, para crear una interfaz debemos seguir una "receta" específica, ya que no tenemos las ayudas modernas (como `override` o punteros inteligentes estándar).

#### Requisitos Técnicos en C++98:
1.  **`virtual ... = 0`**: Debes igualar las funciones a cero para indicar que no tienen implementación y obligar a las clases hijas a definirlas,.
2.  **Destructor Virtual (`virtual ~Clase() {}`)**: Esto es **crítico**. Si borras un objeto derivado a través de un puntero a la interfaz (algo muy común), y el destructor no es virtual, el destructor de la clase derivada no se ejecutará, causando fugas de memoria,.
3.  **Herencia Pública**: Las clases concretas deben heredar públicamente de la interfaz para que el polimorfismo funcione.

### 3. Ejemplo de Código en C++98

Vamos a simular un sistema de dibujo. Definiremos una interfaz `IDibujable` (la convención `I` es común para identificar interfaces).

#### Definición de la Interfaz (Header)

```cpp
// IDibujable.h
#ifndef IDIBUJABLE_H
#define IDIBUJABLE_H

// En C++98 usamos 'class' o 'struct'. 'struct' hace todo público por defecto.
class IDibujable {
public:
    // 1. Destructor Virtual (OBLIGATORIO en interfaces)
    // Debe tener un cuerpo vacío, incluso si es puro, para permitir la destrucción segura.
    virtual ~IDibujable() {} 

    // 2. Métodos Virtuales Puros
    // El "= 0" hace que la clase sea abstracta. No se puede instanciar IDibujable.
    virtual void dibujar() const = 0; 
    virtual void redimensionar(int porcentaje) = 0;
};

#endif
```

#### Implementación Concreta (Clases Derivadas)

Ahora creamos clases que "firman el contrato" implementando todos los métodos.

```cpp
// Circulo.h
#include <iostream>
#include "IDibujable.h"

class Circulo : public IDibujable {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    // Implementación del contrato
    // Nota: En C++98 no existe la palabra clave 'override', 
    // así que debemos tener mucho cuidado de escribir la firma EXACTAMENTE igual.
    void dibujar() const {
        std::cout << "Dibujando un Circulo de radio: " << radio << std::endl;
    }

    void redimensionar(int porcentaje) {
        radio *= (porcentaje / 100.0);
    }
    
    // El destructor de Circulo se llamará automáticamente gracias al virtual ~IDibujable()
    ~Circulo() {
        std::cout << "Destruyendo Circulo" << std::endl;
    }
};
```

#### Uso Polimórfico (Main)

Aquí es donde brilla la interfaz. El código cliente no necesita saber si es un `Circulo` o un `Rectangulo`, solo que es `IDibujable`.

```cpp
// main.cpp
#include <iostream>
#include <vector> // En C++98 vector es parte de STL estándar
#include "Circulo.h"

// Otra implementación para el ejemplo
class Cuadrado : public IDibujable {
public:
    void dibujar() const { std::cout << "Dibujando Cuadrado" << std::endl; }
    void redimensionar(int p) { /* logica */ }
    ~Cuadrado() { std::cout << "Destruyendo Cuadrado" << std::endl; }
};

int main() {
    // 1. No podemos instanciar la interfaz
    // IDibujable forma; // ERROR de compilación: clase abstracta

    // 2. Polimorfismo mediante punteros
    // Creamos un array de punteros a la interfaz
    const int TAM = 2;
    IDibujable* formas[TAM];

    // Asignamos objetos concretos (Upcasting implícito)
    formas = new Circulo(5.0);
    formas = new Cuadrado();

    // 3. Usamos los objetos a través de la interfaz
    for (int i = 0; i < TAM; ++i) {
        formas[i]->dibujar(); // Se decide en tiempo de ejecución qué dibujar
    }

    // 4. Limpieza (delete)
    // Gracias al destructor virtual en IDibujable, se llama al destructor correcto (Circulo/Cuadrado)
    for (int i = 0; i < TAM; ++i) {
        delete formas[i]; 
    }

    return 0;
}
```

### Diferencias Clave: Interfaz vs Clase Abstracta Normal

Aunque técnicamente ambas son clases abstractas en C++, conceptualmente son distintas:

| Característica | Interfaz (Interface) | Clase Abstracta (Abstract Class) |
| :--- | :--- | :--- |
| **Implementación** | 100% Virtual Pura. Sin código. | Puede tener métodos con código (comunes) y métodos puros. |
| **Datos (Atributos)** | No tiene variables miembro. | Puede tener variables miembro (protected/private) para compartir estado. |
| **Herencia** | Se usa para definir *comportamiento* ("Es capaz de..."). Soporta herencia múltiple limpia. | Se usa para definir *identidad* ("Es un tipo de..."). |

### Resumen de Peligros en C++98
1.  **Falta de `override`**: Si en la clase hija escribes `void dibujar(int x)` (añadiendo un parámetro por error) en lugar de `void dibujar()`, C++98 lo interpretará como una **nueva función** (ocultación) y no como la implementación de la interfaz. Esto hará que la clase hija siga siendo abstracta y falle al compilar al intentar instanciarla, o peor, compile pero no funcione el polimorfismo.
2.  **Gestión de Memoria**: Al no haber `std::unique_ptr` ni `std::shared_ptr` en C++98 (solo el defectuoso `std::auto_ptr`), eres totalmente responsable de hacer `delete` manualmente de los objetos creados a través de interfaces, como se ve en el ejemplo anterior.En C++, y específicamente bajo el estándar **C++98**, el concepto de "Interfaz" no existe como una palabra clave nativa del lenguaje (a diferencia de Java o C# que usan `interface`). Sin embargo, el concepto se implementa utilizando **Clases Abstractas Puras**,.

Aquí te explico detalladamente qué son, cómo se construyen en C++98 y por qué son fundamentales.

### 1. ¿Qué es una Interfaz en C++?

Una interfaz es un "contrato". Define **qué** comportamientos debe tener un objeto, pero no **cómo** se implementan esos comportamientos. Sirve para desacoplar la definición de las operaciones de su implementación concreta, permitiendo el polimorfismo,.

En C++, una interfaz es técnicamente una **Clase Base Abstracta** que cumple dos condiciones estrictas,:
1.  **Métodos Virtuales Puros:** Todos sus métodos son funciones virtuales puras (terminan en `= 0`).
2.  **Sin Estado:** No contiene atributos (variables miembro) ni implementaciones de métodos (salvo, a veces, el destructor).

### 2. Implementación en C++98

En el estándar C++98, para crear una interfaz debemos seguir una "receta" específica, ya que no tenemos las ayudas modernas (como `override` o punteros inteligentes estándar).

#### Requisitos Técnicos en C++98:
1.  **`virtual ... = 0`**: Debes igualar las funciones a cero para indicar que no tienen implementación y obligar a las clases hijas a definirlas,.
2.  **Destructor Virtual (`virtual ~Clase() {}`)**: Esto es **crítico**. Si borras un objeto derivado a través de un puntero a la interfaz (algo muy común), y el destructor no es virtual, el destructor de la clase derivada no se ejecutará, causando fugas de memoria,.
3.  **Herencia Pública**: Las clases concretas deben heredar públicamente de la interfaz para que el polimorfismo funcione.

### 3. Ejemplo de Código en C++98

Vamos a simular un sistema de dibujo. Definiremos una interfaz `IDibujable` (la convención `I` es común para identificar interfaces).

#### Definición de la Interfaz (Header)

```cpp
// IDibujable.h
#ifndef IDIBUJABLE_H
#define IDIBUJABLE_H

// En C++98 usamos 'class' o 'struct'. 'struct' hace todo público por defecto.
class IDibujable {
public:
    // 1. Destructor Virtual (OBLIGATORIO en interfaces)
    // Debe tener un cuerpo vacío, incluso si es puro, para permitir la destrucción segura.
    virtual ~IDibujable() {} 

    // 2. Métodos Virtuales Puros
    // El "= 0" hace que la clase sea abstracta. No se puede instanciar IDibujable.
    virtual void dibujar() const = 0; 
    virtual void redimensionar(int porcentaje) = 0;
};

#endif
```

#### Implementación Concreta (Clases Derivadas)

Ahora creamos clases que "firman el contrato" implementando todos los métodos.

```cpp
// Circulo.h
#include <iostream>
#include "IDibujable.h"

class Circulo : public IDibujable {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    // Implementación del contrato
    // Nota: En C++98 no existe la palabra clave 'override', 
    // así que debemos tener mucho cuidado de escribir la firma EXACTAMENTE igual.
    void dibujar() const {
        std::cout << "Dibujando un Circulo de radio: " << radio << std::endl;
    }

    void redimensionar(int porcentaje) {
        radio *= (porcentaje / 100.0);
    }
    
    // El destructor de Circulo se llamará automáticamente gracias al virtual ~IDibujable()
    ~Circulo() {
        std::cout << "Destruyendo Circulo" << std::endl;
    }
};
```

#### Uso Polimórfico (Main)

Aquí es donde brilla la interfaz. El código cliente no necesita saber si es un `Circulo` o un `Rectangulo`, solo que es `IDibujable`.

```cpp
// main.cpp
#include <iostream>
#include <vector> // En C++98 vector es parte de STL estándar
#include "Circulo.h"

// Otra implementación para el ejemplo
class Cuadrado : public IDibujable {
public:
    void dibujar() const { std::cout << "Dibujando Cuadrado" << std::endl; }
    void redimensionar(int p) { /* logica */ }
    ~Cuadrado() { std::cout << "Destruyendo Cuadrado" << std::endl; }
};

int main() {
    // 1. No podemos instanciar la interfaz
    // IDibujable forma; // ERROR de compilación: clase abstracta

    // 2. Polimorfismo mediante punteros
    // Creamos un array de punteros a la interfaz
    const int TAM = 2;
    IDibujable* formas[TAM];

    // Asignamos objetos concretos (Upcasting implícito)
    formas = new Circulo(5.0);
    formas = new Cuadrado();

    // 3. Usamos los objetos a través de la interfaz
    for (int i = 0; i < TAM; ++i) {
        formas[i]->dibujar(); // Se decide en tiempo de ejecución qué dibujar
    }

    // 4. Limpieza (delete)
    // Gracias al destructor virtual en IDibujable, se llama al destructor correcto (Circulo/Cuadrado)
    for (int i = 0; i < TAM; ++i) {
        delete formas[i]; 
    }

    return 0;
}
```

### Diferencias Clave: Interfaz vs Clase Abstracta Normal

Aunque técnicamente ambas son clases abstractas en C++, conceptualmente son distintas:

| Característica | Interfaz (Interface) | Clase Abstracta (Abstract Class) |
| :--- | :--- | :--- |
| **Implementación** | 100% Virtual Pura. Sin código. | Puede tener métodos con código (comunes) y métodos puros. |
| **Datos (Atributos)** | No tiene variables miembro. | Puede tener variables miembro (protected/private) para compartir estado. |
| **Herencia** | Se usa para definir *comportamiento* ("Es capaz de..."). Soporta herencia múltiple limpia. | Se usa para definir *identidad* ("Es un tipo de..."). |

### Resumen de Peligros en C++98
1.  **Falta de `override`**: Si en la clase hija escribes `void dibujar(int x)` (añadiendo un parámetro por error) en lugar de `void dibujar()`, C++98 lo interpretará como una **nueva función** (ocultación) y no como la implementación de la interfaz. Esto hará que la clase hija siga siendo abstracta y falle al compilar al intentar instanciarla, o peor, compile pero no funcione el polimorfismo.
2.  **Gestión de Memoria**: Al no haber `std::unique_ptr` ni `std::shared_ptr` en C++98 (solo el defectuoso `std::auto_ptr`), eres totalmente responsable de hacer `delete` manualmente de los objetos creados a través de interfaces, como se ve en el ejemplo anterior.

---

Basado en los documentos proporcionados, aquí tienes una explicación detallada sobre la **Gestión de Memoria** y las **Copias Profundas** en C++.

### 2. Copias Profundas vs. Copias Superficiales

Este concepto es crítico cuando tu clase gestiona memoria dinámica (tiene punteros hacia el Heap).

#### El problema: Copia Superficial (Shallow Copy)
Por defecto, C++ proporciona un **constructor de copia** que copia los valores de los miembros tal cual. Si tu clase tiene un puntero, copiará la **dirección de memoria**, no el contenido al que apunta,.
*   **Resultado:** Tienes dos objetos apuntando al mismo bloque de memoria.
*   **Peligro:** Cuando los objetos se destruyen (salen del ámbito), ambos intentarán hacer `delete` sobre la misma dirección. Esto se llama **doble liberación** (*double free*) y corrompe la memoria o cuelga el programa.

#### La solución: Copia Profunda (Deep Copy)
Una copia profunda implica reservar **nueva memoria** para el objeto copia y luego copiar el **contenido** real del objeto original a esta nueva ubicación. De esta forma, cada objeto es dueño de su propia memoria independiente.

Para implementar copias profundas correctamente, debes seguir la **Forma Canónica Ortodoxa** e implementar manualmente:
1.  **Constructor de Copia:** `Clase(const Clase& otro)`
2.  **Operador de Asignación:** `Clase& operator=(const Clase& otro)`
3.  **Destructor:** `~Clase()` para liberar la memoria.

**Ejemplo de Copia Profunda:**

```cpp
#include <iostream>
#include <cstring> // Para strlen y strcpy

class Texto {
private:
    char* buffer;

public:
    // Constructor
    Texto(const char* s) {
        buffer = new char[strlen(s) + 1]; // Reservar memoria nueva
        strcpy(buffer, s);                // Copiar contenido
    }

    // 1. CONSTRUCTOR DE COPIA (Deep Copy)
    Texto(const Texto& otro) {
        // Reservamos NUEVA memoria independiente
        buffer = new char[strlen(otro.buffer) + 1];
        // Copiamos el CONTENIDO, no el puntero
        strcpy(buffer, otro.buffer); 
    }

    // 2. OPERADOR DE ASIGNACIÓN (Deep Copy)
    Texto& operator=(const Texto& otro) {
        // Protección contra auto-asignación (a = a)
        if (this != &otro) {
            // Primero liberamos la memoria vieja
            delete[] buffer; 
            
            // Reservamos memoria nueva y copiamos
            buffer = new char[strlen(otro.buffer) + 1];
            strcpy(buffer, otro.buffer);
        }
        return *this;
    }

    // 3. DESTRUCTOR
    ~Texto() {
        delete[] buffer; // Liberar memoria al morir el objeto
    }
};
```

### 3. C++ Moderno (RAII y Punteros Inteligentes)

Aunque entender `new` y `delete` es fundamental, el C++ moderno (C++11 en adelante) desaconseja su uso directo en favor de la gestión automática mediante **Punteros Inteligentes** (*Smart Pointers*), que siguen el principio RAII (Resource Acquisition Is Initialization).

*   **`std::unique_ptr`:** Garantiza propiedad exclusiva. Cuando el puntero sale del ámbito, la memoria se libera automáticamente. No permite copias (evitando el problema de la copia superficial), solo movimientos,.
*   **`std::shared_ptr`:** Permite que múltiples punteros compartan la propiedad de un objeto. Usa un contador de referencias y libera la memoria solo cuando el último puntero muere.

Usar estos mecanismos evita la mayoría de errores manuales de gestión de memoria y la necesidad de escribir manualmente destructores complejos,.

---

Aquí tienes una explicación detallada de los conceptos **Vtable** y **Overhead** en C++, cómo se relacionan con el polimorfismo y ejemplos prácticos basados en las fuentes proporcionadas.

---

### 1. Vtable (Tabla de Métodos Virtuales)

La **Vtable** (o *Virtual Method Table*) es un mecanismo que utilizan los compiladores de C++ para implementar el **despacho dinámico** (polimorfismo en tiempo de ejecución),.

Cuando declaras una función como `virtual` en una clase, el compilador necesita una forma de saber qué versión de la función ejecutar en tiempo de ejecución (la de la clase base o la de una clase derivada), ya que esto no se puede determinar durante la compilación.

**¿Cómo funciona internamente?**
1.  **Por Clase:** El compilador crea una tabla estática (un array de punteros a funciones) para cada clase que tenga al menos una función virtual. Esta tabla contiene las direcciones de memoria de las funciones virtuales que corresponden a esa clase,.
2.  **Por Objeto (vptr):** Cada vez que creas un objeto de una clase con funciones virtuales, el compilador añade un miembro oculto al objeto llamado **vptr** (*virtual pointer*). Este puntero apunta a la Vtable correspondiente a la clase real del objeto,.

**Proceso de llamada:**
Cuando llamas a `objeto->funcionVirtual()`, el programa:
1.  Sigue el `vptr` del objeto para encontrar la Vtable.
2.  Busca en la Vtable el índice correspondiente a esa función.
3.  Obtiene la dirección de memoria de la función.
4.  Salta a esa dirección para ejecutar el código,.

---

### 2. Overhead (Sobrecarga)

El **Overhead** es el costo extra (en memoria y tiempo) que pagas por usar funciones virtuales en lugar de funciones normales (no virtuales). Aunque a menudo es despreciable, es importante en sistemas de alto rendimiento o con recursos limitados.

#### A. Overhead de Memoria (Espacio)
*   **Por Clase:** Se necesita espacio para almacenar la estructura de la Vtable (array de punteros).
*   **Por Objeto:** Cada instancia de la clase aumenta su tamaño porque debe almacenar el `vptr` (generalmente 8 bytes en sistemas de 64 bits),. Si tienes millones de objetos pequeños, este aumento de tamaño puede ser significativo.

#### B. Overhead de Tiempo (Rendimiento)
*   **Indirección:** Llamar a una función virtual requiere instrucciones extra: desreferenciar el puntero, buscar en la tabla y saltar. Esto es más lento que una llamada directa a una dirección fija.
*   **Pérdida de Inlining:** Este es el mayor costo real. Como el compilador no sabe qué función se llamará hasta que el programa se ejecuta, **no puede realizar "inlining"** (insertar el código de la función directamente en el lugar de la llamada). El inlining es una optimización clave para funciones pequeñas y rápidas,.
*   **Fallos de Caché y Predicción:** La CPU intenta adivinar qué instrucciones ejecutar a continuación (ejecución especulativa). Con funciones virtuales, es más difícil predecir el salto, lo que puede causar que la CPU se equivoque y tenga que descartar trabajo, perdiendo ciclos.

---

### Ejemplo Práctico en C++

A continuación, un código que demuestra la diferencia de tamaño (Overhead de memoria) y cómo se estructuran conceptualmente.

```cpp
#include <iostream>

// Clase SIN funciones virtuales (Sin Vtable, sin Overhead)
class SinVirtual {
public:
    int dato; // 4 bytes
    void funcion() { 
        std::cout << "Funcion normal" << std::endl; 
    }
};

// Clase CON funciones virtuales (Con Vtable, con Overhead)
class ConVirtual {
public:
    int dato; // 4 bytes
    
    // Al añadir 'virtual', el compilador añade un vptr oculto (8 bytes en x64)
    virtual void funcion() { 
        std::cout << "Funcion virtual" << std::endl; 
    }
};

int main() {
    SinVirtual sv;
    ConVirtual cv;

    std::cout << "--- Overhead de Memoria ---" << std::endl;
    // Tamaño esperado: 4 bytes (solo el int)
    std::cout << "Sizeof SinVirtual: " << sizeof(sv) << " bytes" << std::endl;

    // Tamaño esperado: 12 o 16 bytes (int + vptr + padding/alineación)
    std::cout << "Sizeof ConVirtual: " << sizeof(cv) << " bytes" << std::endl;

    return 0;
}
```

**Explicación de la Salida:**
En una arquitectura de 64 bits típica, la salida será:
*   `SinVirtual`: 4 bytes.
*   `ConVirtual`: 16 bytes (4 bytes del `int` + 4 bytes de relleno + 8 bytes del puntero `vptr`). ¡El objeto cuadruplicó su tamaño solo por hacer la función virtual!

### Resumen del Impacto en Rendimiento

Según experimentos citados en las fuentes:
*   Para funciones **pequeñas y rápidas**, el uso de `virtual` puede hacer que la llamada sea un **18% más lenta** debido a la falta de inlining y la indirección.
*   Para funciones **grandes y lentas**, el overhead es despreciable (menos del 1%), ya que el tiempo de ejecución de la función en sí domina sobre el costo de la llamada.

**Conclusión:** Usa funciones virtuales cuando necesites polimorfismo, pero evítalas en clases muy pequeñas que se instancian millones de veces o en funciones críticas muy breves donde el *inlining* sea vital.
# c++

##  **Stack** (Pila) y el **Heap** (Montón)

**1. Stack (Pila de llamadas - Memoria Automática)**
El Stack es una región de memoria estructurada bajo el concepto **LIFO** (Last In, First Out),. Se utiliza para la ejecución de funciones y el almacenamiento de variables locales.
*   **Gestión:** Es automática. La memoria se reserva cuando se entra en un ámbito (como una función) y se libera automáticamente cuando se sale de él,.
*   **Características:** Es una memoria de acceso muy rápido y contigua, pero de tamaño limitado (fijo), lo que puede llevar a un desbordamiento de pila (*stack overflow*) si se abusa de ella (por ejemplo, recursión infinita),.

**2. Heap (Montón - Memoria Dinámica)**
El Heap es una región de memoria utilizada para el almacenamiento dinámico, permitiendo reservar bloques de memoria de tamaño variable durante la ejecución del programa,.
*   **Gestión:** Es manual (en C++ clásico). El programador debe solicitar la memoria explícitamente (usando `new` o `malloc`) y liberarla explícitamente (usando `delete` o `free`),.
*   **Características:** Es más flexible que el Stack (las variables pueden cambiar de tamaño y persistir más allá del ámbito de una función), pero su acceso es más lento y puede sufrir fragmentación. Si no se libera la memoria, ocurren fugas de memoria (*memory leaks*),.

---

### Diferencias Clave

| Característica | Stack (Pila) | Heap (Montón) |
| :--- | :--- | :--- |
| **Gestión** | Automática (por el compilador). | Manual (por el programador). |
| **Velocidad** | Muy rápida. | Más lenta. |
| **Estructura** | Contigua y lineal (LIFO). | Jerárquica o aleatoria (fragmentada). |
| **Vida útil** | Limitada al ámbito (scope) de la función. | Persiste hasta que se libera manualmente. |
| **Tamaño** | Limitado (fijo por el SO). | Limitado por la memoria virtual/física. |

---

El siguiente código ilustra la creación de variables en el Stack y en el Heap, mostrando cómo el puntero se guarda en el Stack mientras que los datos a los que apunta residen en el Heap.

```cpp
#include <iostream>

void FuncionDemo() {
    // --- MEMORIA STACK (Automática) ---
    // 'numeroStack' se crea en la pila.
    // Se destruirá automáticamente al llegar a la llave de cierre '}'.
    int numeroStack = 10; 

    // --- MEMORIA HEAP (Dinámica) ---
    // 1. 'ptrHeap' es un puntero que vive en el STACK.
    // 2. 'new int(20)' reserva memoria en el HEAP y devuelve la dirección.
    int* ptrHeap = new int(20); 

    std::cout << "Valor en Stack: " << numeroStack << std::endl;
    std::cout << "Valor en Heap: " << *ptrHeap << std::endl;

    // --- LIBERACIÓN DE MEMORIA ---
    // Es OBLIGATORIO liberar la memoria del Heap manualmente.
    // Si olvidamos esta línea, se produce un "memory leak" (fuga de memoria).
    delete ptrHeap; 
    
    // Al finalizar la función:
    // 1. 'numeroStack' se elimina automáticamente.
    // 2. El puntero 'ptrHeap' (la variable local) se elimina del Stack,
    //    pero si no hubiéramos hecho 'delete', el valor 20 seguiría ocupando espacio en el Heap.
}

int main() {
    FuncionDemo();
    return 0;
}
```

**Nota sobre la relación entre ambos:**
Es común que ambas memorias interactúen. Por ejemplo, cuando declaras un puntero (`int* ptr`), la variable del puntero en sí (que almacena la dirección de memoria) se guarda en el **Stack**, pero el bloque de memoria al que apunta y donde se guardan los datos reales puede estar en el **Heap**,.

## Operadores `new` y `delete`

En C++, la gestión de memoria dinámica se realiza en el **Heap** (montón) y, a diferencia de C (`malloc`/`free`), estos operadores no solo asignan memoria, sino que gestionan el ciclo de vida de los objetos,.

1.  **Operador `new`**:
    *   Reserva un bloque de memoria en el Heap suficiente para alojar el objeto o tipo de dato solicitado.
    *   **Invoca automáticamente al constructor** del objeto para inicializarlo.
    *   Devuelve un puntero a la memoria asignada. Si falla, lanza una excepción `std::bad_alloc`,.

2.  **Operador `delete`**:
    *   Libera la memoria previamente reservada con `new` para que vuelva a estar disponible.
    *   **Invoca automáticamente al destructor** del objeto, permitiendo una limpieza adecuada de recursos antes de liberar la memoria,.

### Reglas para Arrays (Arreglos)
C++ distingue entre un objeto único y un arreglo de objetos. Es crucial usar los operadores emparejados correctamente para evitar comportamientos indefinidos,:
*   Para un solo objeto: Se usa `new` y **`delete`**.
*   Para un array: Se usa `new[]` y **`delete[]`**.

---

El siguiente ejemplo demuestra cómo asignar objetos simples y arrays, mostrando cómo se ejecutan los constructores y destructores en el proceso.

```cpp
#include <iostream>

class Sensor {
public:
    int id;
    
    // Constructor
    Sensor(int n) : id(n) {
        std::cout << "  [Construyendo Sensor " << id << "]" << std::endl;
    }
    
    // Constructor por defecto (necesario para arrays sin inicialización brace-init)
    Sensor() : id(0) {
        std::cout << "  [Construyendo Sensor Generico]" << std::endl;
    }

    // Destructor
    ~Sensor() {
        std::cout << "  [Destruyendo Sensor " << id << "]" << std::endl;
    }
};

int main() {
    // CASO 1: Objeto Único
    std::cout << "--- 1. Asignacion de objeto unico ---" << std::endl;
    
    // 'new' reserva memoria y llama al constructor Sensor(10)
    Sensor* pSensor = new Sensor(10); 
    
    // Uso del objeto a través del puntero
    std::cout << "Sensor activo con ID: " << pSensor->id << std::endl;

    // 'delete' llama al destructor y libera la memoria
    delete pSensor; 
    
    // Buena práctica: Asignar nullptr para evitar punteros colgantes (dangling pointers)
    pSensor = nullptr;,


    // CASO 2: Array Dinámico
    std::cout << "\n--- 2. Asignacion de array de objetos ---" << std::endl;
    
    // 'new[]' reserva memoria para 3 objetos y llama al constructor 3 veces
    int tamano = 3;
    Sensor* listaSensores = new Sensor[tamano];

    // Inicializamos manualmente los valores para distinguirlos
    for(int i = 0; i < tamano; i++) {
        listaSensores[i].id = i + 100;
    }

    // 'delete[]' es OBLIGATORIO para arrays. 
    // Llama al destructor de cada elemento (3 veces) y libera el bloque.
    delete[] listaSensores;
    listaSensores = nullptr;

    return 0;
}
```

### Puntos Importantes sobre Seguridad

1.  **Fugas de Memoria (Memory Leaks):** Si olvidas llamar a `delete`, la memoria nunca se libera hasta que termina el programa. Si esto ocurre repetidamente (ej. dentro de un bucle o función), agotarás la memoria del sistema.
2.  **Doble liberación:** Nunca uses `delete` dos veces sobre el mismo puntero sin haberlo reasignado, ya que causará un error grave en tiempo de ejecución.
3.  **Nullptr:** Asignar `nullptr` después de borrar un puntero es una buena práctica porque `delete` sobre un puntero nulo es seguro (no hace nada), protegiéndote de errores accidentales.

Aquí tienes la explicación detallada sobre los arrays dinámicos y el uso de estos operadores específicos, basada en las fuentes proporcionadas.

## Definición: Arrays Dinámicos (`new[]` y `delete[]`)

Los **arrays dinámicos** son estructuras de datos cuyo tamaño se determina durante la ejecución del programa (en tiempo de ejecución), a diferencia de los arrays estáticos cuyo tamaño debe conocerse al compilar. Estos se almacenan en el **Heap** (montón) o almacén libre,.

**1. Operador `new[]`**
Se utiliza para solicitar un bloque de memoria contiguo en el Heap capaz de almacenar múltiples elementos de un tipo específico.
*   **Sintaxis:** `tipo* puntero = new tipo[tamaño];`.
*   **Comportamiento:**
    *   Reserva la memoria necesaria para el número de objetos solicitados.
    *   Si el tipo es una clase, invoca al **constructor predeterminado** para *cada* uno de los elementos del array secuencialmente,.
    *   Devuelve un puntero al primer elemento del bloque asignado.

**2. Operador `delete[]`**
Es el operador obligatorio para liberar la memoria de un array asignado con `new[]`.
*   **Sintaxis:** `delete[] puntero;`.
*   **Comportamiento:**
    *   Invoca al **destructor** de *cada* objeto del array (en orden inverso a su construcción) para realizar la limpieza de recursos individuales,.
    *   Libera el bloque de memoria del Heap para que pueda ser reutilizado.

**Regla de Oro:**
Es crucial usar **`delete[]`** (con corchetes) y no `delete` simple cuando se libera un array. Si usas `delete` en un puntero que apunta a un array, el comportamiento es **indefinido** (puede causar errores graves o fugas de memoria al no destruir todos los elementos),.

---

Este ejemplo demuestra la creación de un array de objetos, evidenciando cómo se llama al constructor y destructor para cada elemento individualmente.

```cpp
#include <iostream>

class Procesador {
public:
    int id;

    // Constructor predeterminado
    // Se llamará automáticamente para CADA elemento al hacer new[]
    Procesador() : id(0) {
        std::cout << "  -> Constructor llamado (Procesador creado)" << std::endl;
    }
    
    // Destructor
    // Se llamará automáticamente para CADA elemento al hacer delete[]
    ~Procesador() {
        std::cout << "  <- Destructor llamado (Procesador " << id << " eliminado)" << std::endl;
    }
};

int main() {
    int cantidad;
    std::cout << "Ingrese la cantidad de procesadores a simular: ";
    // El tamaño se define en tiempo de ejecución (entrada del usuario)
    std::cin >> cantidad;

    // 1. ASIGNACIÓN DEL ARRAY DINÁMICO
    // Se usa new[] para reservar memoria para 'n' objetos.
    // Esto invoca al constructor 'cantidad' veces.
    Procesador* listaCPUs = new Procesador[cantidad]; //

    // Uso del array (se comporta igual que un array estático)
    for (int i = 0; i < cantidad; ++i) {
        listaCPUs[i].id = i + 1; // Acceso mediante índice
    }

    std::cout << "\nSistema procesando datos...\n" << std::endl;

    // 2. LIBERACIÓN DE MEMORIA
    // Es OBLIGATORIO usar delete[] para arrays.
    // Si usáramos 'delete listaCPUs' (sin corchetes), solo se destruiría 
    // el primer elemento o causaría un error grave.
    delete[] listaCPUs; 

    // 3. Buenas prácticas
    // Asignar nullptr evita acceder accidentalmente a memoria ya liberada,.
    listaCPUs = nullptr;

    return 0;
}
```

**Resultado visual de la ejecución:**
Si el usuario ingresa "3", verá 3 mensajes de "Constructor llamado" seguidos (al final) de 3 mensajes de "Destructor llamado". Esto confirma que `new[]` y `delete[]` gestionan el ciclo de vida de todo el conjunto de objetos, no solo la memoria bruta,.

Aquí tienes la explicación detallada sobre los **Punteros**, desglosando su declaración y los operadores fundamentales para manipular direcciones de memoria y valores, tal como lo solicitaste.

## Definición: Punteros (Pointers)

Un puntero es una variable que almacena la **dirección de memoria** de otro objeto en lugar de almacenar el dato en sí mismo. Esto permite manipular datos de manera indirecta, pasar grandes estructuras a funciones sin copiarlas y gestionar memoria dinámica.

### 1. Declaración (`Type* ptr`)
Para declarar un puntero, se especifica el tipo de dato al que apuntará, seguido de un asterisco (`*`) y el nombre de la variable.
*   **Sintaxis:** `Tipo* nombre_puntero;`
*   **Nota:** Es una buena práctica inicializar los punteros con `nullptr` si no se les asigna una dirección inmediatamente, para evitar que apunten a lugares aleatorios de la memoria.

**Ejemplo:**
```cpp
int* ptrEntero;      // Declara un puntero a un entero
std::string* stringPTR; // Declara un puntero a un string (como en tu ejercicio)
```

### 2. Operador de Dirección (`&`)
El operador `&` se coloca antes de una variable existente para obtener su **dirección de memoria**. Es lo que permite conectar un puntero con una variable normal.

**Ejemplo:**
```cpp
std::string mensaje = "HI THIS IS BRAIN";
std::string* stringPTR = &mensaje; // stringPTR ahora guarda la dirección de 'mensaje'
```

### 3. Operador de Desreferencia (`*`)
El operador `*` (cuando no se usa en la declaración) se utiliza para **acceder al valor** almacenado en la dirección de memoria que guarda el puntero. A esto se le llama "desreferenciar" el puntero.

*   Si imprimes `stringPTR`, obtienes la dirección (ej. `0x7ffee...`).
*   Si imprimes `*stringPTR`, obtienes el valor (ej. `"HI THIS IS BRAIN"`).

---

Este ejemplo integra los tres conceptos para mostrar la diferencia entre manipular el puntero (dirección) y el objeto apuntado (valor), algo esencial para entender ejercicios de manipulación de memoria.

```cpp
#include <iostream>
#include <string>

int main() {
    // 1. Variable normal
    std::string var = "HI THIS IS BRAIN";

    // 2. Declaración del puntero e inicialización con la dirección de 'var'
    std::string* stringPTR = &var;

    // IMPRIMIENDO DIRECCIONES DE MEMORIA
    std::cout << "Dirección de 'var' (&var): " << &var << std::endl;
    // Imprime la dirección almacenada en el puntero (debe ser igual a la anterior)
    std::cout << "Dirección en stringPTR:   " << stringPTR << std::endl;

    // IMPRIMIENDO VALORES
    std::cout << "Valor de 'var':           " << var << std::endl;
    // Uso del operador de desreferencia (*) para ver el contenido
    std::cout << "Valor apuntado *stringPTR:" << *stringPTR << std::endl;

    return 0;
}
```

**Resumen del comportamiento:**
1.  `&var`: Obtiene la dirección donde vive la variable.
2.  `stringPTR`: Almacena esa dirección.
3.  `*stringPTR`: Viaja a esa dirección para recuperar el texto original,.

### 1. Punteros a Objetos
Un puntero a un objeto es una variable que almacena la dirección de memoria de una instancia de una clase. Se utilizan frecuentemente para manejar objetos en el *heap* (memoria dinámica), iterar sobre estructuras de datos o pasar objetos a funciones de manera eficiente.

Para acceder a los miembros (métodos o atributos) de un objeto a través de un puntero, se utiliza el operador de flecha (`->`), que es una forma abreviada de desreferenciar el puntero y acceder al miembro `(*puntero).miembro`,.

**Ejemplo:**
```cpp
#include <iostream>
#include <string>

class Robot {
public:
    std::string nombre;
    void Saludar() { std::cout << "Hola, soy " << nombre << std::endl; }
};

int main() {
    // 1. Crear un objeto dinámicamente (en el Heap)
    Robot* ptrRobot = new Robot(); 

    // 2. Acceder a miembros usando el operador flecha (->)
    ptrRobot->nombre = "R2D2"; 
    ptrRobot->Saludar();       

    // 3. Liberar memoria
    delete ptrRobot; 
    return 0;
}
```

---

### 2. Punteros a funciones miembro
A diferencia de los punteros a funciones normales, un puntero a una función miembro almacena la dirección de un método perteneciente a una clase específica. No se puede usar por sí solo; debe invocarse en el contexto de un objeto de esa clase.

**Sintaxis:** `Retorno (Clase::*NombrePuntero)(Argumentos) = &Clase::Metodo;`.

**Características clave:**
*   Deben declararse usando el nombre de la clase y el operador de ámbito `::`.
*   No pueden apuntar a miembros estáticos (esos usan punteros de función normales),.

**Ejemplo de declaración:**
```cpp
class Calculadora {
public:
    int Sumar(int a, int b) { return a + b; }
};

// Declaración del puntero a la función miembro 'Sumar'
// Nota: Se requiere &NombreClase::NombreFuncion
int (Calculadora::*ptrMetodo)(int, int) = &Calculadora::Sumar;
```

---

### 3. Punteros a datos miembro
Un puntero a un dato miembro no apunta a una dirección de memoria absoluta con un valor específico (como un `int*` normal), sino que identifica a un miembro específico dentro de *cualquier* instancia de la clase. Contiene la información del tipo de miembro y el desplazamiento (offset) dentro de la clase.

**Sintaxis:** `Tipo Clase::*NombrePuntero = &Clase::Atributo;`,.

**Ejemplo de declaración:**
```cpp
class Punto {
public:
    int x;
    int y;
};

// Puntero al miembro 'x' de la clase Punto
int Punto::*ptrCoordenadaX = &Punto::x;
```

---

### 4. Uso con operadores `.*` y `->*`
Para utilizar los punteros a miembros (tanto funciones como datos) definidos anteriormente, necesitamos ligarlos a un objeto específico. Para ello existen dos operadores especiales,:

1.  **Operador `.*`**: Se usa cuando tienes una **instancia** del objeto o una referencia.
2.  **Operador `->*`**: Se usa cuando tienes un **puntero** al objeto.

**Nota importante de precedencia:** El operador de llamada a función `()` tiene mayor prioridad que `.*` y `->*`. Por lo tanto, al invocar una función miembro a través de un puntero, es obligatorio usar paréntesis alrededor de la expresión del puntero: `(objeto.*puntero)(args)`,.

**Ejemplo Completo:**
```cpp
#include <iostream>

class Motor {
public:
    int potencia;
    void Encender() { std::cout << "Motor encendido a " << potencia << " HP." << std::endl; }
};

int main() {
    // Definición de punteros a miembros
    int Motor::*ptrDato = &Motor::potencia;           // Puntero a dato miembro
    void (Motor::*ptrFuncion)() = &Motor::Encender;   // Puntero a función miembro

    // Caso A: Usando un Objeto (Operador .*)
    Motor miMotor;
    miMotor.*ptrDato = 150; // Acceso indirecto al atributo 'potencia'
    
    // Llamada a función: Nota los paréntesis obligatorios (objeto.*ptr)()
    (miMotor.*ptrFuncion)(); 

    // Caso B: Usando un Puntero a Objeto (Operador ->*)
    Motor* ptrMotor = new Motor();
    ptrMotor->*ptrDato = 300; // Acceso indirecto a 'potencia' en el heap
    
    (ptrMotor->*ptrFuncion)(); // Llamada a función usando ->*

    delete ptrMotor;
    return 0;
}
```

---

## 1. References (Referencias)

**Definición y Sintaxis:**
Una referencia es un **alias** o un nombre alternativo para una variable que ya existe. Una vez declarada, la referencia y la variable original son indistinguibles: cualquier operación sobre la referencia afecta directamente al dato original,.

*   **Sintaxis:** `Type& ref = var;`
*   **Reglas Clave:**
    1.  **Inicialización obligatoria:** A diferencia de los punteros, una referencia debe inicializarse en el momento de su declaración,.
    2.  **No puede ser NULL:** Una referencia siempre debe estar vinculada a un objeto válido; no existe el concepto de "referencia nula",,.
    3.  **Inmutabilidad del vínculo:** Una vez que una referencia se enlaza a una variable, no se puede cambiar para referenciar a otra,.

**Relevancia para `stringREF`:**
En el contexto de manipular cadenas, una referencia comparte la misma **dirección de memoria** que la variable original, ya que no es una copia, sino el mismo objeto con otro nombre.

**Ejemplo:**
```cpp
#include <iostream>
#include <string>

int main() {
    std::string variableOriginal = "HI THIS IS BRAIN";
    
    // CREACIÓN DE LA REFERENCIA:
    // 'stringREF' se convierte en un alias de 'variableOriginal'.
    // No se crea una nueva string en memoria.
    std::string& stringREF = variableOriginal; //,

    // DEMOSTRACIÓN:
    // Imprimir las direcciones de memoria demuestra que son lo mismo.
    std::cout << "Dirección de variableOriginal: " << &variableOriginal << std::endl;
    std::cout << "Dirección de stringREF:       " << &stringREF << std::endl;

    // Modificar la referencia cambia la original
    stringREF = "BRAIN CHANGED";
    std::cout << "Valor original: " << variableOriginal << std::endl; // Imprime "BRAIN CHANGED"

    return 0;
}
```

---

### 2. Referencias Const (`const Type&`)

**Definición:**
Una referencia constante (`const Type&`) permite acceder al objeto original de manera eficiente (sin hacer copias), pero **prohíbe modificarlo** a través de esa referencia.

**Ventajas y Uso:**
*   **Eficiencia:** Es la forma estándar de pasar o retornar objetos grandes (como `std::string` o clases personalizadas). Si pasaras por valor (`Type var`), se crearía una copia completa del objeto. Con `const Type&`, solo pasas el acceso (similar a un puntero en eficiencia) pero con seguridad de lectura,,.
*   **Seguridad:** Garantiza al llamador que la función no alterará el estado del objeto,.

**Relevancia para `getType()` en `Weapon`:**
Si tu clase `Weapon` tiene un miembro `private std::string type`, el *getter* debe retornar `const std::string&`. Esto permite que quien llame a `getType()` lea el tipo sin copiar la cadena, pero evita que le cambien el nombre al arma desde fuera de la clase.

**Ejemplo:**
```cpp
#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(std::string t) : type(t) {}

    // RETORNO POR REFERENCIA CONSTANTE:
    // 1. Eficiente: No copia el string 'type'.
    // 2. Seguro: El 'caller' no puede cambiar el tipo de arma usando esta referencia.
    const std::string& getType() const { //,
        return type;
    }
    
    void setType(std::string t) { type = t; }
};

int main() {
    Weapon club("Club");
    
    // Acceso eficiente de lectura
    // std::string& ref = club.getType(); // ERROR: getType devuelve const, no se puede asignar a ref modificable.
    const std::string& ref = club.getType(); 
    
    std::cout << "Arma: " << ref << std::endl;
    
    return 0;
}
```

---

### 3. Referencias en Constructores (vs. Punteros)

Este concepto es fundamental para entender la diferencia de diseño entre clases que *dependen* obligatoriamente de otro objeto (HumanA) y clases donde la dependencia es *opcional* o cambiante (HumanB).

#### Caso A: Referencia en Constructor (HumanA - "Siempre Armado")
Si un objeto **requiere** otro objeto para existir y nunca va a cambiar esa dependencia, se usa una referencia.
*   **Inicialización:** Dado que las referencias *deben* inicializarse al nacer y no pueden ser nulas, deben inicializarse obligatoriamente en la **lista de inicialización de miembros** del constructor,.
*   **Semántica:** Indica "No puedo existir sin un Arma" y "Mi arma siempre será esta",,.

#### Caso B: Puntero (HumanB - "Opcional")
Si un objeto puede no tener el recurso (ser `nullptr`) o si se le puede cambiar el recurso más tarde, se usa un puntero.
*   **Inicialización:** Puede inicializarse a `nullptr` o asignarse más tarde mediante una función `setWeapon`,,.
*   **Semántica:** Indica "Puedo tener o no un Arma" y "Puedo soltarla o cambiarla",,.

**Relevancia para `attack()`:**
En `HumanA`, `attack()` usa la referencia directamente (seguro, siempre existe). En `HumanB`, `attack()` debe verificar si el puntero es válido antes de usarlo.

**Ejemplo Comparativo:**

```cpp
#include <iostream>
#include <string>

class Weapon {
public:
    std::string type;
    Weapon(std::string t) : type(t) {}
    const std::string& getType() const { return type; }
};

// --- CASO HUMAN A: REFERENCIA ---
// Diseño: HumanA SIEMPRE tiene un arma. Vida ligada.
class HumanA {
private:
    Weapon& weapon; // Referencia: No puede ser null, no reasignable.

public:
    // IMPORTANTE: Las referencias deben inicializarse en la "Member Initializer List" (: weapon(w))
    // No se pueden asignar dentro de las llaves { weapon = w; } porque ya sería tarde.
    HumanA(std::string name, Weapon& w) : weapon(w) { //,
        // name se guarda...
    }

    void attack() {
        // Uso directo: seguro porque la referencia siempre es válida.
        std::cout << "HumanA ataca con " << weapon.getType() << std::endl;
    }
};

// --- CASO HUMAN B: PUNTERO ---
// Diseño: HumanB puede no tener arma o cambiarla.
class HumanB {
private:
    Weapon* weapon; // Puntero: Puede ser nullptr, puede cambiar.

public:
    // Inicializamos a nullptr para seguridad
    HumanB(std::string name) : weapon(nullptr) {} //

    void setWeapon(Weapon& w) {
        weapon = &w; // Guardamos la dirección de memoria
    }

    void attack() {
        // IMPORTANTE: Verificar si existe antes de usar
        if (weapon != nullptr) { //,
             // Usamos '->' para acceder a miembros desde un puntero
            std::cout << "HumanB ataca con " << weapon->getType() << std::endl;
        } else {
            std::cout << "HumanB no tiene arma" << std::endl;
        }
    }
};

int main() {
    Weapon espada("Espada");
    
    // HumanA: Obligado a recibir un arma en el constructor.
    HumanA bob("Bob", espada); 
    bob.attack();

    // HumanB: Puede crearse sin arma.
    HumanB jim("Jim");
    jim.attack(); // "No tiene arma"
    
    jim.setWeapon(espada); // Ahora se le asigna una
    jim.attack(); // "Ataca con Espada"

    return 0;
}
```
---

### 1. Referencias como Alias: Creación e inicialización

**Definición:**
Una referencia es un nombre alternativo o **alias** para un objeto o variable que ya existe. A nivel interno, no es una copia del dato, sino otra forma de acceder a la misma dirección de memoria,.
A diferencia de los punteros, las referencias tienen reglas estrictas de inicialización:
*   **Inicialización obligatoria:** Una referencia debe vincularse a una variable en el momento mismo de su declaración,.
*   **Inmutabilidad del enlace:** Una vez inicializada, la referencia queda ligada a ese objeto para siempre; no se puede "reasignar" para referenciar a otra variable diferente más tarde,.
*   **No pueden ser nulas:** Una referencia asume que siempre apunta a un objeto válido; no existe el concepto de referencia nula,.

**Ejemplo de código:**

```cpp
#include <iostream>

int main() {
    int variableOriginal = 100;

    // CREACIÓN:
    // Se usa '&' en la declaración. Es OBLIGATORIO asignar la variable aquí.
    int& referencia = variableOriginal; //

    // USO:
    // Modificar la referencia afecta directamente a la original.
    referencia = 200; 

    std::cout << "Original: " << variableOriginal << std::endl; // Imprime 200
    std::cout << "Referencia: " << referencia << std::endl;     // Imprime 200
    
    // int& refInvalida; // ERROR: Debe inicializarse al declararse
    
    return 0;
}
```

---

### 2. Referencias vs. Punteros: Cuándo usar cada uno

**Diferencias Clave:**
Aunque ambos permiten acceso indirecto a objetos, sus usos semánticos son distintos:
*   **Punteros:** Son variables que almacenan direcciones de memoria. Pueden ser `nullptr` (indican ausencia de valor) y pueden reasignarse para apuntar a diferentes objetos durante su vida útil,.
*   **Referencias:** Son alias seguros. Garantizan que el objeto existe (no son nulas) y tienen una sintaxis más limpia al no requerir desreferenciación con `*`,.

**¿Cuándo usar cuál?**
1.  **Usa Referencias (Preferencia predeterminada):** Cuando el objeto **siempre** debe existir y no va a cambiar. Es ideal para parámetros de funciones donde se garantiza un valor válido y para sobrecarga de operadores,.
2.  **Usa Punteros:**
    *   Cuando el valor es **opcional** (puede ser `nullptr`),.
    *   Cuando necesitas **cambiar** a qué objeto apuntas (reasignación).
    *   Para gestión manual de memoria (arrays dinámicos) o aritmética de punteros.

**Ejemplo de código:**

```cpp
#include <iostream>

// Caso 1: Referencia. 
// Semántica: "Necesito un objeto válido obligatoriamente".
void ProcesarSeguro(int& numero) { 
    numero++; // Sintaxis limpia, sin '*'
}

// Caso 2: Puntero.
// Semántica: "El objeto es opcional, puede no existir".
void ProcesarOpcional(int* numero) {
    if (numero != nullptr) { // Debemos verificar si es válido
        (*numero)++;         // Sintaxis con desreferencia
    }
}

int main() {
    int valor = 10;
    
    ProcesarSeguro(valor);      // Llamada simple
    ProcesarOpcional(&valor);   // Debemos pasar la dirección explícitamente
    ProcesarOpcional(nullptr);  // Válido: indica "sin valor"
    
    return 0;
}
```

---

### 3. Referencias Constantes (`const T&`) para eficiencia

**Definición:**
Una referencia constante (`const Tipo&`) permite acceder a un objeto original sin hacer una copia, pero **prohíbe modificarlo** a través de esa referencia. Es una herramienta fundamental para la eficiencia en C++.

**Por qué usarla:**
Al pasar objetos grandes (como `structs` grandes o `std::string`) a una función, pasarlos *por valor* crea una copia completa, lo cual es lento. Pasarlos por `const T&`:
1.  **Evita la copia:** Ahorra memoria y tiempo (eficiencia de puntero).
2.  **Garantiza seguridad:** Asegura que la función no alterará el objeto original (seguridad de valor),.
3.  **Admite temporales:** A diferencia de las referencias normales, una referencia `const` puede aceptar valores temporales (r-values), como el resultado de `1 + 2` o un string literal,.

**Ejemplo de código:**

```cpp
#include <iostream>
#include <string>

struct DatosPesados {
    int matriz;
};

// EFICIENCIA:
// Si pasáramos 'd' por valor (DatosPesados d), se copiarían 1000 enteros.
// Con 'const &', solo se pasa la dirección, pero es de solo lectura.
void AnalizarDatos(const DatosPesados& d) {
    // d.matriz = 5; // ERROR: Es de solo lectura
    std::cout << "Primer valor: " << d.matriz << std::endl;
}

// Acepta temporales gracias a const
void ImprimirMensaje(const std::string& msg) {
    std::cout << msg << std::endl;
}

int main() {
    DatosPesados misDatos = {0};
    AnalizarDatos(misDatos); // Eficiente y seguro
    
    // Podemos pasar un temporal ("Hola") porque la referencia es const
    ImprimirMensaje("Hola mundo"); 
    
    return 0;
}
```

---

### 4. Referencias como Parámetros y Retorno

**Referencias como Parámetros (Paso por referencia):**
Permiten que una función modifique directamente la variable original del llamador, en lugar de recibir una copia local. Se declara colocando `&` en el tipo del parámetro. Es útil para devolver múltiples resultados o modificar el estado de un objeto.

**Referencias como Retorno:**
Una función puede devolver una referencia. Esto permite usar la llamada a la función a la izquierda de una asignación (como un *l-value*).
*   **Advertencia crítica:** Nunca devuelvas una referencia a una variable **local** de la función, ya que esa variable se destruye al terminar la función y la referencia quedaría "colgante" (dangling) apuntando a memoria inválida,.

**Ejemplo de código:**

```cpp
#include <iostream>

// 1. PARAMETRO POR REFERENCIA
// Modifica la variable 'n' original
void Incrementar(int& n) {
    n = n + 1; 
}

int arrayGlobal = {10, 20, 30, 40, 50};

// 2. RETORNO POR REFERENCIA
// Devuelve el acceso directo al elemento del array, no una copia de su valor.
int& ObtenerElemento(int indice) {
    return arrayGlobal[indice]; //
}

int main() {
    int x = 5;
    Incrementar(x); 
    std::cout << "X incrementado: " << x << std::endl; // Imprime 6

    // Uso del retorno por referencia para MODIFICAR el array
    // ObtenerElemento(2) se convierte en un alias de arrayGlobal
    ObtenerElemento(2) = 999; 
    
    std::cout << "Array modificado: " << arrayGlobal << std::endl; // Imprime 999

    return 0;
}
```

### 1. ¿Qué es una dirección de memoria?
La memoria del ordenador se organiza como un conjunto de **celdas**, típicamente de 1 byte, donde cada una tiene una **dirección** asociada única que permite acceder a su ubicación. Es el lugar físico dentro de la memoria (como el *Stack* o el *Heap*) donde se aloja el contenido de una variable. Estas direcciones suelen representarse como valores hexadecimales (por ejemplo, `0x28ff0c`),.

### 2. ¿Qué guarda un puntero?
Un puntero es una variable cuyo contenido es la **dirección de memoria** de otra variable,,. A diferencia de una variable normal que guarda un dato (como un `int` o `char`), el puntero guarda la ubicación donde reside ese dato, permitiendo acceder a él indirectamente. Un puntero puede no apuntar a nada válido si se le asigna el valor `nullptr` (o `NULL`),.

### 3. ¿Qué es un alias?
En C++, una referencia es técnicamente un **alias**: un nombre alternativo para una variable que ya existe,,. No es una copia del dato, sino otra etiqueta para acceder a la misma posición de memoria. Una vez definida, la referencia y la variable original son indistinguibles,.

### 4. ¿Por qué una referencia no puede ser NULL?
Una referencia **debe inicializarse** obligatoriamente en el momento de su declaración, vinculándose a un objeto válido,. No existe el concepto de "referencia nula" en C++; debe existir un objeto al cual referirse desde el principio,. Esto proporciona un contrato de seguridad implícito de que el valor existe, a diferencia de los punteros que pueden ser nulos y causar errores si no se verifican.

### 5. ¿Por qué una referencia no se puede reasignar?
El enlace entre una referencia y su objeto es **inmutable**; una vez que una referencia se inicializa con una variable, queda ligada a ella para siempre,. Si intentas asignar una nueva variable a la referencia (`ref = otraVariable`), no cambias a "quién" apunta la referencia, sino que cambias el **valor** de la variable original a la que la referencia estaba ligada. Los punteros, en cambio, sí pueden "re-apuntar" a diferentes direcciones durante su vida útil.

### 6. Diferencia entre `&` en declaración y `&` en expresión
El símbolo `&` tiene significados opuestos según el contexto:
*   **En una declaración (`int& ref`):** Define el **tipo** de la variable como una referencia. Indica que se está creando un alias,.
*   **En una expresión (`&variable`):** Actúa como el **operador de dirección** (address-of operator). Se utiliza para obtener la dirección de memoria de una variable (algo necesario, por ejemplo, para inicializar un puntero),,.

### 7. Diferencia entre pasar por referencia y por valor
*   **Paso por valor:** Se crea una **copia** del argumento en la pila de la función. Los cambios realizados dentro de la función no afectan a la variable original fuera de ella,.
*   **Paso por referencia:** Se pasa la dirección de memoria (el alias), no una copia. La función opera directamente sobre la variable original, por lo que cualquier cambio dentro de la función se refleja fuera,,. Es más eficiente para objetos grandes porque evita la copia.

---

### Ejemplo de Código Completo

```cpp
#include <iostream>

// Función paso por VALOR (copia)
void pasoPorValor(int x) {
    x = 100; // Solo modifica la copia local 'x'
    std::cout << "Dentro de pasoPorValor: " << x << " (dir: " << &x << ")" << std::endl;
}

// Función paso por REFERENCIA (alias)
void pasoPorReferencia(int& x) { // El '&' aquí indica DECLARACIÓN de referencia
    x = 200; // Modifica la variable original
    std::cout << "Dentro de pasoPorReferencia: " << x << " (dir: " << &x << ")" << std::endl;
}

int main() {
    int numero = 10;
    
    // --- CONCEPTOS DE DIRECCIÓN Y PUNTERO ---
    // '&' en expresión: Operador de dirección
    std::cout << "Valor de numero: " << numero << std::endl;
    std::cout << "Direccion de memoria (&numero): " << &numero << std::endl;

    // Puntero: Guarda la dirección
    int* puntero = &numero; 
    std::cout << "Valor del puntero (direccion): " << puntero << std::endl;
    std::cout << "Valor apuntado (*puntero): " << *puntero << std::endl;

    // --- CONCEPTO DE ALIAS (REFERENCIA) ---
    // '&' en declaración: Define una referencia
    int& alias = numero; 
    
    // Demostración: alias y numero comparten dirección
    std::cout << "Direccion de alias: " << &alias << std::endl; // Misma que &numero

    // --- REASIGNACIÓN (IMPOSIBLE EN REFERENCIAS) ---
    int otroNumero = 50;
    alias = otroNumero; 
    // ¡OJO! Esto NO hace que 'alias' apunte a 'otroNumero'.
    // Esto asigna el VALOR 50 a la variable original 'numero'.
    std::cout << "Nuevo valor de numero tras (alias = 50): " << numero << std::endl;

    // --- PASO POR VALOR VS REFERENCIA ---
    std::cout << "\n--- Pruebas de funciones ---" << std::endl;
    
    numero = 0;
    pasoPorValor(numero);
    std::cout << "Main despues de Valor: " << numero << " (Sin cambios)" << std::endl;

    pasoPorReferencia(numero);
    std::cout << "Main despues de Referencia: " << numero << " (Cambio reflejado)" << std::endl;

    return 0;
}
```
## A. File Streams (`<fstream>`)

C++ maneja los archivos como flujos de datos (*streams*), utilizando la biblioteca `<fstream>`. Esto permite usar operadores como `<<` y `>>` de la misma forma que con `cin` y `cout`,.

### 1. `std::ifstream` (Input File Stream)
Es la clase utilizada para **leer** el contenido de un archivo.
*   **Método `.open()`:** Asocia el objeto stream con un archivo físico. A menudo se hace directamente en el constructor, pero se puede llamar explícitamente. Si el archivo no existe, la apertura fallará.
*   **Método `.is_open()`:** Verifica si el archivo se ha abierto correctamente y está listo para operaciones de lectura. Es fundamental comprobar esto antes de intentar leer para evitar errores,.
*   **Método `.rdbuf()`:** Devuelve un puntero al búfer del archivo (file buffer). Es un "truco" muy eficiente para volcar todo el contenido de un archivo en otro stream (como `std::stringstream` o `std::cout`) sin tener que leer línea por línea.

### 2. `std::ofstream` (Output File Stream)
Es la clase utilizada para **crear y escribir** en archivos,.
*   Por defecto, si el archivo no existe, lo crea. Si existe, lo trunca (borra su contenido anterior) a menos que se especifique el modo `std::ios::app`,.

**Ejemplo de Código: Lectura y Escritura con Streams**

```cpp
#include <iostream>
#include <fstream> // Necesario para ifstream, ofstream
#include <sstream> // Necesario para stringstream

int main() {
    // 1. Abrir archivo para LECTURA
    std::ifstream archivoEntrada("original.txt");

    // 2. Verificar apertura con .is_open()
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo original." << std::endl;
        return 1;
    }

    // 3. Uso de .rdbuf() para cargar todo el contenido
    // Cargamos el buffer del archivo en un stringstream
    std::stringstream buffer;
    buffer << archivoEntrada.rdbuf(); 
    
    // Convertimos el stream a un std::string para manipularlo
    std::string contenido = buffer.str(); 

    // Cerramos el archivo de entrada ya que tenemos los datos
    archivoEntrada.close();

    // --- (Aquí iría la lógica de manipulación de strings) ---

    // 4. Abrir archivo para ESCRITURA (.replace)
    // std::ofstream crea el archivo si no existe
    std::ofstream archivoSalida("original.replace");
    
    if (archivoSalida.is_open()) {
        archivoSalida << contenido; // Escribimos el contenido
        archivoSalida.close();      // Cerramos al terminar
    }

    return 0;
}
```

---

## B. Manipulación de Strings (Sin `replace`)

Dado que el sujeto prohíbe `std::string::replace`, debemos construir nuestra propia lógica de "buscar y reemplazar" utilizando herramientas más básicas proporcionadas por la clase `std::string`.

### Herramientas permitidas

1.  **`find(string, pos)`:** Busca la primera aparición de una subcadena.
    *   Devuelve la posición (índice, `size_t`) donde comienza la subcadena.
    *   Si no encuentra nada, devuelve la constante `std::string::npos`,.
    *   El parámetro `pos` indica desde dónde empezar a buscar.

2.  **`erase(pos, len)`:** Elimina una porción de la cadena actual.
    *   `pos`: Índice donde empezar a borrar.
    *   `len`: Cantidad de caracteres a borrar,.

3.  **`insert(pos, string)`:** Inserta una nueva cadena en una posición específica, desplazando el contenido existente hacia la derecha,.

4.  **`substr(pos, len)`:** Crea y devuelve una *nueva* cadena que es una copia de un fragmento de la original. Útil si quisiéramos construir el resultado en una variable nueva en lugar de modificar la existente,.

### Algoritmo de Sustitución Manual
La lógica para reemplazar todas las ocurrencias de `s1` por `s2` en un texto es:
1.  Buscar `s1` en el texto.
2.  Si se encuentra, borrar `s1` (usando su longitud).
3.  Insertar `s2` en la misma posición.
4.  Actualizar la posición de búsqueda para continuar *después* de la inserción (esto evita bucles infinitos si `s2` contiene a `s1`).

**Ejemplo de Código: Buscar y Reemplazar Manual**

```cpp
#include <iostream>
#include <string> //

void customReplace(std::string& texto, const std::string& buscar, const std::string& reemplazar) {
    if (buscar.empty()) return; // Evitar bucles infinitos si la cadena a buscar es vacía

    size_t pos = 0;
    
    // Bucle: Buscamos 'buscar' empezando desde 'pos'
    // find devuelve std::string::npos si no encuentra nada
    while ((pos = texto.find(buscar, pos)) != std::string::npos) {
        
        // 1. Borramos la palabra antigua
        // erase(posición, longitud)
        texto.erase(pos, buscar.length());

        // 2. Insertamos la palabra nueva en el hueco
        // insert(posición, nueva_cadena)
        texto.insert(pos, reemplazar);

        // 3. Avanzamos el índice 'pos'.
        // Importante: sumamos la longitud del reemplazo para no volver a encontrar 
        // lo que acabamos de insertar (evita recursión infinita).
        pos += reemplazar.length();
    }
}

int main() {
    std::string data = "El perro corre en el parque. El perro es rapido.";
    std::string s1 = "perro";
    std::string s2 = "gato";

    std::cout << "Original: " << data << std::endl;

    customReplace(data, s1, s2);

    std::cout << "Reemplazado: " << data << std::endl;
    
    // Ejemplo rápido de substr (no usado en la lógica anterior, pero solicitado):
    // Extrae "gato" de la cadena modificada
    // Supongamos que "El " ocupa 3 chars, "gato" empieza en índice 3 y mide 4.
    std::string sub = data.substr(3, 4); 
    std::cout << "Substr ejemplo: " << sub << std::endl; // Imprime "gato"

    return 0;
}
```

### Resumen de la Lógica Combinada
Al unir ambos conceptos para tu ejercicio:
1.  Usas `ifstream` y `.rdbuf()` para leer todo el archivo en un `std::string`.
2.  Aplicas el algoritmo de bucle `find` + `erase` + `insert` sobre ese string.
3.  Usas `ofstream` para volcar el string modificado al archivo `.replace`.
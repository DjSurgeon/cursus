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


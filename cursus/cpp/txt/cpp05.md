### ¿Qué son las Excepciones?

Una excepción es una respuesta a una circunstancia excepcional (generalmente un error) que surge mientras un programa se está ejecutando, como un intento de dividir por cero o quedarse sin memoria.

El manejo de excepciones proporciona una manera de transferir el control de una parte del programa a otra. En C++, esto se construye sobre tres palabras clave fundamentales: **try**, **catch** y **throw**.

### Los 3 Componentes Principales

#### 1. `throw` (Lanzar)
Se utiliza para "lanzar" una excepción cuando ocurre un problema. El operando de `throw` determina el tipo de excepción. Puede ser cualquier expresión: un entero, una cadena de texto o, lo más recomendable, un objeto.

#### 2. `try` (Intentar)
El bloque `try` identifica una sección de código en la que se sospecha que podría ocurrir una excepción. Debe ir seguido inmediatamente por uno o más bloques `catch`. El código dentro de este bloque se conoce como "código protegido".

#### 3. `catch` (Capturar)
El bloque `catch` sigue al bloque `try` y es el encargado de "atrapar" la excepción si ocurre. Especifica qué tipo de excepción puede manejar (por ejemplo, `int`, `const char*`, o una clase específica como `std::exception`). Si el tipo lanzado coincide con el tipo del `catch`, se ejecuta el código dentro de él.

---

### ¿Para qué sirven? (Ventajas)

El uso de excepciones ofrece beneficios significativos sobre el manejo de errores tradicional (como devolver códigos de error o usar `if-else`):

1.  **Separación de Código:** Permiten separar claramente el código que detecta el error del código que lo maneja. Esto evita el código "espagueti" donde la lógica normal se mezcla con la lógica de errores.
2.  **Propagación Automática:** Las excepciones pueden subir por la pila de llamadas (*call stack*) hasta encontrar un manejador adecuado. No es necesario comprobar códigos de error en cada función intermedia.
3.  **Constructores:** Los constructores no devuelven valores, por lo que las excepciones son la única forma limpia de reportar que la creación de un objeto falló.
4.  **Limpieza Automática (Stack Unwinding):** Cuando se lanza una excepción, C++ destruye automáticamente los objetos locales que salen del ámbito, liberando recursos correctamente (concepto RAII).

---

### Ejemplos de Código

#### Ejemplo 1: Sintaxis Básica (Lanzando un primitivo)
Este ejemplo muestra cómo lanzar un simple número entero o una cadena de texto. Aunque es válido, no es la práctica más recomendada para sistemas complejos.

```cpp
#include <iostream>

double division(int a, int b) {
    if (b == 0) {
        // Detectamos el error y "lanzamos" un mensaje
        throw "Division por cero!"; 
    }
    return (double)a / b;
}

int main() {
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        // Bloque protegido: código que podría fallar
        z = division(x, y);
        std::cout << z << std::endl;
    } 
    catch (const char* msg) { 
        // Bloque manejador: atrapa la excepción si es de tipo const char*
        std::cerr << "Error capturado: " << msg << std::endl;
    }

    return 0;
}
```

#### Ejemplo 2: Uso de Excepciones Estándar (Buenas Prácticas)
Lo recomendable en C++ moderno es lanzar objetos que deriven de la clase base `std::exception`. Esto permite atrapar errores de forma polimórfica y usar el método `.what()` para obtener detalles. Además, se recomienda capturar por referencia constante (`const &`).

```cpp
#include <iostream>
#include <stdexcept> // Necesario para std::runtime_error, std::invalid_argument

void verificarEdad(int edad) {
    if (edad < 0) {
        // Lanzamos un objeto de excepción estándar
        throw std::invalid_argument("La edad no puede ser negativa.");
    }
    std::cout << "Edad valida: " << edad << std::endl;
}

int main() {
    try {
        verificarEdad(-5);
    } 
    catch (const std::exception& e) {
        // Captura cualquier excepción que herede de std::exception
        std::cerr << "Excepcion capturada: " << e.what() << std::endl;
    }
    
    return 0;
}
```

#### Ejemplo 3: Capturar cualquier excepción (`catch(...)`)
Existe una sintaxis especial con puntos suspensivos `(...)` que atrapa **cualquier** tipo de excepción. Debe usarse con precaución, normalmente como último recurso para evitar que el programa se cierre abruptamente.

```cpp
try {
    // Código que podría lanzar tipos desconocidos de excepciones
    throw 404; 
} 
catch (int e) {
    std::cout << "Error numero: " << e << std::endl;
}
catch (...) {
    // Este bloque atrapa todo lo que no fue atrapado arriba
    std::cout << "Excepcion desconocida capturada." << std::endl;
}
```

### Resumen de Reglas Importantes
1.  **Throw:** Úsalo para señalar un error que la función actual no puede resolver localmente.
2.  **Catch:** Atrapa por referencia (`catch(const MyException& e)`) para evitar copias innecesarias y problemas de recorte de objetos (slicing).
3.  **Destructores:** Nunca lances excepciones desde un destructor. Si ocurre un error ahí, debe manejarse dentro del mismo destructor, de lo contrario, el programa podría terminar abruptamente.

---

### 1. ¿Qué son las Clases Anidadas?

Una **clase anidada** es una clase que se declara dentro del ámbito de otra clase (la clase "envolvente" o *enclosing class*),.

**Características principales:**
*   **Ámbito (Scope):** El nombre de la clase anidada es local a la clase envolvente. Para acceder a ella desde fuera, se debe usar el nombre calificado (ej. `ClaseExterna::ClaseAnidada`),.
*   **Visibilidad:** Respetan los modificadores de acceso (`public`, `private`, `protected`). Si declaras la clase anidada en la sección `private` de la clase externa, no podrá ser utilizada fuera de ella,.
*   **Relación:** La anidación define solo un **tipo** dentro del ámbito. No crea automáticamente un objeto de la clase anidada dentro de la clase externa; no implica una relación de composición directa a menos que declares una variable de ese tipo.
*   **Acceso a miembros:**
    *   La clase anidada tiene acceso a los tipos, enumeradores y miembros estáticos de la clase externa.
    *   En C++ moderno, la clase anidada puede acceder a los miembros privados de la clase externa (actúa como un miembro más), pero la clase externa **no** tiene privilegios especiales para acceder a los miembros privados de la clase anidada,.

---

### 2. Creación de una Excepción Personalizada Anidada

Para crear una excepción personalizada estándar en C++, se debe heredar de la clase base `std::exception` (definida en `<exception>`),. Al anidar esta excepción dentro de la clase que la lanza, agrupamos lógicamente el error con la entidad que lo produce.

#### Elementos necesarios para la herencia de `std::exception`:

1.  **Herencia Pública:** La clase debe heredar públicamente: `public std::exception`,.
2.  **Constructor:** Es recomendable definir un constructor para inicializar el mensaje de error o los datos del error.
3.  **Sobrescritura de `what()`:** La clase base `std::exception` tiene un método virtual `what()` que devuelve una cadena de caracteres estilo C (`const char*`) describiendo el error. Debes sobrescribir este método,.
4.  **Especificador `noexcept`:** Desde C++11, el método `what()` debe marcarse como `noexcept` (o `const throw()` en estándares antiguos), prometiendo que no lanzará otra excepción durante su ejecución,,.

---

### 3. Ejemplo de Código Completo

A continuación, implementaremos una clase `CuentaBancaria`. Dentro de ella, definiremos una clase anidada `FondosInsuficientes` que hereda de `std::exception`.

```cpp
#include <iostream>
#include <exception> // Necesario para std::exception
#include <string>
#include <string_view> // Para manejo eficiente de cadenas

// Clase Envolvente
class CuentaBancaria {
private:
    double saldo;

public:
    // Constructor de la cuenta
    CuentaBancaria(double saldoInicial) : saldo(saldoInicial) {}

    // --- DEFINICIÓN DE CLASE ANIDADA (Excepción Personalizada) ---
    // Se declara en la sección public para que pueda ser capturada (catch) fuera de la clase.
    class FondosInsuficientes : public std::exception {
    private:
        std::string mensaje_error;
        double saldo_actual;
        double monto_solicitado;

    public:
        // Constructor de la excepción
        // Recibe detalles para construir un mensaje informativo
        FondosInsuficientes(double actual, double solicitado) 
            : saldo_actual(actual), monto_solicitado(solicitado) {
            mensaje_error = "Error: Fondos insuficientes. Saldo: " + 
                            std::to_string(saldo_actual) + 
                            ", Solicitado: " + std::to_string(monto_solicitado);
        }

        // Sobrescritura del método virtual 'what'
        // Debe ser 'const' y 'noexcept' para cumplir con la firma de std::exception,
        virtual const char* what() const noexcept override {
            return mensaje_error.c_str(); // Devuelve el puntero a char de la string
        }
    };
    // -------------------------------------------------------------

    // Método que lanza la excepción anidada
    void retirar(double cantidad) {
        if (cantidad > saldo) {
            // Se lanza la excepción anidada
            throw FondosInsuficientes(saldo, cantidad); 
        }
        saldo -= cantidad;
        std::cout << "Retiro exitoso. Nuevo saldo: " << saldo << std::endl;
    }
};

int main() {
    CuentaBancaria miCuenta(100.0);

    try {
        // Intentamos retirar más de lo que tenemos
        miCuenta.retirar(150.0); 
    }
    // Capturamos la excepción específica usando el operador de ámbito ::
    // Se captura por referencia const para evitar copias y 'slicing',
    catch (const CuentaBancaria::FondosInsuficientes& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }
    // Captura genérica polimórfica (buenas prácticas)
    catch (const std::exception& e) {
        std::cerr << "Error genérico: " << e.what() << std::endl;
    }

    return 0;
}
```

### Explicación de los Elementos del Ejemplo

1.  **`class FondosInsuficientes`**: Está declarada dentro de `CuentaBancaria`. Esto indica que este error pertenece lógicamente al contexto bancario.
2.  **`public std::exception`**: Heredamos de la clase estándar para que esta excepción pueda ser capturada por bloques `catch(std::exception&)` genéricos si fuera necesario.
3.  **`what() const noexcept`**:
    *   **`const`**: El método no modifica el objeto excepción.
    *   **`noexcept`**: Garantiza que el sistema de manejo de errores no fallará al intentar reportar el error.
    *   **`override`**: (C++11) Asegura al compilador que estamos sobrescribiendo una función virtual existente.
4.  **`CuentaBancaria::FondosInsuficientes`**: En el bloque `catch` del `main`, debemos usar el nombre completo con el operador `::` porque la clase anidada está oculta dentro del ámbito de `CuentaBancaria`,.


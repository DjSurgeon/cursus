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

# Dudas

¡Claro que sí! Estas dos dudas son fundamentales para entender "el porqué" de lo que estás escribiendo, más allá de simplemente hacer que compile. Vamos a desglosarlo con analogías sencillas.

---

### 1. ¿Qué significa ese `throw()` al final?

Verás esto en tu código:

```cpp
virtual const char* what() const throw();

```

En C++98 (el estándar que usas en 42), esto se llama **Especificación de Excepciones**. Es como un "contrato" o una "promesa" que le hace la función al compilador.

* `void func() throw(int)`: Prometo que solo lanzaré excepciones de tipo `int`.
* `void func() throw(A, B)`: Prometo que solo lanzaré excepciones de tipo `A` o `B`.
* **`void func() throw()`: Prometo que NO lanzaré ninguna excepción.**

**¿Por qué es obligatorio ponerlo aquí?**
Porque la función `what()` original (la que está dentro de la clase padre `std::exception`) está definida así.
Al heredar y sobrescribir (`override`) una función, **no puedes ser menos restrictivo que el padre**.

* Si el padre (`std::exception`) prometió **no fallar nunca** (no lanzar nada), tú (`Bureaucrat`) estás obligado a mantener esa promesa en tu versión de la función.

> **Resumen:** `throw()` significa "Esta función es segura, te prometo que nunca fallará ni lanzará errores".

---

### 2. Clases Anidadas: ¿Por qué una clase dentro de otra?

Has definido esto:

```cpp
class Bureaucrat {
    public:
        class GradeTooHighException : public std::exception { ... };
};

```

Esto se llama **Nested Class** (Clase Anidada).

#### A. Sentido de Pertenencia (Contexto)

Imagina que tienes una excepción llamada `Error`. Es un nombre muy genérico.

* Si la declaras fuera, es un error global.
* Si la declaras dentro, es un error **exclusivo de los Burócratas**.

Al hacerlo así, el nombre completo de tu excepción es:
`Bureaucrat::GradeTooHighException`

Esto le dice a cualquiera que lea tu código: *"Este error de 'nota demasiado alta' pertenece a la lógica de los Burócratas, no a la de los Formularios ni a la de los Animales"*.

#### B. Evitar conflictos de nombres (Scope)

En el siguiente ejercicio (Ex01), crearás la clase `Form`. Los formularios **también** tienen notas y también pueden tener notas demasiado altas.

* Si declaras las excepciones fuera, tendrías que llamar a una `BureaucratGradeTooHigh` y a la otra `FormGradeTooHigh` para que no choquen.
* Al anidarlas, puedes llamar a ambas `GradeTooHighException`, pero el compilador las distingue por su "apellido":
1. `Bureaucrat::GradeTooHighException`
2. `Form::GradeTooHighException`



#### C. Encapsulación

Es una forma de ordenar. Si esa excepción solo se va a usar cuando interactúas con un burócrata, ¿para qué tenerla "tirada" por ahí en medio del código global? La guardas dentro de la caja del Burócrata para mantener el código limpio.

---

### 💡 En resumen

1. **`throw()`**: Es una promesa de seguridad. "Esta función (`what`) solo devuelve un mensaje de texto, te juro que no va a explotar".
2. **Clases Anidadas**: Es para ponerle "apellidos" a tus clases. Ayuda a saber que ese error es culpa exclusiva del Burócrata y permite que otras clases (como `Form`) tengan errores con el mismo nombre sin que se peleen.

Entiendo perfectamente la confusión. Estás mezclando "definir una herramienta" con "usar la herramienta". Vamos a separarlo con dos analogías muy claras, porque esto es la base de todo el manejo de errores en C++.

### 1. ¿Por qué tengo que lanzar (`throw`) la excepción si ya creé la clase?

Imagina que estás diseñando un sistema contra incendios para un edificio.

1. **Crear la clase (`class FireAlarm`)**: Es como **fabricar un botón de alarma** en una fábrica. Tienes el aparato físico, sabes que es rojo y que hace ruido.
2. **Instanciar la clase (`new FireAlarm()`)**: Es como **instalar el botón** en la pared. Ahí está el botón, colgado. ¿Está sonando la alarma? **No**. El edificio sigue tranquilo.
3. **Lanzar la excepción (`throw FireAlarm()`)**: Es **romper el cristal y PULSARA el botón**.

**En programación:**

* Si solo escribes `if (grade < 1) { Bureaucrat::GradeTooHighException(); }`, lo único que haces es crear un objeto temporal en la memoria y destruirlo inmediatamente. El programa sigue ejecutándose como si nada hubiera pasado. ¡El error se ignora!
* Cuando escribes **`throw`**, le dices a la CPU: *"DETÉN todo lo que estás haciendo ahora mismo, deja de ejecutar la siguiente línea y salta hacia atrás hasta encontrar a alguien (un `catch`) que sepa manejar esta emergencia"*.

### 2. ¿Por qué tengo que sobrescribir `what()`?

Aquí entra en juego el **Polimorfismo** (la herencia).

Imagina que en tu `main` tienes un bloque `catch` genérico, porque quieres capturar cualquier error que pase, sea de memoria, de matemáticas o de tus burócratas:

```cpp
try {
    // Código peligroso...
}
catch (std::exception &e) { // <--- Aquí atrapamos al PADRE genérico
    std::cout << e.what() << std::endl;
}

```

* **El problema:** `std::exception` es una clase genérica que viene con C++. Su método `what()` original no sabe nada de "Burócratas" ni de "Grados". Si no lo sobrescribes, devolverá un mensaje genérico ("std::exception") o nada.
* **La solución:** Al sobrescribir `what()`, estás usando la magia de las funciones `virtual`.
Aunque el `catch` reciba una referencia genérica (`std::exception &e`), al llamar a `e.what()`, el programa busca en tiempo de ejecución **de qué tipo es realmente** esa excepción.
* Si es `GradeTooHigh`, ejecutará **TU** versión de `what()` y dirá: "Grade is too high!".



**Resumen:**

1. **`throw`**: Es el acto de "pulsar el botón de pánico". Sin él, la clase excepción es solo un objeto inerte.
2. **`what()`**: Es la forma de "meter una nota dentro de la botella". Como el `catch` suele atrapar excepciones genéricas, necesitas este método estandarizado para poder leer el mensaje de error específico que tú definiste.

----

### 🔄 1. ¿Qué es una Dependencia Circular?

Imagina dos amigos, Ana y Beto:

* **Ana** dice: "No puedo presentarme hasta que **Beto** llegue".
* **Beto** dice: "No puedo presentarme hasta que **Ana** llegue".

Resultado: **Nadie llega nunca.** Se quedan bloqueados esperando al otro.

En C++, el compilador lee los archivos de arriba a abajo.

1. Empieza a leer `Bureaucrat.hpp`.
2. Ve `#include "Form.hpp"`. Paufsa y va a leer `Form.hpp`.
3. Empieza a leer `Form.hpp`.
4. Ve `#include "Bureaucrat.hpp"`.
5. Intenta leer `Bureaucrat.hpp` otra vez...

Gracias a los **Include Guards** (`#ifndef`), el compilador no entra en un bucle infinito, PERO ocurre algo peor: **ignora la segunda inclusión**.

* Resultado: Cuando `Form` intenta usar `Bureaucrat`, el compilador dice: *"¿Bureaucrat? No sé qué es eso, todavía no he terminado de leer su archivo porque estaba ocupado leyendo el tuyo"*.

---

### 🛠️ 2. La Solución: "Forward Declaration" (Declaración Adelantada)

La solución es decirle al compilador: *"Oye, existe una clase llamada Bureaucrat. No te doy los detalles ahora (no te doy el `.hpp` completo), pero confía en mí, existe. Te daré los detalles más tarde en el `.cpp`"*.

Esto se hace con la línea: `class NombreDeLaClase;`

#### Regla de Oro:

* En el **`.hpp`**: Usa **Forward Declaration** siempre que solo necesites usar la clase como puntero (`Class*`) o referencia (`Class&`) en los argumentos de una función.
* En el **`.cpp`**: Usa el **`#include`** real, porque ahí es donde necesitas acceder a las funciones internas (como `.getGrade()`).

---

### 💻 3. Cómo arreglar tu código (Paso a Paso)

Vamos a aplicar esto a tus dos archivos.

#### Archivo A: `Bureaucrat.hpp`

El Burócrata necesita firmar un `Form`.

```cpp
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

// 1. FORWARD DECLARATION
// "Prometo que Form existe, no preguntes más por ahora"
class Form; 

class Bureaucrat
{
    // ... tus atributos y constructores ...

    // 2. USO DE LA REFERENCIA
    // Como usamos 'Form&', al compilador le basta con saber que Form existe.
    // No necesita saber cuánto pesa ni qué métodos tiene todavía.
    void signForm(Form& form); 
};

// ...
#endif

```

#### Archivo B: `Form.hpp`

El Formulario necesita ser firmado por un `Bureaucrat`.

```cpp
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

// 1. FORWARD DECLARATION
// "Prometo que Bureaucrat existe"
class Bureaucrat; 

class Form
{
    // ... atributos ...

    // 2. USO DE LA REFERENCIA
    void beSigned(const Bureaucrat& bureaucrat);
};

// ...
#endif

```

#### Archivo C: `Bureaucrat.cpp` (La Implementación)

Aquí es donde realmente "usamos" al formulario (llamamos a sus métodos), así que aquí SÍ necesitamos el include.

```cpp
#include "Bureaucrat.hpp"
#include "Form.hpp" // <--- AQUÍ SÍ ponemos el include real

// ... constructores ...

void Bureaucrat::signForm(Form& form)
{
    try 
    {
        // Aquí necesitamos ver el código de Form para llamar a beSigned
        form.beSigned(*this); 
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

```

#### Archivo D: `Form.cpp` (La Implementación)

```cpp
#include "Form.hpp"
#include "Bureaucrat.hpp" // <--- AQUÍ SÍ ponemos el include real

// ... constructores ...

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    // Aquí necesitamos ver el código de Bureaucrat para llamar a getGrade
    if (bureaucrat.getGrade() > _signGrade)
    {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

```

### 🎯 Resumen para tu "Cheat Sheet"

1. **En los `.hpp**`: Evita `#include "LaOtraClase.hpp"` si puedes. Usa `class LaOtraClase;`.
2. **En los `.cpp**`: Pon todos los `#include` que necesites para que el código funcione.

---

> **"Una vez virtual, siempre virtual".**

### 1. La Herencia de la Virtualidad

La clase padre, `std::exception`, ya declaró la función `what()` como `virtual`.
En C++, cuando una función es virtual en el padre, **automáticamente se vuelve virtual en todos los hijos**, nietos y bisnietos, **aunque tú no escribas la palabra `virtual**`.

Por eso, poner `virtual` en tu clase `GradeTooHighException` es **opcional** para el compilador (porque ya lo sabe), pero es **buena práctica** para el programador (para que tú sepas que estás sobrescribiendo algo).

### 2. ¿Qué pasaría si el padre NO fuera virtual?

Aquí es donde está la magia. Si `std::exception::what()` **no** fuera virtual (hipotéticamente), tu programa se rompería en el `main` al intentar capturar la excepción de forma genérica.

Mira este ejemplo:

```cpp
try {
    // Lanzamos tu excepción específica
    throw Bureaucrat::GradeTooHighException();
}
catch (std::exception &e) { // <--- ATRAPAMOS COMO PADRE GENÉRICO
    // Aquí ocurre la magia del polimorfismo
    std::cout << e.what() << std::endl;
}

```

* **Caso A (Con `virtual`):**
El programa dice: "Tengo una referencia a `std::exception`, pero voy a mirar en la memoria a ver qué objeto es *realmente*. ¡Ah, es un `GradeTooHighException`! Ejecuto **su** versión de `what()`".
* *Salida:* "Grade is too high!"


* **Caso B (Sin `virtual` en el padre):**
El programa diría: "Tengo una referencia a `std::exception`. Como `what` no es virtual, ejecuto la versión de `std::exception` y me da igual lo que sea el objeto real".
* *Salida:* "std::exception" (o un mensaje genérico inútil).



### 3. ¿Por qué lo escribimos entonces?

Aunque el compilador lo haga implícito, lo escribimos explícitamente por dos razones:

1. **Legibilidad:** Le dices a quien lea tu código: *"Ojo, esta función no es nueva, está modificando el comportamiento de mi padre"*.
2. **Seguridad (En C++11 y superior):** Aunque en 42 usáis C++98, en C++ moderno se usa la palabra clave `override` al final (`virtual ... what() const override`) para que el compilador te avise si te has equivocado al escribir el nombre de la función.

---

Basado en las fuentes proporcionadas, el **Template Method** (Método Plantilla) es un patrón de diseño de comportamiento fundamental en la programación orientada a objetos y C++.

Aquí tienes la explicación detallada de qué son, cómo funcionan y un ejemplo práctico.

### ¿Qué es el Template Method?

El **Template Method** define el **esqueleto de un algoritmo** en una operación de la clase base (generalmente una clase abstracta), postergando la definición de algunos de sus pasos a las subclases.

La idea central es que la **Clase Base** define la **estructura** general del algoritmo (el orden en que se ejecutan las cosas) y garantiza que esta estructura no cambie, mientras que permite a las **Clases Derivadas** redefinir o implementar ciertos pasos específicos sin alterar el flujo general.

### ¿Cómo funciona en una Clase Abstracta?

En el contexto de C++, esto se implementa mediante una combinación de métodos no virtuales (el esqueleto) y métodos virtuales (los pasos personalizables):

1.  **El Método Plantilla (Template Method):** Es un método público en la clase base que contiene la lógica de control. Llama a otros métodos en un orden específico. Generalmente, este método no debería ser sobrescrito por las clases hijas para proteger la estructura del algoritmo.
2.  **Operaciones Primitivas (Pasos Abstractos):** Son funciones virtuales puras (`virtual ... = 0`) declaradas en la clase base. Las subclases **están obligadas** a implementarlas para dar cuerpo a los detalles del algoritmo.
3.  **Ganchos (Hooks):** Son funciones virtuales que tienen una implementación vacía o por defecto en la clase base. Las subclases pueden sobrescribirlas si desean extender el comportamiento en puntos cruciales, pero no es obligatorio.

### Ejemplo de Código (El Héroe de un Juego)

Basado en el ejemplo de las fuentes, imaginemos la lógica de ataque de un héroe en un videojuego. La estructura del ataque es siempre la misma (verificar si puede atacar, luego atacar), pero la forma de atacar cambia según si es un Guerrero o un Arquero.

```cpp
#include <iostream>

// CLASE ABSTRACTA (Define el esqueleto)
class Heroe {
public:
    // 1. EL TEMPLATE METHOD
    // Define el esqueleto del algoritmo.
    // Nótese que no es virtual, para que los hijos no cambien el orden.
    void Atacar() {
        if (PuedeAtacar()) {      // Paso 1: Verificación
            EjecutarAtaque();     // Paso 2: La acción concreta
            GritoDeGuerra();      // Paso 3: Un 'Hook' opcional
        }
    }

protected:
    // 2. OPERACIONES PRIMITIVAS (Abstractas)
    // Los hijos DEBEN implementar estos pasos.
    virtual bool PuedeAtacar() const = 0;
    virtual void EjecutarAtaque() const = 0;

    // 3. HOOK (Gancho)
    // Tiene una implementación por defecto (vacía o genérica).
    // Los hijos PUEDEN sobrescribirlo si quieren.
    virtual void GritoDeGuerra() const {
        std::cout << "(Silencio...)" << std::endl;
    }
    
    // Destructor virtual necesario en clases base
    virtual ~Heroe() = default; 
};

// CLASE CONCRETA 1
class Guerrero : public Heroe {
protected:
    bool PuedeAtacar() const override {
        // Lógica específica del guerrero (ej. tiene estamina)
        return true; 
    }

    void EjecutarAtaque() const override {
        std::cout << "¡El guerrero golpea con su espada!" << std::endl;
    }
    
    // Sobrescribe el Hook
    void GritoDeGuerra() const override {
        std::cout << "¡POR EL REY!" << std::endl;
    }
};

// CLASE CONCRETA 2
class Arquero : public Heroe {
protected:
    bool PuedeAtacar() const override {
        // Lógica específica del arquero (ej. tiene flechas)
        return true;
    }

    void EjecutarAtaque() const override {
        std::cout << "¡El arquero dispara una flecha!" << std::endl;
    }
    
    // El Arquero NO sobrescribe el Hook, usará el defecto (silencio).
};

int main() {
    Guerrero g;
    Arquero a;

    std::cout << "--- Turno del Guerrero ---" << std::endl;
    g.Atacar(); // Llama al Template Method de la base

    std::cout << "\n--- Turno del Arquero ---" << std::endl;
    a.Atacar(); // Llama al Template Method de la base

    return 0;
}
```

### Ventajas y Consideraciones

1.  **Inversión de Control:** Es la clase padre la que llama a los métodos de los hijos ("Don't call us, we'll call you"). El padre decide *cuándo* se ejecutan los pasos; el hijo decide *cómo* se ejecutan.
2.  **Evita Duplicación:** La estructura general del flujo de trabajo se implementa una sola vez en la clase abstracta. No tienes que copiar y pegar la lógica del `if (PuedeAtacar())` en cada héroe.
3.  **Extensibilidad:** Los *hooks* proporcionan puntos de extensión seguros sin romper la lógica central del algoritmo.

Este patrón es extremadamente común en frameworks de C++, donde el framework te da una clase base y te pide que implementes solo métodos específicos (como `setup()` o `loop()` en Arduino, o `Start()` y `Update()` en motores de juegos) mientras el motor controla el flujo principal.

----

Basado en las fuentes proporcionadas, aquí tienes una explicación detallada sobre el uso de `rand()` en C++ y cómo implementar una probabilidad del 50%.

### ¿Qué es la función `rand()`?

La función `rand()` (parte de la librería `<cstdlib>`) genera un número entero **pseudoaleatorio** en el rango comprendido entre **0** y una constante llamada **`RAND_MAX`** (cuyo valor suele ser al menos 32767).

Es importante entender que `rand()` genera una secuencia conocida basada en un valor inicial llamado "semilla" (*seed*). Si no cambias la semilla, el programa generará la misma secuencia de números cada vez que lo ejecutes.

---

### Cómo ejecutar algo con el 50% de probabilidad

Para obtener un resultado binario (Cara/Cruz, Verdadero/Falso) con un 50% de probabilidad, la técnica estándar con `rand()` es utilizar el **operador módulo (`%`)** con el número 2.

La lógica es: `rand() % 2` divide el número aleatorio generado entre 2 y devuelve el residuo. Los únicos residuos posibles al dividir por 2 son **0** y **1**, ambos con aproximadamente la misma probabilidad de aparecer.

#### Ejemplo de Código (Estilo Clásico)

Este ejemplo muestra cómo simular el lanzamiento de una moneda:

```cpp
#include <iostream>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime>   // Necesario para time()

int main() {
    // 1. Inicializar la semilla (Seed)
    // Usamos la hora actual para asegurar que la secuencia cambie en cada ejecución.
    std::srand(std::time(NULL)); 

    // 2. Generar el número y aplicar el módulo
    // rand() % 2 devolverá 0 o 1
    int resultado = std::rand() % 2; 

    // 3. Ejecutar lógica basada en el 50%
    if (resultado == 0) {
        std::cout << "Ha salido CARA (Opción A)" << std::endl;
        // Ejecutar código del caso A
    } else {
        std::cout << "Ha salido CRUZ (Opción B)" << std::endl;
        // Ejecutar código del caso B
    }

    return 0;
}
```


**Puntos Clave del Ejemplo:**
1.  **`std::srand(std::time(NULL));`**: Esto se llama **una sola vez** al inicio del programa. Si omites esta línea, `rand()` se comportará como si la semilla fuera 1, repitiendo siempre los mismos números.
2.  **`% 2`**: Restringe el rango de 0 a `RAND_MAX` al rango 0 a 1.

---

### Alternativa Moderna (C++11 en adelante)

Aunque `rand()` es común en ejemplos sencillos, tiene limitaciones estadísticas (su distribución no es perfectamente uniforme en todos los rangos) y no es segura para criptografía.

Para aplicaciones modernas y robustas, C++11 introdujo la librería `<random>`, que ofrece generadores de mayor calidad como el *Mersenne Twister* (`mt19937`).

**Ejemplo Moderno (Recomendado para calidad):**

```cpp
#include <iostream>
#include <random> // Librería moderna

int main() {
    // Inicializar el dispositivo aleatorio y el generador
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    
    // Definir una distribución uniforme entre 0 y 1 (enteros)
    std::uniform_int_distribution<> dis(0, 1);

    // Generar el número (0 o 1)
    if (dis(gen) == 0) {
        std::cout << "Ejecutar lógica A (50%)" << std::endl;
    } else {
        std::cout << "Ejecutar lógica B (50%)" << std::endl;
    }

    return 0;
}
```

----


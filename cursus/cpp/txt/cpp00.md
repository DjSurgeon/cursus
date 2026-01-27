# c++

## namespace

Un **espacio de nombres** (*namespace*) es una región declarativa que otorga un ámbito específico a los identificadores (como nombres de tipos, funciones y variables) que contiene. Su objetivo principal es organizar el código en grupos lógicos y evitar conflictos de nombres (colisiones), lo cual es especialmente útil cuando se integran varias bibliotecas en una misma base de código.

---

Si un identificador no se declara dentro de un espacio de nombres explícito, pertenece automáticamente al espacio de nombres global implícito.

```cpp
// 1. Declaración del espacio de nombres
namespace DatosEmpresa {
    class Gestor {
    public:
        void Procesar() {}
    };
    
    void FuncionAuxiliar(Gestor) {}
}

int main() {
    // Opción A: Usar el nombre completo (recomendado para evitar ambigüedades)
    DatosEmpresa::Gestor gestor1;
    gestor1.Procesar();
    
    // Opción B: Usar una declaración 'using' para un identificador específico
    using DatosEmpresa::Gestor;
    Gestor gestor2; // Ya no requiere el prefijo
    gestor2.Procesar();
    
    // Opción C: Usar una directiva 'using' para todo el espacio de nombres
    // Nota: Esto trae todos los identificadores al ámbito actual.
    using namespace DatosEmpresa;
    Gestor gestor3;
    FuncionAuxiliar(gestor3);
    
    return 0;
}
```

**Nota sobre buenas prácticas:**
Aunque la directiva `using namespace` es cómoda, se aconseja evitar su uso en archivos de encabezado (`.h`), ya que puede causar problemas de colisión de nombres difíciles de depurar al forzar la inclusión de todo el espacio de nombres en cualquier archivo que use ese encabezado.

Aquí tienes la definición y explicación solicitada basada en las fuentes proporcionadas:

## clase

Una **clase** (`class`) es una construcción fundamental en C++ que define un tipo de objeto agrupando sus **miembros** en una unidad lógica. Su objetivo principal es encapsular el código, separando la interfaz pública (accesible para todos) de los detalles de implementación privados.

*   **Miembros de la clase:** Son los componentes que forman la clase. Incluyen **miembros de datos** (variables que almacenan el estado) y **funciones miembro** (métodos que definen el comportamiento). También existen miembros especiales como el **constructor** (para inicialización) y el **destructor** (para limpieza de recursos). Además, pueden existir miembros **estáticos** (`static`), que son compartidos por todas las instancias de la clase en lugar de pertenecer a un objeto específico.

*   **Control de acceso:** C++ utiliza especificadores para proteger los miembros y evitar el uso indebido de los objetos. El acceso predeterminado en una `class` es **private**. Los niveles son:
    1.  **private:** Solo accesible por funciones de la propia clase y funciones "amigas" (`friend`).
    2.  **protected:** Accesible por la clase, sus amigos y también por clases derivadas (herencia).
    3.  **public:** Accesible por cualquier código externo.

---

El siguiente ejemplo ilustra la sintaxis de una clase, sus tipos de miembros y cómo operan los especificadores de acceso:

```cpp
#include <iostream>

// Declaración de la clase
class SistemaSeguridad {
private: 
    // ACCESO PRIVADO (Predeterminado en class):
    // Solo visible dentro de 'SistemaSeguridad'.
    // Oculta los detalles de implementación (encapsulamiento).
    int codigoSecreto; 
    
    // Miembro estático: compartido por todos los objetos de esta clase.
    static int contadorInstancias; 

protected:
    // ACCESO PROTEGIDO:
    // Visible dentro de esta clase y en clases que hereden de ella (derivadas).
    void ActualizarRegistro() {
        // Lógica interna que las subclases podrían necesitar usar
    }

public:
    // ACCESO PÚBLICO:
    // Define la interfaz que el mundo exterior puede usar.
    
    // Constructor: Inicializa los miembros al crear el objeto.
    SistemaSeguridad(int codigo) : codigoSecreto(codigo) {
        contadorInstancias++; // Modifica el miembro estático compartido
    }

    // Función pública para interactuar con datos privados de forma controlada
    bool ValidarAcceso(int intento) {
        if (intento == codigoSecreto) {
            ActualizarRegistro(); // Puede llamar a miembros protegidos
            return true;
        }
        return false;
    }

    // Método estático: Se puede llamar sin crear un objeto
    static int ObtenerTotalSistemas() {
        return contadorInstancias;
    }
};

// Inicialización del miembro estático (ámbito de archivo)
int SistemaSeguridad::contadorInstancias = 0;

int main() {
    // Uso de la interfaz pública
    SistemaSeguridad sistema(1234);
    
    // sistema.codigoSecreto = 0000; // ERROR: Inaccesible (es private)
    // sistema.ActualizarRegistro(); // ERROR: Inaccesible desde main (es protected)

    if (sistema.ValidarAcceso(1234)) { // OK: ValidarAcceso es public
        std::cout << "Acceso concedido." << std::endl;
    }

    // Acceso a función estática
    std::cout << "Sistemas activos: " << SistemaSeguridad::ObtenerTotalSistemas() << std::endl;

    return 0;
}
```

Aquí tienes las definiciones claras y concisas basadas en la documentación, seguidas de un ejemplo de código comentado.

## Constructores

**Constructores**
Un constructor es una función miembro especial que lleva el mismo nombre que la clase y no tiene tipo de retorno. Su propósito principal es inicializar los objetos de la clase y establecer sus miembros en un estado válido en el momento de la creación. Los constructores pueden ser **sobrecargados** (tener múltiples versiones con diferentes parámetros) y pueden tener accesibilidad pública, protegida o privada,. Si no se define ninguno, el compilador genera uno predeterminado implícito.

**Listas de Inicialización de Miembros**
Es un mecanismo que permite inicializar los miembros de datos directamente **antes** de que se ejecute el cuerpo del constructor. Se define colocando dos puntos (`:`) después de la lista de parámetros del constructor, seguidos de los miembros y sus valores iniciales.

*   **¿Por qué usarlas?** Son más eficientes que asignar valores dentro del cuerpo del constructor, ya que evitan una construcción por defecto seguida de una reasignación,.
*   **¿Cuándo son obligatorias?** Son necesarias para inicializar miembros de tipo referencia, miembros `const` o miembros de clases base que requieren parámetros.

---

Este ejemplo muestra una clase `Caja` con múltiples constructores, destacando la diferencia entre usar la lista de inicialización y la asignación normal, así como la inicialización de constantes.

```cpp
#include <iostream>

class Caja {
private:
    // Miembros de datos privados
    int ancho;
    int largo;
    int alto;
    
    // Miembro constante: SOLO se puede inicializar mediante la lista de inicialización
    const int idSerie; 

public:
    // 1. Constructor Predeterminado
    // Utiliza una lista de inicialización para poner los valores a 0.
    // Si no lo hiciéramos, tendrían valores basura (si no se inicializaron al declarar).
    Caja() : ancho(0), largo(0), alto(0), idSerie(999) {,
        std::cout << "Constructor predeterminado invocado." << std::endl;
    }

    // 2. Constructor con Parámetros usando Lista de Inicialización (Recomendado)
    // Sintaxis: : miembro(valor), miembro(valor)...
    // Esto inicializa directamente los miembros antes de entrar a las llaves {}.
    Caja(int w, int l, int h, int id) 
        : ancho(w), largo(l), alto(h), idSerie(id) {,
        // El cuerpo puede estar vacío porque los datos ya se cargaron.
        std::cout << "Constructor con lista de inicialización." << std::endl;
    }

    // 3. Constructor usando Asignación (Menos eficiente)
    // Aquí, los miembros se inicializan por defecto primero, y LUEGO se les asigna valor.
    // NOTA: No podríamos inicializar 'idSerie' aquí porque es const.
    Caja(int tamanioUnico) : idSerie(100) { 
        ancho = tamanioUnico; // Asignación, no inicialización directa
        largo = tamanioUnico;
        alto = tamanioUnico;
        std::cout << "Constructor con asignación en el cuerpo." << std::endl;
    }
    
    // Constructor explícito: Evita conversiones implícitas accidentales (p.ej. Caja c = 5)
    explicit Caja(double dimension) : ancho((int)dimension), largo((int)dimension), alto((int)dimension), idSerie(500) {,
        std::cout << "Constructor explícito invocado." << std::endl;
    }

    int Volumen() {
        return ancho * largo * alto;
    }
};

int main() {
    // Llama al constructor predeterminado
    Caja caja1; 

    // Llama al constructor con lista de inicialización (int, int, int, int)
    // Se prefiere la inicialización uniforme con {} (C++11 en adelante)
    Caja caja2 {5, 6, 7, 101};

    // Llama al constructor de asignación (int)
    Caja caja3(10);

    return 0;
}
```

## Destructores

Un **destructor** es una función miembro especial que se invoca automáticamente cuando un objeto está a punto de ser destruido. Su propósito principal es realizar la limpieza final, como liberar memoria asignada dinámicamente o cerrar identificadores de recursos del sistema,.

**Características principales:**
*   **Sintaxis:** Tiene el mismo nombre que la clase, pero precedido por una tilde (`~`) (por ejemplo, `~Clase()`).
*   **Sin parámetros ni retorno:** No acepta argumentos y no devuelve ningún valor (ni siquiera `void`).
*   **Invocación automática:** Se llama cuando un objeto sale del ámbito (scope), cuando un programa termina (para objetos globales/estáticos) o cuando se usa el operador `delete` explícitamente en un puntero,.
*   **Destructor Virtual:** Si una clase está diseñada para ser heredada y utilizada polimórficamente (a través de punteros de la clase base), su destructor debe declararse como `virtual`. Esto asegura que se invoque el destructor correcto del objeto derivado y no solo el de la base.

**Orden de destrucción:**
El proceso de destrucción ocurre en orden **inverso** a la construcción:
1.  Se ejecuta el cuerpo del destructor de la clase actual.
2.  Se destruyen los miembros del objeto.
3.  Se llama a los destructores de las clases base (en orden inverso a su declaración en la herencia),.

---

Este ejemplo ilustra la sintaxis, la liberación de memoria dinámica y el orden de ejecución en una jerarquía de herencia.

```cpp
#include <iostream>
#include <cstring> // Para funciones de cadena en el ejemplo

// Clase Base
class RecursoBase {
public:
    RecursoBase() {
        std::cout << "Constructor Base invocado." << std::endl;
    }

    // Es CRÍTICO declarar el destructor como virtual en clases base.
    // Permite destruir objetos derivados correctamente usando un puntero de tipo Base.
    virtual ~RecursoBase() {
        std::cout << "Destructor Base invocado." << std::endl;
    }
};

// Clase Derivada que gestiona memoria dinámica
class GestorTexto : public RecursoBase {
private:
    char* texto; // Puntero para memoria dinámica

public:
    // Constructor: Adquiere el recurso (memoria)
    GestorTexto(const char* entrada) {
        std::cout << "Constructor Derivada (GestorTexto) invocado." << std::endl;
        
        // Asignación dinámica de memoria
        size_t longitud = std::strlen(entrada) + 1;
        texto = new char[longitud];
        
        // Copia segura (usando versión estándar para el ejemplo)
        #ifdef _WIN32
            strcpy_s(texto, longitud, entrada); 
        #else
            strcpy(texto, entrada);
        #endif
    }

    // Destructor Personalizado (~NombreClase)
    // Necesario porque la clase "posee" un recurso dinámico (puntero 'texto').
    ~GestorTexto() {
        std::cout << "Destructor Derivada (GestorTexto) invocado. Liberando memoria..." << std::endl;
        
        // Liberación explícita del recurso.
        // Si no hacemos esto, ocurriría una fuga de memoria (memory leak).
        delete[] texto; 
    }
};

int main() {
    std::cout << "--- Inicio del bloque main ---" << std::endl;

    // 1. Creación del objeto
    // Orden de construcción: Base -> Derivada
    RecursoBase* objeto = new GestorTexto("Ejemplo C++");

    std::cout << "--- Objeto en uso ---" << std::endl;

    // 2. Destrucción del objeto
    // Al usar 'delete' en un puntero base, gracias al destructor 'virtual',
    // se invoca primero el destructor de GestorTexto y luego el de RecursoBase.
    delete objeto; 

    std::cout << "--- Fin del bloque main ---" << std::endl;
    return 0;
}
/* SALIDA ESPERADA:
   Constructor Base invocado.
   Constructor Derivada (GestorTexto) invocado.
   --- Objeto en uso ---
   Destructor Derivada (GestorTexto) invocado. Liberando memoria...
   Destructor Base invocado.
*/
```

**Nota sobre la implementación:**
Si no defines un destructor, el compilador genera uno predeterminado. Sin embargo, este destructor predeterminado no libera memoria asignada con `new` ni cierra archivos abiertos manualmente; en esos casos (como en el ejemplo de `GestorTexto`), estás obligado a definir el tuyo propio para evitar fugas de recursos,.


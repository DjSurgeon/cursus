### 1. ¿Por qué `int` y `float` no son "totalmente exactos"?

Aunque a menudo confiamos en ellos, tanto los enteros como los flotantes tienen limitaciones inherentes a cómo el hardware de la computadora almacena los números (binario finito).

#### El caso de los `int` (Enteros)
Los enteros son exactos **solo dentro de su dominio** (números enteros dentro de un rango). Su inexactitud proviene de su incapacidad para representar fracciones.
*   **Truncamiento:** Si intentas representar $123.4$ en un `int`, la parte decimal ($0.4$) se pierde completamente, resultando en $123$. No hay aproximación, hay pérdida de datos.
*   **Desbordamiento (Overflow):** Tienen un rango fijo. Si sumas 1 al entero máximo posible, el número "da la vuelta" y se convierte en el mínimo negativo (en sistemas con complemento a dos) o comportamiento indefinido, perdiendo el valor real.

#### El caso de los `float` (Punto Flotante)
Los números de punto flotante (IEEE 754) son los verdaderos culpables de la "inexactitud" en cálculos reales. Esto se debe a que **no todos los números decimales tienen una representación binaria finita**.

*   **El problema del infinito binario:** Al igual que $1/3$ es $0.3333...$ (infinito) en decimal, números simples como **0.1** o **0.4** son periódicos infinitos en binario,.
*   **Ejemplo:**
    Para representar $0.4$ en binario:
    $0.4 \times 2 = 0.8$ (bit 0)
    $0.8 \times 2 = 1.6$ (bit 1)
    $0.6 \times 2 = 1.2$ (bit 1)
    $0.2 \times 2 = 0.4$ (bit 0) ... y aquí el ciclo se repite infinitamente,.
    Como la computadora tiene bits finitos (32 para `float`, 64 para `double`), debe cortar (truncar) esa secuencia infinita. Al recuperar el número, ya no es $0.4$, sino algo como $0.40000000596$.

---

### 2. ¿Qué son los Números de Punto Fijo (Fixed Point)?

El **Punto Fijo** es una técnica para representar números fraccionarios utilizando **enteros**. La idea es almacenar un número entero y asumir que el "punto decimal" está siempre en una posición fija preacordada.

#### ¿Cómo funciona?
Imagina que quieres guardar precios en dólares ($10.50$).
*   **En Punto Flotante:** Guardas `10.5`. Riesgo de errores de redondeo.
*   **En Punto Fijo (Base 10):** Guardas `1050` (centavos). Asumes implícitamente un factor de escala de $1/100$.
    *   Para el usuario es $10.50$.
    *   Para la CPU es el entero `1050`.

En computación, se usa generalmente **Punto Fijo Binario**. Se reservan una cantidad de bits para la parte entera y otra para la parte fraccionaria.
*   **Fórmula:** Valor Real = $\frac{\text{Entero Almacenado}}{Factor De Escala}$.
*   El factor de escala suele ser una potencia de 2 ($2^n$) para usar desplazamientos de bits (*bit shifting*), que son operaciones extremadamente rápidas.

#### Ventajas del Punto Fijo
1.  **Rendimiento:** Las operaciones se realizan con la unidad aritmética de enteros (ALU), que es más rápida y consume menos energía que la unidad de punto flotante (FPU). Es ideal para sistemas embebidos, DSP (Procesamiento Digital de Señales) y consolas antiguas o FPGAs,.
2.  **Determinismo:** A diferencia de los flotantes, el punto fijo siempre da el mismo resultado en todas las máquinas, ya que es matemáticas de enteros pura.
3.  **Precisión controlada:** La resolución absoluta es constante en todo el rango.

---

### 3. Ejemplo de Código y Uso en C++

C++ no tiene un tipo nativo `fixed_point` en el estándar actual (aunque hay propuestas como N1169), por lo que debemos implementarlo manualmente usando clases y sobrecarga de operadores.

A continuación, un ejemplo de una clase `FixedPoint` que utiliza los últimos 8 bits de un entero para la parte fraccionaria (formato Q24.8 en un sistema de 32 bits),.

```cpp
#include <iostream>
#include <cmath> // Para roundf

class FixedPoint {
private:
    int _rawBits; // El contenedor entero
    static const int _fractionalBits = 8; // Bits reservados para la parte decimal

public:
    // 1. Constructor por defecto
    FixedPoint() : _rawBits(0) {}

    // 2. Constructor desde Entero
    // Para convertir entero a punto fijo, desplazamos a la izquierda (multiplicamos por 2^8)
    // Ejemplo: 1 se convierte en 256 (00000001 00000000)
    FixedPoint(const int n) {
        _rawBits = n << _fractionalBits; 
    }

    // 3. Constructor desde Flotante
    // Multiplicamos por 2^8 (256) y redondeamos para guardar como entero
    FixedPoint(const float n) {
        _rawBits = roundf(n * (1 << _fractionalBits)); 
    }

    // 4. Conversión a Flotante
    // Dividimos el valor crudo por 2^8 para recuperar el decimal
    float toFloat() const {
        return (float)_rawBits / (1 << _fractionalBits);
    }

    // 5. Conversión a Entero
    // Desplazamos a la derecha (división entera por 2^8), perdiendo la parte decimal
    int toInt() const {
        return _rawBits >> _fractionalBits;
    }
    
    // Sobrecarga de operador de asignación
    FixedPoint& operator=(const FixedPoint& other) {
        if (this != &other) {
            _rawBits = other._rawBits;
        }
        return *this;
    }

    // --- OPERACIONES ARITMÉTICAS ---

    // Suma: Directa, como son enteros con la misma escala, solo se suman.
    FixedPoint operator+(const FixedPoint& other) const {
        FixedPoint resultado;
        resultado.setRawBits(this->_rawBits + other._rawBits);
        return resultado;
    }

    // Multiplicación: Más compleja.
    // (A * 2^8) * (B * 2^8) = (A * B) * 2^16. 
    // Tenemos 16 bits de fracción, necesitamos volver a 8. Dividimos por 2^8.
    FixedPoint operator*(const FixedPoint& other) const {
        FixedPoint resultado;
        // Usamos long long para evitar desbordamiento antes de la división
        long long temp = (long long)this->_rawBits * other._rawBits;
        resultado.setRawBits(temp >> _fractionalBits);
        return resultado;
    }

    // Métodos auxiliares para acceso a los bits crudos (útil para serialización)
    int getRawBits() const { return _rawBits; }
    void setRawBits(int const raw) { _rawBits = raw; }
};

// Sobrecarga externa para imprimir fácilmente con std::cout
std::ostream& operator<<(std::ostream& os, const FixedPoint& fp) {
    os << fp.toFloat();
    return os;
}

int main() {
    FixedPoint a(1.23f); // Guarda internamente aprox 315 (1.23 * 256)
    FixedPoint b(2);     // Guarda internamente 512 (2 * 256)
    
    FixedPoint c = a + b; // Suma directa de bits: 315 + 512 = 827
                          // 827 / 256 = 3.2304...

    std::cout << "A (fixed): " << a << " | Raw bits: " << a.getRawBits() << std::endl;
    std::cout << "B (fixed): " << b << " | Raw bits: " << b.getRawBits() << std::endl;
    std::cout << "Suma (A+B): " << c << std::endl;
    
    FixedPoint d = a * b; 
    std::cout << "Multiplicación (A*B): " << d << std::endl;

    return 0;
}
```

#### Análisis del Ejemplo
1.  **Almacenamiento:** El número `1.23` se convierte. $1.23 \times 256 \approx 314.88$. Se redondea y guarda como el entero `315`.
2.  **Precisión:** Al imprimir `a.toFloat()`, hacemos $315 / 256 = 1.23046875$. Observa que hay una pequeña diferencia respecto a $1.23$ original. Esta es la **resolución** determinada por los 8 bits fraccionarios ($1/256 \approx 0.0039$).
3.  **Velocidad:** La suma `a + b` es una simple suma de enteros para la CPU (`315 + 512`), lo cual toma un solo ciclo de reloj en casi cualquier procesador, evitando la lógica compleja de alinear mantisas y exponentes del punto flotante.

----

### ¿Qué es la Forma Canónica Ortodoxa (OCF)?

La Forma Canónica Ortodoxa, también conocida como *Orthodox Canonical Form* o **forma de Coplien**, es un modismo o convención de diseño en C++. Su objetivo es asegurar que una clase definida por el usuario se comporte como un "tipo de dato concreto" (similar a los tipos nativos como `int`) en términos de ciclo de vida y gestión de memoria.

Para cumplir con la OCF, una clase debe definir explícitamente cuatro funciones miembro especiales,:

1.  **Constructor por defecto** (*Default Constructor*).
2.  **Constructor de copia** (*Copy Constructor*).
3.  **Operador de asignación** (*Copy Assignment Operator*).
4.  **Destructor**.

Si no se implementan, el compilador los genera automáticamente, pero estas versiones generadas suelen realizar copias superficiales (*shallow copies*), lo cual es peligroso si la clase gestiona memoria dinámica (punteros),.

---

### Los 4 Componentes de la OCF

#### 1. Constructor por Defecto
Es el constructor que no recibe argumentos (o tiene valores por defecto para todos ellos). Permite crear objetos "vacíos" o en un estado inicial válido sin necesidad de proporcionar datos externos.
*   **Importancia:** Es necesario para declarar arrays de objetos o contenedores de la clase.

#### 2. Constructor de Copia
Inicializa un **nuevo** objeto como una copia idéntica de uno **existente**.
*   **Sintaxis:** `Clase(const Clase& otro);`
*   **Función:** Es crucial cuando la clase tiene punteros. El constructor generado por el compilador solo copia la dirección de memoria (copia superficial), haciendo que dos objetos apunten al mismo recurso. El constructor de copia debe realizar una **copia profunda** (reservar nueva memoria y copiar el contenido),,.

#### 3. Operador de Asignación de Copia
Asigna el estado de un objeto existente a **otro objeto que ya existe** (a diferencia del constructor de copia, que crea uno nuevo).
*   **Sintaxis:** `Clase& operator=(const Clase& otro);`
*   **Pasos críticos:**
    1.  Verificar la **auto-asignación** (`if (this != &other)`), para evitar errores al asignar un objeto a sí mismo.
    2.  Liberar la memoria actual del objeto receptor (para evitar fugas de memoria).
    3.  Realizar la copia profunda del nuevo contenido.
    4.  Retornar `*this` para permitir asignaciones encadenadas (`a = b = c`).

#### 4. Destructor
Se invoca automáticamente cuando el objeto sale del ámbito o se elimina explícitamente. Su función es liberar los recursos (memoria dinámica, archivos abiertos) que el objeto adquirió durante su vida,.

---

### Ejemplo de Código 1: Estructura Básica

Este es el esqueleto que debe tener cualquier clase para cumplir con la OCF:

```cpp
#include <iostream>

class EjemploOCF {
public:
    // 1. Constructor por Defecto
    EjemploOCF() {
        std::cout << "Constructor por defecto llamado" << std::endl;
    }

    // 2. Constructor de Copia
    EjemploOCF(const EjemploOCF& otro) {
        std::cout << "Constructor de copia llamado" << std::endl;
        *this = otro; // A menudo se delega o se copia lógica aquí
    }

    // 3. Operador de Asignación
    EjemploOCF& operator=(const EjemploOCF& otro) {
        std::cout << "Operador de asignación llamado" << std::endl;
        if (this != &otro) { // Protección contra auto-asignación
            // Lógica de copia aquí
        }
        return *this; // Retornar referencia al objeto actual
    }

    // 4. Destructor
    ~EjemploOCF() {
        std::cout << "Destructor llamado" << std::endl;
    }
};
```

---

### Ejemplo de Código 2: Gestión de Memoria Dinámica (Caso Real)

Este ejemplo muestra por qué la OCF es vital. Imagina una clase que maneja una cadena de caracteres (`char*`) dinámicamente. Sin OCF, copiar este objeto causaría errores de memoria (doble liberación o fugas).

```cpp
#include <iostream>
#include <cstring> // Para strlen, strcpy

class Cadena {
private:
    char* _datos; // Recurso dinámico (puntero)

public:
    // 1. Constructor por Defecto
    // Inicializa el puntero en un estado válido (cadena vacía)
    Cadena() {
        std::cout << "Constructor por defecto" << std::endl;
        _datos = new char;
        _datos = '\0'; 
    }

    // Constructor con parámetros (Auxiliar, no estricto OCF pero útil)
    Cadena(const char* str) {
        if (str) {
            _datos = new char[strlen(str) + 1];
            strcpy(_datos, str);
        } else {
            _datos = new char;
            _datos = '\0';
        }
    }

    // 2. Constructor de Copia
    // Crea una copia PROFUNDA del recurso.
    Cadena(const Cadena& otra) {
        std::cout << "Constructor de copia" << std::endl;
        // Reservamos nueva memoria para este nuevo objeto
        _datos = new char[strlen(otra._datos) + 1];
        // Copiamos el contenido real, no solo la dirección
        strcpy(_datos, otra._datos);
    }

    // 3. Operador de Asignación
    Cadena& operator=(const Cadena& otra) {
        std::cout << "Operador de asignación" << std::endl;
        
        // A. Chequeo de auto-asignación (ej: a = a)
        if (this == &otra)
            return *this;

        // B. Limpieza del recurso anterior
        delete[] _datos; 

        // C. Copia profunda del nuevo recurso
        _datos = new char[strlen(otra._datos) + 1];
        strcpy(_datos, otra._datos);

        // D. Retorno de referencia
        return *this;
    }

    // 4. Destructor
    // Libera la memoria para evitar memory leaks.
    ~Cadena() {
        std::cout << "Destructor: liberando memoria" << std::endl;
        delete[] _datos; //,
    }
    
    // Método auxiliar para ver el contenido
    const char* getContenido() const { return _datos; }
};

int main() {
    Cadena s1("Hola Mundo");
    
    // Uso del Constructor de Copia
    Cadena s2 = s1; // s2 es una copia nueva e independiente de s1
    
    Cadena s3;
    // Uso del Operador de Asignación
    s3 = s1; // s3 descarta su contenido y copia el de s1

    return 0; 
    // Al salir, se llama al destructor de s3, s2 y s1.
    // Sin OCF, s1, s2 y s3 intentarían liberar la misma memoria (double free).
}
```

---

### Principales Casos de Uso

La Forma Canónica Ortodoxa es esencial en los siguientes escenarios:

1.  **Clases con Punteros (Gestión de Recursos):**
    Si una clase tiene miembros que son punteros a memoria dinámica (`new`), manejadores de archivos o sockets, es **obligatorio** usar OCF. Si usas la copia por defecto del compilador, solo se copiará el puntero (dirección), no el dato. Esto lleva a que dos objetos compartan la misma memoria, y cuando uno se destruye, el otro se queda con un puntero "colgante" (*dangling pointer*), provocando fallos graves,,.

2.  **Uso en Contenedores (STL):**
    Para almacenar objetos de tu clase en contenedores estándar como `std::vector` o `std::list`, o arrays clásicos, la clase debe ser capaz de copiarse y asignarse correctamente. Si no implementas el constructor de copia o por defecto correctamente, estas estructuras de datos no funcionarán.

3.  **Semántica de Valor:**
    Se utiliza cuando quieres que tu objeto se comporte como una variable primitiva (por ejemplo, `int`). Si copias un `int a = 5` en `int b = a`, cambiar `b` no afecta a `a`. La OCF garantiza este aislamiento e independencia entre objetos,.

4.  **La "Regla de los Tres":**
    En C++98 (y vigente hoy si manejas recursos manuales), existe una regla empírica derivada de la OCF: Si necesitas definir explícitamente **uno** de los tres (Destructor, Constructor de Copia o Asignación), es casi seguro que necesitas definir **los tres** para garantizar la seguridad de la memoria.
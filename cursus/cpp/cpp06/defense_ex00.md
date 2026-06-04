# Guía de Defensa para ex00 (ScalarConverter)

## ¿Qué es `static_cast` y por qué lo usamos?

En C++, los *casts* (conversiones de tipo) son herramientas para transformar una variable de un tipo a otro. `static_cast` es el cast principal utilizado para **conversiones escalares y estándar** (como pasar de `int` a `float`, o de `char` a `int`).

### ¿Por qué no usamos el cast estilo C `(tipo)variable`?
El cast al estilo C (ej. `(int)miFloat`) es muy peligroso en C++. Cuando usas el estilo C, el compilador intenta hacer la conversión a la fuerza probando una cascada de métodos ocultos. Si no puede hacer un `static_cast`, lo intentará transformar a nivel de bits (como un `reinterpret_cast`) o incluso saltarse la seguridad de constantes (`const_cast`). Esto puede causar bugs muy difíciles de rastrear.

Al usar `static_cast<tipo>(variable)` le estás diciendo al compilador: *"Quiero que conviertas el valor de esta variable a este otro tipo de manera segura y lógica"*. Si la conversión no tiene sentido a nivel semántico, **el programa no compilará**. Esto aporta seguridad y hace que el código deje muy claras tus intenciones.

---

## 🎯 Preguntas Clave para la Defensa (Evaluación)

A continuación, tienes las preguntas más comunes que un evaluador te hará en este ejercicio, junto con cómo deberías responderlas.

### 1. ¿Cuál es la diferencia entre `static_cast` y el resto de casts en C++ (`dynamic_cast`, `reinterpret_cast`, `const_cast`)?
**Respuesta ideal:**
- **`static_cast`**: Es para conversiones lógicas y numéricas (escalares) en tiempo de compilación. Convierte el valor en sí.
- **`dynamic_cast`**: Solo se usa con punteros y referencias de clases polimórficas (con herencia y métodos virtuales). Chequea en tiempo de ejecución si la conversión de una clase Base a Derivada es válida.
- **`reinterpret_cast`**: No convierte el valor, simplemente le dice al compilador "interpreta estos ceros y unos de la memoria como si fueran otra cosa" (ej. convertir un puntero a un número entero).
- **`const_cast`**: Únicamente sirve para quitar o poner la propiedad `const` o `volatile` a una variable.

### 2. ¿Qué pasa si casteas un `float` gigante (ej. `1e20f`) a un `int`?
**Respuesta ideal:**
En C++, cuando conviertes un número de coma flotante que es más grande de lo que un `int` puede almacenar (`INT_MAX`), se produce un **Undefined Behavior (Comportamiento Indefinido)**. Esto significa que el programa podría darte un número negativo aleatorio, bloquearse, o devolver el máximo posible dependiendo de la arquitectura y el compilador.
*Extra:* "Por eso en el código validamos si el valor original excede `INT_MAX` o `INT_MIN` utilizando el double guardado original (`valueAsDouble`), para así imprimir 'impossible' y protegernos de usar el valor corrompido que devuelve el cast."

### 3. ¿Por qué has utilizado funciones como `std::strtol` o `std::strtod` en lugar de `std::stoi` o `std::stof`?
**Respuesta ideal:**
Porque el subject requiere adherencia estricta al estándar **C++98**. Funciones como `std::stoi` y `std::stof` fueron introducidas en C++11. Por lo tanto, dependemos de las funciones de la librería de C heredada en `<cstdlib>` para hacer el parseo seguro en C++98.

### 4. ¿Por qué todos los constructores y el operador de asignación de `ScalarConverter` son privados?
**Respuesta ideal:**
El subject especifica claramente que *"The class must not be instantiable"* (La clase no debe poder instanciarse). Al declarar los constructores y el destructor de forma privada, nos aseguramos de que nadie pueda hacer `ScalarConverter myConverter;`. La clase solo funciona como un contenedor o espacio de nombres para el método estático `convert`.

### 5. ¿Por qué es necesario hacer cast explícitamente en el código si en C++ puedes igualar un `char c = 65;` y se castea solo?
**Respuesta ideal:**
Aunque el compilador puede hacer conversiones implícitas de `int` a `char`, el subject requiere que se demuestre el control total sobre los tipos de datos en C++ mediante el uso explícito de los casts de C++ (`static_cast`). Es una cuestión de demostrar que entendemos la jerarquía de tipos y cómo forzar las conversiones de manera idiomática en C++ (evitando el comportamiento implícito de C).

### 6. ¿Cómo detectas si un literal es un tipo especial como `nan` o `inf`?
**Respuesta ideal:**
En la fase de identificación (`isSpecial`), comparo el string literal contra las cadenas específicas dictadas por el subject (`nan`, `+inf`, `-inf`, `nanf`, etc.). Para representarlos internamente, confío en el parseo de `std::strtod`, que sabe traducir "nan" o "inf" a los valores double especiales, y si este falla, fuerzo el valor a `std::numeric_limits<double>::quiet_NaN()` o infinito usando los límites de la cabecera `<limits>`.

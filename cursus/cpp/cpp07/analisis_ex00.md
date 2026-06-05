# Análisis ex00: Start with a few functions

## 1. ¿De qué trata el ejercicio?
El ejercicio `ex00` del Módulo 07 nos introduce al concepto de **Plantillas de Funciones (Function Templates)** en C++. El objetivo es implementar tres funciones genéricas básicas que puedan trabajar con cualquier tipo de dato (enteros, flotantes, strings, e incluso objetos de clases personalizadas, siempre y cuando estas soporten los operadores necesarios).

Las tres funciones a implementar son:
- `swap`: Intercambia los valores de dos variables dadas.
- `min`: Compara dos valores y devuelve el menor. Si son iguales, devuelve el segundo.
- `max`: Compara dos valores y devuelve el mayor. Si son iguales, devuelve el segundo.

## 2. ¿Qué vamos a aprender?
- **Sintaxis de Plantillas:** Cómo declarar e implementar templates usando `template <typename T>`.
- **Compilación de Plantillas:** Entender por qué la implementación de las plantillas debe ir en el archivo de cabecera (`.hpp`) y no en un archivo fuente separado (`.cpp`). En C++, el compilador necesita tener acceso al código fuente de la plantilla en el momento y lugar donde esta es instanciada para generar la versión específica de esa función.
- **Tipado Genérico:** Comprender cómo una sola porción de código puede adaptarse dinámicamente a distintos tipos de datos.
- **Pasaje por Referencia:** Uso de referencias (`T&` y `const T&`) para modificar variables (como es el caso de `swap`) o para evitar copias costosas al pasar parámetros y devolver valores (en el caso de `min` y `max`).

## 3. ¿Qué vamos a realizar?
Se requiere crear un directorio `ex00/` y entregar los siguientes archivos:
1. **`whatever.hpp` (o `.h`):** En este archivo de cabecera declararemos e implementaremos las tres plantillas de función (`swap`, `min` y `max`).
2. **`main.cpp`:** Contendrá el código de prueba (el cual viene proporcionado en el *subject*) para demostrar el uso de nuestras plantillas con variables int y std::string.
3. **`Makefile`:** El sistema de compilación habitual con las reglas `all`, `clean`, `fclean`, `re` y usando los flags obligatorios `c++ -Wall -Wextra -Werror -std=c++98`.

## 4. ¿Cómo vamos a afrontarlo? (Consideraciones Técnicas)

### a) Implementación en Cabecera
Todo el código de `swap`, `min` y `max` residirá en `whatever.hpp`. Utilizaremos las directivas del preprocesador de C++ (`#ifndef`, `#define`, `#endif`) para proteger el archivo contra inclusiones múltiples.

### b) Análisis individual de las funciones:

- **`swap`**:
  - *Firma lógica*: `template <typename T> void swap(T& a, T& b);`
  - *Estrategia*: Usaremos una variable local temporal de tipo `T` para guardar el valor de `a`, luego asignaremos `b` a `a`, y finalmente asignaremos el valor temporal a `b`. Es imprescindible usar referencias `T&` para modificar las variables originales.

- **`min`**:
  - *Firma lógica*: `template <typename T> const T& min(const T& a, const T& b);`
  - *Estrategia*: Usaremos el operador ternario. Evaluamos `(a < b)`. Si es verdadero, devolvemos `a`. Si es falso (lo que incluye el caso donde `a` es mayor o **igual** a `b`), devolvemos `b`. De este modo cumplimos la norma de devolver el segundo argumento si son iguales: `return (a < b) ? a : b;`. Se utilizan referencias constantes (`const T&`) tanto en los parámetros como en el tipo de retorno para optimizar el paso de objetos grandes por memoria.

- **`max`**:
  - *Firma lógica*: `template <typename T> const T& max(const T& a, const T& b);`
  - *Estrategia*: De manera análoga, evaluamos `(a > b)`. Si es verdadero, devolvemos `a`. Si es falso (es menor o igual), devolvemos `b`. Retornando: `return (a > b) ? a : b;`.

### c) Testing y Main
Utilizaremos exactamente el `main` provisto en el documento `sub.md` para verificar que la salida por consola coincida línea por línea con la salida esperada en las instrucciones.

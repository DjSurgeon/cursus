Viewed sub.md:1-262

¡Hola! He revisado el archivo `sub.md` que contiene las instrucciones del **Módulo 07 de C++**. Como este módulo no requiere que escribamos código todavía, sino que quieres una explicación, no generaré un plan de implementación.

Para empezar, aquí tienes el **resumen de los elementos clave y temas importantes** que vas a aprender en este módulo:

### 📚 Resumen de Conceptos Clave (C++ Module 07)

El tema central absoluto de este módulo son las **Plantillas (Templates) en C++**. Las plantillas nos permiten escribir código genérico (meta-programación) que funciona para cualquier tipo de dato, evitando tener que reescribir la misma función o clase para `int`, `float`, `std::string`, etc.

Los temas principales que vas a tratar son:
1. **Plantillas de Funciones (Function Templates):** Aprenderás a definir funciones genéricas usando `template <typename T>`. Esto lo verás en el `ex00` (`swap`, `min`, `max`) y en el `ex01` (`iter`).
2. **Plantillas de Clases (Class Templates):** Aprenderás a crear clases completas que pueden manejar cualquier tipo de dato interno. Lo aplicarás en el `ex02` creando tu propia clase `Array<T>`.
3. **Manejo de Constantes en Plantillas:** En el `ex01` se te exigirá que tu función genérica sepa lidiar tanto con variables mutables como con variables inmutables (`const`), lo cual es un desafío clásico en C++.
4. **Gestión de Memoria y Punteros a Arrays:** En el `ex02`, volverás a trabajar con la asignación dinámica (`new[]` y `delete[]`) para gestionar memoria de arreglos, asegurándote de no tener fugas de memoria (memory leaks).
5. **Excepciones (Exceptions):** Reforzarás el uso de excepciones (`try/catch` y `throw std::exception`) para manejar errores de forma segura, como el acceso a un índice fuera de los límites de un array.
6. **Forma Canónica Ortodoxa en Clases Genéricas:** Deberás aplicar la regla de los 4 (Constructor por defecto, Constructor de copia, Operador de asignación, Destructor) a tu clase plantilla `Array`, garantizando que las "copias profundas" (deep copies) funcionen correctamente sin afectar a la instancia original.

---

### 📖 Explicación paso a paso de los Ejercicios (Respetando la Normativa)

A continuación, te explico los detalles de cada ejercicio basándome en las instrucciones del documento:

#### **Exercise 00: Start with a few functions**
El objetivo aquí es crear tus primeras **plantillas de funciones**.
*   **Restricciones y Normativa:** No hay funciones prohibidas, pero las plantillas **deben** estar definidas en los archivos de cabecera (header files, por ejemplo, `whatever.hpp`). En C++, el compilador necesita ver la implementación completa de un template para instanciarlo.
*   **`swap(a, b)`:** Tienes que escribir una plantilla que intercambie los valores de dos variables. Su firma implícita será algo como `template <typename T> void swap(T& a, T& b);`. Debes pasar los argumentos por referencia para poder modificarlos.
*   **`min(a, b)` y `max(a, b)`:** Tienes que devolver el menor y el mayor de dos valores, respectivamente. Si son iguales, **debes devolver el segundo**. Ambas funciones deben poder recibir cualquier tipo (siempre y cuando esos tipos tengan sobrecargados los operadores de comparación como `<`, `>`, `==`).

#### **Exercise 01: Iter**
Aquí crearás una función que itera sobre un array genérico y aplica una función a cada elemento.
*   **Parámetros requeridos:** 
    1. La dirección de memoria de un array (ej. un puntero `T*`).
    2. La longitud del array (debe ser un valor constante, típicamente `size_t` o `unsigned int`).
    3. Una función que se llamará por cada elemento.
*   **El desafío clave ("Think carefully about how to support both const and non-const elements"):** Tu plantilla debe ser capaz de recibir tanto un array normal (`int*`) como un array constante (`const int*`), y la función del tercer parámetro también podría recibir sus argumentos como referencia constante o no constante. Probablemente necesites declarar el tipo de la función como otro parámetro de la plantilla o usar punteros a función genéricos.

#### **Exercise 02: Array**
Este es el ejercicio principal del módulo. Vas a replicar el comportamiento básico de un `std::vector` o un `std::array`, creando una **plantilla de clase `Array<T>`**.
*   **Constructor por defecto:** `Array()` debe crear un array vacío.
*   **Constructor con tamaño:** `Array(unsigned int n)` debe crear un array de `n` elementos de tipo `T`. Un detalle muy importante que menciona el tip (`int * a = new int();`) es que los elementos deben estar **inicializados por defecto**. No basta con asignar memoria, tienes que asegurarte de que si es un tipo primitivo (como `int`), se inicialice a `0`.
*   **Regla de la Forma Canónica (Copia y Asignación):** Es vital que cuando hagas `Array<int> a = b;` o `a(b)`, se realice una **copia profunda** (deep copy). Si modificas `a[0]`, `b[0]` NO debe verse afectado. Esto significa que debes reservar nueva memoria con `new[]` y copiar los elementos uno a uno.
*   **Gestión estricta de la memoria:** Te exigen usar `new[]`. Además, prohíben la "asignación preventiva" (preventive allocation). Esto significa que si el usuario pide un array de tamaño 5, debes hacer un `new T[5]`, no un `new T[10]` por si acaso. Si el array está vacío, su tamaño es 0.
*   **Sobrecarga del operador `[ ]`:** Debes permitir acceder a los elementos usando corchetes, por ejemplo `miArray[3] = 4;`. Necesitarás dos versiones de este operador: una normal y una `const` (para arrays de solo lectura).
*   **Excepciones de fuera de límites:** Dentro de tu operador `[]`, debes comprobar si el índice solicitado es mayor o igual a `size()`. Si es así, debes lanzar (hacer `throw`) una `std::exception` (o una clase derivada tuya como `Array::OutOfBoundsException`). Nunca debes acceder a memoria no asignada.
*   **Función `size()`:** Devuelve el número de elementos. Como dice la norma que "no debe modificar la instancia actual", esta función **debe ser declarada como `const`** (`unsigned int size() const;`).

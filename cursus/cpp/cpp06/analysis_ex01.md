# Análisis del Ejercicio 01: Serialization

## 1. El Objetivo del Ejercicio
El ejercicio nos pide implementar una clase estática `Serializer` con dos métodos:
- `serialize(Data* ptr)`: Coge un puntero a un objeto `Data` y lo transforma en un número entero sin signo (`uintptr_t`).
- `deserialize(uintptr_t raw)`: Coge ese número entero y lo vuelve a transformar en un puntero a `Data`.

**¿Qué es esto realmente?**
En programación de bajo nivel, la "serialización de punteros" significa tomar una dirección de memoria (que no deja de ser un número hexadecimal, ej: `0x7fffcb8`) y tratarlo literalmente como un número entero. Esto es útil en sistemas embebidos, en algunas APIs del sistema operativo (como pasar datos a través de *callbacks* de hilos (threads) en pthreads), o al guardar direcciones en memoria compartida. 

Al final, tenemos que demostrar que si pasas un puntero a un número, y luego ese número lo pasas a puntero, **vuelves a apuntar exactamente al mismo objeto en memoria** sin haber perdido ni corrompido nada.

## 2. El Reparto (Actores Principales)

### La estructura `Data`
El subject pide que creemos una estructura `Data` que no esté vacía.
- *Decisión de diseño:* Crearemos un archivo `Data.hpp` con una estructura simple. Por ejemplo, puede contener un `int id`, un `std::string name` y un `float value` para demostrar que tras deserializar, podemos acceder a todos sus miembros sin problema.

### La clase `Serializer`
Igual que en el `ex00`:
- **No instanciable:** Constructores y destructor deben ser privados.
- **Métodos estáticos:** Solo contendrá `serialize` y `deserialize`.

### El tipo `uintptr_t`
Este es el tipo clave del ejercicio. Se encuentra en la librería `<stdint.h>`. Es un tipo de entero sin signo (`unsigned int` / `unsigned long`) que **el estándar garantiza que es lo suficientemente grande como para almacenar un puntero completo** sin perder datos, independientemente de si estás compilando en 32 bits (donde un puntero ocupa 4 bytes) o en 64 bits (donde ocupa 8 bytes). 

## 3. El Casting: ¿Cuál usamos?
Como vimos en el ex00, no podemos usar casts al estilo C. Tenemos 4 opciones en C++:
1. `static_cast`: **Prohibido.** No permite convertir entre tipos no relacionados, como un puntero y un número entero.
2. `dynamic_cast`: **Prohibido.** Es para herencia de clases (polimorfismo).
3. `const_cast`: **Prohibido.** Solo quita o pone `const`.
4. **`reinterpret_cast`:** **¡LA OPCIÓN CORRECTA!**

`reinterpret_cast` le dice al compilador: *"Coge la representación binaria en memoria (los ceros y unos) de la variable A y trátalos exactamente como si fueran la variable B"*. Es el cast más peligroso, pero es exactamente el que necesitamos para tratar una dirección de memoria como un entero y viceversa.

## 4. Posibles Edge Cases (Casos límite)

Antes de programar, tenemos que tener en cuenta qué cosas pueden salir mal para cubrirlas:

1. **Punteros Nulos (`NULL`):**
   - ¿Qué pasa si le pasamos `NULL` a `serialize`? `reinterpret_cast` convertirá un `NULL` a un `uintptr_t` con valor `0`.
   - Al deserializar un `0`, nos devolverá un puntero `NULL`. 
   - *Prevención:* Nuestro `main.cpp` deberá incluir una prueba pasando `NULL` y demostrando que no crashea, sino que serializa un `0` y devuelve un `NULL`.

2. **Diferencias de Arquitectura (Pérdida de datos):**
   - Si en vez de `uintptr_t` usáramos un `unsigned int` normal en una máquina de 64 bits, recortaríamos la dirección de memoria por la mitad (de 8 bytes a 4 bytes). Al deserializar, el puntero apuntaría a un sitio totalmente distinto, provocando un *Segfault*.
   - *Prevención:* El uso de `uintptr_t` (exigido por el subject) soluciona esto inherentemente, pero es el concepto exacto que debes explicarle al evaluador si te pregunta por qué no usamos un `int`.

3. **Inmutabilidad del objeto:**
   - La serialización no clona el objeto, solo su "dirección de ubicación". Si modificamos los datos usando el puntero original, el puntero deserializado reflejará esos cambios (porque apuntan a la misma casa). Esto lo demostraremos en el programa de test.

## 5. Resumen del Plan de Acción
1. Crear `Data.hpp` con la estructura.
2. Crear `Serializer.hpp` (Constructores privados).
3. Crear `Serializer.cpp` usando `reinterpret_cast<uintptr_t>` y `reinterpret_cast<Data*>`.
4. Crear `main.cpp` para hacer las pruebas:
   - Prueba con un puntero válido.
   - Prueba de modificación cruzada (cambiar el original y leer el deserializado).
   - Prueba con `NULL`.

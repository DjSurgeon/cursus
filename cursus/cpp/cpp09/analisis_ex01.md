# Análisis Exhaustivo - Ejercicio 01: Reverse Polish Notation (`RPN`)

## 🎯 1. Objetivo del Ejercicio
El objetivo de este ejercicio es crear un programa llamado `RPN` que tome como único argumento una expresión matemática escrita en **Notación Polaca Inversa** (Reverse Polish Notation) y muestre su resultado exacto por la salida estándar.

Este ejercicio está diseñado para evaluar tu comprensión sobre las estructuras de datos tipo **LIFO** (Last In, First Out) y el uso estricto del contenedor adecuado, cumpliendo la regla de oro del módulo de no repetir contenedores usados previamente (es decir, no podemos usar `std::map`).

## 🧠 2. Conceptos Teóricos Involucrados

### A. ¿Qué es la Notación Polaca Inversa (RPN)?
En la matemática tradicional usamos la notación infija (ej. `3 + 4`). En la notación postfija o polaca inversa, el operador sigue a los operandos (ej. `3 4 +`).
La ventaja principal de RPN es que **elimina por completo la necesidad de usar paréntesis** para marcar la precedencia, ya que el orden de las operaciones está dictado únicamente por la posición.

Ejemplo del subject: `"8 9 * 9 - 9 - 9 - 4 - 1 +"`
Se resuelve de izquierda a derecha operando siempre sobre los dos últimos números que hayamos leído en cuanto encontremos un operador.

### B. El Contenedor Ideal: `std::stack`
Para procesar RPN, la estructura de datos natural y canónica en ciencias de la computación es una pila (**Stack / LIFO**). 
En C++, usamos `std::stack<int>`. 

**Algoritmo estándar de RPN con Stack:**
1. Leemos la expresión token a token (separada por espacios).
2. Si el token es un **número**, lo apilamos (`stack.push(num)`).
3. Si el token es un **operador** (`+`, `-`, `*`, `/`):
   - Extraemos los dos números superiores de la pila.
   - ¡Cuidado con el orden! El primer número que sacas (top) es el operando derecho de la operación, y el segundo que sacas es el operando izquierdo.
   - Aplicamos la operación.
   - Apilamos el resultado devuelto.
4. Al terminar de procesar toda la cadena, el único número que debe quedar en la pila es el resultado final.

```cpp
// Snippet conceptual
std::stack<int> s;

// Asumiendo que encontramos un operador '-'
if (s.size() < 2) throw std::runtime_error("Error de sintaxis RPN");
int right = s.top(); s.pop();
int left = s.top(); s.pop();

s.push(left - right); // Importante: left - right, no right - left
```

### C. Restricciones del Subject y Casos Especiales
- **Números de un solo dígito**: El subject afirma que los números pasados como argumentos siempre serán menores que 10 (es decir, de un dígito, 0-9). *Sin embargo*, los resultados intermedios y el cálculo en sí pueden superar ampliamente el 10, por lo que usaremos enteros normales (`int`).
- **Solo operadores básicos**: Solo debemos manejar `+`, `-`, `/`, `*`.
- **Manejo de Errores**: Si la expresión está mal formada (ej. `1 + 1` o te sobran operadores/números al final) o si hay división por cero, el programa debe mostrar `Error`.

## 🔍 3. Ayudas y Búsquedas por Internet
- **"RPN evaluator algorithm C++"**: Para entender cómo funciona el bucle de parsing.
- **"C++ stringstream extraction"**: Dado que la cadena viene separada por espacios, `std::stringstream` es la herramienta perfecta para extraer token a token de forma limpia.
- **"C++ check if string is only one digit"**: Para la validación estricta de que los números de entrada son menores de 10 como estipula el subject.

## 📂 4. Estructura de Archivos y Paso a Paso

### 1. `RPN.hpp` y `RPN.cpp`
Como siempre, usaremos la *Forma Canónica Ortodoxa*.
- **Atributos:** Un `std::stack<int> _stack;` privado.
- **Métodos Públicos:** `void calculate(const std::string& expression);` (o devolver un `int`).
- **Helpers Privados:** 
  - Validaciones para saber si un token es operador: `bool _isOperator(const std::string& token)`.
  - Método para operar: `void _executeOperation(const std::string& op)`.

### 2. `main.cpp`
Comprobar `argc == 2`, atrapar excepciones, llamar al método `calculate` de la clase `RPN` e imprimir el resultado.

### 3. `Makefile`
Idéntico al del `ex00`, cambiando el nombre del binario a `RPN`.

---

## 🚦 Conclusión y Consejos para la Defensa
Durante la evaluación, probarán todos los modos posibles de colgar tu programa:
1. **Pila vacía / Sintaxis inválida:** Ej. `"1 +"` (intenta sacar dos números pero solo hay uno). O `"1 2 3 +"` (al final quedan 2 números en la pila en vez de 1).
2. **División por cero:** Ej. `"8 0 /"`. Esto en C++ crashea el programa con un `Floating point exception` o similar. **Debes validar manualmente** si el divisor es 0 antes de operar y lanzar tu error controlado.
3. **Números >= 10 en el input:** Si te pasan `"10 2 *"`, según el subject, los números de entrada deben ser < 10, así que debería dar error.
4. **Espacios extra:** `"1   2 *"` (El uso de `std::stringstream` te solucionará automáticamente los problemas de múltiples espacios).

Si tienes claro que `std::stack` es la herramienta, el código de este ejercicio no superará las 80 líneas y es muy divertido de programar.

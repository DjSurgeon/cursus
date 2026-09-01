# Análisis Exhaustivo - Ejercicio 00: Bitcoin Exchange (`btc`)

## 🎯 1. Objetivo del Ejercicio
El objetivo principal es procesar un archivo de base de datos en formato CSV (`data.csv`) que contiene el histórico de precios de Bitcoin a lo largo del tiempo. A continuación, el programa debe recibir por argumento un segundo archivo (input) con fechas y cantidades de Bitcoin, y debe calcular el valor de esas cantidades basándose en el precio que tenía el Bitcoin en esa fecha exacta (o en la fecha anterior más cercana registrada en la base de datos).

Este ejercicio pone a prueba de forma intensiva el **manejo de archivos**, el **parsing y validación de strings**, y sobre todo el uso de **contenedores asociativos ordenados** (como `std::map`).

## 🧠 2. Conceptos Teóricos Involucrados

### A. Lectura de Archivos y Diferencia de Formatos (`std::ifstream`)
Dado que tenemos que leer tanto la base de datos CSV como el archivo de entrada, necesitaremos usar flujos de lectura de archivos y prestar **mucha atención a los formatos**:
1. **La Base de Datos (CSV)**: Al arrancar el programa, leeremos `data.csv`. El formato estricto de este archivo es `fecha,valor` (separado por una **coma**). Guardaremos estos datos en memoria.
2. **El Input (TXT)**: El programa recibe por argumento un archivo de texto con las consultas del usuario. El formato de este archivo es `fecha | valor` (separado por **pipe** y espacios ` | `).

Es vital separar (split) la línea usando los delimitadores correspondientes para cada caso. Al leer el TXT, tomaremos el valor, buscaremos el precio del Bitcoin en esa fecha exacta (o en la anterior más cercana, usando `lower_bound`) en nuestra BBDD en memoria, multiplicaremos ambos valores e imprimiremos el resultado (ej. `2011-01-03 => 3 = 0.9`).

### B. Contenedor Asociativo Ordenado (`std::map`)
La regla de oro de este módulo dicta que debemos elegir el contenedor perfecto. `std::map` almacena elementos formados por una combinación de un valor clave (`key`) y un valor mapeado (`mapped value`), ordenados por la clave.
- **Clave (`std::string`)**: La fecha en formato "YYYY-MM-DD". Su ordenación alfabética/lexicográfica funciona perfectamente para la cronología (ej. "2011-01-03" < "2012-01-11").
- **Valor (`float` o `double`)**: El precio del Bitcoin.

```cpp
std::map<std::string, float> _database;
```

### C. Búsqueda Binaria de la "Fecha Anterior Más Cercana" (`lower_bound`)
El subject pide: *"Si la fecha usada en el input no existe en tu base de datos, debes usar la fecha más cercana contenida en tu base de datos. Ten cuidado de usar la fecha inferior y no la superior."*

`std::map::lower_bound(key)` devuelve un iterador al primer elemento cuya clave *no es estrictamente menor* que `key` (es decir, es `>= key`).
Para encontrar la "fecha inferior más cercana":
1. Hacemos `it = map.lower_bound(date)`.
2. Si `it` apunta a la fecha exacta que buscamos, perfecto.
3. Si no es la fecha exacta, significa que `it` apunta a la primera fecha **mayor**. Para obtener la fecha inmediatamente **menor**, simplemente retrocedemos el iterador (`--it`).
4. **Edge case**: Si `it` es `map.begin()`, significa que la fecha buscada es anterior a cualquier registro en nuestra base de datos (error lógico/falta de datos).

```cpp
std::map<std::string, float>::const_iterator it = _database.lower_bound(target_date);

if (it == _database.end() || it->first != target_date) {
    if (it == _database.begin()) {
        throw std::runtime_error("Fecha anterior al primer registro de la BBDD");
    }
    --it;
}
// it->second contiene el precio correcto.
```

### D. Validación de Datos (Parsing)
La mayor parte del código en este ejercicio será para validar el formato de la entrada:
- **Fechas:** Formato `YYYY-MM-DD`. Debes asegurar que el año, el mes (1-12) y los días (1-31, considerando bisiestos y días por mes) son válidos lógicamente.
- **Valores:** En el input, debe ser un `float` o número positivo, entre 0 y 1000. Debes capturar errores como "not a positive number" o "too large a number".
- Utiliza `std::stringstream` o funciones como `strtod`/`strtof` junto con el manejo del puntero extra para detectar basura (`"1.2abc"`).

## 🔍 3. Ayudas y Búsquedas por Internet
- **"C++ check if string is a valid date" o "C++ leap year calculation"**: Para el algoritmo de validación de bisiestos y el límite de días según el mes (Febrero tiene 28 o 29, Abril 30, etc).
- **"std::map lower_bound explained c++"**: Entender visualmente cómo `lower_bound` navega el árbol (Red-Black Tree interno del std::map).
- **"C++ string split without boost"**: Ya que Boost está prohibido, repasar cómo usar `std::string::find` o `std::stringstream` con un delimitador para extraer fecha y valor.

## 📂 4. Estructura de Archivos y Paso a Paso

### 1. `BitcoinExchange.hpp` y `BitcoinExchange.cpp`
Esta clase debe encapsular toda la lógica de negocio. Debe cumplir la *Forma Ortodoxa Canónica*.
- **Atributos:** Un `std::map<std::string, float> _database;`.
- **Métodos Privados:** `loadDatabase(const std::string& dbPath)` para inicializar el mapa con `data.csv`. Y métodos booleanos de validación como `isValidDate(const std::string& date)`, `isValidValue(const std::string& value)`.
- **Métodos Públicos:** Constructor que tome el path a la DB, y una función `void processInput(const std::string& inputPath)` que lea línea a línea el input.txt, valide la línea, y si es correcta, busque el ratio en el `_database`, calcule el resultado e imprima en consola.

### 2. `main.cpp`
Extremadamente sencillo. Su única responsabilidad es comprobar los argumentos de la línea de comandos, instanciar la clase `BitcoinExchange` (atrapando cualquier posible excepción al cargar la BBDD) y decirle que procese el archivo.
```cpp
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc("data.csv");
        btc.processInput(argv[1]);
    } catch (std::exception &e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }
    return 0;
}
```

### 3. `Makefile`
Con las flags de siempre (`-Wall -Wextra -Werror -std=c++98`).

---

## 🚦 Conclusión y Consejos para la Defensa
En la defensa, el evaluador pondrá a prueba tu parsing pasándote archivos malignos:
- Fechas inexistentes (`2001-42-42`, `2021-02-29` en año no bisiesto).
- Números negativos o por encima de 1000 en el input.
- Cabeceras erróneas en el archivo (la primera línea debe ser `date | value`).
- Espacios raros en las líneas.

Lo más importante que te preguntarán es **por qué elegiste tu contenedor**. La respuesta ganadora es: "Elegí `std::map` porque asocia intrínsecamente pares clave-valor (fecha-precio), mantiene las claves ordenadas (lo cual es vital para buscar cronológicamente) y provee métodos de búsqueda algorítmica de complejidad $O(\log n)$ como `lower_bound`, lo cual hace que buscar la fecha anterior más cercana sea trivial y muy eficiente comparado con recorrer un `std::vector` linealmente".

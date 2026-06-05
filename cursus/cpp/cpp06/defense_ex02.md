# Guía de Defensa para ex02 (Identify Real Type)

## 🦆 Explicación "Patito de Goma" (Rubber Duck)

Imagina que tienes tres tipos de regalos diferentes: una caja de bombones (`A`), un libro (`B`) y un videojuego (`C`). 

Tú (la función `generate`) coges uno de estos regalos al azar, pero para que nadie sepa qué es, lo envuelves en un papel de regalo genérico y aburrido llamado `Base`. A partir de este momento, desde fuera, el paquete solo se ve como un "paquete Base".

Ahora le entregas este paquete genérico a tu amigo (la función `identify`) y le dices: *"Adivina qué hay dentro sin quitar el papel de regalo" (es decir, sin usar `std::typeinfo`)*.

¿Cómo lo adivina tu amigo? Probando llaves:
1. **La versión con Punteros:** Tu amigo intenta encajar el regalo en el hueco del estante de bombones (`dynamic_cast<A*>(p)`). Si el regalo **no entra** porque en realidad era un libro, la operación da como resultado un espacio vacío (`NULL`). Como vio que daba `NULL`, sabe que no era la caja `A`, así que prueba con el hueco `B`. ¡Si entra, bingo! Era `B`.
2. **La versión con Referencias:** Aquí la cosa se pone tensa. Tu amigo intenta meter el regalo a la fuerza en el hueco de bombones. Pero como en C++ **no existen las referencias vacías/nulas**, si no encaja, el estante estalla en pedazos y le grita en la cara (lanza una **excepción** `std::bad_cast`). Sabiendo que esto va a pasar, tu amigo se pone unos tapones en los oídos (`try...catch`) y dice: *"Vale, ha explotado, pruebo el siguiente"*, hasta que uno no explota.

---

## 🎯 Preguntas Difíciles para la Defensa (Evaluación)

Si quieres sacar un 100/100, tienes que saber responder a estas preguntas que los evaluadores usarán para comprobar si realmente entiendes lo que has escrito.

### 1. ¿Por qué la clase `Base` TIENE que tener un destructor `virtual`? ¿Qué pasa si se lo quitas?
**Respuesta ideal:**
Si se lo quito, el compilador me dará un error y el `dynamic_cast` se negará a funcionar. `dynamic_cast` solo puede utilizarse en clases **polimórficas** (clases que tienen al menos una función `virtual`). Al añadir un destructor virtual, el compilador se ve obligado a crear una cosa llamada **Vtable** (Tabla Virtual) para esa clase. Esa Vtable guarda el RTTI (Run-Time Type Information), que es básicamente la etiqueta secreta de la que lee `dynamic_cast` para saber qué hay realmente dentro del puntero en tiempo de ejecución. Sin virtual, no hay Vtable; sin Vtable, el compilador dice: *"Esto es solo un Base tonto, no puedo adivinar nada más"*.

### 2. ¿Cuál es exactamente la diferencia entre cómo falla el casteo de un puntero y el de una referencia?
**Respuesta ideal:**
- Cuando fallas casteando un **puntero** (`Base*` a `A*`), el resultado es amigable: simplemente te devuelve la dirección `NULL` (valor `0`). El programa sigue fluyendo y tú lo chequeas con un `if`.
- Cuando fallas casteando una **referencia** (`Base&` a `A&`), es un error fatal. C++ tiene como regla de oro que *no puede existir una referencia a la nada*. Como no puede devolver un "NULL de referencia", su única salida es parar el mundo y arrojar una excepción, concretamente `std::bad_cast`. Por eso nos obliga a usar bloques `try...catch`.

### 3. ¿Por qué no usamos `static_cast` aquí como en el ejercicio 00?
**Respuesta ideal:**
Porque `static_cast` se resuelve en tiempo de **compilación**. Es decir, se fía ciegamente de ti. Si le dices "toma este puntero `Base` (que en realidad oculta un `B`) y conviértelo a `A`", el `static_cast` dirá: *"Vale, jefe"*. No comprobará nada, no dará error, y te devolverá un puntero de tipo `A`. Pero cuando intentes usarlo en el código, el programa crasheará estrepitosamente porque estás intentando leer el índice de un libro como si fueran las calorías de un bombón. 
`dynamic_cast` se ejecuta en tiempo de **ejecución**, garantizando que si te equivocas, te protege devolviendo `NULL` o lanzando una excepción.

### 4. ¿Qué significa RTTI?
**Respuesta ideal:**
Son las siglas de **Run-Time Type Information** (Información de Tipos en Tiempo de Ejecución). Es un mecanismo oculto de C++ que expone información sobre el tipo dinámico (real) de un objeto mientras el programa ya se está ejecutando. `dynamic_cast` y `typeid` (que nos han prohibido usar) son las herramientas de C++ para leer este RTTI.

### 5. ¿Habría Memory Leaks si no hiciéramos `delete obj` en el `main`?
**Respuesta ideal:**
Por supuesto. La función `generate()` usa `new A()`, `new B()` o `new C()`. Esos objetos se alojan en el montón (Heap). Si nosotros recogemos ese puntero genérico en el `main`, adivinamos su tipo y luego nos olvidamos de él sin llamar a `delete`, la memoria se quedará bloqueada para siempre, suspendiendo el proyecto automáticamente por leaks. Por eso el destructor virtual en `Base` es una doble victoria: nos da polimorfismo, y a la vez asegura que cuando hagamos `delete obj;`, se llame correctamente al destructor de la clase hija antes de borrarlo.

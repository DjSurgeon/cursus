# Documentación del Sistema de Variables de Entorno - Minishell

## Visión General del Problema y Solución

El desarrollo de un shell requiere un manejo sofisticado del entorno de ejecución que hereda del proceso padre. Cuando tu minishell se ejecuta, recibe a través del parámetro `envp` un array de strings que contiene todas las variables de entorno del sistema. Cada string sigue el formato "NOMBRE=valor", donde variables como "PATH=/usr/bin:/bin" definen aspectos cruciales del comportamiento del sistema.

El desafío fundamental radica en que este array `envp` es de solo lectura y tiene limitaciones para las operaciones dinámicas que un shell debe realizar. Un shell moderno necesita capacidades como añadir nuevas variables con el comando `export`, eliminar variables existentes con `unset`, modificar valores de variables, y pasar un entorno actualizado a programas hijos mediante `execve`. Estas operaciones requieren una estructura de datos que sea tanto flexible como eficiente.

## Arquitectura de la Estructura de Datos

Hemos diseñado una solución basada en listas enlazadas que proporciona la flexibilidad necesaria para todas las operaciones de manipulación del entorno. La estructura elegida es una lista enlazada simple donde cada nodo representa una variable de entorno completa. Esta aproximación ofrece ventajas significativas sobre arrays estáticos: permite inserción y eliminación de variables en tiempo constante, se adapta dinámicamente al número de variables sin desperdiciar memoria, y facilita operaciones de búsqueda y modificación.

La estructura de cada nodo ha sido diseñada con tres campos estratégicos. El campo `key` almacena el nombre de la variable como un string independiente, facilitando operaciones de búsqueda y comparación. El campo `value` contiene el valor asociado a esa variable, también como un string separado que puede modificarse independientemente. El campo `full_env` representa una optimización importante: almacena la variable completa en formato "NOMBRE=valor", eliminando la necesidad de construir este formato repetidamente para operaciones como `execve`.

## Gestión de Memoria: Copias Profundas y Ownership

La decisión más crítica en nuestro diseño ha sido implementar un sistema de copias profundas para todos los datos del entorno. Cuando procesamos cada variable del array `envp` original, no almacenamos referencias a esa memoria original, sino que creamos copias completamente independientes. Esta aproximación tiene implicaciones profundas para la robustez y mantenibilidad del sistema.

El proceso de copia comienza con el parsing de cada string del array `envp`. Utilizamos `ft_strchr()` para localizar el primer carácter '=' que separa el nombre del valor. Una vez identificadas las posiciones, empleamos memoria dinámica para crear strings independientes tanto para la clave como para el valor. Este proceso utiliza `malloc()` para alojar exactamente la cantidad de memoria necesaria, evitando el desperdicio asociado con arrays de tamaño fijo.

La función `ft_lstnew_mini()` implementa el principio de ownership completo, donde cada nodo toma responsabilidad total sobre sus datos. En lugar de simplemente almacenar punteros a memoria externa, la función crea copias internas usando `ft_strdup()` o equivalentes. Esto significa que una vez creado el nodo, es completamente autónomo y no depende de la validez de ninguna memoria externa.

## Estrategia de Triple Almacenamiento

La inclusión del campo `full_env` representa una decisión de diseño que prioriza el rendimiento operacional sobre la eficiencia de memoria pura. Al almacenar tanto los componentes separados como la variable completa, estamos invirtiendo memoria adicional para ganar eficiencia en operaciones frecuentes. Esta estrategia es particularmente valiosa para la función de conversión que necesitará generar arrays de environment para `execve`.

Cuando necesitemos pasar el entorno a un programa hijo, simplemente copiaremos punteros al campo `full_env` de cada nodo, eliminando completamente la necesidad de construcción dinámica de strings. Esta optimización convierte una operación potencialmente costosa en términos de CPU y memoria temporal en una simple copia de punteros.

## Flujo de Inicialización y Parsing

El proceso de inicialización sigue un patrón cuidadosamente estructurado que garantiza la integridad de los datos en cada paso. Comenzamos recorriendo el array `envp` elemento por elemento, verificando que cada string contiene el carácter '=' que indica una variable válida. Para cada variable válida, ejecutamos el proceso de parsing que separa nombre y valor, creamos las copias necesarias en memoria dinámica, y finalmente construimos el nodo de la lista enlazada.

La gestión de memoria durante este proceso requiere atención particular al ciclo de vida de los datos temporales. Las funciones `set_key()` y `set_value()` crean copias temporales que utilizamos para inicializar el nodo. Una vez que `ft_lstnew_mini()` ha creado sus propias copias internas, estas copias temporales deben liberarse inmediatamente para evitar memory leaks. Este patrón de "crear, usar, transferir ownership, limpiar" es fundamental para mantener un uso eficiente de la memoria.

## Consideraciones de Memoria y Escalabilidad

El sistema diseñado maneja la memoria de forma precisa y eficiente dentro del contexto de las necesidades reales de un shell. Aunque almacenamos cada variable en tres formatos diferentes, el overhead de memoria es acceptable considerando que los entornos típicos contienen entre 50 y 200 variables, con nombres y valores relativamente cortos. El beneficio operacional de tener datos preformateados supera ampliamente el costo adicional de memoria.

La escalabilidad del sistema se basa en el principio de que la memoria se aloja exactamente según las necesidades. No hay arrays de tamaño fijo que desperdicien espacio, ni limitaciones artificiales en el tamaño de nombres o valores de variables. El sistema puede manejar desde entornos minimalistas con pocas variables hasta entornos complejos con cientos de variables sin cambios en la arquitectura.

## Preparación para Operaciones Futuras

Esta arquitectura establece las bases sólidas para todas las operaciones avanzadas que implementaremos posteriormente. El comando `export` podrá buscar variables existentes, modificar sus valores actualizando tanto `value` como `full_env`, o crear nuevos nodos para variables completamente nuevas. El comando `unset` podrá eliminar nodos completos de la lista, liberando automáticamente toda la memoria asociada gracias al encapsulamiento de ownership.

La expansión de variables para la interpretación de comandos será eficiente porque podremos buscar variables por nombre en la lista enlazada y acceder directamente a sus valores. La conversión para `execve` será trivial porque cada nodo ya mantiene su representación completa en el formato requerido por el sistema operativo.

El diseño también facilita funciones de debugging y diagnóstico, ya que toda la información sobre cada variable está encapsulada en estructuras bien definidas que pueden inspeccionarse fácilmente durante el desarrollo y la resolución de problemas.

Esta fundación robusta nos permite enfocarnos en la lógica de alto nivel de las operaciones del shell, confiando en que la gestión de memoria y la integridad de los datos están garantizadas por la arquitectura que hemos establecido.
# Resumen de los principales cambios en esta rama

## 1. Nueva función `pipes()`

- **Propósito:**  
  Añade soporte para ejecutar múltiples comandos conectados mediante pipes.
- **Funcionamiento:**  
  La función `pipes()` recibe como argumentos:
  - Un array de comandos (ya separados por el símbolo `|`)
  - El número de bloques de comandos
  - Los file descriptors de entrada y salida
  - La lista de entorno
- **Detalles:**  
  Gestiona la creación de pipes, el fork de procesos hijos y la correcta redirección de entrada/salida para cada comando de la cadena.  
  Se han dejado comentarios en bruto en el código para facilitar la comprensión, pero se pueden eliminar.

## 2. Renombrado de funciones de inicialización de la lista de entorno

- **Qué ha cambiado:**  
  Las funciones antes llamadas `get_key` y `get_fullenv` ahora se llaman `set_key` y `set_fullenv`.
- **Motivo:**  
  Así se evita confusión, dejando claro que estas funciones se encargan de establecer (y no solo obtener) los valores al inicializar la lista de entorno.

## 3. Nuevas funciones para buscar nodos por clave

- **Nuevas funciones:**  
  - `get_value_by_key`
  - `get_full_env`
- **Propósito:**  
  Permiten recuperar el valor o el string completo de una variable de entorno a partir de su clave, facilitando el acceso programático a las variables.

## 4. Mejora en la gestión de memoria de `envlist_to_arr()`

- **Qué ha cambiado:**  
  Al convertir la lista enlazada de entorno en un array (para usar con `execve()`), ahora cada string se duplica usando `ft_strdup()`.
- **Por qué:**  
  Así el array resultante es independiente de la lista original, evitando problemas si la lista se modifica durante la sesión.  
  El array se libera correctamente tras la ejecución del comando, incluso si `execve()` falla.

## 5. Limpieza de código y documentación

- **Comentarios:**  
  - Se han sustituido la mayoría de los comentarios en línea por documentación estilo Doxygen para mayor claridad y mantenibilidad.
  - Se han dejado comentarios detallados en bruto en la función `pipes()` para facilitar su comprensión; se podrán limpiar más adelante.

---

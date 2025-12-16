# environment.c

Incorrecto: perror() imprime errores del sistema (cuando errno está configurado), pero tu función get_environment() falla por malloc(), no por errores del sistema.

```bash
bash: cannot allocate memory for environment
exit 2  # O exit 1
```
posible solucion:

```c
if (!get_environment(envp, &environment))
{
    write(STDERR_FILENO, "minishell: failed to initialize environment\n", 43);
    return (free_environment(&environment), 1);
}
```
¿Qué pasa si envp está vacío—es true correcto? ¿Deberías verificar si se añadió al menos un nodo?

Si falla a mitad de recorrido, no se libera la parte de la lista ya creada → habría que limpiar antes de devolver false.

set_key y set_value deben manejar bien casos como "VAR=" (valor vacío) o "=valor" (clave vacía, que probablemente deberías ignorar).
"KEY="           // Valor vacío - ¿válido?
"=VALUE"         // Key vacía - ¿válido?  
"KEY=VALUE=MORE" // Múltiples = - ¿cómo lo manejas?

ft_lstnew_mini_env debe hacer copias internas para que liberar key y value aquí no rompa nada.

Si en el futuro quieres añadir variables propias (SHLVL, _), este es el sitio.

# set_key y set_value

Si se usa set key fuera del contexto de get environmet podria tener segfaults

```c
while (str[i] != '=')  // ¿Qué pasa si NO hay '='?
    i++;               // Loop infinito hasta segfault!
```
Decidir política para claves vacías o valores vacíos.

# environment utils

En las copias profundas su falla un strdup que hacemos?

```c
new_node->key = ft_strdup(key);        // ¿Qué si falla?
new_node->value = ft_strdup(value);    // ¿Qué si falla?
new_node->full_env = ft_strdup(full);  // ¿Qué si falla?
```

No se verifica si ft_strdup falla. Si cualquiera de estas llamadas devuelve NULL, entonces:

    El nodo tendrá un puntero NULL para ese campo

    Se producirá un memory leak porque el nodo ya está allocado pero no se libera

    Si luego intentas acceder a estos campos NULL, causará segmentation fault

Para solucionar hay que comprobar cada nodo, y si uno falla liberar el anterior en orden.

# Casos de prueba recomendados

    "PATH=/usr/bin" → clave y valor normales.

    "VAR=" → valor vacío.

    "=value" → clave vacía (decidir si lo aceptas).

    Entrada sin '=' → ignorada por get_environment.

    Fallo de malloc → simular y verificar que no hay fugas.


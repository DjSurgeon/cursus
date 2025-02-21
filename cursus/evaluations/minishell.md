## Primera batería: Enfoque general

Estas preguntas te ayudarán a entender cómo encararon el proyecto y qué decisiones tomaron:

- ¿Cómo estructuraron el proyecto? ¿Dividieron el trabajo en módulos o lo hicieron todo en un solo archivo?
- ¿Cuáles fueron los principales retos al inicio del proyecto? ¿Por dónde empezaron y por qué?
- ¿Cómo manejaron la gestión de memoria? ¿Tuvieron problemas con leaks? ¿Cómo los resolvieron?
- ¿Qué técnicas usaron para depurar errores en el código? ¿Usaron herramientas como `valgrind` o `gdb`?
- ¿Cómo probaron su minishell? ¿Desarrollaron tests específicos? ¿Cómo verificaron que se comporta igual que `bash` en ciertos casos?
- ¿Cómo organizaron el código para cumplir con la norma? ¿Tuvieron que hacer refactorizaciones importantes?
- Si volvieran a empezar, ¿qué harían diferente? ¿Qué partes fueron las más complicadas y qué podrían haber optimizado?

## Segunda batería: Preguntas concretas para la corrección

Aquí te enfocas en aspectos técnicos específicos para identificar errores o mejoras:

- ¿El minishell maneja correctamente el historial de comandos? ¿Cómo lo implementaron?
- ¿Funciona la ejecución de comandos con rutas absolutas y relativas?
- ¿Las redirecciones (`<`, `>`, `<<`, `>>`) funcionan correctamente en todos los casos? ¿Probaron casos límite como archivos protegidos o inexistentes?
- ¿Los pipes (`|`) funcionan bien con múltiples comandos encadenados?
- ¿Las variables de entorno (`$VAR`) se expanden correctamente? ¿Qué pasa con `"$VAR"` y `'$VAR'`?
- ¿Cómo manejaron las señales (`ctrl-C`, `ctrl-D`, `ctrl-\`)? ¿Se comportan exactamente como en `bash`?
- ¿Implementaron correctamente los built-ins (`cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`)?
- ¿Gestionaron correctamente `$?` para devolver el estado del último comando?
- ¿Tuvieron en cuenta la limitación de variables globales? ¿Cómo lo resolvieron?
- ¿Existen casos en los que el minishell crashea o tiene un comportamiento inesperado?

┌──────────────────────────────────────────────┐
│                INICIO (main)                 │
└──────────────────────────────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │ Copiar envp a lista   │
      │ get_environment()     │
      └───────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │ Mostrar prompt         │
      │ input = readline()     │
      └───────────────────────┘
                │
        ┌───────┴────────┐
        │ ¿EOF / Ctrl+D? │───Sí──▶ Imprimir "exit" y salir
        └───────┬────────┘
                │ No
                ▼
      ┌───────────────────────┐
      │ ¿Línea vacía?         │───Sí──▶ Volver a prompt
      └───────────────────────┘
                │ No
                ▼
      ┌───────────────────────┐
      │ add_history(input)    │
      └───────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │        LEXER           │
      │ - Tokenizar por espacios
      │ - Detectar operadores
      │ - Crear lista t_token
      └───────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │        PARSER          │
      │ - Validar sintaxis
      │ - Agrupar tokens en
      │   comandos y args
      │ - Detectar redirecciones
      │ - Detectar pipes
      │ - Construir estructura
      │   de ejecución (AST o lista)
      └───────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │   EXPANSIONES          │
      │ - Variables $VAR
      │ - $? y $$
      │ - Expansión en comillas
      └───────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │   EJECUTOR             │
      │ - Si hay pipes: crear
      │   procesos y conectar FDs
      │ - Si hay redirecciones:
      │   abrir ficheros y redirigir
      │ - Ejecutar builtins o execve
      └───────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │ Liberar memoria usada │
      │ (tokens, AST, etc.)   │
      └───────────────────────┘
                │
                ▼
      ┌───────────────────────┐
      │ Volver a prompt       │
      └───────────────────────┘

Fase 1 – Lexer básico

    Solo separar por espacios y operadores (|, <, >, >>, <<).

    Crear lista enlazada t_token.

Fase 2 – Parser inicial

    Validar sintaxis mínima (no empezar con |, no operadores sin argumento).

    Agrupar tokens en comandos simples.

Fase 3 – Expansiones

    Sustituir $VAR por su valor.

    Manejar comillas simples/dobles.

Fase 4 – Ejecutor simple

    Sin pipes ni redirecciones, solo ejecutar comandos con execve.

Fase 5 – Redirecciones

    Abrir ficheros y redirigir stdin/stdout.

Fase 6 – Pipes

    Crear procesos conectados por pipe().
## **Índice**

  - [Fase 1: Configuración inicial del repositorio](https://www.google.com/search?q=%23fase-1-configuracion-inicial-del-repositorio)
  - [Fase 2: Estrategia de ramas (Gitflow)](https://www.google.com/search?q=%23fase-2-estrategia-de-ramas-gitflow)
      - [Rama `main`](https://www.google.com/search?q=%23rama-main)
      - [Rama `develop`](https://www.google.com/search?q=%23rama-develop)
      - [Protección de ramas](https://www.google.com/search?q=%23proteccion-de-ramas)
      - [Ramas auxiliares](https://www.google.com/search?q=%23ramas-auxiliares)
  - [Fase 3: Workflow diario de desarrollo](https://www.google.com/search?q=%23fase-3-workflow-diario-de-desarrollo)
      - [3.1 Clonación y setup inicial del colaborador](https://www.google.com/search?q=%2331-clonacion-y-setup-inicial-del-colaborador)
      - [3.2 Creación de una nueva `feature`](https://www.google.com/search?q=%2332-creacion-de-una-nueva-feature)
      - [3.3 Buenas prácticas de commit y ramas](https://www.google.com/search?q=%2333-buenas-practicas-de-commit-y-ramas)
  - [Fase 4: Integración y merges](https://www.google.com/search?q=%23fase-4-integracion-y-merges)
      - [4.1 Preparar la `feature` para merge](https://www.google.com/search?q=%2341-preparar-la-feature-para-merge)
      - [4.2 Pull Request y Code Review](https://www.google.com/search?q=%2342-pull-request-y-code-review)
      - [4.3 Merge final a `develop`](https://www.google.com/search?q=%2343-merge-final-a-develop)
  - [Fase 5: Testing y CI/CD](https://www.google.com/search?q=%23fase-5-testing-y-cicd)
      - [Tests locales](https://www.google.com/search?q=%23tests-locales)
      - [Hooks de Git](https://www.google.com/search?q=%23hooks-de-git)
      - [Integración continua (CI)](https://www.google.com/search?q=%23integracion-continua-ci)
  - [Fase 6: Resolución de conflictos](https://www.google.com/search?q=%23fase-6-resolucion-de-conflictos)
      - [Conflictos en `rebase`](https://www.google.com/search?q=%23conflictos-en-rebase)
      - [Conflictos en `merge`](https://www.google.com/search?q=%23conflictos-en-merge)
      - [Herramientas](https://www.google.com/search?q=%23herramientas)
  - [Fase 7: Monitoreo y métricas](https://www.google.com/search?q=%23fase-7-monitoreo-y-metricas)
  - [Fase 8: Workflow específico para Minishell](https://www.google.com/search?q=%23fase-8-workflow-especifico-para-minishell)
  - [Comandos útiles de emergencia](https://www.google.com/search?q=%23comandos-utiles-de-emergencia)

-----

## **Fase 1: Configuración inicial del repositorio**

Uno de los dos compañeros, el "Owner", debe crear el repositorio e inicialmente configurar los ajustes principales El Owner realiza los siguientes pasos en su máquina local:

```bash
# Crear directorio del proyecto y entrar
mkdir minishell
cd minishell

# Inicializar Git
git init

# Configurar usuario (si no está en global)
git config user.name "Tu Nombre"
git config user.email "tu.email@student.42.fr"

# Crear un README inicial
echo "# Minishell Proyecto 42" > README.md

# Crear .gitignore con archivos binarios o temporales
cat > .gitignore << EOF
# Ejecutables
minishell
*.o
*.a
# Archivos temporales
*~
*.swp
.DS_Store
# Directorios de compilación
obj/
.vscode/
*.dSYM/
EOF

# Estructura de directorios inicial
mkdir -p includes srcs/{parser, executor, builtins, utils} libft

# Primer commit
git add .
git commit -m "Initial commit: estructura del proyecto y archivos base"

# Crear repositorio en GitHub/GitLab (desde web) y conectar remoto:
git remote add origin https://github.com/TU_USUARIO/minishell.git
git branch -M main
git push -u origin main
```

Con esto, se crea la rama `main` vacía con un primer *commit* inicial. A continuación, el Owner debe proteger la rama `main` para prohibir "force pushes" y exigir revisiones de *Pull Requests* (PR) antes de fusionar.

El Owner invita al otro compañero como "Collaborator" en GitHub o "Developer" o "Maintainer" en GitLab. El compañero recibirá una invitación por correo electrónico para clonar el repositorio.

-----

## **Fase 2: Estrategia de ramas (Gitflow)**

La estrategia de ramas seguirá un modelo similar a Gitflow, con ramas principales y auxiliares bien definidas. Aunque Gitflow es considerado un flujo "legado" en favor de flujos basados en `trunk` (`trunk-based`) , para este proyecto se usará `main` y `develop` para organizar las características, versiones y parches, lo que facilita lanzamientos formales.

### **Rama `main`**

Esta rama contiene el código de producción listo para desplegar. Cada *commit* en `main` suele estar marcado con una etiqueta de versión (`tag`).

### **Rama `develop`**

Esta es la rama de integración donde se fusionan las nuevas funcionalidades. Contiene los cambios inestables que se prueban para la próxima versión. El equipo trabajará en `develop` a diario. En esencia, `main` almacena la historia oficial lanzada y `develop` la historia completa en desarrollo.

### **Protección de ramas**

Es importante proteger las ramas `main` y opcionalmente `develop` con reglas que prohíban los *push* directos y exijan revisiones o pruebas. Las reglas de protección de ramas de GitHub deshabilitan los `force-pushes` y pueden requerir que las PRs pasen todas las verificaciones antes de la fusión.

  - **Configuración inicial de ramas en local por el Owner**:
    ```bash
    git checkout -b develop
    git push -u origin develop
    ```
  - **En GitHub/GitLab (web)**: se debe proteger la rama `main` y configurar reglas como "Require pull request reviews before merging" y la verificación de estados (`status checks`) 60].

### **Ramas auxiliares**

Se crearán ramas temporales para tareas específicas que se borrarán después de la fusión.

  - **Feature branches**: Se crean desde `develop` para cada nueva funcionalidad. Por convención, se nombran `feature/nombre` (ej. `feature/parser`, `feature/executor`) y se fusionan de nuevo en `develop` cuando la característica esté lista 5].
  - **Release branches**: Se crean desde `develop` cuando el proyecto está listo para una entrega. Por ejemplo, `release/v1.0`. Se corrigen errores menores y se actualiza la documentación. Una vez finalizada, se fusiona en `main` (etiquetándola con la versión) y también de vuelta en `develop` para no perder los cambios finales.
  - **Hotfix branches**: Se crean desde `main` para corregir errores críticos en producción. Una vez listo el parche, se fusiona en `main` y en `develop`, y se etiqueta la nueva versión en `main`.
    Esta estrategia mantiene el flujo de trabajo organizado: todas las ramas de funcionalidad interactúan con `develop`, y las versiones oficiales salen de `main` a través de un proceso de `release`.

-----

## **Fase 3: Workflow diario de desarrollo**

### **3.1 Clonación y setup inicial del colaborador**

El colaborador acepta la invitación y clona el repositorio remoto. Después, verifica las ramas remotas y crea su rama `develop` local para rastrear la rama remota.

```bash
git clone https://github.com/OWNER_USUARIO/minishell.git
cd minishell
# Configurar usuario Git (del colaborador)
git config user.name "Nombre Compañero"
git config user.email "compañero.email@student.42.fr"
# Ver ramas remotas
git branch -a
# Crear rama develop local rastreando origin/develop
git checkout -b develop origin/develop
```

Según la guía oficial de Gitflow, los desarrolladores deben clonar el repositorio central y crear una rama de seguimiento para `develop`.

### **3.2 Creación de una nueva `feature`**

Antes de empezar a trabajar en una nueva tarea, el colaborador debe asegurarse de que su rama `develop` esté actualizada:

```bash
git checkout develop
git pull origin develop
```

Luego, se crea una rama `feature` desde `develop` con un nombre claro, como `feature/parser`.

```bash
git checkout -b feature/parser
```

Los *commits* deben ser frecuentes, atómicos y seguir la convención **Conventional Commits**. El mensaje debe tener la forma `<tipo>(<alcance>): <descripción>`. Los tipos comunes son `feat` (nueva funcionalidad), `fix` (arreglo de bug), `refactor`, `test`, `docs`, etc.

  - **Ejemplos prácticos**:
      - `feat(parser): soporte de comillas simples y dobles`.
      - `fix(executor): corregir fuga de descriptores en pipes`.
  - Finalmente, se sube la rama regularmente al repositorio remoto para respaldo y colaboración:
    ```bash
    git push -u origin feature/parser
    ```

### **3.3 Buenas prácticas de commit y ramas**

  - **Commits descriptivos**: Cada *commit* debe centrarse en un solo objetivo. Además de la sintaxis `tipo(alcance): desc breve`, se puede incluir en el cuerpo del mensaje una lista de puntos clave si es útil.
  - **Commits frecuentes**: No se deben acumular grandes cambios sin hacer *commit*. Es mejor hacer múltiples *commits* pequeños que uno gigantesco.
  - **Sincronización**: Antes de iniciar una tarea o enviarla a revisión, se debe actualizar siempre la rama con los últimos cambios de `develop` (`pull`/`rebase`).
  - **Evitar `git push --force`**: Nunca se debe usar `git push --force` directamente en `main` o `develop`. Si se necesita reescribir el historial en una rama *feature*, es más seguro usar **`--force-with-lease`**.

-----

## **Fase 4: Integración y merges**

### **4.1 Preparar la `feature` para merge**

Antes de crear un *Pull Request*, se deben integrar los cambios recientes de `develop` en la rama de la *feature*.

```bash
git checkout develop
git pull origin develop
git checkout feature/parser
```

Se puede usar `rebase` para un historial limpio o `merge` si se prefiere no reescribir el historial.

  - **Rebase (historial limpio)**:
    ```bash
    git rebase develop
    ```
    Esto reaplica los *commits* de la *feature* encima de la punta de `develop`. Si hay conflictos, se resuelven manualmente, se añade el archivo y se continúa el `rebase`. El `rebase` mantiene una historia lineal, lo que facilita la auditoría.
  - **Merge (sin reescribir)**:
    ```bash
    git merge develop
    ```
    Se resuelven los conflictos de la misma manera.
    Después de resolver los conflictos, se debe forzar el *push* de la rama (ya que el historial ha cambiado si se hizo `rebase`). Se recomienda el uso de `--force-with-lease` para evitar sobrescribir *commits* desconocidos en el repositorio remoto.

### **4.2 Pull Request y Code Review**

Se debe crear un *Pull Request* desde la rama *feature* a la rama `develop`.

  - El título debe ser claro (ej. `feat(parser): implementar el tokenizador completo`).
  - La descripción debe explicar el propósito y los cambios importantes.
  - Es una buena práctica crear PRs pequeñas y bien documentadas, ya que son más fáciles de revisar.
  - Se puede usar un esquema en Markdown para la descripción, incluyendo la descripción, los cambios principales, las pruebas realizadas y un *checklist*.
  - Es recomendable revisar el propio PR antes de enviarlo.
  - El compañero revisor debe descargar la PR localmente, compilar y probar. Luego, revisar el código línea por línea y comentar en la PR.

### **4.3 Merge final a `develop`**

Una vez que la PR está aprobada y todas las verificaciones pasan, se puede proceder a la fusión.

```bash
git checkout develop
git pull origin develop
git merge --no-ff feature/parser -m "feat(parser): integrar tokenizador completo"
git push origin develop
```

Esto integra los cambios de la *feature* en `develop`. Luego se puede eliminar la rama de la *feature* tanto local como remotamente. El uso de `--no-ff` es opcional, pero ayuda a mantener visible el punto de integración de la PR en el registro de *commits*.

-----

## **Fase 5: Testing y CI/CD**

Para garantizar la calidad del proyecto, se deben configurar pruebas y automatizaciones.

### **Tests locales**

Se puede crear un directorio de pruebas (ej. `tests/`) con *scripts* que compilen, verifiquen el estilo (`Norminette`) y ejecuten la minishell con **Valgrind** para detectar fugas de memoria.

### **Hooks de Git**

Se pueden usar *hooks* de Git (ej. `pre-commit`) para automatizar las verificaciones antes de cada *commit*. Si una verificación falla, el *commit* es abortado, lo que asegura la calidad del código antes de enviarlo.

### **Integración continua (CI)**

Configurar un *pipeline* de CI (por ejemplo, con GitHub Actions o GitLab CI) que se active con cada *push* o PR. La CI compilará el proyecto y ejecutará las pruebas y verificaciones de estilo automáticamente. Los resultados se mostrarán en la PR, bloqueando la fusión si algo falla.

-----

## **Fase 6: Resolución de conflictos**

Cuando se trabaja en paralelo, pueden surgir conflictos al actualizar ramas.

### **Conflictos en `rebase`**

Si aparecen conflictos al `rebasear` una *feature* sobre `develop`, se deben usar los comandos:

```bash
git status # lista los archivos en conflicto
# Editar cada archivo, buscando los marcadores <<<<<<<, =======, >>>>>>>
git add <archivo_resuelto>
git rebase --continue
```

Si la situación se complica, se puede abortar el `rebase` con `git rebase --abort` y optar por un `merge` tradicional.

### **Conflictos en `merge`**

Si hay conflictos al hacer `git merge develop` o un `hotfix`, se usa `git status` para ver los archivos en conflicto, se editan, se añaden los archivos resueltos y se completa el `merge` con un *commit*.

### **Herramientas**

Se pueden usar herramientas como **`git mergetool`** para la ayuda visual en la resolución de conflictos. Es fundamental verificar que el programa compile y funcione correctamente después de resolver los conflictos. Se recomienda crear una rama de respaldo (`git branch backup-<fecha>`) antes de realizar operaciones riesgosas.

-----

## **Fase 7: Monitoreo y métricas**

Se pueden usar *scripts* simples para obtener estadísticas del proyecto, como el número de *commits* por autor, el total de líneas de código, las ramas activas y los últimos *commits*. Esto proporciona un panorama rápido para monitorear el progreso del proyecto.

-----

## **Fase 8: Workflow específico para Minishell**

Una división típica de tareas para el proyecto Minishell podría ser:

  - **Compañero A (Parser & Señales)**: Se enfoca en el análisis léxico y sintáctico, manejo de tokens, comillas, variables y señales. Ejemplos de ramas: `feature/lexer`, `feature/parser`, `feature/quote-handling`, `feature/variable-expansion`, `feature/signal-handling`.
  - **Compañero B (Ejecutor & Builtins)**: Se encarga de la ejecución de comandos, *pipes*, redirecciones y comandos internos (*builtins*). Ejemplos de ramas: `feature/executor-basico`, `feature/pipes`, `feature/redirections`, `feature/builtins`, `feature/process-management`.

Diariamente, cada uno debe actualizar su rama con los cambios de `develop` (`git pull`, `git rebase develop`) y hacer *commits* frecuentes en sus propias ramas.

Para las entregas, se usa una rama `release` para los ajustes finales, que luego se fusiona en `main` y se etiqueta con la versión, y se vuelve a fusionar en `develop`.

-----

## **Comandos útiles de emergencia**

  - `git status`: Para ver el estado de los archivos y las ramas activas.
  - `git log --graph --oneline --all`: Para ver el historial de `Git` de forma compacta y gráfica.
  - `git reset --soft HEAD~1`: Deshace el último *commit* sin perder los cambios.
  - `git reset --hard HEAD`: Deshace todos los cambios no comiteados (usar con cuidado).
  - `git reflog`: Muestra todos los puntos `HEAD` recientes (útil para recuperar estados).
  - `git checkout -- <archivo>`: Descarta los cambios locales en un archivo específico.
  - `git diff <rama1>..<rama2>`: Muestra las diferencias entre dos ramas.
  - `git fetch origin && git reset --hard origin/develop`: Sincroniza la rama local con la remota, pero borra los cambios locales.
  - `git branch backup-<fecha>`: Crea una rama de respaldo antes de operaciones de riesgo.
  - `git log --grep="palabra-clave"`: Busca en el historial por un mensaje de *commit* o autor.
  - `git log --author="Nombre"`: Filtra los *commits* por autor.

**Importante**: **Nunca usar `git push --force` en las ramas `main` o `develop`**. Se deben conversar los cambios sensibles y usar `--force-with-lease` en las ramas de las *features* si es indispensable.
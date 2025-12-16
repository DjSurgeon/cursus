## **Índice**

  - [Guía de colaboración en GitHub](https://www.google.com/search?q=%23guia-de-colaboracion-en-github)
      - [Reglas Generales](https://www.google.com/search?q=%23reglas-generales)
  - [Antes de comenzar a trabajar](https://www.google.com/search?q=%23antes-de-comenzar-a-trabajar)
  - [Al finalizar el día de trabajo](https://www.google.com/search?q=%23al-finalizar-el-dia-de-trabajo)
  - [Manejo de conflictos](https://www.google.com/search?q=%23manejo-de-conflictos)
  - [Revisión de código (Code Review)](https://www.google.com/search?q=%23revision-de-codigo-code-review)
  - [Hoja de comandos de Git](https://www.google.com/search?q=%23hoja-de-comandos-de-git)
      - [Resumen de comandos clave](https://www.google.com/search?q=%23resumen-de-comandos-clave)
  - [Fuentes](https://www.google.com/search?q=%23fuentes)

-----

## **Guía de colaboración en GitHub**

Esta guía presenta reglas y buenas prácticas para el trabajo en equipo con GitHub, utilizando un flujo de trabajo basado en las ramas **`main`**, **`feature/*`** y **`hotfix/*`**.

La rama **`main`** contendrá siempre código estable listo para producción. Se usará un modelo de desarrollo basado en troncos (**`trunk-based`**), prescindiendo de una rama intermedia **`develop`**. Cada nueva funcionalidad se desarrolla en una rama propia (**`feature/nombre`**), lo que evita contaminar la rama principal con código en desarrollo. Si surge un fallo crítico en producción, se crea una rama **`hotfix/*`** a partir de **`main`** para corregirlo rápidamente y luego se fusiona de nuevo en **`main`**.

### **Reglas Generales**

  - **Respetar la rama `main`**: Solo debe contener código probado y listo para producción. Evita hacer *commits* directos a `main`; en cambio, integra los cambios mediante *Pull Requests* (PR) después de que hayan sido revisados por el equipo.

  - **Trabajar en ramas de funcionalidad (`feature/*`)**: Cada desarrollador crea y trabaja en su propia rama de funcionalidad, derivada de `main`. Esto permite aislar el trabajo en curso y fusionarlo (*merge*) cuando esté terminado.

  - **Sincronización frecuente**: Mantén tu rama personal o de funcionalidad siempre actualizada con los cambios de `main`. Antes de empezar a trabajar, haz **`git pull origin main`** y luego fusiona (*merge*) esos cambios en tu rama. Sincronizar regularmente ayuda a prevenir conflictos de *merge*.

  - **Uso de Pull Requests (PR)**: Para integrar cambios a `main`, crea un PR en GitHub. Un PR inicia la revisión de código; permite discutir y verificar los cambios antes de fusionarlos. Revisa los PR de tus compañeros, da *feedback* constructivo y aprueba los que cumplen los estándares de calidad antes de hacer el *merge*.

-----

## **Antes de comenzar a trabajar**

1.  **Actualizar tu rama local**: Siempre parte del código más reciente.

    ```bash
    git checkout main # Cambia a la rama principal.
    git pull origin main # Actualiza main con el repositorio remoto.
    git checkout <tu-rama>
    git merge main # Fusiona los cambios de main en tu rama.
    ```

    Con esto te aseguras de incorporar los últimos cambios de la rama principal antes de empezar a desarrollar.

2.  **Revisar tareas pendientes**: Comprueba si tienes *issues* asignados o PRs pendientes de revisión. Asegúrate de entender bien los requisitos antes de codificar.

-----

## **Al finalizar el día de trabajo**

1.  **Confirmar (`commit`) tus cambios**: Antes de terminar la jornada, guarda tus avances en la rama local:

    ```bash
    git add .
    git commit -m "Descripción clara de los cambios realizados"
    ```

    Usa mensajes de *commit* concisos y descriptivos.

2.  **Enviar cambios al repositorio remoto (`push`)**: Para no perder tu trabajo, empuja los *commits* de tu rama al servidor:

    ```bash
    git push origin <tu-rama>
    ```

3.  **Abrir un Pull Request si es necesario**: Si has completado una funcionalidad o arreglo, crea un PR hacia `main`. Proporciona un título y descripción detallados del cambio.

4.  **Resolver conflictos pendientes**: Si tu PR muestra conflictos, resuélvelos de inmediato. Comprueba que los cambios compilados y se integran correctamente.

-----

## **Manejo de conflictos**

Cuando intentas fusionar ramas (*merge*) y Git detecta cambios conflictivos, marca los archivos afectados. Para resolverlos:

1.  **Identificar los conflictos**: Ejecuta **`git status`** para ver qué archivos tienen conflictos. Git inserta marcadores (`<<<<<<<`, `=======`, `>>>>>>>`) en el código donde no pudo decidir automáticamente 1324, 1325].

2.  **Resolver manualmente**: Abre cada archivo conflictivo y combina los cambios de forma adecuada. Elimina los marcadores de conflicto una vez resuelto.

3.  **Marcar como resuelto**: Prepara los archivos resueltos con **`git add`**. Por ejemplo:

    ```bash
    git add ruta/al/archivo_resuelto
    ```

    Según las recomendaciones, después de editar los archivos en conflicto se debe ejecutar **`git add`** para indicar que están listos.

4.  **Finalizar la fusión**:

      * Si estabas haciendo *merge*, completa con: **`git merge --continue`**.
      * Si estabas en medio de un *rebase* usa: **`git rebase --continue`**.

    Finalmente, verifica (**`git status`**) que no queden conflictos y realiza un **`git commit`** si es necesario.

-----

## **Revisión de código (Code Review)**

  - **Revisar los PR de otros desarrolladores**: Cada PR debe ser analizado por al menos otro miembro del equipo. Lee el código propuesto, comenta sugerencias y verifica que siga las normas de estilo y que no introduzca errores.

  - **Dar feedback constructivo**: Señala posibles mejoras o errores, pero de forma clara y respetuosa. El objetivo es mejorar la calidad del código, no criticar a la persona.

  - **Aprobar y fusionar**: Si el PR cumple con los requisitos y no tiene problemas, apruébalo en GitHub. Después de la aprobación, fusiona los cambios en `main`. Recuerda eliminar la rama que ya no sea necesaria tras el *merge* para mantener el repositorio limpio.

  - **Importancia de los PR**: Los Pull Requests son fundamentales para el trabajo en equipo, pues permiten revisar y discutir cambios antes de integrarlos a la rama principal. Además, proveen un registro documentado de por qué se hicieron cambios específicos.

-----

## **Hoja de comandos de Git**

A continuación, algunos comandos básicos de Git usados en este flujo de trabajo:

1.  **Mantener tu rama actualizada con `main`**:

    ```bash
    git checkout main
    git pull origin main # Obtiene cambios de main
    git checkout <tu-rama>
    git merge main # Fusiona main en tu rama
    ```

2.  **`git checkout main`**: Cambia a la rama principal.

3.  **`git pull origin main`**: Descarga y fusiona cambios remotos de `main`.

4.  **`git merge main`**: Integra los cambios de `main` en la rama actual.

5.  **Confirmar cambios (`commit`)**:

    ```bash
    git add .
    git commit -m "Mensaje explicativo"
    ```

6.  **`git add .`**: Prepara todos los archivos modificados para el *commit*.

7.  **`git commit -m "mensaje"`**: Crea un *commit* con los cambios preparados y el mensaje dado.

8.  **Enviar cambios al repositorio remoto (`push`)**:

    ```bash
    git push origin <tu-rama>
    ```

9.  Empuja los *commits* locales de tu rama al repositorio remoto para respaldarlos y compartirlos.

10. **Resolver conflictos durante un *merge* o *rebase***:

    ```bash
    git merge --continue
    # o, si estabas haciendo un rebase:
    git rebase --continue
    ```

11. Después de resolver conflictos y hacer **`git add`**, estos comandos completan la operación de *merge* o *rebase*.

12. **Fusionar un Pull Request en `main`** (por terminal, tras aprobación):

    ```bash
    git checkout main
    git pull origin main # Asegúrate de tener la última versión de main
    git merge <tu-rama>
    git push origin main
    ```

13. **`git merge <tu-rama>`**: Fusiona tu rama de funcionalidad en `main`.

14. Luego se debe hacer **`git push origin main`** para subir la fusión al servidor.

### **Resumen de comandos clave**

| Comando | Descripción | Flags importantes |
| :--- | :--- | :--- |
| `git checkout` | Cambiar entre ramas o crear una nueva rama. | `-b <rama>` (crear rama) |
| `git pull` | Descargar cambios del repositorio remoto y fusionar. | `origin <rama>` |
| `git merge` | Fusionar otra rama en la rama actual. | `--continue` (tras conflictos) |
| `git add` | Marcar archivos para incluir en el próximo *commit*. | `.` (todos los archivos) |
| `git commit` | Crear un *commit* con los cambios preparados. | `-m "mensaje"` (mensaje de *commit*) |
| `git push` | Enviar *commits* locales al repositorio remoto. | `origin <rama>` |
| `git rebase` | Reaplicar *commits* de una rama sobre otra. | `--continue` (tras conflictos) |

Estas prácticas y comandos facilitan una colaboración ordenada y eficiente en GitHub, asegurando que el código se mantenga estable y de calidad mientras el equipo desarrolla nuevas funcionalidades.

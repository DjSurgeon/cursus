The provided Plan de Acción is excellent, comprehensive, and follows industry best practices for library testing. It moves logically from diagnosis to automation.

To translate this methodology into an executable plan within your current repository structure, you will need to focus on **tooling setup** and **scripting**, rather than creating a new "agent." The "agent" here is the overall build/test system itself.

Here is the actionable plan, specifying required external files and configuration steps.

### Plan de Acción Ejecutable para la Batería de Pruebas

This plan assumes you are using a standard C build system (like `make`) and that the core library functions are in `libft/src/` and the tests are in `libft/test/`.

#### 🛠️ Fase 0: Preparación del Entorno (Configuración Inicial)

Antes de empezar, necesitamos un sistema de compilación unificado.

1.  **Crear un Makefile Maestro:**
    *   **Ubicación:** Raíz del proyecto (libft).
    *   **Propósito:** Este archivo debe orquestar la compilación de la librería *y* la ejecución de todos los tests.
    *   **Acción:** Crear un Makefile que defina reglas para:
        *   `all`: Compilar la librería principal.
        *   test: Compilar y ejecutar la suite completa de tests.
        *   `clean`: Limpiar todos los archivos generados.

2.  **Estandarizar el Runner (Si es necesario):**
    *   **Revisión:** Dado que tienes `test_*.sh` y `test_*.c` runners, asegúrate de que todos los *runners* de prueba (los archivos `.sh` en test) llamen a un ejecutable compilado (ej. `test_ft_atoi_runner`) y no dependan de compilaciones manuales.

#### 🧪 Fase 1: Análisis y Estandarización (Diagnóstico)

Esta fase es principalmente de **ejecución de herramientas** y **documentación**.

1.  **Ejecutar Análisis de Cobertura:**
    *   **Herramienta:** `gcov` / `lcov`.
    *   **Acción:** Modificar el Makefile para que, después de compilar la librería, ejecute el proceso de cobertura.
    *   **Comando de Ejemplo (en el Makefile):**
        ```makefile
        # Ejemplo conceptual
        $(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(OBJECTS) -o libft_test_run
        ./libft_test_run
        # Luego, usar herramientas de cobertura para generar el reporte
        ```
2.  **Crear un "Reporte de Cobertura" (Documento):** Documentar los *gaps* encontrados (funciones no cubiertas) para priorizar el desarrollo de nuevas pruebas.

#### 🧪 Fase 2: Implementación de Pruebas (Iterativo)

En lugar de escribir tests gigantes, se recomienda usar un *framework* de pruebas unificado (como CUnit o Check) para que el proceso de ejecución sea más limpio.

*   **Acción:** Refactorizar los tests existentes para que todos hereden de una clase base o utilicen las macros del *framework* elegido.
*   **Objetivo:** Asegurar que cada funcionalidad crítica tenga al menos un test unitario asociado.

#### 🚀 Fase 3: Automatización y Ejecución (El Ciclo CI/CD)

El objetivo final es que el proceso de prueba sea automático.

1.  **Script de Ejecución Único:** Crear un script maestro (`run_all_tests.sh`) que haga lo siguiente:
    a. Compilar el código fuente.
    b. Ejecutar la suite de tests unitarios.
    c. Reportar el éxito/fracaso.
2.  **Integración Continua (CI):** Si el proyecto crece, este script debe ser el primer paso en cualquier *pipeline* de CI (GitHub Actions, GitLab CI, etc.).

### Resumen de Entregables (Checklist)

| Componente | Descripción | Estado |
| :--- | :--- | :--- |
| **Makefile** | Debe compilar el código fuente y ejecutar la suite de tests. | $\square$ |
| **`run_all_tests.sh`** | Script maestro para ejecutar el proceso de prueba completo. | $\square$ |
| **Test Suite** | Cobertura de pruebas unitarias para las funciones críticas. | $\square$ |
| **Coverage Report** | Documentación de las áreas de código que aún no están probadas. | $\square$ |
| **CI Pipeline** | Configuración para ejecutar `run_all_tests.sh` automáticamente. | $\square$ |
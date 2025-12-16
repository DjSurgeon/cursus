

# Crear repo en GitHub y conectar
git remote add origin https://github.com/TU_USUARIO/minishell.git
git branch -M main
git push -u origin main

feature/<nombre>: ramas para trabajar cada funcionalidad (por ej: feature/parser, feature/executor).


1) Comenzar a trabajar (día a día): 

git checkout main
git pull origin main

🔹 Crear nueva rama para una funcionalidad:

git checkout -b feature/parser

Trabaja ahí. Haz commits frecuentes y descriptivos:

git add .
git commit -m "feat(parser): añadir manejo de comillas"

Sube tus avances:

git push -u origin feature/parser

2) Pull Requests y revisiones (Cuando termines una funcionalidad):

Asegúrate de actualizar tu rama:

git pull origin main
git merge main

Crea un Pull Request en GitHub: de tu rama feature/* hacia main.

El compañero lo revisa: Una vez aprobado, merge desde GitHub.

3) Después del merge:

Borrar la rama feature/*:

git branch -d feature/parser             # local
git push origin --delete feature/parser  # remoto

(4) Resolución de conflictos (si ocurre)

Cuando Git no puede fusionar cambios automáticamente:
git status  # ver archivos en conflicto
# Editar archivos, buscar <<<<<<< ======= >>>>>>>
git add archivo_resuelto
git merge --continue  # o git rebase --continue si estabas rebaseando

Consejo: Antes de operaciones complejas, crea una rama backup:

git checkout -b backup-2025-08-19


| Acción                   |Comando                                                    |
| ------------------------ | ---------------------------------------------------------- |
| Clonar repo              | `git clone <url>`                                          |
| Cambiar rama             | `git checkout <rama>`                                      |
| Crear rama               | `git checkout -b feature/nombre`                           |
| Subir rama               | `git push -u origin feature/nombre`                        |
| Fusionar cambios de main | `git pull origin main && git merge main`                   |
| Resolver conflictos      | `git status`, editar, `git add`, `git merge --continue`    |
| Crear PR                 | Desde GitHub, entre `feature/*` y `main`                   |
| Borrar rama              | `git branch -d <rama>` y `git push origin --delete <rama>` |


# FDF

Este proyecto, conocido como **FDF** (del francés '*fil de fer*' o 'modelo de estructura alámbrica'), es una iniciativa fundamental en el campo de la programación gráfica. Su objetivo principal es la creación y visualización de un paisaje tridimensional mediante un modelo de estructura alámbrica, conectando puntos definidos por coordenadas (x, y, z) a través de segmentos de línea. Este trabajo sirve como una introducción práctica a la programación gráfica básica, familiarizando al desarrollador con la biblioteca **MiniLibX** y conceptos esenciales como la gestión de ventanas, la creación de imágenes y la manipulación de eventos de teclado y ratón.

Ls principales carácteristicas del proyecto son:
- Renderizado de un paisaje 3D a partir de un archivo `*.fdf`.
- Implementación obligatoria de una proyección isométrica.
- Gestión interactiva de la ventana gráfica.

## Conceptos iniciales

### Wireframe Modelling o Modelado de Estructura Alámbrica

El modelado de estructura alámbrica es una técnica de renderización en gráficos 3D que representa objetos mediante la visualización de sus aristas o 'segmentos de línea' (*edges*), sin rellenar las superficies. Esto resulta en una imagen **semitransparente** donde la estructura interna del objeto es visible. Para FDF, esto implica conectar cada punto (x, y, z) con sus vecinos adyacentes para formar una malla visible. Esta técnica es valorada en proyectos gráficos iniciales por su simplicidad computacional, ya que evita la complejidad de los algoritmos de renderizado de superficies.

### Proyecciones Geométricas

Las proyecciones geométricas son métodos matemáticos utilizados para transformar objetos **tridimensionales** en una representación **bidimensional**, permitiendo su visualización en una pantalla.

#### Proyección Ortográfica

Representa objetos mediante vistas separadas (frontal, superior, lateral), proyectando los puntos perpendicularmente a un plano. No hay efecto de perspectiva, y las líneas paralelas permanecen paralelas. Aunque no es la proyección principal de FDF, es fundamental para entender la base de las proyecciones paralelas.

#### Proyeccion Isométrica

Es una **proyección paralela** donde los **tres ejes** principales (X, Y, Z) forman **ángulos de 120 grados** entre sí. Las líneas paralelas a estos ejes se dibujan a la misma escala, sin puntos de fuga. Esta proyección es la obligatoria para el renderizado del modelo en FDF. Se elige por su capacidad de ofrecer una percepción de profundidad sin la complejidad computacional de la perspectiva real, lo que la hace ideal para un proyecto gráfico introductorio que se enfoca en las transformaciones 3D básicas.

#### Perspectiva

Intenta **simular la visión humana**, donde los objetos se hacen más pequeños a medida que se alejan del observador. Requiere uno o más puntos de fuga donde las líneas paralelas convergen. En FDF, la implementación de la perspectiva es una característica extra (bonus) , lo que subraya su mayor complejidad computacional y su naturaleza opcional.

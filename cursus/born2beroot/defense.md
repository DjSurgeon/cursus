# Born2beRoot

## ¿Qué es una máquina virtual?

Una **máquina virtual** (VM) es un entorno informático emulado que opera como un sistema independiente, con su propio sistema operativo, CPU virtual, memoria, almacenamiento e interfaces de red, todo ello creado a partir de los recursos físicos de un equipo host mediante un software de virtualización, como **VirtualBox** o **UTM**. Este entorno se encapsula generalmente en un único archivo o conjunto de archivos, lo que permite su portabilidad entre diferentes máquinas físicas; es decir, puede trasladarse y ejecutarse en otro equipo siempre que se disponga del software de virtualización adecuado, manteniendo su funcionalidad intacta. Al estar aislada del sistema host y de otras VMs, ofrece un entorno seguro y controlado para pruebas, desarrollo o ejecución de sistemas operativos.

## Qué es la virtualización?

La **virtualización** es una tecnología que permite crear entornos simulados o virtuales a partir de los recursos de una máquina física. Mediante esta técnica, se abstrae el hardware físico (como CPU, memoria, almacenamiento y red) para dividirlo y asignarlo a múltiples entornos independientes, conocidos como máquinas virtuales (VMs). Esto optimiza el uso de los recursos del equipo físico, ya que permite ejecutar varios sistemas operativos o aplicaciones de forma simultánea en un solo dispositivo, mejorando la eficiencia y flexibilidad en la gestión de sistemas.

## ¿Qué son los hipervisores?

Un **hipervisor**, también conocido como monitor de máquinas virtuales (VMM, por sus siglas en inglés: *Virtual Machine Manager*), es un software, firmware o combinación de ambos que gestiona y separa los recursos físicos de un sistema para asignarlos a entornos virtuales, como las máquinas virtuales (VMs). Actúa como una capa intermedia entre el hardware físico (denominado *host*) y las VMs (denominadas *guests*), permitiendo que múltiples sistemas operativos se ejecuten simultáneamente en el mismo equipo. El hipervisor toma los recursos físicos, como CPU, memoria y almacenamiento, y los distribuye dinámicamente según las necesidades de cada VM, facilitando tanto la creación como la administración de estas.

Existen dos tipos principales de hipervisores, adaptados a diferentes casos de uso:

- **Tipo 1** (*Bare Metal* o Nativo): Este hipervisor se ejecuta directamente sobre el hardware físico del host, sin necesidad de un sistema operativo subyacente. Programa los recursos del hardware de manera directa para las VMs, lo que lo hace eficiente y adecuado para entornos empresariales, como centros de datos o servidores dedicados. Ejemplos incluyen **VMware** **ESXi**, **Xen** o **Microsoft Hyper-V** en modo nativo.
- Tipo 2 (Alojado o *Hosted*): Este hipervisor se ejecuta como una aplicación sobre un sistema operativo convencional (como **Windows**, **Linux** o **macOS**). Abstrae los recursos del sistema operativo host para asignarlos a las VMs, lo que lo hace ideal para uso personal, pruebas o entornos de desarrollo. En el caso del proyecto "Born2beRoot", utilizamos un hipervisor de Tipo 2, como **VirtualBox** o **UTM**, aunque también existen otras opciones como **VMware Workstation** o **Parallels**.

## ¿Qué es KVM?

KVM (*Kernel-based Virtual Machine*) es un hipervisor de Tipo 1 de código abierto integrado directamente en el núcleo (kernel) de distribuciones modernas de Linux. Funciona como una extensión del kernel Linux, permitiendo que este actúe como un hipervisor para gestionar máquinas virtuales (VMs). Al ejecutarse a nivel de hardware, KVM ofrece un alto rendimiento al aprovechar las capacidades nativas de virtualización del procesador (como **Intel VT-x** o **AMD-V**) y las funciones de optimización del kernel Linux. Esto permite a los usuarios beneficiarse de un control detallado sobre las VMs, así como de una eficiencia superior en entornos de servidores o centros de datos donde se requiere virtualización robusta y escalable.

## Debian

Debian es un sistema operativo de código abierto basado en el núcleo Linux (kernel Linux) y en la filosofía GNU, desarrollado de manera no comercial y totalmente gratuito para cualquier uso. Fundado en 1993 por Ian Murdock, es una de las distribuciones más antiguas y relevantes del ecosistema Linux, destacándose por su fuerte compromiso con el software libre. Distros populares como **Ubuntu**, **Linux Mint**, **Raspbian** y **Kali Linux** son derivadas de Debian, lo que las convierte en *forks* o personalizaciones con adaptaciones específicas para diferentes públicos y usos.

### Características importantes:

**Software gratuito y filosofía libre**: La característica más destacada de Debian es que, por defecto, incluye únicamente software gratuito bajo licencias open source, alineándose con los principios de la Free Software Foundation. Sin embargo, reconoce que algunos componentes, como ciertos controladores de hardware, pueden no ser libres, aunque no impone restricciones a los usuarios para instalar software de cualquier tipo si lo desean.
**Alta estabilidad**: Debian prioriza la estabilidad sobre la novedad, lo que significa que las versiones de los programas incluidos en sus repositorios no siempre son las más recientes, sino las que han sido probadas exhaustivamente a lo largo del tiempo. Esto lo hace ideal para entornos que requieren fiabilidad, como servidores.
**Popularidad en servidores**: Su estabilidad y robustez lo convierten en una opción preferida para la administración de servidores, aunque no es tan común como distro de escritorio debido a la falta de software reciente por defecto.
**Interfaz gráfica y gestión de paquetes**: GNOME es la interfaz gráfica predeterminada, aunque puede instalarse otra. Debian utiliza APT (Advanced Package Tool) como sistema de gestión de paquetes, que simplifica la instalación, actualización y eliminación de software, siendo una herramienta clave para su administración.

## Rocky Linux

Rocky Linux es una distribución de código abierto basada en **Red Hat Enterprise Linux** (RHEL), diseñada para ser estable, fácil de usar y compatible con aplicaciones tanto de servidor como de escritorio. Lanzada por primera vez en 2021, es considerada un "clon" de RHEL, ofreciendo compatibilidad binaria con este, lo que facilita la migración desde distribuciones como **CentOS** o **Alma Linux**. La distribución es mantenida por Rocky Enterprise Software Foundation, liderada por Gregory Kurtzer, cofundador de CentOS, quien aporta experiencia en las necesidades de los usuarios de sistemas empresariales.

### Características importantes:

**Estabilidad**: Al igual que RHEL, Rocky Linux prioriza la estabilidad sobre actualizaciones frecuentes, enfocándose en ofrecer un sistema fiable sin sorpresas o interrupciones, ideal para servidores y entornos críticos.
**Compatibilidad**: Su compatibilidad binaria con RHEL permite una transición suave desde otras distribuciones basadas en RHEL, como CentOS, y asegura soporte para software empresarial.
**Código abierto**: Rocky Linux se desarrolla bajo la filosofía de software open source, garantizando transparencia y acceso a la comunidad.
**Reciente y limitada documentación**: Al ser una distribución relativamente nueva (lanzada en 2021), cuenta con menos informes de usuarios, documentación y comunidad en comparación con distribuciones más establecidas como Debian o RHEL. Esto puede dificultar su adopción para usuarios novatos o en entornos complejos.

## Debian vs. Rocky Linux

### Coincidencias

**Código abierto y gratuito**: Ambos son distribuciones de código abierto bajo licencias que promueven el software libre, accesibles sin costo para cualquier uso, alineándose con la filosofía del software libre y open source.
**Alta estabilidad**: Priorizan la estabilidad sobre la novedad, lo que los hace ideales para servidores y entornos críticos donde la fiabilidad es esencial. Sus versiones estables incluyen software probado exhaustivamente, evitando actualizaciones frecuentes que podrían introducir errores.
**Uso en servidores**: Son ampliamente utilizados en la administración de servidores debido a su robustez y capacidad para manejar configuraciones complejas, como las requeridas en el ejercicio (por ejemplo, LVM, firewalls, y políticas de seguridad).
**Soporte para virtualización**: Ambos son compatibles con entornos virtualizados, como los creados con VirtualBox o UTM.
**Gestión de paquetes avanzada**: Aunque usan herramientas diferentes, ambas distribuciones ofrecen sistemas potentes para gestionar paquetes: APT en Debian y DNF/YUM en Rocky Linux, facilitando la instalación y actualización de software.

### Diferencias

**Origen y base**:
- **Debian**: Es una distribución independiente basada en el kernel Linux y la filosofía GNU, fundada en 1993 por Ian Murdock. No depende de ninguna empresa comercial y es mantenida por una comunidad global, lo que la alinea con los principios del software libre.
- **Rocky Linux**: Es una distribución derivada de Red Hat Enterprise Linux (RHEL), lanzada en 2021 como un "clon" de RHEL tras la transición de CentOS. Está respaldada por Rocky Enterprise Software Foundation y se enfoca en compatibilidad binaria con RHEL, siendo más orientada a entornos empresariales.
**Filosofía y software**:
- **Debian**: Se caracteriza por incluir exclusivamente software libre por defecto, aunque permite a los usuarios instalar software propietario si lo desean. Su compromiso con la Free Software Foundation es central, pero esto puede limitar la inclusión de controladores o programas no libres (como algunos controladores de hardware).
- **Rocky Linux**: Aunque también es open source, no tiene una filosofía tan estricta sobre el software libre, ya que está diseñada para ser compatible con RHEL, que incluye componentes propietarios en algunos casos (por ejemplo, soporte para hardware específico). Esto la hace más práctica para entornos empresariales, pero menos purista en términos de software libre.
**Interfaz y gestión de paquetes**:
- **Debian**: Utiliza GNOME como interfaz gráfica predeterminada y APT como su sistema de gestión de paquetes, que es simple y eficiente para usuarios con experiencia en Linux. También se puede usar aptitude para una gestión más avanzada.
- **Rocky Linux**: No tiene una interfaz gráfica predeterminada tan definida para servidores y utiliza DNF (o YUM en versiones anteriores) como sistema de gestión de paquetes, que es más complejo pero potente para entornos empresariales.
**Complejidad y experiencia requerida**:
- **Debian**: Es más accesible para usuarios novatos en administración de sistemas, lo que lo hace adecuada para quienes no tienen experiencia previa. Su configuración (como AppArmor, LVM) es más sencilla y bien documentada.
- **Rocky Linux**: Es más complejo de configurar, especialmente por la necesidad de gestionar SELinux y su enfoque en entornos empresariales. El ejercicio advierte que no es necesario configurar KDump, pero aún requiere más conocimientos para cumplir con las reglas estrictas.
**Popularidad y documentación**:
- **Debian**: Con más de 30 años de historia, tiene una comunidad grande, extensa documentación y un ecosistema maduro, lo que facilita su uso y resolución de problemas. Es menos común como distro de escritorio, pero dominante en servidores y entornos educativos.
- **Rocky Linux**: Al ser una distribución más reciente (desde 2021), tiene menos documentación y comunidad en comparación con Debian o RHEL, lo que puede dificultar su adopción para usuarios sin experiencia o en configuraciones complejas.
**Seguridad y herramientas específicas**:
**Debian**: Utiliza AppArmor como sistema de seguridad obligatorio (en el ejercicio), que es más fácil de configurar para usuarios novatos y se integra bien con APT.
**Rocky Linux**: Requiere SELinux, que es más complejo de manejar, pero ofrece mayor control granular para entornos empresariales.

## Herramientas de gestión de paquetes en Debian

Debian ofrece tres herramientas principales para gestionar paquetes, instalar, actualizar y administrar software: **apt**, **apt-get** y **aptitude**. Cada una tiene características, propósitos y niveles de complejidad distintos, lo que las hace complementarias pero con usos específicos.

### apt

**Descripción**: apt (*Advanced Package Tool*) es una interfaz de alto nivel introducida en Debian para simplificar la administración de paquetes y mejorar la experiencia del usuario. Actúa como una capa más amigable sobre *apt-get* y *apt-cache*, combinando sus funcionalidades en comandos más intuitivos y modernos.
**Características**: Utiliza una sintaxis simplificada, lo que la hace accesible para usuarios novatos o administradores ocasionales (por ejemplo, *apt update*, *apt upgrade*, *apt install*). Su salida es más legible y amigable, con mensajes claros y una barra de progreso durante las instalaciones, lo que facilita la interpretación de la información. Oculta detalles técnicos innecesarios, enfocándose en la usabilidad, pero esto puede limitar su flexibilidad para tareas avanzadas.
**Ventajas**: Es ideal para tareas rápidas y cotidianas, especialmente en entornos donde la simplicidad es prioritaria.
**Limitaciones**: Ofrece menos control granular que apt-get o aptitude, lo que puede ser un inconveniente para usuarios avanzados o scripts automatizados.

### apt-get

**Descripción**: apt-get es una herramienta de línea de comandos de nivel bajo, más antigua y técnica, que forma parte del sistema APT en Debian. Es una de las herramientas más tradicionales, utilizada desde las primeras versiones de Debian, y sigue siendo fundamental para tareas avanzadas.
**Características**: Proporciona un mayor nivel de control y personalización en las operaciones de gestión de paquetes, como instalación, actualización, eliminación y resolución de dependencias (por ejemplo, *apt-get update*, *apt-get upgrade*, *apt-get remove*). Es menos amigable para usuarios novatos debido a su salida más técnica y a la falta de una barra de progreso o mensajes simplificados, pero es altamente predecible y útil para usuarios avanzados o en scripts automatizados. Permite un manejo más preciso de las dependencias y opciones avanzadas, como forzar la instalación o ignorar ciertas dependencias con parámetros específicos.
**Ventajas**: Ideal para administradores experimentados que necesitan un control detallado sobre el sistema o para automatizar tareas en entornos como servidores Debian configurados.
**Limitaciones**: Su interfaz es menos intuitiva y puede resultar abrumadora para usuarios sin experiencia, además de requerir más conocimiento técnico para aprovecharla al máximo.

### aptitude

**Descripción**: aptitude es una herramienta de gestión de paquetes con una interfaz de texto interactiva (basada en ncurses), diseñada para ofrecer un enfoque más poderoso y detallado. Es conocida por su capacidad avanzada para gestionar dependencias y resolver conflictos, lo que la hace atractiva para usuarios experimentados.
**Características**: Proporciona una visualización detallada de las dependencias, paquetes y acciones, facilitando la comprensión de las operaciones antes de ejecutarlas (por ejemplo, muestra árboles de dependencias en modo interactivo). Resuelve conflictos de dependencias de manera más inteligente que apt o apt-get, proponiendo soluciones alternativas al usuario para que elija la más adecuada, lo que reduce errores en configuraciones complejas. Mantiene un registro detallado de todas las acciones realizadas, lo que facilita el seguimiento de cambios en el sistema y la auditoría, algo útil en entornos críticos como los servidores configurados en el proyecto. Ofrece una interfaz de texto que permite navegar, buscar e instalar paquetes de forma interactiva, aunque también puede usarse en modo línea de comandos.
**Ventajas**: Es ideal para administradores avanzados que necesitan un control exhaustivo sobre paquetes, especialmente en sistemas con dependencias complicadas o en configuraciones de seguridad estrictas (por ejemplo, para verificar dependencias de AppArmor o LVM).
**Limitaciones**: Su interfaz interactiva puede ser intimidante para usuarios novatos, y su uso requiere más tiempo y experiencia que apt o apt-get. Además, no es tan común en scripts automatizados debido a su enfoque interactivo.

## MAC (Mandatory Access Control)

**Definición**: MAC, o Control de Acceso Obligatorio (*Mandatory Access Control*), es un modelo de control de acceso utilizado en sistemas operativos y aplicaciones para restringir el acceso a recursos (como archivos, procesos, dispositivos y redes) según reglas predefinidas e inmutables impuestas por un administrador de sistemas o políticas de seguridad centralizadas. A diferencia de otros modelos, como **DAC** (*Discretionary Access Control*), en MAC el acceso no es determinado por el propietario del recurso, sino por una autoridad central que define y aplica las políticas de seguridad, las cuales los usuarios no pueden modificar.

**Características principales**: 
- **Políticas centralizadas e inmutables**: Las reglas de acceso en MAC son establecidas por un administrador o un sistema de seguridad (como **SELinux** o **AppArmor**), y los usuarios no tienen la capacidad de cambiarlas. Esto asegura un control estricto y consistente, ideal para entornos de alta seguridad.
**Jerarquía de seguridad**: MAC a menudo utiliza niveles o categorías de seguridad (por ejemplo, confidencial, secreto, público) y etiquetas para clasificar recursos y usuarios. El acceso se concede solo si las etiquetas del usuario y el recurso coinciden con las políticas definidas.
**Aplicaciones típicas**: Es común en sistemas críticos, como servidores gubernamentales, militares o empresariales, donde la seguridad es prioritaria. También se utiliza en distribuciones Linux como Debian (con AppArmor) y Rocky Linux (con SELinux).
**Restricciones estrictas**: MAC limita no solo quién puede acceder a un recurso, sino también qué acciones (lectura, escritura, ejecución) pueden realizarse, basándose en las políticas predefinidas.
**Diferencia con DAC** (*Discretionary Access Control*): En DAC, el propietario de un recurso tiene la libertad de decidir quién puede acceder y qué permisos otorgar, generalmente mediante permisos de lectura, escritura y ejecución (por ejemplo, usando chmod en Linux). En cambio, MAC elimina esta discreción, imponiendo un control obligatorio y centralizado que prioriza la seguridad sobre la flexibilidad, lo que lo hace más adecuado para entornos regulados o sensibles.
**Ventajas de MAC**: Proporciona un alto nivel de seguridad y protección contra accesos no autorizados o configuraciones erróneas por parte de usuarios. Es ideal para entornos multiusuario o críticos donde la integridad y confidencialidad de los datos son prioritarias.
**Limitaciones de MAC**: Puede ser complejo de configurar y administrar, especialmente para usuarios sin experiencia, lo que podría ser un desafío en "Born2beRoot" si optas por Rocky Linux y SELinux. Reduce la flexibilidad para los usuarios, ya que no pueden modificar las políticas de acceso, lo que podría ser inconveniente en entornos menos estrictos.
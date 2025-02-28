# Born2beRoot

## ¿Qué es una máquina virtual?

Una **máquina virtual** (VM) es un entorno informático emulado que opera como un sistema independiente, con su propio sistema operativo, CPU virtual, memoria, almacenamiento e interfaces de red, todo ello creado a partir de los recursos físicos de un equipo host mediante un software de virtualización, como **VirtualBox** o **UTM**. Este entorno se encapsula generalmente en un único archivo o conjunto de archivos, lo que permite su portabilidad entre diferentes máquinas físicas; es decir, puede trasladarse y ejecutarse en otro equipo siempre que se disponga del software de virtualización adecuado, manteniendo su funcionalidad intacta. Al estar aislada del sistema host y de otras VMs, ofrece un entorno seguro y controlado para pruebas, desarrollo o ejecución de sistemas operativos.

## Qué es la virtualización?

La **virtualización** es una tecnología que permite crear entornos simulados o virtuales a partir de los recursos de una máquina física. Mediante esta técnica, se abstrae el hardware físico (como CPU, memoria, almacenamiento y red) para dividirlo y asignarlo a múltiples entornos independientes, conocidos como máquinas virtuales (VMs). Esto optimiza el uso de los recursos del equipo físico, ya que permite ejecutar varios sistemas operativos o aplicaciones de forma simultánea en un solo dispositivo, mejorando la eficiencia y flexibilidad en la gestión de sistemas.

## ¿Qué son los hipervisores?

Un **hipervisor**, también conocido como monitor de máquinas virtuales (VMM, por sus siglas en inglés: *Virtual Machine Manager*), es un software, firmware o combinación de ambos que gestiona y separa los recursos físicos de un sistema para asignarlos a entornos virtuales, como las máquinas virtuales (VMs). Actúa como una capa intermedia entre el hardware físico (denominado *host*) y las VMs (denominadas *guests*), permitiendo que múltiples sistemas operativos se ejecuten simultáneamente en el mismo equipo. El hipervisor toma los recursos físicos, como CPU, memoria y almacenamiento, y los distribuye dinámicamente según las necesidades de cada VM, facilitando tanto la creación como la administración de estas.

Existen dos tipos principales de hipervisores, adaptados a diferentes casos de uso:

- **Tipo 1** (*Bare Metal* o Nativo): Este hipervisor se ejecuta directamente sobre el hardware físico del host, sin necesidad de un sistema operativo subyacente. Programa los recursos del hardware de manera directa para las VMs, lo que lo hace eficiente y adecuado para entornos empresariales, como centros de datos o servidores dedicados. Ejemplos incluyen **VMware** **ESXi**, **Xen** o **Microsoft Hyper-V** en modo nativo.
- Tipo 2 (Alojado o *Hosted*): Este hipervisor se ejecuta como una aplicación sobre un sistema operativo convencional (como **Windows**, **Linux** o **macOS**). Abstrae los recursos del sistema operativo host para asignarlos a las VMs, lo que lo hace ideal para uso personal, pruebas o entornos de desarrollo.

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
- **Debian**: Utiliza AppArmor como sistema de seguridad obligatorio (en el ejercicio), que es más fácil de configurar para usuarios novatos y se integra bien con APT.
- **Rocky Linux**: Requiere SELinux, que es más complejo de manejar, pero ofrece mayor control granular para entornos empresariales.

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
- **Jerarquía de seguridad**: MAC a menudo utiliza niveles o categorías de seguridad (por ejemplo, confidencial, secreto, público) y etiquetas para clasificar recursos y usuarios. El acceso se concede solo si las etiquetas del usuario y el recurso coinciden con las políticas definidas.
- **Aplicaciones típicas**: Es común en sistemas críticos, como servidores gubernamentales, militares o empresariales, donde la seguridad es prioritaria. También se utiliza en distribuciones Linux como Debian (con AppArmor) y Rocky Linux (con SELinux).
- **Restricciones estrictas**: MAC limita no solo quién puede acceder a un recurso, sino también qué acciones (lectura, escritura, ejecución) pueden realizarse, basándose en las políticas predefinidas.
- **Diferencia con DAC** (*Discretionary Access Control*): En DAC, el propietario de un recurso tiene la libertad de decidir quién puede acceder y qué permisos otorgar, generalmente mediante permisos de lectura, escritura y ejecución (por ejemplo, usando chmod en Linux). En cambio, MAC elimina esta discreción, imponiendo un control obligatorio y centralizado que prioriza la seguridad sobre la flexibilidad, lo que lo hace más adecuado para entornos regulados o sensibles.
- **Ventajas de MAC**: Proporciona un alto nivel de seguridad y protección contra accesos no autorizados o configuraciones erróneas por parte de usuarios. Es ideal para entornos multiusuario o críticos donde la integridad y confidencialidad de los datos son prioritarias.
- **Limitaciones de MAC**: Puede ser complejo de configurar y administrar, especialmente para usuarios sin experiencia, lo que podría ser un desafío en "Born2beRoot" si optas por Rocky Linux y SELinux. Reduce la flexibilidad para los usuarios, ya que no pueden modificar las políticas de acceso, lo que podría ser inconveniente en entornos menos estrictos.

## AppArmor

**AppArmor** es un módulo de seguridad de Linux que implementa un sistema de control de acceso obligatorio (**MAC**) basado en políticas. Permite restringir el acceso de aplicaciones y procesos al sistema operativo mediante perfiles predefinidos, limitando las operaciones y recursos (como archivos, redes, capacidades del kernel y dispositivos) que un programa puede realizar, independientemente de los privilegios del usuario que lo ejecuta.

**Características principales**:
- **Políticas basadas en perfiles**: AppArmor utiliza perfiles configurables para especificar qué recursos y operaciones están permitidos o denegados para cada aplicación o proceso. Estos perfiles se basan en nombres de ruta (*pathnames*) para definir permisos, lo que facilita su configuración en comparación con otros sistemas como SELinux.
- **Restricciones independientemente de privilegios**: A diferencia de los controles tradicionales basados en permisos de usuario (como **DAC**), AppArmor impone restricciones incluso si un usuario o proceso tiene privilegios elevados (por ejemplo, *root*), lo que lo hace ideal para proteger sistemas críticos.
- **Desarrollo e integración**: Originalmente desarrollado por **SUSE Linux**, AppArmor es ahora parte del kernel Linux y está ampliamente utilizado en distribuciones como Debian, Ubuntu y, en menor medida, Rocky Linux (donde SELinux es más común). Es una alternativa ligera y fácil de usar frente a SELinux, especialmente para usuarios novatos.

**Objetivos y funciones**:
- **Limitación de acceso**: AppArmor restringe las aplicaciones a solo los recursos necesarios para su funcionamiento, previniendo accesos no autorizados a archivos, dispositivos o redes que no deberían utilizar. Esto reduce la superficie de ataque en el sistema.
- **Prevención de escalamiento de privilegios**: Si una aplicación o proceso es comprometido (por ejemplo, mediante un *exploit*), AppArmor puede evitar que un atacante acceda a otras partes del sistema, limitando el daño potencial y protegiendo recursos críticos.
- **Facilidad de configuración**: Comparado con SELinux, AppArmor es más sencillo de implementar y administrar, ya que utiliza nombres de ruta en lugar de etiquetas o contextos de seguridad, lo que lo hace más intuitivo para usuarios sin experiencia avanzada en seguridad.

**Ventajas**:
- Es más ligero y menos complejo que SELinux, lo que lo hace ideal para distribuciones como Debian en entornos personales o educativos.
- Permite una configuración granular sin requerir un conocimiento profundo de sistemas de seguridad, lo que facilita su uso en proyectos con reglas estrictas, como limitar accesos a servicios como SSH o gestionar recursos en LVM.
- Ofrece protección en tiempo real contra amenazas, como malware o exploits, al restringir operaciones no autorizadas.

**Limitaciones**:
- Su dependencia en nombres de ruta puede ser una desventaja si los archivos cambian de ubicación o si se requiere una gestión más dinámica, como en sistemas empresariales complejos.
- No es tan flexible ni tan avanzado como SELinux en términos de control granular basado en etiquetas y contextos, lo que lo limita en entornos muy críticos o regulados.

## ¿Qué es una partición?

Una partición es una división lógica de un disco duro o unidad de almacenamiento (como SSDs o discos externos) que permite segmentar el espacio físico en unidades independientes, cada una con su propio sistema de archivos y propósito. Estas particiones se comportan como discos separados dentro del mismo dispositivo físico, lo que facilita la organización, administración y uso de los datos. 

**Las particiones se utilizan para**:
- Organizar mejor los datos, separando, por ejemplo, el sistema operativo, los archivos de usuario y los datos de aplicaciones.
- Facilitar la administración del espacio de almacenamiento, asignando tamaños específicos a cada sección según las necesidades.
- Mejorar la seguridad, cifrando o restringiendo el acceso a ciertas particiones.
- Soportar múltiples sistemas operativos en un solo disco, cada uno instalado en su propia partición.

### Tipos de particiones

Existen diferentes tipos de particiones, cada una con un propósito específico y compatibilidad según la tabla de particiones utilizada (**MBR** o **GPT**).
**Primaria**: Son particiones básicas que pueden alojar un sistema operativo o datos. En discos con la tabla MBR (*Master Boot Record*), se pueden crear hasta 4 particiones primarias por disco.
**Extendida**: Es una partición especial que actúa como contenedor para particiones lógicas, permitiendo superar el límite de 4 particiones primarias en discos MBR. No puede almacenar datos directamente, solo sirve como un "recipiente" para particiones lógicas.
**Lógica**: Se crean dentro de una partición extendida y permiten dividir el espacio restante en más unidades independientes. Son útiles para organizar datos o sistemas adicionales en discos MBR.
**EFI (UEFI System Partition)**: Es una partición especial utilizada en sistemas con la tabla GPT (*GUID Partition Table*) y UEFI (*Unified Extensible Firmware Interface*) para almacenar el gestor de arranque (*bootloader*) y otros datos necesarios para el arranque seguro.

## LVM (Logical Volume Manager)

**LVM**, o *Logical Volume Manager*, es un sistema de gestión de almacenamiento en Linux que permite crear volúmenes lógicos flexibles y dinámicos en lugar de depender exclusivamente de particiones físicas tradicionales. LVM abstrae el almacenamiento físico (discos duros, SSDs, o particiones) en una estructura jerárquica que facilita la administración, el redimensionamiento y la organización del espacio de almacenamiento, siendo ideal para entornos como servidores o máquinas virtuales.

**Características principales**:
- **Redimensionamiento dinámico**: LVM permite aumentar o disminuir el tamaño de los volúmenes lógicos sin necesidad de reiniciar el sistema, siempre que haya espacio disponible en el grupo de volúmenes (VG). Esto es especialmente útil para adaptarse a las necesidades cambiantes de almacenamiento en tiempo real, como en el proyecto donde se requiere flexibilidad para particiones cifradas.
- **Snapshots**: LVM soporta la creación de instantáneas (*snapshots*) de los volúmenes lógicos, permitiendo copias de seguridad puntuales del sistema sin interrumpir los servicios en ejecución. Estas instantáneas son útiles para pruebas, restauraciones o recuperación de datos en caso de fallos.
- **Agregación de discos**: Permite combinar múltiples discos físicos o particiones en un único grupo de volúmenes lógicos, ofreciendo un almacenamiento unificado y escalable. Esto facilita la gestión de recursos en máquinas virtuales con discos asignados dinámicamente, como en VirtualBox o UTM.
- **Aislamiento y organización**: LVM permite crear múltiples volúmenes lógicos independientes dentro de un mismo grupo de volúmenes, lo que facilita la segregación de datos (por ejemplo, `/`, `/home`, `/var`, `/swap`) y mejora la seguridad al limitar el acceso entre ellos.

**Componentes clave de LVM**:
- **PV (Physical Volume - Volumen Físico)**: Representa el almacenamiento físico subyacente, como discos duros, SSDs o particiones (por ejemplo, `/dev/sda5`). Es el bloque básico que se inicializa para ser gestionado por LVM.
- **VG (Volume Group - Grupo de Volúmenes)**: Es un conjunto de uno o más volúmenes físicos combinados en una unidad lógica. Actúa como un "contenedor" que agrupa los PVs para crear volúmenes lógicos.
- **LV (Logical Volume - Volumen Lógico)**: Es la unidad de almacenamiento final que se monta y utiliza como si fuera una partición tradicional. Los LVs se crean dentro de un VG y pueden redimensionarse o cifrarse.

**Ventajas**:
- Flexibilidad para gestionar el almacenamiento dinámicamente, para crear particiones cifradas (como con LUKS) y ajustar su tamaño según las necesidades.
- Mayor control sobre la organización del almacenamiento, permitiendo separar recursos críticos (como `/boot`, que no debe cifrarse, de `/` o `/home`, que sí deben estar cifrados).
- Compatibilidad con herramientas de seguridad, como el cifrado con LUKS.

## Nomenclatura de los discos en Linux

En Linux, los discos de almacenamiento (como discos duros, SSDs, o discos virtuales en máquinas virtuales) se identifican como dispositivos de bloque, que son archivos especiales ubicados en el directorio `/dev`. Estos dispositivos siguen una convención estándar de nomenclatura que permite identificar de forma única los discos físicos y sus particiones, facilitando su gestión en sistemas operativos como Debian o Rocky Linux.

La nomenclatura más común para discos en Linux es `/dev/sdxn`, donde:

`**/dev/**`: Es el directorio raíz donde se almacenan los dispositivos especiales en el sistema, accesibles como archivos.
**sd**: Es el prefijo que identifica discos basados en SCSI (*Small Computer System Interface*) o SATA, comúnmente usado para discos físicos o virtuales (por ejemplo, discos en VirtualBox o UTM).
**hd** (para discos IDE, aunque obsoletos en sistemas modernos).
**nvme** (para discos NVMe en sistemas modernos con SSDs de alta velocidad).
`**x**`: Es una letra que identifica el disco físico o virtual, comenzando desde a para el primer disco (`/dev/sda`), b para el segundo (`/dev/sdb`), y así sucesivamente.
`**n**`: Es un número que representa la partición dentro de un disco específico, comenzando desde 1 (por ejemplo, `/dev/sda1` para la primera partición del primer disco, `/dev/sda2` para la segunda, `/dev/sdb1` para la primera partición del segundo disco, etc.).

En máquinas virtuales, VirtualBox o UTM pueden asignar discos virtuales (como archivos **.vdi** o **.qcow2**) que se presentan como `/dev/sda`, `/dev/sdb`, etc., siguiendo la misma convención.
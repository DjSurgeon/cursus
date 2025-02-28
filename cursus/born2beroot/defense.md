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


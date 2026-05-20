# minitalk

## ¿Qué es una señal en Unix?

Una señal es un pequeño mensaje que notifica a un proceso que un evento de algun tipo ha ocurrido en el sistema.

Una señal es un mecanismo de comunicación asíncrona utilizado en sistemas Unix y compatibles con POSIX para notificar a un proceso sobre eventos específicos. Funciona como una interrupción controlada:

- Asíncrona: Puede ocurrir en cualquier momento durante la ejecución del proceso.
- Limitada: No transporta datos complejos (salvo en señales en tiempo real con sigqueue).
- Acciones predefinidas: Cada señal tiene un comportamiento por defecto (ej: terminar, ignorar, volcar memoria).

## Proposito y uso

Notificar eventos:

- SIGINT (Ctrl-C): Terminación del proceso.
- SIGSEGV: Violación de segmento (acceso a memoria inválida).
- SIGTERM: Solicitud de terminación "amigable".

Eventos del sistema: Finalización de un proceso hijo (SIGCHLD), error de tubería (SIGPIPE).
Comunicación entre procesos (IPC): Un proceso puede enviar señales a otro usando kill(pid, señal).

El kernel envia o (entrega) una señal a un proceso destino actualizando algun estado en el contexto del proceso destino.

## Mandar una señal

El kernel envia señales por algun razón:

- El kernel detecta un evento de sistema como division por 0 (SIGFPE) o la terminación de un proceso hijo (SIGCHLD)
- Otro proceso invoca la función `kill`, mandando un petición al kernel para enviar una señal al proceso destino.

`kill` es una función del sistema (y también un comando en la terminal) que permite enviar una señal a un proceso o a un grupo de procesos. Estas señales son notificaciones asíncronas que el sistema operativo utiliza para comunicar eventos a los procesos, por ejemplo, para interrumpirlos, terminarlos o realizar acciones específicas definidas en los handlers del proceso receptor.

`int	kill(pid_t pid, int sig);`

## Procesos y PID

Un proceso es el mecanismo de trabajo de un programa que se esta ejecutando actualmente. Cuando se crea un proceso el sistema (kernel) le asigna un proceso de identificación único (PID). Cuando un proceso muere su PID vuelve al pool para que este disponible y otro proceso puede luego reutilizarlo.

Con los comando `ps` y `top` se pueden ver los PID actuales en el sistema.

Los procesos tienen un tipo de comportamiento determinado por unos atributos.

- Term
- Ign
- Core
- Stop
- Cont

Estos atributos determinan el comportamiento de la señal cuando es entregada. El comportamiento por defecto es terminar el proceso.

## Manejar señales `sigaction`

`sigaction` es una llamada al sistema que permite establecer un nuevo comportamiento (handler) para una señal determinada. A diferencia de signal, sigaction ofrece mayor control y flexibilidad, permitiéndote especificar:

- Una función manejadora de la señal.
- Un conjunto de señales que se bloquearán mientra se ejecuta el handler.

`int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`

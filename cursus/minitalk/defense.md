# minitalk

## ¿Qué es una señal en Unix?

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


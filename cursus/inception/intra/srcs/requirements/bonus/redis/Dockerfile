# Base image: alpine 3.22 (Consistent with the rest of the Inception stack)
FROM alpine:3.22

# Update package lists, upgrade system, and install Redis without caching index locally
RUN apk update && apk upgrade && \
    apk add --no-cache redis

# Copiar el archivo de configuración personalizado al contenedor
COPY conf/redis.conf /etc/redis.conf

# Exponer el puerto por defecto de Redis (solo internamente a la red de Docker)
EXPOSE 6379

# Iniciar el servidor Redis en foreground usando nuestra configuración como PID 1
CMD ["redis-server", "/etc/redis.conf"]

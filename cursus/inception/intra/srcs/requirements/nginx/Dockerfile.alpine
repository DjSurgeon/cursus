# 1. Imagen base
FROM alpine:3.22

# 2. Instalar NGINX y las herramientas para crear certificados de seguridad
RUN apk update && apk add --no-cache nginx openssl

# 3. Crear el directorio donde guardaremos los certificados
RUN mkdir -p /etc/nginx/ssl

# 4. Generar el certificado SSL autofirmado (El candado del HTTPS)
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=42/CN=serjimen.42.fr"

# 5. Copiar nuestro archivo de configuración personalizado
COPY conf/nginx.conf /etc/nginx/nginx.conf

# 6. Exponer SOLAMENTE el puerto 443 
EXPOSE 443

# 7. Arrancar NGINX en primer plano (PID 1)
CMD ["nginx", "-g", "daemon off;"]
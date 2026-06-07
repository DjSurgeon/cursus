# Base image: alpine 3.22 (Consistent with the rest of the Inception stack)
FROM alpine:3.22

# Update package lists, upgrade system, and install Redis without caching index locally
RUN apk update && apk upgrade && \
    apk add --no-cache redis

# TODO: Add configuration, entrypoint script and expose port

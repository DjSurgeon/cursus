FROM alpine:3.22

# Instalar Grafana
RUN apk add --no-cache grafana

# Copiar el aprovisionamiento de Datasource (Prometheus)
COPY conf/datasource.yml /usr/share/grafana/conf/provisioning/datasources/

# Copiar el aprovisionamiento de Dashboards (El puntero al JSON)
COPY conf/dashboards.yml /usr/share/grafana/conf/provisioning/dashboards/

# Copiar el JSON del dashboard de MariaDB
COPY conf/mariadb.json /usr/share/grafana/public/dashboards/

# Puerto por defecto de Grafana
EXPOSE 3000

# Aseguramos que se ejecuta en foreground (PID 1)
ENTRYPOINT ["/usr/sbin/grafana-server", "--homepath=/usr/share/grafana"]

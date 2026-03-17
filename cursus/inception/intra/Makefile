# Variables
LOGIN       ?= serjimen
DATA_PATH    = /home/$(LOGIN)/data
COMPOSE_FILE = srcs/docker-compose.yml
D_COMPOSE    = docker compose -f $(COMPOSE_FILE)

# Colors
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RED     = \033[0;31m
BLUE    = \033[0;34m
NC      = \033[0m

# Default rule
all: help

# Help menu
help:
	@echo -e "$(BLUE)Inception Infrastructure Orchestrator$(NC)"
	@echo -e ""
	@echo -e "$(YELLOW)Usage:$(NC) make [target]"
	@echo -e ""
	@echo -e "$(YELLOW)Targets:$(NC)"
	@echo -e "  $(GREEN)up$(NC)        Create data directories and start containers (build if needed)"
	@echo -e "  $(GREEN)down$(NC)      Stop and remove containers and networks"
	@echo -e "  $(GREEN)restart$(NC)   Restart all services"
	@echo -e "  $(GREEN)ps$(NC)        List containers and their status"
	@echo -e "  $(GREEN)logs$(NC)      Show real-time logs for all services"
	@echo -e "  $(GREEN)clean$(NC)     Stop and remove containers, networks, images, and volumes"
	@echo -e "  $(GREEN)fclean$(NC)    Full clean: clean + remove host data directories ($(RED)DANGER$(NC))"
	@echo -e "  $(GREEN)re$(NC)        Full restart (fclean + up)"

# Infrastructure management
up:
	@echo -e "$(BLUE)Creating data volumes at $(DATA_PATH)...$(NC)"
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	@echo -e "$(BLUE)Building and starting containers...$(NC)"
	@$(D_COMPOSE) up -d --build

down:
	@echo -e "$(YELLOW)Stopping containers...$(NC)"
	@$(D_COMPOSE) down

restart:
	@echo -e "$(BLUE)Restarting containers...$(NC)"
	@$(D_COMPOSE) restart

# Monitoring
ps:
	@$(D_COMPOSE) ps

logs:
	@$(D_COMPOSE) logs -f

# Cleanup
clean:
	@echo -e "$(YELLOW)Cleaning up Docker resources...$(NC)"
	@$(D_COMPOSE) down --rmi all --volumes --remove-orphans

fclean: clean
	@echo -e "$(RED)Removing host data directories...$(NC)"
	@sudo rm -rf $(DATA_PATH)

re: fclean up

.PHONY: all help up down restart ps logs clean fclean re
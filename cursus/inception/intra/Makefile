# Enable Docker BuildKit
export DOCKER_BUILDKIT=1
export COMPOSE_DOCKER_CLI_BUILD=1

# Variables
LOGIN        ?= $(shell whoami)
DATA_PATH     = /home/$(LOGIN)/data
COMPOSE_FILE  = srcs/docker-compose.yml
D_COMPOSE     = docker compose -f $(COMPOSE_FILE)

# Colors
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RED     = \033[0;31m
BLUE    = \033[0;34m
NC      = \033[0m

# Default rule
all: up

up:
	@echo -e "$(BLUE)Creating data volumes at $(DATA_PATH)...$(NC)"
	@sudo mkdir -p $(DATA_PATH)/mariadb
	@sudo mkdir -p $(DATA_PATH)/wordpress
	@sudo chown -R $(LOGIN):$(LOGIN) $(DATA_PATH)
	@echo -e "$(BLUE)Building and starting containers using $(COMPOSE_FILE)...$(NC)"
	@$(D_COMPOSE) up -d --build
	@echo -e "$(GREEN)Infrastructure deployed successfully!$(NC)"

bonus:
	@echo -e "$(BLUE)Creating data volumes at $(DATA_PATH)...$(NC)"
	@sudo mkdir -p $(DATA_PATH)/mariadb
	@sudo mkdir -p $(DATA_PATH)/wordpress
	@sudo chown -R $(LOGIN):$(LOGIN) $(DATA_PATH)
	@echo -e "$(BLUE)Building and starting containers (MANDATORY + BONUS) using $(COMPOSE_FILE)...$(NC)"
	@$(D_COMPOSE) --profile bonus up -d --build
	@echo -e "$(GREEN)Infrastructure with bonus deployed successfully!$(NC)"

down:
	@echo -e "$(YELLOW)Stopping containers...$(NC)"
	@$(D_COMPOSE) --profile bonus down

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
	@$(D_COMPOSE) --profile bonus down --rmi all --volumes --remove-orphans

fclean: clean
	@echo -e "$(RED)Removing host data directories...$(NC)"
	@sudo rm -rf $(DATA_PATH)
	@echo -e "$(GREEN)Full cleanup complete. Ready for a pristine build.$(NC)"

re: fclean all

.PHONY: all up bonus down restart ps logs clean fclean re
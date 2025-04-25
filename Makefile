NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread

SRCDIR = srcs
SRCBONUSDIR = srcs_bonus
INCLUDEDIR = includes
OBJS_DIR = objs
OBJS_BONUS_DIR = objs_bonus


FILES = main.c helpers.c initialize_global_info.c initialize_philos_and_start.c join_and_destroy.c \
	error_msg.c actions.c print-main.c print-utils.c supervisor.c \

FILES_BONUS = main_bonus.c  \

SRCS = $(addprefix $(SRCDIR)/, $(FILES))

SRCS_BONUS = $(addprefix $(SRCBONUSDIR)/, $(FILES_BONUS))

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJS_DIR)/%.o)

OBJS_BONUS = $(SRCS_BONUS:$(SRCBONUSDIR)/%.c=$(OBJS_BONUS_DIR)/%.o)

INCLUDES = -I$(INCLUDEDIR)

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_BONUS_DIR):
	mkdir -p $(OBJS_BONUS_DIR)

$(OBJS_DIR)/%.o: $(SRCDIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_BONUS_DIR)/%.o: $(SRCBONUSDIR)/%.c | $(OBJS_BONUS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	# $(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $@

$(NAME)_bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME)_bonus

clean:
	rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)

fclean: clean
	rm -f $(NAME) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re bonus

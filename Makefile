# -*- MakeFile -*-

TARGET = push_swap
SRCS = main.c linked_list.c str_util.c display_util.c std_util.c stack_util.c \
		 swap_util.c push_util.c rotate_util.c sort_util.c info_util.c small_sort.c \
		 large_sort.c
OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	touch output.txt trials.txt

test:
	@echo $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
re: fclean all

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re
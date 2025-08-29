NAME = clapTrap

CPPFLAGS = -Wall -Wextra -Werror -std=c++11

CC = c++

OBJ_DIR = obj

SRC = main.cpp ClapTrap.cpp

# Object files corresponding to the source files
OBJECTS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Default target - create executable
all: $(NAME) 

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
# Create the necessary subdirectories # Compile .cpp to .o
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@) 
	@$(CC) $(CPPFLAGS) -c $< -o $@

# Link the object files to create the final executable
$(NAME): $(OBJECTS)
	@$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)
	@echo "Executable created: $(NAME)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "OBJECT FILES REMOVED"
	
fclean: clean
	@rm -f $(NAME)
	@echo "Executable Removed"

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

# Mark targets that don't produce files as phony
.PHONY: all clean fclean re

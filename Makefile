FT			= ft
STD 		= std

INCLUDES	= -I./includes/

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

all : vector stack map set

comp : compst compv compm comps

STACK_NAME	= stack
STACK_FT_NAME = stack_ft
STACK_STD_NAME = stack_std
STACK_SRC = srcs/main_stack.cpp

$(STACK_NAME) : $(STACK_FT_NAME) $(STACK_STD_NAME) 

$(STACK_FT_NAME) : $(STACK_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(FT) $(STACK_SRC) -o $(STACK_FT_NAME)
	@echo "$(STACK_FT_NAME) created"

$(STACK_STD_NAME) : $(STACK_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(STD) $(STACK_SRC) -o $(STACK_STD_NAME)
	@echo "$(STACK_STD_NAME) created"

compst : $(STACK_NAME)
	@mkdir -p logs
	@./$(STACK_FT_NAME) > logs/ft_stack.log
	@./$(STACK_STD_NAME) > logs/std_stack.log
	@echo "--------- Stack diff ---------"
	@diff logs/ft_stack.log logs/std_stack.log  

VECTOR_NAME	= vector
VECTOR_FT_NAME = vector_ft
VECTOR_STD_NAME = vector_std
VECTOR_SRC = srcs/main_vector.cpp

$(VECTOR_NAME) : $(VECTOR_FT_NAME) $(VECTOR_STD_NAME)

$(VECTOR_FT_NAME) : $(VECTOR_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(FT) $(VECTOR_SRC) -o $(VECTOR_FT_NAME)
	@echo "$(VECTOR_FT_NAME) created"

$(VECTOR_STD_NAME) : $(VECTOR_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(STD) $(VECTOR_SRC) -o $(VECTOR_STD_NAME)
	@echo "$(VECTOR_STD_NAME) created"

compv : $(VECTOR_NAME)
	@mkdir -p logs
	@./$(VECTOR_FT_NAME) > logs/ft_vector.log
	@./$(VECTOR_STD_NAME) > logs/std_vector.log
	@echo "--------- Vector diff ---------"
	@diff logs/ft_vector.log logs/std_vector.log

MAP_NAME	= map
MAP_FT_NAME = map_ft
MAP_STD_NAME = map_std
MAP_SRC = srcs/main_map.cpp

$(MAP_NAME) : $(MAP_FT_NAME) $(MAP_STD_NAME)

$(MAP_FT_NAME) : $(MAP_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(FT) $(MAP_SRC) -o $(MAP_FT_NAME)
	@echo "$(MAP_FT_NAME) created"

$(MAP_STD_NAME) : $(MAP_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(STD) $(MAP_SRC) -o $(MAP_STD_NAME)
	@echo "$(MAP_STD_NAME) created"

compm : $(MAP_NAME)
	@mkdir -p logs
	@./$(MAP_FT_NAME) > logs/ft_map.log
	@./$(MAP_STD_NAME) > logs/std_map.log
	@echo "--------- Map diff ---------"
	@diff logs/ft_map.log logs/std_map.log

SET_NAME	= set
SET_FT_NAME = set_ft
SET_STD_NAME = set_std
SET_SRC = srcs/main_set.cpp

$(SET_NAME) : $(SET_FT_NAME) $(SET_STD_NAME)

$(SET_FT_NAME) : $(SET_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(FT) $(SET_SRC) -o $(SET_FT_NAME)
	@echo "$(SET_FT_NAME) created"

$(SET_STD_NAME) : $(SET_SRC)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -D NS=$(STD) $(SET_SRC) -o $(SET_STD_NAME)
	@echo "$(SET_STD_NAME) created"

comps : $(SET_NAME)
	@mkdir -p logs
	@./$(SET_FT_NAME) > logs/ft_set.log
	@./$(SET_STD_NAME) > logs/std_set.log
	@echo "--------- Set diff ---------"
	@diff logs/ft_set.log logs/std_set.log

clean: 
	rm -rf $(VECTOR_FT_NAME)
	rm -rf $(VECTOR_STD_NAME)
	rm -rf $(STACK_FT_NAME)
	rm -rf $(STACK_STD_NAME)
	rm -rf $(MAP_FT_NAME)
	rm -rf $(MAP_STD_NAME)
	rm -rf $(SET_FT_NAME)
	rm -rf $(SET_STD_NAME)

fclean: clean
	rm -rf logs
	
re: fclean all

.PHONY: all clean fclean re 

# A phony target is one that is not really the name of a file; 
# rather it is just a name for a recipe to be executed when you make an explicit request. 
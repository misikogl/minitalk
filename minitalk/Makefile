SERVER          =   server

SERVER_SRC      =   server.c

CLIENT          =   client

CLIENT_SRC      =   client.c

CC              =   gcc

RM              =   rm -rf

FLAGS           =   -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) :
			$(CC) $(FLAGS) $(SERVER_SRC) -o $(SERVER)

$(CLIENT) :
			$(CC) $(FLAGS) $(CLIENT_SRC) -o $(CLIENT)

fclean :
			$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all fclean re
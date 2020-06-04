##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##


NAMESRV	=	myteams_server
NAMECLI	=	myteams_cli

SRVDIR	=	server/src
CLIDIR	=	client/src
CMDDIR	=	commands/src
UTIDIR	=	utilities/src
BDDDIR	=	database/src

SRCSSRV	=	$(SRVDIR)/main.c							\
			$(SRVDIR)/parser.c							\
			$(SRVDIR)/inetinfo.c						\
			$(SRVDIR)/create.c							\
			$(SRVDIR)/accept.c							\
			$(SRVDIR)/disconnect.c						\
			$(UTIDIR)/my_clean_str.c					\
			$(UTIDIR)/my_strlen.c						\
			$(UTIDIR)/my_strcat.c						\
			$(UTIDIR)/my_uuid.c							\
			$(UTIDIR)/my_str_to_word_tab.c				\
			$(UTIDIR)/my_strcmp.c						\
			$(UTIDIR)/my_strndup.c						\
			$(UTIDIR)/my_dup_array.c					\
			$(UTIDIR)/my_free_array.c					\
			$(UTIDIR)/my_len_array.c					\
			$(UTIDIR)/my_print_to_file.c				\
			$(UTIDIR)/my_str_to_word_array.c			\
			$(UTIDIR)/fs_open_file.c					\
			$(UTIDIR)/my_check_arguments.c				\
			$(UTIDIR)/my_intostr.c						\
			$(CMDDIR)/user/my_user.c					\
			$(CMDDIR)/user/my_users.c					\
			$(CMDDIR)/use/my_use.c						\
			$(CMDDIR)/unsubscribe/my_unsubscribe.c		\
			$(CMDDIR)/subscribe/my_subscribe.c			\
			$(CMDDIR)/subscribe/my_subscribed.c			\
			$(CMDDIR)/message/my_messages.c				\
			$(CMDDIR)/message/my_send.c					\
			$(CMDDIR)/logout/my_logout.c				\
			$(CMDDIR)/login/my_login.c					\
			$(CMDDIR)/login/my_check_user_id.c			\
			$(CMDDIR)/list/my_list.c					\
			$(CMDDIR)/info/my_info.c					\
			$(CMDDIR)/help/my_help.c					\
			$(CMDDIR)/create/my_create.c				\
			$(SRVDIR)/write.c							\
			$(BDDDIR)/bdd.c								\
			$(BDDDIR)/my_bdd.c							\
			$(BDDDIR)/strings_formater.c				\
			$(BDDDIR)/my_struct_bdd.c					\


SRCSCLI	=	$(CLIDIR)/main.c						\
			$(CLIDIR)/parser.c						\
			$(CLIDIR)/accept.c						\
			$(CLIDIR)/create.c						\
			$(CLIDIR)/my_functions/login.c			\
			$(CLIDIR)/my_functions/message.c		\
			$(CLIDIR)/my_functions/print_create.c	\
			$(UTIDIR)/my_clean_str.c				\
			$(UTIDIR)/my_strlen.c					\
			$(UTIDIR)/my_strcat.c					\
			$(UTIDIR)/my_uuid.c						\
			$(UTIDIR)/my_str_to_word_tab.c			\
			$(UTIDIR)/my_strcmp.c					\
			$(UTIDIR)/my_strndup.c					\
			$(UTIDIR)/my_dup_array.c				\
			$(UTIDIR)/my_free_array.c				\
			$(UTIDIR)/my_len_array.c				\
			$(UTIDIR)/my_print_to_file.c			\
			$(UTIDIR)/my_str_to_word_array.c		\
			$(UTIDIR)/my_intostr.c					\
			$(UTIDIR)/fs_open_file.c				\

INCLUDES	=	-I ./server/include/ -I ./client/include/ -I ./utilities/include -I ./commands/include/ -I ./libs/myteams/

CFLAGS	+=	-W -Wall -Wextra -Werror $(INCLUDES) -ggdb3 -luuid -L./libs/myteams -lmyteams

CC	=	gcc

RM	=	rm -f

OBJSSRV	=	$(SRCSSRV:.c=.o)
OBJSCLI	=	$(SRCSCLI:.c=.o)

%.o: %.c
		$(CC) -c -o $@ $< $(CFLAGS)

all:		myteams_server myteams_cli

srv:		$(NAMESRV)

cli:	$(NAMECLI)

$(NAMESRV):	$(OBJSSRV)
		$(CC) $(OBJSSRV) -o $(NAMESRV) -luuid -L./libs/myteams -lmyteams

$(NAMECLI):	$(OBJSCLI)
		$(CC) $(OBJSCLI) -o $(NAMECLI) -luuid -L./libs/myteams -lmyteams

clean:
		rm -f $(OBJSSRV)
		rm -f $(OBJSCLI)
		rm -f $(OBJSCMD)
		rm -f $(OBJSUTI)

fclean:		clean
		rm -f $(NAMESRV)
		rm -f $(NAMECLI)

re:		fclean all

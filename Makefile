DIRS := day*/ex*

all clean fclean:
	for dir in $(DIRS); do \
		${MAKE} -C $$dir $@; \
	done

re: fclean all

.PHONY: all clean fclean re
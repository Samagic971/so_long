all: 
	make -C main_part

bonus :
	make -C bonus_part

clean:
	@make clean -C main_part
	@make clean -C bonus_part

fclean:
	@make fclean -C main_part
	@make fclean -C bonus_part

re:			fclean	all

re_bonus:	fclean	bonus

.PHONY:		all clean fclean re re_bonus

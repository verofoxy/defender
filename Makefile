##
## EPITECH PROJECT, 2019
## Lib my
## File description:
## Makefile
##

.PHONY	=	all my_defender libs init clean fclean re

CC	=	gcc

DEBUG_FLAGS = -g3 -ggdb

CFLAGS	=	-W -Wall -Wextra
ifeq ($(DEBUG), yes)
	CFLAGS	:= $(CFLAGS) $(DEBUG_FLAGS)
endif
CPPFLAGS	:=	-I./include
LFLAGS	+=	-L./lib/my -lmy	\
			-L./lib/list -llist \
			-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window \
			-lm

SRC	:=	src/main.c \
		src/engine/scenes/scene.c \
		src/engine/scenes/scene1.c \
		src/engine/scenes/shop_menu/shop.c \
		src/engine/scenes/pause_menu/pause.c \
		src/engine/scenes/main_menu/main_menu.c \
		src/engine/scenes/main_menu/buttons.c\
		src/engine/scenes/main_menu/buttons_2.c\
		src/engine/scenes/main_menu/manage_event.c\
		src/engine/system/game_system.c \
		src/engine/window/window.c \
		src/engine/animations/animation.c \
		src/engine/animations/animation_part1.c \
		src/engine/res/image/image.c \
		src/engine/res/objects/entity.c \
		src/engine/res/objects/hitbox.c \
		src/engine/res/objects/stat.c \
		src/engine/res/objects/game_object.c \
		src/engine/res/objects/enemy/wave_generator.c \
		src/engine/res/objects/enemy/wave.c \
		src/engine/res/objects/enemy/move.c \
		src/engine/res/objects/enemy/deplacement.c \
		src/engine/res/objects/buildings/entity_canon.c \
		src/engine/res/objects/buildings/entity_slow_tower.c \
		src/engine/res/objects/buildings/entity_archer.c \
		src/engine/res/objects/enemy/entity_enemy_fly.c \
		src/engine/res/objects/enemy/entity_enemy_shrimp.c \
		src/engine/map/tilemap_cutter.c \
		src/engine/map/create_map.c \
		src/engine/res/ui/btns.c \
		src/engine/res/ui/activity_btn.c \
		src/engine/res/objects/buildings/entity_booster.c \
		src/engine/path_filing/path.c \
		src/engine/path_filing/find.c \
		src/engine/map/tower_locations.c \
		src/engine/res/objects/collision.c \
		src/engine/res/objects/buildings/building.c \
		src/engine/res/text/label.c \
		src/engine/scenes/shop_menu/shop_callback.c \
		src/engine/scenes/shop_menu/shop_btns.c \
		src/engine/scenes/level.c \
		src/engine/res/objects/enemy/enemy.c \
		src/engine/scenes/pause_menu/pause_btns.c \
		src/engine/scenes/pause_menu/pause_callback.c \
		src/engine/res/sounds/sound.c \
		src/engine/scenes/gameover_menu/gameover.c \
		src/engine/scenes/gameover_menu/gameover_callback.c \
		src/engine/scenes/gameover_menu/btn_gameover_menu.c \
		src/engine/scenes/gameover_menu/struct_gameover.c\
		src/engine/scenes/victory_menu/btn_victory_menu.c\
		src/engine/scenes/victory_menu/victory_menu.c\
		src/engine/scenes/victory_menu/struct_victory.c\
		src/engine/scenes/victory_menu/victory_callback.c \
		src/engine/scenes/credits_scene/credits_scene.c \
		src/engine/scenes/how_to_play/how_scene.c

OBJ	=	$(SRC:.c=.o)
OBJ_PATH	:=	./obj

NAME	=	my_defender

LIBS	=	libs

all: $(NAME)

get_obj	=	$(OBJ_PATH)/$(notdir $(1))

$(NAME):	$(LIBS) $(OBJ)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) \
	$(foreach obj, $(OBJ), $(call get_obj,$(obj))) $(LFLAGS) && \
	echo -e "\e[1m\e[32m******** Compilation completed ********\033[0m" || \
    echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"

%.o:	%.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(LFLAGS) &&  \
	echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" && \
    mv $@ $(OBJ_PATH)/$(notdir $@) || \
    echo -e "\e[91;5m[KO]\e[25m" $<  : Compilation failed "\033[5m\e[0m\n"

$(LIBS):
	@make -C lib/my
	@make -C lib/list

init:
	@touch .gitignore && \
	mkdir obj src lib include && \
	echo -e "\e[32m[OK] Project basics initialized" \
	"\033[0m\e[1m\e[32m\033[0m" || echo -e \
	"\e[31m[OK] Project basics already initialized \033[0m\e[1m\e[32m\033[0m"

clean:
	rm -f $(foreach wrd, $(OBJ), $(call get_obj,$(wrd)))

fclean: clean
	@make -C lib/my/ fclean
	@make -C lib/list fclean
	rm -f $(NAME)

re: clean all

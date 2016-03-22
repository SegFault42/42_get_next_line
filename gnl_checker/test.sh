#!/bin/bash

echo "\033[33m--------------------------Norme--------------------------\033[0m"

norminette *.[ch]

echo "\033[33m-----------------------Préliminaires---------------------\033[0m"

if [ -f "../auteur" ]
then
	echo "\033[32mauteur found :\033[0m"
	cat -e ../auteur
else
	echo "\033[31mauteur not found\033[0m"
fi

if [ -f "../get_next_line.c" ]
then
	echo "\033[32mget_next_line.c found\033[0m"
else
	echo "\033[31mget_next_line.c not found\033[0m"
fi

if [ -f "../get_next_line.h" ]
then
	echo "\033[32mget_next_line.h found\033[0m"
else
	echo "\033[31mget_next_line.h not found\033[0m"
fi

echo "\033[33m\nVerification de la presence de BUFF_SIZE dans get_next_line.h\033[0m"
grep 'BUFF_SIZE' ../get_next_line.h
retval=$?
if [ "$retval" = 0 ]
then echo "\033[32mBUFF_SIZE found\n\033[0m"
else
echo "\033[31mBUFF_SIZE not found\n\033[0m"
fi
# end

echo "\033[33m--------------Verification contenue dossier--------------\033[0m"
cd ../
ls -la
cd gnl_checker


echo "\033[33m---------------------------TESTS-------------------------\033[0m"

sed -i '' 's/^\# define BUFF_SIZE.*/\# define BUFF_SIZE 8/' ../get_next_line.h
cat ../get_next_line.h
echo "\033[32m\nBUFF_SIZE defined to 8\033[0m\n"

make -C ../libft/ fclean && make -C ../libft/

echo "\033[32mCompilation gnl OK\033[0m"
gcc -Wall -Wextra -Werror -o gnl ../main.c ../get_next_line.c ../libft/libft.a

echo "\033[33m\nVerification fonction interdite\033[0m"
nm -j ./gnl | cut -c 2-

echo "\033[36m\n- Lire et retourner une ligne de 8 caractères terminée par un '\ n' inclus depuis l'entrée standard.\n\033[0m"
"echo -n "01234657" | ./gnl"

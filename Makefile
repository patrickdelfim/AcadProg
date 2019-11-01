# _*_ Makefile _*_

# Nome do projeto
PROJ_NAME=AcadProg

# Nome da pasta de source code
SOURCE_FOLDER=$(wildcard ./sources/)

# Arquivos .c
C_SOURCE=$(wildcard ./sources/*.c)

# Nome da pasta das biblioteca
LIB_FOLDER=$(wildcard ./lib/)
# Arquivos .h
H_SOURCE=$(wildcard ./lib/*.h)

# Nome da pasta de objetos (Assembly)
OBJ_FOLDER=$(wildcard ./objects/)
# Aquivos de objetos
OBJ=$(subst .c,.o,$(subst sources,objects,$(C_SOURCE)))

# Compilador e linkador
CC=gcc

# Flags para o compilador
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -pedantic

# Comando para limpar usado no clean target
RM = rm -rf

#
# Processo de compilacao e linkamento
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Construindo binario usando GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Processo de construcao completa: $@'
	@ echo ' '

./objects/%.o: ./sources/%.c ./lib/%.h
	@ echo 'Construindo target usando GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./sources/main.c $(H_SOURCE)
	@ echo 'Construindo target usando GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) $(OBJ_FOLDER)*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean

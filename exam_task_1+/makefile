# make mode=debug (или release)

# Компилятор
CC := gcc
# Флаги компиляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Iinc
# Флаги для Valgrind
VAL_FLAGS := --leak-check=full --quiet  --show-leak-kinds=all --track-origins=yes

# Каталоги
OUT := out/
SRC := src/
INC := inc/
# Список исходных файлов в каталоге SRC
SRC_FILES := $(wildcard $(SRC)*.c)
# Список объектных файлов из исходных файлов
OBJ_SRC_FILES := $(SRC_FILES:$(SRC)%.c=$(OUT)%.o)

# Отладочная сборка: добавим генерацию отладочной информации
ifeq ($(mode), debug)
	CFLAGS += -g3
endif
# Финальная сборка: исключим отладочную информацию и утверждения (asserts)
ifeq ($(mode), release)
	CFLAGS += -g0
endif

# Дополнительные флаги для ubuntu
ifeq ($(shell grep -o "^ID=.*" /etc/os-release | cut -d'=' -f2), ubuntu)
	LDFLAGS += -lsubunit
endif

# Компиляция программы
app.exe: $(OBJ_SRC_FILES)
	$(CC) -o $@ $^

# Правило компиляции объектных файлов из исходных файлов
$(OUT)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Запуск программы
.PHONY: run
run: app.exe
	./app.exe

# Запуск Valgrind для проверки утечек памяти
.PHONY: check
check: app.exe test.txt test_ans.txt
	valgrind $(VAL_FLAGS) ./app.exe < test.txt > test_out.txt

# Очистка исполняемых и объектных файлов
.PHONY: clean
clean:
	rm *.exe $(OUT)*.o

# Закомментированная строка для генерации зависимостей
# $(CC) -MM -Iinc $(SRC)*.c
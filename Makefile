# Определение операционной системы
ifeq ($(OS),Windows_NT)
    SYSTEM := Windows
    TARGET_EXT := .exe
    RM := del /Q
    MKDIR := mkdir
    SEP := \\
else
    SYSTEM := Unix
    TARGET_EXT :=
    RM := rm -rf
    MKDIR := mkdir -p
    SEP := /
endif

# Компилятор и флаги
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -pedantic
TESTFLAGS := -lgtest -lgtest_main -lpthread  # Флаги для Google Test

# Директории
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := tests

# Исходные файлы и объекты
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Тесты
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRCS))
TEST_EXES := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%$(TARGET_EXT),$(TEST_SRCS))

# Целевой исполняемый файл
TARGET := task$(TARGET_EXT)

# Основные цели
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Правила компиляции
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Сборка тестов
$(OBJ_DIR)/%$(TARGET_EXT): $(OBJ_DIR)/%.o $(filter-out $(OBJ_DIR)/main.o,$(OBJS))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(TESTFLAGS)

# Создание директорий
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Запуск тестов
test: $(TEST_EXES)
ifeq ($(SYSTEM),Windows)
	@for test in $(TEST_EXES); do \
		$$test; \
	done
else
	@for test in $(TEST_EXES); do \
		./$$test; \
	done
endif

# Очистка
clean:
ifeq ($(SYSTEM),Windows)
	$(RM) $(TARGET)
	$(RM) $(subst /,$(SEP),$(OBJ_DIR))
else
	$(RM) $(TARGET) $(OBJ_DIR)
endif

rebuild: clean all

.PHONY: all test clean rebuild
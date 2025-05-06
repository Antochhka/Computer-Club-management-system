# Компилятор и флаги
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -pedantic
TESTFLAGS := -lgtest -lgtest_main -pthread  # Флаги для тестов

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
TEST_EXES := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%,$(TEST_SRCS))

# Целевой исполняемый файл
TARGET := task

# Основные цели
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Правила компиляции
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Сборка тестов (с добавлением TESTFLAGS)
$(OBJ_DIR)/%: $(OBJ_DIR)/%.o $(filter-out $(OBJ_DIR)/main.o,$(OBJS))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(TESTFLAGS)

# Создание директорий
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Запуск тестов
test: $(TEST_EXES)
	@for test in $(TEST_EXES); do \
		echo "Running $$test..."; \
		./$$test; \
	done

# Очистка
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)

rebuild: clean all

.PHONY: all test clean rebuild
# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

# Список всех исходных файлов
SRCS = array.cpp dlist.cpp hash_table.cpp list.cpp queue.cpp stack.cpp tree.cpp

# Список всех тестов
TESTS = array_test.cpp dlist_test.cpp hash_table_test.cpp list_test.cpp queue_test.cpp stack_test.cpp tree_test.cpp main_test.cpp

# Соответствующие объектные файлы
OBJS = $(SRCS:.cpp=.o) $(TESTS:.cpp=.o)

# Цель по умолчанию
all: MyProject

# Правило для сборки исполняемого файла
MyProject: $(OBJS)
	$(CXX) $(CXXFLAGS) -o MyProject $(OBJS) -lgtest -lgtest_main -pthread

# Правила для сборки объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка скомпилированных файлов
clean:
	rm -f *.o MyProject

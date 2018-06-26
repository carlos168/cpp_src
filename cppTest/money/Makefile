CC=g++ 
FLAGS=-W -g
FLAGS_TST=-W -g 

INCLUDES=-I./

SONAME=money.so
TARGET=money.so
SONAME_TST=money_tst.so
TARGET_TST=money_tst.so
    
OBJS=$(patsubst %.cpp,obj/%.o,$(wildcard *.cpp))
OBJS_TST=$(patsubst %.cpp,obj/%.lo,$(wildcard *.cpp))

obj/%.o: %.cpp
	$(CC) $(FLAGS) $(INCLUDES)  -c $< -o $@
obj/%.lo: %.cpp
	$(CC) $(FLAGS_TST) $(INCLUDES)  -c $< -o $@
    
$(TARGET): $(OBJS)
	$(CC) -shared -fpic -Wl,-soname,$(SONAME) -o $(TARGET) $(OBJS) 
	cp $(TARGET) ./bin/
	cp $(TARGET) ./bin/

api_tst: $(OBJS_TST)
	$(CC) -shared -fpic -Wl,-soname,$(SONAME_TST) -o $(TARGET_TST) $(OBJS_TST) $(LIBS_TST)

init:
	mkdir -p obj
    
clean:
	-rm obj/*

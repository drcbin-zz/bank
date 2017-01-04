# this is makefile
CPPS = $(wildcard ./*.cpp)
OS = $(patsubst %.cpp, %.o, $(CPPS))
DS = $(patsubst %.o, %.d, $(OS))
EXE = main
$(EXE): $(OS) $(HS)
	g++ -std=c++11 $(OS) $(HS) -o $(EXE) -lpthread
%.o: %.cpp
	g++ -std=c++11 -c -MMD  $< -o $@ -lpthread

-include $(DS)

clean:
	@rm $(EXE) $(OS) $(DS)


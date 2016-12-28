# this is makefile
CPPS = $(wildcard ./*.cpp)
OS = $(patsubst %.cpp, %.o, $(CPPS))
DS = $(patsubst %.o, %.d, $(OS))
EXE = main


$(EXE): $(OS) $(HS)
	g++ -std=c++11 $(OS) $(HS) -fPIC -shared -o $(EXE) -lpthread
%.o: %.cpp
	g++ -std=c++11 -c -fPIC -MMD  $< -o $@ -lpthread

-include $(DS)

# Ticket.o:Ticket.cpp
	# g++ -c Ticket.cpp
# Customer.o:Customer.cpp
	# g++ -c Customer.cpp
# 为什么不能把上述的两个cpp一起编译呢? 因为Customer里面需要用到Ticket,而Ticker和main又没有直接的联系


clean:
	@rm $(EXE) $(OS) $(DS)


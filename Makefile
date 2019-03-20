OPTS = -Wall -std=c++11 -pthread

all: readGraph.o shortestPath.o BinaryHeap.o

tests: readGraph_TEST shortestPath_TEST BinaryHeap_TEST

readGraph.o: readGraph.cpp readGraph.hpp
	g++ ${OPTS} -c readGraph.cpp

shortestPath.o: shortestPath.cpp shortestPath.hpp
	g++ ${OPTS} -c shortestPath.cpp

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.hpp
	g++ ${OPTS} -c BinaryHeap.cpp

readGraph_TEST: readGraph_TEST.cpp readGraph.cpp readGraph.hpp catch.hpp
	g++ ${OPTS} --coverage -o readGraph_TEST readGraph_TEST.cpp readGraph.cpp

shortestPath_TEST: shortestPath_TEST.cpp readGraph.o shortestPath.cpp shortestPath.hpp BinaryHeap.o catch.hpp
	g++ ${OPTS} --coverage -o shortestPath_TEST shortestPath_TEST.cpp readGraph.o shortestPath.cpp BinaryHeap.o

BinaryHeap_TEST: BinaryHeap_TEST.cpp BinaryHeap.cpp BinaryHeap.hpp catch.hpp
	g++ ${OPTS} --coverage -o BinaryHeap_TEST BinaryHeap_TEST.cpp BinaryHeap.cpp

bellmanFord: bellmanFord.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o bellmanFord bellmanFord.cpp readGraph.o shortestPath.o BinaryHeap.o

currency: currency.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o currency currency.cpp readGraph.o shortestPath.o BinaryHeap.o

parallelDijkstra: parallelDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o parallelDijkstra parallelDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

matrixDijkstra: matrixDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o matrixDijkstra matrixDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

listDijkstra: listDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o listDijkstra listDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

mapqueue: mapqueue.cpp
	g++ ${OPTS} -o mapqueue mapqueue.cpp

clean:
	rm -f *.o *.gcov *.gcda *.gcno readGraph_TEST BinaryHeap_TEST shortestPath_TEST bellmanFord parallelDijkstra currency matrixDijkstra listDijkstra mapqueue

cleancov:
	rm -f -r *.gcda *.gcno *.gcov *.info coverage

cleanemacs:
	rm *~

ParrDij:
	make clean
	make parallelDijkstra
	./parallelDijkstra graph.txt output.txt LicoriceCastle CandyCastle 2

Matrix:
	make clean
	make matrixDijkstra
	./matrixDijkstra graph.txt output.txt GingerbreadPlumTrees CandyCastle
	./matrixDijkstra graph.txt output.txt GingerbreadPlumTrees LicoriceCastle
	./matrixDijkstra graph.txt output.txt GingerbreadPlumTrees PeanutBrittleHouse
	./matrixDijkstra graph.txt output.txt CandyCastle GingerbreadPlumTrees
	./matrixDijkstra graph.txt output.txt CandyCastle LicoriceCastle
	./matrixDijkstra graph.txt output.txt CandyCastle PeanutBrittleHouse
	./matrixDijkstra graph.txt output.txt LicoriceCastle GingerbreadPlumTrees
	./matrixDijkstra graph.txt output.txt LicoriceCastle CandyCastle
	./matrixDijkstra graph.txt output.txt LicoriceCastle PeanutBrittleHouse
	./matrixDijkstra graph.txt output.txt PeanutBrittleHouse GingerbreadPlumTrees
	./matrixDijkstra graph.txt output.txt PeanutBrittleHouse CandyCastle
	./matrixDijkstra graph.txt output.txt PeanutBrittleHouse LicoriceCastle



List:
	make clean
	make listDijkstra
#	./listDijkstra graph.txt output.txt GingerbreadPlumTrees GingerbreadPlumTrees
	./listDijkstra graph.txt output.txt GingerbreadPlumTrees CandyCastle
	./listDijkstra graph.txt output.txt GingerbreadPlumTrees LicoriceCastle
	./listDijkstra graph.txt output.txt GingerbreadPlumTrees PeanutBrittleHouse
	./listDijkstra graph.txt output.txt CandyCastle GingerbreadPlumTrees
#	./listDijkstra graph.txt output.txt CandyCastle CandyCastle
	./listDijkstra graph.txt output.txt CandyCastle LicoriceCastle
	./listDijkstra graph.txt output.txt CandyCastle PeanutBrittleHouse
	./listDijkstra graph.txt output.txt LicoriceCastle GingerbreadPlumTrees
	./listDijkstra graph.txt output.txt LicoriceCastle CandyCastle
#	./listDijkstra graph.txt output.txt LicoriceCastle LicoriceCastle
	./listDijkstra graph.txt output.txt LicoriceCastle PeanutBrittleHouse
	./listDijkstra graph.txt output.txt PeanutBrittleHouse GingerbreadPlumTrees
	./listDijkstra graph.txt output.txt PeanutBrittleHouse CandyCastle
	./listDijkstra graph.txt output.txt PeanutBrittleHouse LicoriceCastle
#	./listDijkstra graph.txt output.txt PeanutBrittleHouse PeanutBrittleHouse




Bell:
	make clean
	make bellmanFord
#	./bellmanFord graph.txt output.txt LicoriceCastle CandyCastle
	./bellmanFord graph2.txt output.txt v2 v5
#	./bellmanFord graph2.txt output.txt v3 v4
#	./bellmanFord graph2.txt output.txt v4 v4
#	./bellmanFord graph2.txt output.txt v1 v3
#	./bellmanFord graph2.txt output.txt v2 v3
#	./bellmanFord graph2.txt output.txt v3 v3
#	./bellmanFord graph2.txt output.txt v4 v3
#	./bellmanFord graph2.txt output.txt v1 v2
#	./bellmanFord graph2.txt output.txt v2 v2
#	./bellmanFord graph2.txt output.txt v3 v2
#	./bellmanFord graph2.txt output.txt v4 v2
#	./bellmanFord graph2.txt output.txt v1 v1
#	./bellmanFord graph2.txt output.txt v2 v1
#	./bellmanFord graph2.txt output.txt v3 v1
#	./bellmanFord graph2.txt output.txt v4 v1

Curr:
	make clean
	make currency
	./currency exchangerates.txt output.txt GBP EUR 0.001
	./currency exchangerates.txt output.txt GBP JPY 0.001
	./currency exchangerates.txt output.txt GBP CHF 0.001
	./currency exchangerates.txt output.txt GBP USD 0.001
	./currency exchangerates.txt output.txt GBP GLD 0.001
	./currency exchangerates.txt output.txt EUR GBP 0.001
	./currency exchangerates.txt output.txt EUR JPY 0.001
	./currency exchangerates.txt output.txt EUR CHF 0.001
	./currency exchangerates.txt output.txt EUR USD 0.001
	./currency exchangerates.txt output.txt EUR GLD 0.001
	./currency exchangerates.txt output.txt JPY EUR 0.001
	./currency exchangerates.txt output.txt JPY GBP 0.001
	./currency exchangerates.txt output.txt JPY CHF 0.001
	./currency exchangerates.txt output.txt JPY USD 0.001
	./currency exchangerates.txt output.txt JPY GLD 0.001
	./currency exchangerates.txt output.txt CHF EUR 0.001
	./currency exchangerates.txt output.txt CHF JPY 0.001
	./currency exchangerates.txt output.txt CHF GBP 0.001
	./currency exchangerates.txt output.txt CHF USD 0.001
	./currency exchangerates.txt output.txt CHF GLD 0.001
	./currency exchangerates.txt output.txt USD EUR 0.001
	./currency exchangerates.txt output.txt USD JPY 0.001
	./currency exchangerates.txt output.txt USD CHF 0.001
	./currency exchangerates.txt output.txt USD GBP 0.001
	./currency exchangerates.txt output.txt USD GLD 0.001
	./currency exchangerates.txt output.txt GLD EUR 0.001
	./currency exchangerates.txt output.txt GLD JPY 0.001
	./currency exchangerates.txt output.txt GLD CHF 0.001
	./currency exchangerates.txt output.txt GLD GBP 0.001
	./currency exchangerates.txt output.txt GLD USD 0.001

runtests:
	make clean
	make cleancov
	make tests
	
	./readGraph_TEST 
	./shortestPath_TEST 
	./BinaryHeap_TEST
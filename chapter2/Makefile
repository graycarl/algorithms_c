all: bubble insert merge quick heap count data

testall: testinsert testbubble testmerge testquick testheap testcount

data: createdata.sh
	rm -f data
	./createdata.sh

insert: main.c insertsort.c
	gcc main.c insertsort.c -o insert

testinsert: insert data
	./insert
	mv result result_insert

bubble: main.c bubblesort.c
	gcc main.c bubblesort.c -o bubble

testbubble: bubble data
	./bubble
	mv result result_bubble

merge: main.c mergesort.c
	gcc main.c mergesort.c -o merge

testmerge: merge data
	./merge
	mv result result_merge

quick: main.c quicksort.c
	gcc main.c quicksort.c -o quick	

testquick: quick data
	./quick
	mv result result_quick

heap: main.c heapsort.c
	gcc main.c heapsort.c -o heap

testheap: heap data
	./heap
	mv result result_heap

count: main.c countsort.c
	gcc main.c countsort.c -o count

testcount: count data
	./count
	mv result result_count

clean:
	-rm -f insert
	-rm -f bubble
	-rm -f merge
	-rm -f quick
	-rm -f heap
	-rm -f count
	-rm -f data
	-rm -f result*

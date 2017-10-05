stack-test:
	g++ -std=c++14 -c ../data_structure/stack/stack.cpp stack_test.cpp
	g++ stack.o stack_test.o -o stack_test
	./stack_test -s
	rm *.o stack_test

singly-linked-list-test:
	g++ -std=c++14 -c ../data_structure/singly_linked_list/singly_linked_list.cpp singly_linked_list_test.cpp
	g++ singly_linked_list.o singly_linked_list_test.o -o singly_linked_list_test
	./singly_linked_list_test -s
	rm *.o singly_linked_list_test

doubly-linked-list-test:
	g++ -std=c++14 -c ../data_structure/doubly_linked_list/doubly_linked_list.cpp doubly_linked_list_test.cpp
	g++ doubly_linked_list.o doubly_linked_list_test.o -o doubly_linked_list_test
	./doubly_linked_list_test -s
	rm *.o doubly_linked_list_test

heap-test:
	g++ -std=c++14 -c ../data_structure/heap/heap.cpp heap_test.cpp
	g++ heap.o heap_test.o -o heap_test
	./heap_test -s
	rm *.o heap_test

rle-test:
	g++ -std=c++14 -c ../encoding/rle/rle.cpp rle_encoding_test.cpp
	g++ rle.o rle_encoding_test.o -o rle_test
	./rle_test -s
	rm *.o rle_test

counting-sort-test:
	g++ -std=c++14 -c ../sort/counting_sort/counting_sort.cpp counting_sort_test.cpp
	g++ counting_sort.o counting_sort_test.o -o cs_test
	./cs_test
	rm *.o cs_test
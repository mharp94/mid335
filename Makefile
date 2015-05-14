all:	mid335

mid335:	mid335.cpp
	g++ mid335.cpp -o mid335

clean: mid335
	rm -f mid335

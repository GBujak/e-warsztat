warsztat: clean 
	g++ src/* -o warsztat `wx-config --cxxflags --libs` -Wall

clean:
	rm warsztat
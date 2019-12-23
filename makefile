warsztat: clean 
	g++ src/* -o warsztat `wx-config-gtk3 --cxxflags --libs` -Wall

clean:
	rm warsztat

CC = g++
all:
	@echo "Building.."
	@${CC} main.cpp Book.cpp Schedule.cpp Library.cpp Exceptions.cpp -std=c++11 -o binary
clean:
	@echo "Cleaning up.."
	@rm -rf binary

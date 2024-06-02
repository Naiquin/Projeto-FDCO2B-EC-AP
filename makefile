main: main.o
	@echo "Gerando arquivo executável"
	gcc *.o -o main

main.o: main.c
	@echo "Compilando e gerando os objetos"
	gcc -c *.c
#"del /Q *.o main.exe" é para windows e o outro para linux
clean:
	@echo "Apagando objetos e executáveis antigos..."
	del /Q *.o main.exe
	rm -f *.o main

run:
	./main
	
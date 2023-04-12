all:npipe_reader.exe npipe_writer.exe

npipe_reader.exe:npipe_reader.c
	gcc npipe_reader.c -o npipe_reader.exe
	
npipe_writer.exe:npipe_writer.c
	gcc npipe_writer.c -o npipe_writer.exe

clean:
	rm -f npipe_reader.exe npipe_writer.exe

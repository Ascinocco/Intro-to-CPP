## Week 1
### Notes


#### Compilation Process
Source file -> preprocessor -> compiler -> assembler -> Object Code File -> linker -> Executable

- Source File
    - This is what I write, this is my main.cpp etc../.
- C++ Preprocessor
    - This looks at my file and includes all the libraries I ask for
    - Then outputs a temporary file which includes the expanded source code (meaning it has my includes in it ex. stdio)
- compiler
    - compiles my code down into an assembler file
- assembler
    - converts my assebler file into Object File code
- linker
    - creates the executable file
    - meaning that it combines each Object File into a single executable file


### Usuable imports
- stdstream
- stdio

### compile and run
- compile: make fileName
- run: just like bash - ./fileName

### Important!
- You need to include the .h for certain header files...
- Good to know
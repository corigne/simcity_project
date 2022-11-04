# SimCity v1.0 README
## Group 6 - CSCE 2110 - Section 002/213
### Members:
- Chandler Garret
- Trevonne Bridges
- Salma Omary
- Nathan Jodoin

### Compiling
To compile, please use the following command:

  >``g++ main.cpp -o main``

### Running
To run the application with a supplied config text file and CSV:

  1. Place the .CSV in the project folder.
  2. For Example: run >``./main "config1.txt"`` .  

If you do not include a config filename argument while runnning the executable,  
the program will exit with error code 1 and inform you of the error.

### Make
Due to the simplicity of our includes, a makefile is unecessary for compilation.
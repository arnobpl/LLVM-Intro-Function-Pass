# LLVM Intro Function Pass
It is an LLVM-based project which warns developers if they have any method in their C/C++ code that has more than three parameters. It is an introductory project which utilizes LLVM compiler infrastructure.

## Environment Setup for the First Time
Here is my first-time environment setup which I have used for this project:
- **Operating system:** Ubuntu 18.04 LTS

- **Commands to setup LLVM:** To setup LLVM on my Ubuntu machine, I have used the following commands:
  - **To update and upgrade repositories:**
    ```console
    sudo apt-get update
    sudo apt-get upgrade
    ```
  - **To install LLVM and Clang:**
    ```console
    sudo apt-get install clang-6.0 lldb-6.0 lld-6.0
    sudo apt-get install llvm
    sudo apt-get install clang
    sudo apt-get install clang-tools
    ```
  - **To install CMake and other build tools:**
    ```console
    sudo apt-get install build-essential
    sudo apt-get install cmake
    ```

- **Test whether the setup done correctly:** I have used the following commands to test whether the environment setup has been done correctly: 
    ```console
    username@PC-NAME:~$ llvm-config --version
    6.0.0
    username@PC-NAME:~$ llvm-config --prefix
    /usr/lib/llvm-6.0
    username@PC-NAME:~$ clang
    clang: error: no input files
    username@PC-NAME:~$ 
    ```
    Notice the output of each command.

## Build LLVM Function Pass
- **Commands to build LLVM Function Pass:** Notice that there is an LLVM function pass defined in `/skeleton/Skeleton.cpp` file. I have opened a terminal window outside of `/skeleton` directory. Then I have run the following commands:
    ```console
    mkdir build
    cd build/
    cmake ..
    make
    ```
    Notice that `/build/skeleton/libSkeletonPass.so` file has been generated.

- **Commands to use the LLVM Function Pass to compile code:**
  - If you open `/skeleton/Skeleton.cpp` file, then you will see that `SkeletonPass` function pass actually warns developers if they have any function in their code that has more than three parameters.
  - Now notice that `/HelloWorld.c` file has a function called `void concatCharArray(char *result, const char *a, const char *b, const char *c)`. So `concatCharArray` function has more than three arguments (four arguments).
  - I have used the following command to compile `/HelloWorld.c` file with `SkeletonPass` function pass:
    ```console
    username@PC-NAME:~/Desktop/LLVM Intro Function Pass/build$ clang -Xclang -load -Xclang skeleton/libSkeletonPass.so ../HelloWorld.c
    Warning: 'concatCharArray' function has 4 arguments!
    username@PC-NAME:~/Desktop/LLVM Intro Function Pass/build$ 
    ```
    Notice that the above console output shows a warning generated by `SkeletonPass` function pass.

- **Commands to run the compiled executable code**: Since the compiled executable code of `/HelloWorld.c` has been created, I can use the following command to run it:
    ```console
    username@PC-NAME:~/Desktop/LLVM Intro Function Pass/build$ ./a.out 
    Hello World!
    I am testing llvm!
    username@PC-NAME:~/Desktop/LLVM Intro Function Pass/build$ 
    ```

## Additional Resource
- Here is an extremely helpful LLVM learning resource for absolute beginners:

  [Adrian Sampson: LLVM for Grad Students](http://www.cs.cornell.edu/~asampson/blog/llvm.html)

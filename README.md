# search_engine_1
This is the initial version of c++ backend of the mini search engine project for searching research papers by using c++ and qt
Here the search algorithm uses a trie

# Build instructions
This c++ project prints the search results in your console screen. This project was developed on Visual Studio Code 1.43.2 with Bazel 3.0.0 on a 64-bit Ubuntu 16.04 inside a virtual machine in windows 10.
Try out this c++ search engine by installing Bazel and Visual Studio Code (preferably inside Ubuntu).
For building C++ files, you can install Bazel using this [link](https://docs.bazel.build/versions/master/install.html).
After the installation of visual studio code and bazel is complete follow the steps below:
## 1. Clone this repo:
git clone https://github.com/RudrenduMahindar/search_engine_1.git 

## 2. Build and run this project in Visual Studio Code
#### Open Visual Studio Code
#### In the top menubar of Visual Studio Code, click on File->Open Folder, select the folder of search_engine_1 and open it
#### In the top menubar of Visual Studio Code, click on Terminal->New Terminal
After the terminal opens, type:
#### bazel run src/main:main
Enjoy!!

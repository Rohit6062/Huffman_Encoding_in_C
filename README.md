Huffman algorithm was intorduced By David A. Huffman.
More about Him : https://en.wikipedia.org/wiki/David_A._Huffman

Project Overview

This project involves implementing the Huffman Encoding algorithm in the C programming language. Huffman Encoding is a popular method of lossless data compression. The project will focus on creating an efficient program that reads input data, constructs a Huffman tree, generates corresponding Huffman codes, and then uses these codes to encode and decode data.
Objectives

    Understand Huffman Encoding: Gain a deep understanding of the Huffman encoding algorithm, including the creation of Huffman trees and the generation of variable-length codes.
    Data Structures and Algorithms: Implement necessary data structures such as priority queues (min-heaps), binary trees, and hash tables in C.
    File I/O: Handle file input and output operations to read the data to be encoded and store the encoded output.
    Encoding and Decoding: Develop functions for encoding data using the Huffman codes and for decoding the encoded data back to its original form.
    Efficiency: Ensure the implementation is efficient in terms of both time and space.

Features

    Input Handling:
        Read data from a file or standard input.
        Calculate the frequency of each character in the input data.

    Huffman Tree Construction:
        Use a priority queue to build the Huffman tree based on character frequencies.
        Store the resulting tree for encoding and decoding purposes.

    Code Generation:
        Generate Huffman codes for each character by traversing the Huffman tree.
        Store these codes in a hash table for quick lookup during encoding.

    Encoding:
        Encode the input data using the generated Huffman codes.
        Write the encoded data to an output file or standard output.

    Decoding:
        Read the encoded data.
        Use the Huffman tree to decode the data back to its original form.
        Write the decoded data to an output file or standard output.

    Efficiency and Optimization:
        Implement memory management techniques to handle dynamic data structures efficiently.
        Optimize the algorithm for better performance.

Technical Requirements

    Programming Language: C
    Compiler: GCC or any standard C compiler
    Development Environment: Any C development environment (e.g., Visual Studio Code, Eclipse, Code::Blocks)
    Libraries: Standard C libraries (stdlib.h, stdio.h, string.h)
    Tools: Makefile for build automation (optional but recommended)


By the end of this project, you will have a functional Huffman encoding and decoding program written in C, along with a deeper understanding of data compression techniques and the C programming language..

**Setup :-**

  **For Compression:**
  
  just run compress file followed by file Name you want to compress and Name of output file.
    Example: ( for Linux environment )
            **./compress file_to_compress.txt compressed_file.dat**
             ( for windows just run it and it will ask you names of files in input )
  
  **for Decompression :**
  
  just run decompress file followed by compressed file name and file name of output file.
    Example: 
            **./decompress compressed.dat decompressed.txt**
  

**TIP :-**
**For testing Purpose u can create a test data file by simply running generateTestData.py file.**

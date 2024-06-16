This project is a implementation of huffman encoding . A algorithm used to compressed files of any type. 
This project is completely written in C language.
This code can be used for educational perpose.

Huffman algorithm was intorduced By David A. Huffman.
More about Him : https://en.wikipedia.org/wiki/David_A._Huffman

Huffman Encoding is Loss less data compression algorithm widely used in field of computer science. The main idea behind huffman is to calculate occurence of perticular character compaire it with occurences of other characters and then generate a unique code according to position of that character in list sorted using occurence count.
By using this we unsure that the characters occures most have the smallest code.

**Setup**:

  **For Compression.**
  
  just run compress file followed by file Name you want to compress and Name of output file.
    Example: ( for Linux environment )
            **./compress file_to_compress.txt compressed_file.dat**
             ( for windows just run it and it will ask you names of files in input )
  
  **for Decompression.**
  
  just run decompress file followed by compressed file name and file name of output file.
    Example: 
            **./decompress compressed.dat decompressed.txt**
  

**TIP :**
**For testing Purpose u can create a test data file by simply running generateTestData.py file.**

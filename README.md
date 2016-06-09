# MergeSortBenchmarks

## Introduction

We are currently using Java and Node.js at pVelocity for server side development. We wanted to know the state of Swift and how its raw runtime characteristics will compare with Java and Node.js. We also compared it with C as a base reference point.

The rationale is to explore the possibility of Swift as a server side native coding platform on Linux and in the future Windows. Swift offers the promise of a contemporary programming language with modern style and feel, that does not compromise on performance. We were interested to see how this claimed performance compares to Java and Node.js that both use JIT compilation technologies.

The hardware test platform that was used is:

    Model Name: MacBook Pro (Retina, 15-inch, Mid 2015)
    Model Identifier: MacBookPro11,5
    Processor Name:   Intel Core i7
    Processor Speed:  2.5 GHz
    Number of Processors: 1
    Total Number of Cores:    4
    L2 Cache (per Core):  256 KB
    L3 Cache: 6 MB
    Memory:   16 GB 1600 MHz DDR3

We took the implementation offered in http://www.cquestions.com/2011/07/merge-sort-program-in-c.html and ported to the above languages, with tweaks tailored to language specific optimization considerations. Each program will sort ten thousand integers stored in the ```TestData.txt``` file. Only the merge sort time is recorded. The timings to process the contents of the file into arrays and the output of the sorted list of integers did not contribute to the reported time.

## Building From Source

Both the C and Swift versions are written with Xcode (7.3.1). You should be able to open their corresponding projects. From the terminal:

	open C/MergeSort.xcodeproj
	open Swift/
	
The projects already have their scheme set accordingly so the programs will compile and run.

For the Java version, an Ant ```build.xml``` file is provided. Simply run Ant to build the ```MergeSort.jar``` file and then run it.

	cd Java
	ant
	java -server -jar MergeSort.jar
	
The Node.js version is the simplest if you already have ```node``` installed on your machine.

	node mergeSort.js
	
## Results

Each is run with 10 iterations.

### C

We will start with the age old language of kernels and systems.

    Elapsed time: 0.000971 (secs)
    Elapsed time: 0.000778 (secs)
    Elapsed time: 0.000735 (secs)
    Elapsed time: 0.000752 (secs)
    Elapsed time: 0.000752 (secs)
    Elapsed time: 0.000763 (secs)
    Elapsed time: 0.000735 (secs)
    Elapsed time: 0.000871 (secs)
    Elapsed time: 0.000753 (secs)
    Elapsed time: 0.000751 (secs)

Consistently performing below 0.8 ms.

### Java

The current server side language of the enterprise.

    Elapsed time: 0.003000 (secs)
    Elapsed time: 0.003000 (secs)
    Elapsed time: 0.003000 (secs)
    Elapsed time: 0.004000 (secs)
    Elapsed time: 0.003000 (secs)
    Elapsed time: 0.004000 (secs)
    Elapsed time: 0.004000 (secs)
    Elapsed time: 0.003000 (secs)
    Elapsed time: 0.003000 (secs)
    Elapsed time: 0.003000 (secs)

I couldn't the granularity in micro seconds, so Java's performance running with 

    java version "1.8.0_92"
    Java(TM) SE Runtime Environment (build 1.8.0_92-b14)
    Java HotSpot(TM) 64-Bit Server VM (build 25.92-b14, mixed mode)

Seems to be hovering between 3 to 4 ms, probably closer to the 3 ms mark.

### Node.js

    time: 0.0278 (secs)
    time: 0.0276 (secs)
    time: 0.0324 (secs)
    time: 0.0282 (secs)
    time: 0.0266 (secs)
    time: 0.0276 (secs)
    time: 0.0281 (secs)
    time: 0.0269 (secs)
    time: 0.0277 (secs)
    time: 0.0328 (secs)

Using:

    node --version
    v4.2.6

Approximately at around the 28 ms mark.

### Swift

And now for the newest language on the scene:

    Elapsed time: 0.001098 (secs)
    Elapsed time: 0.001154 (secs)
    Elapsed time: 0.001104 (secs)
    Elapsed time: 0.001056 (secs)
    Elapsed time: 0.001662 (secs)
    Elapsed time: 0.001361 (secs)
    Elapsed time: 0.001375 (secs)
    Elapsed time: 0.001136 (secs)
    Elapsed time: 0.001109 (secs)
    Elapsed time: 0.001068 (secs)
    
Using:

    swift --version
    Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
    Target: x86_64-apple-macosx10.9
    
But the compiled version of the program is run, using the scheme configured in Xcode. The Swift version consistently scores just above the 1+ ms mark.

## Conclusion

It seems Swift has a lot of potential. Unfortunately as of Swift 2.2, the support for Windows is still missing. The above results look very promising and I look forward to Swift 3.0 and will definitely keep my ears perked for future development of Swift. I have already begin exploring possibilities offered by the following frameworks:

* [Perfect](http://perfect.org)
* [Vapor](http://qutheory.io)





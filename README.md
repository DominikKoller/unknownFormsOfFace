unknownFormsOfFace
==================

looking for faces in randomness

Project description:
http://dominikkoller.net/unknownFormsOfFace

This includes the C++ (win), Processing and JavaScript version of the project.

Fiddle about with the OpenCV face detection parameters and flags to get different results!

C++
-------------------
The C++ is the recommended one to use, if possible. It is the fastest, which is crucial. 
Also, it's the most tweakable, and therefore will give you the best results.
It contains the source file and the compiled version (VS 2012, win32 release)
OpenCV needs to be installed on the system, including the OpenCV environment variables!
http://docs.opencv.org/doc/tutorials/introduction/windows_install/windows_install.html#windows-installation

Processing
-------------
Tested only on win, but should run cross-platform. OpenCV for Processing library must be installed (Sketch -> Import Library -> Add Library -> search for OpenCV -> install)

JavaScript
------------
Works nicely in a browser, it's just really inefficient. Not based on OpenCV face detection, but jQuery facedetection plugin
http://facedetection.jaysalvat.com/

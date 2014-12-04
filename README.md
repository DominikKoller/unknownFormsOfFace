unknownFormsOfFace
==================

looking for faces in randomness

Project description:
http://dominikkoller.net/UnknownFormsOfFace

This includes the C++ (win), Processing and JavaScript version of the project.

Fiddle about with the OpenCV face detection parameters and flags to get different results!

C++
-------------------
Fastest implementation.
Also, it's very tweakable, and therefore will give you the best results.
It contains the source file and the compiled version (VS 2012, win32 release)
OpenCV needs to be installed on the system, including the OpenCV environment variables!
http://docs.opencv.org/doc/tutorials/introduction/windows_install/windows_install.html#windows-installation

vvvv
--------------------
45beta33.3 32bit

Just as tweakable as the C++ version, and it's arguably easier to do so. All you need is vvvv + addonpack.
This version is, in my opinion, the best compromise between performance, ease to use and tweakability.
Win only.

Processing
-------------
Tested only on win, but should run cross-platform. OpenCV for Processing library must be installed (Sketch -> Import Library -> Add Library -> search for OpenCV -> install)
Performance is all right, not as fast as C++ or vvvv.

JavaScript
------------
Works nicely in a browser, it's just really inefficient. Not based on OpenCV face detection, but jQuery facedetection plugin
http://facedetection.jaysalvat.com/

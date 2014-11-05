#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <direct.h>

using namespace std;
using namespace cv;

/** Function Headers */
void detect( Mat frame );

/** Global variables */
//this haarcascade produces the few positives, which is good in our case (more time - better quality)
String face_cascade_name = "haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
String window_name = "Capture - Face detection";
String directory = "images";
bool showRealtimeScanning;

vector<Rect> faces;
int nImagesFound = 0;

/** @function main */
int main( void )
{
	//-- check whether to show scanned images in seperate window
	cout << "Show scanning in realtime, in a seperate window?" << endl
		 << "This may make the process a bit slower. [Y] or [N]: ";
	char choice = ' ';
	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') 
	{
		cin >> choice;
		if (choice == 'y' || choice == 'Y') 
			showRealtimeScanning = true;
		else if (choice == 'n' || choice == 'N') 
			showRealtimeScanning = false;
	}

	//-- Confirm overwriting images
	cout << endl << endl
		 << "Pictures will be stored in /images" << endl << endl
	     << "Previous pictures will be overwritten!" << endl
	     << "Confirm? [Y] or [N]: ";

	cin >> choice;
	while (choice != 'y' && choice != 'Y')
	{
		if (choice == 'n') 
			return 0;
		cin >> choice;
	}

	//-- start!
	cout	<< "Looking for faces" << endl << "...";

    //-- Load the cascade
    if( !face_cascade.load( face_cascade_name ) )
	{
		cout << endl << "--(!)Error loading face cascade\n" << endl
			 << "press enter to exit";
		//clear input buffer
		cin.ignore();
		//wait for enter
		cin.get(); 
		return -1;
	}

	//-- Crate directory, in case it doesn't yet exist
	_mkdir("images");
	_mkdir("images\\unmarked");

    //-- Matrix for storing image
	Mat image(500,800, CV_8UC1);

    while ( true )
    {
		//-- create random image
		randu(image, Scalar::all(0), Scalar::all(255));

        //-- apply the classifier to the image
        detect( image );

		//-- waitKey needs to be called for CV_highgui to work
		if(showRealtimeScanning) 
			waitKey(1);
    }
    return 0;
}

/** @function detectAndDisplay */
void detect( Mat image )
{
    //-- Detect faces and store in vector<Rect> faces
	//image, objects out, scaleFactor, minNeighbours, flags, minSize, maxSize
    face_cascade.detectMultiScale( image, faces, 1.2, 3, 0, Size(10, 10), Size(100, 100));

	//-- if any faces are found:
	if(faces.size() > 0)
	{
		nImagesFound ++;
		cout << endl << nImagesFound;

		//save raw image
		imwrite("images\\unmarked\\" + to_string(nImagesFound) + ".jpg", image);
		
		//draw rectangles over all faces
		for ( size_t i = 0; i < faces.size(); i++ )
			rectangle( image, faces[i], Scalar( 255, 255, 255), 2, 8, 0);
	
		//save image with faces marked
		imwrite("images\\" + to_string(nImagesFound) + ".jpg", image);
	}

    //-- Show what you got
	if (showRealtimeScanning) 
		imshow( window_name, image );
}
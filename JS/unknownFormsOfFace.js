//depends on
//jquery.facedetection.min.js
//jquery.min.js

var canvas = document.getElementById("canvas"),
context = canvas.getContext("2d"),
imagedata = context.getImageData(0, 0, canvas.width, canvas.height);

var workersRunning = false;
var faceFindTimer = false;


function toggleSearchForFace(){
	if(faceFindTimer) stopSearchForFace();
	else startSearchForFace();
}

function stopSearchForFace() {
	clearInterval(faceFindTimer);
	faceFindTimer = false;
}

function startSearchForFace() {
	//clear timer in case it is running
	clearInterval(faceFindTimer);

	//start timer
	faceFindTimer = setInterval( function () { 

		//generate random image
		for(var i=0; i< imagedata.data.length; i+=4)
		{
			//random values are NOT drawn from random.ORG, as this would overcomplicate things with API keys and such
			imagedata.data[i] = imagedata.data[i+1] = imagedata.data[i+2] = Math.random() * 255; //rgb (grayscale)
			imagedata.data[i+3] = 255; // alpha
		}
		//------------------------------------

		//draw random image
		context.putImageData(imagedata, 0, 0);
		//------------------------------------

		//run face detection
		//this is not really done every frame (as this would drain a lot of CPU (no, it's not GPU based, sorry)). 
		//this is not done nicely, speaking of performance, it only gives the impression of scanning many images when in reality it probably scans much less.
		//however, it looks nice
		if(workersRunning < 10) {
		//state that one more worker is running
			workersRunning ++;
						
			//uncomment this to check how many images are actually scanned (as opposed to how many images are shown)
			//console.log("start worker");	
			//uncomment this to see how many workers are running at a time
			//console.log("workers running: " + workersRunning);

			$('#canvas').faceDetection({

				//run in asynchronously, to enable doing other stuff while the image is scanned for faces
				//and running more than one detection at a time (in this case, max 10)
				//more random images are drawn while this runs in the background
				//to cheat the impression of many images being scanned
				async : true,

	       		complete: function (faces)
	       		{
	       			//state that one worker less is running
	       			workersRunning--;
					//if a face is detected, halt the loop and draw a rect around the face
					if(faces.length > 0) {
						console.log("Face found!");

         				for(var i=0; i < faces.length; i++)
         				{
         					//draw a rectangle around each face
         					context.rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
         					context.strokeStyle="white";
							context.stroke(); 
         				}

         				//stop main loop when picture found
         				stopTimer();
         			}
        		},

        		error: function (code, message)
        		{
    				console.log("ERROR!");
    				console.log("Code:  " + code);
    				console.log("Message: " + message);
				}
    		});
		}

	}, 50 );
}
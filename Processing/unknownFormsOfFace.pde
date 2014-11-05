import gab.opencv.*;
import java.awt.Rectangle;

OpenCV opencv;
PImage image;

String directory = "images";
boolean showRealtimeScanning = true;
boolean overwriteConfirmed = false;

int nImagesFound = 0;

void setup() {

  size(400, 500);

  image = createImage(width, height, ALPHA);
  opencv = new OpenCV(this, image);
  opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);
  
  
  //click to confirm overwriting of images
  fill(0);
  text("Pictures will be stored in /images", 10, 20);
  text("Previous pictures will be overwritten!", 10, 40);
  text("Click to confirm", 10, 60);

  noFill();
  stroke(255);
  strokeWeight(2);
}

void draw() {

  //if the user has confirmed overwrite (by clicking)
  if (overwriteConfirmed)
  {
    //randomize image
    image.loadPixels();
    for (int i = 0; i < image.pixels.length; i++)
      image.pixels[i] = color(random(255));
    image.updatePixels();

    //load image into openCV
    opencv.loadImage(image);

    //look for faces
    Rectangle[] faces = opencv.detect();

    //if any faces are found:
    if (faces.length > 0) {
      nImagesFound++;
      println(faces.length);

      //save raw image
      save("images\\unmarked\\"+ nImagesFound + ".tif");

      //draw rectangles over all faces
      for (int i = 0; i < faces.length; i++) 
        rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);

      //save images with faces marked
      save("images\\" + nImagesFound + ".tif");
    }

    //remove to make stuff run faster
    image(image, 0, 0);
  }
}

void mousePressed() {
  overwriteConfirmed = true;
}


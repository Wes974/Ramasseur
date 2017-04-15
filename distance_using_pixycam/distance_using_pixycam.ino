/*
 * based on http://www.pyimagesearch.com/2015/01/19/find-distance-camera-objectmarker-using-python-opencv/
 * for use with the Pixy Cam (CMUcam 5)
 *
*/

#include "Pixy.h"

/* Calibrate using a tape measure or ruler, set your pixycam 2 foot from the color coded object
 * In the serial monitor, take a few reading of for the width and height.
 * they should be the same on each reading, once you are sure they are.
 * Put your readings in the variables, set Calibrate back to 0, reupload the sketch.
 * Now the sketch should start to give you distances.
*/

#define Calibrate 0 //Change to 1 see above for details.
#define calDistance 30 //in inches 24inches or 2 foot


int calWidth = 38; //Calibrated width reading
int calHeight = 21; //Calibrated height reading
int pixelsWidth;   //read by the camera
int pixelsHeight; //read by the camera
float distanceWidth;   //calculated distance based on the width of the object
float distanceHeight;  //calculated distance based on the height of the object
float widthOfObject = 6; //inches (3.75 inches) real size of your object
float heightOfObject = 6; //inches (2.5 inches) real size of your object
int focalLengthWidth;  //calculated focal length for width
int focalLengthHeight; //calculated focal length for height
float avg;

//Formula = FocalLengthWidth = (pixels * knowdistanceininches) / widthOfObject
//Distance = (widthOfObject * FocalLengthWidth) / pixelsWidth
//focal length and distance for height is calculated the same way replacing width with height values

Pixy pixy;

void setup()
{
  Serial.begin(9600); // 9600 baud for the serial *console* (not for the UART connected to Pixy)
  Serial.print("Starting...\n");

  pixy.init();
  //calculate focal length
  focalLengthWidth = (calWidth * calDistance) / widthOfObject;
  focalLengthHeight = (calHeight * calDistance) / heightOfObject;

}

void loop()
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];

  blocks = pixy.getBlocks();

  if (blocks) {

      i++;

      // do this (print) every 50 frames because printing every
      // frame would bog down the Arduino
      if (i%50==0) {

          if (Calibrate) {
              sprintf(buf, "Detected %d:\n", blocks);
              Serial.print(buf);
              for (j=0; j<blocks; j++) {
                  sprintf(buf, "  block %d: ", j);
                  Serial.print(buf);
                  pixy.blocks[j].print();
              }
          } else {
              sprintf(buf, "Detected %d:\n", blocks);
              Serial.print(buf);
              for (j=0; j<blocks; j++) {
                  //sprintf(buf, "  block %d: ", j);
                  //Serial.print(buf);
                  pixelsWidth = pixy.blocks[j].width;
                  pixelsHeight = pixy.blocks[j].height;
                  distanceWidth = (widthOfObject * focalLengthWidth) / pixelsWidth;
                  distanceHeight = (heightOfObject * focalLengthHeight) / pixelsHeight;
                  avg = (distanceWidth + distanceHeight)/2;
                  avg = round(avg);

                  Serial.print("Width: ");
                  Serial.print(pixelsWidth);
                  Serial.print(" Height: ");
                  Serial.print(pixelsHeight);
                  Serial.print(" Distance W: ");
                  Serial.print(distanceWidth);
                  Serial.print("cm. ");
                  Serial.print("Distance H: ");
                  Serial.print(distanceHeight);
                  Serial.print("cm. Angle:");
                  Serial.println(pixy.blocks[j].angle);
                  Serial.print("Average: ");
                  Serial.print(avg);
                  Serial.print("cm. ");

     }
    }
  }
}
}

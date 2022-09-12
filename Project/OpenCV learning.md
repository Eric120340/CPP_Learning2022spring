# OpenCV learning



## 1.Basic operation in opencv

### 1.1 Image

Three key functions：

- imread(image name/path, flag)	这里使用绝对路径，clion中的相对路径不适合
- imread(name of window, image)
- imwrite(file name, image)

```c++
//Include Libraries
#include "opencv2/highgui//highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

// Namespace nullifies the use of cv::function(); 
using namespace std;
using namespace cv;
int main()
{
    // Read an image
    Mat img_grayscale = imread("test.jpg", 0);

// Display the image.
    imshow("grayscale image", img_grayscale);

// Wait for a keystroke.
    waitKey(0);

// Destroys all the windows created
    destroyAllWindows();

// Write the image in the same directory
    imwrite("grayscale.jpg", img_grayscale);
    return 0;
}
```

flag(imread) have different options to read different types of the images.

- `cv2.IMREAD_UNCHANGED` or `-1`
- `cv2.IMREAD_GRAYSCALE` or `0`
- `cv2.IMREAD_COLOR` or `1`

waitKey() means  to delay the image show process. 0 represent infinite.

### 1.1 video

Video is similar to image.

- VideoCapture: 创造一个视频捕捉的对象，有助于视频的播放
- VideoWriter：保存视频

```c++
// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main()
{
	// initialize a video capture object
	VideoCapture vid_capture("Resources/Cars.mp4");

	// Print error message if the stream is invalid
	if (!vid_capture.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
	}

	else
	{
		// Obtain fps and frame count by get() method and print
		// You can replace 5 with CAP_PROP_FPS as well, they are enumerations
		int fps = vid_capture.get(5);
		cout << "Frames per second :" << fps;

		// Obtain frame_count using opencv built in frame count reading method
		// You can replace 7 with CAP_PROP_FRAME_COUNT as well, they are enumerations
		int frame_count = vid_capture.get(7);
		cout << "  Frame count :" << frame_count;
	}


	// Read the frames to the last frame
	while (vid_capture.isOpened())
	{
		// Initialise frame matrix
		Mat frame;

	    // Initialize a boolean to check if frames are there or not
		bool isSuccess = vid_capture.read(frame);

		// If frames are present, show it
		if(isSuccess == true)
		{
			//display frames
			imshow("Frame", frame);
		}

		// If frames are not there, close it
		if (isSuccess == false)
		{
			cout << "Video camera is disconnected" << endl;
			break;
		}
		
		//wait 20 ms between successive frames and break the loop if key q is pressed
		int key = waitKey(20);
		if (key == 'q')
		{
			cout << "q key is pressed by the user. Stopping the video" << endl;
			break;
		}


	}
	// Release the video capture object
	vid_capture.release();
	destroyAllWindows();
	return 0;
}
```

创建视频捕捉对象**VideoCapture(path, apiPreference)** 

`VideoCapture vid_capture("Resources/Cars.mp4");`





Pose detector

```python
import cv2
import mediapipe as mp
import time

class poseDetecor()
	
  def __init__(self,self.mode = False, self.upBody = False, self.smooth = True, )
```


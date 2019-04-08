// Start01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;


void basicOpening (cv::Mat img)
{
	cv::namedWindow("mypicture", cv::WINDOW_NORMAL);
	cv::imshow("mypicture", img);
}

void contrastChangeNmb1(cv::Mat originImg)
{
	cv::Mat contrastImg = originImg * 0.5;
	cv::namedWindow("Low_Contrast", cv::WINDOW_NORMAL);
	cv::imshow("Low_Contrast", contrastImg);
}

void contrastChangeNmb2(cv::Mat originImg)
{
	cv::Mat contrastImg;
	originImg.convertTo(contrastImg, -1, 2, 0);
	cv::namedWindow("High_Contrast", cv::WINDOW_AUTOSIZE);
	cv::imshow("High_Contrast", contrastImg);
}

void histogramEqualization(cv::Mat originImg)
{
	cv::Mat img_hist_equalized;
	cv::cvtColor(originImg, originImg, cv::COLOR_RGB2GRAY);
	cv::equalizeHist(originImg, img_hist_equalized);
	cv::namedWindow("histogramEqualization", cv::WINDOW_NORMAL);
	cv::imshow("histogramEqualization", img_hist_equalized);

}

void blendingPictures (cv::Mat originImg)
{
	cv::Mat secondImage = cv::imread("nope.jpg");
	cv::Mat mixedImage;
	double alpha = 0.8; // is needs to between 0.0 - 1.0
	double beta = 1.0 - alpha;

	cv::resize(secondImage, secondImage, originImg.size()); // two image must be the same size
	cv::addWeighted(originImg, alpha, secondImage, beta, 0.0, mixedImage);
	cv::namedWindow("Blending", cv::WINDOW_AUTOSIZE);
	cv::imshow("Blending", mixedImage);
}

void makeItGRay(cv::Mat originImg) 
{
	cv::Mat imgGray;
	cv::cvtColor(originImg, imgGray, cv::COLOR_RGB2GRAY); //input, output, change
	cv::namedWindow("RGB2GRAY", cv::WINDOW_NORMAL);
	cv::moveWindow("RGB2GRAY", 100, 320);
	cv::imshow("RGB2GRAY", imgGray);
}

void basicDrawing()
{
	
	// # Create a black image
	cv::Mat backGround(250, 500, CV_8UC3, cv::Scalar(0, 0, 0)); //scalar - r g b (bgr);
	
	
	cv::line(backGround, cv::Point(10, 30), cv::Point(30, 200), cv::Scalar(100, 100, 20), 10);
	cv::circle(backGround, cv::Point(100, 100), 50, cv::Scalar(0 ,100 ,0), 10);
	cv::ellipse(backGround, cv::RotatedRect(cv::Point(250, 100), cv::Size(150, 50), 30), cv::Scalar(0,255,255), 5);
	cv::rectangle(backGround, cv::Rect(350, 100, 100, 100), cv::Scalar(255, 0, 255), 5);

	cv::namedWindow("DRAWING", cv::WINDOW_AUTOSIZE);
	cv::imshow("DRAWING", backGround);


}

void basicTexting() 
{
	//Create an empty image
	cv::Mat backGround(250, 500, CV_8UC3, cv::Scalar(0, 0, 0)); 
	cv::putText(backGround, "ALOHA!", cv::Point(120, 120), cv::FONT_HERSHEY_SCRIPT_SIMPLEX, 2.4, cv::Scalar(10, 255, 20), 2);

	cv::namedWindow("TEXTING", cv::WINDOW_AUTOSIZE);
	cv::imshow("TEXTING", backGround);

} 

void linearFilters(cv::Mat originImg)
{
	cv::Mat filteredImg;
	cv::Point anchor = cv::Point(-1, -1);
	double delta = 0;
	double ddepth = -1;
	cv::Mat kernel;
	int kernel_size;

	int ind = 0;
	for (;;)
	{
		// Update kernel size for a normalized box filter
		kernel_size = 3 + 2 * (ind % 5);
		kernel = cv::Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
		// Apply filter
		//filter2D - sorce file, output file, value for the filter (negative number), a point but ???, value to be added to each pixel default - 0, default value,
		filter2D(originImg, filteredImg, ddepth, kernel, anchor, delta, cv::BORDER_DEFAULT);
		cv::namedWindow("Using Filter", cv::WINDOW_AUTOSIZE);
		cv::imshow("Using Filter", filteredImg);
		char c = (char)cv::waitKey(500);
		// Press 'ESC' to exit the program
		if (c == 27)
		{
			break;
		}
		ind++;
	}

}

void morphologicalOperators()//not done
{
	cv::Mat original = cv::imread("number.jpg");
	cv::Mat erosion;
	cv::erode(original, erosion, cv::Mat());
	cv::namedWindow("Erosion", cv::WINDOW_NORMAL);
	cv::imshow("Erosion", erosion);
	cv::namedWindow("Origin", cv::WINDOW_NORMAL);
	cv::imshow("Origin", original);

	cv::Mat dilate;
	cv::dilate(original, dilate, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
	cv::namedWindow("Dilate", cv::WINDOW_NORMAL);
	cv::imshow("Dilate", dilate);

}


int main()
{
	cv::Mat original = cv::imread("lena.jpg");
	if (original.empty()){
		std::cout << "Could not open or find the image!\n" << std::endl;
		return -1;
	}
	
	//basicOpening(original);
	//contrastChangeNmb1(original);
	//contrastChangeNmb2(original);
	//histogramEqualization(original);
	//makeItGRay(original);
	//blendingPictures(original);
	//basicDrawing(); 
	//basicTexting(); 
	//linearFilters(original); //question!!
	morphologicalOperators();


	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
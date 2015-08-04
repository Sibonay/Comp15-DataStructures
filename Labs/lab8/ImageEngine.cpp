/*
 * ImageEngine.cpp
 *
 *  Created on: Mar 29, 2015
 *      Author: Chris Gregg
 */

#include "ImageEngine.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ImageEngine::ImageEngine() {
	// Nothing to do!
}

ImageEngine::~ImageEngine() {
	// Nothing to do!
}

void ImageEngine::readImage(std::string filename) {
	// reads in a ppm file into Image
	ifstream inputFile;
	inputFile.open (filename.c_str());
	if (inputFile.is_open())
	{
		inputFile >> image.magic_number;
		inputFile >> image.width;
		inputFile >> image.height;
		inputFile >> image.max_color;
		cout << image.width << "," << image.height << "\n";
		// read in the colors
		for (int r=0;r<image.height;r++) {
			vector<rgb> image_row;
			for (int c=0;c<image.width;c++) {
				rgb color;
				inputFile >> color.red;
				inputFile >> color.green;
				inputFile >> color.blue;
				image_row.push_back(color);
			}
			image.colors.push_back(image_row);
		}
	}

	else {
		cout << "Unable to open file.\n";
		exit(0);
	}
}

void ImageEngine::copyMetadata(Image &new_image) {
	new_image.magic_number = image.magic_number;
	//new_image.comment = image.comment;
	new_image.max_color = image.max_color;
	new_image.width = image.width;
	new_image.height = image.height;
}

void ImageEngine::scale_up(int factor) {
	// scale the image up depending on factor
	// Process: repeat each character in each
	// row and each character in each column
	Image new_image;
	copyMetadata(new_image);

	for (int r = 0; r < image.height; r++) {
		// duplicate each pixel in a row a factor of times
		vector<rgb> image_row;
		for (int c = 0; c < image.width; c++) {
			for (int i = 0; i < factor; i++) {
				image_row.push_back(image.colors[r][c]);
			}
		}
		// copy new row a factor number of times into the new image
		for (int j = 0; j < factor; j++) {
			// NOTE: what you want to push back is in the brackets
			// new_image.colors is what you are pushing to
			new_image.colors.push_back(image_row);
		}
	}
	
	new_image.width = image.width * factor;
	new_image.height = image.height * factor;

	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}
void ImageEngine::scale_down(int factor) {
	// scale the image down depending on factor
	// where factor means "divide image by factor"
	// e.g., a factor of 2 will make the image twice as
	// small in each direction

	// basically, need to skip copying a certain amount of pixels

	Image new_image;
	copyMetadata(new_image);

	for (int r = 0; r < image.height; r = r + factor) {
		// only copy every [factor-size] pixel
		vector<rgb> image_row;
		for (int c = 0; c < image.width; c = c + factor) {
				image_row.push_back(image.colors[r][c]);
		}
		new_image.colors.push_back(image_row);
	}

	new_image.width = image.width / factor;
	new_image.height = image.height / factor;


	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}
void ImageEngine::mirror(){
	// mirror the image left/right

	Image new_image;
	copyMetadata(new_image);

	// NOTE: REMEMBER TO SUBTRACT 1 SO AS TO NOT RUN OFF END OF ARRAY
	for (int r = 0; r < image.height; r++) {
		vector<rgb> image_row;
		for (int c = 0; c < image.width; c++) {
			image_row.push_back(image.colors[r][image.width - c - 1]);
		}
		new_image.colors.push_back(image_row);
	}

	new_image.width = image.width;
	new_image.height = image.height;



	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}

void ImageEngine::flip(){
	// flip the image upside down

	Image new_image;
	copyMetadata(new_image);

	// NOTE: REMEMBER TO SUBTRACT 1 SO AS TO NOT RUN OFF END OF ARRAY
	for (int r = 0; r < image.height; r++) {
		vector<rgb> image_row;
		for (int c = 0; c < image.width; c++) {
			image_row.push_back(image.colors[image.height - r - 1][c]);
		}
		new_image.colors.push_back(image_row);
	}

	new_image.width = image.width;
	new_image.height = image.height;

	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}

void ImageEngine::psychedelic(){
	// this rotates the color scheme
	// as follows: r-g-b becomes b-r-g

	Image new_image;
	copyMetadata(new_image);

	for (int r = 0; r < image.height; r++) {
		vector<rgb> image_row;
		for (int c = 0; c < image.width; c++) {
			rgb color;
			color.red = image.colors[r][c].blue;
			color.green = image.colors[r][c].red;
			color.blue = image.colors[r][c].green;
			image_row.push_back(color);
		}
		new_image.colors.push_back(image_row);
	}

	// copy new image to old image (vectors can do this
	// with an assignment overload!)
	image = new_image;
}

void ImageEngine::save(string filename) {
	ofstream outputfile;

	outputfile.open (filename.c_str());
	outputfile << image.magic_number << "\n";
	outputfile << image.width << " " << image.height << "\n";
	outputfile << image.max_color << "\n";
	vector<vector<rgb> >::iterator r;
	vector<rgb>::iterator c;

	for (r=image.colors.begin();r!=image.colors.end();r++) {
		for (c=r->begin();c<r->end();c++) {
			outputfile << c->red << " ";
			outputfile << c->green << " ";
			outputfile << c->blue << "  ";
		}
		outputfile << "\n";
	}
	outputfile.close();
}

/*
 * ImageEngine.h
 * A tool for tranforming PNM images
 *
 *  Created on: Mar 29, 2015
 *      Author: Chris Gregg
 */

#ifndef ImageEngine_H_
#define ImageEngine_H_

#include<vector>
#include<string>

// the three colors represented in the image
struct rgb {
	int red,green,blue;
};

// A .ppm file has the following format:
// magic number (P3)
// width height
// max_color
// r0_0 g0_0 b0_0  r0_1 g0_1 b0_1  r0_2 g0_2 b0_2 ...
// r1_0 g1_0 b1_0  r1_1 g1_1 b1_1  r1_2 g1_2 b1_2 ...
// etc. until all rows have been defined
//
// .ppm files can also have comments, but this program does not
// handle ppms with comments.
// See: http://en.wikipedia.org/wiki/Netpbm_format#PPM_example

struct Image {
	std::string magic_number; // should be "P3"
	int width;
	int height;
	int max_color; // the maximum image amount
	std::vector<std::vector<rgb> >colors; // the 2D array of colors
};

class ImageEngine {
public:
	ImageEngine(); // constructor (not needed)
	~ImageEngine(); // destructor (not needed)

	// reads in the .ppm file
	void readImage(std::string filename);

	// scales the image up by an integer factor, e.g., 2x or 3x
	void scale_up(int factor);

	// scales the image down by an integer factor, e.g., 2 (half-size)
	void scale_down(int factor);

	// mirrors the image left-right
	void mirror();

	// flips the image vertically
	// (note: _not_ a 180 degree rotation!)
	void flip();

	// rotates the rgb colors so that r==g, g==b, b==r
	void psychedelic();

	// saves the output to a new .ppm file
	void save(std::string filename);
private:
	// copies just the metadata for the image to another
	// image (not the color data)
	void copyMetadata(Image &new_image);

	// the image itself
	Image image;
};

#endif /* ImageEngine_H_ */

/*
 * mimageEngn.cpp
 *
 *  Created on: Mar 29, 2015
 *      Author: Chris Gregg
 */
#include "ImageEngine.h"
#include <iostream>
#include <cctype>

using namespace std;

int main() {
	string filename;
	char command;
	int scale_factor;
	ImageEngine imageEng;
	cout << "Filename: ";
	cin >> filename;

	cout << "Scale up or down, mirror,\n";
	cout << "flip, or psychedelic? (u/d/m/f/p): ";
	cin >> command;
	command = tolower(command);

	if (command=='u' or command=='d') {
		cout << "Scale factor: ";
		cin >> scale_factor;
	}
	imageEng.readImage(filename);
	cout << "Done reading image.\n";
	switch(command) {
	case 'u':
		imageEng.scale_up(scale_factor);
		break;
	case 'd':
		imageEng.scale_down(scale_factor);
		break;
	case 'm':
		imageEng.mirror();
		break;
	case 'f':
		imageEng.flip();
		break;
	case 'p':
		imageEng.psychedelic();
		break;
	default:
		cout << "Not a recognized command!\n";
		return 0;
	}

	cout << "Filename for save? ";
	cin >> filename;

	cout << "To see your new image, type the following:\n";
	cout << "  eog " << filename << "\n";

	imageEng.save(filename);
	return 0;
}

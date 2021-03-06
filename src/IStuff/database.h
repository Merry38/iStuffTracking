/**
* @file database.h
* @brief Library for Database class
* @author Mattia Rizzini
* @version 0.1.3
* @date 2013-07-14
*/

#ifndef DATABASE_H__
#define DATABASE_H__

// Standard C++ libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>

// Custom header files
#include "object.h"

// OpenCV libraries
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/video/video.hpp"

// Boost libraries
#include "boost/filesystem.hpp"
#include "boost/lambda/bind.hpp"
#include "boost/foreach.hpp"

#include "boost/archive/binary_oarchive.hpp"
#include "boost/archive/binary_iarchive.hpp"

#include "boost/random.hpp"

#include "boost/serialization/vector.hpp"
#include "serialize_opencv.h"

#include "boost/lexical_cast.hpp"

extern bool debug;

namespace IStuff {
	class Database {
		private:
			const float NNDR_RATIO = 0.6;
			const float MIN_INLIER_RATIO = 0.5;
			const int MATCH_THRESHOLD = 20;

			std::string dbPath;
			std::string dbName;

			cv::FlannBasedMatcher matcher;
			std::vector< std::vector< Label > > labelDB;
			std::vector< std::vector< cv::KeyPoint > > keypointDB;
			std::vector< cv::Mat > descriptorDB;

		public:
			Database( std::string, std::string );
			virtual ~Database();

			Object match( cv::Mat );

		private:
			void build( std::string );
			void load();
			void save();
	};

	class DBCreationException: public std::exception {
		public: virtual const char* what() const throw() {
			return "***Error in Database creation, no files in given directory or wrong path given***\n";
		}
	};

	class DBLoadingException: public std::exception {
		public: virtual const char* what() const throw() {
			return "***Error in Database loading, database seems to exist but files are missing***\n";
		}
	};

	class DBSavingException: public std::exception {
		public: virtual const char* what() const throw() {
			return "***Error in Database saving***\n";
		}
	};
};

#endif

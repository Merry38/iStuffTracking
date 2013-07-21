/**
 * @file tracker.h
 * @brief Header file relative to the class IStuff::Tracker.
 * @author Maurizio Zucchelli
 * @version 0.1.0
 * @date 2013-07-17
 */

#ifndef I_STUFF_TRACKER_H__
#define I_STUFF_TRACKER_H__

#include <iostream>
#include <map>

#include <boost/thread.hpp>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/nonfree/nonfree.hpp"

#include "object.h"

extern bool debug;

namespace IStuff
{
	class Manager;

	class Tracker
	{
		/* Attributes */
		private:
			const static char TAG[];

			std::auto_ptr<boost::thread> running;
			boost::shared_mutex object_update;

			Object original_object;
			cv::Mat original_frame;
			std::map<Label, std::vector<cv::Point2f> > original_features;
			cv::Mat future_frame;

			cv::Ptr<cv::FeatureDetector> detector;

		/* Methods */
		public:
			/* Constructors and Destructors */
			Tracker();
			virtual ~Tracker();

			/* Setters */

			/* Getters */
			bool isRunning() const;

			/* Other methods */
			Object trackFrame(cv::Mat);
			void sendMessage(int, void*, void* = NULL);
		private:
			void setObject(Object);
			void setObject(Object, cv::Mat);
			bool backgroundTrackFrame(cv::Mat, Manager*);
	};
}

#include "manager.h"

#endif /* defined I_STUFF_TRACKER_H__ */

//! [includes]
#include <opencv2/dnn.hpp>
#include <librealsense2/rs.hpp>
#include "../cv-helpers.hpp"

#include <iostream>
//! [includes]

int main( int argc, char** argv )
{
    auto data = pipe.wait_for_frames(); // Wait for next set of frames
    data = align_to.process(data); // Align color frame to depth import

    auto color_frame = data.get_color_frame(); // Get color frame
    auto depth_frame = data.get_depth_frame(); // Get depth frame
    auto infrared_frame = data.get_infrared_frame(1); // get left infrared frame

    auto color_mat = frame_to_mat(color_frame);
    auto depth_mat = frame_to_mat(depth_frame);
    auto infrared_mat = frame_to_mat(infrared_frame)

    //! [window]
    namedWindow( "color", WINDOW_AUTOSIZE );
    //! [window]
    //! [window]
    namedWindow( "depth", WINDOW_AUTOSIZE );
    //! [window]
    //! [window]
    namedWindow( "infrared", WINDOW_AUTOSIZE );
    //! [window]

    imshow("color",color_mat);
    imshow("depth",depth_mat);
    imshow("infrared",depth_mat);

    //! [wait]
    waitKey(0); // Wait for a keystroke in the window
    //! [wait]
    return 0;
}

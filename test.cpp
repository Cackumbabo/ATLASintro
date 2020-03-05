#include <opencv2/dnn.hpp>
#include <librealsense2/rs.hpp>
#include "../cv-helpers.hpp"

int main( int argc, char** argv )
{
    auto data = pipe.wait_for_frames();
    data = align_to.process(data);

    auto color_frame = data.get_color_frame();
    auto depth_frame = data.get_depth_frame();

    auto color_mat = frame_to_mat(color_frame);
    auto depth_mat = frame_to_mat(depth_frame);

    //! [window]
    namedWindow( "color", WINDOW_AUTOSIZE );
    //! [window]
    //! [window]
    namedWindow( "depth", WINDOW_AUTOSIZE );
    //! [window]

    imshow("color",color_mat);
    imshow("depth",depth_mat);

    //! [wait]
    waitKey(0); // Wait for a keystroke in the window
    //! [wait]
    return 0;
}

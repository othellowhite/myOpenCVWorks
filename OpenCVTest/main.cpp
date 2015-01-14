
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[])
{
    cv::VideoCapture capture(0); // 카메라 탐색
    
    if( !capture.isOpened() ) { // 카메라 인식 확인
        std::cerr << "Could not open camera" << std::endl;
        return 0;
    }
    
    capture.set(CV_CAP_PROP_FRAME_WIDTH, 832);  // 사진크기 가로 832
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480); // 사진크기 세로 480
    
    cv::Mat img; // 윈도우 선언
    
    int i=0;
    while (1) {
        
        capture>>img; // 카메라 인식 사진을 윈도우에 할당
        printf("%d times captured\n", i++);
        
        if (img.empty()) break; // 인식 사진이 없을 시 종료
        imshow("mycam", img); // 윈도우를 화면에 출력
        
        if (cv::waitKey(10)==27) break; // esc 키를 누르면 종료
    }
    cv::destroyAllWindows(); // 할당 메모리 해제
    
    printf("\n");
    
    return 0 ;
}


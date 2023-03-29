#include<opencv/highgui.h>
int main()
{
    IplImage*img=cvLoadImage("movie.jpg");
    cvShowImage("week07",img);
    cvWaitKey(0);
}

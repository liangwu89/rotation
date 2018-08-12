#include "rotation.h"
using namespace std;
int main(int argc, char** argv)
{
  Rotation rotationProcess = Rotation();
  Vector3d euler(0, 0, PI / 2);
  rotationProcess.setEuler(euler);
  rotationProcess.run();
  cout << rotationProcess.getRotationMat()<<endl;
  return 0;
}
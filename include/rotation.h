#include<Eigen/Dense>
#include<iostream>
using namespace Eigen;
using namespace std;
#define PI 3.1415926
class Rotation
{
public:
	Rotation();              //构造函数
	~Rotation(){}            //析构函数
	Matrix3d getRotationMat();//获取旋转矩阵
	Vector3d getEuler();     //获取欧拉角
	Quaterniond getQuatern();//获取四元数
	void setRotationMat(const Matrix3d& mat);//设置旋转矩阵
	void setEuler(const Vector3d& vec);      //设置欧拉角
	void setQuatern(const Quaterniond& qua);//设置四元数
	void run();                             //主程序
private:
	Matrix3d m_RotationMat; //旋转矩阵
	Vector3d m_euler;       //欧拉角
	Quaterniond m_quatern;  //四元数
private:
	void euler2RotMat();    //欧拉角转旋转矩阵
	void euler2Quatern();   //欧拉角转四元数
	void rotMat2euler();    //旋转矩阵转欧拉角
	void rotMat2Quatern();  //旋转矩阵转四元数 
	void quatern2Euler();   //四元数转欧拉角
	void quatern2RotMat();  //四元数转旋转矩阵
};
#include<Eigen/Dense>
#include<iostream>
using namespace Eigen;
using namespace std;
#define PI 3.1415926
class Rotation
{
public:
	Rotation();              //���캯��
	~Rotation(){}            //��������
	Matrix3d getRotationMat();//��ȡ��ת����
	Vector3d getEuler();     //��ȡŷ����
	Quaterniond getQuatern();//��ȡ��Ԫ��
	void setRotationMat(const Matrix3d& mat);//������ת����
	void setEuler(const Vector3d& vec);      //����ŷ����
	void setQuatern(const Quaterniond& qua);//������Ԫ��
	void run();                             //������
private:
	Matrix3d m_RotationMat; //��ת����
	Vector3d m_euler;       //ŷ����
	Quaterniond m_quatern;  //��Ԫ��
private:
	void euler2RotMat();    //ŷ����ת��ת����
	void euler2Quatern();   //ŷ����ת��Ԫ��
	void rotMat2euler();    //��ת����תŷ����
	void rotMat2Quatern();  //��ת����ת��Ԫ�� 
	void quatern2Euler();   //��Ԫ��תŷ����
	void quatern2RotMat();  //��Ԫ��ת��ת����
};
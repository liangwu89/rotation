// rotation.cpp : 定义控制台应用程序的入口点。
#include"rotation.h"
Rotation::Rotation()
{
	m_RotationMat.setIdentity(3, 3);
	m_euler.fill(0.0);
	m_quatern.setIdentity();
}

Matrix3d Rotation::getRotationMat()//获取旋转矩阵
{
	return m_RotationMat;
}

Vector3d Rotation::getEuler()     //获取欧拉角
{
	return m_euler; 
}
Quaterniond Rotation::getQuatern()//获取四元数
{
	return m_quatern;
}

void Rotation::setRotationMat(const Matrix3d& mat)//设置旋转矩阵
{
	m_RotationMat = mat;
}

void Rotation::setEuler(const Vector3d& vec)      //设置欧拉角
{
	m_euler = vec;
}

void Rotation::setQuatern(const Quaterniond& qua)//设置四元数
{
	m_quatern = qua;
}

void Rotation::euler2RotMat()    //欧拉角转旋转矩阵
{
	m_RotationMat = AngleAxisd(m_euler[1], Vector3d::UnitY()).matrix()*\
		AngleAxisd(m_euler[0], Vector3d::UnitX()).matrix()*\
		AngleAxisd(m_euler[2], Vector3d::UnitZ()).matrix();

	cout << "m_RotationMat:\n" << m_RotationMat << endl;
}

void Rotation::euler2Quatern()   //欧拉角转四元数
{
	euler2RotMat();
	m_quatern = m_RotationMat;
	cout << "m_quatern:\n" << m_quatern.coeffs() << endl;
}
void Rotation::rotMat2euler()    //旋转矩阵转欧拉角
{
	m_euler = m_RotationMat.eulerAngles(1, 0, 2);
}

void Rotation::rotMat2Quatern()  //旋转矩阵转四元数 
{
	m_quatern = m_RotationMat;
}

void Rotation::quatern2Euler()   //四元数转欧拉角
{
	euler2RotMat();
	rotMat2euler();
}

void Rotation::quatern2RotMat()  //四元数转旋转矩阵
{
	m_RotationMat = m_quatern.toRotationMatrix();
}

void Rotation::run()            //主程序
{
	euler2RotMat();
	euler2Quatern();
}









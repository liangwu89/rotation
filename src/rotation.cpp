// rotation.cpp : �������̨Ӧ�ó������ڵ㡣
#include"rotation.h"
Rotation::Rotation()
{
	m_RotationMat.setIdentity(3, 3);
	m_euler.fill(0.0);
	m_quatern.setIdentity();
}

Matrix3d Rotation::getRotationMat()//��ȡ��ת����
{
	return m_RotationMat;
}

Vector3d Rotation::getEuler()     //��ȡŷ����
{
	return m_euler; 
}
Quaterniond Rotation::getQuatern()//��ȡ��Ԫ��
{
	return m_quatern;
}

void Rotation::setRotationMat(const Matrix3d& mat)//������ת����
{
	m_RotationMat = mat;
}

void Rotation::setEuler(const Vector3d& vec)      //����ŷ����
{
	m_euler = vec;
}

void Rotation::setQuatern(const Quaterniond& qua)//������Ԫ��
{
	m_quatern = qua;
}

void Rotation::euler2RotMat()    //ŷ����ת��ת����
{
	m_RotationMat = AngleAxisd(m_euler[1], Vector3d::UnitY()).matrix()*\
		AngleAxisd(m_euler[0], Vector3d::UnitX()).matrix()*\
		AngleAxisd(m_euler[2], Vector3d::UnitZ()).matrix();

	cout << "m_RotationMat:\n" << m_RotationMat << endl;
}

void Rotation::euler2Quatern()   //ŷ����ת��Ԫ��
{
	euler2RotMat();
	m_quatern = m_RotationMat;
	cout << "m_quatern:\n" << m_quatern.coeffs() << endl;
}
void Rotation::rotMat2euler()    //��ת����תŷ����
{
	m_euler = m_RotationMat.eulerAngles(1, 0, 2);
}

void Rotation::rotMat2Quatern()  //��ת����ת��Ԫ�� 
{
	m_quatern = m_RotationMat;
}

void Rotation::quatern2Euler()   //��Ԫ��תŷ����
{
	euler2RotMat();
	rotMat2euler();
}

void Rotation::quatern2RotMat()  //��Ԫ��ת��ת����
{
	m_RotationMat = m_quatern.toRotationMatrix();
}

void Rotation::run()            //������
{
	euler2RotMat();
	euler2Quatern();
}









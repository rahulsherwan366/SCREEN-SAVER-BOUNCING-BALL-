#include"main.h"
#include"physics.h"
#include <iostream>
using namespace std;
#include<math.h>


void ball_collision(float cmi[3][50],float veli[3][50], float cmj[3][50],float velj[3][50],int i,int k)
{	//cout<<"abhi";
	//cout<<veli[2]<<endl;
	//cout<<velj[2]<<endl;
     //float r=0.2;
	float radial_vec_x =cmj[0][k]-cmi[0][i];
	float radial_vec_y =cmj[1][k]-cmi[1][i];
	float radial_vec_z =cmj[2][k]-cmi[2][i];
    //cout<<radial_vec_z<<endl;
	float radial_mod = ((radial_vec_x*radial_vec_x) + (radial_vec_y*radial_vec_y) + (radial_vec_z*radial_vec_z));
    //if(radial_mod<=(4*r*r));

	float dot_x=veli[0][i]*radial_vec_x;
	float dot_y=veli[1][i]*radial_vec_y;
	float dot_z=veli[2][i]*radial_vec_z;
	float dot_res = (dot_x+dot_y+dot_z)/(radial_mod);
    //cout<<dot_z<<endl;
	float axial_veli_x = dot_res*radial_vec_x;
	float axial_veli_y = dot_res*radial_vec_y;
	float axial_veli_z = dot_res*radial_vec_z;
    //cout<<axial_veli_z<<endl;
	float eq_vel_x = veli[0][i] - axial_veli_x;
	float eq_vel_y = veli[1][i] - axial_veli_y;
	float eq_vel_z = veli[2][i] - axial_veli_z;
	//cout<<eq_vel_z<<endl;
	float dotj_x=velj[0][k]*radial_vec_x;
	float dotj_y=velj[1][k]*radial_vec_y;
	float dotj_z=velj[2][k]*radial_vec_z;
	float dotj_resj = (dotj_x+dotj_y+dotj_z)/(radial_mod);
    //cout<<dotj_z<<endl;
	float axial_velj_x = dotj_resj*radial_vec_x;
	float axial_velj_y = dotj_resj*radial_vec_y;
	float axial_velj_z = dotj_resj*radial_vec_z;
	//cout<<axial_velj_z<<endl;
	float eq_vel_xj = velj[0][k] - axial_velj_x;
	float eq_vel_yj = velj[1][k] - axial_velj_y;
	float eq_vel_zj = velj[2][k] - axial_velj_z;
	///cout<<eq_vel_zj<<endl;

	 veli[0][i] = eq_vel_x + axial_velj_x;
	 veli[1][i] = eq_vel_y + axial_velj_y;
	 veli[2][i] = eq_vel_z + axial_velj_z;

     velj[0][k] = eq_vel_xj + axial_veli_x;
	 velj[1][k] = eq_vel_yj + axial_veli_y;
	 velj[2][k] = eq_vel_zj + axial_veli_z;

	
	// cout<< veli[0]<<" "<<veli[1]<<" "<<veli[2]<<endl;
	 // cout<< velj[0]<<" "<<velj[1]<<" "<<velj[2]<<endl;
}

  void overlap(float cm[3][50],int i,int k,float r1,float r2)
  {
	float distance;
	distance= ((cm[0][i]-cm[0][k])*(cm[0][i]-cm[0][k])) + ((cm[1][i]-cm[1][k])*(cm[1][i]-cm[1][k])) + ((cm[2][i]-cm[2][k])*(cm[2][i]-cm[2][k]));
	float r;
	if(r2>=r1)
		r=r2;
	else 
		r=r1;
	if(distance<=(4*r1*r2))
	{

	cm[0][i] = cm[0][i] -0.01*(cm[0][k] - cm[0][i]);
	cm[1][i] = cm[1][i] -0.01*(cm[1][k] - cm[1][i]);
	cm[2][i] = cm[2][i] -0.01*(cm[2][k] - cm[2][i]);

	}

}

	void col2 (float cmi[3][50],float veli[3][50], float cmj[3],float velj[3],int i) 
{	
	float radial_vec_x =cmj[0]-cmi[0][i];
	float radial_vec_y =cmj[1]-cmi[1][i];
	float radial_vec_z =cmj[2]-cmi[2][i];
    //cout<<radial_vec_z<<endl;
	float radial_mod = ((radial_vec_x*radial_vec_x) + (radial_vec_y*radial_vec_y) + (radial_vec_z*radial_vec_z));
    //if(radial_mod<=(4*r*r));

	veli[0][i] = veli[0][i] - velj[0];
	veli[1][i] = veli[1][i] - velj[1];
	veli[2][i] = veli[2][i] - velj[2];

	float dot_x=veli[0][i]*radial_vec_x;
	float dot_y=veli[1][i]*radial_vec_y;
	float dot_z=veli[2][i]*radial_vec_z;
	float dot_res = (dot_x+dot_y+dot_z)/(radial_mod);
    //cout<<dot_z<<endl;
	float axial_veli_x = dot_res*radial_vec_x;
	float axial_veli_y = dot_res*radial_vec_y;
	float axial_veli_z = dot_res*radial_vec_z;
    //cout<<axial_veli_z<<endl;
	veli[0][i] = veli[0][i] - 2*axial_veli_x;
	veli[1][i] = veli[1][i] - 2*axial_veli_y;
	veli[2][i] = veli[2][i] - 2*axial_veli_z;
	//cout<<eq_vel_z<<endl;
	
}



  void overlap_static_terrain(float cm[3][50],int i,float cmj[3],float r1,float r2)
  {
	float distance;
	distance= ((cm[0][i]-cmj[0])*(cm[0][i]-cmj[0])) + ((cm[1][i]-cmj[1])*(cm[1][i]-cmj[1])) + ((cm[2][i]-cmj[2])*(cm[2][i]-cmj[2]));
	float r;

	if(distance<=(0.49))
	{

	cm[0][i] = cm[0][i] +0.01*(cm[0][i] - cmj[0]);
	cm[1][i] = cm[1][i] +0.01*(cm[1][i] - cmj[1]);
	cm[2][i] = cm[2][i] +0.01*(cm[2][i] - cmj[2]);

	}

}

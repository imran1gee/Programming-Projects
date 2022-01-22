#include<iostream>
#include<math.h>
#include <fstream>
using namespace std;
int main(){
float a=1;
float b=1;
double g=1;
double d=1;
int n;
cout<<"Enter the number of iterations:"<<endl;
cin>>n;
double x[n+1],y[n+1],t[n+1],k1,k2,k3,k4,w1,w2,w3,w4;
x[0]=0.9, y[0]=1.8, t[0]=0;
double h=0.1;
ofstream myfile;
  myfile.open ("example.txt");
for(int i=1;i<=n;i++){

t[i]=t[i-1]+h;

k1=a*x[i-1]-b*x[i-1]*y[i-1];
k2=a*x[i-1]-b*x[i-1]*(y[i-1]+k1/2);
k3=a*x[i-1]-b*x[i-1]*(y[i-1]+k2/2);
k4=a*x[i-1]-b*x[i-1]*(y[i-1]+k3);

w1=d*x[i-1]*y[i-1]-g*y[i-1];
w2=d*(x[i-1]+w1/2)*y[i-1]-g*y[i-1];
w3=d*(x[i-1]+w2/2)*y[i-1]-g*y[i-1];
w4=d*(x[i-1]+w3)*y[i-1]-g*y[i-1];

x[i]=x[i-1]+h/6*(k1+2*k2+2*k3+k4);
y[i]=y[i-1]+h/6*(w1+2*w2+2*w3+w4);

  myfile << t[i]<<"  "<<x[i]<<"  "<<y[i]<<endl;
}
myfile.close();
}

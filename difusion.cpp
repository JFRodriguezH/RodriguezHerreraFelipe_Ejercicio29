#include <iostream>
#include <fstream>

/*dP/dt = D* d^2P/dx^2 + s */
int const Nx = 30;
float const Dx = 2.0/Nx;
float const Dt = 0.001;
float const D = 1.0;
float const S = 1.0;
float const tf = 1.0;
float const x01 = 0.0;
float const x02 = 0.0;
int const Nt = (tf/Dt)+1;


void buildg(float** g);
void avance(float** g, float* prev, float* next);
std::ofstream outfile;

int main(){
	
	float** g = new float*[Nx];
	for(int i=0;i<Nx;i++){
		g[i] = new float[Nx];
	}
	buildg(g);

	float* temp = new float[Nx];
	float* sol = new float[Nx];
	
	sol[0] = x01;
	temp[0] = x01;
	sol[Nx-1] = x02;
	temp[Nx-1] = x02;
	
	float t = 0;
	outfile.open("difusion.dat");	
	for(int i=0;i<Nt;i++){
		for(int j=0;j<Nx;j++){
			outfile<<sol[j]<<" ";
		}
		outfile<<t<<std::endl;
		t += Dt;
		avance(g, temp, sol);
	}
	outfile.close();
		
	delete [] g;
	delete [] sol;
	delete [] temp;
	return 0;
}


void buildg(float** g){
	float temp = D*Dt/(Dx*Dx);
	for(int i=1;i<Nx-1;i++){
		for(int j=1;j<Nx-1;j++){
			if(i==j){
				g[i][j]=-2.0*temp+1;
				if(j!=0){
					g[i][j-1]=1.0*temp;
				}
				if(j!=(Nx-1)){
					g[i][j+1]=1.0*temp;
				}
			}
		}
	}
}

void avance(float** g, float* prev, float* next){
	float temp;
	for(int j=1;j<Nx-1;j++){
		temp = 0;
		for(int k=0;k<Nx;k++){
			temp += g[j][k]*prev[k];	
		}
		next[j] = temp+Dt*S;
	}
	for(int k=0;k<Nx;k++){
		prev[k] = next[k];	
	}
}
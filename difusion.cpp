#include <iostream>
#include <fstream>

/*dP/dt = D* d^2P/dx^2 + s */
float const D = 1.0;
float const S = 1.0;
float const tf = 1.0;


void buildg(float** g, int Nx, float Dt, float Dx);
void avance(float** g, float* prev, float* next, int Nx, float Dt);
std::ofstream outfile;

int main(){
    
	/*A*/
    int Nx = 30;
    float Dx = 2.0/Nx;
    int Nt = 442;
	float Dt = tf/Nt;
	
	float** g_A = new float*[Nx];
	for(int i=0;i<Nx;i++){
		g_A[i] = new float[Nx];
	}
	buildg(g_A, Nx, Dt, Dx);
	
	float* temp_A = new float[Nx];
	float* sol_A = new float[Nx];
	
	float t = 0;
	outfile.open("difusion_A.dat");	
	for(int i=0;i<Nt;i++){
        outfile<<t<<" ";
		for(int j=0;j<Nx;j++){
			outfile<<sol_A[j]<<" ";
		}
		outfile<<std::endl;
		t += Dt;
		avance(g_A, temp_A, sol_A, Nx, Dt);
	}
	outfile.close();
	
	/*B*/
    Nx = 31;
    Dx = 2.0/Nx;
    Nt = 442;
	Dt = tf/Nt;
	
	float** g_B = new float*[Nx];
	for(int i=0;i<Nx;i++){
		g_B[i] = new float[Nx];
	}
	buildg(g_B, Nx, Dt, Dx);
	
	float* temp_B = new float[Nx];
	float* sol_B = new float[Nx];
	
	t = 0;
	outfile.open("difusion_B.dat");	
	for(int i=0;i<Nt;i++){
        outfile<<t<<" ";
		for(int j=0;j<Nx;j++){
			outfile<<sol_B[j]<<" ";
		}
		outfile<<std::endl;
		t += Dt;
		avance(g_B, temp_B, sol_B, Nx, Dt);
	}
	outfile.close();

	
	/*C*/
    Nx = 29;
    Dx = 2.0/Nx;
	Nt = 442;
	Dt = tf/Nt;
	
	float** g_C = new float*[Nx];
	for(int i=0;i<Nx;i++){
		g_C[i] = new float[Nx];
	}
	buildg(g_C, Nx, Dt, Dx);
	
	float* temp_C = new float[Nx];
	float* sol_C = new float[Nx];
	
	t = 0;
	outfile.open("difusion_C.dat");	
	for(int i=0;i<Nt;i++){
        outfile<<t<<" ";
		for(int j=0;j<Nx;j++){
			outfile<<sol_C[j]<<" ";
		}
		outfile<<std::endl;
		t += Dt;
		avance(g_C, temp_C, sol_C, Nx, Dt);
	}
	outfile.close();
	
	
	
	/*D*/
    Nx = 30;
    Dx = 2.0/Nx;
    Nt = 432;
	Dt = tf/Nt;
	
	float** g_D = new float*[Nx];
	for(int i=0;i<Nx;i++){
		g_D[i] = new float[Nx];
	}
	buildg(g_D, Nx, Dt, Dx);
	
	float* temp_D = new float[Nx];
	float* sol_D = new float[Nx];
	
	t = 0;
	outfile.open("difusion_D.dat");	
	for(int i=0;i<Nt;i++){
        outfile<<t<<" ";
		for(int j=0;j<Nx;j++){
			outfile<<sol_D[j]<<" ";
		}
		outfile<<std::endl;
		t += Dt;
		avance(g_D, temp_D, sol_D, Nx, Dt);
	}
	outfile.close();
	
	delete [] sol_A;
	delete [] temp_A;
	delete [] g_A;
	
	delete [] sol_B;
	delete [] temp_B;
	delete [] g_B;
	
	delete [] sol_C;
	delete [] temp_C;
	delete [] g_C;
	
	delete [] sol_D;
	delete [] temp_D;
	delete [] g_D;

	return 0;
}


void buildg(float** g, int Nx, float Dt, float Dx){
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

void avance(float** g, float* prev, float* next, int Nx, float Dt){
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
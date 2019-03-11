#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <sstream>

using namespace std;

int main()
{
    const char letra[]={'A','B','C','D','E','F','G','H','I','J'};
    string F;
    int a=0;
    bool con=false;
    int k_x=0;
    int n_e; // numero de entradas
    int co;
    int fi;
    int inc[11]={0};
    int cm=0;
    int mod=0;
    int p=0;
    int sim[2][11][1024][11];
    int lim=0; //limite de F
    int in=0; //incremento de F
    int in2=0;
    int f[1024]={0}; // minterminos
    int n[11]={0};
    int prim[100][1024];
    int prim_x[1024][11]={0};
    int l_prim;
    int n_num=0;
    bool ban1=false;
    bool cero=false;
    int n_x[100]={0};
    int k_k[1024]={0};
    string n_l[2][11][1024];
    int ant[11][11]={0};
    int sig[11]={0};
    int n5=0;
    int x=0;
    bool cero_0=false;
    cout << "Ingrese numero de entradas" << endl;
    cin>>n_e;
    cout << "Ingrese F en minterminos(1,4,8,...)" << endl;
    cin>>F;
    fi=pow(2,n_e);
    // inicializar a 0
    for(int l=0;l<2;l++)
    {
        for(int i=0;i<=n_e;i++)
        {

                for(int j=0;j<fi;j++)
                {

                    for(int k=0;k<=n_e;k++)
                    {
                        sim[l][i][j][k]=0;

                    }


                }

        }
    }

    for(int i=0;F[i];i++)
    {
            if(F[i]==',')
            {
                f[in] = atoi(F.substr(lim,i).c_str());
                lim=i+1;
                in++;
            }


    }
    f[in] = atoi(F.substr(lim,F.length()).c_str());
    n_num=in;
    for(int i=0;i<=n_num;i++)
    {
            p=f[i];
            co=0;
            cm=0;
            do
            {
                mod=p % 2;
                p/=2;
                cm++;
                if(mod==1)
                {
                    co++;
                    n[cm]=1;
                }
            }while(p);//p!=0
            n_l[0][co][inc[co]]=static_cast<std::ostringstream*>(&(std::ostringstream() << f[i]))->str()+',';
            if(f[i]==0)
            {
                cero=true;
            }

            sim[0][co][inc[co]][0]=f[i];
            for (int j=1;j<=n_e;j++)
            {
               sim[0][co][inc[co]][j]=n[j];
               n[j]=0;
            }
            inc[co]++;

    }

//Bucle------------------------------------------------------
do
{
    x=0;
    for(int i=0;i<=n_e;i++)
    {
        a=0;
            for(int j=0;sim[0][i][j][0];j++)
            {
                con=false;
                for(int l=0;sim[0][i+1][l][0];l++)
                {
                    co=0;
                    ban1=false;
                    for(int k=1;k<=n_e;k++)
                    {


                        if(sim[0][i][j][k]==1 && sim[0][i+1][l][k]==1)
                        {
                            co++;//Numero de Posiciones iguales
                        }
                        else if((sim[0][i][j][k]==0 && sim[0][i+1][l][k]==1) || (sim[0][i][j][k]==1 && sim[0][i+1][l][k]==0))
                        {

                            k_x=k;//Localizacion de las x
                        }else if(((sim[0][i][j][k]==-1 && sim[0][i+1][l][k]==1) || (sim[0][i][j][k]==1 && sim[0][i+1][l][k]==-1))|| ((sim[0][i][j][k]==-1 && sim[0][i+1][l][k]==0) || (sim[0][i][j][k]==0 && sim[0][i+1][l][k]==-1)))
                        {
                            ban1=true;
                            break;
                        }

                    }
                    //-----encontrado_conjunto-----
                    if(co == i && ban1==false)
                    {
                        x++;
                        con=true;
                        sim[0][i+1][l][0]=-2;
                            //pasar duplicados
                            for(int m=1;m<=n_e;m++)
                            {
                               sig[m]=sim[0][i][j][m];
                            }
                            sig[k_x]=-1;
                            for(int r=0;ant[r][0];r++)
                            {

                                n5=0;
                                for(int m=1;m<=n_e;m++)
                                {
                                    if(ant[r][m]==sig[m])
                                    {
                                        n5++;
                                    }

                                }
                                if(n5==n_e)
                                {
                                    break;
                                }
                            }

                            if(n5!=n_e)
                            {

                                for(int m=1;m<=n_e;m++)
                                {
                                    sim[1][i][a][m]=sim[0][i][j][m];
                                    ant[a][m]=sim[0][i][j][m];
                                }
                                sim[1][i][a][k_x]=-1;
                                sim[1][i][a][0]=i+1;//------------------------
                                n_l[1][i][a]=n_l[0][i][j] + n_l[0][i+1][l];
                                ant[a][k_x]=-1;
                                ant[a][0]=1;
                                a++;
                            }




                    }
                }
                //-----No_encontrado_conjunto-----
                if(con==false && sim[0][i][j][0]!=-2)
                {
                    in=0;
                    lim=0;
                    cout<<"primo: "<<n_l[0][i][j]<<endl;
                    for(int m=0;n_l[0][i][j][m];m++)
                    {
                            if(n_l[0][i][j][m]==',')
                            {
                                prim[in2][in] = atoi(n_l[0][i][j].substr(lim,m).c_str());
                                lim=m+1;
                                k_k[in2]++;
                                in++;

                            }


                    }
                    for(int n=1;n<=n_e;n++)
                    {
                        prim_x[in2][n]=sim[0][i][j][n];
                    }
                    in2++;

                }

            }
//-----Hay 0 en f[i]---------
            if(cero==true)
            {
                cero=false;
                for(int l=0;sim[0][1][l][0];l++)
                {
                    cero_0=true;
                    sim[0][1][l][0]=-2;
                    n_l[1][0][l]=n_l[0][0][0] +  n_l[0][1][l];
                    sim[1][0][l][0]=1;
                    for(int k=1;k<=n_e;k++)
                    {
                        if(sim[0][1][l][k]==1)
                        {
                            sim[1][0][l][k]=-1;
                        }
                        else
                        {
                            sim[1][0][l][k]=sim[0][1][l][k];
                        }

                    }
                }
                if(cero_0==false)
                {
                    cout<<"primo: "<<n_l[0][0][0]<<endl;
                    k_k[in2]++;
                    in2++;
                }

            }



    }


//limpiar y cambiar arreglo
    for(int i=0;i<=n_e;i++)
    {

                for(int j=0;j<fi;j++)
                {

                    for(int k=0;k<=n_e;k++)
                    {
                        sim[0][i][j][k]=sim[1][i][j][k];
                        sim[1][i][j][k]=0;
                    }
                    n_l[0][i][j]=n_l[1][i][j];
                    n_l[1][i][j]=' ';


                }
    }

}while(x);
// Primos esenciales e imprimir
cout<<"F= ";
for(int i=0;i<=n_num;i++)
{
    in=0;
    for(int j=0;j<in2;j++)
    {
        for(int k=0;k<k_k[j];k++)
        {
            if(prim[j][k]==f[i])
            {
                in++;
                l_prim=j;
            }
        }


    }
    if(in==1 && n_x[l_prim]==0)
    {

        n_x[l_prim]=1;
        for(int m=n_e;m>=1;m--)
        {

                if(prim_x[l_prim][m]==1)
                {
                    cout<<letra[n_e-m];
                }
                else if(prim_x[l_prim][m]==0)
                {
                    cout<<letra[n_e-m]<<"'";
                }

        }

            cout<<" + ";


    }


}
    cout<<endl;
    system("PAUSE");
    return 0;
}

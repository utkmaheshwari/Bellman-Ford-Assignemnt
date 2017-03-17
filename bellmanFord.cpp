//Name - Utkarsh Maheshwari
//Enrollment Number - 13115130
//Class - B.Tech, 4th Year, Electrical Engineering

//Bellman Ford Implementation
#include<bits/stdc++.h>
#include <sys/time.h>
#include<stdio.h>
#include<time.h>
using namespace std;

long long n,i,j,k;
long long maxV=200;//maxV is the number of iterations 

int main()
{
	long long ans[maxV+1];//Bellman Ford algorithm is applied for every graph 
	for(n=3;n<=maxV;++n){ //from number of vertices=3 to number of vertices=200
		long long edge[n+1][n+1];
		for(i=1;i<=n;++i){	   //all the graphs are assumed to be complete graphs with self 
			for(j=1;j<=n;++j){ //loops, hence E=O(V^2) and T(n)=O(V^3)
				edge[i][j]=rand()%10+1;//every edge in the graph is between 1 to 10
			}
		}
//		cout<<"Graph"<<endl;
//		for(i=1;i<=n;++i){
//			for(j=1;j<=n;++j){
//				cout<<edge[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		long long dist[n+1];
		dist[1]=0;// vertex with index 1 is the source vertex
		for(i=2;i<=n;++i){
			dist[i]=100000000;//initialise all the dist with very high value
		}
		
		struct timespec start;
		clock_gettime(CLOCK_MONOTONIC_RAW, &start);//start stores the system time at the
												   //beginning of Bellman Ford Algorithm
		for(i=1;i<n;++i){
			for(j=1;j<=n;++j){
				for(k=1;k<=n;++k){
					if(dist[k]+edge[k][j]<dist[j]){//core implementation of 
						dist[j]=dist[k]+edge[k][j];//Bellman Ford Algorithm
					}
				}
			}
		}
//		cout<<"Minimum Distance"<<endl;
//		for(i=1;i<=n;++i){
//			cout<<dist[i]<<" ";
//		}
//		cout<<endl;

		struct timespec end;
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);//end store system time at the termination  
		ans[n] = (end.tv_sec-start.tv_sec)*1000000+(end.tv_nsec-start.tv_nsec)/1000;
		//ans[n] stores the time taken in running the algorithm in micro-second resolution
	}
	for(i=3;i<=maxV;++i){
		cout<<i<<":"<<ans[i]<<endl;//running time of Bellman Ford Algorithm corresponding
								   //to the input size
	}
    return 0;
}

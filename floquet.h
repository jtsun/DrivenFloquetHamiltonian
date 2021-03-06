/*
 * floquet.h
 *
 *  Created on: Oct 15, 2014
 *      Author: Lin Dong
 */
#ifndef FLOQUET_H_
#define FLOQUET_H_
#include "stdcpp.h"
class cFloquet {
private:
	// mpi related:
	int _rank, _size, _root;
	int recvcount, sendcount, stride;
	int *sendbuf, *recvbuf;
	int *sendcounts, *displs, *recvcounts, *displs_r;
	double  *localEig, *TotalEig;
	int offset;
	// system parameter related:
	double  _h, _mu, _T, _Delta0, _v, _L, _kmax;
	double _J, _b, _a, _omega;
	int _ibdg, _PMAX, _NMAX, _SMAX, _pblock,_pblock4,  _NKX, _NKX2;
	char* chernsolver, *topo;
	double* _gauss_k, *_gauss_w_k;
	VectorXd  _bdg_E;
	MatrixXcd _bdg_V, _bdg_H;

public:
	cFloquet(const int rank, const int size, const int root){_rank = rank;_size=size;_root=root;}
	~cFloquet(){}

	void construction();
	void destruction();

	int compute_count(int,int);
	void distribution();
	void aggregation();
	void compute_chern();

	// --> overload member function update
	void update(int);
	void update(double, double);
	void update(double);

};
#endif /* FLOQUET_H_ */

#include <vector>
long segmentt(long i, long j, std::vector<long> &v){
	long mid=(i+j)/2;
	segmentt(i,mid,v)+segmentt(mid+1,j,v);
}
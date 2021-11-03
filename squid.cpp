#ifndef _GLIBCXX_NO_ASSERT
  #include <cassert>
  #endif
  #include <cctype>
  #include <cerrno>
  #include <cfloat>
  #include <ciso646>
  #include <climits>
  #include <clocale>
  #include <cmath>
  #include <csetjmp>
  #include <csignal>
  #include <cstdarg>
  #include <cstddef>
  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <ctime>

  #if __cplusplus >= 201103L
  #include <ccomplex>
  #include <cfenv>
  #include <cinttypes>
  #include <cstdbool>
  #include <cstdint>
  #include <ctgmath>
  #include <cwchar>
  #include <cwctype>
  #endif

  // C++
  #include <algorithm>
  #include <bitset>
  #include <complex>
  #include <deque>
  #include <exception>
  #include <fstream>
  #include <functional>
  #include <iomanip>
  #include <ios>
  #include <iosfwd>
  #include <iostream>
  #include <istream>
  #include <iterator>
  #include <limits>
  #include <list>
  #include <locale>
  #include <map>
  #include <memory>
  #include <new>
  #include <numeric>
  #include <ostream>
  #include <queue>
  #include <set>
  #include <sstream>
  #include <stack>
  #include <stdexcept>
  #include <streambuf>
  #include <string>
  #include <typeinfo>
  #include <utility>
  #include <valarray>
  #include <vector>

  #if __cplusplus >= 201103L
  #include <array>
  #include <atomic>
  #include <chrono>
  #include <condition_variable>
  #include <forward_list>
  #include <future>
  #include <initializer_list>
  #include <mutex>
  #include <random>
  #include <ratio>
  #include <regex>
  #include <scoped_allocator>
  #include <system_error>
  #include <thread>
  #include <tuple>
  #include <typeindex>
  #include <type_traits>
  #include <unordered_map>
  #include <unordered_set>
  #endif
using namespace std;

	int B[100000000];
	int N;
	int M;
	
	bool isAnswerLessEqual(int x){
		int count=1;
		int squid=0;
		for (int i=0; i<N; i++){
			if (B[i]>x){
				return false;
			}
			squid+=B[i];
			if (squid>x){
				squid=B[i];
				count++;
			}
		}
		if (count<=M){
			return true;
		} else {
			return false;
		}
	}

	
	int binarySearch(){
		int lower=0, upper=100000000;
		while (upper-lower>1){
			int mid = (lower+upper)/2;
			if (isAnswerLessEqual(mid)){
				upper=mid;
			} else {
				lower=mid+1;
			}
		}
		if (lower+1 == upper){
			if (isAnswerLessEqual(lower)==false){
				return 0;
			} else {
				return 1;
			}
		}
	}
	
	int main(){
		cin >> N >> M;
		for (int i=0; i<N; i++){
			cin >> B[i];
		}
		if (N==1){
			cout << B[0];
			return 0;
		}
		int t = binarySearch();
		cout << t;
	}
	




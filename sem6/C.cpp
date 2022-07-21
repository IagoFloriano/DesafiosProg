#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll busca(vector<pair <ll, vector<pair<ll,ll>>>>& grafo, ll inicio, ll destino){
	if(inicio == destino)
		return grafo[destino].first;

	if(inicio < destino){ 
		ll peso;
		for(auto i: grafo[inicio].second){
			if(i.first == inicio+1){
				peso = i.second;
				break;
  		}
		}
		if(grafo[inicio].first + peso < grafo[inicio+1].first){
			//cout << "fazendo rota: " << inicio<<"..."<<inicio+1<<"("<<peso<<")"<<endl;
			grafo[inicio+1].first = peso + grafo[inicio].first;
			return busca(grafo, inicio+1, destino);
		}
		return 1123456789;
	}

	ll melhor = 1123456789;
	for(auto i: grafo[inicio].second){
		if(grafo[inicio].first + i.second < grafo[i.first].first){
			//cout << "fazendo rota: " <<inicio << "..." << i.first << "("<<i.second<<")"<< endl;
			grafo[i.first].first = grafo[inicio].first + i.second;
			ll temp = busca(grafo, i.first, destino) + i.second;
			if (temp < melhor)
				melhor = temp;
		}
	}
	return melhor;
}

int main() {
	ll N, M, C, K;
	cin >> N >> M >> C >> K;

	vector<pair <ll, vector<pair<ll,ll>>>> grafo = vector<pair <ll, vector<pair<ll,ll>>>>(N,make_pair(1123456789,vector<pair<ll,ll>>(0)));

	for(ll i = 0; i < M; i++){
		ll U, V, P;
		cin >> U >> V >> P;
		grafo[U].second.push_back(make_pair(V, P));
		grafo[V].second.push_back(make_pair(U, P));
	}

	grafo[K].first = 0;
	busca(grafo, K, C-1);

	//for(ll i = 0; i < N; i++){
	//	cout << i<<"("<<grafo[i].first<<")" << "\t";
	//	for(auto j: grafo[i].second){
	//		cout << j.first << "("<<j.second<<") ";
	//	}
	//	cout << endl;
	//}

	cout << grafo[C-1].first << "\n";
}

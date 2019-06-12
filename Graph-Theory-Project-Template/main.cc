#include <iostream>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"
#include <string> //for string
#include <vector> //for vector
#include <fstream> //for ifstream
#include <limits.h> 
#include <stdio.h> 
#include <cstring>
#include "Positive_Negative.h"
#include "Add_Pathes.h"
#include <algorithm>  
#include <bits/stdc++.h> 
#define V 20

using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();


vector<pair<string, int>> Degree(){

	Vertex* H= nm ->get_all_nodes();
	vector<pair<string, int>> Vertex_Degree;
	
	while(H!=0){
		Vertex_Degree.push_back(make_pair(H->name,0));
		H = H->next;
	}
	
	Edge*_Edge= nm->elist;
	
	for(int i=0; i<Vertex_Degree.size(); i++){
		while(_Edge!=0){
			if((_Edge->head->name==Vertex_Degree[i].first)&&(_Edge->tail->name==Vertex_Degree[i].first)){
				Vertex_Degree[i].second=Vertex_Degree[i].second;
			//	cout<<" circle "<<endl;
			}
			else if(_Edge->head->name==Vertex_Degree[i].first){
				Vertex_Degree[i].second=Vertex_Degree[i].second+1;
			//	cout<<" +1 "<<endl;
			}
			else if(_Edge->tail->name==Vertex_Degree[i].first){
				Vertex_Degree[i].second=Vertex_Degree[i].second-1;
			//	cout<<" -1 "<<endl;
			}
			else{
				Vertex_Degree[i].second=Vertex_Degree[i].second;
			//	cout<<" none "<<endl;
			}
			_Edge=_Edge->next;
		}
//		cout<<endl<<endl;
		_Edge=nm->elist;
	}
	return Vertex_Degree;
//	for(int i=0 ;i<Vertex_Degree.size(); i++){
//		cout<<endl<<Vertex_Degree[i].first<<"  "<<Vertex_Degree[i].second<<endl;
//	}	
}

vector<pair<string,int>> Find_Imbalanced_Nodes (const vector<pair<string, int>> &_Degree){
	
	vector <pair<string,int>> Imbalanced_Nodes;
	
	for(int i=0; i<_Degree.size(); i++){
		if((_Degree[i].second==1) || (_Degree[i].second==-1))
			Imbalanced_Nodes.push_back(_Degree[i]);
	}
	
	return Imbalanced_Nodes;
	
}



int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
  
  
  
  
// A utility function to print the constructed distance array 
int printSolution(int dist[], int n) 
{ 
    printf("Vertex   Distance from Source to \n"); 
//    for (int i = 0; i < V; i++) 
//    printf("%d tt %d\n", i, dist[i]); 
	cout<<dist[n]<<endl;
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
int dijkstra(int graph[V][V], int src, int src1) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
	return dist[src1];
    // print the constructed distance array 
    //printSolution(dist, src1); 
} 

vector<OBJ>Finding_the_Additional_Paths(vector<string> positive,vector<string> negative){

	int graph[V][V];
	for(int i=0; i<V ; i++){
		for(int j=0; j<V; j++){
				graph[i][j]=0;
		}
	}
	
	Edge *Matrix_Edge = nm->elist;
	int row=0;
	int col=0;
	while(Matrix_Edge!=NULL){
		
		if(Matrix_Edge->head->name=="a") row=0;
		if(Matrix_Edge->head->name=="b") row=1;
		if(Matrix_Edge->head->name=="c") row=2;
		if(Matrix_Edge->head->name=="d") row=3;
		if(Matrix_Edge->head->name=="e") row=4;
		if(Matrix_Edge->head->name=="f") row=5;
		if(Matrix_Edge->head->name=="g") row=6;
		if(Matrix_Edge->head->name=="h") row=7;
		if(Matrix_Edge->head->name=="i") row=8;
		if(Matrix_Edge->head->name=="j") row=9;
		if(Matrix_Edge->head->name=="k") row=10;
		if(Matrix_Edge->head->name=="l") row=11;
		if(Matrix_Edge->head->name=="m") row=12;
		if(Matrix_Edge->head->name=="n") row=13;
		if(Matrix_Edge->head->name=="o") row=14;
		if(Matrix_Edge->head->name=="9") row=15;
		if(Matrix_Edge->tail->name=="a") col=0;
		if(Matrix_Edge->tail->name=="b") col=1;
		if(Matrix_Edge->tail->name=="c") col=2;
		if(Matrix_Edge->tail->name=="d") col=3;
		if(Matrix_Edge->tail->name=="e") col=4;
		if(Matrix_Edge->tail->name=="f") col=5;
		if(Matrix_Edge->tail->name=="g") col=6;
		if(Matrix_Edge->tail->name=="h") col=7;
		if(Matrix_Edge->tail->name=="i") col=8;
		if(Matrix_Edge->tail->name=="j") col=9;
		if(Matrix_Edge->tail->name=="k") col=10;
		if(Matrix_Edge->head->name=="l") col=11;
		if(Matrix_Edge->head->name=="m") col=12;
		if(Matrix_Edge->head->name=="n") col=13;
		if(Matrix_Edge->head->name=="o") col=14;
		if(Matrix_Edge->head->name=="9") col=15;
		
		graph[row][col]=Matrix_Edge->flowval;
		Matrix_Edge= Matrix_Edge->next;
	}
	OBJ data;
	vector<vector<OBJ>>pair;
	
    do  
    {  		
			vector<OBJ>_pair;
			for(int i=0; i<positive.size();i++ ){
				data.Negative=negative[i];
				data.Positive=positive[i];
				data.Additional_Paths=0;
				_pair.push_back(data);
				
			}
		pair.push_back(_pair);
    } while (next_permutation(positive.begin(),positive.end()));  

	

	int N_Dijkstra;
	int P_Dijkstra;
	for(int i=0; i<pair.size(); i++){
		for(int j=0; j<pair[i].size(); j++){
			if(pair[i][j].Negative=="a") N_Dijkstra=0;
			if(pair[i][j].Negative=="b") N_Dijkstra=1;
			if(pair[i][j].Negative=="c") N_Dijkstra=2;
			if(pair[i][j].Negative=="d") N_Dijkstra=3;
			if(pair[i][j].Negative=="e") N_Dijkstra=4;
			if(pair[i][j].Negative=="f") N_Dijkstra=5;
			if(pair[i][j].Negative=="g") N_Dijkstra=6;
			if(pair[i][j].Negative=="h") N_Dijkstra=7;
			if(pair[i][j].Negative=="i") N_Dijkstra=8;
			if(pair[i][j].Negative=="j") N_Dijkstra=9;
			if(pair[i][j].Negative=="k") N_Dijkstra=10;
			if(pair[i][j].Negative=="l") N_Dijkstra=11;
			if(pair[i][j].Negative=="m") N_Dijkstra=12;
			if(pair[i][j].Negative=="n") N_Dijkstra=13;
			if(pair[i][j].Negative=="o") N_Dijkstra=14;
			if(pair[i][j].Negative=="p") N_Dijkstra=15;
			if(pair[i][j].Positive=="a") P_Dijkstra=0;
			if(pair[i][j].Positive=="b") P_Dijkstra=1;
			if(pair[i][j].Positive=="c") P_Dijkstra=2;
			if(pair[i][j].Positive=="d") P_Dijkstra=3;
			if(pair[i][j].Positive=="e") P_Dijkstra=4;
			if(pair[i][j].Positive=="f") P_Dijkstra=5;
			if(pair[i][j].Positive=="g") P_Dijkstra=6;
			if(pair[i][j].Positive=="h") P_Dijkstra=7;
			if(pair[i][j].Positive=="i") P_Dijkstra=8;
			if(pair[i][j].Positive=="j") P_Dijkstra=9;
			if(pair[i][j].Positive=="k") P_Dijkstra=10;
			if(pair[i][j].Positive=="l") P_Dijkstra=11;
			if(pair[i][j].Positive=="m") P_Dijkstra=12;
			if(pair[i][j].Positive=="n") P_Dijkstra=13;
			if(pair[i][j].Positive=="o") P_Dijkstra=14;
			if(pair[i][j].Positive=="p") P_Dijkstra=15;
			pair[i][j].Additional_Paths=dijkstra(graph,N_Dijkstra,P_Dijkstra);
		}
	}
	
	vector<int>Summation;
	int sum=0;
	int j;
	
	for(int i=0; i<pair.size(); i++){
		for(j=0; j<pair[i].size(); j++){
			sum=sum+pair[i][j].Additional_Paths;
		}
		Summation.push_back(sum);
		sum=0;
	}

	int min=Summation[0];
	int min_index=0;
	for(int i=0; i<Summation.size(); i++){
		if(min<Summation[i]){
			min=Summation[i];
			min_index=i;
		}
		else{}
	}
	
	vector<OBJ>pairs_results;
	for(int j=0; j<pair[min_index].size(); j++){
		pairs_results.push_back(pair[min_index][j]);
	}
	
//	for(int i=0; i<pairs_results.size(); i++){
//			cout<<pairs_results[i].Negative<<pairs_results[i].Positive<<pairs_results[i].Additional_Paths<<endl;
//	}
	return pairs_results;
}

void printCircuit(vector< vector<int> > adj) 
{ 
    // adj represents the adjacency list of 
    // the directed graph 
    // edge_count represents the number of edges 
    // emerging from a vertex 
    unordered_map<int,int> edge_count; 
  
    for (int i=0; i<adj.size(); i++) 
    { 
        //find the count of edges to keep track 
        //of unused edges 
        edge_count[i] = adj[i].size(); 
    } 
  
    if (!adj.size()) 
        return; //empty graph 
  
    // Maintain a stack to keep vertices 
    stack<int> curr_path; 
  
    // vector to store final circuit 
    vector<int> circuit; 
  
    // start from any vertex 
    curr_path.push(0); 
    int curr_v = 0; // Current vertex 
  
    while (!curr_path.empty()) 
    { 
        // If there's remaining edge 
        if (edge_count[curr_v]) 
        { 
            // Push the vertex 
            curr_path.push(curr_v); 
  
            // Find the next vertex using an edge 
            int next_v = adj[curr_v].back(); 
  
            // and remove that edge 
            edge_count[curr_v]--; 
            adj[curr_v].pop_back(); 
  
            // Move to next vertex 
            curr_v = next_v; 
        } 
  
        // back-track to find remaining circuit 
        else
        { 
            circuit.push_back(curr_v); 
  
            // Back-tracking 
            curr_v = curr_path.top(); 
            curr_path.pop(); 
        } 
    } 
    // we've got the circuit, now print it in reverse




        ofstream outFile;
        outFile.open("Solution.txt", ios::out);
		
		if(!outFile){   //檢查檔案是否成功開啟
            cerr << "Can't open outFile!\n";
            exit(1);     //在不正常情形下，中斷程式的執行
        }
		outFile<<"********************************************************************************************************************************************"<<endl;
		outFile<<"Path :"<<endl;
		for (int i=circuit.size()-1; i>=0; i--) { 	
		if(circuit[i]==0)  outFile<<"a";
		if(circuit[i]==1)  outFile<<"b";
		if(circuit[i]==2)  outFile<<"c";
		if(circuit[i]==3)  outFile<<"d";
		if(circuit[i]==4)  outFile<<"e";
		if(circuit[i]==5)  outFile<<"f";
		if(circuit[i]==6)  outFile<<"g";
		if(circuit[i]==7)  outFile<<"h";
		if(circuit[i]==8)  outFile<<"i";
		if(circuit[i]==9)  outFile<<"j";
		if(circuit[i]==10) outFile<<"k";
		if(circuit[i]==11) outFile<<"l";
		if(circuit[i]==12) outFile<<"m";
		if(circuit[i]==13) outFile<<"n";
		if(circuit[i]==14) outFile<<"o";
		if(circuit[i]==15) outFile<<"p";
        if (i) 
           outFile<<" -> "; 
    }
outFile<<endl;
		
cout<<"********************************************************************************************************************************************"<<endl;
cout<<"Path :"<<endl;
	for (int i=circuit.size()-1; i>=0; i--) { 	
		if(circuit[i]==0)  cout<<"a";
		if(circuit[i]==1)  cout<<"b";
		if(circuit[i]==2)  cout<<"c";
		if(circuit[i]==3)  cout<<"d";
		if(circuit[i]==4)  cout<<"e";
		if(circuit[i]==5)  cout<<"f";
		if(circuit[i]==6)  cout<<"g";
		if(circuit[i]==7)  cout<<"h";
		if(circuit[i]==8)  cout<<"i";
		if(circuit[i]==9)  cout<<"j";
		if(circuit[i]==10) cout<<"k";
		if(circuit[i]==11) cout<<"l";
		if(circuit[i]==12) cout<<"m";
		if(circuit[i]==13) cout<<"n";
		if(circuit[i]==14) cout<<"o";
		if(circuit[i]==15) cout<<"p";
        if (i) 
           cout<<" -> "; 
    }
cout<<endl;


return;
} 

void Find_Path(vector<OBJ>pairs_results){

	Path *path;
	path=new Path();
	path->append(nm->elist);
	
	int sum=0;
	vector<OBJ1>Add_Pathes;
	for(int i=0; i<pairs_results.size(); i++){
		vector<vector<Edge *>> avail_paths = path->find_paths(pairs_results[i].Negative,pairs_results[i].Positive);
		int min=0;
		int _x=0;
		for(int x=0;x<path->paths.size();x++){
			for(int y=0;y<path->paths.at(x).size();y++){
				int S =0;
				Edge*Add_Path_Flowval=nm->get_edge(path->paths.at(x).at(y)->head->name,path->paths.at(x).at(y)->tail->name);
                S=Add_Path_Flowval->flowval;
				sum=sum+S;
			  //cout << path->paths.at(x).at(y)->head->name << "->" << path->paths.at(x).at(y)->tail->name << " ";
			}
			
			if(x==0){
				min=sum;
			}
			else{
				if(sum<=min){
					min=sum;
					_x=x;
				}
				else{}
			}	
		}
		
        for(int j=0;j<path->paths.at(_x).size();j++){
			OBJ1 data;
			data.head=path->paths.at(_x).at(j)->head->name;
			data.tail=path->paths.at(_x).at(j)->tail->name;
			Edge*Add_Path_Flowval=nm->get_edge(path->paths.at(_x).at(j)->head->name, path->paths.at(_x).at(j)->tail->name);
			data.flowval=Add_Path_Flowval->flowval;
			Add_Pathes.push_back(data);
        }
	}


	Edge *pre_total= nm->elist;
	vector<int>total;
    while(pre_total!=NULL) {
        total.push_back(pre_total->flowval);
        pre_total=pre_total->next;
    }
	
	for(int i=0; i<Add_Pathes.size(); i++){
		total.push_back(Add_Pathes[i].flowval);
	}
	

	for(int i=0; i<Add_Pathes.size(); i++){
	
	//cout<<Add_Pathes[i].head<<" "<<Add_Pathes[i].tail<<" "<<Add_Pathes[i].flowval<<endl; 
		nm->connect(Add_Pathes[i].head,Add_Pathes[i].tail);
	}

	string adj_name;
	vector<vector<int> > adj(V); 
	Edge *traversal = nm->elist;
	int row=0;
	int col=0;
	while(traversal!=NULL) {
		traversal->head->name;
		if(traversal->head->name=="a") row=0;
		if(traversal->head->name=="b") row=1;
		if(traversal->head->name=="c") row=2;
		if(traversal->head->name=="d") row=3;
		if(traversal->head->name=="e") row=4;
		if(traversal->head->name=="f") row=5;
		if(traversal->head->name=="g") row=6;
		if(traversal->head->name=="h") row=7;
		if(traversal->head->name=="i") row=8;
		if(traversal->head->name=="j") row=9;
		if(traversal->head->name=="k") row=10;
		if(traversal->head->name=="l") row=11;
		if(traversal->head->name=="m") row=12;
		if(traversal->head->name=="n") row=13;
		if(traversal->head->name=="o") row=14;
		if(traversal->head->name=="p") row=15;
		if(traversal->tail->name=="a") col=0;
		if(traversal->tail->name=="b") col=1;
		if(traversal->tail->name=="c") col=2;
		if(traversal->tail->name=="d") col=3;
		if(traversal->tail->name=="e") col=4;
		if(traversal->tail->name=="f") col=5;
		if(traversal->tail->name=="g") col=6;
		if(traversal->tail->name=="h") col=7;
		if(traversal->tail->name=="i") col=8;
		if(traversal->tail->name=="j") col=9;
		if(traversal->tail->name=="k") col=10;
		if(traversal->tail->name=="l") col=11;
		if(traversal->tail->name=="m") col=12;
		if(traversal->tail->name=="n") col=13;
		if(traversal->tail->name=="o") col=14;
		if(traversal->tail->name=="p") col=15;
		adj[row].push_back(col);
        traversal=traversal->next;
    }
	int Total=0;
	for(int i=0; i<total.size(); i++){
	Total=total[i]+Total;
	}
	printCircuit(adj);
	cout<<endl<<"total :"<<endl;
	cout<<Total<<endl;
	
	cout<<"********************************************************************************************************************************************"<<endl;
	ofstream outFile;
        outFile.open("Solution.txt", ios::app);
		
		if(!outFile){   //檢查檔案是否成功開啟
            cerr << "Can't open outFile!\n";
            exit(1);     //在不正常情形下，中斷程式的執行
        }
	outFile<<endl<<"total :"<<endl;
	outFile<<Total<<endl;
	outFile<<"********************************************************************************************************************************************"<<endl;
	return;
}	






int main(int argc, char** argv){

// read from file
    nm->interpret("/home/cav15/Chinese-Post-Man/Graph-Theory-Project-Template/Demo/cycle.txt");

/*     1.Degreed()      */
/*	   2.Find_Imbalanced_Nodes() */

	vector<pair<string,int>>Imbalanced_Nodes;
	
	Imbalanced_Nodes=Find_Imbalanced_Nodes(Degree());
	
	vector<string>positive;
	vector<string>negative;
/*		分正負分別存進vec	*/	
	for(int i=0 ;i<Imbalanced_Nodes.size(); i++){
		if(Imbalanced_Nodes[i].second>0)
			positive.push_back(Imbalanced_Nodes[i].first);
		else if(Imbalanced_Nodes[i].second<0)
			negative.push_back(Imbalanced_Nodes[i].first);
		else{}
	}

/*		建 adjacency matrix		*/

	vector<OBJ>pairs_results=Finding_the_Additional_Paths(positive,negative);
/*		找路徑以及路徑長度  	*/
	Find_Path(pairs_results);

	
	
	return 0;
	
	
	
	
	
}
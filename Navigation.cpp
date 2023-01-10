#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>

#include "Navigation.h"

using namespace std;

Navigation::Navigation(){}

Navigation::~Navigation(){}

bool Navigation::readNetwork(string _mapName){
    fstream map;
    string line;

    map.open(_mapName, ios::in);
    getline(map, line);
    if(line.size() == 0){
        return false;
    }
    this->numNodes = stoi(line);
    for(int i = 0; i < numNodes; i++){
        this->distanceMap.push_back({});
        while(this->distanceMap[i].size() < numNodes){
            map >> line;
            this->distanceMap[i].push_back(stoi(line));
        }
        //cout << "row " << i << " length " << distanceMap[i].size() << endl;
    }  

    map.close();
    /* test to make sure file was read in properly
    for(int i = 0; i < this->distanceMap.size(); i++){
        for(int j = 0; j < this->distanceMap.size(); j++){
            cout << this->distanceMap[i][j] << " ";
        }
        cout << endl;
    }
    */
    return true;
}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd){
    priority_queue<Node, vector<Node>, Node> pathQueue;

    Node current;
    Node newNode;
    current.cost = 0;
    current.path.push(_startInd);
    pathQueue.push(current);

    while(pathQueue.top().path.back() != _endInd){
        current = pathQueue.top();
        pathQueue.pop();

        //cout << "Paths from node " << current.path.back() << ": ";
        //for each node, check if there is a connection to current node and if so, add a new node to the list extending the path to that node.
        for(int i = 0; i < this->numNodes; i++){
            if(distanceMap[current.path.back()][i] > 0){
                //cout << i << " ";
                newNode = current;
                newNode.cost += distanceMap[current.path.back()][i];
                newNode.path.push(i);
                pathQueue.push(newNode);
            }
        }
        //cout << endl;
    }
    return pathQueue.top().path;
}

void Navigation::printPath(queue<int> _path){
    //cout << "Path from " << _path.front() << " to " << _path.back() << ": ";
    cout << _path.front();
    _path.pop();

    while(!_path.empty()){
        cout << ", " << _path.front();
        _path.pop();
    }
    cout << endl;
}
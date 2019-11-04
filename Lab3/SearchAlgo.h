//
// Created by Ryan on 11/2/19.
//

#ifndef LAB3_SEARCHALGO_H
#define LAB3_SEARCHALGO_H

#include "Algo.h"
#include <string>

class SearchAlgo : Algo{
public:
     void Load(string fileName) ;
     void Execute() ;
     void Display() ;

     void Stats(string type) ;
     void Select(int sortAlgo);
     void Save(string filePath);
     void Configure();
};


#endif //LAB3_SEARCHALGO_H

#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <qdebug.h>
#include "Question.h"
#include "Participant.h"
#include "Observer.h"
using namespace std;

template <typename T>
class Repository:public Observable
{
	vector<T> elems;
	string path;
	void readFromFile();
public:
	vector<T> getElems() { return elems; }
	void add(T elem);
	Repository(string p);
	Repository() {}
	~Repository();
	void addScore(T elem, int score);
	void writeToFile();
};

template<typename T>
void Repository<T>::readFromFile()
{
	if (path == "")
		return;
	ifstream fin(path);
	T ob;
	while (fin >> ob) {
		elems.push_back(ob);
	}
	fin.close();
}

template<typename T>
void Repository<T>::add(T elem)
{
	/*
	Adds a new element at the back of the list
	input: element of type T
	output: -
	*/
	elems.push_back(elem);
	writeToFile();
}

template<typename T>
Repository<T>::Repository(string p) : path(p) {
	readFromFile();
}

template<typename T>
Repository<T>::~Repository()
{
}

template<typename T>
inline void Repository<T>::addScore(T elem, int score)
{
	/*
	Adds score to a given participant
	input: element of type T
			int that represents score to be added
	output: -
	*/
	for (auto& e : elems)
		if (e.getName() == elem.getName())
			e.setScore(e.getScore() + score);
}

template<typename T>
inline void Repository<T>::writeToFile()
{
	if (path == "")
		return;
	ofstream fout(path);
	for (auto e : elems)
		fout << e << '\n';
	fout.close();
}

#include <iostream>
#include <vector>

using namespace std;

int main() {


  int numCandidates, cutoff;

  cin >> numCandidates;
  cin >> cutoff;

  //array of size numCandidates
  vector <int> scores(numCandidates);

  for(int i = 0;i<numCandidates;i++) {
    int score;
    cin >> score;
    scores[i] = score;
  }

  int threshold = scores[cutoff-1];

  int counter = 0;

  //score in scores array
  for(int score:scores) {
    if(score >= threshold && score > 0) counter++;
  }

  cout << counter <<endl;

  return 0;
}
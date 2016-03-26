//============================================================================
// Name : Main.cpp
// Author : David Nogueira
//============================================================================

#include "Perceptron.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "microunit.h"

UNIT(LearnAND) {
  std::cout << "Train AND function with perceptron." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0, 0 },false},
    {{ 0, 1 },false},
    {{ 1, 0 },false},
    {{ 1, 1 },true}
  };

  Perceptron my_perceptron(0.1);
  my_perceptron.Train(training_set, false, true, 100);

  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 0 }) == false);
  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 1 }) == false);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 0 }) == false);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 1 }) == true);
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

UNIT(LearnNAND) {
  std::cout << "Train NAND function with perceptron." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0, 0 },true},
    {{ 0, 1 },true},
    {{ 1, 0 },true},
    {{ 1, 1 },false}
  };

  Perceptron my_perceptron(0.1);
  my_perceptron.Train(training_set, false, true, 100);

  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 0 }) == true);
  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 1 }) == true);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 0 }) == true);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 1 }) == false);
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

UNIT(LearnOR) {
  std::cout << "Train OR function with perceptron." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{  0, 0 },false},
    {{  0, 1 },true},
    {{  1, 0 },true},
    {{  1, 1 },true}
  };

  Perceptron my_perceptron(0.1);
  my_perceptron.Train(training_set, false, true, 100);

  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 0 }) == false);
  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 1 }) == true);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 0 }) == true);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 1 }) == true);
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

UNIT(LearnNOR) {
  std::cout << "Train NOR function with perceptron." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0, 0 },true },
    {{ 0, 1 },false},
    {{ 1, 0 },false},
    {{ 1, 1 },false }
  };

  Perceptron my_perceptron(0.1);
  my_perceptron.Train(training_set, false, true, 100);

  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 0 }) == true);
  ASSERT_TRUE(my_perceptron.GetOutput({ 0, 1 }) == false);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 0 }) == false);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1, 1 }) == false);
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}

UNIT(LearnNOT) {
  std::cout << "Train NOT function with perceptron." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    {{ 0},true},
    {{ 1},false}
  };

  Perceptron my_perceptron(0.1);
  my_perceptron.Train(training_set, false, true, 100);

  ASSERT_TRUE(my_perceptron.GetOutput({ 0 }) == true);
  ASSERT_TRUE(my_perceptron.GetOutput({ 1 }) == false);
  std::cout << "Trained with success." << std::endl;
  std::cout << std::endl;
}


UNIT(LearnXOR) {
  std::cout << "Train XOR function with perceptron." << std::endl;

  std::vector<TrainingSample> training_set =
  {
    { { 0, 0 },false },
    { { 0, 1 },true },
    { { 1, 0 },true },
    { { 1, 1 },false }
  };

  Perceptron my_perceptron(0.1);
  my_perceptron.Train(training_set, false, true, 100);

  if ((!(my_perceptron.GetOutput({ 0, 0 }) == false)) ||
      (!(my_perceptron.GetOutput({ 0, 1 }) == true)) ||
      (!(my_perceptron.GetOutput({ 1, 0 }) == true)) ||
      (!(my_perceptron.GetOutput({ 1, 1 }) == false))){
    std::cout << "Failed to train. " <<
    " A simple perceptron cannot learn the XOR function." << std::endl;
    FAIL();
  }
}

int main() {
  microunit::UnitTester::Run();
  return 0;
}
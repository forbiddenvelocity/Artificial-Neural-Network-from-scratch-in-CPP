#include<bits/stdc++.h>
using namespace std;

// Neuron structure
struct Neuron {
    double output;
    double gradient;
};

// Layer class
class Layer {
public:
    int numNeurons;
    Neuron* neurons;

    Layer(int numNeurons, int numNeuronsInPrevLayer);
    ~Layer();
};

// NeuralNetwork class
class NeuralNetwork {
public:
    int numLayers;
    Layer* layers;

    NeuralNetwork(int numLayers, int* layerSizes);
    ~NeuralNetwork();

    double* feedForward(double* input);
    void backpropagation(double* input, double* target, double learningRate);
};

Layer::Layer(int numNeurons, int numNeuronsInPrevLayer) {
    this->numNeurons = numNeurons;
    neurons = new Neuron[numNeurons];

    for (int i = 0; i < numNeurons; i++) {
        neurons[i].output = 0.0;
        neurons[i].gradient = 0.0;
    }
}

Layer::~Layer() {
    delete[] neurons;
}

NeuralNetwork::NeuralNetwork(int numLayers, int* layerSizes) {
    this->numLayers = numLayers;
    layers = new Layer[numLayers];

    for (int i = 0; i < numLayers; i++) {
        int numNeurons = layerSizes[i];
        int numNeuronsInPrevLayer = (i > 0) ? layerSizes[i - 1] : 0;
        layers[i] = Layer(numNeurons, numNeuronsInPrevLayer);
    }
}

NeuralNetwork::~NeuralNetwork() {
    delete[] layers;
}

int main(){
    
    return 0;
}
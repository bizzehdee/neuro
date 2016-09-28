# Neuro - A Simple C++ Neural Net library
(Originally based On [Neural Networks on C#](http://www.codeproject.com/Articles/16447/Neural-Networks-on-C))

## Main Classes

* __Neuron__ - An abstract base class for all neurons. Encapsulates entities like a neuron's weight, output value, and input value. Other neuron classes inherit from the base class.

* __Layer__ - A collection of neurons. This is a base abstract class, which encapsulates common functionality for all neuron's layers.

* __Network__ - A collection of layers. This is an abstract base class for a layered neural network.

* __IActivationFunction__ - Pure virtual interface for activation functions. Activation functions are used in activation neurons - the type of neuron, where the weighted sum of its inputs is calculated and then the value is passed as input to the activation function, and the output value becomes the output value of the neuron.

* __IUnsupervisedLearning__ - Pure virtual interface for an unsupervised learning algorithms - the type of learning algorithms where a system is provided with sample inputs only during the learning phase, but not with the desired outputs. 

* __ISupervisedLearning__ - Pure virtual interface for a supervised learning algorithms - this type of learning algorithms where a system is provided with sample inputs, with desired output values during the learning phase.

## Architecture

* __Activation Network__ - The neural network where each neuron computes its output as the activation function's output, and the argument is a weighted sum of its inputs combined with the threshold value. The network may consist of a single layer, or of multiple layers. Trained with supervised learning algorithms, the network allows to solve such tasks as approximation, prediction, classification, and recognition.

* __Distance Network__ - The neural network where each neuron computes its output as a distance between its weight values and input values. The network consists of a single layer, and may be used as a base for such networks like Kohonen Self Organizing Map, Elastic Network, and Hamming Network.

## Learning

Different learning algorithms are used to train different neural networks, and are used to solve different problems:

* [Perceptron Learning](https://en.wikipedia.org/wiki/Perceptron) - the algorithm may be considered as the first neural network learning algorithm, and its history starts from 1957. The algorithm may be used with a one-layer activation network, where each neuron has a threshold activation function. The range of its applications are rather small and limited the with classification of linearly separable data.

* [Delta Rule Learning](https://en.wikipedia.org/wiki/Delta_rule) - the algorithm is a next step after the perceptron learning algorithm. It utilizes the activation function's derivative, and may be applicable to single-layer activation networks only, where each neuron has a continuous activation function instead of a threshold activation function. The most popular continuous activation function is the unipolar and bipolar sigmoid function. Because the algorithm may be applied to one-layer networks only, it is limited to some classification and recognition tasks mostly.

* [Back Propagation Learning](https://en.wikipedia.org/wiki/Backpropagation) - this is one of the most popular and known algorithms for multi-layer neural network learning. Initially, it was described in 1974, and from that time, it was extensively studied and applied to a broad range of different tasks. Because the algorithm is able to train multi-layer neural networks, the range of its applications is very great, and includes such tasks as approximation, prediction, object recognition, etc.

* [SOM Learning](https://en.wikipedia.org/wiki/Self-organizing_map) - this algorithm was developed by Kohonen, and may be considered as one of the most famous unsupervised learning algorithms for clusterization problems. It treats neural network as a 2D map of nodes, where each node may represent a separate class. The algorithm organizes a network in such a way, that it becomes possible to find the correlation and similarities between data samples.

* Elastic Network Learning - the algorithm is similar to the idea of the SOM learning algorithm, but it treats network neurons not as a 2D map of nodes, but as a ring. During the learning procedure, the ring gets some shape, which represents a solution. One of the most common demonstrations of this learning algorithm is the Traveling Salesman Problem (TSP).

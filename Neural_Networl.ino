// Include the Arduino library
#include <Arduino.h>

// Define the sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void setup() {
    // Initialize the serial communication for debugging
    Serial.begin(9600);

    // Define fixed weights for a simple neural network
    double weightsInputHidden[2][2] = {{0.5, 0.2}, {0.3, 0.8}};
    double weightsHiddenOutput[2] = {0.4, 0.6};

    // Generate random input (in this case, fixed values)
    double input[2] = {0.7, 0.9};

    // Calculate values in the hidden layer
    double hiddenOutput[2];
    for (int i = 0; i < 2; ++i) {
        hiddenOutput[i] = 0.0;
        for (int j = 0; j < 2; ++j) {
            hiddenOutput[i] += input[j] * weightsInputHidden[j][i];
        }
        hiddenOutput[i] = sigmoid(hiddenOutput[i]);
    }

    // Calculate final output
    double finalOutput = 0.0;
    for (int i = 0; i < 2; ++i) {
        finalOutput += hiddenOutput[i] * weightsHiddenOutput[i];
    }
    finalOutput = sigmoid(finalOutput);

    // Display input and output through serial communication
    Serial.print("Input: ");
    for (int i = 0; i < 2; ++i) {
        Serial.print(input[i]);
        Serial.print(" ");
    }
    Serial.println();

    Serial.print("Output: ");
    Serial.println(finalOutput, 4); // Print with 4 decimal places
}

void loop() {
    // Empty loop
}

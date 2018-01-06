# In linear regression our task is to estimate continious output
# of the unknown parameters.
#
# Challenge is to optimize parameters in such a way that cost
# finction as minimized as possible. This is done by optimizing
# weights, also known as 'learning'.
#
# Optimization can be done using Ordinary Least Squares method, or
# using well common Batch Gradient Descent optimization.

import numpy as np


def ordinary_least_squares(x, y):
    '''
    Find weights for hypothesis of the form:
        w*x + b
    using ordinary leasts squares method where
    w defined as b0, b as b1 by convention.
    
    Params:
        x: training data values
        y: training data lables
    
    Returns:
        hypothesis function
    '''    
    xmean = np.mean(x)
    ymean = np.mean(y)

    m = len(x)
    
    numerator = 0
    denominator = 0

    for i in range(m):
        numerator += (x[i] - xmean) * (y[i] - ymean)
        denominator += (x[i] - xmean)**2
    
    b1 = numerator / denominator
    b0 = ymean - (b1 * xmean)
    
    # b1 and b0 are np arrays -> extract their actual values
    b = b0[0]
    w = b1[0]
    print(b1, b0)
    return lambda x: w*x + b


def batch_gradient_descent(X, y, weights, lrate=0.001, niter=10000, history=True, history_frequency=50):
    '''
    Find weights for hypothesis of the form:
        w_1*x_1 + ... w_n*x_n + b
    
    Usage:
        After gradient descent is done, it returns weigths and history. History
        can be used as a feedback for hyperparameters tuning. To use weights
        the most straightforward thing to do is:
            X.dot(weights)

    Params:
        X: training data
        y: ground truth vector
        weights: initial weights, usually zero vector
        lrate: learning rate
        niter: number of iterations
        history: whether to store history or not
        history_frequency: how often to write into the history
    '''
    cost_function = lambda X, y, weights: np.sum((X.dot(weights) - y)**2) / (2*len(y))

    history = []
    m = len(y)
    
    for i in range(niter):
        h = X.dot(weights)
        loss = h - y
        gradient = X.T.dot(loss) / m
        weights = weights - lrate*gradient
        cost = cost_function(X, y, weights)
        
        if history and i % history_frequency == 0:
            history.append(cost)

    return weights, history

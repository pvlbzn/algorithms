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


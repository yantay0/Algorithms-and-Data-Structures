import numpy as np
import sklearn.model_selection as sksel

x1 = feature1 = [-16, -965, -813, -619, -334, 151, 74, 154, -269, -833, -976, -652, -713, -
            880, 37, -707, -352, 177, 179, 91, -702, -189, 308, -999, -660, 354, -209, 272, -73, -45]
x2 = feature2 = [-3, -8, -7, 0, -9, 1, 0, -7, -9, -1, -6, 0, -9, -
            8, -3, -5, 2, 0, -7, -9, 3, 0, -5, -6, -5, -1, 3, 2, -3, -9]

x1 = np.array(x1)
x2 = np.array(x2)
x = np.column_stack((x1,x2))
data_x = x.reshape((-1, 2))

data_x_train, data_x_test = sksel.train_test_split(
    data_x,  shuffle=False, train_size=0.80)
print(np.float64(data_x_test))
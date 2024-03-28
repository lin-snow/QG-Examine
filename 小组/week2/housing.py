import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 读取数据集
file_path = 'data\\housing.data'
# 加入列名
column_names = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT', 'MEDV']
# 读取数据集到DataFrame
data = pd.read_csv(file_path, header=None, delimiter=r"\s+", names=column_names)
# 开始检查数据是否存在缺失值和异常值
description = data.describe()

# 开始处理数据
def data_manage(data):
    # 获取均值和标准差
    column_mean = np.mean(data, axis=0)
    column_std = np.std(data, axis=0)
    
    # 阈值(设置为三倍标准差)
    threshold = 4 * column_std
    
    # 找出异常数据点的索引
    abnormal_index =  np.where(np.abs(data - column_mean) > threshold)[0]
    
    print(f"\n异常的数据所在行:\n\n",data.loc[abnormal_index])
    
    # 将数据有异常的行给删除
    cleaned_data = data.drop(abnormal_index)
    
    return cleaned_data

cleaned_data = data_manage(data)

cleaned_data.hist(figsize=(15,12), bins=20)
plt.suptitle("Feature Distribution", y=1.02, fontsize=16 )
plt.tight_layout()
plt.show()

# 损失函数
def compute_cost(X, y, theta):
    m = len(y)
    predictions = X.dot(theta)
    cost = (1 / (2 * m)) * np.sum((predictions - y) ** 2)
    return cost

# 梯度下降
def gradient_descent(X, y, theta, alpha, num_iters):
    m = len(y)
    cost_history = np.zeros(num_iters)

    for i in range(num_iters):
        predictions = X.dot(theta)
        errors = predictions - y
        theta = theta - (alpha / m) * (errors.T.dot(X)).T
        cost_history[i] = compute_cost(X, y, theta)

    return theta, cost_history

# 预测
def predict(X, theta):
    predictions = X.dot(theta)
    return predictions

X = data.iloc[:, :-1]  # 取出前13列作为特征
y = data.iloc[:, -1]   # 取出最后一列作为目标值

X = np.hstack((np.ones((X.shape[0], 1)), X))  # 添加偏置项

theta = np.zeros(X.shape[1])  # 初始化一个全0的theta向量

alpha = 0.01     # 学习率
num_iters = 1000 # 迭代次数
theta, cost_history = gradient_descent(X, y, theta, alpha, num_iters)
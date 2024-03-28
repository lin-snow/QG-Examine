import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 读取数据集
file_path = 'data\\housing.data'
# 加入列名
column_names = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT', 'MEDV']
# 读取数据集到DataFrame
data = pd.read_csv(file_path, header=None, delimiter=r"\s+", names=column_names)

# 开始处理数据

# 开始检查数据是否存在缺失值和异常值
description = data.describe()
# 获取均值和标准差
column_mean = np.mean(data, axis=0)
column_std = np.std(data, axis=0)

# 获取每一列的最值
max_values = data.max()
min_value = data.min()

# 输出每一列的均值和标准差
print(f"每列的均值\n{column_mean}")
print(f"每列的标准差\n{column_std}")

# 输出每一列的最值
print(f"每一列的最大值\n{max_values}")
print(f"每一列的最小值\n{min_value}")

# 阈值(设置为三倍标准差)
threshold = 3 * column_std

# 找出异常数据点的索引
abnormal_index =  np.where(np.abs(data - column_mean) > threshold)[0]

print(f"异常的数据所在行\n",data.loc[abnormal_index])
import random

def generate_data(num_rows, num_cols):
    with open("py_small_data.txt", "w") as file:
        for _ in range(num_rows):
            row_data = []
            for _ in range(num_cols):
                if random.random() < 0.5:  # 控制一半的数字是浮点数，另一半是整数
                    row_data.append(str(random.randint(1, 100)))  # 生成整数
                else:
                    num_decimals = random.randint(1, 3)  # 随机生成保留小数位数
                    num_float = round(random.uniform(1, 100), num_decimals)  # 生成浮点数并保留指定小数位数
                    row_data.append("{:.{}f}".format(num_float, num_decimals))  # 格式化保留指定小数位数的浮点数
            file.write(" ".join(row_data) + "\n")  # 将每行数据写入文件并以空格分隔

generate_data(100, 100)

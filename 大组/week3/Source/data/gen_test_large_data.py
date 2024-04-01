import random

def generate_data(num_entries):
    with open("py_large_data.txt", "w") as file:
        for _ in range(num_entries):
            # 生成随机数，可能是整数也可能是浮点数
            if random.choice([True, False]):
                data = random.randint(0, 99999)  # 生成一至五位整数
            else:
                data = round(random.uniform(0, 99999), random.randint(1, 3))  # 生成浮点数，小数点后一至三位

            file.write(str(data) + " ")

if __name__ == "__main__":
    num_entries = int(input("请输入要生成的数据量: "))
    generate_data(num_entries)
    print("数据已生成到 py_large_data.txt 文件中。")

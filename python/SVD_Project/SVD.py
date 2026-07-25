import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

# 读取图片并转为灰度图
img = Image.open(r"D:\CS-Learning\python\SVD_Project\test.jpg").convert("L")
A = np.array(img, dtype=float)

# SVD 分解
U, S, Vt = np.linalg.svd(A, full_matrices=False)

# 选择不同的 k 值进行重构
k_values = [5,10,20,50,100,1000]

for k in k_values:
    Ak = U[:, :k] @ np.diag(S[:k]) @ Vt[:k, :]

    plt.figure()
    plt.imshow(Ak, cmap="gray")
    plt.title(f"k = {k}")
    plt.axis("off")
    plt.show()

    m, n = A.shape
    compression_ratio = k * (m + n + 1) / (m * n)
    print(f"k = {k}, 压缩后数据量比例 = {compression_ratio:.4f}")

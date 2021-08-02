#main.py https://www.codewars.com/kata/5667e8f4e3f572a8f2000039/train/python
def accum(sum):
    return "-".join([sum2 + sum2.lower()*i for sum2, i in zip(sum.upper(), range(len(sum)))])

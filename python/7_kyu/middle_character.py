#main.py https://www.codewars.com/kata/56747fd5cb988479af000028/train/python
def get_middle(sum):
    return sum[len(sum)//2]if(len(sum) % 2 == 1)else(sum[(len(sum)-1)//2]+sum[len(sum)//2])

class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

def getJosephusPosition(m, n):
    head = Node(1)
    prev = head
    for i in range(2, n + 1):
        prev.next = Node(i)
        prev = prev.next
    prev.next = head 
    ptr1 = head
    ptr2 = head
    while (ptr1.next != ptr1):
        count = 1
        while (count != m):
            ptr2 = ptr1
            ptr1 = ptr1.next
            count += 1
        ptr2.next = ptr1.next
        ptr1 = ptr2.next
    print("Last person is ", ptr1.data)
  
if __name__ == '__main__':
    n = 5
    m = 1
    getJosephusPosition(m, n)
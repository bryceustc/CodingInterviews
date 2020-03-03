class MaxQueue:

    def __init__(self):
        self.queue=[]
        self.max_queue=[]
        
    def max_value(self) -> int:
        if not self.queue:
            return -1
        return self.max_queue[0]
        

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.max_queue and value > self.max_queue[-1]:
                self.max_queue.pop(-1)
        self.max_queue.append(value)

    def pop_front(self) -> int:
        if not self.queue:
            return -1
        if self.queue[0]==self.max_queue[0]:
            self.max_queue.pop(0)
        return self.queue.pop(0)

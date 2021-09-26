#purpose of this file: demo objects
#Date: 2021-09-24
#---------------------------------
class Apple:
    def __init__(self, arg_name, arg_weight):
        # print("custom constructor called")
        self.name = arg_name
        self.total_weight = arg_weight

    def eat(self, amount):
        self.total_weight = self.total_weight - amount

    def display(self):
        print("total weight:", self.total_weight)
        print("name:", self.name)





def add_one(number, number2):
    print("hiiis")
    return number + number2

def resturanut(money):
    return "food"


def main():

    result = 10 + 20
    result_from_func = add_one(10, 20)



    myApple = Apple("granny smith", 100)
    myApple.eat(10)
    myApple.display()

    # class String:
        # def split():

    # string.split()

    name = "shawn"
    # type: string
    # name of varible: name

if __name__ == "__main__":
    main()


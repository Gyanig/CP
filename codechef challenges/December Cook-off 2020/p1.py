def split(word): 
    return list(word)

def main():
    t=int(input())
    n=0
    while t>0:
        n=int(input())
        a=0
        s=input()
        values=split(s)
        for value in values:
            if(value=='0'):
                a=a+1
                
        p=n-a
        p=p+(120-n)
        percent=(p/120.0)*100.0
        if(percent>=75):
            print("YES\n")
        else:
            print("NO\n")
        t=t-1    


if __name__ == "__main__":
    main()

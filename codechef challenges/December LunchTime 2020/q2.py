
def main():    
    t=int(input())
    while(t>0):
        s=""
        s=input()
        value=split(s)
        value.sort()
        
        all_freq = {} 
        for i in value: 
            if i in all_freq: 
                all_freq[i] += 1
            else: 
                all_freq[i] = 1        
        freq_list=list(all_freq.values())
        freq_list.sort(reverse=True)
        for i in freq_list: 
            while(i>0): 
                
        
def split(word): 
    return list(word) 

if __name__ == '__main__':
    main()
    
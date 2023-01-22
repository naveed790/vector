import numpy as np 
import matplotlib.pyplot as plt 
from numpy import linalg as LA 
import math 
import sys     #for path to external scripts 
  
def bd(point1,point2):
    A=np.array(point1)
    B=np.array(point2)
    dot_product = np.dot(A,B)
    print(dot_product)
    return dot_product


point1= np.array(([3,-5]))
point2= np.array(([2, 7]))
prod = bd(point1,point2)
A = np.array(([3, -5]))
B = np.array(([2, 7]))
 
def line_gen(A,B): 
   len =10 
   dim = A.shape[0] 
   x_AB = np.zeros((dim,len)) 
   lam_1 = np.linspace(0,1,len) 
   for i in range(len): 
     temp1 = A + lam_1[i]*(B-A) 
     x_AB[:,i]= temp1.T 
   return x_AB 

 
 
x_AB = line_gen(A,B) 
plt.plot(x_AB[0,:],x_AB[1,:],label='$AB$') 

plt.xlabel('$x-axis$') 
plt.ylabel('$y-axis$') 
plt.legend(loc='best') 
plt.grid() # minor 
plt.axis('equal') 

plt.text(3,-5,'   A(3,-5)') 
plt.text(2,7,'   B(2,7)') 

#if using termux
plt.savefig('../fig.pdf')
#else
plt.show()
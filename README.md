# 1D Stencil
Deep Dive: SIMD Programming Project - 1D STENCIL

Colab Link for CUDA Implementation: https://colab.research.google.com/drive/1FrAId2P7W_DDiLIQhjGtfldf_TrEKXuv?usp=sharing

I. Comparison of Execution Time

Each kernel version (C, Non SIMD x86-64 assembly, SIMD YMM x86 assembly, and CUDA version) are timed 30 times. 

![image](https://github.com/its-teph/1dStencil-in-Assembly/assets/80933795/b1e57751-18b0-4d26-b324-500ab119e26c)

It can be seen from overall data that the SIMD x86-64 assembly implementation is the fastest version. To discuss the results obtained, in terms of array size of 2^20, Non SIMD Assembly implementation are 64.05% faster than the C, meanwhile SIMD Assembly implementation is 96.36% faster than the Non SIMD assembly, lastly it can be said that the CUDA is 64% faster than the C and 1.05% faster than the Non SIMD. 


II. Outputs

To check the correctness of the output of each kernel, the C version is used as the basis. To better check the similiraties of each version, I used the same data for all versions instead of randomly generated for this screenshot. However, the code also have the implementation of random number for X vector. 

  a. C Program 

  ![image](https://github.com/its-teph/1dStencil-in-Assembly/assets/80933795/f719d4ee-d2ec-4fdf-8184-95abb1f5c4e1)

  b. Non SIMD x86-64 Assembly

  ![image](https://github.com/its-teph/1dStencil-in-Assembly/assets/80933795/b58ba080-46fc-4efd-9ba6-89de6536cb9b)

  c. SIMD x86-64 Assembly 
  
  ![image](https://github.com/its-teph/1dStencil-in-Assembly/assets/80933795/1bc959f5-f132-49d0-9064-138915476f96)

  d. CUDA

  ![image](https://github.com/its-teph/1dStencil-in-Assembly/assets/80933795/d416dacc-8cc0-48bc-b1a3-4f7c5024ad6a)


  
  



  










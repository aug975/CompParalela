# Lab 07 - Parte I
## Grupo: Augusto Rassi Scrideli 42023092

### Entregue a solução para o problema dos trapézios, juntamente com uma evidência de que você conseguiu executar pelo menos uma vez. 
### Qualquer coisa serve como evidência: até um print é suficiente.

### Adicione a função f(x) e inclua o cabeçalho math.h para funcionar.

### Para compilar execute o seguinte comando:

>gcc {nome arq} -o {nome exec} -fopenmp -lm

## Execução na AWS

O arquivo foi criado com 
>vim main.c 

e editado com o código fornecido.

![image](https://user-images.githubusercontent.com/101229028/198755796-92d0ea7c-826b-4ec6-87de-8dfabb54f7f7.png)

Depois foi compilado com gcc e openmp.

![image](https://user-images.githubusercontent.com/101229028/198755877-6ea4fc96-9a9d-4ff5-a408-45576b6dea2d.png)

Depois, foi executado com 4 threads.

![image](https://user-images.githubusercontent.com/101229028/198755926-1faae333-ed0e-4b06-9e02-96726d6369a6.png)

Obs.: Uma pequena mudança foi feita no output, para melhor precisão.
> global_output + 1

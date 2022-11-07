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

# Lab 07 - Parte II
## Grupo: Augusto Rassi Scrideli 42023092

### Considere os seguintes problemas que foram implementados até agora:

### -Soma dos trapézios;
### -Multiplicação de matrizes.
### Construa duas versões paralelas com OpenMP explorando pelo menos duas técnicas para o controle de acesso à região crítica. Compare o valor total do somatório para cada uma das versões e explique qual abordagem obteve um valor mais preciso e porquê.

### Faça uma comparação de tempo de execução com 1, 2, 4  e 8 processadores para a versão paralela. Construa uma tabela contendo o tempo médio de 3 execuções para cada versão e sua respectiva quantidade de threads.

### Faça um gráfico que mostre a escalabilidade do Speedup para cada quantidade de threads utilizada.

>OBS: As modificações de código no controle de versão estão comentadas.

## Parte 1 - Comparar valores de somatório

### Primeiramente, vamos comparar dos dois métodos utilizados no código do trapézio.

### O primeiro código utiliza `pragma omp atomic` para controlar o acesso à região crítica.

Criamos o arquivo com `vim trap_atomic.c` e salvamos com o código.

![image](https://user-images.githubusercontent.com/101229028/200225901-4c3140cf-d5f8-4206-9ddc-ea71aa1bb43c.png)
![image](https://user-images.githubusercontent.com/101229028/200225980-3fc8b8a6-5bd2-47af-b40f-510bff574aa3.png)

Compilamos o arquivo com `gcc trap_atomic.c -fopenmp -lm`

![image](https://user-images.githubusercontent.com/101229028/200226282-8b2636dd-db5e-4f64-868c-e94bab9ad34f.png)

Executamos o código com 2 threads.

![image](https://user-images.githubusercontent.com/101229028/200226572-6321db1f-31ef-4b8e-b2af-08388474aa98.png)

>Resultado dessa execução: 2.71828197164920e+00

### O segundo código utiliza `lock_init lock_set lock_unset` para controlar o acesso à região crítica.

Criamos e salvamos da mesma forma que o anterior. Compilamos com gcc.

![image](https://user-images.githubusercontent.com/101229028/200227000-bc27b74a-204d-4287-b762-522267997d56.png)

Executamos o código com 2 threads.

![image](https://user-images.githubusercontent.com/101229028/200227083-ce5c1a0d-f7e4-450c-a1c7-59b43bfbab0a.png)

>Resultado dessa execução: 2.71828197164920e+00

> !!! Há limitação de testes devido a limitações de permissões na AWS. Não é possível testes com mais de duas threads/processadores.

### Conclusão: os dois métodos apresentam a mesma precisão. Isto se deve ao fato que o acesso à variável global se dá com uma soma. Somamos os valores em cada iteração e thread, e retornamos a soma total. Devido a isso, a ordem de acesso à região crítica não causa mudança no resultado. 

### Vamos agora comparar dos dois métodos utilizados no código de multiplicação de matrizes.

### O primeiro código utiliza `for schedule (static)` para controlar o acesso à região crítica.

Criamos e salvamos, compilamos com gcc. Executamos com 2 threads.

![image](https://user-images.githubusercontent.com/101229028/200227920-d2e2c381-4862-405c-87f9-aff1fc7a1d1a.png)

>Resultado dessa execução: 5072 4426 2400 4440, um resultado correto com maior precisão possível para inteiros.
> ![image](https://user-images.githubusercontent.com/101229028/200228246-0674b931-fd0e-4ff1-b5cb-9a2a818a2212.png)

### O segundo código utiliza `parallel for` para controlar o acesso à região crítica.

Obs.: O uso de parallel for para controle de acesso foi explicado [aqui](https://github.com/aug975/CompParalela/commit/edd1b2d028bfec571d2cfcbf28936e7de1ddcd1d#r89080303)
e [aqui.](https://github.com/aug975/CompParalela/commit/ea66ca41842c621f901d07e431be5e88a371b64d)

Criamos e salvamos, compilamos com gcc. Executamos com 2 threads.

![image](https://user-images.githubusercontent.com/101229028/200228888-21ce0c6c-7944-4892-9721-05dc153db3a5.png)

>Resultado dessa execução: 7152 8851 3450 4331, um resultado correto com maior precisão possível para inteiros.
> ![image](https://user-images.githubusercontent.com/101229028/200229034-bdb159d5-45d9-4be5-9b01-e4457c1dd3b1.png)

### Conclusão: de forma semelhante, os dois métodos apresentam a mesma precisão. Isto se deve ao fato que o acesso à variável global se dá com uma soma. Somamos os valores em cada iteração e thread, e retornamos a soma total. Devido a isso, a ordem de acesso à região crítica não causa mudança no resultado.

## Parte 2 - Comparar tempos por processador

### Devido a problemas de permissões dentro do sistema da AWS, é possível apenas a criação de máquinas com 1 e 2 processadores.

![image](https://user-images.githubusercontent.com/101229028/200229356-6fec1c5f-2b6c-4b8d-81c7-ed6cc96c44cd.png)

### Portanto os testes serão apenas com 1 e 2 processadores.

### 1 - Código de trapézio

> Utilizamos `time` para obter tempo. Como o este código possui input de usuário, o valor relevante é _user_

Comparação para `atomic`:

![image](https://user-images.githubusercontent.com/101229028/200229711-34322f7e-3ec2-4d9f-b8de-7045f80f148a.png)

Comparação para `lock`:

![image](https://user-images.githubusercontent.com/101229028/200229930-84af367a-4ed2-4259-933f-8739a01f0070.png)

### 2 - Código de matrizes

Comparação para `schedule`:

![image](https://user-images.githubusercontent.com/101229028/200230033-d6158e21-2750-4ded-a832-c7f4f2acb550.png)

Comparação para `for`:

![image](https://user-images.githubusercontent.com/101229028/200230128-11a22045-02ac-4213-ae14-2bc5b2ff51b7.png)

### Tabela

| trap_atomic | trap_lock | mat_schedule | mat_for | Número de processadores |
| ----------- | --------- | ------------ | ------- | ----------------------- |
|   0.002s    |  0.002s   |   0.002s     |  0.002s | 2                       |
| 0.002s      | 0.002s    | 0.001s       | 0.001s  | 1                       |

## Parte 3 - Speedup

![image](https://user-images.githubusercontent.com/101229028/200234815-b3f39204-da10-43d3-9c82-80b719c22d2a.png)

Obs.: Devido ao limite de dois processadores, estes resultados são imprecisos. O tempo baixo resulta em diferenças pequenas que são essencialmente aleatórias. Não há forma de testar com valores maiores na AWS.

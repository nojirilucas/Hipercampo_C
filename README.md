# Hipercampo_C
São dadas duas âncoras, dois pontos A = (XA, 0) e B = (XB , 0), formando um segmento
horizontal, tal que 0 < XA < XB , e um conjunto P de N pontos da forma (X, Y ), tal que X > 0
e Y > 0. A figura mais à esquerda exemplifica uma possível entrada.
Neste trabalho vamos implementar um sistema que possui âncoras e pontos para criarmos um Hipercampo e localizar os pontos.

![hipercampo](https://user-images.githubusercontent.com/103136574/234601962-a174383c-8627-4680-a8e6-d85e06fc03e2.png)
    
Para "ligar"um ponto v ∈ P precisamos desenhar os dois segmentos de reta (v, A) e (v, B).
Queremos ligar vários pontos, mas de modo que os segmentos se interceptem apenas nas âncoras.
Por exemplo, a figura do meio mostra dois pontos, 1 e 4, que não podem estar ligados ao mesmo
tempo, pois haveria interseção dos segmentos fora das âncoras. A figura mais à direita mostra que
é possível ligar pelo menos 3 pontos, 8, 5 e 3, com interseção apenas nas âncoras. Seu programa
deve computar o número máximo de pontos que é possível ligar com interseção de segmentos
apenas nas âncoras

Testes com 50000v e 100000v

![teste_50000v](https://user-images.githubusercontent.com/103136574/234602418-d57350d1-5a88-4316-b8ed-7aa0eb46768a.png)

![teste_100000v](https://user-images.githubusercontent.com/103136574/234602434-d856bec6-e977-45fb-8314-a4572af74939.png)

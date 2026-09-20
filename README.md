# Monitor de Temperatura em C

Sistema de linha de comando para registrar, acompanhar e analisar leituras de temperatura, escrito em C puro (sem dependências externas).

## Sobre o projeto

O programa mantém um histórico de leituras em um buffer circular, verifica se cada valor está dentro de uma faixa segura configurável e gera um relatório com mínima, máxima e média. A leitura do sensor é simulada por padrão, mas isolada em uma única função — basta substituí-la para integrar um sensor real.

## Funcionalidades

- Registro manual de leituras
- Leitura simulada de sensor (valores entre 15 °C e 35 °C)
- Simulação de N leituras em lote
- Histórico circular de até 100 registros com data e hora
- Alerta automático quando a temperatura sai da faixa segura
- Relatório com mínima, máxima e média

## Como compilar

```bash
gcc -Wall -o monitor monitor_temperatura.c
```

## Como executar

```bash
./monitor
```

## Exemplo de uso

```
=== Monitor de Temperatura ===

1 - Registrar leitura manual
2 - Ler sensor (simulado)
3 - Simular N leituras
4 - Ver relatorio
5 - Listar historico
0 - Sair
Opcao: 2

[20/09/2026 14:32:10] Temperatura: 31.45 C  -> ALERTA: acima do limite (30.0 C)

Opcao: 4

--- Relatorio (3 leituras) ---
Minima : 19.80 C
Maxima : 31.45 C
Media  : 25.12 C
Faixa segura: 18.0 C a 30.0 C
-------------------------------
```

## Configuração

Os limites da faixa segura e o tamanho do histórico ficam no topo do arquivo-fonte:

```c
#define MAX_LEITURAS   100
#define LIMITE_MIN     18.0f   /* graus Celsius */
#define LIMITE_MAX     30.0f
```

## Integrando um sensor real

A leitura está isolada na função `ler_sensor()`. Para usar um sensor físico (LM35, DHT11, termopar via ADC) ou ler de um arquivo/porta serial, substitua o corpo da função e mantenha o retorno em graus Celsius:

```c
float ler_sensor(void)
{
    /* sua leitura aqui */
    return temperatura_em_celsius;
}
```

## Estrutura do código

| Elemento | Função |
|---|---|
| `Leitura` | Struct com o valor e o instante da medição |
| `Historico` | Buffer circular de leituras |
| `historico_inserir()` | Adiciona uma leitura, sobrescrevendo a mais antiga quando cheio |
| `historico_estatisticas()` | Calcula mínima, máxima e média |
| `verificar()` | Classifica a leitura como normal, baixa ou alta |
| `ler_sensor()` | Ponto de integração com o sensor |

## Próximos passos

- Exportação do histórico para CSV
- Leitura contínua em intervalos fixos
- Porte para Arduino / ESP32

## Licença

MIT

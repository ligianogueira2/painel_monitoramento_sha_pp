<h1 align="center"> Painel de Monitoramento do SHA </h1>
<p align="center"> 
<img src="images/painel_capa.png" alt="Imagem do Hidrômetro"/>
</p>
<h4 align="center"> Criação de um Painel de Monitoramento de Simulador de Hidrômetro Analógico para a disciplina de Padrões de Projetos. </h4>
<h4 align="center"> Engenharia de Computação/<a href="https://www.ifpb.edu.br/">IFPB</a> (Setembro 2025) </h4>

<br>
</br>
<p align="center"> 
<a href="https://image.jimcdn.com/app/cms/image/transf/dimension=970x10000:format=gif/path/sa16dc2497d80e05e/image/icd162bb94ffa0064/version/1551588419/image.gif" target="_blank"><img src="https://image.jimcdn.com/app/cms/image/transf/dimension=970x10000:format=gif/path/sa16dc2497d80e05e/image/icd162bb94ffa0064/version/1551588419/image.gif" alt="image host" height="142px"/></a>
</p>

<div align="center">
<h4> | <a href="#contexto">Contexto e objetivo</a> | <a href="#estrutura">Estrutura de pastas</a> | <a href="#requisitos">Requisitos</a> | <a href="#uml">Diagrama de classes (UML)</a> | <a href="#padroes">Padrões de Projeto</a> | <a href="#ferramentas">Ferramentas</a> | <a href="#implementacao">Implementação</a> | <a href="#execucao">Execução</a> | <a href="#progresso">Progresso</a> | <a href="#creditos">Créditos</a> |</h4>
</div>

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="contexto"> :brain: CONTEXTO E OBJETIVO</h2>

<p>O Painel de Monitoramento do SHA (PMSHA) é um sistema desenvolvido em C++ cujo objetivo é monitorar hidrômetros (SHA) a partir de imagens geradas por projetos externos. Cada hidrômetro funciona de forma independente e gera imagens periódicas representando sua leitura de consumo. O desenvolvimento do projeto dar-se-á uma proposta de atividade para a cadeira de Padrões de Projetos, ministrada pelo professor doutor Katyusco Santos.</p>

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="estrutura"> 📁 ESTRUTURA DE PASTAS DO PROJETO </h2>

```
painel_monitoramento_sha_pp/
painel_monitoramento_sha_pp/
├── include/
│   ├── fachada/
│   │   └── FachadaPMSHA.hpp       
│   ├── dto/
│   │   ├── UsuarioDto.hpp         
│   │   └── LeituraDto.hpp
│   ├── infra/
│   │   ├── imagem/
│   │   │   ├── HidrometroParser.hpp
│   │   │   ├── ImagemReader.hpp    
│   │   │   └── OCRService.hpp      
│   │   ├── notificacao/
│   │   │   ├── SNA_Manager.hpp     
│   │   │   ├── NotificacaoTemplate.hpp
│   │   │   └── EmailAdapter.hpp   
│   │   └── logger/
│   │       └── Logger.hpp          
│   └── sgu/
│       ├── SGU_Controller.hpp
│       ├── UsuarioBuilder.hpp      
│       └── UsuarioDAO.hpp          
├── src/
│   ├── fachada/
│   ├── infra/
│   │   ├── imagem/              
│   │   ├── notificacao/
│   │   └── logger/
│   └── sgu/
├── imagens/                        
├── main.cpp                        
└── README.md          
```

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="requisitos"> :clipboard: REQUISITOS FUNCIONAIS E NÃO FUNCIONAIS </h2>

<h4>➔ Requisitos de Funcionalidade</h4>
<ul>
  » Gerenciamento de Usuários e Contas (CRUD):
  <li> RF-FPMH-001: Criar Usuário/Conta; </li>
  <li> RF-FPMH-002: Consultar Usuário/Conta; </li>
  <li> RF-FPMH-003: Atualizar Usuário/Conta; </li>
  <li> RF-FPMH-008: Definir Limite de Alerta. </li>
</ul>

<ul>
  » Monitoramento de Consumo:
  <li> RF-FPMH-005: Monitorar Consumo por SHA; </li>
  <li> RF-FPMH-006: Monitorar Consumo por Usuário (Agregado); </li>
  <li> RF-FPMH-010: Processar Nova Leitura (Imagem). </li>
</ul>

<ul>
  »  Sistema de Alerta:
  <li> RF-FPMH-009: Consultar Alertas Pendentes; </li>
  <li> RF-FPMH-011: Notificar Sistemas Externos. </li>
</ul>

<h4>➔ Requisitos Não Funcionais</h4>
<ul>
  <li> RNF-001: Performance; </li>
  <li> RNF-002: Segurança; </li>
  <li> RNF-003: Disponibilidade; </li>
  <li> RNF-004: Escalabilidade. </li>
</ul>

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="uml"> &#127959 Diagrama de Classes (UML)</h2>

<p>A arquitetura do projeto foi modelada usando um diagrama de classes da Linguagem de Modelagem Unificada (UML). Esta representação visual ilustra a estrutura do sistema, mostrando como as classes se relacionam e interagem para simular o hidrômetro.</p>

<ul>
  <h4>➔ UML do projeto: </h4> 
  </ul> 

<p align="center"> 
<img src="images/diagrama_uml.png" alt="Imagem da UML v1"/>
</p>

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="padroes"> 🧱 Padrões de Projeto</h2>

|            Padrão           | Localização no Projeto      | Benefício Prático                                         |
| :-------------------------: | --------------------------- | --------------------------------------------------------- |
|                             |  **Padrões Criacionais**    |                                                           |
|          Singleton          | Logger.hpp                  | Ponto único de log para todo o sistema                    |
|        Factory Method       | LeitorHidrometro.hpp        | Instanciação dinâmica do leitor correto conforme a imagem |
|           Builder           | UsuarioBuilder.hpp          | Criação detalhada e segura de perfis de usuário no SGU    |
|                             | **Padrões Estruturais**     |                                                           |
|       Facade (Fachada)      | FachadaPMSHA.hpp            | Interface simplificada para o monitoramento central       |
|     Adapter (Adaptador)     | EmailAdapter.hpp            | Isolar bibliotecas externas (como libcurl) do núcleo      |
|          DAO / DTO          | UsuarioDAO.hpp / Pasta dto/ | Abstração da persistência e transporte seguro de dados    |
|                             | **Padrões Comportamentais** |                                                           |
|           Observer          | SNA_Manager / AlertaService | Reação automática ao consumo elevado detectado            |
|           Strategy          | LeitorHidrometro.hpp        | Suporte a múltiplos modelos de hidrômetros (SHA)          |
|       Template Method       | NotificacaoTemplate.hpp     | Padronização das mensagens de alerta enviadas             |


<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="ferramentas"> &#128295 PRINCIPAIS FERRAMENTAS UTILIZADAS </h2>

<ul>
    <li>Linguagem de Programação: C++  </li>
    <li>Editor de Código: Visual Studio Code (VS Code) </li>
    <li>Controle de Versão: Git </li>
    <li>Hospedagem de Código: GitHub </li>
    <li>Diagramação: PlantUML (para a geração do diagrama de classes) </li>
</ul> 

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="implementacao"> &#128187 IMPLEMENTAÇÃO </h2>

<p> A implementação do Painel de Monitoramento SHA segue uma arquitetura orientada a objetos, com forte foco em desacoplamento, extensibilidade e evolução incremental. </p> <ul> <li> A classe <b>FachadaPMSHA</b> atua como ponto único de entrada do sistema, encapsulando toda a complexidade interna e expondo apenas operações de alto nível; </li>

<li>
    O monitoramento de imagens é realizado por diretórios, onde cada pasta representa um SHA ativo. O sistema detecta automaticamente novas imagens e inicia o fluxo de leitura;
</li>

<li>
    A leitura do hidrômetro é feita através do <b>HidrometroParser</b>, que utiliza o padrão Strategy para selecionar dinamicamente o leitor adequado ao modelo do hidrômetro;
</li>

<li>
    O reconhecimento óptico de caracteres (OCR) é atualmente implementado como <b>stub</b>, permitindo validar o fluxo completo do sistema antes da integração com bibliotecas reais;
</li>

<li>
    O módulo <b>SGU</b> (Sistema de Gestão de Usuários) utiliza DAO e Builder para isolar regras de persistência e construção de objetos;
</li>

<li>
    O sistema de alertas é desacoplado da leitura, permitindo futura integração com envio de e-mails, notificações ou dashboards;
</li>

<li>
    Um sistema de <b>Logger</b> centralizado registra todas as ações relevantes, garantindo rastreabilidade e auditabilidade.
</li>
</ul>

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>


<h2 id="execucao"> ▶️ COMO EXECUTAR O PROJETO </h2>

<p>
Esta seção descreve os passos necessários para compilar e executar o Painel de Monitoramento SHA (PMSHA) localmente,
bem como integrá-lo a diretórios de imagens geradas por projetos externos de hidrômetros.
</p>

<h4>➔ Pré-requisitos</h4>

<ul>
    <li>Sistema Operacional: Windows (PowerShell) ou Linux</li>
    <li>Compilador C++ compatível com o padrão <b>C++17</b> (g++, clang ou MSYS2)</li>
    <li>Git (opcional, para clonar o repositório)</li>
</ul>

<h4>➔ Estrutura esperada</h4>

<p>
O painel não depende da execução direta dos projetos de hidrômetro.
Ele apenas consome as imagens geradas por eles, desde que estejam organizadas em diretórios.
</p>

<h4>➔ Compilação</h4>

<p>No diretório raiz do projeto, execute o comando:</p>

<pre>
g++ -std=c++17 -Iinclude src/**/*.cpp -o pmsha
</pre>

<p>
Em ambientes Windows (PowerShell), utilize:
</p>

<pre>
g++ -std=c++17 -Iinclude (Get-ChildItem -Recurse src -Filter *.cpp | ForEach-Object { $_.FullName }) -o pmsha
</pre>

<h4>➔ Execução</h4>

<p>
Após a compilação, execute o painel com:
</p>

<pre>
./pmsha
</pre>

<p>
Durante a execução, o sistema:
</p>

<ul>
    <li>Inicializa a Fachada PMSHA;</li>
    <li>Executa o CRUD de usuários (criação, consulta e definição de limites);</li>
    <li>Monitora diretórios associados a diferentes SHAs;</li>
    <li>Detecta automaticamente novas imagens;</li>
    <li>Realiza a leitura do consumo (via stub);</li>
    <li>Registra todas as ações no log do sistema.</li>
</ul>

<h4>➔ Configuração dos Diretórios de SHAs</h4>

<p>
Os diretórios de imagens dos SHAs são definidos diretamente no código (<code>main.cpp</code>),
simulando a integração com hidrômetros externos.
</p>

<pre>
fachada.monitorarDiretorioSHA(
    1,
    "C:/caminho/para/Medicoes_SHA_1"
);

fachada.monitorarDiretorioSHA(
    2,
    "C:/caminho/para/Medicoes_SHA_2"
);
</pre>

<p>
Cada diretório representa um SHA distinto em funcionamento.
</p>

<h4>➔ Saída esperada</h4>

<p>
Ao executar o sistema, o console exibirá logs semelhantes a:
</p>

<pre>
[INFO] Monitorando diretorio do SHA ID: 1
[INFO] Imagem detectada: leitura_001.png
[INFO] Leitura realizada com sucesso. Valor lido (m3): 123.000000
</pre>

<p>
Esses logs demonstram que o painel detectou imagens reais, interpretou as leituras
e realizou o monitoramento de múltiplos SHAs simultaneamente.
</p>

  <p>⚠️ <b>Uso de OCR Stub (Implementação Temporária)</b></p>

  <p>
    Para viabilizar o desenvolvimento incremental do sistema, este projeto utiliza uma
    implementação <i>stub</i> de OCR (Reconhecimento Óptico de Caracteres).
  </p>

  <p>
    O módulo de leitura por imagem está completamente integrado ao fluxo do Painel de Monitoramento,
    sendo responsabilidade da classe <b>HidrometroParser</b>. Atualmente, a extração do valor de consumo
    é simulada, permitindo validar toda a arquitetura e o processo de monitoramento.
  </p>

  <p>
    🔄 Na próxima versão, o stub será substituído por uma implementação real de OCR
    (ex.: Tesseract, OpenCV), <b>sem necessidade de alterações estruturais</b> no sistema.
  </p>
</blockquote>

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="progresso"> 📊 PROGRESSO DO PROJETO </h2>

<h4>Progresso por Partes </h4>
<ul>

| Módulo                               | Status |
|-------------------------------------|--------|
| Arquitetura e organização           | ██████████ 100% |
| Fachada PMSHA (Facade Pattern)      | ██████████ 100% |
| Monitoramento de SHAs (Diretórios)  | ██████████ 100% |
| Leitura por Imagem (OCR Stub)       | ██████░░░░ 60%  |
| Sistema de Alertas                  | █████░░░░░ 50%  |
| Persistência (PostgreSQL)           | ██░░░░░░░░ 20%  |
| Envio de E-mail (Adapter)           | ░░░░░░░░░░ 10%  |
</ul>

<h4>Progresso Geral </h4>
<ul>

██████████░░░░░░░░░░░░░░░░░░░░ 65%
</ul>

<a href="https://imgbox.com/3tZuCnVg" target="_blank"><img src="https://images2.imgbox.com/42/88/3tZuCnVg_o.png" alt="image host" height="5px" width="900px"/></a>

<h2 id="creditos"> &#11088 CRÉDITOS</h2>

<li>Estudante/desenvolvedora:</li>
<p><a href="http://lattes.cnpq.br/2405746986360435">Anna Lígia Alves Nogueira</a></p>

<li>Professor responsável:</li>
<p><a href="http://lattes.cnpq.br/1246085373474860">Katyusco de Farias Santos</a></p>

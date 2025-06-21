# Verificador de Primos Multithread

**Nome:** Filipe Mallmann Siota  
**Curso:** TADS

## Como rodar o projeto?

### 📜 Pré-requisitos
Para compilar e rodar o projeto, você precisa ter:
- Um compilador C (`gcc`)
- O utilitário `make`

---

### 💻 Linux

1. **Abra o terminal**.
2. **Certifique-se de que o `gcc` e o `make` estão instalados**:
   
   No Ubuntu/Debian:
   ```
   sudo apt update
   sudo apt install build-essential
   ```

   No Fedora:
   ```
   sudo dnf groupinstall "Development Tools"
   ```

3. **Compile o projeto**:
   ```
   make
   ```

4. **Execute o programa**:
   ```
   ./build/program
   ```

---

### 🖥️ Windows

1. **Instale o Chocolatey** (caso ainda não tenha instalado):
   
   Abra o **PowerShell como Administrador** e execute:
   ```
   Set-ExecutionPolicy Bypass -Scope Process -Force; `
   [System.Net.ServicePointManager]::SecurityProtocol = `
   [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; `
   iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
   ```

2. **Instale o GCC e o Make via Chocolatey**:
   
   Ainda no PowerShell, rode:
   ```
   choco install mingw -y
   choco install make -y
   ```

3. **Feche e abra o PowerShell novamente** (ou execute `refreshenv` para atualizar as variáveis de ambiente).

4. **Compile o projeto**:
   ```
   make
   ```

5. **Execute um dos programas**:
   ```
   ./build/program.exe
   ```

---

### 🔥 Dicas
- No Windows, use **PowerShell** ou **Prompt de Comando** depois de instalar o Chocolatey.
- No Linux, qualquer terminal tradicional funcionará.
- Para limpar os arquivos compilados, você pode rodar:
   ```
   make clean
   ```

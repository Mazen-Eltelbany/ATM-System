# ATM & Client Account Manager System

This project contains two C++ applications:

- **ATM System**
- **Client Account Manager**

## ✨ Features

### 🔐 Client Account Manager

- Add, delete, update client records
- Search clients by account number
- Secure PIN management
- Data stored in `cli.txt` file
- Input validation and formatting

### 🏧 ATM System

- 🔐 PIN-based login for secure user authentication
- 💸 Withdraw and deposit operations with balance validation
- ⚡ Quick withdraw using predefined cash amounts for fast transactions
- 🧾 Check balance anytime during a session
- 🔁 Change password functionality for enhanced account security
- 📂 Client data synced with cli.txt (shared with Client Account Manager)
- 💻 User-friendly console interface with clear navigation and prompts

### 📂 Shared Functionality

- Both apps use the **same client file (`cli.txt`)**
- Easy integration between client management and ATM usage
- Modular structure for future expansion

Both applications read/write from the **same shared file (`cli.txt`)**.

> 💡 If you want to install **Client Account Manager only**, visit:  
> [📦 Client Account Manager Repository](https://github.com/Mazen-Eltelbany/Client-Account-Manager)

## 🔧 How to Run

### Option 1:Using Git

**1- Clone the repository:**

```bash
git clone https://github.com/Mazen-Eltelbany/ATM-System.git
```

**2- Navigate to the project**

```bash
cd ATM-System
cd ATM-System-project
```

**3- Compile:**  
 "If you don't have a g++ compiler download from this video"  
<a href="https://youtu.be/GxFiUEO_3zM">The Installation guide</a>

```bash
    g++ ATM-System-project.cpp -o ATM
```

-"If you want to Open Client-Account-Manager"

```
 g++ Client-Account-Manager.cpp -o CAM
./CAM
```

**3-Run:**

```bash
 ./ATM
```

### Option 2: Download As ZIP:

**1- Download the ZIP:**

- Go to the repo: ATM-System on GitHub
- Click the green "Code" button → Download ZIP
- Extract it anywhere on your computer

  **2- Open the Folder:**

```bash
cd ATM-System-main
cd ATM-System-project
```

**3- Compile And Run:**

```bash
g++ ATM-System-project.cpp -o ATM
./ATM
```

## Author

- 👤 Mazen Eltelbany

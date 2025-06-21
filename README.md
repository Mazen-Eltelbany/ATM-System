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

- PIN-based login
- Withdraw and deposit operations
- Quick withdraw (predefined amounts)
- Check balance
- Syncs client data with `cli.txt`
- Secure and user-friendly console UI

### 📂 Shared Functionality

- Both apps use the **same client file (`cli.txt`)**
- Easy integration between client management and ATM usage
- Modular structure for future expansion

Both applications read/write from the **same shared file (`cli.txt`)**.

> 💡 If you want to install **Client Account Manager only**, visit:  
> [📦 Client Account Manager Repository](https://github.com/Mazen-Eltelbany/Client-Account-Manager)

## 🔧 How to Run

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

-"If you want to add more clients make this"

```
1- g++ Client-Account-Manager.cpp -o CAM
2- ./CAM
```

**3-Run:**

```bash
 ./ATM
```

## Author

- 👤 Mazen Eltelbany

# 🛠️ FixItNow Service - Documentație Tehnică

Acest document descrie structura fișierelor de date utilizate pentru inițializarea, testarea și raportarea în cadrul aplicației **FixItNow**.

## 📂 1. Baze de Date (Input)

Aceste fișiere sunt utilizate pentru a popula sistemul cu date inițiale.

### 📄 `tests/employee_init.csv`
**Rol:** Baza de date a angajaților.
**Format:**
```text
Rol, Nume, Prenume, CNP, DataAngajarii, Oras, [Competenta1, Brand1, Competenta2, Brand2...]
```
*   **Technician:** Include lista de competențe la finalul liniei.
*   **Receptionist / Supervisor:** Nu au competențe tehnice listate.
*   **Utilizare:** Se încarcă din **Meniul 1 (Employees)** -> Optiunea "Load from file".

### 📄 `tests/supported_appliances.csv`
**Rol:** Catalogul oficial al modelelor suportate.
**Format:**
```text
Tip, Brand, Model, An, Pret, AtributExtra
```
*   **Important:** Orice cerere pentru un aparat care nu se regăsește exact (Tip + Brand + Model) în acest fișier va fi **REFUZATĂ** automat.
*   **AtributExtra:** Diagonala (TV), Capacitate (Mașină spălat), HasFreezer (1/0 Frigider).

---

## 🧪 2. Scenarii de Test (Simulare)

Fișiere create pentru a valida logica de business (alocare, cozi, refuzuri).

### 📄 `tests/requests.csv` (Test General)
**Rol:** Scenariu complex pentru demonstrarea funcționalității complete.
**Conținut:**
1.  **Cereri Valide:** Modele existente în catalog -> Intră în **Waiting List**.
2.  **Cereri Invalide:** Modele scrise greșit sau inexistente -> Intră în **Refused Statistics**.
3.  **Cereri Multiple:** Pentru a testa încărcarea tehnicienilor (coada de 3 cereri).
**Utilizare:** **Meniul 3 (Requests)** -> "Run Requests".

### 📄 `tests/debug_requests.csv` (Test Rapid)
**Rol:** Scenariu simplificat pentru verificare vizuală (Debugging).
**Conținut:**
*   Conține cereri cu complexitate mică (durată scurtă de reparație).
*   Gândit pentru a urmări ușor mesajele de status din consolă ("Tic-Tac").

---

## 📊 3. Rapoarte Generate (Output)

Aceste fișiere sunt generate automat de aplicație în folderul rădăcină.

| Nume Fișier | Descriere |
| :--- | :--- |
| `report_top_salaries.csv` | Top 3 angajați după salariul pe luna curentă (+ sortare alfabetică). |
| `report_longest_repair.csv` | Datele tehnicianului care a finalizat cea mai lungă reparație. |
| `report_waiting_list.csv` | Lista cererilor rămase nerezolvate, grupate și sortate alfabetic. |

---

## 🚀 Cum se rulează un test complet?

1.  Porniți aplicația.
2.  Din **Meniul Angajați**, încărcați `employees_init.csv`. verificați angajații necesari.
3.  Din **Meniul Electrocasnice**, încărcați `supported_appliances.csv` (dacă nu sunt deja în cod).
4.  Mergeți la **Meniul Cereri (Requests)** -> **Run Requests**.
5.  Introduceți numele fișierului `tests/requests.csv` și o durată (ex: `60` secunde).
6.  Urmăriți simularea în timp real.
7.  La final, generați rapoartele din **Meniul Rapoarte**.

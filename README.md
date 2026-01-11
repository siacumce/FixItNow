FixItNow Service - Test Data Documentation
Acest folder conține fișierele de intrare (baze de date simulate) și scenariile de test necesare pentru rularea și validarea aplicației FixItNow.
1. Baze de Date Principale (Inițializare)
Aceste fișiere sunt folosite pentru a popula aplicația la pornire sau prin meniul de configurare.
employees.txt
Rol: Lista completă a personalului angajat în service.
Structură: Rol, Nume, Prenume, CNP, DataAngajarii, Oras, [Competente...]
Conține exemple pentru toate cele 3 roluri: Technician, Receptionist, Supervisor.
Tehnicienii au lista de competențe (Tip + Brand) la finalul liniei.
Utilizare: Se încarcă la pornirea aplicației sau din Meniul 1 (Employees) -> Load from file.
appliances_catalog.csv (Supported Appliances)
Rol: Catalogul oficial al modelelor pe care service-ul le poate repara.
Structură: Tip, Brand, Model, AnFabricatie, PretReparatie, AtributExtra
Orice cerere pentru un aparat care NU se află în această listă va fi refuzată automat de sistem.
AtributExtra: Diagonala (TV), Capacitate (Mașini de spălat), 1/0 (Congelator Frigider).
Utilizare: Se folosește pentru validarea cererilor la înregistrare.
2. Scenarii de Test (Simulare)
Aceste fișiere conțin date special concepute pentru a testa funcționalitățile complexe (alocare, cozi, refuzuri).
requests.csv (General Test)
Rol: Un set mixt de cereri valide și invalide pentru a testa fluxul complet.
Conținut:
Cereri care corespund cu competențele tehnicienilor (se vor aloca).
Cereri valide dar fără tehnician disponibil (vor intra în Waiting List).
Cereri invalide/modele necunoscute (vor fi Refuzate și contorizate în statistici).
Utilizare: Meniul 3 (Requests) -> Run Scenario.
debug_requests.csv (Test Rapid)
Rol: Un scenariu simplificat pentru depanare (Debugging).
Conținut:
Durate de reparație scurte (vechime mică).
Competențe clare (ex: o cerere doar pentru Andrei, una doar pentru Maria).
Permite verificarea rapidă a mesajelor de "Alocare", "Execuție" și "Finalizare" din consolă.
3. Fișiere Generate (Output)
Aceste fișiere sunt create automat de aplicație în urma rulării rapoartelor.
report_top_salaries.csv: Top 3 salarii calculate pe luna curentă.
report_longest_repair.csv: Tehnicianul care a gestionat cea mai complexă reparație.
report_waiting_list.csv: Lista cererilor rămase nerezolvate, sortată alfabetic.
Notă pentru Testare
Pentru a rula un test complet, urmați pașii:
1.Încărcați employees.txt.
2.Încărcați appliances_catalog.csv (dacă nu e hardcodat).
3.Mergeți la Requests -> Run Scenario -> introduceți requests.csv și durata 30 secunde.
4.Observați consola pentru mesaje în timp real.
5.Generați rapoartele din Meniul 4.
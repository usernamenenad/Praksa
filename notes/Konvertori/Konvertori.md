# Flyback konvertor

## Osobine

- Buck-boost derived konvertor.
- $V_{out} = \frac{nD}{1-D}V_{in}$  
## Prednosti

- Galvanska izolacija izmedju "primarne" i "sekundarne" strane.
## Mane

- Struja kondenzatora diskontinualna, sto dovodi do vece talasnosti izlaznog napona. Efektivna vrijednost struje kondenzatora velika, a time i disipacija na kondenzatoru.
- Talasnost izlaznog napona uslovljena je konacnom kapacitivnoscu kondenzatora.
# Forward konvertor

## Osobine

- Buck derived konvertor.
- $V_{out} = nDV_{in}$
## Prednosti

- Efikasnije koriscenje magnetskih komponenata. Time je bolji izbor pri vecim snagama.
## Mane

- Slozenija konstrukcija (dodatna slozenost u dva jezgra, demagnetizacionom namotaju i vecem broju dioda).

## Push-pull konvertor

## Osobine

- Buck derived konvertor.
- Izveden iz push-pull pojacavaca.
- Za visoke izlazne napone, sa Grecovim spojem.
- *Peak limiting current mode control* - vrsimo prekidanje prekidaca na osnovu kontrole vrsne vrijednosti ulazne struje. Time dobijamo da jezgro transformatora ne ode u zasicenje + kontrolu konvertora. 
- $V_{out} = 2nDV_{in}$

## Prednosti

## Mane

- Naponi na prekidacima dostizu $2V_{in}$, sto je mana kada radimo sa visokim ulaznim naponima.
- 
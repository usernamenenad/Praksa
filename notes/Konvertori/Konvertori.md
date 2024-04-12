# Buck konvertor 

## Osobine

- Troterminalna prekidacka celija, na izlazu $LC$ filtar.
- Sluzi kao **spustac** napona.
- U ustaljenom stanju, za kalem vazi *volt second balance* (*srednja vrijednost napona na kalemu jednaka je nuli tokom jedne periode prekidanja*), dok za kondenzator vazi *amper second balance* (*srednja vrijednost struje na kondenzatoru jednaka je nuli tokom jedne periode prekidanja*).
- Pretpostavka je da $I_L > 0$ (*continuous conduction mode*), u suprotnom *discontinuous conduction mode*.
$$V_{out} = DV_{in}$$$$I_{in} = DI_{out}$$
- Uslov za kontinualni rezim rada $$I_{out}>\frac{V_{in}}{2f_{s}L}D(1-D)$$
## Prednosti

- Jednostavna implementacija za malo dijelova.
- Biranjem dobrog kondenzatora, nizak *voltage ripple* na izlazu.
- Velika efikasnost - $90$% do $95$%, te mala disipaciona snaga.
## Mane

- Nema galvanske izolacije izmedju "primarne" i "sekundarne" strane.
- Neefikasni za manje snage jer su gubici na prekidanju uporedivi sa izlaznom snagom.
- Generacija elektromagnetnih smetnji usljed brzog prekidanja.
- Struja prekidaca diskontinualna - u prvom periodu prekidacke periode jednaka struji kalema (ulaznoj struji), koja moze biti velika.
- Nula u desnoj poluravni - nestabilan sistem sam po sebi, pa teza kontrola.
## Aplikacije

- Baterijski punjaci za mobilne telefone, laptopove i *power-bank*-ove.
- Solarni punjaci.
- Aplikacije u adaptivnom upravljanju.
- Audio pojacavaci.
# Boost konverter

## Osobine

- Slicna konfiguracija kao buck.
- Sluzi kao **podizac** napona.
$$V_{out} = \frac{1}{1 - D}V_{in}$$
$$I_{in}=\frac{1}{1-D}I_{out}$$
- Uslov za kontinualni rezim rada

$$I_{out}>\frac{V_{in}}{2f_{s}L}D(1-D)$$
## Prednosti

- Jednostavna implementacija za malo dijelova.
- Moguce ostvariti malu ulaznu struju.
- Kontinualna ulazna struja, sto je dobro za ulazne napone kao sto su baterija.
- Velika efikasnost - $90$% do $95$%, te mala disipaciona snaga.
- Prekidac vezan jednim krajem za masu - nije potreban *high side driver*.
## Mane

- Nema galvanske izolacije izmedju "primarne" i "sekundarne" strane.
- Struja kondenzatora jednaka struji kalema u prvom periodu prekidacke periode. To je posebno znacajno jer je disipacija na kondenzatoru $P_C = R_{esr}I^2_{Crms}$, gdje je $R_{esr}$ parazitna serijska otpornost kondenzatora. Za velike efektivne vrijednosti struje, kod elektrolitskih kondenzatora moze se razviti ogromna temperatura koja vodi do kljucanja elektrolita i eksplozije kondenzatora.
- Struja prekidaca diskontinualna - u prvom periodu prekidacke periode jednaka struji kalema (ulaznoj struji), koja moze biti velika.
- Kako sluzi kao podizac napona, veliki stres na komponente.
- Prakticno najveci koeficijent korisnog dejstva dostize se kada je $D=0.5$.
- Nula u desnoj poluravni - moze biti otezana kontrola.
- Struja kondenzatora diskontinualna, sto dovodi do vece talasnosti izlaznog napona.
## Aplikacije

- Pojacavaci snage.
- Regulacija u elektroenergetskim sistemima.
- Aplikacije u adaptivnom upravljanju.
- Baterijski punjaci za mobilne telefone, laptopove i *power-bank*-ove.
- Primjena u *automotive* industriji.

# Buck-boost konvertor

## Osobine

- Daje na izlazu negativan napon, sto je potrebno u mnogim elektronskim aplikacijama.
$$V_{out} = -\frac{D}{1-D}V_{in}$$
$$I_{in} = -\frac{D}{1-D}I_{out}$$
- Uslov za kontinualni rezim rada $$I_{out} < -\frac{V_{in}}{2f_{s}L}D(1-D)$$Primjetiti da struja moze imati samo *negativne vrijednosti.
## Prednosti

- Niska cijena, a ogromna primjena.
- Podizanje i spustanje napona - mnogorodnost.
- Mogucnost odrzavanja konstantnog izlaznog napona suprotno promjeni ulaznog napona.
- Nizak napon na prekidackom uredjaju.
## Mane

- Kompeksan dizajn i implementacija, posebno za sisteme koji zahtjevaju veliku snagu i efikasnost.
- Struja kondenzatora diskontinualna, sto dovodi do vece talasnosti izlaznog napona.
## Aplikacije

- Samoregulisuce napajanje.
- Aplikacije u adaptivnom upravljanju.
- Pojacavaci snage.
# Flyback konvertor

## Osobine

- Buck-boost derived konvertor.
$$V_{out} = \frac{nD}{1-D}V_{in}$$  
## Prednosti

- Galvanska izolacija izmedju "primarne" i "sekundarne" strane.
- Visoka efikasnost na manjim snagama.
- Jeftina za primjene pri manjim i srednjim snagama.
- Izlazni kalem nije potreban. Transformer u *flyback* topologiji se ponasa kao kalem.
- Dodatni stepen slobode je odnos namotaja. 
- Moguce dobiti vise izlaznih napona. 
## Mane

- Struja kondenzatora diskontinualna, sto dovodi do vece talasnosti izlaznog napona. Efektivna vrijednost struje kondenzatora velika, a time i disipacija na kondenzatoru.
- Talasnost izlaznog napona uslovljena je konacnom kapacitivnoscu kondenzatora. Moze biti velika.
- Povecan stres na izlaznoj diodi, pogotovo u diskontinualnom rezimu rada.
- Smanjen koeficijent korisnog dejstva u poredjenju sa drugim topologijama.
- Kompleksnost u dizajnu visokofrekventnih transformera.
- Prekidac izlozen maksimalnom naponu i maloj struji, za razliku od buck konvertora gdje su obje prekidacke kompnente bile na visokom naponu i visokoj struji.
- Dizajn transformatora moze biti prostorno velik.
## Aplikacije

- Punjaci baterija i adapteri.
- Telekomunikaciona oprema.
- Industrijski i medicinski izvori.
# Forward konvertor

## Osobine

- Buck derived konvertor.
$$V_{out} = nDV_{in}$$
$$I_{out}=nDI_{in}$$
- Nastao zbog pojednostavljenja konstrukcije transformatora *flyback* konvertora, odnosno smanjivanje njegove velicine.
## Prednosti

- Galvanska izolacija izmedju "primarne" i "sekundarne" strane.
- Efikasnije koriscenje magnetskih komponenata. Time je bolji izbor pri vecim snagama.
- Prekidac povezan na masu - nema potrebe za *high side driver*-om.
- Pri vecim snagama bolji od *flyback* konvertora.
- Izlazna struja relativno konstantna.
- Velika efikasnost, fleksibinost i sigurnost.
## Mane

- Slozenija konstrukcija (dodatna slozenost u dva jezgra, demagnetizacionom namotaju i vecem broju dioda). Time je konvertor skuplji.
- Potrebno *snubbovanje* zbog rasipnih induktivnosti transformatora.
- Kompleksnije upravljanje.
## Aplikacije

- Baterijski punjaci.
- Solarni elektroenergetski sistemi.
- Hibridno punjenje.
# Push-pull konvertor

## Osobine

- Buck derived konvertor.
- Izveden iz push-pull pojacavaca.
- Za visoke izlazne napone, sa Grecovim spojem.
- *Peak limiting current mode control* - vrsimo prekidanje prekidaca na osnovu kontrole vrsne vrijednosti ulazne struje. Time dobijamo da jezgro transformatora ne ode u zasicenje + kontrolu konvertora. 
$$V_{out} = 2nDV_{in}$$
## Prednosti

## Mane

- Naponi na prekidacima dostizu $2V_{in}$, sto je mana kada radimo sa visokim ulaznim naponima.
- 
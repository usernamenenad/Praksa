Model zad3


REM *****************************************:


REM * Common entries:


REM *****************************************:


REM Setting the simulation time step...
rtds_write 0x00000000 0x00000118


REM External SFP Link
rtds_write 0x00000007 0x00000000


REM Fast SFP Send


REM Converter solvers setup


REM Reset analog and digital outputs on simulation stop
rtds_write 0x00C00700 0x00000001
rtds_write 0x00F00000 0x00000001


REM Module block enable
rtds_write 0x00000003 0x00000000


REM LUT solver inputs...
rtds_write 0x01000000 0x00000000


REM HSSL configuration files...
rtds_file_write 0x01C20000 hssl_tx_config.txt
rtds_file_write 0x01C40000 hssl_rx_config.txt


REM Parallel DTV configuration...
rtds_write 0x02400000 0x00000000
rtds_write 0x02400020 0x00000000
rtds_write 0x02400040 0x00000000


REM *****************************************:


REM * SPC0 entries:


REM *****************************************:


REM SPC0 Topology Selector (TS) initialization...
rtds_file_write 0x08180000 SPC0_red_table.txt
rtds_write 0x08100020 0x00000004
rtds_write 0x08100021 0x00000002
rtds_write 0x08100023 0x00000000
rtds_write 0x08100024 0x00000000
rtds_write 0x08100025 0x00000000
rtds_write 0x08100026 0x00000000
rtds_write 0x08100027 0x00000000
rtds_write 0x0810002E 0x00000000
rtds_write 0x0810002F 0x00000000
rtds_write 0x08100030 0x00000000
rtds_write 0x08100031 0x00000000
rtds_write 0x08100032 0x00000000
rtds_write 0x08100033 0x00000000
rtds_write 0x08100034 0x00000000
rtds_write 0x08100035 0x00000000
rtds_write 0x08100036 0x00000000
rtds_write 0x08100037 0x00000000
rtds_write 0x08100038 0x00000000
rtds_write 0x08100039 0x00000000
rtds_file_write 0x08140000 igbt_leg_imem.txt
rtds_file_write 0x08142000 igbt_leg_lut.txt
rtds_write 0x08100040 0x00000001
rtds_write 0x08100041 0x00000000
rtds_write 0x08100043 0x00000000
rtds_write 0x08100044 0x00000000
rtds_write 0x08100045 0x00000000
rtds_write 0x08100046 0x00000000
rtds_write 0x08100047 0x00000000
rtds_write 0x0810004E 0x00000000
rtds_write 0x0810004F 0x00000000
rtds_write 0x08100050 0x00000000
rtds_write 0x08100051 0x00000000
rtds_write 0x08100052 0x00000000
rtds_write 0x08100053 0x00000000
rtds_write 0x08100054 0x00000000
rtds_write 0x08100055 0x00000000
rtds_write 0x08100056 0x00000000
rtds_write 0x08100057 0x00000000
rtds_write 0x08100058 0x00000000
rtds_write 0x08100059 0x00000000
rtds_file_write 0x08148000 trivial_imem.txt
rtds_file_write 0x0814A000 trivial_lut.txt
rtds_write 0x08100060 0x00000001
rtds_write 0x08100061 0x00000000
rtds_write 0x08100063 0x00000000
rtds_write 0x08100064 0x00000000
rtds_write 0x08100065 0x00000000
rtds_write 0x08100066 0x00000000
rtds_write 0x08100067 0x00000000
rtds_write 0x0810006E 0x00000000
rtds_write 0x0810006F 0x00000000
rtds_write 0x08100070 0x00000000
rtds_write 0x08100071 0x00000000
rtds_write 0x08100072 0x00000000
rtds_write 0x08100073 0x00000000
rtds_write 0x08100074 0x00000000
rtds_write 0x08100075 0x00000000
rtds_write 0x08100076 0x00000000
rtds_write 0x08100077 0x00000000
rtds_write 0x08100078 0x00000000
rtds_write 0x08100079 0x00000000
rtds_file_write 0x08150000 trivial_imem.txt
rtds_file_write 0x08152000 trivial_lut.txt


REM SPC0 Variable Delay initialization...
rtds_write 0x08100001 0x0


REM SPC0 Output voltage compare mode...
rtds_write 0x08100005 0x00000000
rtds_write 0x08100006 0x00000005


REM SPC0 Matrix multiplier initialization...
rtds_file_write 0x08000000 SPC0_Com_Word.txt
rtds_file_write 0x08020000 SPC0_Com_LUT.txt
rtds_file_write 0x08080000 SPC0_MAC0.txt
rtds_file_write 0x08082000 SPC0_MAC1.txt
rtds_file_write 0x08084000 SPC0_MAC2.txt
rtds_file_write 0x08086000 SPC0_MAC3.txt
rtds_write 0x08100004 0x00000001


REM SPC0 Contactors initialization...
rtds_write 0x08240000 0x00000000
rtds_write 0x08240080 0x00000000
rtds_write 0x08240100 0x00000000
rtds_write 0x08240180 0x00000000
rtds_write 0x08240200 0x00000000
rtds_write 0x08240280 0x00000000
rtds_write 0x08240300 0x00000000
rtds_write 0x08240380 0x00000000
rtds_write 0x08240400 0x00000001


REM SPC0 GDS compensation settings...
rtds_write 0x080C0000 0x00000001
rtds_write 0x080C0001 0x00000003
rtds_write 0x080C0004 0x3B6A0EA0
rtds_write 0x080C0005 0xEA0F0000
rtds_write 0x08100000 0x00000118
rtds_write 0x08100007 0x00000000


REM SPC0 FSM digital input pin assignments...
rtds_write 0x08100028 0x00000000
rtds_write 0x08100029 0x00000000
rtds_write 0x0810002A 0x00000000
rtds_write 0x0810002B 0x00000000
rtds_write 0x0810002C 0x00000040
rtds_write 0x0810002D 0x00000041
rtds_write 0x08100022 0x00000000


REM SPC0 Comparators initialization...


REM SPC0 DTSM initialization...


REM SPC0 Time Varying Elements initialization...
rtds_write 0x08300040 0x00000000
rtds_write 0x08300020 0x00000007


REM *****************************************:


REM * SPC1 entries:


REM *****************************************:


REM SPC1 Topology Selector (TS) initialization...
rtds_file_write 0x08580000 SPC1_red_table.txt
rtds_write 0x08500020 0x00000000
rtds_write 0x08500021 0x00000000
rtds_write 0x08500023 0x00000000
rtds_write 0x08500024 0x00000000
rtds_write 0x08500025 0x00000000
rtds_write 0x08500026 0x00000000
rtds_write 0x08500027 0x00000000
rtds_write 0x0850002E 0x00000000
rtds_write 0x0850002F 0x00000000
rtds_write 0x08500030 0x00000000
rtds_write 0x08500031 0x00000000
rtds_write 0x08500032 0x00000000
rtds_write 0x08500033 0x00000000
rtds_write 0x08500034 0x00000000
rtds_write 0x08500035 0x00000000
rtds_write 0x08500036 0x00000000
rtds_write 0x08500037 0x00000000
rtds_write 0x08500038 0x00000000
rtds_write 0x08500039 0x00000000
rtds_file_write 0x08540000 trivial_imem.txt
rtds_file_write 0x08542000 trivial_lut.txt
rtds_write 0x08500040 0x00000000
rtds_write 0x08500041 0x00000000
rtds_write 0x08500043 0x00000000
rtds_write 0x08500044 0x00000000
rtds_write 0x08500045 0x00000000
rtds_write 0x08500046 0x00000000
rtds_write 0x08500047 0x00000000
rtds_write 0x0850004E 0x00000000
rtds_write 0x0850004F 0x00000000
rtds_write 0x08500050 0x00000000
rtds_write 0x08500051 0x00000000
rtds_write 0x08500052 0x00000000
rtds_write 0x08500053 0x00000000
rtds_write 0x08500054 0x00000000
rtds_write 0x08500055 0x00000000
rtds_write 0x08500056 0x00000000
rtds_write 0x08500057 0x00000000
rtds_write 0x08500058 0x00000000
rtds_write 0x08500059 0x00000000
rtds_file_write 0x08548000 trivial_imem.txt
rtds_file_write 0x0854A000 trivial_lut.txt
rtds_write 0x08500060 0x00000000
rtds_write 0x08500061 0x00000000
rtds_write 0x08500063 0x00000000
rtds_write 0x08500064 0x00000000
rtds_write 0x08500065 0x00000000
rtds_write 0x08500066 0x00000000
rtds_write 0x08500067 0x00000000
rtds_write 0x0850006E 0x00000000
rtds_write 0x0850006F 0x00000000
rtds_write 0x08500070 0x00000000
rtds_write 0x08500071 0x00000000
rtds_write 0x08500072 0x00000000
rtds_write 0x08500073 0x00000000
rtds_write 0x08500074 0x00000000
rtds_write 0x08500075 0x00000000
rtds_write 0x08500076 0x00000000
rtds_write 0x08500077 0x00000000
rtds_write 0x08500078 0x00000000
rtds_write 0x08500079 0x00000000
rtds_file_write 0x08550000 trivial_imem.txt
rtds_file_write 0x08552000 trivial_lut.txt


REM SPC1 Variable Delay initialization...
rtds_write 0x08500001 0x0


REM SPC1 Output voltage compare mode...
rtds_write 0x08500005 0x00000000
rtds_write 0x08500006 0x00000000


REM SPC1 Matrix multiplier initialization...
rtds_file_write 0x08400000 SPC1_Com_Word.txt
rtds_file_write 0x08420000 SPC1_Com_LUT.txt
rtds_file_write 0x08480000 SPC1_MAC0.txt
rtds_file_write 0x08482000 SPC1_MAC1.txt
rtds_file_write 0x08484000 SPC1_MAC2.txt
rtds_file_write 0x08486000 SPC1_MAC3.txt
rtds_write 0x08500004 0x00000000


REM SPC1 Contactors initialization...


REM SPC1 GDS compensation settings...
rtds_write 0x084C0000 0x00000000
rtds_write 0x084C0001 0x00000000
rtds_write 0x084C0004 0x00000000
rtds_write 0x084C0005 0x00000000
rtds_write 0x08500000 0x00000000
rtds_write 0x08500007 0x00000000


REM SPC1 FSM digital input pin assignments...


REM SPC1 Comparators initialization...


REM SPC1 DTSM initialization...


REM SPC1 Time Varying Elements initialization...


REM *****************************************:


REM * SPC2 entries:


REM *****************************************:


REM SPC2 Topology Selector (TS) initialization...
rtds_file_write 0x08980000 SPC2_red_table.txt
rtds_write 0x08900020 0x00000000
rtds_write 0x08900021 0x00000000
rtds_write 0x08900023 0x00000000
rtds_write 0x08900024 0x00000000
rtds_write 0x08900025 0x00000000
rtds_write 0x08900026 0x00000000
rtds_write 0x08900027 0x00000000
rtds_write 0x0890002E 0x00000000
rtds_write 0x0890002F 0x00000000
rtds_write 0x08900030 0x00000000
rtds_write 0x08900031 0x00000000
rtds_write 0x08900032 0x00000000
rtds_write 0x08900033 0x00000000
rtds_write 0x08900034 0x00000000
rtds_write 0x08900035 0x00000000
rtds_write 0x08900036 0x00000000
rtds_write 0x08900037 0x00000000
rtds_write 0x08900038 0x00000000
rtds_write 0x08900039 0x00000000
rtds_file_write 0x08940000 trivial_imem.txt
rtds_file_write 0x08942000 trivial_lut.txt
rtds_write 0x08900040 0x00000000
rtds_write 0x08900041 0x00000000
rtds_write 0x08900043 0x00000000
rtds_write 0x08900044 0x00000000
rtds_write 0x08900045 0x00000000
rtds_write 0x08900046 0x00000000
rtds_write 0x08900047 0x00000000
rtds_write 0x0890004E 0x00000000
rtds_write 0x0890004F 0x00000000
rtds_write 0x08900050 0x00000000
rtds_write 0x08900051 0x00000000
rtds_write 0x08900052 0x00000000
rtds_write 0x08900053 0x00000000
rtds_write 0x08900054 0x00000000
rtds_write 0x08900055 0x00000000
rtds_write 0x08900056 0x00000000
rtds_write 0x08900057 0x00000000
rtds_write 0x08900058 0x00000000
rtds_write 0x08900059 0x00000000
rtds_file_write 0x08948000 trivial_imem.txt
rtds_file_write 0x0894A000 trivial_lut.txt
rtds_write 0x08900060 0x00000000
rtds_write 0x08900061 0x00000000
rtds_write 0x08900063 0x00000000
rtds_write 0x08900064 0x00000000
rtds_write 0x08900065 0x00000000
rtds_write 0x08900066 0x00000000
rtds_write 0x08900067 0x00000000
rtds_write 0x0890006E 0x00000000
rtds_write 0x0890006F 0x00000000
rtds_write 0x08900070 0x00000000
rtds_write 0x08900071 0x00000000
rtds_write 0x08900072 0x00000000
rtds_write 0x08900073 0x00000000
rtds_write 0x08900074 0x00000000
rtds_write 0x08900075 0x00000000
rtds_write 0x08900076 0x00000000
rtds_write 0x08900077 0x00000000
rtds_write 0x08900078 0x00000000
rtds_write 0x08900079 0x00000000
rtds_file_write 0x08950000 trivial_imem.txt
rtds_file_write 0x08952000 trivial_lut.txt


REM SPC2 Variable Delay initialization...
rtds_write 0x08900001 0x0


REM SPC2 Output voltage compare mode...
rtds_write 0x08900005 0x00000000
rtds_write 0x08900006 0x00000000


REM SPC2 Matrix multiplier initialization...
rtds_file_write 0x08800000 SPC2_Com_Word.txt
rtds_file_write 0x08820000 SPC2_Com_LUT.txt
rtds_file_write 0x08880000 SPC2_MAC0.txt
rtds_file_write 0x08882000 SPC2_MAC1.txt
rtds_file_write 0x08884000 SPC2_MAC2.txt
rtds_file_write 0x08886000 SPC2_MAC3.txt
rtds_write 0x08900004 0x00000000


REM SPC2 Contactors initialization...


REM SPC2 GDS compensation settings...
rtds_write 0x088C0000 0x00000000
rtds_write 0x088C0001 0x00000000
rtds_write 0x088C0004 0x00000000
rtds_write 0x088C0005 0x00000000
rtds_write 0x08900000 0x00000000
rtds_write 0x08900007 0x00000000


REM SPC2 FSM digital input pin assignments...


REM SPC2 Comparators initialization...


REM SPC2 DTSM initialization...


REM SPC2 Time Varying Elements initialization...


REM *****************************************:


REM * SPC3 entries:


REM *****************************************:


REM SPC3 Topology Selector (TS) initialization...
rtds_file_write 0x08D80000 SPC3_red_table.txt
rtds_write 0x08D00020 0x00000000
rtds_write 0x08D00021 0x00000000
rtds_write 0x08D00023 0x00000000
rtds_write 0x08D00024 0x00000000
rtds_write 0x08D00025 0x00000000
rtds_write 0x08D00026 0x00000000
rtds_write 0x08D00027 0x00000000
rtds_write 0x08D0002E 0x00000000
rtds_write 0x08D0002F 0x00000000
rtds_write 0x08D00030 0x00000000
rtds_write 0x08D00031 0x00000000
rtds_write 0x08D00032 0x00000000
rtds_write 0x08D00033 0x00000000
rtds_write 0x08D00034 0x00000000
rtds_write 0x08D00035 0x00000000
rtds_write 0x08D00036 0x00000000
rtds_write 0x08D00037 0x00000000
rtds_write 0x08D00038 0x00000000
rtds_write 0x08D00039 0x00000000
rtds_file_write 0x08D40000 trivial_imem.txt
rtds_file_write 0x08D42000 trivial_lut.txt
rtds_write 0x08D00040 0x00000000
rtds_write 0x08D00041 0x00000000
rtds_write 0x08D00043 0x00000000
rtds_write 0x08D00044 0x00000000
rtds_write 0x08D00045 0x00000000
rtds_write 0x08D00046 0x00000000
rtds_write 0x08D00047 0x00000000
rtds_write 0x08D0004E 0x00000000
rtds_write 0x08D0004F 0x00000000
rtds_write 0x08D00050 0x00000000
rtds_write 0x08D00051 0x00000000
rtds_write 0x08D00052 0x00000000
rtds_write 0x08D00053 0x00000000
rtds_write 0x08D00054 0x00000000
rtds_write 0x08D00055 0x00000000
rtds_write 0x08D00056 0x00000000
rtds_write 0x08D00057 0x00000000
rtds_write 0x08D00058 0x00000000
rtds_write 0x08D00059 0x00000000
rtds_file_write 0x08D48000 trivial_imem.txt
rtds_file_write 0x08D4A000 trivial_lut.txt
rtds_write 0x08D00060 0x00000000
rtds_write 0x08D00061 0x00000000
rtds_write 0x08D00063 0x00000000
rtds_write 0x08D00064 0x00000000
rtds_write 0x08D00065 0x00000000
rtds_write 0x08D00066 0x00000000
rtds_write 0x08D00067 0x00000000
rtds_write 0x08D0006E 0x00000000
rtds_write 0x08D0006F 0x00000000
rtds_write 0x08D00070 0x00000000
rtds_write 0x08D00071 0x00000000
rtds_write 0x08D00072 0x00000000
rtds_write 0x08D00073 0x00000000
rtds_write 0x08D00074 0x00000000
rtds_write 0x08D00075 0x00000000
rtds_write 0x08D00076 0x00000000
rtds_write 0x08D00077 0x00000000
rtds_write 0x08D00078 0x00000000
rtds_write 0x08D00079 0x00000000
rtds_file_write 0x08D50000 trivial_imem.txt
rtds_file_write 0x08D52000 trivial_lut.txt


REM SPC3 Variable Delay initialization...
rtds_write 0x08D00001 0x0


REM SPC3 Output voltage compare mode...
rtds_write 0x08D00005 0x00000000
rtds_write 0x08D00006 0x00000000


REM SPC3 Matrix multiplier initialization...
rtds_file_write 0x08C00000 SPC3_Com_Word.txt
rtds_file_write 0x08C20000 SPC3_Com_LUT.txt
rtds_file_write 0x08C80000 SPC3_MAC0.txt
rtds_file_write 0x08C82000 SPC3_MAC1.txt
rtds_file_write 0x08C84000 SPC3_MAC2.txt
rtds_file_write 0x08C86000 SPC3_MAC3.txt
rtds_write 0x08D00004 0x00000000


REM SPC3 Contactors initialization...


REM SPC3 GDS compensation settings...
rtds_write 0x08CC0000 0x00000000
rtds_write 0x08CC0001 0x00000000
rtds_write 0x08CC0004 0x00000000
rtds_write 0x08CC0005 0x00000000
rtds_write 0x08D00000 0x00000000
rtds_write 0x08D00007 0x00000000


REM SPC3 FSM digital input pin assignments...


REM SPC3 Comparators initialization...


REM SPC3 DTSM initialization...


REM SPC3 Time Varying Elements initialization...


REM *****************************************:


REM * SPC4 entries:


REM *****************************************:


REM SPC4 Topology Selector (TS) initialization...
rtds_file_write 0x09180000 SPC4_red_table.txt
rtds_write 0x09100020 0x00000000
rtds_write 0x09100021 0x00000000
rtds_write 0x09100023 0x00000000
rtds_write 0x09100024 0x00000000
rtds_write 0x09100025 0x00000000
rtds_write 0x09100026 0x00000000
rtds_write 0x09100027 0x00000000
rtds_write 0x0910002E 0x00000000
rtds_write 0x0910002F 0x00000000
rtds_write 0x09100030 0x00000000
rtds_write 0x09100031 0x00000000
rtds_write 0x09100032 0x00000000
rtds_write 0x09100033 0x00000000
rtds_write 0x09100034 0x00000000
rtds_write 0x09100035 0x00000000
rtds_write 0x09100036 0x00000000
rtds_write 0x09100037 0x00000000
rtds_write 0x09100038 0x00000000
rtds_write 0x09100039 0x00000000
rtds_file_write 0x09140000 trivial_imem.txt
rtds_file_write 0x09142000 trivial_lut.txt
rtds_write 0x09100040 0x00000000
rtds_write 0x09100041 0x00000000
rtds_write 0x09100043 0x00000000
rtds_write 0x09100044 0x00000000
rtds_write 0x09100045 0x00000000
rtds_write 0x09100046 0x00000000
rtds_write 0x09100047 0x00000000
rtds_write 0x0910004E 0x00000000
rtds_write 0x0910004F 0x00000000
rtds_write 0x09100050 0x00000000
rtds_write 0x09100051 0x00000000
rtds_write 0x09100052 0x00000000
rtds_write 0x09100053 0x00000000
rtds_write 0x09100054 0x00000000
rtds_write 0x09100055 0x00000000
rtds_write 0x09100056 0x00000000
rtds_write 0x09100057 0x00000000
rtds_write 0x09100058 0x00000000
rtds_write 0x09100059 0x00000000
rtds_file_write 0x09148000 trivial_imem.txt
rtds_file_write 0x0914A000 trivial_lut.txt
rtds_write 0x09100060 0x00000000
rtds_write 0x09100061 0x00000000
rtds_write 0x09100063 0x00000000
rtds_write 0x09100064 0x00000000
rtds_write 0x09100065 0x00000000
rtds_write 0x09100066 0x00000000
rtds_write 0x09100067 0x00000000
rtds_write 0x0910006E 0x00000000
rtds_write 0x0910006F 0x00000000
rtds_write 0x09100070 0x00000000
rtds_write 0x09100071 0x00000000
rtds_write 0x09100072 0x00000000
rtds_write 0x09100073 0x00000000
rtds_write 0x09100074 0x00000000
rtds_write 0x09100075 0x00000000
rtds_write 0x09100076 0x00000000
rtds_write 0x09100077 0x00000000
rtds_write 0x09100078 0x00000000
rtds_write 0x09100079 0x00000000
rtds_file_write 0x09150000 trivial_imem.txt
rtds_file_write 0x09152000 trivial_lut.txt


REM SPC4 Variable Delay initialization...
rtds_write 0x09100001 0x0


REM SPC4 Output voltage compare mode...
rtds_write 0x09100005 0x00000000
rtds_write 0x09100006 0x00000000


REM SPC4 Matrix multiplier initialization...
rtds_file_write 0x09000000 SPC4_Com_Word.txt
rtds_file_write 0x09020000 SPC4_Com_LUT.txt
rtds_file_write 0x09080000 SPC4_MAC0.txt
rtds_file_write 0x09082000 SPC4_MAC1.txt
rtds_file_write 0x09084000 SPC4_MAC2.txt
rtds_file_write 0x09086000 SPC4_MAC3.txt
rtds_write 0x09100004 0x00000000


REM SPC4 Contactors initialization...


REM SPC4 GDS compensation settings...
rtds_write 0x090C0000 0x00000000
rtds_write 0x090C0001 0x00000000
rtds_write 0x090C0004 0x00000000
rtds_write 0x090C0005 0x00000000
rtds_write 0x09100000 0x00000000
rtds_write 0x09100007 0x00000000


REM SPC4 FSM digital input pin assignments...


REM SPC4 Comparators initialization...


REM SPC4 DTSM initialization...


REM SPC4 Time Varying Elements initialization...


REM *****************************************:


REM * SPC5 entries:


REM *****************************************:


REM SPC5 Topology Selector (TS) initialization...
rtds_file_write 0x09580000 SPC5_red_table.txt
rtds_write 0x09500020 0x00000000
rtds_write 0x09500021 0x00000000
rtds_write 0x09500023 0x00000000
rtds_write 0x09500024 0x00000000
rtds_write 0x09500025 0x00000000
rtds_write 0x09500026 0x00000000
rtds_write 0x09500027 0x00000000
rtds_write 0x0950002E 0x00000000
rtds_write 0x0950002F 0x00000000
rtds_write 0x09500030 0x00000000
rtds_write 0x09500031 0x00000000
rtds_write 0x09500032 0x00000000
rtds_write 0x09500033 0x00000000
rtds_write 0x09500034 0x00000000
rtds_write 0x09500035 0x00000000
rtds_write 0x09500036 0x00000000
rtds_write 0x09500037 0x00000000
rtds_write 0x09500038 0x00000000
rtds_write 0x09500039 0x00000000
rtds_file_write 0x09540000 trivial_imem.txt
rtds_file_write 0x09542000 trivial_lut.txt
rtds_write 0x09500040 0x00000000
rtds_write 0x09500041 0x00000000
rtds_write 0x09500043 0x00000000
rtds_write 0x09500044 0x00000000
rtds_write 0x09500045 0x00000000
rtds_write 0x09500046 0x00000000
rtds_write 0x09500047 0x00000000
rtds_write 0x0950004E 0x00000000
rtds_write 0x0950004F 0x00000000
rtds_write 0x09500050 0x00000000
rtds_write 0x09500051 0x00000000
rtds_write 0x09500052 0x00000000
rtds_write 0x09500053 0x00000000
rtds_write 0x09500054 0x00000000
rtds_write 0x09500055 0x00000000
rtds_write 0x09500056 0x00000000
rtds_write 0x09500057 0x00000000
rtds_write 0x09500058 0x00000000
rtds_write 0x09500059 0x00000000
rtds_file_write 0x09548000 trivial_imem.txt
rtds_file_write 0x0954A000 trivial_lut.txt
rtds_write 0x09500060 0x00000000
rtds_write 0x09500061 0x00000000
rtds_write 0x09500063 0x00000000
rtds_write 0x09500064 0x00000000
rtds_write 0x09500065 0x00000000
rtds_write 0x09500066 0x00000000
rtds_write 0x09500067 0x00000000
rtds_write 0x0950006E 0x00000000
rtds_write 0x0950006F 0x00000000
rtds_write 0x09500070 0x00000000
rtds_write 0x09500071 0x00000000
rtds_write 0x09500072 0x00000000
rtds_write 0x09500073 0x00000000
rtds_write 0x09500074 0x00000000
rtds_write 0x09500075 0x00000000
rtds_write 0x09500076 0x00000000
rtds_write 0x09500077 0x00000000
rtds_write 0x09500078 0x00000000
rtds_write 0x09500079 0x00000000
rtds_file_write 0x09550000 trivial_imem.txt
rtds_file_write 0x09552000 trivial_lut.txt


REM SPC5 Variable Delay initialization...
rtds_write 0x09500001 0x0


REM SPC5 Output voltage compare mode...
rtds_write 0x09500005 0x00000000
rtds_write 0x09500006 0x00000000


REM SPC5 Matrix multiplier initialization...
rtds_file_write 0x09400000 SPC5_Com_Word.txt
rtds_file_write 0x09420000 SPC5_Com_LUT.txt
rtds_file_write 0x09480000 SPC5_MAC0.txt
rtds_file_write 0x09482000 SPC5_MAC1.txt
rtds_file_write 0x09484000 SPC5_MAC2.txt
rtds_file_write 0x09486000 SPC5_MAC3.txt
rtds_write 0x09500004 0x00000000


REM SPC5 Contactors initialization...


REM SPC5 GDS compensation settings...
rtds_write 0x094C0000 0x00000000
rtds_write 0x094C0001 0x00000000
rtds_write 0x094C0004 0x00000000
rtds_write 0x094C0005 0x00000000
rtds_write 0x09500000 0x00000000
rtds_write 0x09500007 0x00000000


REM SPC5 FSM digital input pin assignments...


REM SPC5 Comparators initialization...


REM SPC5 DTSM initialization...


REM SPC5 Time Varying Elements initialization...


REM *****************************************:


REM * SPC6 entries:


REM *****************************************:


REM SPC6 Topology Selector (TS) initialization...
rtds_file_write 0x09980000 SPC6_red_table.txt
rtds_write 0x09900020 0x00000000
rtds_write 0x09900021 0x00000000
rtds_write 0x09900023 0x00000000
rtds_write 0x09900024 0x00000000
rtds_write 0x09900025 0x00000000
rtds_write 0x09900026 0x00000000
rtds_write 0x09900027 0x00000000
rtds_write 0x0990002E 0x00000000
rtds_write 0x0990002F 0x00000000
rtds_write 0x09900030 0x00000000
rtds_write 0x09900031 0x00000000
rtds_write 0x09900032 0x00000000
rtds_write 0x09900033 0x00000000
rtds_write 0x09900034 0x00000000
rtds_write 0x09900035 0x00000000
rtds_write 0x09900036 0x00000000
rtds_write 0x09900037 0x00000000
rtds_write 0x09900038 0x00000000
rtds_write 0x09900039 0x00000000
rtds_file_write 0x09940000 trivial_imem.txt
rtds_file_write 0x09942000 trivial_lut.txt
rtds_write 0x09900040 0x00000000
rtds_write 0x09900041 0x00000000
rtds_write 0x09900043 0x00000000
rtds_write 0x09900044 0x00000000
rtds_write 0x09900045 0x00000000
rtds_write 0x09900046 0x00000000
rtds_write 0x09900047 0x00000000
rtds_write 0x0990004E 0x00000000
rtds_write 0x0990004F 0x00000000
rtds_write 0x09900050 0x00000000
rtds_write 0x09900051 0x00000000
rtds_write 0x09900052 0x00000000
rtds_write 0x09900053 0x00000000
rtds_write 0x09900054 0x00000000
rtds_write 0x09900055 0x00000000
rtds_write 0x09900056 0x00000000
rtds_write 0x09900057 0x00000000
rtds_write 0x09900058 0x00000000
rtds_write 0x09900059 0x00000000
rtds_file_write 0x09948000 trivial_imem.txt
rtds_file_write 0x0994A000 trivial_lut.txt
rtds_write 0x09900060 0x00000000
rtds_write 0x09900061 0x00000000
rtds_write 0x09900063 0x00000000
rtds_write 0x09900064 0x00000000
rtds_write 0x09900065 0x00000000
rtds_write 0x09900066 0x00000000
rtds_write 0x09900067 0x00000000
rtds_write 0x0990006E 0x00000000
rtds_write 0x0990006F 0x00000000
rtds_write 0x09900070 0x00000000
rtds_write 0x09900071 0x00000000
rtds_write 0x09900072 0x00000000
rtds_write 0x09900073 0x00000000
rtds_write 0x09900074 0x00000000
rtds_write 0x09900075 0x00000000
rtds_write 0x09900076 0x00000000
rtds_write 0x09900077 0x00000000
rtds_write 0x09900078 0x00000000
rtds_write 0x09900079 0x00000000
rtds_file_write 0x09950000 trivial_imem.txt
rtds_file_write 0x09952000 trivial_lut.txt


REM SPC6 Variable Delay initialization...
rtds_write 0x09900001 0x0


REM SPC6 Output voltage compare mode...
rtds_write 0x09900005 0x00000000
rtds_write 0x09900006 0x00000000


REM SPC6 Matrix multiplier initialization...
rtds_file_write 0x09800000 SPC6_Com_Word.txt
rtds_file_write 0x09820000 SPC6_Com_LUT.txt
rtds_file_write 0x09880000 SPC6_MAC0.txt
rtds_file_write 0x09882000 SPC6_MAC1.txt
rtds_file_write 0x09884000 SPC6_MAC2.txt
rtds_file_write 0x09886000 SPC6_MAC3.txt
rtds_write 0x09900004 0x00000000


REM SPC6 Contactors initialization...


REM SPC6 GDS compensation settings...
rtds_write 0x098C0000 0x00000000
rtds_write 0x098C0001 0x00000000
rtds_write 0x098C0004 0x00000000
rtds_write 0x098C0005 0x00000000
rtds_write 0x09900000 0x00000000
rtds_write 0x09900007 0x00000000


REM SPC6 FSM digital input pin assignments...


REM SPC6 Comparators initialization...


REM SPC6 DTSM initialization...


REM SPC6 Time Varying Elements initialization...


REM *****************************************:


REM * SPC7 entries:


REM *****************************************:


REM SPC7 Topology Selector (TS) initialization...
rtds_file_write 0x09D80000 SPC7_red_table.txt
rtds_write 0x09D00020 0x00000000
rtds_write 0x09D00021 0x00000000
rtds_write 0x09D00023 0x00000000
rtds_write 0x09D00024 0x00000000
rtds_write 0x09D00025 0x00000000
rtds_write 0x09D00026 0x00000000
rtds_write 0x09D00027 0x00000000
rtds_write 0x09D0002E 0x00000000
rtds_write 0x09D0002F 0x00000000
rtds_write 0x09D00030 0x00000000
rtds_write 0x09D00031 0x00000000
rtds_write 0x09D00032 0x00000000
rtds_write 0x09D00033 0x00000000
rtds_write 0x09D00034 0x00000000
rtds_write 0x09D00035 0x00000000
rtds_write 0x09D00036 0x00000000
rtds_write 0x09D00037 0x00000000
rtds_write 0x09D00038 0x00000000
rtds_write 0x09D00039 0x00000000
rtds_file_write 0x09D40000 trivial_imem.txt
rtds_file_write 0x09D42000 trivial_lut.txt
rtds_write 0x09D00040 0x00000000
rtds_write 0x09D00041 0x00000000
rtds_write 0x09D00043 0x00000000
rtds_write 0x09D00044 0x00000000
rtds_write 0x09D00045 0x00000000
rtds_write 0x09D00046 0x00000000
rtds_write 0x09D00047 0x00000000
rtds_write 0x09D0004E 0x00000000
rtds_write 0x09D0004F 0x00000000
rtds_write 0x09D00050 0x00000000
rtds_write 0x09D00051 0x00000000
rtds_write 0x09D00052 0x00000000
rtds_write 0x09D00053 0x00000000
rtds_write 0x09D00054 0x00000000
rtds_write 0x09D00055 0x00000000
rtds_write 0x09D00056 0x00000000
rtds_write 0x09D00057 0x00000000
rtds_write 0x09D00058 0x00000000
rtds_write 0x09D00059 0x00000000
rtds_file_write 0x09D48000 trivial_imem.txt
rtds_file_write 0x09D4A000 trivial_lut.txt
rtds_write 0x09D00060 0x00000000
rtds_write 0x09D00061 0x00000000
rtds_write 0x09D00063 0x00000000
rtds_write 0x09D00064 0x00000000
rtds_write 0x09D00065 0x00000000
rtds_write 0x09D00066 0x00000000
rtds_write 0x09D00067 0x00000000
rtds_write 0x09D0006E 0x00000000
rtds_write 0x09D0006F 0x00000000
rtds_write 0x09D00070 0x00000000
rtds_write 0x09D00071 0x00000000
rtds_write 0x09D00072 0x00000000
rtds_write 0x09D00073 0x00000000
rtds_write 0x09D00074 0x00000000
rtds_write 0x09D00075 0x00000000
rtds_write 0x09D00076 0x00000000
rtds_write 0x09D00077 0x00000000
rtds_write 0x09D00078 0x00000000
rtds_write 0x09D00079 0x00000000
rtds_file_write 0x09D50000 trivial_imem.txt
rtds_file_write 0x09D52000 trivial_lut.txt


REM SPC7 Variable Delay initialization...
rtds_write 0x09D00001 0x0


REM SPC7 Output voltage compare mode...
rtds_write 0x09D00005 0x00000000
rtds_write 0x09D00006 0x00000000


REM SPC7 Matrix multiplier initialization...
rtds_file_write 0x09C00000 SPC7_Com_Word.txt
rtds_file_write 0x09C20000 SPC7_Com_LUT.txt
rtds_file_write 0x09C80000 SPC7_MAC0.txt
rtds_file_write 0x09C82000 SPC7_MAC1.txt
rtds_file_write 0x09C84000 SPC7_MAC2.txt
rtds_file_write 0x09C86000 SPC7_MAC3.txt
rtds_write 0x09D00004 0x00000000


REM SPC7 Contactors initialization...


REM SPC7 GDS compensation settings...
rtds_write 0x09CC0000 0x00000000
rtds_write 0x09CC0001 0x00000000
rtds_write 0x09CC0004 0x00000000
rtds_write 0x09CC0005 0x00000000
rtds_write 0x09D00000 0x00000000
rtds_write 0x09D00007 0x00000000


REM SPC7 FSM digital input pin assignments...


REM SPC7 Comparators initialization...


REM SPC7 DTSM initialization...


REM SPC7 Time Varying Elements initialization...
*****************************************:


REM SP data configuration...
*****************************************:


REM Setting the capture sample step...


REM post SP Init calculation...
rtds_write  
rtds_write 0x00000041 0x000011C1
rtds_write 0x00000005 0x00000002
rtds_write 0x00000043 0x00002710
rtds_write 0x00000042 0x000001F3
rtds_write 0x0000000A 0x00000001
glbl_write 0xFD1A0104 0x0000380E
# disable active eth interfaces previously used by host applications
sys_command_custom "ifconfig eth1 down"
sys_command_custom "ifconfig eth2 down"
sys_command_custom "ifconfig eth3 down"
glbl_file_write 0x31000000 user_sp_cpu_0_imem.bin


REM Communication peripherals reset and load sequence
# Disable CAN interfaces from OS
# CAN bare metal app enables the clocks directly
# CANopen app enables them through ip link commands
sys_command 0x2
glbl_write 0xFD1A0104 0x280a


REM Restart counter for collected Linux OS communication apps
app_file_write 0x0 app_init


REM Clear the /mnt/ext_files. directory
file_write_custom clean_ext_files None
rtds_write 0x00000027 0x00000118
rtds_write 0x00000040 0x00FFFFFF
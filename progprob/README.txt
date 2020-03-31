Conversion table for mV to K, and vice versa, as based on these projections: 
https://www.lakeshore.com/products/cryogenic-temperature-sensors/silicon-diodes/dt-670/pages/Specifications.aspx

Usage:
- Fill out data.txt with the data. Temp in Kelvins on the left, corresponding Volt values on the right, one space between them. No leading or trailing whitespace or characters.
- Run program. Select whether to convert mV or K.
- Input the desired value, run the program.

Notes:
- Does NOT add new values to table as it goes; instead only uses the values in data.txt. It's assumed that since the voltage values go to 6 decimal palces and the system measures at 10hz, the table would rapidly swell to unmanageable size.
- If the value desired is between two values on that table, computes a point between them and returns it.
- If the value desired is beyond the range of the input data, computes a slope from the two nearest points and projects that outwards to the data value. This may result in negative values if the desired number is far enough out of range.

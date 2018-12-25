# g3a

Generator of Petri net models of triangular grid with plugs on edges


*Description:
------------

There is a 2-dimensional triangular grid of size k on a plane. The model is composed of packet switching devices whose ports are situated on sides of a unit-size equilateral triangle. Each
device works in full-duplex mode based on store-and-forward principle. Plugs, consisting of a single transition, are attached to the grid edges; a plug closes an output tract of a device port with its input tract. The grid consists of triangles of two types which interchange in a row. The triangle of the second type is obtained via rotation of the first type triangle by 180 degrees
regarding its center. Triangles are connected via merging contact places situated on common sides. On the edges of the
triangle, plug devices are attached. Triangular grids are applied in radio- and TV- broadcasting.


Command line format:
--------------------

>g3a k [p] [b] > tr_model.ndr


Parameters:
-----------

k   size of triangular grid;

p   the number of packets in each section of the internal buffer;

b   the available buffer size.

             
Output (file) format:
---------------------

.ndr  Petri nets graphical descriptions format according to http://www.laas.fr/tina


Tools to display, edit, visualize, and analyze generated models:
----------------------------------------------------------------

Tina Toolbox for analysis of Petri nets and Time Petri nets http://www.laas.fr/tina

Exported from Tina models are opened with other tools for Petri nets http://www.informatik.uni-hamburg.de/TGI/PetriNets /tools/quick.html


An example:
-----------

>g3a 4 2 3 > tr_k4p2b3.ndr

- Generate a model of a triangular grid with size 4, with 2 packets in each section of the internal buffer and available size of buffer 3.

>nd tr_k4p2b3.ndr

- The model is loaded into graphical environment of Tina. 

Menu: "Tools - stepper simulator - Rand"

- Watch the token game.


References:
-----------

Dmitry A. Zaitsev, Ivan D. Zaitsev and Tatiana R. Shmeleva. Infinite Petri Nets: Part 2, Modeling Triangular, Hexagonal, Hypercube and Hypertorus Structures, Complex Systems, 26(4), 2017, 341-371,  http://dx.doi.org/10.25088/ComplexSystems.26.4.341

Shmeleva T.R. Petri models program generator of triangular communication grids, Proceedings of the O.S. Popov ONAT, No.1, 2016, pp. 82-89, http://ojs.onat.edu.ua/index.php/sbornik_onat/article/view/944


----------------------------------------------------------
https://scholar.google.com.ua/citations?user=uuSbZDkAAAAJ
email: tishtri@rambler.ru
----------------------------------------------------------


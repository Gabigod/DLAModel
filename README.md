# DLAModel
This is an C program that simulate a DLA model aglomeration.

The problem was solved by following this steps:

	Step 1) It is generated a matrix 200x200 with a small cluster in the center.
	Step 2) It is generated, with a rand() function, an x and y coordinate (random particle) belonging to the matrix and that it is neither part of the cluster nor next to it.
	Step 3) This particle moves randomly in vertical and horizontal directions, always checking if the cluster is in the vicinity of this particle.
	Step 4) If the particle encounters the cluster, it joins it and a new random particle is generated, repeating steps 2 through 4 approximately 7500 times.
	Step 5) The program saves the matrix in a .txt file to view the cluster.

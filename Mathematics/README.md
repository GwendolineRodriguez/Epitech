# Mathematics
A collection of maths projects written in python or C.

## Pong
A program that print :  
- the coordinates of the ball speed vector,
- the ones of the ball in a given amount of time,
- the angle at which the ball will hit the bat(if ever the ball will indeed hit the bat, at any time from t=0).

```javascript
$> ./pong 1.1 3 5 -7 9 2 4 The speed vector coordinates are : (-8.10;6.00;-3.00)
At time t+4, ball coordinates will be : (-39.40;33.00;-10.00)
The incidence angle is :
16.57 degrees
```
## Chiffrement
#### Usage
```javascript
$> ./chiffrement message key flag
```
```javascript
$> ./chiffrement "Just because I don’t care doesn’t mean I don’t understand." "Homer S" 0
Key matrix :
72 111 109
101 114 32 83 0 0
Encrypted message :
26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 12333 11874
5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 18804 14859 12033 27738
23835 15331 21487 16656 13238 21696 15978 6976 20750 23307 14093 16788 11751 8981
22339 24861 15619 21295 16524 13668 26403 23610 15190 29451 25764 16106 26394 23307
14093 3312 5106 5014
```
```javascript
$> ./chiffrement "26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 12333 11874 5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 18804 14859 12033 27738 23835 15331 21487 16656 13238 21696 15978 6976 20750 23307 14093 16788 11751 8981 22339 24861 15619 21295 16524 13668 26403 23610 15190 29451 25764 16106 26394 23307 14093 3312 5106 5014" "Homer S" 1
Key matrix :
0.0 0.0 -0.004 0.012 0.013 -0.013
0.012
-0.012
0.004
Decrypted message :
Just because I don’t care doesn’t mean I don’t understand.
```
## Architecte
a program that compute points images in the plan after several transformations.
```javascript
$> ./architecte 5 0 -t -1 1
Translation by the vector (-1, 1)
1.00 0.00 -1.00
0.00 1.00 1.00
0.00 0.00 1.00 (5,0) => (4.00,1.00)
```
## Intersection
A program that shows potential intersection points between light rays and scene objects (here cylinders, spheres and cones).
```javascript
$> ./intersection opt xp yp zp xv yv zv p
```
```javascript
$> ./intersection 2 0 0 2 1 1 0 1
cylinder of radius 1
straight line going through the (0,0,2) point and of direction vector (1,1,0)
2 intersection points :
(0.707, 0.707, 2.000)
(-0.707, -0.707, 2.000)
```
## Tore
A program that solve a 4th degree equation : a4x4 + a3x3 + a2x2 + a1x + a0 = 0.
```javascript
$> ./tore opt a0 a1 a2 a3 a4 n
```
```javascript
$> ./tore 2 -1 0 6 -5 1 12
x = 0.5
x = 0.522727272727
x = 0.522740003514
x = 0.522740003526
```
## Bombyx
#### Usage
```javascript
$> ./bombyx -h 
USAGE
./bombyx n [k | i0 i1]
DESCRIPTION
n number of first generation individuals k growth rate from 1 to 4
i0 initial generation (included)
i1 final generation (included)
```
## Transfert
```javascript
$> ./transfert "0*1*2*3*4" "1" > file
$> head -n 12 file
0 -> 0.00000
0.001 -> 0.00100
0.002 -> 0.00201
0.003 -> 0.00302
0.004 -> 0.00403
0.005 -> 0.00505
0.006 -> 0.00607
0.007 -> 0.00710
0.008 -> 0.00813
0.009 -> 0.00916
0.01 -> 0.01020
0.011 -> 0.01125
```
## Monstre
```javascript
$> ./monstre -h
USAGE
./108monstre fun a0 a1 a2....
DESCRIPTION
fun function to be applied, among at least "EXP", "COS", "SIN", "COSH" and "SINH"
ai coeficients of the matrix
```
```javascript
$> ./monstre EXP 1 2 3 4 51.97 74.74
112.10 164.07
```

## Titrage
```javascript
$> ./titrage -h
USAGE
./titrage file
DESCRIPTION
file a csv file containing "vol;ph" lines
```
## Borwein
```javascript
$> ./borwein -h USAGE
./borwein n
DESCRIPTION
n constant defining the integral to be computed
```
```javascript
$> ./borwein 0 Rectangles:
I0 = 1.8208154789
diff = 0.2500191521
Trapezoids:
I0 = 1.5707660806 diff = -0.0000302462
Simpson:
I0 = 1.5707654320
diff = -0.0000308948
```

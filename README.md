miniRT
======

Project Overview
----------------

WARNING: Only Compatible With LINUX!

**miniRT** is a group project designed to implement a basic raytracer using the MiniLibX library. The program reads a scene description file (`.rt`) and generates an image of the scene, applying realistic lighting and shading based on ray-object intersections.

The goal is to simulate the way light interacts with simple geometric objects: spheres, planes, and cylinders. Objects appear black if the light incident on them does not contain their color (e.g., a red sphere under pure blue light).

The program also handles:

-   Ambient and diffuse lighting

-   Shadows

-   Object transformations (translation and rotation where applicable)

-   Window management with MiniLibX (ESC to exit, red cross to close)

* * * * *

Scene File Format (`.rt`)
-------------------------

### General Rules

-   Each scene must contain **at least one shape**.

-   Exactly **one** of each of these identifiers must be present:

    -   `A` → Ambient light

    -   `C` → Camera

    -   `L` → Light source

-   Any other identifiers or duplicates are invalid --- the program will exit immediately.

-   Elements can be separated by multiple line breaks, and parameters can be separated by one or more spaces or tabs.

-   The **first piece of information** in each line is the type identifier (1--2 characters), followed by the parameters in a strict order.

* * * * *

### Element Definitions

#### Ambient Lighting

Example in `.rt` file:

`A 0.2 255,255,255`

Parameters:

| Parameter | Meaning | Range |
| --- | --- | --- |
| A | Identifier | Fixed |
| 0.2 | Ambient lighting ratio | 0.0 -- 1.0 |
| 255,255,255 | Color (R,G,B) | 0 -- 255 each |

#### Camera

Example in `.rt` file:

`C -50.0,0,20 0,0,1 70`

Parameters:

| Parameter | Meaning | Range |
| --- | --- | --- |
| C | Identifier | Fixed |
| -50.0,0,20 | Camera position (x,y,z) | Float values |
| 0,0,1 | Normalized orientation vector | Each axis [-1,1] |
| 70 | Horizontal field of view (FOV) | 0 -- 180 degrees |

#### Light

Example in `.rt` file:

`L -40.0,50.0,0.0 0.6 10,0,255`

Parameters:

| Parameter | Meaning | Range |
| --- | --- | --- |
| L | Identifier | Fixed |
| -40.0,50.0,0.0 | Light position (x,y,z) | Float values |
| 0.6 | Brightness ratio | 0.0 -- 1.0 |
| 10,0,255 | Color (R,G,B) | 0 -- 255 each |

#### Sphere

Example in `.rt` file:

`sp 0.0,0.0,20.6 12.6 10,0,255`

Parameters:

| Parameter | Meaning | Range |
| --- | --- | --- |
| sp | Identifier | Fixed |
| 0.0,0.0,20.6 | Center coordinates (x,y,z) | Float values |
| 12.6 | Diameter | Float |
| 10,0,255 | Color (R,G,B) | 0 -- 255 each |

#### Plane

Example in `.rt` file:

`pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225`

Parameters:

| Parameter | Meaning | Range |
| --- | --- | --- |
| pl | Identifier | Fixed |
| 0.0,0.0,-10.0 | Point on plane (x,y,z) | Float values |
| 0.0,1.0,0.0 | Normalized vector | Each axis [-1,1] |
| 0,0,225 | Color (R,G,B) | 0 -- 255 each |

#### Cylinder

Example in `.rt` file:

`cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255`

Parameters:

| Parameter | Meaning | Range |
| --- | --- | --- |
| cy | Identifier | Fixed |
| 50.0,0.0,20.6 | Center coordinates (x,y,z) | Float values |
| 0.0,0.0,1.0 | Axis vector (normalized) | Each axis [-1,1] |
| 14.2 | Diameter | Float |
| 21.42 | Height | Float |
| 10,0,255 | Color (R,G,B) | 0 -- 255 each |

* * * * *

### Example `.rt` File

```
A 0.2 255,255,255        # Ambient light
C -50.0,0,20 0,0,1 70   # Camera
L -40.0,50.0,0.0 0.6 10,0,255   # Light

sp 0.0,0.0,20.6 12.6 10,0,255   # Sphere
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225   # Plane
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255   # Cylinder
```

Lines can be separated by multiple newlines.\
Parameters can be separated by spaces or tabs.\
Any invalid element or duplicate identifier will cause the program to exit immediately.

* * * * *

Raytracing Algorithm
--------------------

The raytracer simulates light rays from the camera through each pixel into the scene:

1.  **Ray casting:** Each pixel sends a ray into the scene.

2.  **Intersection:** Determine the first object the ray intersects.

3.  **Shading:** Calculate color based on ambient and diffuse lighting.

4.  **Color evaluation:** If the incoming light does not contain the object's color, the object appears black.

5.  **Shadows:** Light paths blocked by other objects produce shadows.

6.  **Final pixel color:** Combined lighting effects produce the final color for that pixel.

* * * * *

Compilation and Usage
---------------------

**Compile**

`make`

**Run**

`./miniRT <scene_file.rt>`

**Makefile Targets**

-   `all` → Compile program

-   `clean` → Remove object files

-   `fclean` → Remove object files and binary

-   `re` → Clean and rebuild

-   `bonus` → Build bonus features (if implemented)

**Controls**

-   Press ESC → Close window and exit cleanly

-   Click red cross → Close window and exit cleanly

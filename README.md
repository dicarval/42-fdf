
# Creating a Wireframe model
<p align="center">
	<img class="center" src="/home/dicarval/Pictures/FDF.png" width=70% height=70%>
</p>

## Introduction
Wireframe models are an essential tool in the world 
of graphics programming, as they allow designers and 
developers to visualize and understand the structure 
and layout of 3D objects without the need for surface 
details or textures. In this project, my main goal was
to create a simple wireframe model representation of 
a 3D landscape by linking various points (x, y, z) 
using line segments (edges).

To create the wireframe model, I used a combination 
of graphics programming techniques and spatial geometry 
principles. By linking points in 3D space using line segments,
I was able to represent the basic structure and layout of the 
landscape. This process allows to visualize and understand 
the overall shape and form of the landscape, as well as identify 
any potential issues or areas for improvement.

One of the key advantages of using a wireframe model in this 
context is the ability to quickly and easily manipulate and 
modify the model as needed. By adjusting the position of points 
and line segments, I was able to refine the overall structure 
and layout of the landscape to better match our desired design.


## Theory
### Isometric projection
To convert 3D coordinates into 2D isometric projection coordinates I used the following formula:

```c
    x = (isoX - isoY) * cos(30)
    y = (isoX + isoY) * sin(30) - isoZ
```
where isoX and isoY are the isometric projection's x and y coordinates, and isoZ is the isometric projection's z coordinate.

### Parallel projection
To convert 3D coordinates into 2D parallel projection coordinates I used the following formula:
```c
    x = (parellX - parellZ) * cos(45)
    y = (pparellY - parellZ) * sin(45)
```
where parellX and parellY are the parallel projection's x and y coordinates, and parellZ is the paralell projection's z coordinate.

## To draw a line

#### DDA (Digital Differential Analyzer) algorithm: 
This algorithm uses floating-point arithmetic to draw a line between two points by incrementally increasing the x or y coordinate by the slope of the line. It is simple to implement but relatively slow compared to other algorithms.



### Minilibx

The **minilibx** is a small C library used for rendering graphics, primarily used by [42](https://en.wikipedia.org/wiki/42_(school)) students. Is built on top of the X Window System API, to provide a much simpler programming interface suited for beginners. Indeed, no X knowledge is needed at all to render graphics properly using this kind of library.

In order to understand the library I used here is the documentation: [42 Minilibx Docs](https://harm-smits.github.io/42docs/libs/minilibx)

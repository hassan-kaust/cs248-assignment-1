# CS248 Assignment 1: Simple Ray Tracing

openFrameworks (C++) ray tracer. Source is in `src/`.

## Build and run

    make
    make RunRelease

`ofApp::setup()` sets `perspectiveMode` (`true` = perspective, `false` = parallel projection).

## What is in the scene

| # | Object | Color |
|---|--------|-------|
| 1 | Sphere (z > 0) | (1, 0, 0) |
| 2 | Ellipsoid (z > 0) | (0, 1, 0) |
| 3 | Ellipsoid, center (1.5, -0.5, 1.8) | (0, 0, 1) |
| 4 | Plane, point (0, -1.4, 0), normal (0, 1, 0) | (0.5, 0.5, 0.5) |

Viewpoint (0, 0, -1), viewing plane z = 0 with extents x in [-2, 2] and y in [-1.5, 1.5], 640x480.
Lambertian shading (ka = 0.2, kd = 0.8), light at (0, 5, 0), shadow rays.

Note: under parallel projection the rays all point along +z, so the floor
(normal +y) is seen edge-on and does not appear. This is expected. It is
visible in perspective mode.

## Files for the grader

### `debug_log.txt`
A chronological log of the bugs found and fixed while building the project
(each entry has symptom, cause, fix and result), plus a list of known issues.
It covers the edge-on floor in parallel mode, adding the plane, the upside-down
image (row-to-`v` mapping in `RayGenerator.cpp`), a stale build that hid the
fixes, and shadow acne (fixed by offsetting the shadow-ray origin in `Shade.cpp`).

### `src/<FileName>_prompts.txt`
Each source file in `src/` has a matching `<FileName>_prompts.txt` that records
the prompts given to the AI assistant to produce or change that file:

| Prompts file | Source it documents |
|--------------|---------------------|
| `Vec3_prompts.txt` | `Vec3.h/.cpp`, own vector library |
| `Ray_prompts.txt` | `Ray.h/.cpp` |
| `RayGenerator_prompts.txt` | `RayGenerator.h/.cpp`, parallel and perspective rays |
| `Object_prompts.txt` | `Object.h/.cpp`, base class |
| `Sphere_prompts.txt` | `Sphere.h/.cpp` |
| `Ellipsoid_prompts.txt` | `Ellipsoid.h/.cpp` |
| `Plane_prompts.txt` | `Plane.h/.cpp` |
| `Shade_prompts.txt` | `Shade.h/.cpp`, Lambertian shading and shadows |
| `Util_prompts.txt` | `Util.h/.cpp`, color clamping |
| `ofApp_prompts.txt` | `ofApp.h/.cpp`, canvas, scene setup, render loop |

`main.cpp` is the unmodified openFrameworks entry point and has no prompts file.
`debug_log.txt` covers the changes made later, during debugging.

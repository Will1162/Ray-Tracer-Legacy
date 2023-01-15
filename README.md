<img src="https://img.shields.io/github/repo-size/Will1162/Ray-Tracer-Legacy"/> <img src="https://img.shields.io/tokei/lines/github/Will1162/Ray-Tracer-Legacy"/> <img src="https://img.shields.io/github/downloads/Will1162/Ray-Tracer-Legacy/total"/> <img src="https://img.shields.io/github/last-commit/Will1162/Ray-Tracer-Legacy"/>

# Ray Tracer (Legacy)
	
## About the project

A more simulation based ray tracing engine, which builds on top of my [Ray Casting engine](https://github.com/Will1162/Ray-Caster).

Currently the engine has the capabilites to render spheres of any RGB colour with one of two materials, Lambertian, and metal, where metal can also have a "fuzz" value associated with it.

The entire program runs on a single CPU thread, making it very slow at rendering even simple scenes at low quality and resolution due to the required millions of rays and vector calculations. As a result, as new version of the program has been made ([OpenCL Ray Tracer](https://github.com/Will1162/OpenCL-Ray-Tracer)) which runs using the GPU for computation.

## Sources

- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley

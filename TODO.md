# TODO

## Phase 1: Core 2D Improvements

### Rendering Primitives
- [x] Fix line drawing algorithm (current version has issues with steep slopes)
  - [x] Implement proper Bresenham's line algorithm
  - [x] Handle all octants correctly
- [x] Add circle drawing (Midpoint Circle Algorithm)
- [ ] Add rectangle drawing (filled and wireframe)
- [ ] Add polygon drawing (arbitrary n-gons)

### Triangle Rasterizer Improvements
- [ ] Add proper edge fill rules (top-left rule) to avoid gaps/overlaps
- [ ] Add clipping against screen boundaries
- [ ] Optimize scanline algorithm (remove redundant calculations)
- [ ] Add sub-pixel precision option
- [ ] Handle degenerate cases better (zero-area triangles, etc.)

### Color & Blending
- [ ] Add alpha blending support
- [ ] Implement color interpolation across triangles (Gouraud shading)
- [ ] Add basic color utilities (RGB to hex, color mixing, etc.)

## Phase 2: 3D Foundation

### 3D Math Library
- [ ] Add vec3 type and operations
  - [ ] add, sub, scale, dot, cross
  - [ ] normalize, length, distance
- [ ] Add vec4 type for homogeneous coordinates
- [ ] Add mat4 type and operations
  - [ ] identity, multiply
  - [ ] translation, rotation, scale matrices
  - [ ] lookAt matrix (view transform)
  - [ ] perspective projection matrix
  - [ ] orthographic projection matrix

### 3D to 2D Pipeline
- [ ] Implement vertex transformation pipeline
  - [ ] Model transform
  - [ ] View transform
  - [ ] Projection transform
  - [ ] Viewport transform
- [ ] Add perspective divide (homogeneous to Cartesian)
- [ ] Add screen space mapping

## Phase 3: 3D Rasterization

### Depth Buffer
- [ ] Add z-buffer to Framebuffer struct
- [ ] Implement depth testing
- [ ] Clear depth buffer each frame
- [ ] Interpolate depth (z) across triangles

### Backface Culling
- [ ] Implement basic backface culling
- [ ] Add winding order detection
- [ ] Make culling toggleable

### Mesh Support
- [ ] Create mesh data structure
  - [ ] Vertex array
  - [ ] Index array (for sharing vertices)
  - [ ] Normal array
- [ ] Load simple mesh formats
  - [ ] Start with hardcoded cube/pyramid
  - [ ] Add OBJ file loader later
- [ ] Add mesh transformation functions

## Phase 4: Lighting & Shading

### Lighting Models
- [ ] Add normal vectors to vertices
- [ ] Implement flat shading (per-triangle)
- [ ] Implement Gouraud shading (per-vertex, interpolated)
- [ ] Add directional light
- [ ] Add point light
- [ ] Add ambient + diffuse lighting (Lambertian)
- [ ] Add specular highlights (Phong/Blinn-Phong)

### Attribute Interpolation
- [ ] Interpolate vertex colors across triangle
- [ ] Interpolate normals across triangle
- [ ] Add barycentric coordinate calculation
- [ ] Perspective-correct interpolation

## Phase 5: Texturing

### Texture System
- [ ] Add texture data structure
- [ ] Load textures from image files (PNG/BMP)
- [ ] Add UV coordinate support to vertices
- [ ] Implement texture sampling (point sampling)
- [ ] Implement bilinear filtering
- [ ] Add texture wrapping modes (repeat, clamp)

### Texture Mapping
- [ ] Interpolate UV coordinates across triangles
- [ ] Add perspective-correct texture mapping
- [ ] Support multiple textures per frame

## Phase 6: Optimization

### Performance
- [ ] Profile rendering pipeline
- [ ] Add bounding box tests before rasterization
- [ ] Implement frustum culling
- [ ] Add SIMD optimizations (if appropriate)
- [ ] Consider multi-threading for scanlines
- [ ] Add dirty rectangle tracking

### Code Quality
- [ ] Add assertions and better error handling
- [ ] Add unit tests for math functions
- [ ] Document all public APIs
- [ ] Add debug visualization modes

## Phase 7: Advanced Features

### Camera System
- [ ] Add camera struct (position, target, up, fov)
- [ ] Add camera movement functions
- [ ] Add FPS-style camera controls
- [ ] Add orbit camera mode

### Scene Management
- [ ] Add scene graph structure
- [ ] Support multiple objects
- [ ] Add transform hierarchy
- [ ] Batch similar objects

### Effects
- [ ] Add wireframe overlay mode
- [ ] Add normal visualization
- [ ] Add fog effect
- [ ] Add simple shadows (shadow mapping)

### File I/O
- [ ] Implement OBJ file loader
- [ ] Add PNG/BMP texture loader
- [ ] Consider MTL file support (materials)

## Phase 8: Nice-to-Haves

### Developer Tools
- [ ] Add FPS counter
- [ ] Add render statistics (tris/sec, etc.)
- [ ] Add performance overlay
- [ ] Add debug console/command system

### Input & Interaction
- [ ] Add keyboard input handling
- [ ] Add mouse input handling
- [ ] Add object picking (ray casting)

### Additional Rendering
- [ ] Add line anti-aliasing
- [ ] Add MSAA or FXAA
- [ ] Add skybox rendering
- [ ] Add basic particle system

---

## Current Status

**Completed:**
- Basic framebuffer system
- Pixel plotting
- Line drawing (needs improvement)
- Wireframe triangle drawing
- Filled triangle rasterization (scanline algorithm, now fully iterative)
- SDL3 window/rendering setup

**Next Recommended Steps:**
1. Fix the Bresenham line algorithm (foundation for everything)
2. Add vec3 and basic 3D math
3. Add depth buffer
4. Render a spinning 3D cube
5. Add basic lighting

---

## Notes

- Focus on correctness first, optimization later
- Test each feature with simple cases before moving on
- Keep the API simple and consistent
- Document tricky algorithms inline
- The triangle rasterizer is now fully iterative (no recursion)

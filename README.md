## C++ BMP Image Processor

A command-line utility written in C++ for fast, dependency-free BMP image manipulation. This tool allows you to apply various filters to 24-bit bitmap images directly from your terminal. This project is built from scratch to demonstrate low-level binary file parsing and image processing algorithms.

### Available filters

- Grayscale (-grayscale): Converts the image to black and white using weighted luminance.

- Negative (-negative): Inverts all colors to produce a photographic negative.

- Threshold (-threshold [value]): Converts the image to pure black and white based on a brightness limit. Allowed values: 0 to 255 (typically 128).

- Rotate (-rotate): Rotates the image (90 degrees).

- Flip (-flip [h/v]): Mirrors the image horizontally or vertically.

- Scale (-scale [koef]): Resizes the image by a specified coefficient. Allowed values: 0.1 to 10.0
    - Downscaling: Use a coefficient > 1 (e.g., 2.0 makes the image 2x smaller).
    - Upscaling: Use a coefficient < 1 (e.g., 0.5 makes the image 2x larger).

- Blur (-blur): Smooths the image.

- Sharpening (-sharpening): Enhances edges and fine details using a convolution matrix.

### Usage

The application is a command-line tool. Use the following syntax to process your images:

```./image_processor <input.bmp> <output.bmp> [-filter1 params] [-filter2 params] ...```

If you want to see the filters in action before running the tool, check out the examples/ folder.

### Architecture & Design Patterns
This project follows Object-Oriented Programming (OOP) principles to ensure code maintainability and scalability.

###### Polymorphism:
I implemented a polymorphic filter system that allows the application to treat different image effects uniformly. By using a base abstract class, adding a new filter requires zero changes to the core logic:

- Base Class Filter: Defines a virtual apply(Image& img) method.

- Derived Classes: Each filter overrides the base method with its own specific algorithm.

- Dynamic Dispatch: The application selects the appropriate filter at runtime based on user input, storing them in smart pointers (std::unique_ptr<BaseFilter>).

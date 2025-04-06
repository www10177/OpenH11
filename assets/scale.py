import sys
from PIL import Image

def scale_image(input_file, output_file):
    try:
        with Image.open(input_file) as img:
            original_width, original_height = img.size
            print(f"Original size: {img.size}")
            # Compute new dimensions by scaling each dimension by 1/10.
            new_width = original_width // 10
            new_height = original_height // 10
            print(f"Resized dimensions: {new_width}x{new_height}")
            # Resize image using a high-quality downsampling filter.
            scaled_img = img.resize((new_width, new_height), Image.LANCZOS)
            scaled_img.save(output_file)
            print(f"Saved resized image as: {output_file}")
    except Exception as e:
        print(f"Error processing image: {e}")

def main():
    if len(sys.argv) < 2:
        print("Usage: python script.py <input_file.png>")
        sys.exit(1)
    
    input_file = sys.argv[1]
    # Create output filename by removing extension and appending '_resize.png'
    base_name = input_file.rsplit('.', 1)[0]
    output_file = f"{base_name}_resize.png"
    scale_image(input_file, output_file)

if __name__ == "__main__":
    main()

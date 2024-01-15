

def apply_lut(lut_path: str, image_path: str, output_path: str) -> str:
    """Apply a LUT to an image.

    Args:
        lut_path (str): Path to the LUT file.
        image_path (str): Path to the input image.
        output_path (str): Path to the output image.

    Returns:
        str: 'success:ok' if the LUT was applied successfully.
    """

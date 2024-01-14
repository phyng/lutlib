use pyo3::prelude::*;

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("lutlib/src/bridge.h");

        type BridgeClient;

        fn new_bridge_client() -> UniquePtr<BridgeClient>;
        fn apply_lut(&self, lut_path: String, image_path: String, output_path: String) -> String;
    }
}

/// Formats the sum of two numbers as string.
#[pyfunction]
fn apply_lut(a: usize, b: usize) -> PyResult<String> {
    let client = ffi::new_bridge_client();
    let result = client.apply_lut(
        "/Users/phyng/dev/lut/hype.cube".to_string(),
        "/Users/phyng/dev/lut/1.jpg".to_string(),
        "/Users/phyng/dev/lut/1_output.jpg".to_string(),
    );
    Ok((a + b).to_string() + &result)
}

/// A Python module implemented in Rust.
#[pymodule]
fn lutlib(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_function(wrap_pyfunction!(apply_lut, m)?)?;
    Ok(())
}

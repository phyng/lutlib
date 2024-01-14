// build.rs

fn main() {
  cxx_build::bridge("src/lib.rs")
      .file("src/bridge.cc")
      .flag_if_supported("-std=c++14")
      .flag_if_supported("-Wno-missing-field-initializers") // 忽略特定的警告
      .flag_if_supported("-Wno-deprecated-declarations") // 忽略 deprecated-declarations 警告
      .compile("cxx-demo");

  println!("cargo:rerun-if-changed=src/lib.rs");
  println!("cargo:rerun-if-changed=src/bridge.cc");
  println!("cargo:rerun-if-changed=src/bridge.h");
}

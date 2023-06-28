with (import <nixpkgs> { });
mkShell {
  buildInputs = [
    rustup
	  rust-analyzer
    hyperfine
  ];
  shellHook = ''
    echo "Start Developing..."
  '';
}

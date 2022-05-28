{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    nativeBuildInputs = with pkgs; [
      cmocka
      gcc
      meson
      ninja
      pkg-config
    ];
}

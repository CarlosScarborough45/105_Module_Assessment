#!/usr/bin/env python3
import os
import subprocess
import time
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent
GCC_DIR = Path(r"D:\Users\932400098\scoop\apps\gcc\current\bin")
OUTPUT = PROJECT_ROOT / "105project.exe"


def make_env():
    env = os.environ.copy()
    env["PATH"] = str(GCC_DIR) + os.pathsep + env.get("PATH", "")
    return env


def build():
    if OUTPUT.exists():
        OUTPUT.unlink()

    cmd = [
        str(GCC_DIR / "g++.exe"),
        *[str(path.name) for path in sorted(PROJECT_ROOT.glob("*.cpp"))],
        "-I",
        str(PROJECT_ROOT / "Headers"),
        "-o",
        str(OUTPUT),
    ]
    print(f"$ {' '.join(cmd)}")
    result = subprocess.run(cmd, cwd=str(PROJECT_ROOT), env=make_env())
    if result.returncode != 0:
        raise RuntimeError("Compile failed")
    print(f"Built: {OUTPUT}")


def get_files():
    files = {}
    for path in PROJECT_ROOT.rglob("*"):
        if path.is_file() and ".git" not in path.parts and "out" not in path.parts:
            files[str(path)] = path.stat().st_mtime_ns
    return files


if __name__ == "__main__":
    print(f"Watching project: {PROJECT_ROOT}")
    print("Rebuilding on any file save. Press Ctrl+C to stop.")
    snapshot = get_files()

    while True:
        current = get_files()
        if current != snapshot:
            print("Detected change. Rebuilding...")
            try:
                build()
            except RuntimeError:
                print("Build failed. Waiting for next save...")
            snapshot = current
        time.sleep(1)

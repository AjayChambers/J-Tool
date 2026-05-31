param(
  # Parameter: Build Type Configuration
  [Parameter(Mandatory = $false, Position = 0)]
  [ValidateSet("Debug", "Release", "RelWithDebInfo")]
  [string]$BuildType = "Debug"
)

$preset = "Windows-$BuildType"
$generator = "Ninja"
$toolchain = Resolve-Path "./cmake/toolchains/windows-toolchain.cmake"`


$cmakeArgs = @(
  "--toolchain", $toolchain
  "--preset", $preset
  "-B", "build"
  "-S", "."
  "-G", $generator
  "-DCMAKE_BUILD_TYPE=$BuildType"
  "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON"
)

# Print the command that executes
$escaped = $cmakeArgs | ForEach-Object {
  if ($_ -match '\s') { '"{0}"' -f $_ } else { $_ }
}

Write-Host "`n  EXECUTING CMAKE COMMAND: " -ForegroundColor Cyan
Write-Host "cmake $escaped" -ForegroundColor Yellow
Write-Host ""

# --- Execute ---
& cmake @cmakeArgs

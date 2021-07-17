# example-app

## How to build

System requirements to build:

- macOS 11+
- Xcode 12+
- Command Line Tools for Xcode
- CMake (`brew install cmake`)

### Steps

1.  Find your codesign identity if you have one.<br />
    (Skip this step if you don't have your codesign identity.)

    ```shell
    security find-identity -p codesigning -v | grep 'Developer ID Application'
    ```

    The result is as follows.

    ```text
    1) 8D660191481C98F5C56630847A6C39D95C166F22 "Developer ID Application: Fumihiko Takayama (G43BCU2T37)"
    ```

    Your codesign identity is `8D660191481C98F5C56630847A6C39D95C166F22` in the above case.

2.  Set environment variable to use your codesign identity.<br />
    (Skip this step if you don't have your codesign identity.)

    ```shell
    export PQRS_ORG_CODE_SIGN_IDENTITY=8D660191481C98F5C56630847A6C39D95C166F22
    ```

3.  Build and run.

    ```shell
    make all run
    ```

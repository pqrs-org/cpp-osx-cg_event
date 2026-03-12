BUILD_ROOT := /tmp/pqrs-osx-cg_event-tests

all:
	xcodegen generate
	xcodebuild -project test.xcodeproj -scheme test -configuration Release SYMROOT="$(BUILD_ROOT)/build" -derivedDataPath "$(BUILD_ROOT)/DerivedData"
	make run

clean:
	rm -rf "$(BUILD_ROOT)"
	rm -rf *.xcodeproj

run:
	"$(BUILD_ROOT)/build/Release/test"

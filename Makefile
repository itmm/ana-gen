MDs = $(shell hx-srcs.sh)
CPPs = $(shell hx-files.sh $(MDs))
APPs = $(CPPs:.cpp=)
CXXFLAGS += -Wall -std=c++17

.PHONY: clean all

all: hx-run hx-run-combined

index-combined.md: $(MDs)
	$(error "update $@!")

hx-run: $(MDs)
	@echo "HX"
	@hx
	@date >$@
	@make --no-print-directory $(APPs)

hx-run-combined: index-combined.md
	@echo "HX combined"
	@hx --css=./slides-combined/slides.css $^
	@date >$@

%: %.cpp
	@echo "C++ $@"
	@$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@echo "RM"
	@rm -f $(APPs) $(CPPs) hx-run hx-run-combined


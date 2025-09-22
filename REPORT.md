Q1. Explain the linking rule in this part's Makefile: $(TARGET): $(OBJECTS). How does it differ from a Makefile rule that links against a library?

The rule $(TARGET): $(OBJECTS) tells make that the final executable relies on all the listed object files. If any of these object files are updated, the target will be rebuilt. Here, the linker takes all the .o files and combines them into a single executable binary.
When linking against a library, instead of listing multiple .o files directly, the rule uses an option like -lmylib . In this case, the linker retrieves the necessary symbols from the library to create the final executable.

Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?

A Git tag is a pointer to a specific commit, commonly used to mark important milestones like releases or stable versions. It helps identify and return to a particular state of the code easily. There are two types of tags: lightweight tags, which are simple pointers to a commit without extra details, and annotated tags, which include metadata such as the author, date, and a message. Annotated tags are preferred for official releases as they provide more context and information about the version

Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?

Creating a Release on GitHub helps package and share a specific version of your project in a clear and organized way. It marks a stable point in the codebase, often linked to a Git tag, and provides users with details about updates or changes. Attaching binaries (like a compiled executable) makes it easy for others to use the program without having to build it from source, saving time and reducing setup complexity. This is especially useful for non-developers or end-users who just need the ready-to-use software

Q4. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?

In Part 2, all source files were compiled directly into object files and linked together to create the executable. In Part 3, the build process is split into two phases: first, utility source files are compiled into object files and archived into a static library (lib/libmyutils.a) using ar, then main.c is compiled and linked against that library using -Llib -lmyutils. New variables like LIB_DIR and LIBNAME were added, along with separate targets for building the library and the client_static executable. Additional rules were included for creating the archive (ar rcs) and indexing it (ranlib). The top-level Makefile now delegates tasks to the lib/ and src/ directories using recursive make.

Q5. What is the purpose of the ar command? Why is ranlib often used immediately after it?

The ar command is used to create static library files (.a) by combining multiple object files (.o) into a single archive. The ranlib command then generates an index or symbol table for the archive, allowing the linker to quickly find and access symbols within it. On many modern systems, using ar rcs automatically creates this index, but running ranlib separately ensures broader compatibility across different environments.

Q6. When you run nm on your client_static executable, are the symbols for functions like mystrlen present? What does this tell you about how static linking works?

Running nm on a statically linked executable usually displays the function symbols because the object code from the static library is directly included in the final binary during the linking process. This demonstrates that static linking embeds all necessary code into the executable at build time, unlike dynamic linking, where the symbols are resolved later at runtime through shared libraries.

Q7. What is Position-Independent Code (-fPIC) and why is it a fundamental requirement for creating shared libraries?

Position-Independent Code (PIC) is machine code that can run correctly regardless of where it is loaded in memory. Since shared libraries (.so files) can be mapped to different memory addresses by different processes, they must be compiled with the -fPIC flag, allowing the dynamic loader to relocate them as needed without requiring modifications to the code.

Q8. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?

The client_static executable is larger because it contains all the utility function object code directly embedded within the binary. In contrast, client_dynamic is smaller since it only holds references to the functions in libmyutils.so, with the actual code remaining in the shared library and being loaded into memory at runtime.

Q9. What is the LD_LIBRARY_PATH environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?

The LD_LIBRARY_PATH variable tells the dynamic loader where to look for .so files at runtime. By default, the loader searches only standard system directories like /lib and /usr/lib. Since our libmyutils.so is stored in a custom ./lib directory, we need to update LD_LIBRARY_PATH to include it. This process highlights the role of the dynamic loader, which is to locate, load, and map the required shared libraries before the program starts executing.


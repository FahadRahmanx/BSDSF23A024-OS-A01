Q1. Explain the linking rule in this part's Makefile: $(TARGET): $(OBJECTS). How does it differ from a Makefile rule that links against a library?

The rule $(TARGET): $(OBJECTS) tells make that the final executable relies on all the listed object files. If any of these object files are updated, the target will be rebuilt. Here, the linker takes all the .o files and combines them into a single executable binary.
When linking against a library, instead of listing multiple .o files directly, the rule uses an option like -lmylib . In this case, the linker retrieves the necessary symbols from the library to create the final executable.

Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?

A Git tag is a pointer to a specific commit, commonly used to mark important milestones like releases or stable versions. It helps identify and return to a particular state of the code easily. There are two types of tags: lightweight tags, which are simple pointers to a commit without extra details, and annotated tags, which include metadata such as the author, date, and a message. Annotated tags are preferred for official releases as they provide more context and information about the version

Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?

Creating a Release on GitHub helps package and share a specific version of your project in a clear and organized way. It marks a stable point in the codebase, often linked to a Git tag, and provides users with details about updates or changes. Attaching binaries (like a compiled executable) makes it easy for others to use the program without having to build it from source, saving time and reducing setup complexity. This is especially useful for non-developers or end-users who just need the ready-to-use software



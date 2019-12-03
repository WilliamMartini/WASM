# Proposed repo structure for finalization and reporting

- toolchain-comparison
- deployment
- reporting
- README.md

## README

README contains a short description of what the project was about and how the repo
is structured.

## toolchain-comparison

This should contain the following subdirectories:
- wasmer
- lucet
- wasmtime
- benchmarking

Each of the directories - wasmer, lucet, wasmtime - should contain instructions on
how to build an application for the different WASM platforms and any scripts/tools
that you used.

The benchmarking directory should contain the results that you obtained for the
comparison and the conclusions of the analysis. This can be in a markdown file (as
I think you already have). Note that you may include the references to the
papers that we have circulated throughout this work perhaps with a small comment
on what those papers/blog posts etc address here if you like.

## deployment

This folder should contain information on how to deploy a wasm application to
different serverless platforms. It may contain the following
- aws
- bluemix

The details depend a little on the results of the meeting today.

## reporting

This should contain a final report of, say, 5 pages which collates the work of the
project - you can of course reuse the text you wrote in the other markdown files
in the repo.

This directory can also contain all the meeting files.

It can also include the interim presentation and the final presentation when done.

### Proposed structure of report

- Introduction
    - Serverless is increasingly important trend seeing significant traction
    - Still v much tied to specific technologies; cross platform or portable serverless applications not easy today
    - this project tries to address that somewhat

- Technology overview
    - Serverless technologies
    - WASM
    - Related work
        - include links to blog posts and papers that were shared throughout project

- Comparison of different WASM executable options
    - documents results of benchmarking; how experiments were conducted
    - comment on results of the benchmarking - which runtime is most suitable to support wasm serverless applications

- Deployment of WASM on serverless platforms
    - Deployment using javascript approach
    - Deployment using docker approaches
    - Comparison of performance of solution using JS and solution using docker
    - Comment on issues regarding integration
        - how are parameters passed to function
        - how can this be made portable/platform independent

- Conclusion
    - The project was a SUCCESS!
    - deploying the same wasm to different serverless platforms was possible
    - the issues around giving params to the serverless function is still open
    - using wasmer in docker is a nice way to achieve a good balance between performance and portability
        - depending on results of the experiments this week...



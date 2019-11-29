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
I think you already have). Note that you should include the references to the
papers that we have circulated throughout this work perhaps with a small comment
on what those papers/blog posts etc address.

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
-- Serverless is increasingly important trend seeing significant traction
-- Still v much tied to specific technologies; cross platform or portable serverless applications not easy today
-- this project tries to address that somewhat

- Technology overview
    - Serverless technologies
    - WASM

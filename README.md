# Using Web Assembly to make Serverless Applications more Portable  
This project is part of the course [Software Maintenance and Evolution](https://www.ifi.uzh.ch/en/seal/teaching/courses/sme.html).    
Supervisor: Dr. Sebastiano Panichella   
Advisor: Dr Seán Murphy

## Context 
Web Assembly (WASM) is a relatively new system for packaging software which can run in very diverse contexts; originally developed for a browser context - running in a classical Javascript V8 engine - there is increasing interest in running it WASM binaries in a server context. More specifically, running a V8 or other Javascript engine on a server to execute arbitrary server side code is the focus.

There are some reasons to believe that WASM is a good candidate for The Ultimate Portable Application Binary: many languages can compile down to a WASM binary, Javascript runtimes are mature, stable and well optimized and offer powerful interfaces and abstractions of key Operating System concepts.

In concert with WASM development, interest in serverless technology [7]  is increasing rapidly, providing an (arguably) new approach to software design. In essence, serverless computing is an event driven, stateless paradigm which supports loose coupling of platform services (eg database services, file storage services) delivering a new approaches to application design. At present, most serverless platforms execute some variant of docker containers, but there is interest in considering alternative runtimes for serverless: WASM is a candidate for consideration in this context and indeed Cloudflare is already offering it as one way of packaging applications for their platform [3]. 

## Goal/objective
The objective of this project is to understand how WASM can be used as a standalone binary format which can be executed in multiple cloud contexts in order to recommend how serverless platforms can best support WASM..

## Overview

## Source
[3] https://blog.cloudflare.com/webassembly-on-cloudflare-workers/   
[7] JONAS, Eric, SCHLEIER-SMITH, Johann, SREEKANTI, Vikram, et al. Cloud programming simplified: a berkeley view on serverless computing. arXiv preprint arXiv:1902.03383, 2019.

## Links
https://www.fortinet.com/blog/threat-research/webassembly-101-bringing-bytecode-to-the-web.html  
https://de.slideshare.net/gskachkov/webassembly-overview  
https://de.slideshare.net/BradBeiermann/webassembly-wasm-introduction-presentation
https://hacks.mozilla.org/2019/11/announcing-the-bytecode-alliance/

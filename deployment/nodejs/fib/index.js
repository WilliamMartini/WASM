'use strict';
const fs = require('fs');
const util = require('util')

const WASM_MODULE = 'fib.wasm'
let wasm_instance

async function load_wasm(wasm_module) {
  if (!wasm_instance) {
    const bytes = fs.readFileSync(wasm_module);
    const memory = new WebAssembly.Memory({initial: 1});
    const env = {
      __memory_base: 0, memory
    }

    const { instance, module } = await WebAssembly.instantiate(bytes, { env });
    wasm_instance = instance
  }

  return wasm_instance.exports.calculate
}

exports.main = async function ({ a = 1}) {
  const calculate = await load_wasm(WASM_MODULE)
  const fib = calculate(a)
  return { fib }
}
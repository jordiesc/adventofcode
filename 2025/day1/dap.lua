local ok, dap = pcall(require, 'dap')
if not ok then
    return
end

--
-- See
-- https://sourceware.org/gdb/current/onlinedocs/gdb.html/Interpreters.html
-- https://sourceware.org/gdb/current/onlinedocs/gdb.html/Debugger-Adapter-Protocol.html
dap.adapters.gdb = {
    id = 'gdb',
    type = 'executable',
    command = 'gdb',
    args = { '--quiet', '--interpreter=dap' },
}

dap.configurations.cpp = { 
    {
        name = 'Run executable (GDB)',
        type = 'gdb',
        request = 'launch',
        program = "${workspaceFolder}/main",
console = "integratedTerminal",  
       cwd = '${workspaceFolder}',
    stopAtEntry = true,
    -- Setup commands can be useful for GDB pretty-printing
    setupCommands = {
      { text = '-enable-pretty-printing', description = 'enable pretty printing'   }}
},

}

Comando: ls -la > output.txt < input.txt

Se representa como:
┌─────────────────────────────────┐
│ t_command                       │
│ ├─ cmd_args: ["ls", "-la"]      │
│ ├─ cmd_argc: 2                  │
│ ├─ type: CMD_SIMPLE             │
│ ├─ redirs: ┌─────────────────┐  │
│ │          │ t_redir         │  │
│ │          │ ├─ type: REDIR_OUT│ │
│ │          │ ├─ outfile: "output.txt"│
│ │          │ └─ next: ───────┐  │  │
│ │          └─────────────────┘  │  │
│ │                   ┌──────────────┘  │
│ │                   ▼                 │
│ │          ┌─────────────────┐        │
│ │          │ t_redir         │        │
│ │          │ ├─ type: REDIR_IN│       │
│ │          │ ├─ infile: "input.txt"   │
│ │          │ └─ next: NULL    │       │
│ │          └─────────────────┘        │
│ └─ next: NULL                        │
└─────────────────────────────────────┘
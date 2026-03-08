## 1. Issue Templates

Create a `.github/ISSUE_TEMPLATE/` directory with these templates:

### **Bug Report** (`bug_report.md`)
```markdown
---
name: Bug Report
about: Create a report to help us improve the IRC server
title: "[BUG] "
labels: bug
assignees: ''

---

## Bug Description
A clear and concise description of what the bug is.

## To Reproduce
Steps to reproduce the behavior:
1. Start server with `./ircserv 6667 pass`
2. Connect client using `nc 127.0.0.1 6667`
3. Send command `...`
4. See error

## Expected Behavior
A clear description of what you expected to happen.

## Actual Behavior
What actually happened (include error messages, server output).

## Environment
- OS: [e.g., Ubuntu 22.04, macOS 14]
- Compiler: [e.g., g++ 11.4.0, clang++ 15]
- Client used for testing: [e.g., nc, irssi, HexChat]
- Branch: [e.g., main, develop]

## Additional Context
Add any other context about the problem here.
- Does it happen consistently or intermittently?
- Does it affect multiple clients or just one?
- Any relevant logs or screenshots
```

### **Feature Request** (`feature_request.md`)
```markdown
---
name: Feature Request
about: Suggest a new feature or enhancement for ft_irc
title: "[FEAT] "
labels: enhancement
assignees: ''

---

## Feature Description
A clear and concise description of what you want to happen.

## Is this a mandatory or bonus feature?
- [ ] Mandatory Part (authentication, channels, operators, etc.)
- [ ] Bonus Part (file transfer, bot, etc.)
- [ ] Code Quality/Refactoring
- [ ] Documentation

## Technical Details
- Which IRC commands are involved? (e.g., NICK, JOIN, MODE, KICK)
- Does this require new data structures?
- Are there edge cases to consider?

## Acceptance Criteria
- [ ] Criterion 1
- [ ] Criterion 2
- [ ] Criterion 3

## Additional Context
Add any other context, RFC references, or screenshots about the feature request here.
```

### **Learning Task** (`learning_task.md`)
```markdown
---
name: Learning Task
about: Track learning progress for ft_irc concepts
title: "[LEARN] "
labels: learning
assignees: ''

---

## Topic
What needs to be learned? (e.g., "Socket programming in C++", "IRC protocol RFC 1459")

## Resources
- [ ] Official documentation: 
- [ ] Tutorial: 
- [ ] Video: 
- [ ] 42 Subject PDF section: 

## Learning Goals
- [ ] Goal 1
- [ ] Goal 2
- [ ] Goal 3

## Proof of Understanding
Before closing this issue, demonstrate understanding by:
- [ ] Summary notes in team wiki/notes
- [ ] Small test program or code snippet
- [ ] Presentation to partner (5-10 min)
- [ ] Applied knowledge in actual codebase

## Time Estimate
How long do you expect this to take? (e.g., 2-3 hours)

## Related Implementation Issue
Link to the actual coding task that depends on this knowledge.
```

### **Code Review** (`code_review.md`)
```markdown
---
name: Code Review Request
about: Request a review of specific code before merging
title: "[REVIEW] "
labels: review
assignees: ''

---

## Code Location
- Branch: 
- File(s): 
- Lines: 
- Commit/PR: 

## What to Review
Specific aspects you want feedback on:
- [ ] Logic correctness
- [ ] C++98 compliance
- [ ] Memory management (no leaks)
- [ ] Error handling
- [ ] Code style/conventions
- [ ] Performance

## Context
Why was this approach chosen? What alternatives were considered?

## Specific Questions
1. 
2. 
3. 

## Checklist before requesting review
- [ ] Code compiles with `-Wall -Wextra -Werror -std=c++98`
- [ ] Tested with reference client
- [ ] No memory leaks (checked with valgrind on Linux)
- [ ] Self-reviewed first
```

---

## 2. Git Workflow (Simple & Professional)

Create a `GIT_WORKFLOW.md` file in your repo root:

```markdown
# ft_irc Git Workflow

## Branch Strategy: GitHub Flow (Simplified)

```
main (production-ready)
  │
  ├── feature/nick-command      ← Your feature branches
  ├── feature/channel-join
  ├── bugfix/poll-handling
  └── learn/socket-basics       ← Learning branches allowed
```

### Branch Naming Convention
| Prefix | Use Case | Example |
|--------|----------|---------|
| `feature/` | New functionality | `feature/mode-command` |
| `bugfix/` | Bug fixes | `bugfix/segfault-on-disconnect` |
| `refactor/` | Code restructuring | `refactor/server-class` |
| `docs/` | Documentation only | `docs/readme-update` |
| `learn/` | Learning/experiments | `learn/poll-vs-select` |

### Workflow Steps

#### 1. Start New Work
```bash
# Always start from latest main
git checkout main
git pull origin main

# Create descriptive branch
git checkout -b feature/command-join
```

#### 2. Commit Rules
- **Frequency**: Commit early, commit often
- **Message format**: `type: imperative description (max 50 chars)`

| Type | Use When | Example |
|------|----------|---------|
| `feat:` | New feature | `feat: implement JOIN command` |
| `fix:` | Bug fix | `fix: handle empty password` |
| `refactor:` | Restructure code | `refactor: extract Client class` |
| `docs:` | Documentation | `docs: add setup instructions` |
| `test:` | Tests | `test: add channel unit tests` |
| `chore:` | Maintenance | `chore: update Makefile` |

**Bad**: `fixed stuff` / `WIP` / `asdf`  
**Good**: `feat: add KICK command with operator validation`

#### 3. Before Pushing
```bash
# 1. Check C++98 compliance
make re && make clean && make

# 2. Test your changes
./ircserv 6667 testpass &
# Test with your reference client

# 3. Update from main (handle conflicts locally)
git checkout main && git pull
git checkout your-branch
git rebase main  # or git merge main

# 4. Push
git push origin your-branch
```

#### 4. Pull Request Process
**PR Title Format**: `[TYPE] Brief description`  
Example: `[FEAT] Implement MODE command with +t +k flags`

**PR Description Template**:
```markdown
## What
Brief description of changes

## How
Technical approach explanation

## Testing
- [ ] Compiled with `-Wall -Wextra -Werror`
- [ ] Tested with nc
- [ ] Tested with [reference client]
- [ ] Memory check: valgrind --leak-check=full

## Related Issues
Closes #3
```

**Review Requirements**:
- Minimum 1 approval from partner
- All comments resolved
- CI passes (if you set up GitHub Actions)

#### 5. After Merge
```bash
git checkout main
git pull origin main
git branch -d your-old-branch  # Delete local
git push origin --delete your-old-branch  # Delete remote
```

### Forbidden ❌
- Never push directly to `main`
- Never commit compiled binaries or `.o` files
- Never commit with messages like "fix", "update", "WIP"
- Never merge your own PR without review

### Emergency Hotfix Protocol
If main is broken:
1. Create `hotfix/critical-description` from main
2. Fix with minimal changes
3. Fast-track review (both partners approve quickly)
4. Merge immediately
5. Everyone `git pull` main immediately
```

---

## 3. Learning Roadmap & Issues

Create GitHub Issues for each learning milestone. Here's the structured roadmap:

### **Phase 1: Networking Fundamentals** (Week 1)

| Issue # | Title | Assignee | Est. Time |
|---------|-------|----------|-----------|
| #1 | [LEARN] Socket API basics (socket, bind, listen, accept) | Both | 3h |
| #2 | [LEARN] Non-blocking I/O and poll()/select() | Both | 4h |
| #3 | [LEARN] TCP/IP fundamentals for IRC | Both | 2h |

**Issue #1 Details:**
```markdown
## Topic: Socket Programming in C++

### Resources
- [ ] Beej's Guide to Network Programming (Chapters 1-5): https://beej.us/guide/bgnet/
- [ ] 42 ft_irc subject (General Rules + Mandatory Part)
- [ ] `man socket`, `man bind`, `man listen`, `man accept`

### Practical Exercise
Create `test_socket.cpp` that:
1. Creates a TCP socket
2. Binds to port 8080
3. Listens for connections
4. Accepts one connection and echoes back received data
5. Handles multiple connections using `poll()`

### Deliverables
- [ ] Working test program committed to `learn/sockets` branch
- [ ] Notes on: difference between blocking/non-blocking, file descriptors
- [ ] 10-min explanation to partner of how `poll()` works
```

### **Phase 2: IRC Protocol** (Week 1-2)

| Issue # | Title | Assignee | Est. Time |
|---------|-------|----------|-----------|
| #4 | [LEARN] RFC 1459 - IRC Protocol overview | Partner A | 3h |
| #5 | [LEARN] IRC message format and parsing | Partner B | 3h |
| #6 | [LEARN] IRC registration flow (NICK, USER, PASS) | Both | 4h |

**Issue #4 Details:**
```markdown
## Topic: RFC 1459 - Internet Relay Chat Protocol

### Resources
- [ ] RFC 1459 (sections 1-4): https://datatracker.ietf.org/doc/html/rfc1459
- [ ] Modern IRC docs: https://modern.ircdocs.horse/

### Key Concepts to Understand
- [ ] Message format: `:[prefix] <command> <params> :trailing\r\n`
- [ ] Numeric replies (001-999)
- [ ] Channel prefixes (#) and user prefixes (@, +)
- [ ] Client-server vs server-server communication (we only do client-server)

### Practical Exercise
Connect to a real IRC network (libera.chat) using:
```bash
nc irc.libera.chat 6667
```
And manually send:
```
NICK testuser123
USER testuser 0 * :Real Name
JOIN #test-channel
PRIVMSG #test-channel :Hello World
```

### Deliverables
- [ ] Screenshot or log of successful manual IRC session
- [ ] Summary document: "IRC Protocol Cheat Sheet" in repo wiki
- [ ] List of commands we MUST implement vs NICE to have
```

### **Phase 3: Implementation Architecture** (Week 2)

| Issue # | Title | Assignee | Est. Time |
|---------|-------|----------|-----------|
| #7 | [LEARN] C++98 classes design for IRC server | Both | 3h |
| #8 | [LEARN] File descriptor management patterns | Partner A | 2h |
| #9 | [LEARN] Signal handling in servers (SIGINT, SIGPIPE) | Partner B | 2h |

### **Phase 4: Mandatory Features Deep Dive** (Week 2-3)

| Issue # | Title | Assignee | Est. Time |
|---------|-------|----------|-----------|
| #10 | [LEARN] Authentication and registration flow | Partner A | 3h |
| #11 | [LEARN] Channel management (JOIN, PART, TOPIC) | Partner B | 4h |
| #12 | [LEARN] Operator privileges and MODE command | Partner A | 4h |
| #13 | [LEARN] Private messages (PRIVMSG, NOTICE) | Partner B | 2h |

### **Phase 5: Testing & Debugging** (Ongoing)

| Issue # | Title | Assignee | Est. Time |
|---------|-------|----------|-----------|
| #14 | [LEARN] Testing IRC server with nc and reference clients | Both | 2h |
| #15 | [LEARN] Memory leak detection with valgrind | Both | 2h |
| #16 | [LEARN] Debugging network applications (wireshark, strace) | Both | 3h |

---

## Quick Setup Commands

Run these to initialize your repo structure:

```bash
# Create directory structure
mkdir -p .github/ISSUE_TEMPLATE
mkdir -p docs
mkdir -p src
mkdir -p includes

# Create files
touch .github/ISSUE_TEMPLATE/bug_report.md
touch .github/ISSUE_TEMPLATE/feature_request.md
touch .github/ISSUE_TEMPLATE/learning_task.md
touch .github/ISSUE_TEMPLATE/code_review.md
touch GIT_WORKFLOW.md
touch README.md
touch Makefile

# Add to git
git add .
git commit -m "chore: initialize project structure with templates and workflow"
git push origin main
```

## GitHub Project Board Setup

1. Go to **Projects** tab → **New Project** → **Board**
2. Create columns:
   - **Backlog** (all new issues)
   - **Learning** (active learning tasks)
   - **To Do** (ready to implement)
   - **In Progress** (max 2 items!)
   - **Review** (PRs waiting)
   - **Done**

3. Add these custom fields:
   - **Priority**: Urgent / High / Medium / Low
   - **Type**: Feature / Bug / Learning / Refactor
   - **Estimate**: Number (hours)

This setup keeps you professional, consistent, and ensures both partners learn effectively while building the server. Good luck with ft_irc!
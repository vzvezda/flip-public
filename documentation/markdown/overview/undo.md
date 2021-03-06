<p><sup><a href="model.md">previous</a> | <a href="thread.md">next</a></sup></p>

<h1>Undo/Redo System</h1>

<p>With its program/transaction system, handling undo/redo or history with Flip is simple as giving a name (or any metadata) to a transaction.</p>

<p><center><img src="undo.png" /></center></p>

<p>Flip will then replay the transaction in reverse (undo) or as originally intended (redo). In the case where a transaction would fail structural validation, Flip will modify the transaction so that it can be replayed.</p>

<p>Therefore, clients do not need to code "action classes" (or anything similar) for every single action applied to the model. The only thing needed is to describe what metadata the client wants to attach to a transaction. Usually this is just a string describing the action.</p>

<p>When the client calls <code>undo ()</code> or <code>redo ()</code> on the document history, the exact same code path is used. The transaction or its inverse is sent to the server, and the observers are called to allow further examination of the model change.</p>

<p><sup><a href="model.md">previous</a> | <a href="thread.md">next</a></sup></p>


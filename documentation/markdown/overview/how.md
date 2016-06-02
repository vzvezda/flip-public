<p><sup><a href="about.md">previous</a> | <a href="model.md">next</a></sup></p>

<h1>How it Works</h1>

<h2 id="build">Building a Transaction</h2>

<p>The client of the Flip framework will directly modify the model by either :</p>

<ul>
<li>modifying a value by assigning it</li>
<li>insert, move or erase an object in a container</li>
</ul>

<p><center><img src="how.asm.png" /></center></p>

<p>Assigning a value is done with the <code>operator =</code> and modifying a container follows the same kind of prototypes as found in the standard library  (<code>insert</code>, <code>erase</code>, etc.) which makes the use of Flip quite natural.</p>

<p>In the background, each operation is translated in real-time in a simple assembler. When the client of the library manipulate the model, Flip will apply and record all the changes made to the model and will make a program in that assembler.</p>

<p>This program is also a transaction in the sense that applying a transaction will transform the model from a valid state to another valid state.</p>

<h2 id="validation">Validation</h2>

<p>This transaction is then sent to the server. The server will interpret the assembler to make the changes to its own model. The transaction is then validated by the server. Validation ensure that the model is consistent and is done in two steps :</p>

<ol>
<li>structural validation</li>
<li>logical validation</li>
</ol>

<p><center><img src="how.valid.png" /></center></p>

<h3 id="validation-structural">Structural Validation</h3>

<p>Structure validation is handled by Flip. It ensures that an object can be either modified, inserted or erased. For example structure validation may fail if two clients tries to erase an object concurrently. In that case the second transaction is rejected. Another example would be to reject a transaction where a client tries to change a value of an object that was erased concurrently.</p>

<h3 id="validation-logical">Logical Validation</h3>

<p>Logical validation is handled by the client. It ensures that the model is consistent relative to the meaning that the the client assign virtually to the model structures. For example the client might want to ensure that for a container which the client assign the meaning of length, that its element which could be defined with a position and length do not go passed the length of container, that is to ensure :</p>

```c++
element._position + element._length <= container._length
0 <= element._position
0 <= element._length
0 <= container._length
```

<p><center><img src="how.valid.logic.png" /></center></p>

<p>This kind of validation is possible in Flip, as it is dynamic (it is a program that the client writes) rather than static or semi-static (like a XML/DTD)</p>

<p>The architecture of Flip allows to write validators very quickly, in a tree parsing fashion.</p>

<h2 id="approval">Validation Approval</h2>

<p><center><img src="how.valid.ok.png" /></center></p>

<p>When the two staged validation is good, the transaction is considered as accepted. The server will broadcast the transaction for execution to the other clients, and will send an approval to the original client.</p>

<h2 id="refusal">Validation Refusal</h2>

<p><center><img src="how.valid.fail.png" /></center></p>

<p>When the two stages validation is wrong, the transaction is considered as refused. The server will send a disapproval to the original client which will rollback the transaction.</p>

<p>When another client execute the transaction, it will make all the changes needed by that transaction. When it is done and succesfully applied, the client observers are called.</p>

<p><sup><a href="about.md">previous</a> | <a href="model.md">next</a></sup></p>

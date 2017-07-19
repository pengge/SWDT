# REF [site] >> https://www.tensorflow.org/get_started/get_started

import tensorflow as tf
import numpy as np

#%%-------------------------------------------------------------------

sess = tf.Session()

#A = tf.constant([[[1, 1, 1], [2, 2, 2]], [[3, 3, 3], [4, 4, 4]]])
#A = tf.constant([[[1, 11, 21], [2, 12, 22]], [[3, 13, 23], [4, 14, 24]]])
A = tf.constant([[[1, -3, -12], [0, -7, 5]], [[-11, 19, 13], [37, 5, -19]]])

e1 = A[0, 1, :]
e2 = A[1, :, :]
e3 = A[0:-1, :, 1:-1]

type(A)
type(e1)
print(sess.run([e1, e2, e3]))

size = tf.size(A)
print(sess.run(size))
shape = tf.shape(A)
print(sess.run(shape))

M0 = tf.argmax(A, axis=0)
M1 = tf.argmax(A, axis=1)
M2 = tf.argmax(A, axis=2)
M_1 = tf.argmax(A, axis=-1)
sess.run([M0, M1, M2, M_1])

#%%-------------------------------------------------------------------

node1 = tf.constant(3.0, tf.float32)
node2 = tf.constant(4.0) # also tf.float32 implicitly
print(node1, node2)

sess = tf.Session()
print(sess.run([node1, node2]))

node3 = tf.add(node1, node2)
print("node3: ", node3)
print("sess.run(node3): ",sess.run(node3))

#%%-------------------------------------------------------------------

a = tf.placeholder(tf.float32)
b = tf.placeholder(tf.float32)
adder_node = a + b  # + provides a shortcut for tf.add(a, b)

print(sess.run(adder_node, {a: 3, b: 4.5}))
print(sess.run(adder_node, {a: [1, 3], b: [2, 4]}))

add_and_triple = adder_node * 3.
print(sess.run(add_and_triple, {a: 3, b: 4.5}))

#%%-------------------------------------------------------------------

W = tf.Variable([.3], tf.float32)
b = tf.Variable([-.3], tf.float32)
x = tf.placeholder(tf.float32)
linear_model = W * x + b

init = tf.global_variables_initializer()
sess.run(init)

print(sess.run(linear_model, {x:[1,2,3,4]}))

y = tf.placeholder(tf.float32)
squared_deltas = tf.square(linear_model - y)
loss = tf.reduce_sum(squared_deltas)
print(sess.run(loss, {x:[1,2,3,4], y:[0,-1,-2,-3]}))

#%%-------------------------------------------------------------------

fixW = tf.assign(W, [-1.])
fixb = tf.assign(b, [1.])
sess.run([fixW, fixb])
print(sess.run(loss, {x:[1,2,3,4], y:[0,-1,-2,-3]}))

#%%-------------------------------------------------------------------

optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

sess.run(init) # Reset values to incorrect defaults.
for i in range(1000):
  sess.run(train, {x:[1,2,3,4], y:[0,-1,-2,-3]})

print(sess.run([W, b]))

#%%-------------------------------------------------------------------

# Model parameters.
W = tf.Variable([.3], tf.float32)
b = tf.Variable([-.3], tf.float32)

# Model input and output.
x = tf.placeholder(tf.float32)
linear_model = W * x + b
y = tf.placeholder(tf.float32)

# Loss.
loss = tf.reduce_sum(tf.square(linear_model - y)) # Sum of the squares.

# Optimizer.
optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

# Training data.
x_train = [1,2,3,4]
y_train = [0,-1,-2,-3]

# Train loop.
init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)  # Reset values to wrong.
for i in range(1000):
  sess.run(train, {x: x_train, y: y_train})

# Evaluate training accuracy.
curr_W, curr_b, curr_loss = sess.run([W, b, loss], {x: x_train, y: y_train})
print("W: %s b: %s loss: %s" % (curr_W, curr_b, curr_loss))

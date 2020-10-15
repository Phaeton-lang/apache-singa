<!--
    Licensed to the Apache Software Foundation (ASF) under one
    or more contributor license agreements.  See the NOTICE file
    distributed with this work for additional information
    regarding copyright ownership.  The ASF licenses this file
    to you under the Apache License, Version 2.0 (the
    "License"); you may not use this file except in compliance
    with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing,
    software distributed under the License is distributed on an
    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
    KIND, either express or implied.  See the License for the
    specific language governing permissions and limitations
    under the License.
-->

# How to format code

This guide is for singa devoloper who wants to visualize the memory footprint of singa.

## Examples

1. Plot the memory footprint, usage:

```
$ python3 plot-memory-footprint.py
```

2. Plot the distribution of each memory block, including start memory address, malloc size and lifetime.

```
$ python3 plot-block-distribution.py
```

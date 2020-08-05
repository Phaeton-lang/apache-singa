# Errors

### 1. proto 初始化错误

```
(base) ljs@180-ubuntu:/home/extend/lijiansong/work-space$ python3
Python 3.5.2 (default, Apr 16 2020, 17:47:17)
[GCC 5.4.0 20160609] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import sys
>>> sys.path.append('./anaconda2/envs/intel-caffe/lib/python3.6/site-packages')
>>> from singa import tensor
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "./anaconda2/envs/intel-caffe/lib/python3.6/site-packages/singa/tensor.py", line 63, in <module>
    from .proto import core_pb2
  File "./anaconda2/envs/intel-caffe/lib/python3.6/site-packages/singa/proto/core_pb2.py", line 22, in <module>
    serialized_pb=b'\n\ncore.proto\x12\x05singa\"p\n\x0bMemPoolConf\x12\x13\n\x04type\x18\x01 \x01(\t:\x05\x63nmem\x12\x16\n\tinit_size\x18\x02 \x01(\r
:\x03\x32\x35\x36\x12\x13\n\x08max_size\x18\x03 \x01(\r:\x01\x30\x12\x0f\n\x04\x66lag\x18\x0b \x01(\r:\x01\x30\x12\x0e\n\x06\x64\x65vice\x18\x0c \x03(\
r\"\xab\x01\n\x0bTensorProto\x12\r\n\x05shape\x18\x01 \x03(\r\x12\"\n\tdata_type\x18\x02 \x01(\x0e\x32\x0f.singa.DataType\x12\x0e\n\x06stride\x18\x03 \
x03(\x05\x12\x16\n\nfloat_data\x18\x04 \x03(\x02\x42\x02\x10\x01\x12\x17\n\x0b\x64ouble_data\x18\x05 \x03(\x01\x42\x02\x10\x01\x12\x14\n\x08int_data\x1
8\x06 \x03(\x05\x42\x02\x10\x01\x12\x12\n\nbytes_data\x18\x07 \x03(\x0c*f\n\x08\x44\x61taType\x12\x0c\n\x08kFloat32\x10\x00\x12\x0c\n\x08kFloat16\x10\x
01\x12\x08\n\x04kInt\x10\x02\x12\t\n\x05kChar\x10\x03\x12\x0b\n\x07kDouble\x10\x04\x12\n\n\x06kUChar\x10\x05\x12\x10\n\x0ckNumDataType\x10\x06*@\n\x08L
angType\x12\x08\n\x04kCpp\x10\x00\x12\t\n\x05kCuda\x10\x01\x12\x0b\n\x07kOpencl\x10\x02\x12\x12\n\x0ekNumDeviceType\x10\x04*n\n\rCopyDirection\x12\x0f\
n\x0bkHostToHost\x10\x00\x12\x11\n\rkHostToDevice\x10\x01\x12\x11\n\rkDeviceToHost\x10\x02\x12\x13\n\x0fkDeviceToDevice\x10\x03\x12\x11\n\rkNumDirectio
n\x10\x04\x42\x18\n\x16org.apache.singa.proto'
TypeError: __init__() got an unexpected keyword argument 'serialized_options'
```

protoc 版本不匹配导致该错误，此时可以通过如下方式解决：<https://blog.csdn.net/qq_41185868/article/details/82890135>

```
$ pip3 install -U protobuf
```


### 2、singa python import

由于从源码编译的singa是安装在虚拟环境`./anaconda2/envs/intel-caffe/lib/python3.6/site-packages/singa`中，所以需要：

```
import sys
sys.path.append('/home/extend/lijiansong/work-space/anaconda2/envs/intel-caffe/lib/python3.6/site-packages')
from singa import tensor
```

示例可以参考：<http://singa.apache.org/docs/examples/>中的Colab示例，如：<https://colab.research.google.com/drive/1fbGUs1AsoX6bU5F745RwQpohP4bHTktq#scrollTo=xM7G0MjzKSVj>



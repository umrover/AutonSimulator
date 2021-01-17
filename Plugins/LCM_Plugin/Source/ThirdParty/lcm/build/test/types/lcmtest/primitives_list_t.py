"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

import lcmtest.primitives_t

class primitives_list_t(object):
    __slots__ = ["num_items", "items"]

    __typenames__ = ["int32_t", "lcmtest.primitives_t"]

    __dimensions__ = [None, ["num_items"]]

    def __init__(self):
        self.num_items = 0
        self.items = []

    def encode(self):
        buf = BytesIO()
        buf.write(primitives_list_t._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">i", self.num_items))
        for i0 in range(self.num_items):
            assert self.items[i0]._get_packed_fingerprint() == lcmtest.primitives_t._get_packed_fingerprint()
            self.items[i0]._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != primitives_list_t._get_packed_fingerprint():
            raise ValueError("Decode error")
        return primitives_list_t._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = primitives_list_t()
        self.num_items = struct.unpack(">i", buf.read(4))[0]
        self.items = []
        for i0 in range(self.num_items):
            self.items.append(lcmtest.primitives_t._decode_one(buf))
        return self
    _decode_one = staticmethod(_decode_one)

    def _get_hash_recursive(parents):
        if primitives_list_t in parents: return 0
        newparents = parents + [primitives_list_t]
        tmphash = (0xaedf3d0724cd948b+ lcmtest.primitives_t._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if primitives_list_t._packed_fingerprint is None:
            primitives_list_t._packed_fingerprint = struct.pack(">Q", primitives_list_t._get_hash_recursive([]))
        return primitives_list_t._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)


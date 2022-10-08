
import zlib,base64
f1=open('filename.pdf','r')
text = f1.read()
f1.close()
code= base64.b64encode(zlib.compress(text.encode('utf-8'),9))
code = code.decode('utf-8')
f=open('filename','w')
f.write(code)
f.close()

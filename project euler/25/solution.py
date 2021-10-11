n = 10**999
fn, fp = 1, 0
idx = 1

while fn < n:
    idx += 1
    fn, fp = fn + fp, fn

print(idx, len(str(fn)))
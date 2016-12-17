import sys
import os
import socket

import select

"""
Rewriting https://gist.github.com/kazuho/10436253 in Python out of curiosity
"""

if __name__ == '__main__':
    if len(sys.argv) < 1 or sys.argv[1] not in ['accept', 'select-accept']:
        print('Usage: {} <accept|select-accept>'.format(sys.argv[0]))
        exit(1)
    mode = sys.argv[1]

    listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    listener.bind(('', 12345))

    if mode == 'select-accept':
        # FIXME: How do we test if it succeeded?
        listener.setblocking(1)
        # or die "failed to set listening socket to non-blocking mode:$!";

    pid = os.fork()
    # die "fork failed:$!"
    #     unless defined $pid;

    while True:
        if mode == 'select-accept':
            rfds = bytearray(255)
            rfds[listener.fileno()] = 1
            if select.select([listener.fileno()], [], [])[0]:
                break
        conn = listener.accept()
        if conn:
            print('Connected')
            conn.close()
        else:
            print('Accept failed')  # errno?

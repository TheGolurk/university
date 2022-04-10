package com.upemor;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.OutputStream;

public class append extends ObjectOutputStream {
    public append(OutputStream out) throws IOException {
        super(out);
    }
    @Override
    protected void writeStreamHeader() throws IOException {
    }
}

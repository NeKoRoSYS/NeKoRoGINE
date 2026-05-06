#pragma once
#include <vector>

class Signature {
private:
    std::vector<bool> bits;

public:
    void set(size_t pos, bool value = true) {
        if (pos >= bits.size()) {
            bits.resize(pos + 1, false);
        }
        bits[pos] = value;
    }

    void reset(size_t pos) {
        if (pos < bits.size()) {
            bits[pos] = false;
        }
    }

    bool test(size_t pos) const {
        return pos < bits.size() ? bits[pos] : false;
    }

    bool matches(const Signature& systemSignature) const {
        for (size_t i = 0; i < systemSignature.bits.size(); ++i) {
            if (systemSignature.bits[i] && (i >= bits.size() || !bits[i])) {
                return false;
            }
        }
        return true;
    }
};
const test = require("tape");
const asfw = require("..");

test("invalid PID behavior", function (t) {
    if (process.platform === "win32") {
        let threw = false;
        try {
            t.equal(asfw.AllowSetForegroundWindow(), 0)
        } catch (e) {
            threw = true;
        }
        t.equal(threw, true, "should throw");
    } else {
        t.equal(asfw.AllowSetForegroundWindow(0), 0)
    }
    t.end();
});

test("throws when missing argument", function (t) {
    let threw = false;
    try {
        t.equal(asfw.AllowSetForegroundWindow(), 0)
    } catch (e) {
        threw = true;
    }
    t.equal(threw, true, "should throw")
    t.end();
});

test("throws when argument is not a number", function (t) {
    let threw = false;
    try {
        t.equal(asfw.AllowSetForegroundWindow("whoops"), 0)
    } catch (e) {
        threw = true;
    }
    t.equal(threw, true, "should throw")
    t.end();
});

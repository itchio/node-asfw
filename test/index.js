const test = require("tape");
const asfw = require("..");

if (process.platform == "win32") {
    test("throws when missing argument", function (t) {
        let threw = false;
        try {
            t.equal(asfw.SetForegroundWindow(), 0)
        } catch (e) {
            threw = true;
        }
        t.equal(threw, true, "should throw")
        t.end();
    });

    test("throws when argument is not a number", function (t) {
        let threw = false;
        try {
            t.equal(asfw.SetForegroundWindow("whoops"), 0)
        } catch (e) {
            threw = true;
        }
        t.equal(threw, true, "should throw")
        t.end();
    });

    test("throws when argument is an invalid window handle", function (t) {
        let threw = false;
        try {
            t.equal(asfw.SetForegroundWindow(0), 0)
        } catch (e) {
            threw = true;
        }
        t.equal(threw, true, "should throw")
        t.end();
    })
} else {
    test("throws because it's not implemented", function (t) {
        let threw = false;
        try {
            t.equal(asfw.SetForegroundWindow(), 0)
        } catch (e) {
            threw = true;
        }
        t.equal(threw, true, "should throw")
        t.end();
    });
}
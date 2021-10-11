function palindrome(s) {
    for (let i = 0; i < s.length; i++) {
        if (s[i] != s[s.length-1-i]) return false;
    }
    return true;
}

let total = 0n;
for (let i = 0n; i < 1000000n; i++) {
    if (palindrome(i.toString(2)) && palindrome(i.toString())) {
        total += i;
    }
}
console.log(total);
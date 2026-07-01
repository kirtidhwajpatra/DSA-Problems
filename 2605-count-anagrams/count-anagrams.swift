class Solution {
    let MOD = 1_000_000_007

    func countAnagrams(_ s: String) -> Int {
        let chars = Array(s)
        let n = chars.count

        // Precompute factorials
        var fact = Array(repeating: 1 as Int64, count: n + 1)

        if n > 0 {
            for i in 1...n {
                fact[i] = (fact[i - 1] * Int64(i)) % Int64(MOD)
            }
        }

        let words = s.split(separator: " ")

        var answer: Int64 = 1

        for word in words {

            var freq = Array(repeating: 0, count: 26)

            for ch in word {
                let index = Int(ch.asciiValue! - Character("a").asciiValue!)
                freq[index] += 1
            }

            var ways = fact[word.count]

            

            for f in freq {
                if f > 1 {
                    ways = (ways * modInverse(fact[f])) % Int64(MOD)
                }


            }

               answer = (answer * ways) % Int64(MOD)
        }



        return Int(answer)
    }



    func modPow(_ base: Int64, _ exp: Int64) -> Int64 {
        var base = base
        var exp = exp
        var result: Int64 = 1

        while exp > 0 {
            if exp % 2 == 1 {
                result = (result * base) % Int64(MOD)
            }

            base = (base * base) % Int64(MOD)
            exp /= 2
        }

        return result
    }

    func modInverse(_ x: Int64) -> Int64 {
        return modPow(x, Int64(MOD - 2))
    }
}
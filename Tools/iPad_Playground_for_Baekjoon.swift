// Module for Algorithm --------------------------------
// input here
var _input : String = ""
var _arr : [String.SubSequence] {
    return _input.split(separator: "\n")
}
var _index : Int = 0

func readLine () -> String? {
    if _index >= _arr.count {
        return nil
    }
    let result = _arr[ _index ]
    _index += 1
    return String(result)
}

var _output : String = ""
func print (terminator: String = "\n") {
    _output += terminator
}
func print (_ value : Any, terminator: String = "\n") {
    _output +=  "\(value)" + terminator
}

func _main (){
// ---------------------------------------------------

// Main Code Start
var arr = readLine()!.split(separator: " ")
var n = Int(arr[0])!
var m = Int(arr[1])!
var v = Int(arr[2])! - 1

var connect : [[Bool]] = [[Bool]](repeating: [Bool](repeating: false, count: n), count: n)

for i in 0..<m {
    arr = readLine()!.split(separator: " ")
    let from = Int(arr[0])! - 1
    let to = Int(arr[1])! - 1
    connect[from][to] = true
    connect[to][from] = true
}

var opened : [Bool] = [Bool](repeating: false, count: n)
func dfs ( point : Int ) {
    opened[point] = true
    print(point+1, terminator: " ")
    for i in 0..<n {
        if i == point { continue }
        if connect[point][i] && !opened[i] { dfs(point: i) }
    }
}
dfs(point: v)
print()

opened = [Bool](repeating: false, count: n)
func bfs ( point : Int ) {
    opened[point] = true
    var queue : [Int] = [Int]()
    queue.append( point )
    while queue.count > 0 {
        var poped = queue[0]
        queue.remove(at: 0)
        print(poped + 1, terminator: " ")
        for i in 0..<n {
            if i == poped { continue }
            if connect[poped][i] && !opened[i] {
                opened[i] = true
                queue.append( i )
            }
        }
    }
}
bfs(point: v)

// Main Code End

// for Output ------------------------------------
}
_input = """
4 5 1
1 2
1 3
1 4
2 4
3 4
"""
_main()
_output





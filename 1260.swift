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

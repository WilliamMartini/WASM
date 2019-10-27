package prime

func Prime(number uint) bool {
    switch number {
    case 0:
        return false
    case 1:
        return false
    }
    var i uint = 2
    for i < number {
        if number%i == 0 {
            return false
        }
        i++
    }
    return true
}

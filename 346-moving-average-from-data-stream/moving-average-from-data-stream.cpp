// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
// For example,
//
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3
//
//


class MovingAverage {
private:
    queue<int> m_queue;
    int m_size;
    int m_count;
    int m_sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        m_size = size;
        m_count = 0;
        m_sum = 0;
    }
    
    double next(int val) {
        if (m_size == 0) {
            return 0;
        }
        
        m_count += 1;
        if (m_count > m_size) {
            m_sum -= m_queue.front();
            m_queue.pop();
            m_count -= 1;
        }
        
        m_queue.push(val);
        m_sum += val;
        
        return double(m_sum)/double(m_count);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

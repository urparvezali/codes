use std::mem;
use std::ptr;

struct MyVec<T> {
    ptr: *mut T,     // Raw pointer to the data
    capacity: usize, // The capacity of the vector (max elements it can hold)
    length: usize,   // The current number of elements in the vector
}

impl<T> MyVec<T> {
    // Create a new, empty vector with a starting capacity
    fn new() -> Self {
        MyVec {
            ptr: ptr::null_mut(), // Initially, no memory is allocated
            capacity: 0,          // Capacity starts at 0
            length: 0,            // No elements yet
        }
    }

    // Push a new element into the vector
    fn push(&mut self, elem: T) {
        if self.length == self.capacity {
            // If we're at capacity, we need to grow the vector
            self.grow();
        }

        unsafe {
            // Write the new element into the memory at ptr + length
            ptr::write(self.ptr.add(self.length), elem);
        }

        // Increment the length
        self.length += 1;
    }

    // Function to grow the vector's capacity
    fn grow(&mut self) {
        // If the capacity is 0, we start with an initial capacity of 1.
        // Otherwise, we double the capacity.
        let new_capacity = if self.capacity == 0 {
            1
        } else {
            self.capacity * 2
        };

        // Allocate new memory for the new capacity
        let new_ptr = unsafe {
            let layout = std::alloc::Layout::array::<T>(new_capacity).unwrap();
            let ptr = std::alloc::alloc(layout) as *mut T;

            if ptr.is_null() {
                std::alloc::handle_alloc_error(layout);
            }
            ptr
        };

        // If we already have elements, move them into the new memory
        if !self.ptr.is_null() {
            unsafe {
                ptr::copy_nonoverlapping(self.ptr, new_ptr, self.length);

                // Deallocate the old memory
                let old_layout = std::alloc::Layout::array::<T>(self.capacity).unwrap();
                std::alloc::dealloc(self.ptr as *mut u8, old_layout);
            }
        }

        // Update the pointer and capacity to the new values
        self.ptr = new_ptr;
        self.capacity = new_capacity;
    }

    // Pop an element off the vector
    fn pop(&mut self) -> Option<T> {
        if self.length == 0 {
            return None;
        }

        self.length -= 1;

        unsafe {
            // Read the element at the current length and return it
            Some(ptr::read(self.ptr.add(self.length)))
        }
    }

    // Access elements by index
    fn get(&self, index: usize) -> Option<&T> {
        if index >= self.length {
            None
        } else {
            unsafe { Some(&*self.ptr.add(index)) }
        }
    }

    // Get the current length of the vector
    fn len(&self) -> usize {
        self.length
    }
}

// Implement Drop to clean up memory when the vector is dropped
impl<T> Drop for MyVec<T> {
    fn drop(&mut self) {
        if !self.ptr.is_null() {
            unsafe {
                // Drop all elements in the vector
                for i in 0..self.length {
                    ptr::drop_in_place(self.ptr.add(i));
                }

                // Deallocate the memory
                let layout = std::alloc::Layout::array::<T>(self.capacity).unwrap();
                std::alloc::dealloc(self.ptr as *mut u8, layout);
            }
        }
    }
}

fn fixme() {
	todo!()
}

fn main() {
    let mut vec = MyVec::new();

    // Push elements to the custom vector
    vec.push(1);
    vec.push(2);
    vec.push(3);

    println!("Length of vec: {}", vec.len());

    // Access elements
    for i in 0..vec.len() {
        println!("Element at {}: {:?}", i, vec.get(i));
    }

    // Pop an element
    if let Some(value) = vec.pop() {
        println!("Popped value: {}", value);
    }

    println!("Length after pop: {}", vec.len());
}

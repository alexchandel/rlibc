#[macro_export]
macro_rules! cc {
    ($e:expr) => {
        $e as char_t
    }
}

#[macro_export]
macro_rules! cs {
    ($e:expr) => {
        (concat!($e, "\0")).repr().data as *const char_t
    }
}

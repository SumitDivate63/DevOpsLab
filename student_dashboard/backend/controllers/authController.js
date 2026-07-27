// Mock database array
const users = [];

exports.register = (req, res) => {
    const { fullname, email, password } = req.body;
    
    // Check if user already exists
    const userExists = users.find(u => u.email === email);
    if (userExists) {
        return res.status(400).json({ message: 'User already exists' });
    }
    
    // In a real app we would hash the password here
    const newUser = { id: Date.now(), fullname, email, password };
    users.push(newUser);
    
    res.status(201).json({ message: 'User registered successfully', userId: newUser.id });
};

exports.login = (req, res) => {
    const { email, password } = req.body;
    
    const user = users.find(u => u.email === email);
    
    // Direct password comparison for mock purposes
    if (!user || user.password !== password) {
        return res.status(401).json({ message: 'Invalid credentials' });
    }
    
    // In a real app we would return a JWT token here
    res.status(200).json({ message: 'Login successful', userId: user.id, fullname: user.fullname });
};
